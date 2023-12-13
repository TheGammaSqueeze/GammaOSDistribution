package com.android.systemui.media;

import android.content.Context;
import android.content.res.Configuration;
import android.view.View;
import android.view.ViewGroup;
import androidx.annotation.VisibleForTesting;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.StatusBarState;
import com.android.systemui.statusbar.SysuiStatusBarStateController;
import com.android.systemui.statusbar.notification.stack.MediaHeaderView;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.util.Utils;
import javax.inject.Inject;
import javax.inject.Named;

/**
 * Controls the media notifications on the lock screen, handles its visibility and placement -
 * switches media player positioning between split pane container vs single pane container
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000Z\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\b\u0011\n\u0002\u0010\b\n\u0002\b\u0002\b\u0007\u0018\u00002\u00020\u0001B9\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u0006\u0010\f\u001a\u00020\r\u00a2\u0006\u0002\u0010\u000eJ\u0010\u0010(\u001a\u00020!2\b\u0010)\u001a\u0004\u0018\u00010\u0010J\u000e\u0010*\u001a\u00020!2\u0006\u0010+\u001a\u00020\u0015J\b\u0010,\u001a\u00020!H\u0002J\u0010\u0010-\u001a\u00020!2\u0006\u0010&\u001a\u00020\u0017H\u0002J\b\u0010.\u001a\u00020!H\u0002J\u0006\u0010/\u001a\u00020!J\u001a\u00100\u001a\u00020!2\b\u00101\u001a\u0004\u0018\u00010\u00152\u0006\u00102\u001a\u000203H\u0002J\b\u00104\u001a\u00020!H\u0002J\b\u00105\u001a\u00020!H\u0002R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\"\u0010\u0011\u001a\u0004\u0018\u00010\u00102\b\u0010\u000f\u001a\u0004\u0018\u00010\u0010@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0013R\u0010\u0010\u0014\u001a\u0004\u0018\u00010\u0015X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R,\u0010\u0018\u001a\u00020\u00172\u0006\u0010\u0016\u001a\u00020\u00178\u0006@FX\u0087\u000e\u00a2\u0006\u0014\n\u0000\u0012\u0004\b\u0019\u0010\u001a\u001a\u0004\b\u001b\u0010\u001c\"\u0004\b\u001d\u0010\u001eR(\u0010\u001f\u001a\u0010\u0012\u0004\u0012\u00020\u0017\u0012\u0004\u0012\u00020!\u0018\u00010 X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\"\u0010#\"\u0004\b$\u0010%R\u001e\u0010&\u001a\u00020\u00172\u0006\u0010\u000f\u001a\u00020\u0017@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\'\u0010\u001c"}, d2 = {"Lcom/android/systemui/media/KeyguardMediaController;", "", "mediaHost", "Lcom/android/systemui/media/MediaHost;", "bypassController", "Lcom/android/systemui/statusbar/phone/KeyguardBypassController;", "statusBarStateController", "Lcom/android/systemui/statusbar/SysuiStatusBarStateController;", "notifLockscreenUserManager", "Lcom/android/systemui/statusbar/NotificationLockscreenUserManager;", "context", "Landroid/content/Context;", "configurationController", "Lcom/android/systemui/statusbar/policy/ConfigurationController;", "(Lcom/android/systemui/media/MediaHost;Lcom/android/systemui/statusbar/phone/KeyguardBypassController;Lcom/android/systemui/statusbar/SysuiStatusBarStateController;Lcom/android/systemui/statusbar/NotificationLockscreenUserManager;Landroid/content/Context;Lcom/android/systemui/statusbar/policy/ConfigurationController;)V", "<set-?>", "Lcom/android/systemui/statusbar/notification/stack/MediaHeaderView;", "singlePaneContainer", "getSinglePaneContainer", "()Lcom/android/systemui/statusbar/notification/stack/MediaHeaderView;", "splitShadeContainer", "Landroid/view/ViewGroup;", "value", "", "useSplitShade", "getUseSplitShade$annotations", "()V", "getUseSplitShade", "()Z", "setUseSplitShade", "(Z)V", "visibilityChangedListener", "Lkotlin/Function1;", "", "getVisibilityChangedListener", "()Lkotlin/jvm/functions/Function1;", "setVisibilityChangedListener", "(Lkotlin/jvm/functions/Function1;)V", "visible", "getVisible", "attachSinglePaneContainer", "mediaView", "attachSplitShadeContainer", "container", "hideMediaPlayer", "onMediaHostVisibilityChanged", "reattachHostView", "refreshMediaPosition", "setVisibility", "view", "newVisibility", "", "showMediaPlayer", "updateResources"})
@com.android.systemui.dagger.SysUISingleton()
public final class KeyguardMediaController {
    private boolean useSplitShade = false;
    
    /**
     * Is the media player visible?
     */
    private boolean visible = false;
    @org.jetbrains.annotations.Nullable()
    private kotlin.jvm.functions.Function1<? super java.lang.Boolean, kotlin.Unit> visibilityChangedListener;
    
    /**
     * single pane media container placed at the top of the notifications list
     */
    @org.jetbrains.annotations.Nullable()
    private com.android.systemui.statusbar.notification.stack.MediaHeaderView singlePaneContainer;
    private android.view.ViewGroup splitShadeContainer;
    private final com.android.systemui.media.MediaHost mediaHost = null;
    private final com.android.systemui.statusbar.phone.KeyguardBypassController bypassController = null;
    private final com.android.systemui.statusbar.SysuiStatusBarStateController statusBarStateController = null;
    private final com.android.systemui.statusbar.NotificationLockscreenUserManager notifLockscreenUserManager = null;
    private final android.content.Context context = null;
    
    private final void updateResources() {
    }
    
    @androidx.annotation.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getUseSplitShade$annotations() {
    }
    
    public final boolean getUseSplitShade() {
        return false;
    }
    
    public final void setUseSplitShade(boolean value) {
    }
    
    public final boolean getVisible() {
        return false;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final kotlin.jvm.functions.Function1<java.lang.Boolean, kotlin.Unit> getVisibilityChangedListener() {
        return null;
    }
    
    public final void setVisibilityChangedListener(@org.jetbrains.annotations.Nullable()
    kotlin.jvm.functions.Function1<? super java.lang.Boolean, kotlin.Unit> p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.stack.MediaHeaderView getSinglePaneContainer() {
        return null;
    }
    
    /**
     * Attaches media container in single pane mode, situated at the top of the notifications list
     */
    public final void attachSinglePaneContainer(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.stack.MediaHeaderView mediaView) {
    }
    
    /**
     * Called whenever the media hosts visibility changes
     */
    private final void onMediaHostVisibilityChanged(boolean visible) {
    }
    
    /**
     * Attaches media container in split shade mode, situated to the left of notifications
     */
    public final void attachSplitShadeContainer(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup container) {
    }
    
    private final void reattachHostView() {
    }
    
    public final void refreshMediaPosition() {
    }
    
    private final void showMediaPlayer() {
    }
    
    private final void hideMediaPlayer() {
    }
    
    private final void setVisibility(android.view.ViewGroup view, int newVisibility) {
    }
    
    @javax.inject.Inject()
    public KeyguardMediaController(@org.jetbrains.annotations.NotNull()
    @javax.inject.Named(value = "media_keyguard")
    com.android.systemui.media.MediaHost mediaHost, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.KeyguardBypassController bypassController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.SysuiStatusBarStateController statusBarStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationLockscreenUserManager notifLockscreenUserManager, @org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.ConfigurationController configurationController) {
        super();
    }
}