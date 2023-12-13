package com.android.systemui.demomode;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.os.UserHandle;
import android.util.Log;
import com.android.systemui.Dumpable;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.statusbar.policy.CallbackController;
import com.android.systemui.util.Assert;
import com.android.systemui.util.settings.GlobalSettings;
import java.io.FileDescriptor;
import java.io.PrintWriter;

/**
 * Handles system broadcasts for [DemoMode]
 *
 * Injected via [DemoModeModule]
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000t\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0007\n\u0002\u0010$\n\u0002\u0010\u000e\n\u0002\u0010!\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u0011\n\u0002\b\f\n\u0002\u0010\b\n\u0002\b\u0002\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u00012\u00020\u0003B\u001d\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\u0010\u0010\u001c\u001a\u00020\u001d2\u0006\u0010\u001e\u001a\u00020\u0002H\u0016J\u0016\u0010\u001f\u001a\u00020\u001d2\u0006\u0010 \u001a\u00020\u00172\u0006\u0010!\u001a\u00020\"J-\u0010#\u001a\u00020\u001d2\u0006\u0010$\u001a\u00020%2\u0006\u0010&\u001a\u00020\'2\u000e\u0010!\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u00170(H\u0016\u00a2\u0006\u0002\u0010)J\b\u0010*\u001a\u00020\u001dH\u0002J\b\u0010+\u001a\u00020\u001dH\u0002J\u0006\u0010,\u001a\u00020\u001dJ\u0010\u0010-\u001a\u00020\u001d2\u0006\u0010\u001e\u001a\u00020\u0002H\u0016J\u0006\u0010.\u001a\u00020\u001dJ\u000e\u0010/\u001a\u00020\u001d2\u0006\u00100\u001a\u00020\u000eJ\u0006\u00101\u001a\u00020\u001dJ\u0018\u00102\u001a\u00020\u001d2\u0006\u00103\u001a\u00020\u00172\u0006\u00104\u001a\u000205H\u0002J\u0010\u00106\u001a\u00020\u001d2\u0006\u00107\u001a\u00020\u000eH\u0002R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001c\u0010\u000f\u001a\u00020\u000e8FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000f\u0010\u0010\"\u0004\b\u0011\u0010\u0012R\u001a\u0010\u0013\u001a\u00020\u000eX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0013\u0010\u0010\"\u0004\b\u0014\u0010\u0012R \u0010\u0015\u001a\u0014\u0012\u0004\u0012\u00020\u0017\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00020\u00180\u0016X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0019\u001a\b\u0012\u0004\u0012\u00020\u00020\u0018X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001a\u001a\u00020\u001bX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/demomode/DemoModeController;", "Lcom/android/systemui/statusbar/policy/CallbackController;", "Lcom/android/systemui/demomode/DemoMode;", "Lcom/android/systemui/Dumpable;", "context", "Landroid/content/Context;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "globalSettings", "Lcom/android/systemui/util/settings/GlobalSettings;", "(Landroid/content/Context;Lcom/android/systemui/dump/DumpManager;Lcom/android/systemui/util/settings/GlobalSettings;)V", "broadcastReceiver", "Landroid/content/BroadcastReceiver;", "initialized", "", "isAvailable", "()Z", "setAvailable", "(Z)V", "isInDemoMode", "setInDemoMode", "receiverMap", "", "", "", "receivers", "tracker", "Lcom/android/systemui/demomode/DemoModeAvailabilityTracker;", "addCallback", "", "listener", "dispatchDemoCommand", "command", "args", "Landroid/os/Bundle;", "dump", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "enterDemoMode", "exitDemoMode", "initialize", "removeCallback", "requestFinishDemoMode", "requestSetDemoModeAllowed", "allowed", "requestStartDemoMode", "setGlobal", "key", "value", "", "setIsDemoModeAllowed", "enabled"})
public final class DemoModeController implements com.android.systemui.statusbar.policy.CallbackController<com.android.systemui.demomode.DemoMode>, com.android.systemui.Dumpable {
    private boolean isInDemoMode = false;
    private boolean isAvailable = false;
    private boolean initialized = false;
    private final java.util.List<com.android.systemui.demomode.DemoMode> receivers = null;
    private final java.util.Map<java.lang.String, java.util.List<com.android.systemui.demomode.DemoMode>> receiverMap = null;
    private final com.android.systemui.demomode.DemoModeAvailabilityTracker tracker = null;
    private final android.content.BroadcastReceiver broadcastReceiver = null;
    private final android.content.Context context = null;
    private final com.android.systemui.dump.DumpManager dumpManager = null;
    private final com.android.systemui.util.settings.GlobalSettings globalSettings = null;
    
    public final boolean isInDemoMode() {
        return false;
    }
    
    public final void setInDemoMode(boolean p0) {
    }
    
    public final boolean isAvailable() {
        return false;
    }
    
    public final void setAvailable(boolean p0) {
    }
    
    public final void initialize() {
    }
    
    @java.lang.Override()
    public void addCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.demomode.DemoMode listener) {
    }
    
    @java.lang.Override()
    public void removeCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.demomode.DemoMode listener) {
    }
    
    private final void setIsDemoModeAllowed(boolean enabled) {
    }
    
    private final void enterDemoMode() {
    }
    
    private final void exitDemoMode() {
    }
    
    public final void dispatchDemoCommand(@org.jetbrains.annotations.NotNull()
    java.lang.String command, @org.jetbrains.annotations.NotNull()
    android.os.Bundle args) {
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    public final void requestSetDemoModeAllowed(boolean allowed) {
    }
    
    public final void requestStartDemoMode() {
    }
    
    public final void requestFinishDemoMode() {
    }
    
    private final void setGlobal(java.lang.String key, int value) {
    }
    
    public DemoModeController(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.settings.GlobalSettings globalSettings) {
        super();
    }
}