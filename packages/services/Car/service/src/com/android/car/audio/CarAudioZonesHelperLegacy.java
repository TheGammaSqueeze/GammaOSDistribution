/*
 * Copyright (C) 2018 The Android Open Source Project
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
package com.android.car.audio;

import static android.car.media.CarAudioManager.PRIMARY_AUDIO_ZONE;

import static com.android.car.audio.CarAudioUtils.isMicrophoneInputDevice;
import static com.android.car.audio.CarAudioZonesHelper.LEGACY_CONTEXTS;
import static com.android.car.internal.ExcludeFromCodeCoverageGeneratedReport.DEPRECATED_CODE;

import android.annotation.NonNull;
import android.annotation.XmlRes;
import android.content.Context;
import android.content.res.TypedArray;
import android.content.res.XmlResourceParser;
import android.media.AudioDeviceAttributes;
import android.media.AudioDeviceInfo;
import android.util.AttributeSet;
import android.util.Slog;
import android.util.SparseArray;
import android.util.SparseIntArray;
import android.util.Xml;

import com.android.car.CarLog;
import com.android.car.R;
import com.android.car.audio.hal.AudioControlWrapperV1;
import com.android.car.internal.ExcludeFromCodeCoverageGeneratedReport;

import org.xmlpull.v1.XmlPullParserException;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

/**
 * A helper class loads volume groups from car_volume_groups.xml configuration into one zone.
 *
 * @deprecated This is replaced by {@link CarAudioZonesHelper}.
 */
@Deprecated
@ExcludeFromCodeCoverageGeneratedReport(reason = DEPRECATED_CODE)
class CarAudioZonesHelperLegacy {
    private static final String TAG_VOLUME_GROUPS = "volumeGroups";
    private static final String TAG_GROUP = "group";
    private static final String TAG_CONTEXT = "context";

    private static final int NO_BUS_FOR_CONTEXT = -1;

    private final Context mContext;
    private final @XmlRes int mXmlConfiguration;
    private final SparseIntArray mLegacyAudioContextToBus;
    private final SparseArray<CarAudioDeviceInfo> mBusToCarAudioDeviceInfo;
    private final CarAudioSettings mCarAudioSettings;
    private final AudioDeviceInfo[] mInputDevices;

    CarAudioZonesHelperLegacy(@NonNull Context context, @XmlRes int xmlConfiguration,
            @NonNull List<CarAudioDeviceInfo> carAudioDeviceInfos,
            @NonNull AudioControlWrapperV1 audioControlWrapper,
            @NonNull CarAudioSettings carAudioSettings,
            AudioDeviceInfo[] inputDevices) {
        Objects.requireNonNull(context, "Context must not be null.");
        Objects.requireNonNull(carAudioDeviceInfos,
                "Car Audio Device Info must not be null.");
        Objects.requireNonNull(audioControlWrapper,
                "Car Audio Control must not be null.");
        Objects.requireNonNull(inputDevices, "Input Devices must not be null.");
        mCarAudioSettings = Objects.requireNonNull(carAudioSettings,
                "Car Audio Settings can not be null.");
        mContext = context;
        mXmlConfiguration = xmlConfiguration;
        mBusToCarAudioDeviceInfo =
                generateBusToCarAudioDeviceInfo(carAudioDeviceInfos);

        mLegacyAudioContextToBus =
                loadBusesForLegacyContexts(audioControlWrapper);
        mInputDevices = inputDevices;
    }

    /* Loads mapping from {@link CarAudioContext} values to bus numbers
     * <p>Queries {@code IAudioControl#getBusForContext} for all
     * {@code CArAudioZoneHelper.LEGACY_CONTEXTS}. Legacy
     * contexts are those defined as part of
     * {@code android.hardware.automotive.audiocontrol.V1_0.ContextNumber}
     *
     * @param audioControl wrapper for IAudioControl HAL interface.
     * @return SparseIntArray mapping from {@link CarAudioContext} to bus number.
     */
    private static SparseIntArray loadBusesForLegacyContexts(
            @NonNull AudioControlWrapperV1 audioControlWrapper) {
        SparseIntArray contextToBus = new SparseIntArray();

        for (int legacyContext : LEGACY_CONTEXTS) {
            int bus = audioControlWrapper.getBusForContext(legacyContext);
            validateBusNumber(legacyContext, bus);
            contextToBus.put(legacyContext, bus);
        }
        return contextToBus;
    }

    private static void validateBusNumber(int legacyContext, int bus) {
        if (bus == NO_BUS_FOR_CONTEXT) {
            throw new IllegalArgumentException(
                    String.format("Invalid bus %d was associated with context %s", bus,
                            CarAudioContext.toString(legacyContext)));
        }
    }

    private static SparseArray<CarAudioDeviceInfo> generateBusToCarAudioDeviceInfo(
            List<CarAudioDeviceInfo> carAudioDeviceInfos) {
        SparseArray<CarAudioDeviceInfo> busToCarAudioDeviceInfo = new SparseArray<>();

        for (CarAudioDeviceInfo carAudioDeviceInfo : carAudioDeviceInfos) {
            int busNumber = parseDeviceAddress(carAudioDeviceInfo.getAddress());
            if (busNumber >= 0) {
                if (busToCarAudioDeviceInfo.get(busNumber) != null) {
                    throw new IllegalArgumentException("Two addresses map to same bus number: "
                            + carAudioDeviceInfo.getAddress()
                            + " and "
                            + busToCarAudioDeviceInfo.get(busNumber).getAddress());
                }
                busToCarAudioDeviceInfo.put(busNumber, carAudioDeviceInfo);
            }
        }

        return busToCarAudioDeviceInfo;
    }

