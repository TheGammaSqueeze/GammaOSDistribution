package com.android.systemui.statusbar.notification.collection.render;

import com.android.systemui.log.LogBuffer;
import com.android.systemui.log.LogLevel;
import com.android.systemui.log.dagger.NotificationLog;
import java.lang.RuntimeException;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000<\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\u0018\u00002\u00020\u0001B\u0011\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0016\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\bJ*\u0010\n\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\u000b\u001a\u00020\f2\b\u0010\r\u001a\u0004\u0018\u00010\b2\b\u0010\u000e\u001a\u0004\u0018\u00010\bJ\u0016\u0010\u000f\u001a\u00020\u00062\u0006\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u0013J\u001e\u0010\u0014\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\b2\u0006\u0010\u0015\u001a\u00020\u0016J\u0018\u0010\u0017\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\b\u0010\t\u001a\u0004\u0018\u00010\bR\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/render/ShadeViewDifferLogger;", "", "buffer", "Lcom/android/systemui/log/LogBuffer;", "(Lcom/android/systemui/log/LogBuffer;)V", "logAttachingChild", "", "key", "", "parent", "logDetachingChild", "isTransfer", "", "oldParent", "newParent", "logDuplicateNodeInTree", "node", "Lcom/android/systemui/statusbar/notification/collection/render/NodeSpec;", "ex", "Ljava/lang/RuntimeException;", "logMovingChild", "toIndex", "", "logSkippingDetach"})
public final class ShadeViewDifferLogger {
    private final com.android.systemui.log.LogBuffer buffer = null;
    
    public final void logDetachingChild(@org.jetbrains.annotations.NotNull()
    java.lang.String key, boolean isTransfer, @org.jetbrains.annotations.Nullable()
    java.lang.String oldParent, @org.jetbrains.annotations.Nullable()
    java.lang.String newParent) {
    }
    
    public final void logSkippingDetach(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.Nullable()
    java.lang.String parent) {
    }
    
    public final void logAttachingChild(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.NotNull()
    java.lang.String parent) {
    }
    
    public final void logMovingChild(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.NotNull()
    java.lang.String parent, int toIndex) {
    }
    
    public final void logDuplicateNodeInTree(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.NodeSpec node, @org.jetbrains.annotations.NotNull()
    java.lang.RuntimeException ex) {
    }
    
    @javax.inject.Inject()
    public ShadeViewDifferLogger(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.log.dagger.NotificationLog()
    com.android.systemui.log.LogBuffer buffer) {
        super();
    }
}