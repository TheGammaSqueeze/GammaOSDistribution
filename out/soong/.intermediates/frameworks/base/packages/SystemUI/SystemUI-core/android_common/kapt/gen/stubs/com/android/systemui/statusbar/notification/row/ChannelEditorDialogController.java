package com.android.systemui.statusbar.notification.row;

import android.app.Dialog;
import android.app.INotificationManager;
import android.app.NotificationChannel;
import android.app.NotificationChannelGroup;
import android.app.NotificationManager.Importance;
import android.content.Context;
import android.graphics.Color;
import android.graphics.PixelFormat;
import android.graphics.drawable.ColorDrawable;
import android.graphics.drawable.Drawable;
import android.util.Log;
import android.view.Gravity;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.TextView;
import com.android.internal.annotations.VisibleForTesting;
import com.android.systemui.R;
import com.android.systemui.dagger.SysUISingleton;
import javax.inject.Inject;

/**
 * ChannelEditorDialogController is the controller for the dialog half-shelf
 * that allows users to quickly turn off channels. It is launched from the NotificationInfo
 * guts view and displays controls for toggling app notifications as well as up to 4 channels
 * from that app like so:
 *
 *  APP TOGGLE                                                 <on/off>
 *  - Channel from which we launched                           <on/off>
 *  -                                                          <on/off>
 *  - the next 3 channels sorted alphabetically for that app   <on/off>
 *  -                                                          <on/off>
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0098\u0001\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010%\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\r\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\t\n\u0002\u0010\u0002\n\u0002\b\b\n\u0002\u0010 \n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\"\n\u0002\b\u000b\b\u0007\u0018\u00002\u00020\u0001B\u001f\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\b\u00106\u001a\u000207H\u0007J\u0010\u00108\u001a\u0002072\u0006\u00109\u001a\u00020\u000eH\u0002J\u0006\u0010:\u001a\u00020\u000eJ\b\u0010;\u001a\u000207H\u0002J\b\u0010<\u001a\u00020\u000eH\u0002J\u0006\u0010=\u001a\u000207J\b\u0010>\u001a\u000207H\u0002J\u000e\u0010?\u001a\b\u0012\u0004\u0012\u00020\u00160@H\u0002J\u001c\u0010A\u001a\b\u0012\u0004\u0012\u00020\u001e0B2\f\u0010C\u001a\b\u0012\u0004\u0012\u00020\u00160BH\u0002J\u0010\u0010D\u001a\u00020!2\b\u0010E\u001a\u0004\u0018\u00010\fJ\b\u0010F\u001a\u00020\u000eH\u0002J\b\u0010G\u001a\u000207H\u0002J\u0010\u0010H\u001a\u0002072\u0006\u0010I\u001a\u00020JH\u0007J\u0016\u0010K\u001a\u0002072\f\u0010L\u001a\b\u0012\u0004\u0012\u00020\u001e0MH\u0002J>\u0010N\u001a\u0002072\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010.\u001a\u00020\f2\u0006\u0010O\u001a\u00020\u00122\f\u0010L\u001a\b\u0012\u0004\u0012\u00020\u001e0M2\u0006\u0010\t\u001a\u00020\n2\b\u0010,\u001a\u0004\u0018\u00010-J\u0016\u0010P\u001a\u0002072\u0006\u0010Q\u001a\u00020\u001e2\u0006\u0010R\u001a\u00020\u0012J\u000e\u0010S\u001a\u0002072\u0006\u0010T\u001a\u00020\u000eJ\b\u0010U\u001a\u000207H\u0002J\u0018\u0010V\u001a\u0002072\u0006\u0010Q\u001a\u00020\u001e2\u0006\u0010W\u001a\u00020\u0012H\u0002J\u0006\u0010X\u001a\u000207R\u0010\u0010\t\u001a\u0004\u0018\u00010\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u000b\u001a\u0004\u0018\u00010\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\r\u001a\u0004\u0018\u00010\u000eX\u0082\u000e\u00a2\u0006\u0004\n\u0002\u0010\u000fR\u000e\u0010\u0010\u001a\u00020\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u0011\u001a\u0004\u0018\u00010\u0012X\u0082\u000e\u00a2\u0006\u0004\n\u0002\u0010\u0013R\u0014\u0010\u0014\u001a\b\u0012\u0004\u0012\u00020\u00160\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0017\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0018\u0010\u0019R\u000e\u0010\u001a\u001a\u00020\u001bX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u001c\u001a\u000e\u0012\u0004\u0012\u00020\u001e\u0012\u0004\u0012\u00020\u00120\u001dX\u0082\u0004\u00a2\u0006\u0002\n\u0000R(\u0010\u001f\u001a\u000e\u0012\u0004\u0012\u00020\f\u0012\u0004\u0012\u00020!0 8\u0000X\u0081\u0004\u00a2\u0006\u000e\n\u0000\u0012\u0004\b\"\u0010#\u001a\u0004\b$\u0010%R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001c\u0010&\u001a\u0004\u0018\u00010\'X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b(\u0010)\"\u0004\b*\u0010+R\u0010\u0010,\u001a\u0004\u0018\u00010-X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010.\u001a\u0004\u0018\u00010\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\"\u0010/\u001a\b\u0012\u0004\u0012\u00020\u001e0\u00158\u0000X\u0081\u0004\u00a2\u0006\u000e\n\u0000\u0012\u0004\b0\u0010#\u001a\u0004\b1\u00102R\u000e\u00103\u001a\u00020\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u00104\u001a\b\u0012\u0004\u0012\u00020\u001e0\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u00105\u001a\u00020\u0012X\u0082D\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/row/ChannelEditorDialogController;", "", "c", "Landroid/content/Context;", "noMan", "Landroid/app/INotificationManager;", "dialogBuilder", "Lcom/android/systemui/statusbar/notification/row/ChannelEditorDialog$Builder;", "(Landroid/content/Context;Landroid/app/INotificationManager;Lcom/android/systemui/statusbar/notification/row/ChannelEditorDialog$Builder;)V", "appIcon", "Landroid/graphics/drawable/Drawable;", "appName", "", "appNotificationsCurrentlyEnabled", "", "Ljava/lang/Boolean;", "appNotificationsEnabled", "appUid", "", "Ljava/lang/Integer;", "channelGroupList", "", "Landroid/app/NotificationChannelGroup;", "context", "getContext", "()Landroid/content/Context;", "dialog", "Lcom/android/systemui/statusbar/notification/row/ChannelEditorDialog;", "edits", "", "Landroid/app/NotificationChannel;", "groupNameLookup", "Ljava/util/HashMap;", "", "getGroupNameLookup$main$annotations", "()V", "getGroupNameLookup$main", "()Ljava/util/HashMap;", "onFinishListener", "Lcom/android/systemui/statusbar/notification/row/OnChannelEditorDialogFinishedListener;", "getOnFinishListener", "()Lcom/android/systemui/statusbar/notification/row/OnChannelEditorDialogFinishedListener;", "setOnFinishListener", "(Lcom/android/systemui/statusbar/notification/row/OnChannelEditorDialogFinishedListener;)V", "onSettingsClickListener", "Lcom/android/systemui/statusbar/notification/row/NotificationInfo$OnSettingsClickListener;", "packageName", "paddedChannels", "getPaddedChannels$main$annotations", "getPaddedChannels$main", "()Ljava/util/List;", "prepared", "providedChannels", "wmFlags", "apply", "", "applyAppNotificationsOn", "b", "areAppNotificationsEnabled", "buildGroupNameLookup", "checkAreAppNotificationsOn", "close", "done", "fetchNotificationChannelGroups", "", "getDisplayableChannels", "Lkotlin/sequences/Sequence;", "groupList", "groupNameForId", "groupId", "hasChanges", "initDialog", "launchSettings", "sender", "Landroid/view/View;", "padToFourChannels", "channels", "", "prepareDialogForApp", "uid", "proposeEditForChannel", "channel", "edit", "proposeSetAppNotificationsEnabled", "enabled", "resetState", "setChannelImportance", "importance", "show"})
@com.android.systemui.dagger.SysUISingleton()
public final class ChannelEditorDialogController {
    @org.jetbrains.annotations.NotNull()
    private final android.content.Context context = null;
    private boolean prepared = false;
    private com.android.systemui.statusbar.notification.row.ChannelEditorDialog dialog;
    private android.graphics.drawable.Drawable appIcon;
    private java.lang.Integer appUid;
    private java.lang.String packageName;
    private java.lang.String appName;
    private com.android.systemui.statusbar.notification.row.NotificationInfo.OnSettingsClickListener onSettingsClickListener;
    @org.jetbrains.annotations.Nullable()
    private com.android.systemui.statusbar.notification.row.OnChannelEditorDialogFinishedListener onFinishListener;
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<android.app.NotificationChannel> paddedChannels = null;
    private final java.util.List<android.app.NotificationChannel> providedChannels = null;
    private final java.util.Map<android.app.NotificationChannel, java.lang.Integer> edits = null;
    private boolean appNotificationsEnabled = true;
    private java.lang.Boolean appNotificationsCurrentlyEnabled;
    @org.jetbrains.annotations.NotNull()
    private final java.util.HashMap<java.lang.String, java.lang.CharSequence> groupNameLookup = null;
    private final java.util.List<android.app.NotificationChannelGroup> channelGroupList = null;
    private final int wmFlags = -2130444288;
    private final android.app.INotificationManager noMan = null;
    private final com.android.systemui.statusbar.notification.row.ChannelEditorDialog.Builder dialogBuilder = null;
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.Context getContext() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.row.OnChannelEditorDialogFinishedListener getOnFinishListener() {
        return null;
    }
    
    public final void setOnFinishListener(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.row.OnChannelEditorDialogFinishedListener p0) {
    }
    
    @com.android.internal.annotations.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getPaddedChannels$main$annotations() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<android.app.NotificationChannel> getPaddedChannels$main() {
        return null;
    }
    
    @com.android.internal.annotations.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getGroupNameLookup$main$annotations() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.HashMap<java.lang.String, java.lang.CharSequence> getGroupNameLookup$main() {
        return null;
    }
    
    /**
     * Give the controller all of the information it needs to present the dialog
     * for a given app. Does a bunch of querying of NoMan, but won't present anything yet
     */
    public final void prepareDialogForApp(@org.jetbrains.annotations.NotNull()
    java.lang.String appName, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, int uid, @org.jetbrains.annotations.NotNull()
    java.util.Set<android.app.NotificationChannel> channels, @org.jetbrains.annotations.NotNull()
    android.graphics.drawable.Drawable appIcon, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.row.NotificationInfo.OnSettingsClickListener onSettingsClickListener) {
    }
    
    private final void buildGroupNameLookup() {
    }
    
    private final void padToFourChannels(java.util.Set<android.app.NotificationChannel> channels) {
    }
    
    private final kotlin.sequences.Sequence<android.app.NotificationChannel> getDisplayableChannels(kotlin.sequences.Sequence<android.app.NotificationChannelGroup> groupList) {
        return null;
    }
    
    public final void show() {
    }
    
    /**
     * Close the dialog without saving. For external callers
     */
    public final void close() {
    }
    
    private final void done() {
    }
    
    private final void resetState() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.CharSequence groupNameForId(@org.jetbrains.annotations.Nullable()
    java.lang.String groupId) {
        return null;
    }
    
    public final void proposeEditForChannel(@org.jetbrains.annotations.NotNull()
    android.app.NotificationChannel channel, @android.app.NotificationManager.Importance()
    int edit) {
    }
    
    public final void proposeSetAppNotificationsEnabled(boolean enabled) {
    }
    
    public final boolean areAppNotificationsEnabled() {
        return false;
    }
    
    private final boolean hasChanges() {
        return false;
    }
    
    @kotlin.Suppress(names = {"unchecked_cast"})
    private final java.util.List<android.app.NotificationChannelGroup> fetchNotificationChannelGroups() {
        return null;
    }
    
    private final boolean checkAreAppNotificationsOn() {
        return false;
    }
    
    private final void applyAppNotificationsOn(boolean b) {
    }
    
    private final void setChannelImportance(android.app.NotificationChannel channel, int importance) {
    }
    
    @com.android.internal.annotations.VisibleForTesting()
    public final void apply() {
    }
    
    @com.android.internal.annotations.VisibleForTesting()
    public final void launchSettings(@org.jetbrains.annotations.NotNull()
    android.view.View sender) {
    }
    
    private final void initDialog() {
    }
    
    @javax.inject.Inject()
    public ChannelEditorDialogController(@org.jetbrains.annotations.NotNull()
    android.content.Context c, @org.jetbrains.annotations.NotNull()
    android.app.INotificationManager noMan, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.row.ChannelEditorDialog.Builder dialogBuilder) {
        super();
    }
}