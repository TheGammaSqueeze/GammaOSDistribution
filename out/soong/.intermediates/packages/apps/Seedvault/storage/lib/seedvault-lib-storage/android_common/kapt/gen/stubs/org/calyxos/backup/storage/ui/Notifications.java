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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000H\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0006\n\u0002\u0010\r\n\u0002\b\t\n\u0002\u0018\u0002\n\u0002\b\u0007\b\u0000\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\r\u0010\b\u001a\u00020\tH\u0000\u00a2\u0006\u0002\b\nJ\r\u0010\u000b\u001a\u00020\tH\u0000\u00a2\u0006\u0002\b\fJ\b\u0010\r\u001a\u00020\u000eH\u0002J\b\u0010\u000f\u001a\u00020\u000eH\u0002J+\u0010\u0010\u001a\u00020\u00112\b\b\u0001\u0010\u0012\u001a\u00020\u00132\b\b\u0002\u0010\u0014\u001a\u00020\u00132\b\b\u0002\u0010\u0015\u001a\u00020\u0013H\u0000\u00a2\u0006\u0002\b\u0016J8\u0010\u0017\u001a\u00020\u00112\b\b\u0001\u0010\u0018\u001a\u00020\u00132\u0006\u0010\u0019\u001a\u00020\u001a2\b\u0010\u001b\u001a\u0004\u0018\u00010\u001a2\b\b\u0002\u0010\u0014\u001a\u00020\u00132\b\b\u0002\u0010\u0015\u001a\u00020\u0013H\u0002J+\u0010\u001c\u001a\u00020\u00112\b\b\u0001\u0010\u0012\u001a\u00020\u00132\b\b\u0002\u0010\u0014\u001a\u00020\u00132\b\b\u0002\u0010\u0015\u001a\u00020\u0013H\u0000\u00a2\u0006\u0002\b\u001dJ!\u0010\u001e\u001a\u00020\u00112\b\b\u0002\u0010\u001f\u001a\u00020\u00132\b\b\u0002\u0010\u0015\u001a\u00020\u0013H\u0000\u00a2\u0006\u0002\b J\'\u0010!\u001a\u00020\t2\u0006\u0010\u001f\u001a\u00020\u00132\u0006\u0010\"\u001a\u00020\u00132\b\u0010#\u001a\u0004\u0018\u00010$H\u0000\u00a2\u0006\u0002\b%J+\u0010&\u001a\u00020\t2\b\b\u0001\u0010\u0012\u001a\u00020\u00132\b\b\u0002\u0010\u0014\u001a\u00020\u00132\b\b\u0002\u0010\u0015\u001a\u00020\u0013H\u0000\u00a2\u0006\u0002\b\'J+\u0010(\u001a\u00020\t2\b\b\u0001\u0010\u0012\u001a\u00020\u00132\b\b\u0002\u0010\u0014\u001a\u00020\u00132\b\b\u0002\u0010\u0015\u001a\u00020\u0013H\u0000\u00a2\u0006\u0002\b)J\u001d\u0010*\u001a\u00020\t2\u0006\u0010\u001f\u001a\u00020\u00132\u0006\u0010\u0015\u001a\u00020\u0013H\u0000\u00a2\u0006\u0002\b+R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0005\u001a\n \u0007*\u0004\u0018\u00010\u00060\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/ui/Notifications;", "", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "nm", "Landroid/app/NotificationManager;", "kotlin.jvm.PlatformType", "cancelBackupNotification", "", "cancelBackupNotification$main", "cancelPruneNotification", "cancelPruneNotification$main", "createBackupChannel", "Landroid/app/NotificationChannel;", "createRestoreChannel", "getBackupNotification", "Landroid/app/Notification;", "textRes", "", "transferred", "expected", "getBackupNotification$main", "getNotification", "icon", "title", "", "infoText", "getPruneNotification", "getPruneNotification$main", "getRestoreNotification", "restored", "getRestoreNotification$main", "showRestoreCompleteNotification", "total", "intent", "Landroid/app/PendingIntent;", "showRestoreCompleteNotification$main", "updateBackupNotification", "updateBackupNotification$main", "updatePruneNotification", "updatePruneNotification$main", "updateRestoreNotification", "updateRestoreNotification$main"})
public final class Notifications {
    private final android.app.NotificationManager nm = null;
    private final android.content.Context context = null;
    
    private final android.app.NotificationChannel createBackupChannel() {
        return null;
    }
    
    private final android.app.NotificationChannel createRestoreChannel() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.app.Notification getBackupNotification$main(@androidx.annotation.StringRes()
    int textRes, int transferred, int expected) {
        return null;
    }
    
    public final void updateBackupNotification$main(@androidx.annotation.StringRes()
    int textRes, int transferred, int expected) {
    }
    
    public final void cancelBackupNotification$main() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.app.Notification getPruneNotification$main(@androidx.annotation.StringRes()
    int textRes, int transferred, int expected) {
        return null;
    }
    
    public final void updatePruneNotification$main(@androidx.annotation.StringRes()
    int textRes, int transferred, int expected) {
    }
    
    public final void cancelPruneNotification$main() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.app.Notification getRestoreNotification$main(int restored, int expected) {
        return null;
    }
    
    public final void updateRestoreNotification$main(int restored, int expected) {
    }
    
    public final void showRestoreCompleteNotification$main(int restored, int total, @org.jetbrains.annotations.Nullable()
    android.app.PendingIntent intent) {
    }
    
    private final android.app.Notification getNotification(@androidx.annotation.DrawableRes()
    int icon, java.lang.CharSequence title, java.lang.CharSequence infoText, int transferred, int expected) {
        return null;
    }
    
    public Notifications(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
}