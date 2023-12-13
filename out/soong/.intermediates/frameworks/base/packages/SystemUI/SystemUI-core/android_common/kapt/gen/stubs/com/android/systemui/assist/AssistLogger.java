package com.android.systemui.assist;

import android.content.ComponentName;
import android.content.Context;
import android.content.pm.PackageManager;
import android.util.Log;
import com.android.internal.app.AssistUtils;
import com.android.internal.logging.InstanceId;
import com.android.internal.logging.InstanceIdSequence;
import com.android.internal.logging.UiEventLogger;
import com.android.internal.util.FrameworkStatsLog;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.dagger.SysUISingleton;
import javax.inject.Inject;

/**
 * Class for reporting events related to Assistant sessions.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000V\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0002\b\u0006\b\u0017\u0018\u0000 )2\u00020\u0001:\u0001)B\'\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\b\u0010\u0013\u001a\u00020\u0014H\u0004J\b\u0010\u0015\u001a\u00020\u0016H\u0004J\u0010\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u0016H\u0004J\b\u0010\u001a\u001a\u00020\u000eH\u0004J+\u0010\u001b\u001a\u00020\u00142\u0006\u0010\u001c\u001a\u00020\u001d2\n\b\u0002\u0010\u0019\u001a\u0004\u0018\u00010\u00162\n\b\u0002\u0010\u001e\u001a\u0004\u0018\u00010\u0018\u00a2\u0006\u0002\u0010\u001fJ3\u0010 \u001a\u00020\u00142\u0006\u0010!\u001a\u00020\u00182\u0006\u0010\"\u001a\u00020#2\n\b\u0002\u0010\u0019\u001a\u0004\u0018\u00010\u00162\n\b\u0002\u0010$\u001a\u0004\u0018\u00010\u0018\u00a2\u0006\u0002\u0010%J\b\u0010&\u001a\u00020\u0014H\u0014J\u000e\u0010\'\u001a\u00020\u00142\u0006\u0010(\u001a\u00020\u001dR\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0002\u001a\u00020\u0003X\u0084\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u0010\u0010\r\u001a\u0004\u0018\u00010\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0004\u001a\u00020\u0005X\u0084\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u0012"}, d2 = {"Lcom/android/systemui/assist/AssistLogger;", "", "context", "Landroid/content/Context;", "uiEventLogger", "Lcom/android/internal/logging/UiEventLogger;", "assistUtils", "Lcom/android/internal/app/AssistUtils;", "phoneStateMonitor", "Lcom/android/systemui/assist/PhoneStateMonitor;", "(Landroid/content/Context;Lcom/android/internal/logging/UiEventLogger;Lcom/android/internal/app/AssistUtils;Lcom/android/systemui/assist/PhoneStateMonitor;)V", "getContext", "()Landroid/content/Context;", "currentInstanceId", "Lcom/android/internal/logging/InstanceId;", "instanceIdSequence", "Lcom/android/internal/logging/InstanceIdSequence;", "getUiEventLogger", "()Lcom/android/internal/logging/UiEventLogger;", "clearInstanceId", "", "getAssistantComponentForCurrentUser", "Landroid/content/ComponentName;", "getAssistantUid", "", "assistantComponent", "getOrCreateInstanceId", "reportAssistantInvocationEvent", "invocationEvent", "Lcom/android/internal/logging/UiEventLogger$UiEventEnum;", "deviceState", "(Lcom/android/internal/logging/UiEventLogger$UiEventEnum;Landroid/content/ComponentName;Ljava/lang/Integer;)V", "reportAssistantInvocationEventFromLegacy", "legacyInvocationType", "isInvocationComplete", "", "legacyDeviceState", "(IZLandroid/content/ComponentName;Ljava/lang/Integer;)V", "reportAssistantInvocationExtraData", "reportAssistantSessionEvent", "sessionEvent", "Companion"})
@com.android.systemui.dagger.SysUISingleton()
public class AssistLogger {
    private final com.android.internal.logging.InstanceIdSequence instanceIdSequence = null;
    private com.android.internal.logging.InstanceId currentInstanceId;
    @org.jetbrains.annotations.NotNull()
    private final android.content.Context context = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.internal.logging.UiEventLogger uiEventLogger = null;
    private final com.android.internal.app.AssistUtils assistUtils = null;
    private final com.android.systemui.assist.PhoneStateMonitor phoneStateMonitor = null;
    @org.jetbrains.annotations.NotNull()
    protected static final java.lang.String TAG = "AssistLogger";
    private static final int INSTANCE_ID_MAX = 1048576;
    private static final java.util.Set<com.android.systemui.assist.AssistantSessionEvent> SESSION_END_EVENTS = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.assist.AssistLogger.Companion Companion = null;
    
    public final void reportAssistantInvocationEventFromLegacy(int legacyInvocationType, boolean isInvocationComplete, @org.jetbrains.annotations.Nullable()
    android.content.ComponentName assistantComponent, @org.jetbrains.annotations.Nullable()
    java.lang.Integer legacyDeviceState) {
    }
    
    public final void reportAssistantInvocationEvent(@org.jetbrains.annotations.NotNull()
    com.android.internal.logging.UiEventLogger.UiEventEnum invocationEvent, @org.jetbrains.annotations.Nullable()
    android.content.ComponentName assistantComponent, @org.jetbrains.annotations.Nullable()
    java.lang.Integer deviceState) {
    }
    
    public final void reportAssistantSessionEvent(@org.jetbrains.annotations.NotNull()
    com.android.internal.logging.UiEventLogger.UiEventEnum sessionEvent) {
    }
    
    protected void reportAssistantInvocationExtraData() {
    }
    
    @org.jetbrains.annotations.NotNull()
    protected final com.android.internal.logging.InstanceId getOrCreateInstanceId() {
        return null;
    }
    
    protected final void clearInstanceId() {
    }
    
    @org.jetbrains.annotations.NotNull()
    protected final android.content.ComponentName getAssistantComponentForCurrentUser() {
        return null;
    }
    
    protected final int getAssistantUid(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName assistantComponent) {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    protected final android.content.Context getContext() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    protected final com.android.internal.logging.UiEventLogger getUiEventLogger() {
        return null;
    }
    
    @javax.inject.Inject()
    public AssistLogger(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.internal.logging.UiEventLogger uiEventLogger, @org.jetbrains.annotations.NotNull()
    com.android.internal.app.AssistUtils assistUtils, @org.jetbrains.annotations.NotNull()
    com.android.systemui.assist.PhoneStateMonitor phoneStateMonitor) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\"\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0084T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/assist/AssistLogger$Companion;", "", "()V", "INSTANCE_ID_MAX", "", "SESSION_END_EVENTS", "", "Lcom/android/systemui/assist/AssistantSessionEvent;", "TAG", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}