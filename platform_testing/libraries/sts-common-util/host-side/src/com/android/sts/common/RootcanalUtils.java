/*
 * Copyright (C) 2022 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.android.sts.common;

import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertFalse;
import static com.android.sts.common.CommandUtil.runAndCheck;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.StringReader;
import java.util.concurrent.TimeoutException;
import java.util.concurrent.TimeUnit;
import java.util.List;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.xpath.XPathConstants;
import javax.xml.xpath.XPathFactory;
import javax.xml.xpath.XPathExpressionException;
import org.junit.rules.TestWatcher;
import org.junit.runner.Description;
import org.junit.rules.TestWatcher;
import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;

import com.android.compatibility.common.tradefed.build.CompatibilityBuildHelper;
import com.android.tradefed.device.DeviceNotAvailableException;
import com.android.tradefed.device.ITestDevice;
import com.android.tradefed.testtype.junit4.BaseHostJUnit4Test;
import com.android.tradefed.log.LogUtil.CLog;
import com.android.tradefed.util.CommandResult;
import com.android.tradefed.util.CommandStatus;
import com.android.tradefed.util.RunUtil;

/** TestWatcher that sets up a virtual bluetooth HAL and reboots the device once done. */
public class RootcanalUtils extends TestWatcher {
    private static final String LOCK_FILENAME = "/data/local/tmp/sts_rootcanal.lck";

    private BaseHostJUnit4Test test;
    private OverlayFsUtils overlayFsUtils;

    public RootcanalUtils(BaseHostJUnit4Test test) {
        assertNotNull(test);
        this.test = test;
        this.overlayFsUtils = new OverlayFsUtils(test);
    }

    @Override
    public void finished(Description d) {
        ITestDevice device = test.getDevice();
        assertNotNull("Device not set", device);
        try {
            device.enableAdbRoot();
            runAndCheck(device, String.format("rm -rf '%s'", LOCK_FILENAME));
            device.disableAdbRoot();
            // OverlayFsUtils' finished() will restart the device.
            overlayFsUtils.finished(d);
        } catch (DeviceNotAvailableException e) {
            throw new AssertionError("Device unavailable when cleaning up", e);
        }
    }

    /** Replace existing HAL with RootCanal HAL on current device. */
    public void enableRootcanal()
            throws DeviceNotAvailableException, IOException, InterruptedException,
                    TimeoutException {
        enableRootcanal(6111);
    }

    /**
     * Replace existing HAL with RootCanal HAL on current device.
     *
     * @param port host TCP port to adb-forward to rootcanal control port.
     */
    public void enableRootcanal(int port)
            throws DeviceNotAvailableException, IOException, InterruptedException,
                    TimeoutException {
        ITestDevice device = test.getDevice();
        CompatibilityBuildHelper buildHelper = new CompatibilityBuildHelper(test.getBuild());
        assertNotNull("Device not set", device);
        assertNotNull("Build not set", buildHelper);

        // Check and made sure we're not calling this more than once for a device
        assertFalse("rootcanal set up called more than once", device.doesFileExist(LOCK_FILENAME));
        device.pushString("", LOCK_FILENAME);

        // Make sure that /vendor is writable
        try {
            overlayFsUtils.makeWritable("/vendor", 100);
        } catch (IllegalStateException e) {
            CLog.w(e);
        }

        // Remove existing HAL files and push new virtual HAL files.
        runAndCheck(device, "svc bluetooth disable");
        runAndCheck(
                device,
                "rm -f /vendor/lib64/hw/android.hardware.bluetooth@* "
                        + "/vendor/lib/hw/android.hardware.bluetooth@* "
                        + "/vendor/bin/hw/android.hardware.bluetooth@* "
                        + "/vendor/etc/init/android.hardware.bluetooth@*");

        device.pushFile(
                buildHelper.getTestFile("android.hardware.bluetooth@1.1-service.sim"),
                "/vendor/bin/hw/android.hardware.bluetooth@1.1-service.sim");

        // Pushing the same lib to both 32 and 64bit lib dirs because (a) it works and
        // (b) FileUtil does not yet support "arm/lib" and "arm64/lib64" layout.
        device.pushFile(
                buildHelper.getTestFile("android.hardware.bluetooth@1.1-impl-sim.so"),
                "/vendor/lib/hw/android.hardware.bluetooth@1.1-impl-sim.so");
        device.pushFile(
                buildHelper.getTestFile("android.hardware.bluetooth@1.1-impl-sim.so"),
                "/vendor/lib64/hw/android.hardware.bluetooth@1.1-impl-sim.so");
        device.pushFile(
                buildHelper.getTestFile("android.hardware.bluetooth@1.1-service.sim.rc"),
                "/vendor/etc/init/android.hardware.bluetooth@1.1-service.sim.rc");

        // Download and patch the VINTF manifest if needed.
        tryUpdateVintfManifest(device);

        // Fix up permissions and SELinux contexts of files pushed over
        runAndCheck(device, "cp /system/lib64/libchrome.so /vendor/lib64/libchrome.so");
        runAndCheck(device, "chmod 755 /vendor/bin/hw/android.hardware.bluetooth@1.1-service.sim");
        runAndCheck(
                device,
                "chcon u:object_r:hal_bluetooth_default_exec:s0 "
                        + "/vendor/bin/hw/android.hardware.bluetooth@1.1-service.sim");
        runAndCheck(
                device,
                "chmod 644 "
                        + "/vendor/etc/vintf/manifest.xml "
                        + "/vendor/lib/hw/android.hardware.bluetooth@1.1-impl-sim.so "
                        + "/vendor/lib64/hw/android.hardware.bluetooth@1.1-impl-sim.so");
        runAndCheck(
                device, "chcon u:object_r:vendor_configs_file:s0 /vendor/etc/vintf/manifest.xml");
        runAndCheck(
                device,
                "chcon u:object_r:vendor_file:s0 "
                        + "/vendor/lib/hw/android.hardware.bluetooth@1.1-impl-sim.so "
                        + "/vendor/lib64/hw/android.hardware.bluetooth@1.1-impl-sim.so");

        // Kill currently running BT HAL.
        if (ProcessUtil.killAll(device, "android\\.hardware\\.bluetooth@.*", 10_000, false)) {
            CLog.d("Killed existing BT HAL");
        } else {
            CLog.w("No existing BT HAL was found running");
        }

        // Kill hwservicemanager, wait for it to come back up on its own, and wait for it
        // to finish initializing. This is needed to reload the VINTF and HAL rc information.
        // Note that a userspace reboot would not work here because hwservicemanager starts
        // before userdata is mounted.
        device.setProperty("hwservicemanager.ready", "false");
        ProcessUtil.killAll(device, "hwservicemanager$", 10_000);
        waitPropertyValue(device, "hwservicemanager.ready", "true", 10_000);
        TimeUnit.SECONDS.sleep(30);

        // Launch the new HAL
        List<String> cmd =
                List.of(
                        "adb",
                        "-s",
                        device.getSerialNumber(),
                        "shell",
                        "/vendor/bin/hw/android.hardware.bluetooth@1.1-service.sim");
        RunUtil.getDefault().runCmdInBackground(cmd);
        ProcessUtil.waitProcessRunning(
                device, "android\\.hardware\\.bluetooth@1\\.1-service\\.sim", 10_000);

        // Reenable Bluetooth and enable RootCanal control channel
        String checkCmd = "netstat -l -t -n -W | grep '0\\.0\\.0\\.0:6111'";
        while (true) {
            runAndCheck(device, "svc bluetooth enable");
            runAndCheck(device, "setprop vendor.bt.rootcanal_test_console true");
            CommandResult res = device.executeShellV2Command(checkCmd);
            if (res.getStatus() == CommandStatus.SUCCESS) {
                break;
            }
        }

        device.executeAdbCommand("forward", "tcp:6111", String.format("tcp:%d", port));
    }

