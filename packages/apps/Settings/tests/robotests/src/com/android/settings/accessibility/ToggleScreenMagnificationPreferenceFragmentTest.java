/*
 * Copyright (C) 2020 The Android Open Source Project
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

package com.android.settings.accessibility;

import static com.android.settings.accessibility.AccessibilityUtil.State.OFF;
import static com.android.settings.accessibility.AccessibilityUtil.State.ON;
import static com.android.settings.accessibility.AccessibilityUtil.UserShortcutType;
import static com.android.settings.accessibility.ToggleFeaturePreferenceFragment.KEY_SAVED_USER_SHORTCUT_TYPE;

import static com.google.common.truth.Truth.assertThat;

import static org.mockito.ArgumentMatchers.any;
import static org.mockito.ArgumentMatchers.anyInt;
import static org.mockito.Mockito.RETURNS_DEEP_STUBS;
import static org.mockito.Mockito.doReturn;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.spy;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

import android.content.ComponentName;
import android.content.Context;
import android.content.DialogInterface;
import android.content.res.Resources;
import android.os.Bundle;
import android.provider.Settings;
import android.text.TextUtils;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.XmlRes;
import androidx.appcompat.app.AlertDialog;
import androidx.fragment.app.FragmentActivity;
import androidx.preference.Preference;
import androidx.preference.PreferenceManager;
import androidx.preference.PreferenceScreen;
import androidx.test.core.app.ApplicationProvider;

import com.android.settings.DialogCreatable;
import com.android.settings.R;
import com.android.settings.accessibility.AccessibilityDialogUtils.DialogType;
import com.android.settings.testutils.shadow.ShadowFragment;
import com.android.settings.testutils.shadow.ShadowSettingsPreferenceFragment;
import com.android.settingslib.core.lifecycle.Lifecycle;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mockito;
import org.mockito.MockitoAnnotations;
import org.robolectric.Robolectric;
import org.robolectric.RobolectricTestRunner;
import org.robolectric.annotation.Config;

@RunWith(RobolectricTestRunner.class)
@Config(shadows = {ShadowSettingsPreferenceFragment.class})
public class ToggleScreenMagnificationPreferenceFragmentTest {

    private static final String PLACEHOLDER_PACKAGE_NAME = "com.mock.example";
    private static final String PLACEHOLDER_CLASS_NAME =
            PLACEHOLDER_PACKAGE_NAME + ".mock_a11y_service";
    private static final ComponentName PLACEHOLDER_COMPONENT_NAME = new ComponentName(
            PLACEHOLDER_PACKAGE_NAME, PLACEHOLDER_CLASS_NAME);
    private static final String PLACEHOLDER_DIALOG_TITLE = "title";

    private static final String SOFTWARE_SHORTCUT_KEY =
            Settings.Secure.ACCESSIBILITY_BUTTON_TARGETS;
    private static final String HARDWARE_SHORTCUT_KEY =
            Settings.Secure.ACCESSIBILITY_SHORTCUT_TARGET_SERVICE;
    private static final String TRIPLETAP_SHORTCUT_KEY =
            Settings.Secure.ACCESSIBILITY_DISPLAY_MAGNIFICATION_ENABLED;

    private static final String MAGNIFICATION_CONTROLLER_NAME =
            "com.android.server.accessibility.MagnificationController";

    private TestToggleScreenMagnificationPreferenceFragment mFragment;
    private Context mContext;
    private Resources mResources;

    private FragmentActivity mActivity;

    @Before
    public void setUpTestFragment() {
        MockitoAnnotations.initMocks(this);

        mContext = spy(ApplicationProvider.getApplicationContext());
        mActivity = Robolectric.setupActivity(FragmentActivity.class);
        mFragment = spy(new TestToggleScreenMagnificationPreferenceFragment(mContext));
        mResources = spy(mContext.getResources());
        when(mContext.getResources()).thenReturn(mResources);
        when(mFragment.getContext().getResources()).thenReturn(mResources);
        doReturn(mActivity).when(mFragment).getActivity();
    }

    @Test
    public void hasValueInSettings_putValue_hasValue() {
        setMagnificationTripleTapEnabled(/* enabled= */ true);

        assertThat(ToggleScreenMagnificationPreferenceFragment.hasMagnificationValuesInSettings(
                mContext, UserShortcutType.TRIPLETAP)).isTrue();
    }

    @Test
    public void optInAllValuesToSettings_optInValue_haveMatchString() {
        int shortcutTypes = UserShortcutType.SOFTWARE | UserShortcutType.TRIPLETAP;

        ToggleScreenMagnificationPreferenceFragment.optInAllMagnificationValuesToSettings(mContext,
                shortcutTypes);

        assertThat(getStringFromSettings(SOFTWARE_SHORTCUT_KEY)).isEqualTo(
                MAGNIFICATION_CONTROLLER_NAME);
        assertThat(getMagnificationTripleTapStatus()).isTrue();

    }

    @Test
    public void optInAllValuesToSettings_existOtherValue_optInValue_haveMatchString() {
        putStringIntoSettings(SOFTWARE_SHORTCUT_KEY, PLACEHOLDER_COMPONENT_NAME.flattenToString());

        ToggleScreenMagnificationPreferenceFragment.optInAllMagnificationValuesToSettings(mContext,
                UserShortcutType.SOFTWARE);

        assertThat(getStringFromSettings(SOFTWARE_SHORTCUT_KEY)).isEqualTo(
                PLACEHOLDER_COMPONENT_NAME.flattenToString() + ":" + MAGNIFICATION_CONTROLLER_NAME);
    }

    @Test
    public void optOutAllValuesToSettings_optOutValue_emptyString() {
        putStringIntoSettings(SOFTWARE_SHORTCUT_KEY, MAGNIFICATION_CONTROLLER_NAME);
        putStringIntoSettings(HARDWARE_SHORTCUT_KEY, MAGNIFICATION_CONTROLLER_NAME);
        setMagnificationTripleTapEnabled(/* enabled= */ true);
        int shortcutTypes =
                UserShortcutType.SOFTWARE | UserShortcutType.HARDWARE | UserShortcutType.TRIPLETAP;

        ToggleScreenMagnificationPreferenceFragment.optOutAllMagnificationValuesFromSettings(
                mContext, shortcutTypes);

        assertThat(getStringFromSettings(SOFTWARE_SHORTCUT_KEY)).isEmpty();
        assertThat(getStringFromSettings(HARDWARE_SHORTCUT_KEY)).isEmpty();
        assertThat(getMagnificationTripleTapStatus()).isFalse();
    }

    @Test
    public void optOutValueFromSettings_existOtherValue_optOutValue_haveMatchString() {
        putStringIntoSettings(SOFTWARE_SHORTCUT_KEY,
                PLACEHOLDER_COMPONENT_NAME.flattenToString() + ":" + MAGNIFICATION_CONTROLLER_NAME);
        putStringIntoSettings(HARDWARE_SHORTCUT_KEY,
                PLACEHOLDER_COMPONENT_NAME.flattenToString() + ":" + MAGNIFICATION_CONTROLLER_NAME);
        int shortcutTypes = UserShortcutType.SOFTWARE | UserShortcutType.HARDWARE;

        ToggleScreenMagnificationPreferenceFragment.optOutAllMagnificationValuesFromSettings(
                mContext, shortcutTypes);

        assertThat(getStringFromSettings(SOFTWARE_SHORTCUT_KEY)).isEqualTo(
                PLACEHOLDER_COMPONENT_NAME.flattenToString());
        assertThat(getStringFromSettings(HARDWARE_SHORTCUT_KEY)).isEqualTo(
                PLACEHOLDER_COMPONENT_NAME.flattenToString());
    }

    @Test
    public void updateShortcutPreferenceData_assignDefaultValueToVariable() {
        mFragment.updateShortcutPreferenceData();

        final int expectedType = PreferredShortcuts.retrieveUserShortcutType(mContext,
                MAGNIFICATION_CONTROLLER_NAME, UserShortcutType.SOFTWARE);
        // Compare to default UserShortcutType
        assertThat(expectedType).isEqualTo(UserShortcutType.SOFTWARE);
    }

    @Test
    public void updateShortcutPreferenceData_hasValueInSettings_assignToVariable() {
        putStringIntoSettings(SOFTWARE_SHORTCUT_KEY, MAGNIFICATION_CONTROLLER_NAME);
        setMagnificationTripleTapEnabled(/* enabled= */ true);

        mFragment.updateShortcutPreferenceData();

        final int expectedType = PreferredShortcuts.retrieveUserShortcutType(mContext,
                MAGNIFICATION_CONTROLLER_NAME, UserShortcutType.SOFTWARE);
        assertThat(expectedType).isEqualTo(UserShortcutType.SOFTWARE | UserShortcutType.TRIPLETAP);
    }

    @Test
    public void updateShortcutPreferenceData_hasValueInSharedPreference_assignToVariable() {
        final PreferredShortcut tripleTapShortcut = new PreferredShortcut(
                MAGNIFICATION_CONTROLLER_NAME, UserShortcutType.TRIPLETAP);

        putUserShortcutTypeIntoSharedPreference(mContext, tripleTapShortcut);
        mFragment.updateShortcutPreferenceData();

        final int expectedType = PreferredShortcuts.retrieveUserShortcutType(mContext,
                MAGNIFICATION_CONTROLLER_NAME, UserShortcutType.SOFTWARE);
        assertThat(expectedType).isEqualTo(UserShortcutType.TRIPLETAP);
    }

    @Test
    public void setupMagnificationEditShortcutDialog_shortcutPreferenceOff_checkboxIsEmptyValue() {
        mContext.setTheme(R.style.Theme_AppCompat);
        final AlertDialog dialog = AccessibilityDialogUtils.showEditShortcutDialog(
                mContext, DialogType.EDIT_SHORTCUT_MAGNIFICATION, PLACEHOLDER_DIALOG_TITLE,
                this::callEmptyOnClicked);
        final ShortcutPreference shortcutPreference = new ShortcutPreference(mContext, /* attrs= */
                null);
        mFragment.mShortcutPreference = shortcutPreference;

        mFragment.mShortcutPreference.setChecked(false);
        mFragment.setupMagnificationEditShortcutDialog(dialog);

        final int checkboxValue = mFragment.getShortcutTypeCheckBoxValue();
        assertThat(checkboxValue).isEqualTo(UserShortcutType.EMPTY);
    }

    @Test
    public void setupMagnificationEditShortcutDialog_shortcutPreferenceOn_checkboxIsSavedValue() {
        mContext.setTheme(R.style.Theme_AppCompat);
        final AlertDialog dialog = AccessibilityDialogUtils.showEditShortcutDialog(
                mContext, DialogType.EDIT_SHORTCUT_MAGNIFICATION, PLACEHOLDER_DIALOG_TITLE,
                this::callEmptyOnClicked);
        final ShortcutPreference shortcutPreference = new ShortcutPreference(mContext, /* attrs= */
                null);
        final PreferredShortcut tripletapShortcut = new PreferredShortcut(
                MAGNIFICATION_CONTROLLER_NAME, UserShortcutType.TRIPLETAP);
        mFragment.mShortcutPreference = shortcutPreference;

        PreferredShortcuts.saveUserShortcutType(mContext, tripletapShortcut);
        mFragment.mShortcutPreference.setChecked(true);
        mFragment.setupMagnificationEditShortcutDialog(dialog);

        final int checkboxValue = mFragment.getShortcutTypeCheckBoxValue();
        assertThat(checkboxValue).isEqualTo(UserShortcutType.TRIPLETAP);
    }

    @Test
    @Config(shadows = ShadowFragment.class)
    public void restoreValueFromSavedInstanceState_assignToVariable() {
        mContext.setTheme(R.style.Theme_AppCompat);
        final AlertDialog dialog = AccessibilityDialogUtils.showEditShortcutDialog(
                mContext, DialogType.EDIT_SHORTCUT_MAGNIFICATION, PLACEHOLDER_DIALOG_TITLE,
                this::callEmptyOnClicked);
        final Bundle savedInstanceState = new Bundle();
        mFragment.mShortcutPreference = new ShortcutPreference(mContext, /* attrs= */ null);

        savedInstanceState.putInt(KEY_SAVED_USER_SHORTCUT_TYPE,
                UserShortcutType.HARDWARE | UserShortcutType.TRIPLETAP);
        mFragment.onCreate(savedInstanceState);
        mFragment.setupMagnificationEditShortcutDialog(dialog);
        final int value = mFragment.getShortcutTypeCheckBoxValue();
        mFragment.saveNonEmptyUserShortcutType(value);

        final int expectedType = PreferredShortcuts.retrieveUserShortcutType(mContext,
                MAGNIFICATION_CONTROLLER_NAME, UserShortcutType.SOFTWARE);
        assertThat(value).isEqualTo(6);
        assertThat(expectedType).isEqualTo(UserShortcutType.HARDWARE | UserShortcutType.TRIPLETAP);
    }

    @Test
    public void onCreateView_notSupportsMagnificationArea_settingsPreferenceIsNull() {
        when(mResources.getBoolean(
                com.android.internal.R.bool.config_magnification_area))
                .thenReturn(false);

        mFragment.onCreateView(LayoutInflater.from(mContext), mock(ViewGroup.class), Bundle.EMPTY);

        assertThat(mFragment.mSettingsPreference).isNull();
    }

    @Test
    public void onCreateView_setDialogDelegateAndAddTheControllerToLifeCycleObserver() {
        mFragment.onCreateView(LayoutInflater.from(mContext), mock(ViewGroup.class), Bundle.EMPTY);

        verify(mFragment).setDialogDelegate(any(MagnificationModePreferenceController.class));
        verify(mFragment.mSpyLifeyCycle).addObserver(
                any(MagnificationModePreferenceController.class));
    }

    @Test
    public void onCreateDialog_setDialogDelegate_invokeDialogDelegate() {
        final DialogCreatable dialogDelegate = mock(DialogCreatable.class, RETURNS_DEEP_STUBS);
        when(dialogDelegate.getDialogMetricsCategory(anyInt())).thenReturn(1);
        mFragment.setDialogDelegate(dialogDelegate);

        mFragment.onCreateDialog(1);
        mFragment.getDialogMetricsCategory(1);

        verify(dialogDelegate).onCreateDialog(1);
        verify(dialogDelegate).getDialogMetricsCategory(1);
    }

    private void putStringIntoSettings(String key, String componentName) {
        Settings.Secure.putString(mContext.getContentResolver(), key, componentName);
    }

    private void putUserShortcutTypeIntoSharedPreference(Context context,
            PreferredShortcut shortcut) {
        PreferredShortcuts.saveUserShortcutType(context, shortcut);
    }

    private void setMagnificationTripleTapEnabled(boolean enabled) {
        Settings.Secure.putInt(mContext.getContentResolver(), TRIPLETAP_SHORTCUT_KEY,
                enabled ? ON : OFF);
    }

    private String getStringFromSettings(String key) {
        return Settings.Secure.getString(mContext.getContentResolver(), key);
    }

    private boolean getMagnificationTripleTapStatus() {
        return Settings.Secure.getInt(mContext.getContentResolver(), TRIPLETAP_SHORTCUT_KEY, OFF)
                == ON;
    }

    private void callEmptyOnClicked(DialogInterface dialog, int which) {}

    /**
     * a test fragment that initializes PreferenceScreen for testing.
     */
    static class TestToggleScreenMagnificationPreferenceFragment
            extends ToggleScreenMagnificationPreferenceFragment {

        private final Lifecycle mSpyLifeyCycle = Mockito.mock(Lifecycle.class);

        private final Context mContext;
        private final PreferenceManager mPreferenceManager;

        TestToggleScreenMagnificationPreferenceFragment(Context context) {
            super();
            mContext = context;
            mPreferenceManager = new PreferenceManager(context);
            mPreferenceManager.setPreferences(mPreferenceManager.createPreferenceScreen(context));
            setArguments(new Bundle());
        }

        @Override
        protected void onPreferenceToggled(String preferenceKey, boolean enabled) {
        }

        @Override
        public int getMetricsCategory() {
            return 0;
        }

        @Override
        int getUserShortcutTypes() {
            return 0;
        }

        @Override
        public int getPreferenceScreenResId() {
            return R.xml.placeholder_prefs;
        }

        @Override
        public PreferenceScreen getPreferenceScreen() {
            return mPreferenceManager.getPreferenceScreen();
        }

        @Override
        public <T extends Preference> T findPreference(CharSequence key) {
            if (TextUtils.isEmpty(key)) {
                return null;
            }
            return getPreferenceScreen().findPreference(key);
        }

        @Override
        public PreferenceManager getPreferenceManager() {
            return mPreferenceManager;
        }

        @Override
        public void onViewCreated(View view, Bundle savedInstanceState) {
            // do nothing
        }

        @Override
        public void onDestroyView() {
            // do nothing
        }

        @Override
        public void addPreferencesFromResource(@XmlRes int preferencesResId) {
            // do nothing
        }

        @Override
        protected void updateShortcutPreference() {
            // UI related function, do nothing in tests
        }

        @Override
        public Lifecycle getSettingsLifecycle() {
            return mSpyLifeyCycle;
        }

        @Override
        public Context getContext() {
            return mContext;
        }
    }
}
