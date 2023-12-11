package com.android.systemui.statusbar;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.ObjectAnimator;
import android.animation.ValueAnimator;
import android.content.Context;
import android.content.res.Configuration;
import android.os.SystemClock;
import android.util.IndentingPrintWriter;
import android.util.MathUtils;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewConfiguration;
import androidx.annotation.VisibleForTesting;
import com.android.systemui.Dumpable;
import com.android.systemui.ExpandHelper;
import com.android.systemui.Gefingerpoken;
import com.android.systemui.R;
import com.android.systemui.animation.Interpolators;
import com.android.systemui.biometrics.UdfpsKeyguardViewController;
import com.android.systemui.classifier.Classifier;
import com.android.systemui.classifier.FalsingCollector;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.media.MediaHierarchyManager;
import com.android.systemui.plugins.ActivityStarter.OnDismissAction;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.qs.QS;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.row.ExpandableNotificationRow;
import com.android.systemui.statusbar.notification.row.ExpandableView;
import com.android.systemui.statusbar.notification.stack.AmbientState;
import com.android.systemui.statusbar.notification.stack.NotificationStackScrollLayoutController;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.phone.LSShadeTransitionLogger;
import com.android.systemui.statusbar.phone.NotificationPanelViewController;
import com.android.systemui.statusbar.phone.ScrimController;
import com.android.systemui.statusbar.phone.StatusBar;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.util.Utils;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import javax.inject.Inject;

