/*
 * Copyright (C) 2021 The Android Open Source Project
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

package com.android.tv.settings.device.displaysound;

import static android.view.Display.HdrCapabilities.HDR_TYPE_DOLBY_VISION;
import static android.view.Display.HdrCapabilities.HDR_TYPE_HDR10;
import static android.view.Display.HdrCapabilities.HDR_TYPE_HDR10_PLUS;
import static android.view.Display.HdrCapabilities.HDR_TYPE_HLG;

import static com.android.tv.settings.device.displaysound.HdrFormatSelectionFragment.KEY_HDR_FORMAT_PREFIX;
import static com.android.tv.settings.device.displaysound.HdrFormatSelectionFragment.KEY_HDR_FORMAT_SELECTION_AUTO;
import static com.android.tv.settings.device.displaysound.HdrFormatSelectionFragment.KEY_HDR_FORMAT_SELECTION_MANUAL;
import static com.android.tv.settings.device.displaysound.HdrFormatSelectionFragment.KEY_SHOW_HIDE_FORMAT_INFO;

import static com.google.common.truth.Truth.assertThat;

import static org.mockito.Mockito.doReturn;
import static org.mockito.Mockito.spy;
import static org.mockito.Mockito.verify;

import android.hardware.display.DisplayManager;
import android.view.Display;

import androidx.preference.Preference;
import androidx.preference.PreferenceCategory;
import androidx.preference.SwitchPreference;

import com.android.tv.settings.R;
import com.android.tv.settings.RadioPreference;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.ArgumentCaptor;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;
import org.robolectric.RobolectricTestRunner;
import org.robolectric.shadows.androidx.fragment.FragmentController;

import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

@RunWith(RobolectricTestRunner.class)
public class HdrFormatSelectionFragmentTest {

    @Mock private DisplayManager mDisplayManager;

    @Before
    public void setUp() {
        MockitoAnnotations.initMocks(this);
    }

    @Test
    public void testOnPreferenceTreeClick_withAuto_allowsUserDisabledHdrTypes() {
        HdrFormatSelectionFragment fragment = createDefaultHdrFormatSelectionFragment();
        RadioPreference preference = fragment.findPreference(KEY_HDR_FORMAT_SELECTION_AUTO);

        fragment.onPreferenceTreeClick(preference);

        verify(mDisplayManager).setAreUserDisabledHdrTypesAllowed(true);
    }

    @Test
    public void testOnPreferenceTreeClick_withManual_disallowsUserDisabledHdrTypes() {
        HdrFormatSelectionFragment fragment = createDefaultHdrFormatSelectionFragment();
        RadioPreference preference = fragment.findPreference(KEY_HDR_FORMAT_SELECTION_MANUAL);

        fragment.onPreferenceTreeClick(preference);

        verify(mDisplayManager).setAreUserDisabledHdrTypesAllowed(false);
    }

    @Test
    public void testOnPreferenceTreeClick_withFormatDisabled_disablesHdrTypeInDisplayManager() {
        int[] deviceHdrTypes = { HDR_TYPE_DOLBY_VISION,
                HDR_TYPE_HDR10, HDR_TYPE_HLG, HDR_TYPE_HDR10_PLUS };
        int[] displayReportedHdrTypes = { HDR_TYPE_DOLBY_VISION, HDR_TYPE_HDR10, HDR_TYPE_HLG };
        int[] userDisabledHdrTypes = { HDR_TYPE_DOLBY_VISION };

        HdrFormatSelectionFragment fragment =
                createHdrFormatSelectionFragmentWithDisplayManagerReturning(
                        deviceHdrTypes, displayReportedHdrTypes, userDisabledHdrTypes);

        RadioPreference preference = fragment.findPreference(KEY_HDR_FORMAT_SELECTION_MANUAL);
        fragment.onPreferenceTreeClick(preference);

        SwitchPreference pref = (SwitchPreference) fragment.findPreference(
                KEY_HDR_FORMAT_PREFIX + HDR_TYPE_HDR10);
        pref.setChecked(false);
        fragment.onPreferenceTreeClick(pref);

        ArgumentCaptor<int[]> userDisabledTypesCaptor =
                ArgumentCaptor.forClass(int[].class);
        verify(mDisplayManager).setUserDisabledHdrTypes(
                userDisabledTypesCaptor.capture());
        assertThat(userDisabledTypesCaptor.getValue())
                .isEqualTo(new int[]{ HDR_TYPE_DOLBY_VISION, HDR_TYPE_HDR10 });
    }

    @Test
    public void testOnPreferenceTreeClick_withFormatEnabled_enablesHdrTypeInDisplayManager() {
        int[] deviceHdrTypes = { HDR_TYPE_DOLBY_VISION,
                HDR_TYPE_HDR10, HDR_TYPE_HLG, HDR_TYPE_HDR10_PLUS };
        int[] displayReportedHdrTypes = { HDR_TYPE_DOLBY_VISION, HDR_TYPE_HDR10, HDR_TYPE_HLG };
        int[] userDisabledTypes = { HDR_TYPE_DOLBY_VISION, HDR_TYPE_HDR10 };

        HdrFormatSelectionFragment fragment =
                createHdrFormatSelectionFragmentWithDisplayManagerReturning(
                        deviceHdrTypes, displayReportedHdrTypes, userDisabledTypes);

        RadioPreference preference = fragment.findPreference(KEY_HDR_FORMAT_SELECTION_MANUAL);
        fragment.onPreferenceTreeClick(preference);

        SwitchPreference pref = (SwitchPreference) fragment.findPreference(
                KEY_HDR_FORMAT_PREFIX + HDR_TYPE_HDR10);
        pref.setChecked(true);
        fragment.onPreferenceTreeClick(pref);

        ArgumentCaptor<int[]> userDisabledTypesCaptor =
                ArgumentCaptor.forClass(int[].class);
        verify(mDisplayManager).setUserDisabledHdrTypes(
                userDisabledTypesCaptor.capture());
        assertThat(userDisabledTypesCaptor.getValue())
                .isEqualTo(new int[]{HDR_TYPE_DOLBY_VISION});
    }

    @Test
    public void
            testGetPreferenceScreen_whenManual_returnsFormatPreferencesInCorrectPreferenceGroup() {
        int[] deviceHdrTypes = { HDR_TYPE_DOLBY_VISION, HDR_TYPE_HDR10, HDR_TYPE_HLG };
        int[] displayReportedHdrTypes = { HDR_TYPE_DOLBY_VISION, HDR_TYPE_HLG };
        int[] userDisabledTypes = { HDR_TYPE_HLG };

        HdrFormatSelectionFragment fragment =
                createHdrFormatSelectionFragmentWithDisplayManagerReturning(
                        deviceHdrTypes, displayReportedHdrTypes, userDisabledTypes);
        RadioPreference preference = fragment.findPreference(KEY_HDR_FORMAT_SELECTION_MANUAL);
        fragment.onPreferenceTreeClick(preference);

        assertThat(fragment.getPreferenceScreen().getPreferenceCount()).isEqualTo(3);

        Preference supportedFormatPreference = fragment.getPreferenceScreen().getPreference(1);
        assertThat(supportedFormatPreference.getTitle()).isEqualTo(
                fragment.getContext().getString(R.string.hdr_format_supported_title));
        assertThat(getChildrenTitles(supportedFormatPreference)).containsExactly(
                fragment.getContext().getString(R.string.hdr_format_dolby_vision),
                fragment.getContext().getString(R.string.hdr_format_hlg));

        Preference unsupportedFormatPreference =
                fragment.getPreferenceScreen().getPreference(2);
        assertThat(unsupportedFormatPreference.getTitle()).isEqualTo(
                fragment.getContext().getString(R.string.hdr_format_unsupported_title));
        assertThat(getChildrenTitles(unsupportedFormatPreference)).containsExactly(
                fragment.getContext().getString(R.string.hdr_format_hdr10));
    }

    @Test
    public void
            testGetPreferenceScreen_whenManual_returnsFormatPreferencesWithCorrectCheckedState() {
        int[] deviceHdrTypes = { HDR_TYPE_DOLBY_VISION, HDR_TYPE_HDR10, HDR_TYPE_HLG };
        int[] displayReportedHdrTypes = { HDR_TYPE_DOLBY_VISION, HDR_TYPE_HLG };
        int[] userDisabledTypes = { HDR_TYPE_HLG };

        HdrFormatSelectionFragment fragment =
                createHdrFormatSelectionFragmentWithDisplayManagerReturning(
                        deviceHdrTypes, displayReportedHdrTypes, userDisabledTypes);
        RadioPreference preference = fragment.findPreference(KEY_HDR_FORMAT_SELECTION_MANUAL);
        fragment.onPreferenceTreeClick(preference);

        PreferenceCategory supportedFormatPreference =
                (PreferenceCategory) fragment.getPreferenceScreen().getPreference(1);
        SwitchPreference dolbyVisionPref =
                (SwitchPreference) supportedFormatPreference.getPreference(0);
        assertThat(dolbyVisionPref.getTitle().toString())
                .isEqualTo(fragment.getContext().getString(R.string.hdr_format_dolby_vision));
        assertThat(dolbyVisionPref.isChecked()).isTrue();

        SwitchPreference hlgPref = (SwitchPreference) supportedFormatPreference.getPreference(1);
        assertThat(hlgPref.getTitle().toString())
                .isEqualTo(fragment.getContext().getString(R.string.hdr_format_hlg));
        assertThat(hlgPref.isChecked()).isFalse();
    }

    @Test
    public void testGetPreferenceScreen_whenAuto_returnsNoFormatPreferences() {
        int[] deviceHdrTypes = { HDR_TYPE_DOLBY_VISION, HDR_TYPE_HDR10, HDR_TYPE_HLG };
        int[] displayReportedHdrTypes = { HDR_TYPE_DOLBY_VISION, HDR_TYPE_HLG };
        int[] userDisabledTypes = { HDR_TYPE_HLG };

        HdrFormatSelectionFragment fragment =
                createHdrFormatSelectionFragmentWithDisplayManagerReturning(
                        deviceHdrTypes, displayReportedHdrTypes, userDisabledTypes);
        RadioPreference preference = fragment.findPreference(KEY_HDR_FORMAT_SELECTION_AUTO);
        fragment.onPreferenceTreeClick(preference);

        assertThat(fragment.getPreferenceScreen().getPreferenceCount()).isEqualTo(2);
    }

    @Test
    public void testGetPreferenceScreen_whenAuto_showsFormatInfoPreference() {
        int[] deviceHdrTypes = { HDR_TYPE_DOLBY_VISION, HDR_TYPE_HDR10, HDR_TYPE_HLG };
        int[] displayReportedHdrTypes = { HDR_TYPE_DOLBY_VISION, HDR_TYPE_HLG };
        int[] userDisabledTypes = { HDR_TYPE_HLG };

        HdrFormatSelectionFragment fragment =
                createHdrFormatSelectionFragmentWithDisplayManagerReturning(
                        deviceHdrTypes, displayReportedHdrTypes, userDisabledTypes);

        Preference preference = fragment.findPreference(KEY_HDR_FORMAT_SELECTION_AUTO);
        fragment.onPreferenceTreeClick(preference);

        assertThat(fragment.getPreferenceScreen().getPreferenceCount()).isEqualTo(2);

        PreferenceCategory formatInfoPreferenceCategory =
                (PreferenceCategory) fragment.getPreferenceScreen().getPreference(1);
        assertThat(formatInfoPreferenceCategory.getTitle()).isEqualTo(
                fragment.getContext().getString(R.string.hdr_format_info));
        assertThat(formatInfoPreferenceCategory.getPreferenceCount()).isEqualTo(1);
        Preference showFormatPreference = formatInfoPreferenceCategory.getPreference(0);
        assertThat(showFormatPreference.getTitle()).isEqualTo(
                fragment.getContext().getString(R.string.hdr_show_formats));
    }

    @Test
    public void testGetPreferenceScreen_whenAuto_returnsFormatsInCorrectPreferenceGroup() {
        int[] deviceHdrTypes = { HDR_TYPE_DOLBY_VISION, HDR_TYPE_HDR10 };
        int[] displayReportedHdrTypes = { HDR_TYPE_DOLBY_VISION };
        int[] userDisabledTypes = { HDR_TYPE_DOLBY_VISION };

        HdrFormatSelectionFragment fragment =
                createHdrFormatSelectionFragmentWithDisplayManagerReturning(
                        deviceHdrTypes, displayReportedHdrTypes, userDisabledTypes);

        Preference preference = fragment.findPreference(KEY_HDR_FORMAT_SELECTION_AUTO);
        fragment.onPreferenceTreeClick(preference);

        preference = fragment.findPreference(KEY_SHOW_HIDE_FORMAT_INFO);
        fragment.onPreferenceTreeClick(preference);

        PreferenceCategory formatInfoPreferenceCategory =
                (PreferenceCategory) fragment.getPreferenceScreen().getPreference(1);
        assertThat(formatInfoPreferenceCategory.getPreferenceCount()).isEqualTo(3);

        Preference hideFormatPreference = formatInfoPreferenceCategory.getPreference(0);
        assertThat(hideFormatPreference.getTitle()).isEqualTo(
                fragment.getContext().getString(R.string.hdr_hide_formats));

        Preference enabledFormatsCategory = formatInfoPreferenceCategory.getPreference(1);
        assertThat(enabledFormatsCategory.getTitle()).isEqualTo(
                fragment.getContext().getString(R.string.hdr_enabled_formats));
        assertThat(getChildrenTitles(enabledFormatsCategory)).containsExactly(
                fragment.getContext().getString(R.string.hdr_format_dolby_vision));

        Preference disabledFormatsCategory = formatInfoPreferenceCategory.getPreference(2);
        assertThat(disabledFormatsCategory.getTitle()).isEqualTo(
                fragment.getContext().getString(R.string.hdr_disabled_formats));
        assertThat(getChildrenTitles(disabledFormatsCategory)).containsExactly(
                fragment.getContext().getString(R.string.hdr_format_hdr10));
    }

    private List<String> getChildrenTitles(Preference preference) {
        PreferenceCategory category = (PreferenceCategory) preference;

        return IntStream.range(0, category.getPreferenceCount())
                .mapToObj(i -> category.getPreference(i).getTitle().toString())
                .collect(Collectors.toList());
    }

    private HdrFormatSelectionFragment createDefaultHdrFormatSelectionFragment() {
        return createHdrFormatSelectionFragmentWithDisplayManagerReturning(
                new int[]{}, new int[]{}, new int[]{});
    }

    private HdrFormatSelectionFragment createHdrFormatSelectionFragmentWithDisplayManagerReturning(
            int[] deviceHdrTypes, int[] displayReportedHdrTypes, int[] userDisabledHdrTypes) {
        doReturn(userDisabledHdrTypes).when(mDisplayManager).getUserDisabledHdrTypes();
        Display display = spy(Display.class);
        doReturn(displayReportedHdrTypes).when(display).getReportedHdrTypes();

        int[] hdrCapabilitiesReportedFormats =
                difference(displayReportedHdrTypes, userDisabledHdrTypes);
        Display.HdrCapabilities hdrCapabilities = new Display.HdrCapabilities(
                hdrCapabilitiesReportedFormats, -1 /*maxLuminance*/,
                -1 /* maxAverageLuminance*/, -1 /* minLuminance */);
        doReturn(hdrCapabilities).when(display).getHdrCapabilities();

        doReturn(display).when(mDisplayManager).getDisplay(Display.DEFAULT_DISPLAY);

        HdrFormatSelectionFragment fragment = spy(HdrFormatSelectionFragment.class);
        doReturn(mDisplayManager).when(fragment).getDisplayManager();
        doReturn(deviceHdrTypes).when(fragment).getDeviceSupportedHdrTypes();

        return FragmentController.of(fragment)
                .create()
                .start()
                .get();
    }

    private int[] difference(int[] array1, int[] array2) {
        Set<Integer> set2 = Arrays.stream(array2).boxed().collect(Collectors.toSet());
        Set<Integer> differenceSet = new HashSet<>();
        for (int i : array1) {
            if (!set2.contains(i)) {
                differenceSet.add(i);
            }
        }
        return differenceSet.stream().mapToInt(Number::intValue).toArray();
    }

}
