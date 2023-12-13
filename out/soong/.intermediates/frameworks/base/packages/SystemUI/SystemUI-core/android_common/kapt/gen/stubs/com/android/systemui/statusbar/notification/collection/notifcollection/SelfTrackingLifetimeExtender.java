package com.android.systemui.statusbar.notification.collection.notifcollection;

import android.os.Handler;
import android.util.ArrayMap;
import android.util.Log;
import com.android.systemui.Dumpable;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import java.io.FileDescriptor;
import java.io.PrintWriter;

/**
 * A helpful class that implements the core contract of the lifetime extender internally,
 * making it easier for coordinators to interact with them
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000b\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\b\u0006\n\u0002\u0010\t\n\u0002\b\t\n\u0002\u0010\b\n\u0000\b&\u0018\u00002\u00020\u00012\u00020\u0002B%\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0004\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\u000e\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u0010J+\u0010\u0016\u001a\u00020\u00142\u0006\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u001a2\u000e\u0010\u001b\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u00040\u001c\u00a2\u0006\u0002\u0010\u001dJ\u0006\u0010\u001e\u001a\u00020\u0014J\u000e\u0010\u001f\u001a\u00020\u00142\u0006\u0010 \u001a\u00020\u0004J\u0016\u0010!\u001a\u00020\u00142\u0006\u0010 \u001a\u00020\u00042\u0006\u0010\"\u001a\u00020#J\u0006\u0010$\u001a\u00020\u0004J\u000e\u0010%\u001a\u00020\u00072\u0006\u0010 \u001a\u00020\u0004J\u0010\u0010&\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u0010H\u0016J\u0010\u0010\'\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u0010H\u0016J\u0010\u0010(\u001a\u00020\u00072\u0006\u0010\u0015\u001a\u00020\u0010H&J\u000e\u0010)\u001a\u00020\u00142\u0006\u0010*\u001a\u00020\fJ\u0016\u0010+\u001a\u00020\u00072\u0006\u0010\u0015\u001a\u00020\u00102\u0006\u0010,\u001a\u00020-J\b\u0010.\u001a\u00020\u0014H\u0002R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R \u0010\u000e\u001a\u000e\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u00100\u000fX\u0084\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u0012R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/notifcollection/SelfTrackingLifetimeExtender;", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/NotifLifetimeExtender;", "Lcom/android/systemui/Dumpable;", "tag", "", "name", "debug", "", "mainHandler", "Landroid/os/Handler;", "(Ljava/lang/String;Ljava/lang/String;ZLandroid/os/Handler;)V", "mCallback", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/NotifLifetimeExtender$OnEndLifetimeExtensionCallback;", "mEnding", "mEntriesExtended", "Landroid/util/ArrayMap;", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "getMEntriesExtended", "()Landroid/util/ArrayMap;", "cancelLifetimeExtension", "", "entry", "dump", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "endAllLifetimeExtensions", "endLifetimeExtension", "key", "endLifetimeExtensionAfterDelay", "delayMillis", "", "getName", "isExtending", "onCanceledLifetimeExtension", "onStartedLifetimeExtension", "queryShouldExtendLifetime", "setCallback", "callback", "shouldExtendLifetime", "reason", "", "warnIfEnding"})
public abstract class SelfTrackingLifetimeExtender implements com.android.systemui.statusbar.notification.collection.notifcollection.NotifLifetimeExtender, com.android.systemui.Dumpable {
    private com.android.systemui.statusbar.notification.collection.notifcollection.NotifLifetimeExtender.OnEndLifetimeExtensionCallback mCallback;
    @org.jetbrains.annotations.NotNull()
    private final android.util.ArrayMap<java.lang.String, com.android.systemui.statusbar.notification.collection.NotificationEntry> mEntriesExtended = null;
    private boolean mEnding = false;
    private final java.lang.String tag = null;
    private final java.lang.String name = null;
    private final boolean debug = false;
    private final android.os.Handler mainHandler = null;
    
    @org.jetbrains.annotations.NotNull()
    protected final android.util.ArrayMap<java.lang.String, com.android.systemui.statusbar.notification.collection.NotificationEntry> getMEntriesExtended() {
        return null;
    }
    
    /**
     * When debugging, warn if the call is happening during and "end lifetime extension" call.
     *
     * Note: this will warn a lot! The pipeline explicitly re-invokes all lifetime extenders
     * whenever one ends, giving all of them a chance to re-up their lifetime extension.
     */
    private final void warnIfEnding() {
    }
    
    public final void endAllLifetimeExtensions() {
    }
    
    public final void endLifetimeExtensionAfterDelay(@org.jetbrains.annotations.NotNull()
    java.lang.String key, long delayMillis) {
    }
    
    public final void endLifetimeExtension(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    public final boolean isExtending(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public final java.lang.String getName() {
        return null;
    }
    
    @java.lang.Override()
    public final boolean shouldExtendLifetime(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry, int reason) {
        return false;
    }
    
    @java.lang.Override()
    public final void cancelLifetimeExtension(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
    }
    
    public abstract boolean queryShouldExtendLifetime(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry);
    
    public void onStartedLifetimeExtension(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
    }
    
    public void onCanceledLifetimeExtension(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
    }
    
    @java.lang.Override()
    public final void setCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.notifcollection.NotifLifetimeExtender.OnEndLifetimeExtensionCallback callback) {
    }
    
    @java.lang.Override()
    public final void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    public SelfTrackingLifetimeExtender(@org.jetbrains.annotations.NotNull()
    java.lang.String tag, @org.jetbrains.annotations.NotNull()
    java.lang.String name, boolean debug, @org.jetbrains.annotations.NotNull()
    android.os.Handler mainHandler) {
        super();
    }
}