/**
 * A class that controls the lockscreen to shade transition
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0084\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0010\t\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u0007\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\n\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\t\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0013\n\u0002\u0018\u0002\n\u0002\b\u0006\b\u0007\u0018\u00002\u00020\u0001Bw\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u0006\u0010\f\u001a\u00020\r\u0012\u0006\u0010\u000e\u001a\u00020\u000f\u0012\u0006\u0010\u0010\u001a\u00020\u0011\u0012\u0006\u0010\u0012\u001a\u00020\u0013\u0012\u0006\u0010\u0014\u001a\u00020\u0015\u0012\u0006\u0010\u0016\u001a\u00020\u0017\u0012\u0006\u0010\u0018\u001a\u00020\u0019\u0012\u0006\u0010\u001a\u001a\u00020\u001b\u0012\u0006\u0010\u001c\u001a\u00020\u001d\u00a2\u0006\u0002\u0010\u001eJ\u0012\u0010h\u001a\u00020\"2\b\b\u0002\u0010i\u001a\u00020!H\u0002J\u000e\u0010j\u001a\u00020\"2\u0006\u0010k\u001a\u00020lJ\r\u0010m\u001a\u000209H\u0000\u00a2\u0006\u0002\bnJ-\u0010o\u001a\u00020\"2\u0006\u0010p\u001a\u00020q2\u0006\u0010r\u001a\u00020s2\u000e\u0010t\u001a\n\u0012\u0006\b\u0001\u0012\u00020v0uH\u0016\u00a2\u0006\u0002\u0010wJ\u000e\u0010x\u001a\u00020\"2\u0006\u0010y\u001a\u000209J\u001c\u0010z\u001a\u00020\"2\b\u0010{\u001a\u0004\u0018\u00010|2\b\b\u0002\u0010}\u001a\u000209H\u0007J9\u0010~\u001a\u00020\"2\b\u0010\u007f\u001a\u0004\u0018\u00010|2\u0017\b\u0002\u0010\u0080\u0001\u001a\u0010\u0012\u0004\u0012\u00020!\u0012\u0004\u0012\u00020\"\u0018\u00010 2\f\b\u0002\u0010\u0081\u0001\u001a\u0005\u0018\u00010\u0082\u0001H\u0002J\u001b\u0010\u0083\u0001\u001a\u0002092\n\u0010\u0084\u0001\u001a\u0005\u0018\u00010\u0085\u0001H\u0000\u00a2\u0006\u0003\b\u0086\u0001J\u0018\u0010\u0087\u0001\u001a\u00020\"2\u0007\u0010\u0088\u0001\u001a\u000209H\u0000\u00a2\u0006\u0003\b\u0089\u0001J\u000f\u0010\u008a\u0001\u001a\u00020\"H\u0000\u00a2\u0006\u0003\b\u008b\u0001J\u001b\u0010\u008c\u0001\u001a\u00020\"2\n\u0010\u008d\u0001\u001a\u0005\u0018\u00010\u0085\u0001H\u0000\u00a2\u0006\u0003\b\u008e\u0001J#\u0010\u008f\u0001\u001a\u00020\"2\t\u0010\u008d\u0001\u001a\u0004\u0018\u00010|2\u0007\u0010\u0090\u0001\u001a\u00020$H\u0000\u00a2\u0006\u0003\b\u0091\u0001J\u0018\u0010\u0092\u0001\u001a\u00020\"2\u0006\u0010i\u001a\u00020!2\u0007\u0010\u0093\u0001\u001a\u00020$J\u0007\u0010\u0094\u0001\u001a\u00020\"J\u0011\u0010\u0095\u0001\u001a\u00020\"2\u0006\u0010i\u001a\u00020!H\u0002J0\u0010\u0096\u0001\u001a\u00020\"2\u0007\u0010\u0097\u0001\u001a\u00020(2\b\b\u0002\u0010i\u001a\u00020!2\u0012\b\u0002\u0010\u0098\u0001\u001a\u000b\u0012\u0004\u0012\u00020\"\u0018\u00010\u0099\u0001H\u0002J\u001b\u0010\u009a\u0001\u001a\u00020\"2\u0007\u0010\u009b\u0001\u001a\u00020(2\t\b\u0002\u0010\u009c\u0001\u001a\u000209J\u000f\u0010\u009d\u0001\u001a\u00020\"2\u0006\u0010I\u001a\u00020JJ\u0011\u0010\u009e\u0001\u001a\u00020\"2\u0006\u0010)\u001a\u00020(H\u0002J\t\u0010\u009f\u0001\u001a\u00020\"H\u0002R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001c\u0010\u001f\u001a\u0010\u0012\u0004\u0012\u00020!\u0012\u0004\u0012\u00020\"\u0018\u00010 X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0014\u001a\u00020\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010#\u001a\u00020$8F\u00a2\u0006\u0006\u001a\u0004\b%\u0010&R$\u0010)\u001a\u00020(2\u0006\u0010\'\u001a\u00020(@@X\u0080\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b*\u0010+\"\u0004\b,\u0010-R&\u0010.\u001a\u0004\u0018\u00010/8\u0000@\u0000X\u0081\u000e\u00a2\u0006\u0014\n\u0000\u0012\u0004\b0\u00101\u001a\u0004\b2\u00103\"\u0004\b4\u00105R\u0010\u00106\u001a\u0004\u0018\u000107X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u00108\u001a\u000209X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010:\u001a\u00020$X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010;\u001a\u0002098@X\u0080\u0004\u00a2\u0006\u0006\u001a\u0004\b<\u0010=R\u0014\u0010>\u001a\u0002098@X\u0080\u0004\u00a2\u0006\u0006\u001a\u0004\b?\u0010=R\u001e\u0010A\u001a\u0002092\u0006\u0010@\u001a\u000209@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\bA\u0010=R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010B\u001a\u000209X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010C\u001a\u00020DX\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\bE\u0010F\"\u0004\bG\u0010HR\u000e\u0010I\u001a\u00020JX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010K\u001a\u00020(X\u0082\u000e\u00a2\u0006\u0002\n\u0000R&\u0010L\u001a\u0004\u0018\u00010/8\u0000@\u0000X\u0081\u000e\u00a2\u0006\u0014\n\u0000\u0012\u0004\bM\u00101\u001a\u0004\bN\u00103\"\u0004\bO\u00105R\u001a\u0010P\u001a\u00020QX\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\bR\u0010S\"\u0004\bT\u0010UR\u000e\u0010\u0010\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010V\u001a\u00020$X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010W\u001a\u00020XX\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\bY\u0010Z\"\u0004\b[\u0010\\R\u0011\u0010]\u001a\u00020^\u00a2\u0006\b\n\u0000\u001a\u0004\b_\u0010`R\u001c\u0010a\u001a\u0004\u0018\u00010bX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bc\u0010d\"\u0004\be\u0010fR\u000e\u0010g\u001a\u000209X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/LockscreenShadeTransitionController;", "Lcom/android/systemui/Dumpable;", "statusBarStateController", "Lcom/android/systemui/statusbar/SysuiStatusBarStateController;", "logger", "Lcom/android/systemui/statusbar/phone/LSShadeTransitionLogger;", "keyguardBypassController", "Lcom/android/systemui/statusbar/phone/KeyguardBypassController;", "lockScreenUserManager", "Lcom/android/systemui/statusbar/NotificationLockscreenUserManager;", "falsingCollector", "Lcom/android/systemui/classifier/FalsingCollector;", "ambientState", "Lcom/android/systemui/statusbar/notification/stack/AmbientState;", "mediaHierarchyManager", "Lcom/android/systemui/media/MediaHierarchyManager;", "scrimController", "Lcom/android/systemui/statusbar/phone/ScrimController;", "depthController", "Lcom/android/systemui/statusbar/NotificationShadeDepthController;", "context", "Landroid/content/Context;", "wakefulnessLifecycle", "Lcom/android/systemui/keyguard/WakefulnessLifecycle;", "configurationController", "Lcom/android/systemui/statusbar/policy/ConfigurationController;", "falsingManager", "Lcom/android/systemui/plugins/FalsingManager;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "(Lcom/android/systemui/statusbar/SysuiStatusBarStateController;Lcom/android/systemui/statusbar/phone/LSShadeTransitionLogger;Lcom/android/systemui/statusbar/phone/KeyguardBypassController;Lcom/android/systemui/statusbar/NotificationLockscreenUserManager;Lcom/android/systemui/classifier/FalsingCollector;Lcom/android/systemui/statusbar/notification/stack/AmbientState;Lcom/android/systemui/media/MediaHierarchyManager;Lcom/android/systemui/statusbar/phone/ScrimController;Lcom/android/systemui/statusbar/NotificationShadeDepthController;Landroid/content/Context;Lcom/android/systemui/keyguard/WakefulnessLifecycle;Lcom/android/systemui/statusbar/policy/ConfigurationController;Lcom/android/systemui/plugins/FalsingManager;Lcom/android/systemui/dump/DumpManager;)V", "animationHandlerOnKeyguardDismiss", "Lkotlin/Function1;", "", "", "distanceUntilShowingPulsingNotifications", "", "getDistanceUntilShowingPulsingNotifications", "()I", "value", "", "dragDownAmount", "getDragDownAmount$main", "()F", "setDragDownAmount$main", "(F)V", "dragDownAnimator", "Landroid/animation/ValueAnimator;", "getDragDownAnimator$main$annotations", "()V", "getDragDownAnimator$main", "()Landroid/animation/ValueAnimator;", "setDragDownAnimator$main", "(Landroid/animation/ValueAnimator;)V", "draggedDownEntry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "forceApplyAmount", "", "fullTransitionDistance", "isDragDownAnywhereEnabled", "isDragDownAnywhereEnabled$main", "()Z", "isFalsingCheckNeeded", "isFalsingCheckNeeded$main", "<set-?>", "isWakingToShadeLocked", "nextHideKeyguardNeedsNoAnimation", "notificationPanelController", "Lcom/android/systemui/statusbar/phone/NotificationPanelViewController;", "getNotificationPanelController", "()Lcom/android/systemui/statusbar/phone/NotificationPanelViewController;", "setNotificationPanelController", "(Lcom/android/systemui/statusbar/phone/NotificationPanelViewController;)V", "nsslController", "Lcom/android/systemui/statusbar/notification/stack/NotificationStackScrollLayoutController;", "pulseHeight", "pulseHeightAnimator", "getPulseHeightAnimator$main$annotations", "getPulseHeightAnimator$main", "setPulseHeightAnimator$main", "qS", "Lcom/android/systemui/plugins/qs/QS;", "getQS", "()Lcom/android/systemui/plugins/qs/QS;", "setQS", "(Lcom/android/systemui/plugins/qs/QS;)V", "scrimTransitionDistance", "statusbar", "Lcom/android/systemui/statusbar/phone/StatusBar;", "getStatusbar", "()Lcom/android/systemui/statusbar/phone/StatusBar;", "setStatusbar", "(Lcom/android/systemui/statusbar/phone/StatusBar;)V", "touchHelper", "Lcom/android/systemui/statusbar/DragDownHelper;", "getTouchHelper", "()Lcom/android/systemui/statusbar/DragDownHelper;", "udfpsKeyguardViewController", "Lcom/android/systemui/biometrics/UdfpsKeyguardViewController;", "getUdfpsKeyguardViewController", "()Lcom/android/systemui/biometrics/UdfpsKeyguardViewController;", "setUdfpsKeyguardViewController", "(Lcom/android/systemui/biometrics/UdfpsKeyguardViewController;)V", "useSplitShade", "animateAppear", "delay", "bindController", "notificationShelfController", "Lcom/android/systemui/statusbar/NotificationShelfController;", "canDragDown", "canDragDown$main", "dump", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "finishPulseAnimation", "cancelled", "goToLockedShade", "expandedView", "Landroid/view/View;", "needsQSAnimation", "goToLockedShadeInternal", "expandView", "animationHandler", "cancelAction", "Ljava/lang/Runnable;", "isDragDownEnabledForView", "view", "Lcom/android/systemui/statusbar/notification/row/ExpandableView;", "isDragDownEnabledForView$main", "onCrossedThreshold", "above", "onCrossedThreshold$main", "onDragDownReset", "onDragDownReset$main", "onDragDownStarted", "startingChild", "onDragDownStarted$main", "onDraggedDown", "dragLengthY", "onDraggedDown$main", "onHideKeyguard", "previousState", "onPulseExpansionStarted", "performDefaultGoToFullShadeAnimation", "setDragDownAmountAnimated", "target", "endlistener", "Lkotlin/Function0;", "setPulseHeight", "height", "animate", "setStackScroller", "transitionToShadeAmountCommon", "updateResources"})
@com.android.systemui.dagger.SysUISingleton()
public final class LockscreenShadeTransitionController implements com.android.systemui.Dumpable {
    private float pulseHeight = 0.0F;
    private boolean useSplitShade = false;
    private com.android.systemui.statusbar.notification.stack.NotificationStackScrollLayoutController nsslController;
    public com.android.systemui.statusbar.phone.NotificationPanelViewController notificationPanelController;
    public com.android.systemui.statusbar.phone.StatusBar statusbar;
    public com.android.systemui.plugins.qs.QS qS;
    
    /**
     * A handler that handles the next keyguard dismiss animation.
     */
    private kotlin.jvm.functions.Function1<? super java.lang.Long, kotlin.Unit> animationHandlerOnKeyguardDismiss;
    
    /**
     * The entry that was just dragged down on.
     */
    private com.android.systemui.statusbar.notification.collection.NotificationEntry draggedDownEntry;
    
    /**
     * The current animator if any
     */
    @org.jetbrains.annotations.Nullable()
    private android.animation.ValueAnimator dragDownAnimator;
    
    /**
     * The current pulse height animator if any
     */
    @org.jetbrains.annotations.Nullable()
    private android.animation.ValueAnimator pulseHeightAnimator;
    
    /**
     * Distance that the full shade transition takes in order for scrim to fully transition to
     * the shade (in alpha)
     */
    private int scrimTransitionDistance = 0;
    
    /**
     * Distance that the full transition takes in order for us to fully transition to the shade
     */
    private int fullTransitionDistance = 0;
    
    /**
     * Flag to make sure that the dragDownAmount is applied to the listeners even when in the
     * locked down shade.
     */
    private boolean forceApplyAmount = false;
    
    /**
     * A flag to suppress the default animation when unlocking in the locked down shade.
     */
    private boolean nextHideKeyguardNeedsNoAnimation = false;
    
    /**
     * Are we currently waking up to the shade locked
     */
    private boolean isWakingToShadeLocked = false;
    
    /**
     * The udfpsKeyguardViewController if it exists.
     */
    @org.jetbrains.annotations.Nullable()
    private com.android.systemui.biometrics.UdfpsKeyguardViewController udfpsKeyguardViewController;
    
    /**
     * The touch helper responsible for the drag down animation.
     */
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.statusbar.DragDownHelper touchHelper = null;
    
    /**
     * The amount in pixels that the user has dragged down.
     */
    private float dragDownAmount = 0.0F;
    private final com.android.systemui.statusbar.SysuiStatusBarStateController statusBarStateController = null;
    private final com.android.systemui.statusbar.phone.LSShadeTransitionLogger logger = null;
    private final com.android.systemui.statusbar.phone.KeyguardBypassController keyguardBypassController = null;
    private final com.android.systemui.statusbar.NotificationLockscreenUserManager lockScreenUserManager = null;
    private final com.android.systemui.classifier.FalsingCollector falsingCollector = null;
    private final com.android.systemui.statusbar.notification.stack.AmbientState ambientState = null;
    private final com.android.systemui.media.MediaHierarchyManager mediaHierarchyManager = null;
    private final com.android.systemui.statusbar.phone.ScrimController scrimController = null;
    private final com.android.systemui.statusbar.NotificationShadeDepthController depthController = null;
    private final android.content.Context context = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.phone.NotificationPanelViewController getNotificationPanelController() {
        return null;
    }
    
    public final void setNotificationPanelController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.NotificationPanelViewController p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.phone.StatusBar getStatusbar() {
        return null;
    }
    
    public final void setStatusbar(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.StatusBar p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.plugins.qs.QS getQS() {
        return null;
    }
    
    public final void setQS(@org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.qs.QS p0) {
    }
    
    /**
     * The current animator if any
     */
    @androidx.annotation.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getDragDownAnimator$main$annotations() {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.animation.ValueAnimator getDragDownAnimator$main() {
        return null;
    }
    
    public final void setDragDownAnimator$main(@org.jetbrains.annotations.Nullable()
    android.animation.ValueAnimator p0) {
    }
    
    /**
     * The current pulse height animator if any
     */
    @androidx.annotation.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getPulseHeightAnimator$main$annotations() {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.animation.ValueAnimator getPulseHeightAnimator$main() {
        return null;
    }
    
    public final void setPulseHeightAnimator$main(@org.jetbrains.annotations.Nullable()
    android.animation.ValueAnimator p0) {
    }
    
    public final boolean isWakingToShadeLocked() {
        return false;
    }
    
    public final int getDistanceUntilShowingPulsingNotifications() {
        return 0;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.biometrics.UdfpsKeyguardViewController getUdfpsKeyguardViewController() {
        return null;
    }
    
    public final void setUdfpsKeyguardViewController(@org.jetbrains.annotations.Nullable()
    com.android.systemui.biometrics.UdfpsKeyguardViewController p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.DragDownHelper getTouchHelper() {
        return null;
    }
    
    private final void updateResources() {
    }
    
    public final void setStackScroller(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.stack.NotificationStackScrollLayoutController nsslController) {
    }
    
    /**
     * Initialize the shelf controller such that clicks on it will expand the shade
     */
    public final void bindController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationShelfController notificationShelfController) {
    }
    
    /**
     * @return true if the interaction is accepted, false if it should be cancelled
     */
    public final boolean canDragDown$main() {
        return false;
    }
    
    /**
     * Called by the touch helper when when a gesture has completed all the way and released.
     */
    public final void onDraggedDown$main(@org.jetbrains.annotations.Nullable()
    android.view.View startingChild, int dragLengthY) {
    }
    
    /**
     * Called by the touch helper when the drag down was aborted and should be reset.
     */
    public final void onDragDownReset$main() {
    }
    
    /**
     * The user has dragged either above or below the threshold which changes the dimmed state.
     * @param above whether they dragged above it
     */
    public final void onCrossedThreshold$main(boolean above) {
    }
    
    /**
     * Called by the touch helper when the drag down was started
     */
    public final void onDragDownStarted$main(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.row.ExpandableView startingChild) {
    }
    
    public final boolean isFalsingCheckNeeded$main() {
        return false;
    }
    
    /**
     * Is dragging down enabled on a given view
     * @param view The view to check or `null` to check if it's enabled at all
     */
    public final boolean isDragDownEnabledForView$main(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.row.ExpandableView view) {
        return false;
    }
    
    public final boolean isDragDownAnywhereEnabled$main() {
        return false;
    }
    
    public final float getDragDownAmount$main() {
        return 0.0F;
    }
    
    public final void setDragDownAmount$main(float value) {
    }
    
    private final void transitionToShadeAmountCommon(float dragDownAmount) {
    }
    
    private final void setDragDownAmountAnimated(float target, long delay, kotlin.jvm.functions.Function0<kotlin.Unit> endlistener) {
    }
    
    /**
     * Animate appear the drag down amount.
     */
    private final void animateAppear(long delay) {
    }
    
    /**
     * Ask this controller to go to the locked shade, changing the state change and doing
     * an animation, where the qs appears from 0 from the top
     *
     * If secure with redaction: Show bouncer, go to unlocked shade.
     * If secure without redaction or no security: Go to [StatusBarState.SHADE_LOCKED].
     *
     * @param expandView The view to expand after going to the shade
     * @param needsQSAnimation if this needs the quick settings to slide in from the top or if
     *                        that's already handled separately
     */
    public final void goToLockedShade(@org.jetbrains.annotations.Nullable()
    android.view.View expandedView, boolean needsQSAnimation) {
    }
    
    /**
     * Ask this controller to go to the locked shade, changing the state change and doing
     * an animation, where the qs appears from 0 from the top
     *
     * If secure with redaction: Show bouncer, go to unlocked shade.
     * If secure without redaction or no security: Go to [StatusBarState.SHADE_LOCKED].
     *
     * @param expandView The view to expand after going to the shade
     * @param needsQSAnimation if this needs the quick settings to slide in from the top or if
     *                        that's already handled separately
     */
    public final void goToLockedShade(@org.jetbrains.annotations.Nullable()
    android.view.View expandedView) {
    }
    
    /**
     * If secure with redaction: Show bouncer, go to unlocked shade.
     *
     * If secure without redaction or no security: Go to [StatusBarState.SHADE_LOCKED].
     *
     * @param expandView The view to expand after going to the shade.
     * @param animationHandler The handler which performs the go to full shade animation. If null,
     *                        the default handler will do the animation, otherwise the caller is
     *                        responsible for the animation. The input value is a Long for the
     *                        delay for the animation.
     * @param cancelAction The runnable to invoke when the transition is aborted. This happens if
     *                    the user goes to the bouncer and goes back.
     */
    private final void goToLockedShadeInternal(android.view.View expandView, kotlin.jvm.functions.Function1<? super java.lang.Long, kotlin.Unit> animationHandler, java.lang.Runnable cancelAction) {
    }
    
    /**
     * Notify this handler that the keyguard was just dismissed and that a animation to
     * the full shade should happen.
     *
     * @param delay the delay to do the animation with
     * @param previousState which state were we in when we hid the keyguard?
     */
    public final void onHideKeyguard(long delay, int previousState) {
    }
    
    /**
     * Perform the default appear animation when going to the full shade. This is called when
     * not triggered by gestures, e.g. when clicking on the shelf or expand button.
     */
    private final void performDefaultGoToFullShadeAnimation(long delay) {
    }
    
    /**
     * Set the height how tall notifications are pulsing. This is only set whenever we are expanding
     * from a pulse and determines how much the notifications are expanded.
     */
    public final void setPulseHeight(float height, boolean animate) {
    }
    
    /**
     * Finish the pulse animation when the touch interaction finishes
     * @param cancelled was the interaction cancelled and this is a reset?
     */
    public final void finishPulseAnimation(boolean cancelled) {
    }
    
    /**
     * Notify this class that a pulse expansion is starting
     */
    public final void onPulseExpansionStarted() {
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    @javax.inject.Inject()
    public LockscreenShadeTransitionController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.SysuiStatusBarStateController statusBarStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.LSShadeTransitionLogger logger, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.KeyguardBypassController keyguardBypassController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationLockscreenUserManager lockScreenUserManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.classifier.FalsingCollector falsingCollector, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.stack.AmbientState ambientState, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaHierarchyManager mediaHierarchyManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.ScrimController scrimController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationShadeDepthController depthController, @org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.keyguard.WakefulnessLifecycle wakefulnessLifecycle, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.ConfigurationController configurationController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.FalsingManager falsingManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager) {
        super();
    }
}