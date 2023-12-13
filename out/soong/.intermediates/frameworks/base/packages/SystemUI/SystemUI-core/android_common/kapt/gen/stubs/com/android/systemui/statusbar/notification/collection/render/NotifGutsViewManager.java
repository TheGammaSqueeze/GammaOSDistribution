package com.android.systemui.statusbar.notification.collection.render;

import java.lang.System;

/**
 * A type which provides open and close guts events to a single listener
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\bf\u0018\u00002\u00020\u0001J\u0012\u0010\u0002\u001a\u00020\u00032\b\u0010\u0004\u001a\u0004\u0018\u00010\u0005H&"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/render/NotifGutsViewManager;", "", "setGutsListener", "", "listener", "Lcom/android/systemui/statusbar/notification/collection/render/NotifGutsViewListener;"})
public abstract interface NotifGutsViewManager {
    
    /**
     * @param listener the object that will listen to open and close guts events
     */
    public abstract void setGutsListener(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.render.NotifGutsViewListener listener);
}