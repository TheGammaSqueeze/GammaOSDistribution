package android.location.cts.gnss;


import static android.Manifest.permission.ACCESS_COARSE_LOCATION;
import static android.Manifest.permission.ACCESS_FINE_LOCATION;

import android.app.UiAutomation;
import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.location.GnssStatus;
import android.location.cts.common.GnssTestCase;
import android.location.cts.common.SoftAssert;
import android.location.cts.common.TestLocationListener;
import android.location.cts.common.TestLocationManager;
import android.location.cts.common.TestMeasurementUtil;
import android.platform.test.annotations.AppModeFull;
import android.util.Log;

import androidx.test.InstrumentationRegistry;

import java.util.ArrayList;
import java.util.List;

public class GnssStatusTest extends GnssTestCase  {

    private static final String TAG = "GnssStatusTest";
    private static final int LOCATION_TO_COLLECT_COUNT = 1;
    private static final int STATUS_TO_COLLECT_COUNT = 3;
    private UiAutomation mUiAutomation;

  @Override
  protected void setUp() throws Exception {
    super.setUp();
    mTestLocationManager = new TestLocationManager(getContext());
    mUiAutomation = InstrumentationRegistry.getInstrumentation().getUiAutomation();
  }

  /**
   * Tests that one can listen for {@link GnssStatus}.
   */
  @AppModeFull(reason = "Instant apps cannot access package manager to scan for permissions")
  public void testGnssStatusChanges() throws Exception {
    // Checks if GPS hardware feature is present, skips test (pass) if not
    if (!TestMeasurementUtil.canTestRunOnCurrentDevice(mTestLocationManager, TAG)) {
      return;
    }

    // Revoke location permissions from packages before running GnssStatusTest stops
    // active location requests, allowing this test to receive all necessary Gnss callbacks.
    List<String> courseLocationPackages = revokePermissions(ACCESS_COARSE_LOCATION);
    List<String> fineLocationPackages = revokePermissions(ACCESS_FINE_LOCATION);

    try {
        // Register Gps Status Listener.
        TestGnssStatusCallback testGnssStatusCallback =
            new TestGnssStatusCallback(TAG, STATUS_TO_COLLECT_COUNT);
        checkGnssChange(testGnssStatusCallback);
    } finally {
        // For each location package, re-grant the permission
        grantLocationPermissions(ACCESS_COARSE_LOCATION, courseLocationPackages);
        grantLocationPermissions(ACCESS_FINE_LOCATION, fineLocationPackages);
    }
  }

  private void checkGnssChange(TestGnssStatusCallback testGnssStatusCallback)
      throws InterruptedException {
    mTestLocationManager.registerGnssStatusCallback(testGnssStatusCallback);

    TestLocationListener locationListener = new TestLocationListener(LOCATION_TO_COLLECT_COUNT);
    mTestLocationManager.requestLocationUpdates(locationListener);

    boolean success = testGnssStatusCallback.awaitStart();
    success = success ? testGnssStatusCallback.awaitStatus() : false;
    success = success ? testGnssStatusCallback.awaitTtff() : false;
    mTestLocationManager.removeLocationUpdates(locationListener);
    success = success ? testGnssStatusCallback.awaitStop() : false;
    mTestLocationManager.unregisterGnssStatusCallback(testGnssStatusCallback);

    SoftAssert softAssert = new SoftAssert(TAG);
    softAssert.assertTrue(
        "Time elapsed without getting the right status changes."
            + " Possibly, the test has been run deep indoors."
            + " Consider retrying test outdoors.",
        success);
    softAssert.assertAll();
  }

  /**
   * Tests values of {@link GnssStatus}.
   */
  public void testGnssStatusValues() throws InterruptedException {
    // Checks if GPS hardware feature is present, skips test (pass) if not
    if (!TestMeasurementUtil.canTestRunOnCurrentDevice(mTestLocationManager, TAG)) {
      return;
    }
    SoftAssert softAssert = new SoftAssert(TAG);
    // Register Gps Status Listener.
    TestGnssStatusCallback testGnssStatusCallback =
        new TestGnssStatusCallback(TAG, STATUS_TO_COLLECT_COUNT);
    checkGnssChange(testGnssStatusCallback);
    validateGnssStatus(testGnssStatusCallback.getGnssStatus(), softAssert);
    softAssert.assertAll();
  }

