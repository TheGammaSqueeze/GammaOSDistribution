package com.android.systemui.media;

import android.content.Context;
import android.content.Intent;
import android.content.res.ColorStateList;
import android.content.res.Configuration;
import android.util.Log;
import android.util.MathUtils;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import androidx.annotation.VisibleForTesting;
import com.android.systemui.Dumpable;
import com.android.systemui.R;
import com.android.systemui.classifier.FalsingCollector;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.qs.PageIndicator;
import com.android.systemui.shared.system.SysUiStatsLog;
import com.android.systemui.statusbar.notification.collection.legacy.VisualStabilityManager;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.util.Utils;
import com.android.systemui.util.animation.UniqueObjectHostView;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.systemui.util.time.SystemClock;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.util.TreeMap;
import javax.inject.Inject;
import javax.inject.Provider;

/**
 * Class that is responsible for keeping the view carousel up to date.
 * This also handles changes in state and applies them to the media carousel like the expansion.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00fe\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0010\u0007\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010#\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\b\n\n\u0002\u0010\u0015\n\u0002\b\u000b\n\u0002\u0010\t\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\b\r\b\u0007\u0018\u00002\u00020\u0001Bo\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\f\u0010\u0004\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\r\u001a\u00020\u000e\u0012\b\b\u0001\u0010\u000f\u001a\u00020\u0010\u0012\u0006\u0010\u0011\u001a\u00020\u0012\u0012\u0006\u0010\u0013\u001a\u00020\u0014\u0012\u0006\u0010\u0015\u001a\u00020\u0016\u0012\u0006\u0010\u0017\u001a\u00020\u0018\u0012\u0006\u0010\u0019\u001a\u00020\u001a\u00a2\u0006\u0002\u0010\u001bJ*\u0010X\u001a\u00020,2\u0006\u0010Y\u001a\u0002092\b\u0010Z\u001a\u0004\u0018\u0001092\u0006\u0010[\u001a\u00020\\2\u0006\u0010]\u001a\u00020,H\u0002J \u0010^\u001a\u00020Q2\u0006\u0010Y\u001a\u0002092\u0006\u0010[\u001a\u00020_2\u0006\u0010`\u001a\u00020,H\u0002J\u0010\u0010a\u001a\u00020Q2\b\b\u0002\u0010b\u001a\u00020,J-\u0010c\u001a\u00020Q2\u0006\u0010d\u001a\u00020e2\u0006\u0010f\u001a\u00020g2\u000e\u0010h\u001a\n\u0012\u0006\b\u0001\u0012\u0002090iH\u0016\u00a2\u0006\u0002\u0010jJ\b\u0010k\u001a\u00020\u001dH\u0002J\b\u0010l\u001a\u00020\u001dH\u0002J\b\u0010m\u001a\u00020AH\u0002J\b\u0010n\u001a\u00020QH\u0002JZ\u0010o\u001a\u00020Q2\u0006\u0010p\u001a\u00020\u001d2\u0006\u0010q\u001a\u00020\u001d2\u0006\u0010r\u001a\u00020\u001d2\u0006\u0010s\u001a\u00020t2\b\b\u0002\u0010u\u001a\u00020\u001d2\b\b\u0002\u0010v\u001a\u00020\u001d2\b\b\u0002\u0010w\u001a\u00020\u001d2\b\b\u0002\u0010x\u001a\u00020\u001d2\b\b\u0002\u0010y\u001a\u00020,H\u0007J\u000e\u0010z\u001a\u00020Q2\u0006\u0010{\u001a\u00020,J\b\u0010|\u001a\u00020QH\u0002J7\u0010}\u001a\u00020Q2\u0006\u00103\u001a\u00020\u001d2\b\u00101\u001a\u0004\u0018\u0001022\u0006\u0010~\u001a\u00020,2\t\b\u0002\u0010\u007f\u001a\u00030\u0080\u00012\n\b\u0002\u0010\u0081\u0001\u001a\u00030\u0080\u0001J\t\u0010\u0082\u0001\u001a\u00020QH\u0002J\t\u0010\u0083\u0001\u001a\u00020QH\u0002J%\u0010\u0084\u0001\u001a\u00020Q2\u0006\u0010Y\u001a\u0002092\t\b\u0002\u0010\u0085\u0001\u001a\u00020,2\t\b\u0002\u0010\u0086\u0001\u001a\u00020,J\u0015\u0010\u0087\u0001\u001a\u00020Q2\n\u0010\u0088\u0001\u001a\u0005\u0018\u00010\u0089\u0001H\u0002J+\u0010\u008a\u0001\u001a\u00020Q2\u0007\u0010\u008b\u0001\u001a\u00020\u001d2\u0007\u0010\u008c\u0001\u001a\u00020\u001d2\u0007\u0010\u008d\u0001\u001a\u00020*2\u0007\u0010\u008e\u0001\u001a\u00020,J\t\u0010\u008f\u0001\u001a\u00020QH\u0002J\t\u0010\u0090\u0001\u001a\u00020QH\u0002J\t\u0010\u0091\u0001\u001a\u00020QH\u0002J\t\u0010\u0092\u0001\u001a\u00020QH\u0002J\t\u0010\u0093\u0001\u001a\u00020QH\u0002J\u001b\u0010\u0094\u0001\u001a\u00020Q2\u0007\u0010\u0095\u0001\u001a\u00020\u00062\u0007\u0010\u0096\u0001\u001a\u00020,H\u0002R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001c\u001a\u00020\u001dX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001e\u001a\u00020\u001dX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001f\u001a\u00020\u001dX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010 \u001a\u00020!X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\"\u001a\u00020\u001dX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010#\u001a\u00020\u001dX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010$\u001a\u00020\u001dX\u0082\u000e\u00a2\u0006\b\n\u0000\u0012\u0004\b%\u0010&R\u0014\u0010\'\u001a\u00020\u001dX\u0082\u000e\u00a2\u0006\b\n\u0000\u0012\u0004\b(\u0010&R\u000e\u0010)\u001a\u00020*X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001e\u0010-\u001a\u00020,2\u0006\u0010+\u001a\u00020,@BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\b.\u0010/R\u000e\u00100\u001a\u00020,X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u00101\u001a\u0004\u0018\u000102X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u00103\u001a\u00020\u001dX\u0082\u000e\u00a2\u0006\b\n\u0000\u0012\u0004\b4\u0010&R\u001e\u00105\u001a\u00020,2\u0006\u0010+\u001a\u00020,@BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\b6\u0010/R\u0014\u00107\u001a\b\u0012\u0004\u0012\u00020908X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010:\u001a\u00020;X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010<\u001a\u00020=\u00a2\u0006\b\n\u0000\u001a\u0004\b>\u0010?R\u000e\u0010@\u001a\u00020AX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0004\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010B\u001a\u00020A\u00a2\u0006\b\n\u0000\u001a\u0004\bC\u0010DR\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010E\u001a\u00020,X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010F\u001a\u00020GX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010H\u001a\u00020,X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010I\u001a\u00020JX\u0082.\u00a2\u0006\u0002\n\u0000R\u001a\u0010K\u001a\u00020,X\u0084\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bL\u0010M\"\u0004\bN\u0010/R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R \u0010O\u001a\b\u0012\u0004\u0012\u00020Q0PX\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\bR\u0010S\"\u0004\bT\u0010UR\u000e\u0010V\u001a\u00020WX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/MediaCarouselController;", "Lcom/android/systemui/Dumpable;", "context", "Landroid/content/Context;", "mediaControlPanelFactory", "Ljavax/inject/Provider;", "Lcom/android/systemui/media/MediaControlPanel;", "visualStabilityManager", "Lcom/android/systemui/statusbar/notification/collection/legacy/VisualStabilityManager;", "mediaHostStatesManager", "Lcom/android/systemui/media/MediaHostStatesManager;", "activityStarter", "Lcom/android/systemui/plugins/ActivityStarter;", "systemClock", "Lcom/android/systemui/util/time/SystemClock;", "executor", "Lcom/android/systemui/util/concurrency/DelayableExecutor;", "mediaManager", "Lcom/android/systemui/media/MediaDataManager;", "configurationController", "Lcom/android/systemui/statusbar/policy/ConfigurationController;", "falsingCollector", "Lcom/android/systemui/classifier/FalsingCollector;", "falsingManager", "Lcom/android/systemui/plugins/FalsingManager;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "(Landroid/content/Context;Ljavax/inject/Provider;Lcom/android/systemui/statusbar/notification/collection/legacy/VisualStabilityManager;Lcom/android/systemui/media/MediaHostStatesManager;Lcom/android/systemui/plugins/ActivityStarter;Lcom/android/systemui/util/time/SystemClock;Lcom/android/systemui/util/concurrency/DelayableExecutor;Lcom/android/systemui/media/MediaDataManager;Lcom/android/systemui/statusbar/policy/ConfigurationController;Lcom/android/systemui/classifier/FalsingCollector;Lcom/android/systemui/plugins/FalsingManager;Lcom/android/systemui/dump/DumpManager;)V", "bgColor", "", "carouselMeasureHeight", "carouselMeasureWidth", "configListener", "Lcom/android/systemui/statusbar/policy/ConfigurationController$ConfigurationListener;", "currentCarouselHeight", "currentCarouselWidth", "currentEndLocation", "getCurrentEndLocation$annotations", "()V", "currentStartLocation", "getCurrentStartLocation$annotations", "currentTransitionProgress", "", "value", "", "currentlyExpanded", "setCurrentlyExpanded", "(Z)V", "currentlyShowingOnlyActive", "desiredHostState", "Lcom/android/systemui/media/MediaHostState;", "desiredLocation", "getDesiredLocation$annotations", "isRtl", "setRtl", "keysNeedRemoval", "", "", "mediaCarousel", "Lcom/android/systemui/media/MediaScrollView;", "mediaCarouselScrollHandler", "Lcom/android/systemui/media/MediaCarouselScrollHandler;", "getMediaCarouselScrollHandler", "()Lcom/android/systemui/media/MediaCarouselScrollHandler;", "mediaContent", "Landroid/view/ViewGroup;", "mediaFrame", "getMediaFrame", "()Landroid/view/ViewGroup;", "needsReordering", "pageIndicator", "Lcom/android/systemui/qs/PageIndicator;", "playersVisible", "settingsButton", "Landroid/view/View;", "shouldScrollToActivePlayer", "getShouldScrollToActivePlayer", "()Z", "setShouldScrollToActivePlayer", "updateUserVisibility", "Lkotlin/Function0;", "", "getUpdateUserVisibility", "()Lkotlin/jvm/functions/Function0;", "setUpdateUserVisibility", "(Lkotlin/jvm/functions/Function0;)V", "visualStabilityCallback", "Lcom/android/systemui/statusbar/notification/collection/legacy/VisualStabilityManager$Callback;", "addOrUpdatePlayer", "key", "oldKey", "data", "Lcom/android/systemui/media/MediaData;", "isSsReactivated", "addSmartspaceMediaRecommendations", "Lcom/android/systemui/media/SmartspaceMediaData;", "shouldPrioritize", "closeGuts", "immediate", "dump", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "getBackgroundColor", "getForegroundColor", "inflateMediaCarousel", "inflateSettingsButton", "logSmartspaceCardReported", "eventId", "instanceId", "uid", "surfaces", "", "interactedSubcardRank", "interactedSubcardCardinality", "rank", "receivedLatencyMillis", "isSwipeToDismiss", "logSmartspaceImpression", "qsExpanded", "maybeResetSettingsCog", "onDesiredLocationChanged", "animate", "duration", "", "startDelay", "onSwipeToDismiss", "recreatePlayers", "removePlayer", "dismissMediaData", "dismissRecommendation", "reorderAllPlayers", "previousVisiblePlayerKey", "Lcom/android/systemui/media/MediaPlayerData$MediaSortKey;", "setCurrentState", "startLocation", "endLocation", "progress", "immediately", "updateCarouselDimensions", "updateCarouselSize", "updatePageIndicator", "updatePageIndicatorAlpha", "updatePageIndicatorLocation", "updatePlayerToState", "mediaPlayer", "noAnimation"})
@com.android.systemui.dagger.SysUISingleton()
public final class MediaCarouselController implements com.android.systemui.Dumpable {
    
    /**
     * The current width of the carousel
     */
    private int currentCarouselWidth = 0;
    
    /**
     * The current height of the carousel
     */
    private int currentCarouselHeight = 0;
    
    /**
     * Are we currently showing only active players
     */
    private boolean currentlyShowingOnlyActive = false;
    
    /**
     * Is the player currently visible (at the end of the transformation
     */
    private boolean playersVisible = false;
    
    /**
     * The desired location where we'll be at the end of the transformation. Usually this matches
     * the end location, except when we're still waiting on a state update call.
     */
    private int desiredLocation = -1;
    
    /**
     * The ending location of the view where it ends when all animations and transitions have
     * finished
     */
    private int currentEndLocation = -1;
    
    /**
     * The ending location of the view where it ends when all animations and transitions have
     * finished
     */
    private int currentStartLocation = -1;
    
    /**
     * The progress of the transition or 1.0 if there is no transition happening
     */
    private float currentTransitionProgress = 1.0F;
    
    /**
     * The measured width of the carousel
     */
    private int carouselMeasureWidth = 0;
    
    /**
     * The measured height of the carousel
     */
    private int carouselMeasureHeight = 0;
    private com.android.systemui.media.MediaHostState desiredHostState;
    private final com.android.systemui.media.MediaScrollView mediaCarousel = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.media.MediaCarouselScrollHandler mediaCarouselScrollHandler = null;
    @org.jetbrains.annotations.NotNull()
    private final android.view.ViewGroup mediaFrame = null;
    private android.view.View settingsButton;
    private final android.view.ViewGroup mediaContent = null;
    private final com.android.systemui.qs.PageIndicator pageIndicator = null;
    private final com.android.systemui.statusbar.notification.collection.legacy.VisualStabilityManager.Callback visualStabilityCallback = null;
    private boolean needsReordering = false;
    private java.util.Set<java.lang.String> keysNeedRemoval;
    private int bgColor;
    private boolean shouldScrollToActivePlayer = false;
    private boolean isRtl = false;
    private boolean currentlyExpanded = true;
    private final com.android.systemui.statusbar.policy.ConfigurationController.ConfigurationListener configListener = null;
    
    /**
     * Update MediaCarouselScrollHandler.visibleToUser to reflect media card container visibility.
     * It will be called when the container is out of view.
     */
    public kotlin.jvm.functions.Function0<kotlin.Unit> updateUserVisibility;
    private final android.content.Context context = null;
    private final javax.inject.Provider<com.android.systemui.media.MediaControlPanel> mediaControlPanelFactory = null;
    private final com.android.systemui.statusbar.notification.collection.legacy.VisualStabilityManager visualStabilityManager = null;
    private final com.android.systemui.media.MediaHostStatesManager mediaHostStatesManager = null;
    private final com.android.systemui.plugins.ActivityStarter activityStarter = null;
    private final com.android.systemui.util.time.SystemClock systemClock = null;
    private final com.android.systemui.media.MediaDataManager mediaManager = null;
    
    /**
     * The desired location where we'll be at the end of the transformation. Usually this matches
     * the end location, except when we're still waiting on a state update call.
     */
    @MediaLocation()
    @java.lang.Deprecated()
    private static void getDesiredLocation$annotations() {
    }
    
    /**
     * The ending location of the view where it ends when all animations and transitions have
     * finished
     */
    @MediaLocation()
    @java.lang.Deprecated()
    private static void getCurrentEndLocation$annotations() {
    }
    
    /**
     * The ending location of the view where it ends when all animations and transitions have
     * finished
     */
    @MediaLocation()
    @java.lang.Deprecated()
    private static void getCurrentStartLocation$annotations() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.media.MediaCarouselScrollHandler getMediaCarouselScrollHandler() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.view.ViewGroup getMediaFrame() {
        return null;
    }
    
    protected final boolean getShouldScrollToActivePlayer() {
        return false;
    }
    
    protected final void setShouldScrollToActivePlayer(boolean p0) {
    }
    
    private final void setRtl(boolean value) {
    }
    
    private final void setCurrentlyExpanded(boolean value) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final kotlin.jvm.functions.Function0<kotlin.Unit> getUpdateUserVisibility() {
        return null;
    }
    
    public final void setUpdateUserVisibility(@org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<kotlin.Unit> p0) {
    }
    
    private final void inflateSettingsButton() {
    }
    
    private final android.view.ViewGroup inflateMediaCarousel() {
        return null;
    }
    
    private final void reorderAllPlayers(com.android.systemui.media.MediaPlayerData.MediaSortKey previousVisiblePlayerKey) {
    }
    
    private final boolean addOrUpdatePlayer(java.lang.String key, java.lang.String oldKey, com.android.systemui.media.MediaData data, boolean isSsReactivated) {
        return false;
    }
    
    private final void addSmartspaceMediaRecommendations(java.lang.String key, com.android.systemui.media.SmartspaceMediaData data, boolean shouldPrioritize) {
    }
    
    public final void removePlayer(@org.jetbrains.annotations.NotNull()
    java.lang.String key, boolean dismissMediaData, boolean dismissRecommendation) {
    }
    
    private final void recreatePlayers() {
    }
    
    private final int getBackgroundColor() {
        return 0;
    }
    
    private final int getForegroundColor() {
        return 0;
    }
    
    private final void updatePageIndicator() {
    }
    
    /**
     * Set a new interpolated state for all players. This is a state that is usually controlled
     * by a finger movement where the user drags from one state to the next.
     *
     * @param startLocation the start location of our state or -1 if this is directly set
     * @param endLocation the ending location of our state.
     * @param progress the progress of the transition between startLocation and endlocation. If
     *                this is not a guided transformation, this will be 1.0f
     * @param immediately should this state be applied immediately, canceling all animations?
     */
    public final void setCurrentState(@MediaLocation()
    int startLocation, @MediaLocation()
    int endLocation, float progress, boolean immediately) {
    }
    
    private final void updatePageIndicatorAlpha() {
    }
    
    private final void updatePageIndicatorLocation() {
    }
    
    /**
     * Update the dimension of this carousel.
     */
    private final void updateCarouselDimensions() {
    }
    
    private final void maybeResetSettingsCog() {
    }
    
    private final void updatePlayerToState(com.android.systemui.media.MediaControlPanel mediaPlayer, boolean noAnimation) {
    }
    
    /**
     * The desired location of this view has changed. We should remeasure the view to match
     * the new bounds and kick off bounds animations if necessary.
     * If an animation is happening, an animation is kicked of externally, which sets a new
     * current state until we reach the targetState.
     *
     * @param desiredLocation the location we're going to
     * @param desiredHostState the target state we're transitioning to
     * @param animate should this be animated
     */
    public final void onDesiredLocationChanged(int desiredLocation, @org.jetbrains.annotations.Nullable()
    com.android.systemui.media.MediaHostState desiredHostState, boolean animate, long duration, long startDelay) {
    }
    
    public final void closeGuts(boolean immediate) {
    }
    
    /**
     * Update the size of the carousel, remeasuring it if necessary.
     */
    private final void updateCarouselSize() {
    }
    
    /**
     * Log the user impression for media card at visibleMediaIndex.
     */
    public final void logSmartspaceImpression(boolean qsExpanded) {
    }
    
    /**
     * Log Smartspace events
     *
     * @param eventId UI event id (e.g. 800 for SMARTSPACE_CARD_SEEN)
     * @param instanceId id to uniquely identify a card, e.g. each headphone generates a new
     * instanceId
     * @param uid uid for the application that media comes from
     * @param surfaces list of display surfaces the media card is on (e.g. lockscreen, shade) when
     * the event happened
     * @param interactedSubcardRank the rank for interacted media item for recommendation card, -1
     * for tapping on card but not on any media item, 0 for first media item, 1 for second, etc.
     * @param interactedSubcardCardinality how many media items were shown to the user when there
     * is user interaction
     * @param rank the rank for media card in the media carousel, starting from 0
     * @param receivedLatencyMillis latency in milliseconds for card received events. E.g. latency
     * between headphone connection to sysUI displays media recommendation card
     * @param isSwipeToDismiss whether is to log swipe-to-dismiss event
     */
    public final void logSmartspaceCardReported(int eventId, int instanceId, int uid, @org.jetbrains.annotations.NotNull()
    int[] surfaces, int interactedSubcardRank, int interactedSubcardCardinality, int rank, int receivedLatencyMillis, boolean isSwipeToDismiss) {
    }
    
    /**
     * Log Smartspace events
     *
     * @param eventId UI event id (e.g. 800 for SMARTSPACE_CARD_SEEN)
     * @param instanceId id to uniquely identify a card, e.g. each headphone generates a new
     * instanceId
     * @param uid uid for the application that media comes from
     * @param surfaces list of display surfaces the media card is on (e.g. lockscreen, shade) when
     * the event happened
     * @param interactedSubcardRank the rank for interacted media item for recommendation card, -1
     * for tapping on card but not on any media item, 0 for first media item, 1 for second, etc.
     * @param interactedSubcardCardinality how many media items were shown to the user when there
     * is user interaction
     * @param rank the rank for media card in the media carousel, starting from 0
     * @param receivedLatencyMillis latency in milliseconds for card received events. E.g. latency
     * between headphone connection to sysUI displays media recommendation card
     * @param isSwipeToDismiss whether is to log swipe-to-dismiss event
     */
    public final void logSmartspaceCardReported(int eventId, int instanceId, int uid, @org.jetbrains.annotations.NotNull()
    int[] surfaces, int interactedSubcardRank, int interactedSubcardCardinality, int rank, int receivedLatencyMillis) {
    }
    
    /**
     * Log Smartspace events
     *
     * @param eventId UI event id (e.g. 800 for SMARTSPACE_CARD_SEEN)
     * @param instanceId id to uniquely identify a card, e.g. each headphone generates a new
     * instanceId
     * @param uid uid for the application that media comes from
     * @param surfaces list of display surfaces the media card is on (e.g. lockscreen, shade) when
     * the event happened
     * @param interactedSubcardRank the rank for interacted media item for recommendation card, -1
     * for tapping on card but not on any media item, 0 for first media item, 1 for second, etc.
     * @param interactedSubcardCardinality how many media items were shown to the user when there
     * is user interaction
     * @param rank the rank for media card in the media carousel, starting from 0
     * @param receivedLatencyMillis latency in milliseconds for card received events. E.g. latency
     * between headphone connection to sysUI displays media recommendation card
     * @param isSwipeToDismiss whether is to log swipe-to-dismiss event
     */
    public final void logSmartspaceCardReported(int eventId, int instanceId, int uid, @org.jetbrains.annotations.NotNull()
    int[] surfaces, int interactedSubcardRank, int interactedSubcardCardinality, int rank) {
    }
    
    /**
     * Log Smartspace events
     *
     * @param eventId UI event id (e.g. 800 for SMARTSPACE_CARD_SEEN)
     * @param instanceId id to uniquely identify a card, e.g. each headphone generates a new
     * instanceId
     * @param uid uid for the application that media comes from
     * @param surfaces list of display surfaces the media card is on (e.g. lockscreen, shade) when
     * the event happened
     * @param interactedSubcardRank the rank for interacted media item for recommendation card, -1
     * for tapping on card but not on any media item, 0 for first media item, 1 for second, etc.
     * @param interactedSubcardCardinality how many media items were shown to the user when there
     * is user interaction
     * @param rank the rank for media card in the media carousel, starting from 0
     * @param receivedLatencyMillis latency in milliseconds for card received events. E.g. latency
     * between headphone connection to sysUI displays media recommendation card
     * @param isSwipeToDismiss whether is to log swipe-to-dismiss event
     */
    public final void logSmartspaceCardReported(int eventId, int instanceId, int uid, @org.jetbrains.annotations.NotNull()
    int[] surfaces, int interactedSubcardRank, int interactedSubcardCardinality) {
    }
    
    /**
     * Log Smartspace events
     *
     * @param eventId UI event id (e.g. 800 for SMARTSPACE_CARD_SEEN)
     * @param instanceId id to uniquely identify a card, e.g. each headphone generates a new
     * instanceId
     * @param uid uid for the application that media comes from
     * @param surfaces list of display surfaces the media card is on (e.g. lockscreen, shade) when
     * the event happened
     * @param interactedSubcardRank the rank for interacted media item for recommendation card, -1
     * for tapping on card but not on any media item, 0 for first media item, 1 for second, etc.
     * @param interactedSubcardCardinality how many media items were shown to the user when there
     * is user interaction
     * @param rank the rank for media card in the media carousel, starting from 0
     * @param receivedLatencyMillis latency in milliseconds for card received events. E.g. latency
     * between headphone connection to sysUI displays media recommendation card
     * @param isSwipeToDismiss whether is to log swipe-to-dismiss event
     */
    public final void logSmartspaceCardReported(int eventId, int instanceId, int uid, @org.jetbrains.annotations.NotNull()
    int[] surfaces, int interactedSubcardRank) {
    }
    
    /**
     * Log Smartspace events
     *
     * @param eventId UI event id (e.g. 800 for SMARTSPACE_CARD_SEEN)
     * @param instanceId id to uniquely identify a card, e.g. each headphone generates a new
     * instanceId
     * @param uid uid for the application that media comes from
     * @param surfaces list of display surfaces the media card is on (e.g. lockscreen, shade) when
     * the event happened
     * @param interactedSubcardRank the rank for interacted media item for recommendation card, -1
     * for tapping on card but not on any media item, 0 for first media item, 1 for second, etc.
     * @param interactedSubcardCardinality how many media items were shown to the user when there
     * is user interaction
     * @param rank the rank for media card in the media carousel, starting from 0
     * @param receivedLatencyMillis latency in milliseconds for card received events. E.g. latency
     * between headphone connection to sysUI displays media recommendation card
     * @param isSwipeToDismiss whether is to log swipe-to-dismiss event
     */
    public final void logSmartspaceCardReported(int eventId, int instanceId, int uid, @org.jetbrains.annotations.NotNull()
    int[] surfaces) {
    }
    
    private final void onSwipeToDismiss() {
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    @javax.inject.Inject()
    public MediaCarouselController(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    javax.inject.Provider<com.android.systemui.media.MediaControlPanel> mediaControlPanelFactory, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.legacy.VisualStabilityManager visualStabilityManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaHostStatesManager mediaHostStatesManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.ActivityStarter activityStarter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.time.SystemClock systemClock, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    com.android.systemui.util.concurrency.DelayableExecutor executor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaDataManager mediaManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.ConfigurationController configurationController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.classifier.FalsingCollector falsingCollector, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.FalsingManager falsingManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager) {
        super();
    }
}