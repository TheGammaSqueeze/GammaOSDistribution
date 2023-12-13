package com.android.systemui.qs.tiles;

import android.app.AlarmManager;
import android.app.AlarmManager.AlarmClockInfo;
import android.content.Intent;
import android.os.Handler;
import android.os.Looper;
import android.provider.AlarmClock;
import android.service.quicksettings.Tile;
import android.text.TextUtils;
import android.text.format.DateFormat;
import android.view.View;
import androidx.annotation.VisibleForTesting;
import com.android.internal.jank.InteractionJankMonitor;
import com.android.internal.logging.MetricsLogger;
import com.android.systemui.R;
import com.android.systemui.animation.ActivityLaunchAnimator;
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.qs.QSTile;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.qs.QSHost;
import com.android.systemui.qs.logging.QSLogger;
import com.android.systemui.qs.tileimpl.QSTileImpl;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.statusbar.policy.NextAlarmController;
import java.util.Locale;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0096\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0010\b\n\u0000\n\u0002\u0010\r\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000b\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u0001B[\b\u0007\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\b\b\u0001\u0010\u0005\u001a\u00020\u0006\u0012\b\b\u0001\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\r\u001a\u00020\u000e\u0012\u0006\u0010\u000f\u001a\u00020\u0010\u0012\u0006\u0010\u0011\u001a\u00020\u0012\u0012\u0006\u0010\u0013\u001a\u00020\u0014\u0012\u0006\u0010\u0015\u001a\u00020\u0016\u00a2\u0006\u0002\u0010\u0017J\u0010\u0010%\u001a\u00020&2\u0006\u0010\'\u001a\u00020$H\u0002J\n\u0010(\u001a\u0004\u0018\u00010\u001bH\u0016J\b\u0010)\u001a\u00020*H\u0016J\b\u0010+\u001a\u00020,H\u0016J\u0012\u0010-\u001a\u00020.2\b\u0010/\u001a\u0004\u0018\u000100H\u0014J\u001a\u00101\u001a\u00020.2\u0006\u00102\u001a\u00020\u00022\b\u00103\u001a\u0004\u0018\u000104H\u0014J\b\u00105\u001a\u00020\u0002H\u0016J\b\u00106\u001a\u000207H\u0002R\u000e\u0010\u0018\u001a\u00020\u0019X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001c\u0010\u001a\u001a\u00020\u001b8\u0000X\u0081\u0004\u00a2\u0006\u000e\n\u0000\u0012\u0004\b\u001c\u0010\u001d\u001a\u0004\b\u001e\u0010\u001fR\u0016\u0010 \u001a\n \"*\u0004\u0018\u00010!0!X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010#\u001a\u0004\u0018\u00010$X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/tiles/AlarmTile;", "Lcom/android/systemui/qs/tileimpl/QSTileImpl;", "Lcom/android/systemui/plugins/qs/QSTile$State;", "host", "Lcom/android/systemui/qs/QSHost;", "backgroundLooper", "Landroid/os/Looper;", "mainHandler", "Landroid/os/Handler;", "falsingManager", "Lcom/android/systemui/plugins/FalsingManager;", "metricsLogger", "Lcom/android/internal/logging/MetricsLogger;", "statusBarStateController", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController;", "activityStarter", "Lcom/android/systemui/plugins/ActivityStarter;", "qsLogger", "Lcom/android/systemui/qs/logging/QSLogger;", "userTracker", "Lcom/android/systemui/settings/UserTracker;", "nextAlarmController", "Lcom/android/systemui/statusbar/policy/NextAlarmController;", "(Lcom/android/systemui/qs/QSHost;Landroid/os/Looper;Landroid/os/Handler;Lcom/android/systemui/plugins/FalsingManager;Lcom/android/internal/logging/MetricsLogger;Lcom/android/systemui/plugins/statusbar/StatusBarStateController;Lcom/android/systemui/plugins/ActivityStarter;Lcom/android/systemui/qs/logging/QSLogger;Lcom/android/systemui/settings/UserTracker;Lcom/android/systemui/statusbar/policy/NextAlarmController;)V", "callback", "Lcom/android/systemui/statusbar/policy/NextAlarmController$NextAlarmChangeCallback;", "defaultIntent", "Landroid/content/Intent;", "getDefaultIntent$main$annotations", "()V", "getDefaultIntent$main", "()Landroid/content/Intent;", "icon", "Lcom/android/systemui/plugins/qs/QSTile$Icon;", "kotlin.jvm.PlatformType", "lastAlarmInfo", "Landroid/app/AlarmManager$AlarmClockInfo;", "formatNextAlarm", "", "info", "getLongClickIntent", "getMetricsCategory", "", "getTileLabel", "", "handleClick", "", "view", "Landroid/view/View;", "handleUpdateState", "state", "arg", "", "newTileState", "use24HourFormat", ""})
public final class AlarmTile extends com.android.systemui.qs.tileimpl.QSTileImpl<com.android.systemui.plugins.qs.QSTile.State> {
    private android.app.AlarmManager.AlarmClockInfo lastAlarmInfo;
    private final com.android.systemui.plugins.qs.QSTile.Icon icon = null;
    @org.jetbrains.annotations.NotNull()
    private final android.content.Intent defaultIntent = null;
    private final com.android.systemui.statusbar.policy.NextAlarmController.NextAlarmChangeCallback callback = null;
    private final com.android.systemui.settings.UserTracker userTracker = null;
    
    @androidx.annotation.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getDefaultIntent$main$annotations() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.Intent getDefaultIntent$main() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.plugins.qs.QSTile.State newTileState() {
        return null;
    }
    
    @java.lang.Override()
    protected void handleClick(@org.jetbrains.annotations.Nullable()
    android.view.View view) {
    }
    
    @java.lang.Override()
    protected void handleUpdateState(@org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.qs.QSTile.State state, @org.jetbrains.annotations.Nullable()
    java.lang.Object arg) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.CharSequence getTileLabel() {
        return null;
    }
    
    private final java.lang.String formatNextAlarm(android.app.AlarmManager.AlarmClockInfo info) {
        return null;
    }
    
    private final boolean use24HourFormat() {
        return false;
    }
    
    @java.lang.Override()
    public int getMetricsCategory() {
        return 0;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public android.content.Intent getLongClickIntent() {
        return null;
    }
    
    @javax.inject.Inject()
    public AlarmTile(@org.jetbrains.annotations.NotNull()
    com.android.systemui.qs.QSHost host, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Background()
    android.os.Looper backgroundLooper, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    android.os.Handler mainHandler, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.FalsingManager falsingManager, @org.jetbrains.annotations.NotNull()
    com.android.internal.logging.MetricsLogger metricsLogger, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.ActivityStarter activityStarter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.qs.logging.QSLogger qsLogger, @org.jetbrains.annotations.NotNull()
    com.android.systemui.settings.UserTracker userTracker, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.NextAlarmController nextAlarmController) {
        super(null, null, null, null, null, null, null, null);
    }
}