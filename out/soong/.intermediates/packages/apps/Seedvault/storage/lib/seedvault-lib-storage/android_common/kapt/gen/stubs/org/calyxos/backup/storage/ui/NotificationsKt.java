package org.calyxos.backup.storage.ui;

import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import androidx.annotation.DrawableRes;
import androidx.annotation.StringRes;
import androidx.core.app.NotificationCompat;
import org.calyxos.backup.storage.R;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0012\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0003\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0003\u001a\u00020\u0004X\u0080T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0005\u001a\u00020\u0004X\u0080T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0006\u001a\u00020\u0004X\u0080T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0007\u001a\u00020\u0004X\u0080T\u00a2\u0006\u0002\n\u0000"}, d2 = {"CHANNEL_ID_BACKUP", "", "CHANNEL_ID_RESTORE", "NOTIFICATION_ID_BACKUP", "", "NOTIFICATION_ID_PRUNE", "NOTIFICATION_ID_RESTORE", "NOTIFICATION_ID_RESTORE_COMPLETE"})
public final class NotificationsKt {
    private static final java.lang.String CHANNEL_ID_BACKUP = "seedvault.storage.backup";
    private static final java.lang.String CHANNEL_ID_RESTORE = "seedvault.storage.restore";
    public static final int NOTIFICATION_ID_BACKUP = 1000;
    public static final int NOTIFICATION_ID_PRUNE = 1001;
    public static final int NOTIFICATION_ID_RESTORE = 1002;
    public static final int NOTIFICATION_ID_RESTORE_COMPLETE = 1003;
}