  /**
   * To validate the fields in GnssStatus class, the value is got from device
   * @param status, GnssStatus
   * @param softAssert, customized assert class.
   */
  private void validateGnssStatus(GnssStatus status, SoftAssert softAssert) {
    int sCount = status.getSatelliteCount();
    Log.i(TAG, "Total satellite:" + sCount);
    // total number of satellites for all constellation is less than 200
    softAssert.assertTrue("Satellite count test sCount : " + sCount , sCount < 200);
    for (int i = 0; i < sCount; ++i) {
      softAssert.assertTrue("azimuth_degrees: Azimuth in degrees: ",
          "0.0 <= X <= 360.0",
          String.valueOf(status.getAzimuthDegrees(i)),
          status.getAzimuthDegrees(i) >= 0.0 && status.getAzimuthDegrees(i) <= 360.0);
      TestMeasurementUtil.verifyGnssCarrierFrequency(softAssert, mTestLocationManager,
          status.hasCarrierFrequencyHz(i),
          status.hasCarrierFrequencyHz(i) ? status.getCarrierFrequencyHz(i) : 0F);

      softAssert.assertTrue("c_n0_dbhz: Carrier-to-noise density",
          "0.0 <= X <= 63",
          String.valueOf(status.getCn0DbHz(i)),
          status.getCn0DbHz(i) >= 0.0 &&
              status.getCn0DbHz(i) <= 63.0);

      Log.i(TAG, "hasBasebandCn0DbHz: " + status.hasBasebandCn0DbHz(i));
      if (status.hasBasebandCn0DbHz(i)) {
        softAssert.assertTrue("baseband_cn0_dbhz: Baseband carrier-to-noise density",
                "0.0 <= X <= 63",
                String.valueOf(status.getBasebandCn0DbHz(i)),
                status.getBasebandCn0DbHz(i) >= 0.0 &&
                        status.getBasebandCn0DbHz(i) <= 63.0);
      }

      softAssert.assertTrue("elevation_degrees: Elevation in Degrees :",
          "0.0 <= X <= 90.0",
          String.valueOf(status.getElevationDegrees(i)),
          status.getElevationDegrees(i) >= 0.0 && status.getElevationDegrees(i) <= 90.0);

      // in validateSvidSub, it will validate ConstellationType, svid
      // however, we don't have the event time in the current scope, pass in "-1" instead
      TestMeasurementUtil.validateSvidSub(softAssert, null,
          status.getConstellationType(i),status.getSvid(i));

      // For those function with boolean type return, just simply call the function
      // to make sure those function won't crash, also increase the test coverage.
      Log.i(TAG, "hasAlmanacData: " + status.hasAlmanacData(i));
      Log.i(TAG, "hasEphemerisData: " + status.hasEphemerisData(i));
      Log.i(TAG, "usedInFix: " + status.usedInFix(i));
    }
  }

  private List<String> getPackagesWithPermissions(String permission) {
    Context context = InstrumentationRegistry.getTargetContext();
    PackageManager pm = context.getPackageManager();

    ArrayList<String> packagesWithPermission = new ArrayList<>();
    List<ApplicationInfo> packages = pm.getInstalledApplications(/*flags=*/ 0);

    for (ApplicationInfo applicationInfo : packages) {
      String packageName = applicationInfo.packageName;
      if (packageName.equals(context.getPackageName())) {
        // Don't include this test package.
        continue;
      }

      if (pm.checkPermission(permission, packageName) == PackageManager.PERMISSION_GRANTED) {
        final int flags;
        mUiAutomation.adoptShellPermissionIdentity("android.permission.GET_RUNTIME_PERMISSIONS");
        try {
          flags = pm.getPermissionFlags(permission, packageName,
                    android.os.Process.myUserHandle());
        } finally {
          mUiAutomation.dropShellPermissionIdentity();
        }

        final boolean fixed = (flags & (PackageManager.FLAG_PERMISSION_USER_FIXED
            | PackageManager.FLAG_PERMISSION_POLICY_FIXED
            | PackageManager.FLAG_PERMISSION_SYSTEM_FIXED)) != 0;
        if (!fixed) {
          packagesWithPermission.add(packageName);
        }
      }
    }
    return packagesWithPermission;
  }

  private List<String> revokePermissions(String permission) {
    List<String> packages = getPackagesWithPermissions(permission);
    for (String packageWithPermission : packages) {
      Log.i(TAG, "Revoking permissions from: " + packageWithPermission);
      mUiAutomation.revokeRuntimePermission(packageWithPermission, permission);
    }
    return packages;
  }

  private void grantLocationPermissions(String permission, List<String> packages) {
    for (String packageToGivePermission : packages) {
      Log.i(TAG, "Granting permissions (back) to: " + packageToGivePermission);
      mUiAutomation.grantRuntimePermission(packageToGivePermission, permission);
    }
  }
}
