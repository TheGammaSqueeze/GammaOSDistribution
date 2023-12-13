package com.android.systemui.statusbar.notification.collection.render;

import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.row.NotificationGuts;

/**
 * Interface for listening to guts open and close events.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&J\u0018\u0010\u0006\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010\u0007\u001a\u00020\bH&"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/render/NotifGutsViewListener;", "", "onGutsClose", "", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "onGutsOpen", "guts", "Lcom/android/systemui/statusbar/notification/row/NotificationGuts;"})
public abstract interface NotifGutsViewListener {
    
    /**
     * A notification's guts are being opened
     */
    public abstract void onGutsOpen(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.row.NotificationGuts guts);
    
    /**
     * A notification's guts are being closed
     */
    public abstract void onGutsClose(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry);
}