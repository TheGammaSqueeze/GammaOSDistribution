package com.android.systemui.statusbar.notification.icon;

import android.app.Notification;
import android.content.Context;
import com.android.systemui.statusbar.StatusBarIconView;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import javax.inject.Inject;

/**
 * Testable wrapper around Context.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\r\n\u0000\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B\u000f\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u000e\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bJ\u000e\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\fR\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/icon/IconBuilder;", "", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "createIconView", "Lcom/android/systemui/statusbar/StatusBarIconView;", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "getIconContentDescription", "", "n", "Landroid/app/Notification;"})
public final class IconBuilder {
    private final android.content.Context context = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.StatusBarIconView createIconView(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.CharSequence getIconContentDescription(@org.jetbrains.annotations.NotNull()
    android.app.Notification n) {
        return null;
    }
    
    @javax.inject.Inject()
    public IconBuilder(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
}