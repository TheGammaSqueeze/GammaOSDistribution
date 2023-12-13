package com.android.settings.fuelgauge.batterysaver;

import static com.google.common.truth.Truth.assertThat;

import static org.mockito.ArgumentMatchers.any;
import static org.mockito.Mockito.spy;
import static org.mockito.Mockito.never;
import static org.mockito.Mockito.verify;

import android.content.ContentResolver;
import android.content.Context;
import android.os.PowerManager;
import android.provider.Settings;
import android.provider.Settings.Global;

import androidx.preference.PreferenceScreen;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;
import org.robolectric.RobolectricTestRunner;
import org.robolectric.RuntimeEnvironment;

@RunWith(RobolectricTestRunner.class)
public class BatterySaverScheduleSeekBarControllerTest {

    private Context mContext;
    private ContentResolver mResolver;
    private BatterySaverScheduleSeekBarController mController;
    @Mock
    private PreferenceScreen mScreen;

    @Before
    public void setUp() {
        MockitoAnnotations.initMocks(this);
        mContext = RuntimeEnvironment.application;
        mController = new BatterySaverScheduleSeekBarController(mContext);
        mResolver = mContext.getContentResolver();
        mController.mSeekBarPreference = spy(mController.mSeekBarPreference);
    }

    @Test
    public void onPreferenceChange_updatesSettingsGlobal() {
        final CharSequence expectedTitle = "50%";
        Settings.Global.putInt(mResolver, Global.LOW_POWER_MODE_TRIGGER_LEVEL, 5);
        mController.onPreferenceChange(mController.mSeekBarPreference, 10);
        assertThat(Settings.Global.getInt(mResolver, Global.LOW_POWER_MODE_TRIGGER_LEVEL, -1))
                .isEqualTo(50);

        assertThat(mController.mSeekBarPreference.getTitle()).isEqualTo(expectedTitle);
        verify(mController.mSeekBarPreference).overrideSeekBarStateDescription(expectedTitle);
    }

    @Test
    public void updateSeekBar_routineMode_hasCorrectProperties() {
        Settings.Global.putInt(mResolver, Global.AUTOMATIC_POWER_SAVE_MODE,
                PowerManager.POWER_SAVE_MODE_TRIGGER_DYNAMIC);
        mController.updateSeekBar();
        assertThat(mController.mSeekBarPreference.isVisible()).isFalse();
        verify(mController.mSeekBarPreference, never()).overrideSeekBarStateDescription(any());
    }

    @Test
    public void updateSeekBar_percentageMode_hasCorrectProperties() {
        final CharSequence expectedTitle = "5%";
        Settings.Global.putInt(mResolver, Global.AUTOMATIC_POWER_SAVE_MODE,
                PowerManager.POWER_SAVE_MODE_TRIGGER_PERCENTAGE);
        Settings.Global.putInt(mResolver, Global.LOW_POWER_MODE_TRIGGER_LEVEL, 5);
        mController.updateSeekBar();

        assertThat(mController.mSeekBarPreference.isVisible()).isTrue();
        assertThat(mController.mSeekBarPreference.getTitle()).isEqualTo(expectedTitle);
        verify(mController.mSeekBarPreference).overrideSeekBarStateDescription(expectedTitle);
    }

    @Test
    public void updateSeekBar_noneMode_hasCorrectProperties() {
        Settings.Global.putInt(mResolver, Global.AUTOMATIC_POWER_SAVE_MODE,
                PowerManager.POWER_SAVE_MODE_TRIGGER_PERCENTAGE);
        Settings.Global.putInt(mResolver, Global.LOW_POWER_MODE_TRIGGER_LEVEL, 0);
        mController.updateSeekBar();
        assertThat(mController.mSeekBarPreference.isVisible()).isFalse();
        verify(mController.mSeekBarPreference, never()).overrideSeekBarStateDescription(any());
    }

    @Test
    public void addToScreen_addsToEnd() {
        Settings.Global.putInt(mResolver, Global.AUTOMATIC_POWER_SAVE_MODE,
                PowerManager.POWER_SAVE_MODE_TRIGGER_PERCENTAGE);
        Settings.Global.putInt(mResolver, Global.LOW_POWER_MODE_TRIGGER_LEVEL, 15);
        mController.addToScreen(mScreen);
        assertThat(mController.mSeekBarPreference.getOrder()).isEqualTo(100);
    }

}