    SparseArray<CarAudioZone> loadAudioZones() {
        CarAudioZone zone = new CarAudioZone(PRIMARY_AUDIO_ZONE, "Primary zone");
        for (CarVolumeGroup volumeGroup : loadVolumeGroups()) {
            zone.addVolumeGroup(volumeGroup);
        }
        SparseArray<CarAudioZone> carAudioZones = new SparseArray<>();
        addMicrophonesToPrimaryZone(zone);
        carAudioZones.put(PRIMARY_AUDIO_ZONE, zone);

        return carAudioZones;
    }

    /**
     * @return all {@link CarVolumeGroup} read from configuration.
     */
    private List<CarVolumeGroup> loadVolumeGroups() {
        List<CarVolumeGroup> carVolumeGroups = new ArrayList<>();
        try (XmlResourceParser parser = mContext.getResources().getXml(mXmlConfiguration)) {
            AttributeSet attrs = Xml.asAttributeSet(parser);
            int type;
            // Traverse to the first start tag
            while ((type = parser.next()) != XmlResourceParser.END_DOCUMENT
                    && type != XmlResourceParser.START_TAG) {
                // ignored
            }

            if (!TAG_VOLUME_GROUPS.equals(parser.getName())) {
                throw new IllegalArgumentException(
                        "Meta-data does not start with volumeGroups tag");
            }
            int outerDepth = parser.getDepth();
            int id = 0;
            while ((type = parser.next()) != XmlResourceParser.END_DOCUMENT
                    && (type != XmlResourceParser.END_TAG || parser.getDepth() > outerDepth)) {
                if (type == XmlResourceParser.END_TAG) {
                    continue;
                }
                if (TAG_GROUP.equals(parser.getName())) {
                    carVolumeGroups.add(parseVolumeGroup(id, attrs, parser));
                    id++;
                }
            }
        } catch (Exception e) {
            Slog.e(CarLog.TAG_AUDIO, "Error parsing volume groups configuration", e);
        }
        return carVolumeGroups;
    }

    private CarVolumeGroup parseVolumeGroup(int id, AttributeSet attrs,
            XmlResourceParser parser) throws XmlPullParserException, IOException {
        CarVolumeGroup.Builder builder = new CarVolumeGroup.Builder(PRIMARY_AUDIO_ZONE, id,
                mCarAudioSettings, /* useCarVolumeGroupMute= */ false);

        List<Integer> audioContexts = parseAudioContexts(parser, attrs);

        for (int i = 0; i < audioContexts.size(); i++) {
            bindContextToBuilder(builder, audioContexts.get(i));
        }

        return builder.build();
    }


    private void bindContextToBuilder(CarVolumeGroup.Builder groupBuilder, int legacyAudioContext) {
        int busNumber = mLegacyAudioContextToBus.get(legacyAudioContext);
        CarAudioDeviceInfo info = mBusToCarAudioDeviceInfo.get(busNumber);
        groupBuilder.setDeviceInfoForContext(legacyAudioContext, info);

        if (legacyAudioContext == CarAudioService.DEFAULT_AUDIO_CONTEXT) {
            CarAudioZonesHelper.setNonLegacyContexts(groupBuilder, info);
        }
    }

    private List<Integer> parseAudioContexts(XmlResourceParser parser, AttributeSet attrs)
            throws IOException, XmlPullParserException {
        List<Integer> contexts = new ArrayList<>();
        int type;
        int innerDepth = parser.getDepth();
        while ((type = parser.next()) != XmlResourceParser.END_DOCUMENT
                && (type != XmlResourceParser.END_TAG || parser.getDepth() > innerDepth)) {
            if (type == XmlResourceParser.END_TAG) {
                continue;
            }
            if (TAG_CONTEXT.equals(parser.getName())) {
                TypedArray c = mContext.getResources().obtainAttributes(
                        attrs, R.styleable.volumeGroups_context);
                contexts.add(c.getInt(R.styleable.volumeGroups_context_context, -1));
                c.recycle();
            }
        }

        return contexts;
    }

    private void addMicrophonesToPrimaryZone(CarAudioZone primaryAudioZone) {
        for (int index = 0; index < mInputDevices.length; index++) {
            AudioDeviceInfo info = mInputDevices[index];
            if (isMicrophoneInputDevice(info)) {
                primaryAudioZone.addInputAudioDevice(new AudioDeviceAttributes(info));
            }
        }
    }

    /**
     * Parse device address. Expected format is BUS%d_%s, address, usage hint
     *
     * @return valid address (from 0 to positive) or -1 for invalid address.
     */
    private static int parseDeviceAddress(String address) {
        String[] words = address.split("_");
        int addressParsed = -1;
        if (words[0].toLowerCase().startsWith("bus")) {
            try {
                addressParsed = Integer.parseInt(words[0].substring(3));
            } catch (NumberFormatException e) {
                //ignore
            }
        }
        if (addressParsed < 0) {
            return -1;
        }
        return addressParsed;
    }
}
