package com.android.systemui.sensorprivacy;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.hardware.SensorPrivacyManager;
import android.os.Bundle;
import android.os.Handler;
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.statusbar.phone.KeyguardDismissUtil;
import com.android.systemui.statusbar.policy.IndividualSensorPrivacyController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import javax.inject.Inject;

/**
 * Dialog to be shown on top of apps that are attempting to use a sensor (e.g. microphone) which is
 * currently in "sensor privacy mode", aka. muted.
 *
 * <p>The dialog is started for the user the app is running for which might be a secondary users.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000j\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0005\u0018\u0000 *2\u00020\u00012\u00020\u00022\u00020\u0003:\u0001*B)\b\u0007\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\b\b\u0001\u0010\n\u001a\u00020\u000b\u00a2\u0006\u0002\u0010\fJ\b\u0010\u0017\u001a\u00020\u0018H\u0002J\b\u0010\u0019\u001a\u00020\u0018H\u0016J\u001a\u0010\u001a\u001a\u00020\u00182\b\u0010\u001b\u001a\u0004\u0018\u00010\u001c2\u0006\u0010\u001d\u001a\u00020\u0010H\u0016J\u0012\u0010\u001e\u001a\u00020\u00182\b\u0010\u001f\u001a\u0004\u0018\u00010 H\u0014J\b\u0010!\u001a\u00020\u0018H\u0014J\u0012\u0010\"\u001a\u00020\u00182\b\u0010\u001b\u001a\u0004\u0018\u00010\u001cH\u0016J\u0012\u0010#\u001a\u00020\u00182\b\u0010$\u001a\u0004\u0018\u00010%H\u0014J\b\u0010&\u001a\u00020\u0018H\u0014J\b\u0010\'\u001a\u00020\u0018H\u0014J\u0010\u0010(\u001a\u00020\u00182\u0006\u0010)\u001a\u00020\u0016H\u0002R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\r\u001a\u0004\u0018\u00010\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0014X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0015\u001a\u00020\u0016X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/sensorprivacy/SensorUseStartedActivity;", "Landroid/app/Activity;", "Landroid/content/DialogInterface$OnClickListener;", "Landroid/content/DialogInterface$OnDismissListener;", "sensorPrivacyController", "Lcom/android/systemui/statusbar/policy/IndividualSensorPrivacyController;", "keyguardStateController", "Lcom/android/systemui/statusbar/policy/KeyguardStateController;", "keyguardDismissUtil", "Lcom/android/systemui/statusbar/phone/KeyguardDismissUtil;", "bgHandler", "Landroid/os/Handler;", "(Lcom/android/systemui/statusbar/policy/IndividualSensorPrivacyController;Lcom/android/systemui/statusbar/policy/KeyguardStateController;Lcom/android/systemui/statusbar/phone/KeyguardDismissUtil;Landroid/os/Handler;)V", "mDialog", "Landroid/app/AlertDialog;", "sensor", "", "sensorPrivacyListener", "Lcom/android/systemui/statusbar/policy/IndividualSensorPrivacyController$Callback;", "sensorUsePackageName", "", "unsuppressImmediately", "", "disableSensorPrivacy", "", "onBackPressed", "onClick", "dialog", "Landroid/content/DialogInterface;", "which", "onCreate", "savedInstanceState", "Landroid/os/Bundle;", "onDestroy", "onDismiss", "onNewIntent", "intent", "Landroid/content/Intent;", "onStart", "onStop", "setSuppressed", "suppressed", "Companion"})
public final class SensorUseStartedActivity extends android.app.Activity implements android.content.DialogInterface.OnClickListener, android.content.DialogInterface.OnDismissListener {
    private int sensor = -1;
    private java.lang.String sensorUsePackageName;
    private boolean unsuppressImmediately = false;
    private com.android.systemui.statusbar.policy.IndividualSensorPrivacyController.Callback sensorPrivacyListener;
    private android.app.AlertDialog mDialog;
    private final com.android.systemui.statusbar.policy.IndividualSensorPrivacyController sensorPrivacyController = null;
    private final com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController = null;
    private final com.android.systemui.statusbar.phone.KeyguardDismissUtil keyguardDismissUtil = null;
    private final android.os.Handler bgHandler = null;
    private static final java.lang.String LOG_TAG = null;
    private static final long SUPPRESS_REMINDERS_REMOVAL_DELAY_MILLIS = 2000L;
    private static final long UNLOCK_DELAY_MILLIS = 200L;
    public static final int CAMERA = android.hardware.SensorPrivacyManager.Sensors.CAMERA;
    public static final int MICROPHONE = android.hardware.SensorPrivacyManager.Sensors.MICROPHONE;
    public static final int ALL_SENSORS = java.lang.Integer.MAX_VALUE;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.sensorprivacy.SensorUseStartedActivity.Companion Companion = null;
    
    @java.lang.Override()
    protected void onCreate(@org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState) {
    }
    
    @java.lang.Override()
    protected void onStart() {
    }
    
    @java.lang.Override()
    public void onClick(@org.jetbrains.annotations.Nullable()
    android.content.DialogInterface dialog, int which) {
    }
    
    @java.lang.Override()
    protected void onStop() {
    }
    
    @java.lang.Override()
    protected void onDestroy() {
    }
    
    @java.lang.Override()
    public void onBackPressed() {
    }
    
    @java.lang.Override()
    protected void onNewIntent(@org.jetbrains.annotations.Nullable()
    android.content.Intent intent) {
    }
    
    private final void disableSensorPrivacy() {
    }
    
    private final void setSuppressed(boolean suppressed) {
    }
    
    @java.lang.Override()
    public void onDismiss(@org.jetbrains.annotations.Nullable()
    android.content.DialogInterface dialog) {
    }
    
    @javax.inject.Inject()
    public SensorUseStartedActivity(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.IndividualSensorPrivacyController sensorPrivacyController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.KeyguardDismissUtil keyguardDismissUtil, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Background()
    android.os.Handler bgHandler) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\"\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0010\t\n\u0000\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0080T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0080T\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0006\u001a\n \b*\u0004\u0018\u00010\u00070\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0004X\u0080T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\u000bX\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/sensorprivacy/SensorUseStartedActivity$Companion;", "", "()V", "ALL_SENSORS", "", "CAMERA", "LOG_TAG", "", "kotlin.jvm.PlatformType", "MICROPHONE", "SUPPRESS_REMINDERS_REMOVAL_DELAY_MILLIS", "", "UNLOCK_DELAY_MILLIS"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}