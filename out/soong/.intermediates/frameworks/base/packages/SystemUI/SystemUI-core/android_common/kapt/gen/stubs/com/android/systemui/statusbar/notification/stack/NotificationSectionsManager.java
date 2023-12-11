package com.android.systemui.statusbar.notification.stack;

import android.annotation.ColorInt;
import android.annotation.LayoutRes;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import com.android.internal.annotations.VisibleForTesting;
import com.android.systemui.R;
import com.android.systemui.media.KeyguardMediaController;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.StatusBarState;
import com.android.systemui.statusbar.notification.NotificationSectionsFeatureManager;
import com.android.systemui.statusbar.notification.collection.render.SectionHeaderController;
import com.android.systemui.statusbar.notification.collection.render.ShadeViewManager;
import com.android.systemui.statusbar.notification.dagger.AlertingHeader;
import com.android.systemui.statusbar.notification.dagger.IncomingHeader;
import com.android.systemui.statusbar.notification.dagger.PeopleHeader;
import com.android.systemui.statusbar.notification.dagger.SilentHeader;
import com.android.systemui.statusbar.notification.row.ExpandableNotificationRow;
import com.android.systemui.statusbar.notification.row.ExpandableView;
import com.android.systemui.statusbar.notification.row.StackScrollerDecorView;
import com.android.systemui.statusbar.notification.stack.StackScrollAlgorithm.SectionProvider;
import com.android.systemui.statusbar.policy.ConfigurationController;
import javax.inject.Inject;