    private void tryUpdateVintfManifest(ITestDevice device)
            throws DeviceNotAvailableException, IOException {
        try {
            String vintfManifest = device.pullFileContents("/vendor/etc/vintf/manifest.xml");
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = factory.newDocumentBuilder();
            Document doc = builder.parse(new InputSource(new StringReader(vintfManifest)));
            String XPATH = "/manifest/hal[name=\"android.hardware.bluetooth\"][version!=\"1.1\"]";
            Node node =
                    (Node)
                            XPathFactory.newInstance()
                                    .newXPath()
                                    .evaluate(XPATH, doc, XPathConstants.NODE);
            if (node != null) {
                Node versionNode =
                        (Node)
                                XPathFactory.newInstance()
                                        .newXPath()
                                        .evaluate("version", node, XPathConstants.NODE);
                versionNode.setTextContent("1.1");

                Node fqnameNode =
                        (Node)
                                XPathFactory.newInstance()
                                        .newXPath()
                                        .evaluate("fqname", node, XPathConstants.NODE);
                String newFqname =
                        fqnameNode.getTextContent().replaceAll("@[0-9]+\\.[0-9]+(::.*)", "@1.1$1");
                fqnameNode.setTextContent(newFqname);

                File outFile = File.createTempFile("stsrootcanal", null);
                outFile.deleteOnExit();

                Transformer transformer = TransformerFactory.newInstance().newTransformer();
                DOMSource source = new DOMSource(doc);
                StreamResult result = new StreamResult(new FileWriter(outFile));
                transformer.transform(source, result);
                device.pushFile(outFile, "/vendor/etc/vintf/manifest.xml");
                CLog.d("Updated VINTF manifest");
            } else {
                CLog.d("Not updating VINTF manifest");
            }
        } catch (ParserConfigurationException
                | SAXException
                | XPathExpressionException
                | TransformerException e) {
            CLog.e("Could not parse vintf manifest: %s", e);
        }
    }

    /** Spin wait until given property has given value. */
    private void waitPropertyValue(ITestDevice device, String name, String value, long timeoutMs)
            throws TimeoutException, DeviceNotAvailableException, InterruptedException {
        long endTime = System.currentTimeMillis() + timeoutMs;
        while (true) {
            if (value.equals(device.getProperty(name))) {
                return;
            }
            if (System.currentTimeMillis() > endTime) {
                throw new TimeoutException();
            }
            TimeUnit.MILLISECONDS.sleep(250);
        }
    }
}
