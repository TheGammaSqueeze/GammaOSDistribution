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
 * A utility class to enable the downward swipe on the lockscreen to go to the full shade and expand
 * the notification where the drag started.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000f\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\r\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0015\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\t\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u00002\u00020\u0001B%\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\u0010\u0010+\u001a\u00020,2\u0006\u0010-\u001a\u00020\'H\u0002J\u0018\u0010.\u001a\u00020,2\u0006\u0010/\u001a\u00020\f2\u0006\u00100\u001a\u00020\fH\u0002J\u001a\u00101\u001a\u0004\u0018\u00010\'2\u0006\u0010/\u001a\u00020\f2\u0006\u00100\u001a\u00020\fH\u0002J\u0018\u00102\u001a\u00020,2\u0006\u00103\u001a\u00020\f2\u0006\u0010-\u001a\u00020\'H\u0002J\u0010\u00104\u001a\u00020\u000e2\u0006\u00105\u001a\u000206H\u0016J\u0010\u00107\u001a\u00020\u000e2\u0006\u00105\u001a\u000206H\u0016J\b\u00108\u001a\u00020,H\u0002J\u000e\u00109\u001a\u00020,2\u0006\u0010\b\u001a\u00020\tR\u000e\u0010\u000b\u001a\u00020\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u000f\u001a\u00020\u0010X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0011\u0010\u0012\"\u0004\b\u0013\u0010\u0014R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0015\u001a\u00020\u0016X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0017\u0010\u0018\"\u0004\b\u0019\u0010\u001aR\u000e\u0010\u001b\u001a\u00020\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001c\u001a\u00020\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u001d\u001a\u00020\u000e8F\u00a2\u0006\u0006\u001a\u0004\b\u001d\u0010\u001eR\u001e\u0010 \u001a\u00020\u000e2\u0006\u0010\u001f\u001a\u00020\u000e@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b \u0010\u001eR\u0014\u0010!\u001a\u00020\u000e8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b!\u0010\u001eR\u000e\u0010\"\u001a\u00020\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010#\u001a\u00020$X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010%\u001a\u00020\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010&\u001a\u0004\u0018\u00010\'X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010(\u001a\u00020)X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010*\u001a\u00020\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/DragDownHelper;", "Lcom/android/systemui/Gefingerpoken;", "falsingManager", "Lcom/android/systemui/plugins/FalsingManager;", "falsingCollector", "Lcom/android/systemui/classifier/FalsingCollector;", "dragDownCallback", "Lcom/android/systemui/statusbar/LockscreenShadeTransitionController;", "context", "Landroid/content/Context;", "(Lcom/android/systemui/plugins/FalsingManager;Lcom/android/systemui/classifier/FalsingCollector;Lcom/android/systemui/statusbar/LockscreenShadeTransitionController;Landroid/content/Context;)V", "dragDownAmountOnStart", "", "draggedFarEnough", "", "expandCallback", "Lcom/android/systemui/ExpandHelper$Callback;", "getExpandCallback", "()Lcom/android/systemui/ExpandHelper$Callback;", "setExpandCallback", "(Lcom/android/systemui/ExpandHelper$Callback;)V", "host", "Landroid/view/View;", "getHost", "()Landroid/view/View;", "setHost", "(Landroid/view/View;)V", "initialTouchX", "initialTouchY", "isDragDownEnabled", "()Z", "<set-?>", "isDraggingDown", "isFalseTouch", "lastHeight", "minDragDistance", "", "slopMultiplier", "startingChild", "Lcom/android/systemui/statusbar/notification/row/ExpandableView;", "temp2", "", "touchSlop", "cancelChildExpansion", "", "child", "captureStartingChild", "x", "y", "findView", "handleExpansion", "heightDelta", "onInterceptTouchEvent", "event", "Landroid/view/MotionEvent;", "onTouchEvent", "stopDragging", "updateResources"})
public final class DragDownHelper implements com.android.systemui.Gefingerpoken {
    private float dragDownAmountOnStart = 0.0F;
    public com.android.systemui.ExpandHelper.Callback expandCallback;
    public android.view.View host;
    private int minDragDistance = 0;
    private float initialTouchX = 0.0F;
    private float initialTouchY = 0.0F;
    private float touchSlop = 0.0F;
    private float slopMultiplier = 0.0F;
    private final int[] temp2 = null;
    private boolean draggedFarEnough = false;
    private com.android.systemui.statusbar.notification.row.ExpandableView startingChild;
    private float lastHeight = 0.0F;
    private boolean isDraggingDown = false;
    private final com.android.systemui.plugins.FalsingManager falsingManager = null;
    private final com.android.systemui.classifier.FalsingCollector falsingCollector = null;
    private final com.android.systemui.statusbar.LockscreenShadeTransitionController dragDownCallback = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.ExpandHelper.Callback getExpandCallback() {
        return null;
    }
    
    public final void setExpandCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.ExpandHelper.Callback p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.view.View getHost() {
        return null;
    }
    
    public final void setHost(@org.jetbrains.annotations.NotNull()
    android.view.View p0) {
    }
    
    public final boolean isDraggingDown() {
        return false;
    }
    
    private final boolean isFalseTouch() {
        return false;
    }
    
    public final boolean isDragDownEnabled() {
        return false;
    }
    
    public final void updateResources(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
    }
    
    @java.lang.Override()
    public boolean onInterceptTouchEvent(@org.jetbrains.annotations.NotNull()
    android.view.MotionEvent event) {
        return false;
    }
    
    @java.lang.Override()
    public boolean onTouchEvent(@org.jetbrains.annotations.NotNull()
    android.view.MotionEvent event) {
        return false;
    }
    
    private final void captureStartingChild(float x, float y) {
    }
    
    private final void handleExpansion(float heightDelta, com.android.systemui.statusbar.notification.row.ExpandableView child) {
    }
    
    private final void cancelChildExpansion(com.android.systemui.statusbar.notification.row.ExpandableView child) {
    }
    
    private final void stopDragging() {
    }
    
    private final com.android.systemui.statusbar.notification.row.ExpandableView findView(float x, float y) {
        return null;
    }
    
    public DragDownHelper(@org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.FalsingManager falsingManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.classifier.FalsingCollector falsingCollector, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.LockscreenShadeTransitionController dragDownCallback, @org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
}