/**
 * Manages the boundaries of the notification sections (incoming, conversations, high priority, and
 * low priority).
 *
 * In the legacy notification pipeline, this is responsible for correctly positioning all section
 * headers after the [NotificationStackScrollLayout] has had notifications added/removed/changed. In
 * the new pipeline, this is handled as part of the [ShadeViewManager].
 *
 * TODO: Move remaining sections logic from NSSL into this class.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00a8\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0011\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u000f\n\u0002\u0010 \n\u0002\b\u0003\n\u0002\u0010\u000e\n\u0002\b\u0003\u0018\u0000 Z2\u00020\u0001:\u0003Z[\\BW\b\u0001\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\b\b\u0001\u0010\f\u001a\u00020\r\u0012\b\b\u0001\u0010\u000e\u001a\u00020\r\u0012\b\b\u0001\u0010\u000f\u001a\u00020\r\u0012\b\b\u0001\u0010\u0010\u001a\u00020\r\u00a2\u0006\u0002\u0010\u0011J\u001a\u0010.\u001a\u00020\u001e2\u0006\u0010/\u001a\u0002002\b\u00101\u001a\u0004\u0018\u000100H\u0016J\u0011\u00102\u001a\b\u0012\u0004\u0012\u00020403\u00a2\u0006\u0002\u00105J%\u00106\u001a\b\u0012\u0004\u0012\u0002H807\"\b\b\u0000\u00108*\u0002092\u0006\u0010:\u001a\u0002H8H\u0002\u00a2\u0006\u0002\u0010;J%\u0010<\u001a\b\u0012\u0004\u0012\u0002H807\"\b\b\u0000\u00108*\u00020=2\u0006\u0010:\u001a\u0002H8H\u0002\u00a2\u0006\u0002\u0010>J\u0019\u0010?\u001a\u0004\u0018\u00010@2\b\u0010/\u001a\u0004\u0018\u000100H\u0002\u00a2\u0006\u0002\u0010AJ\u0016\u0010B\u001a\u00020C2\u0006\u0010&\u001a\u00020\'2\u0006\u0010D\u001a\u00020EJ\u001b\u0010F\u001a\u00020C2\f\u0010G\u001a\b\u0012\u0004\u0012\u00020403H\u0002\u00a2\u0006\u0002\u0010HJ\u0018\u0010I\u001a\u00020C2\u0006\u0010J\u001a\u00020@2\u0006\u0010K\u001a\u000200H\u0002J\b\u0010L\u001a\u00020CH\u0002J1\u0010M\u001a\u0002H8\"\b\b\u0000\u00108*\u00020=2\b\u0010/\u001a\u0004\u0018\u0001H82\u0006\u0010D\u001a\u00020E2\u0006\u0010N\u001a\u00020@H\u0002\u00a2\u0006\u0002\u0010OJ\u000e\u0010P\u001a\u00020C2\u0006\u0010D\u001a\u00020EJ\u000e\u0010Q\u001a\u00020C2\u0006\u0010R\u001a\u00020@J\'\u0010S\u001a\u00020\u001e2\f\u0010G\u001a\b\u0012\u0004\u0012\u000204032\f\u0010T\u001a\b\u0012\u0004\u0012\u00020=0U\u00a2\u0006\u0002\u0010VJ\b\u0010W\u001a\u00020CH\u0007J\u000e\u0010W\u001a\u00020C2\u0006\u0010X\u001a\u00020YR\u000e\u0010\u000f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001c\u0010\u0012\u001a\u0004\u0018\u00010\u00138FX\u0087\u0004\u00a2\u0006\f\u0012\u0004\b\u0014\u0010\u0015\u001a\u0004\b\u0016\u0010\u0017R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0018\u001a\u00020\u0019X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001c\u0010\u001a\u001a\u0004\u0018\u00010\u00138FX\u0087\u0004\u00a2\u0006\f\u0012\u0004\b\u001b\u0010\u0015\u001a\u0004\b\u001c\u0010\u0017R\u000e\u0010\u001d\u001a\u00020\u001eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u001f\u001a\u00020\u001e8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u001f\u0010 R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R$\u0010#\u001a\u0004\u0018\u00010\"2\b\u0010!\u001a\u0004\u0018\u00010\"8G@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b$\u0010%R\u000e\u0010&\u001a\u00020\'X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001c\u0010(\u001a\u0004\u0018\u00010\u00138FX\u0087\u0004\u00a2\u0006\f\u0012\u0004\b)\u0010\u0015\u001a\u0004\b*\u0010\u0017R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001c\u0010+\u001a\u0004\u0018\u00010\u00138FX\u0087\u0004\u00a2\u0006\f\u0012\u0004\b,\u0010\u0015\u001a\u0004\b-\u0010\u0017R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/stack/NotificationSectionsManager;", "Lcom/android/systemui/statusbar/notification/stack/StackScrollAlgorithm$SectionProvider;", "statusBarStateController", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController;", "configurationController", "Lcom/android/systemui/statusbar/policy/ConfigurationController;", "keyguardMediaController", "Lcom/android/systemui/media/KeyguardMediaController;", "sectionsFeatureManager", "Lcom/android/systemui/statusbar/notification/NotificationSectionsFeatureManager;", "logger", "Lcom/android/systemui/statusbar/notification/stack/NotificationSectionsLogger;", "incomingHeaderController", "Lcom/android/systemui/statusbar/notification/collection/render/SectionHeaderController;", "peopleHeaderController", "alertingHeaderController", "silentHeaderController", "(Lcom/android/systemui/plugins/statusbar/StatusBarStateController;Lcom/android/systemui/statusbar/policy/ConfigurationController;Lcom/android/systemui/media/KeyguardMediaController;Lcom/android/systemui/statusbar/notification/NotificationSectionsFeatureManager;Lcom/android/systemui/statusbar/notification/stack/NotificationSectionsLogger;Lcom/android/systemui/statusbar/notification/collection/render/SectionHeaderController;Lcom/android/systemui/statusbar/notification/collection/render/SectionHeaderController;Lcom/android/systemui/statusbar/notification/collection/render/SectionHeaderController;Lcom/android/systemui/statusbar/notification/collection/render/SectionHeaderController;)V", "alertingHeaderView", "Lcom/android/systemui/statusbar/notification/stack/SectionHeaderView;", "getAlertingHeaderView$annotations", "()V", "getAlertingHeaderView", "()Lcom/android/systemui/statusbar/notification/stack/SectionHeaderView;", "configurationListener", "Lcom/android/systemui/statusbar/policy/ConfigurationController$ConfigurationListener;", "incomingHeaderView", "getIncomingHeaderView$annotations", "getIncomingHeaderView", "initialized", "", "isUsingMultipleSections", "()Z", "<set-?>", "Lcom/android/systemui/statusbar/notification/stack/MediaHeaderView;", "mediaControlsView", "getMediaControlsView", "()Lcom/android/systemui/statusbar/notification/stack/MediaHeaderView;", "parent", "Lcom/android/systemui/statusbar/notification/stack/NotificationStackScrollLayout;", "peopleHeaderView", "getPeopleHeaderView$annotations", "getPeopleHeaderView", "silentHeaderView", "getSilentHeaderView$annotations", "getSilentHeaderView", "beginsSection", "view", "Landroid/view/View;", "previous", "createSectionsForBuckets", "", "Lcom/android/systemui/statusbar/notification/stack/NotificationSection;", "()[Lcom/android/systemui/statusbar/notification/stack/NotificationSection;", "decorViewHeaderState", "Lcom/android/systemui/statusbar/notification/stack/NotificationSectionsManager$SectionUpdateState;", "T", "Lcom/android/systemui/statusbar/notification/row/StackScrollerDecorView;", "header", "(Lcom/android/systemui/statusbar/notification/row/StackScrollerDecorView;)Lcom/android/systemui/statusbar/notification/stack/NotificationSectionsManager$SectionUpdateState;", "expandableViewHeaderState", "Lcom/android/systemui/statusbar/notification/row/ExpandableView;", "(Lcom/android/systemui/statusbar/notification/row/ExpandableView;)Lcom/android/systemui/statusbar/notification/stack/NotificationSectionsManager$SectionUpdateState;", "getBucket", "", "(Landroid/view/View;)Ljava/lang/Integer;", "initialize", "", "layoutInflater", "Landroid/view/LayoutInflater;", "logSections", "sections", "([Lcom/android/systemui/statusbar/notification/stack/NotificationSection;)V", "logShadeChild", "i", "child", "logShadeContents", "reinflateView", "layoutResId", "(Lcom/android/systemui/statusbar/notification/row/ExpandableView;Landroid/view/LayoutInflater;I)Lcom/android/systemui/statusbar/notification/row/ExpandableView;", "reinflateViews", "setHeaderForegroundColor", "color", "updateFirstAndLastViewsForAllSections", "children", "", "([Lcom/android/systemui/statusbar/notification/stack/NotificationSection;Ljava/util/List;)Z", "updateSectionBoundaries", "reason", "", "Companion", "SectionBounds", "SectionUpdateState"})
public final class NotificationSectionsManager implements com.android.systemui.statusbar.notification.stack.StackScrollAlgorithm.SectionProvider {
    private final com.android.systemui.statusbar.policy.ConfigurationController.ConfigurationListener configurationListener = null;
    private com.android.systemui.statusbar.notification.stack.NotificationStackScrollLayout parent;
    private boolean initialized = false;
    @org.jetbrains.annotations.Nullable()
    private com.android.systemui.statusbar.notification.stack.MediaHeaderView mediaControlsView;
    private final com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController = null;
    private final com.android.systemui.statusbar.policy.ConfigurationController configurationController = null;
    private final com.android.systemui.media.KeyguardMediaController keyguardMediaController = null;
    private final com.android.systemui.statusbar.notification.NotificationSectionsFeatureManager sectionsFeatureManager = null;
    private final com.android.systemui.statusbar.notification.stack.NotificationSectionsLogger logger = null;
    private final com.android.systemui.statusbar.notification.collection.render.SectionHeaderController incomingHeaderController = null;
    private final com.android.systemui.statusbar.notification.collection.render.SectionHeaderController peopleHeaderController = null;
    private final com.android.systemui.statusbar.notification.collection.render.SectionHeaderController alertingHeaderController = null;
    private final com.android.systemui.statusbar.notification.collection.render.SectionHeaderController silentHeaderController = null;
    private static final java.lang.String TAG = "NotifSectionsManager";
    private static final boolean DEBUG = false;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.notification.stack.NotificationSectionsManager.Companion Companion = null;
    
    @com.android.internal.annotations.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getSilentHeaderView$annotations() {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.stack.SectionHeaderView getSilentHeaderView() {
        return null;
    }
    
    @com.android.internal.annotations.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getAlertingHeaderView$annotations() {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.stack.SectionHeaderView getAlertingHeaderView() {
        return null;
    }
    
    @com.android.internal.annotations.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getIncomingHeaderView$annotations() {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.stack.SectionHeaderView getIncomingHeaderView() {
        return null;
    }
    
    @com.android.internal.annotations.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getPeopleHeaderView$annotations() {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.stack.SectionHeaderView getPeopleHeaderView() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @com.android.internal.annotations.VisibleForTesting()
    public final com.android.systemui.statusbar.notification.stack.MediaHeaderView getMediaControlsView() {
        return null;
    }
    
    /**
     * Must be called before use.
     */
    public final void initialize(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.stack.NotificationStackScrollLayout parent, @org.jetbrains.annotations.NotNull()
    android.view.LayoutInflater layoutInflater) {
    }
    
    private final <T extends com.android.systemui.statusbar.notification.row.ExpandableView>T reinflateView(T view, android.view.LayoutInflater layoutInflater, @android.annotation.LayoutRes()
    int layoutResId) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.stack.NotificationSection[] createSectionsForBuckets() {
        return null;
    }
    
    /**
     * Reinflates the entire notification header, including all decoration views.
     */
    public final void reinflateViews(@org.jetbrains.annotations.NotNull()
    android.view.LayoutInflater layoutInflater) {
    }
    
    @java.lang.Override()
    public boolean beginsSection(@org.jetbrains.annotations.NotNull()
    android.view.View view, @org.jetbrains.annotations.Nullable()
    android.view.View previous) {
        return false;
    }
    
    private final java.lang.Integer getBucket(android.view.View view) {
        return null;
    }
    
    private final void logShadeChild(int i, android.view.View child) {
    }
    
    private final void logShadeContents() {
    }
    
    private final boolean isUsingMultipleSections() {
        return false;
    }
    
    @com.android.internal.annotations.VisibleForTesting()
    public final void updateSectionBoundaries() {
    }
    
    private final <T extends com.android.systemui.statusbar.notification.row.ExpandableView>com.android.systemui.statusbar.notification.stack.NotificationSectionsManager.SectionUpdateState<T> expandableViewHeaderState(T header) {
        return null;
    }
    
    private final <T extends com.android.systemui.statusbar.notification.row.StackScrollerDecorView>com.android.systemui.statusbar.notification.stack.NotificationSectionsManager.SectionUpdateState<T> decorViewHeaderState(T header) {
        return null;
    }
    
    /**
     * Should be called whenever notifs are added, removed, or updated. Updates section boundary
     * bookkeeping and adds/moves/removes section headers if appropriate.
     */
    public final void updateSectionBoundaries(@org.jetbrains.annotations.NotNull()
    java.lang.String reason) {
    }
    
    /**
     * Updates the boundaries (as tracked by their first and last views) of the priority sections.
     *
     * @return `true` If the last view in the top section changed (so we need to animate).
     */
    public final boolean updateFirstAndLastViewsForAllSections(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.stack.NotificationSection[] sections, @org.jetbrains.annotations.NotNull()
    java.util.List<? extends com.android.systemui.statusbar.notification.row.ExpandableView> children) {
        return false;
    }
    
    private final void logSections(com.android.systemui.statusbar.notification.stack.NotificationSection[] sections) {
    }
    
    public final void setHeaderForegroundColor(@android.annotation.ColorInt()
    int color) {
    }
    
    @javax.inject.Inject()
    public NotificationSectionsManager(@org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.ConfigurationController configurationController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.KeyguardMediaController keyguardMediaController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.NotificationSectionsFeatureManager sectionsFeatureManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.stack.NotificationSectionsLogger logger, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.statusbar.notification.dagger.IncomingHeader()
    com.android.systemui.statusbar.notification.collection.render.SectionHeaderController incomingHeaderController, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.statusbar.notification.dagger.PeopleHeader()
    com.android.systemui.statusbar.notification.collection.render.SectionHeaderController peopleHeaderController, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.statusbar.notification.dagger.AlertingHeader()
    com.android.systemui.statusbar.notification.collection.render.SectionHeaderController alertingHeaderController, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.statusbar.notification.dagger.SilentHeader()
    com.android.systemui.statusbar.notification.collection.render.SectionHeaderController silentHeaderController) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0002\b\u000b\n\u0002\u0010\u0002\bb\u0018\u0000*\n\b\u0000\u0010\u0001 \u0001*\u00020\u00022\u00020\u0003J\b\u0010\u0010\u001a\u00020\u0011H&R\u001a\u0010\u0004\u001a\u0004\u0018\u00010\u0005X\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b\u0006\u0010\u0007\"\u0004\b\b\u0010\tR\u0012\u0010\n\u001a\u00028\u0000X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u000b\u0010\fR\u001a\u0010\r\u001a\u0004\u0018\u00010\u0005X\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b\u000e\u0010\u0007\"\u0004\b\u000f\u0010\t"}, d2 = {"Lcom/android/systemui/statusbar/notification/stack/NotificationSectionsManager$SectionUpdateState;", "T", "Lcom/android/systemui/statusbar/notification/row/ExpandableView;", "", "currentPosition", "", "getCurrentPosition", "()Ljava/lang/Integer;", "setCurrentPosition", "(Ljava/lang/Integer;)V", "header", "getHeader", "()Lcom/android/systemui/statusbar/notification/row/ExpandableView;", "targetPosition", "getTargetPosition", "setTargetPosition", "adjustViewPosition", ""})
    static abstract interface SectionUpdateState<T extends com.android.systemui.statusbar.notification.row.ExpandableView> {
        
        @org.jetbrains.annotations.NotNull()
        public abstract T getHeader();
        
        @org.jetbrains.annotations.Nullable()
        public abstract java.lang.Integer getCurrentPosition();
        
        public abstract void setCurrentPosition(@org.jetbrains.annotations.Nullable()
        java.lang.Integer p0);
        
        @org.jetbrains.annotations.Nullable()
        public abstract java.lang.Integer getTargetPosition();
        
        public abstract void setTargetPosition(@org.jetbrains.annotations.Nullable()
        java.lang.Integer p0);
        
        public abstract void adjustViewPosition();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\b2\u0018\u00002\u00020\u0001:\u0003\r\u000e\u000fB\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u000e\u0010\u0003\u001a\u00020\u00002\u0006\u0010\u0004\u001a\u00020\u0005J\u000e\u0010\u0006\u001a\u00020\u00072\u0006\u0010\b\u001a\u00020\tJ \u0010\n\u001a\u00020\u0007*\u00020\t2\b\u0010\u000b\u001a\u0004\u0018\u00010\u00052\b\u0010\f\u001a\u0004\u0018\u00010\u0005H\u0002\u0082\u0001\u0003\u0010\u0011\u0012"}, d2 = {"Lcom/android/systemui/statusbar/notification/stack/NotificationSectionsManager$SectionBounds;", "", "()V", "addNotif", "notif", "Lcom/android/systemui/statusbar/notification/row/ExpandableView;", "updateSection", "", "section", "Lcom/android/systemui/statusbar/notification/stack/NotificationSection;", "setFirstAndLastVisibleChildren", "first", "last", "Many", "None", "One", "Lcom/android/systemui/statusbar/notification/stack/NotificationSectionsManager$SectionBounds$Many;", "Lcom/android/systemui/statusbar/notification/stack/NotificationSectionsManager$SectionBounds$One;", "Lcom/android/systemui/statusbar/notification/stack/NotificationSectionsManager$SectionBounds$None;"})
    static abstract class SectionBounds {
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.statusbar.notification.stack.NotificationSectionsManager.SectionBounds addNotif(@org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.notification.row.ExpandableView notif) {
            return null;
        }
        
        public final boolean updateSection(@org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.notification.stack.NotificationSection section) {
            return false;
        }
        
        private final boolean setFirstAndLastVisibleChildren(com.android.systemui.statusbar.notification.stack.NotificationSection $this$setFirstAndLastVisibleChildren, com.android.systemui.statusbar.notification.row.ExpandableView first, com.android.systemui.statusbar.notification.row.ExpandableView last) {
            return false;
        }
        
        private SectionBounds() {
            super();
        }
        
        @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\t\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0005J\t\u0010\t\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\n\u001a\u00020\u0003H\u00c6\u0003J\u001d\u0010\u000b\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u0003H\u00c6\u0001J\u0013\u0010\f\u001a\u00020\r2\b\u0010\u000e\u001a\u0004\u0018\u00010\u000fH\u00d6\u0003J\t\u0010\u0010\u001a\u00020\u0011H\u00d6\u0001J\t\u0010\u0012\u001a\u00020\u0013H\u00d6\u0001R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0006\u0010\u0007R\u0011\u0010\u0004\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\u0007"}, d2 = {"Lcom/android/systemui/statusbar/notification/stack/NotificationSectionsManager$SectionBounds$Many;", "Lcom/android/systemui/statusbar/notification/stack/NotificationSectionsManager$SectionBounds;", "first", "Lcom/android/systemui/statusbar/notification/row/ExpandableView;", "last", "(Lcom/android/systemui/statusbar/notification/row/ExpandableView;Lcom/android/systemui/statusbar/notification/row/ExpandableView;)V", "getFirst", "()Lcom/android/systemui/statusbar/notification/row/ExpandableView;", "getLast", "component1", "component2", "copy", "equals", "", "other", "", "hashCode", "", "toString", ""})
        public static final class Many extends com.android.systemui.statusbar.notification.stack.NotificationSectionsManager.SectionBounds {
            @org.jetbrains.annotations.NotNull()
            private final com.android.systemui.statusbar.notification.row.ExpandableView first = null;
            @org.jetbrains.annotations.NotNull()
            private final com.android.systemui.statusbar.notification.row.ExpandableView last = null;
            
            @org.jetbrains.annotations.NotNull()
            public final com.android.systemui.statusbar.notification.row.ExpandableView getFirst() {
                return null;
            }
            
            @org.jetbrains.annotations.NotNull()
            public final com.android.systemui.statusbar.notification.row.ExpandableView getLast() {
                return null;
            }
            
            public Many(@org.jetbrains.annotations.NotNull()
            com.android.systemui.statusbar.notification.row.ExpandableView first, @org.jetbrains.annotations.NotNull()
            com.android.systemui.statusbar.notification.row.ExpandableView last) {
                super();
            }
            
            @org.jetbrains.annotations.NotNull()
            public final com.android.systemui.statusbar.notification.row.ExpandableView component1() {
                return null;
            }
            
            @org.jetbrains.annotations.NotNull()
            public final com.android.systemui.statusbar.notification.row.ExpandableView component2() {
                return null;
            }
            
            @org.jetbrains.annotations.NotNull()
            public final com.android.systemui.statusbar.notification.stack.NotificationSectionsManager.SectionBounds.Many copy(@org.jetbrains.annotations.NotNull()
            com.android.systemui.statusbar.notification.row.ExpandableView first, @org.jetbrains.annotations.NotNull()
            com.android.systemui.statusbar.notification.row.ExpandableView last) {
                return null;
            }
            
            @org.jetbrains.annotations.NotNull()
            @java.lang.Override()
            public java.lang.String toString() {
                return null;
            }
            
            @java.lang.Override()
            public int hashCode() {
                return 0;
            }
            
            @java.lang.Override()
            public boolean equals(@org.jetbrains.annotations.Nullable()
            java.lang.Object p0) {
                return false;
            }
        }
        
        @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\t\u0010\u0007\u001a\u00020\u0003H\u00c6\u0003J\u0013\u0010\b\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u0003H\u00c6\u0001J\u0013\u0010\t\u001a\u00020\n2\b\u0010\u000b\u001a\u0004\u0018\u00010\fH\u00d6\u0003J\t\u0010\r\u001a\u00020\u000eH\u00d6\u0001J\t\u0010\u000f\u001a\u00020\u0010H\u00d6\u0001R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006"}, d2 = {"Lcom/android/systemui/statusbar/notification/stack/NotificationSectionsManager$SectionBounds$One;", "Lcom/android/systemui/statusbar/notification/stack/NotificationSectionsManager$SectionBounds;", "lone", "Lcom/android/systemui/statusbar/notification/row/ExpandableView;", "(Lcom/android/systemui/statusbar/notification/row/ExpandableView;)V", "getLone", "()Lcom/android/systemui/statusbar/notification/row/ExpandableView;", "component1", "copy", "equals", "", "other", "", "hashCode", "", "toString", ""})
        public static final class One extends com.android.systemui.statusbar.notification.stack.NotificationSectionsManager.SectionBounds {
            @org.jetbrains.annotations.NotNull()
            private final com.android.systemui.statusbar.notification.row.ExpandableView lone = null;
            
            @org.jetbrains.annotations.NotNull()
            public final com.android.systemui.statusbar.notification.row.ExpandableView getLone() {
                return null;
            }
            
            public One(@org.jetbrains.annotations.NotNull()
            com.android.systemui.statusbar.notification.row.ExpandableView lone) {
                super();
            }
            
            @org.jetbrains.annotations.NotNull()
            public final com.android.systemui.statusbar.notification.row.ExpandableView component1() {
                return null;
            }
            
            @org.jetbrains.annotations.NotNull()
            public final com.android.systemui.statusbar.notification.stack.NotificationSectionsManager.SectionBounds.One copy(@org.jetbrains.annotations.NotNull()
            com.android.systemui.statusbar.notification.row.ExpandableView lone) {
                return null;
            }
            
            @org.jetbrains.annotations.NotNull()
            @java.lang.Override()
            public java.lang.String toString() {
                return null;
            }
            
            @java.lang.Override()
            public int hashCode() {
                return 0;
            }
            
            @java.lang.Override()
            public boolean equals(@org.jetbrains.annotations.Nullable()
            java.lang.Object p0) {
                return false;
            }
        }
        
        @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\n\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002"}, d2 = {"Lcom/android/systemui/statusbar/notification/stack/NotificationSectionsManager$SectionBounds$None;", "Lcom/android/systemui/statusbar/notification/stack/NotificationSectionsManager$SectionBounds;", "()V"})
        public static final class None extends com.android.systemui.statusbar.notification.stack.NotificationSectionsManager.SectionBounds {
            @org.jetbrains.annotations.NotNull()
            public static final com.android.systemui.statusbar.notification.stack.NotificationSectionsManager.SectionBounds.None INSTANCE = null;
            
            private None() {
                super();
            }
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/stack/NotificationSectionsManager$Companion;", "", "()V", "DEBUG", "", "TAG", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}