package com.android.systemui.privacy.logging;

import android.permission.PermGroupUsage;
import com.android.systemui.log.LogBuffer;
import com.android.systemui.log.LogLevel;
import com.android.systemui.log.LogMessage;
import com.android.systemui.log.dagger.PrivacyLog;
import com.android.systemui.privacy.PrivacyDialog;
import com.android.systemui.privacy.PrivacyItem;
import java.text.SimpleDateFormat;
import java.util.Locale;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000f\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0010\t\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\b\u0004\u0018\u00002\u00020\u0001B\u0011\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0016\u0010\u0005\u001a\u00020\u00062\f\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\t0\bH\u0002JE\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\r2\u0017\u0010\u000e\u001a\u0013\u0012\u0004\u0012\u00020\u0010\u0012\u0004\u0012\u00020\u000b0\u000f\u00a2\u0006\u0002\b\u00112\u0019\b\b\u0010\u0012\u001a\u0013\u0012\u0004\u0012\u00020\u0010\u0012\u0004\u0012\u00020\u00060\u000f\u00a2\u0006\u0002\b\u0011H\u0082\bJ\u000e\u0010\u0013\u001a\u00020\u000b2\u0006\u0010\u0014\u001a\u00020\u0015J\u0014\u0010\u0016\u001a\u00020\u000b2\f\u0010\u0017\u001a\b\u0012\u0004\u0012\u00020\u00180\bJ\u0006\u0010\u0019\u001a\u00020\u000bJ\u0006\u0010\u001a\u001a\u00020\u000bJ\u0014\u0010\u001b\u001a\u00020\u000b2\f\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\t0\bJ\u000e\u0010\u001c\u001a\u00020\u000b2\u0006\u0010\u001d\u001a\u00020\u001eJ\u0014\u0010\u001f\u001a\u00020\u000b2\f\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\t0\bJ\u0014\u0010 \u001a\u00020\u000b2\f\u0010!\u001a\b\u0012\u0004\u0012\u00020\"0\bJ\u0016\u0010#\u001a\u00020\u000b2\u0006\u0010$\u001a\u00020\u00062\u0006\u0010%\u001a\u00020\u0018J\u001e\u0010&\u001a\u00020\u000b2\u0006\u0010\'\u001a\u00020\u00152\u0006\u0010(\u001a\u00020\u00152\u0006\u0010)\u001a\u00020\u0015J\u0014\u0010*\u001a\u00020\u000b2\f\u0010!\u001a\b\u0012\u0004\u0012\u00020+0\bJ&\u0010,\u001a\u00020\u000b2\u0006\u0010-\u001a\u00020\u00182\u0006\u0010.\u001a\u00020\u00182\u0006\u0010$\u001a\u00020\u00062\u0006\u0010/\u001a\u00020\u0015R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/privacy/logging/PrivacyLogger;", "", "buffer", "Lcom/android/systemui/log/LogBuffer;", "(Lcom/android/systemui/log/LogBuffer;)V", "listToString", "", "list", "", "Lcom/android/systemui/privacy/PrivacyItem;", "log", "", "logLevel", "Lcom/android/systemui/log/LogLevel;", "initializer", "Lkotlin/Function1;", "Lcom/android/systemui/log/LogMessage;", "Lkotlin/ExtensionFunctionType;", "printer", "logChipVisible", "visible", "", "logCurrentProfilesChanged", "profiles", "", "logEmptyDialog", "logPrivacyDialogDismissed", "logPrivacyItemsToHold", "logPrivacyItemsUpdateScheduled", "delay", "", "logRetrievedPrivacyItemsList", "logShowDialogContents", "contents", "Lcom/android/systemui/privacy/PrivacyDialog$PrivacyElement;", "logStartSettingsActivityFromDialog", "packageName", "userId", "logStatusBarIconsVisible", "showCamera", "showMicrophone", "showLocation", "logUnfilteredPermGroupUsage", "Landroid/permission/PermGroupUsage;", "logUpdatedItemFromAppOps", "code", "uid", "active"})
public final class PrivacyLogger {
    private final com.android.systemui.log.LogBuffer buffer = null;
    
    public final void logUpdatedItemFromAppOps(int code, int uid, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, boolean active) {
    }
    
    public final void logRetrievedPrivacyItemsList(@org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.privacy.PrivacyItem> list) {
    }
    
    public final void logPrivacyItemsToHold(@org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.privacy.PrivacyItem> list) {
    }
    
    public final void logPrivacyItemsUpdateScheduled(long delay) {
    }
    
    public final void logCurrentProfilesChanged(@org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.Integer> profiles) {
    }
    
    public final void logChipVisible(boolean visible) {
    }
    
    public final void logStatusBarIconsVisible(boolean showCamera, boolean showMicrophone, boolean showLocation) {
    }
    
    public final void logUnfilteredPermGroupUsage(@org.jetbrains.annotations.NotNull()
    java.util.List<android.permission.PermGroupUsage> contents) {
    }
    
    public final void logShowDialogContents(@org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.privacy.PrivacyDialog.PrivacyElement> contents) {
    }
    
    public final void logEmptyDialog() {
    }
    
    public final void logPrivacyDialogDismissed() {
    }
    
    public final void logStartSettingsActivityFromDialog(@org.jetbrains.annotations.NotNull()
    java.lang.String packageName, int userId) {
    }
    
    private final java.lang.String listToString(java.util.List<com.android.systemui.privacy.PrivacyItem> list) {
        return null;
    }
    
    private final void log(com.android.systemui.log.LogLevel logLevel, kotlin.jvm.functions.Function1<? super com.android.systemui.log.LogMessage, kotlin.Unit> initializer, kotlin.jvm.functions.Function1<? super com.android.systemui.log.LogMessage, java.lang.String> printer) {
    }
    
    @javax.inject.Inject()
    public PrivacyLogger(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.log.dagger.PrivacyLog()
    com.android.systemui.log.LogBuffer buffer) {
        super();
    }
}