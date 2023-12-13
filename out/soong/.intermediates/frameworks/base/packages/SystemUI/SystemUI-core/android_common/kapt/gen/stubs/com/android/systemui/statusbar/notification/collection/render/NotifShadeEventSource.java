package com.android.systemui.statusbar.notification.collection.render;

import java.lang.System;

/**
 * This is an object which provides callbacks for certain important events related to the
 * notification shade, such as notifications being removed by the user, or the shade becoming empty.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&J\u0010\u0010\u0006\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/render/NotifShadeEventSource;", "", "setNotifRemovedByUserCallback", "", "callback", "Ljava/lang/Runnable;", "setShadeEmptiedCallback"})
public abstract interface NotifShadeEventSource {
    
    /**
     * Registers a callback to be invoked when the last notification has been removed from
     * the shade for any reason
     */
    public abstract void setShadeEmptiedCallback(@org.jetbrains.annotations.NotNull()
    java.lang.Runnable callback);
    
    /**
     * Registers a callback to be invoked when a notification has been removed from
     * the shade by a user action
     */
    public abstract void setNotifRemovedByUserCallback(@org.jetbrains.annotations.NotNull()
    java.lang.Runnable callback);
}