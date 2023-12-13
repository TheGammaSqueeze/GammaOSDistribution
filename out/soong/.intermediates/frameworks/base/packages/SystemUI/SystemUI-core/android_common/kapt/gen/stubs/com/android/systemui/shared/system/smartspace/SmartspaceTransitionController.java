package com.android.systemui.shared.system.smartspace;

import android.graphics.Rect;
import android.view.View;
import com.android.systemui.shared.system.ActivityManagerWrapper;
import com.android.systemui.shared.system.QuickStepContract;

/**
 * Controller that keeps track of SmartSpace instances in remote processes (such as Launcher),
 * allowing System UI to query or update their state during shared-element transitions.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000N\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0002\b\u0002\u0018\u0000 $2\u00020\u0001:\u0001$B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0006\u0010\u001a\u001a\u00020\u001bJ\u0006\u0010\u001c\u001a\u00020\u001dJ\u0006\u0010\u001e\u001a\u00020\u001fJ\u000e\u0010 \u001a\u00020\u001f2\u0006\u0010!\u001a\u00020\"J\b\u0010#\u001a\u0004\u0018\u00010\u0012R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001c\u0010\u0005\u001a\u0004\u0018\u00010\u0006X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0007\u0010\b\"\u0004\b\t\u0010\nR\u001c\u0010\u000b\u001a\u0004\u0018\u00010\fX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\r\u0010\u000e\"\u0004\b\u000f\u0010\u0010R\u001c\u0010\u0011\u001a\u0004\u0018\u00010\u0012X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0013\u0010\u0014\"\u0004\b\u0015\u0010\u0016R\u000e\u0010\u0017\u001a\u00020\u0018X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0019\u001a\u00020\u0018X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/shared/system/smartspace/SmartspaceTransitionController;", "", "()V", "ISmartspaceTransitionController", "Lcom/android/systemui/shared/system/smartspace/ISmartspaceTransitionController$Stub;", "launcherSmartspace", "Lcom/android/systemui/shared/system/smartspace/ISmartspaceCallback;", "getLauncherSmartspace", "()Lcom/android/systemui/shared/system/smartspace/ISmartspaceCallback;", "setLauncherSmartspace", "(Lcom/android/systemui/shared/system/smartspace/ISmartspaceCallback;)V", "lockscreenSmartspace", "Landroid/view/View;", "getLockscreenSmartspace", "()Landroid/view/View;", "setLockscreenSmartspace", "(Landroid/view/View;)V", "mLauncherSmartspaceState", "Lcom/android/systemui/shared/system/smartspace/SmartspaceState;", "getMLauncherSmartspaceState", "()Lcom/android/systemui/shared/system/smartspace/SmartspaceState;", "setMLauncherSmartspaceState", "(Lcom/android/systemui/shared/system/smartspace/SmartspaceState;)V", "smartspaceDestinationBounds", "Landroid/graphics/Rect;", "smartspaceOriginBounds", "createExternalInterface", "Lcom/android/systemui/shared/system/smartspace/ISmartspaceTransitionController;", "isSmartspaceTransitionPossible", "", "prepareForUnlockTransition", "", "setProgressToDestinationBounds", "progress", "", "updateLauncherSmartSpaceState", "Companion"})
public final class SmartspaceTransitionController {
    
    /**
     * Implementation of [ISmartspaceTransitionController] that we provide to Launcher, allowing it
     * to provide us with a callback to query and update the state of its Smartspace.
     */
    private final com.android.systemui.shared.system.smartspace.ISmartspaceTransitionController.Stub ISmartspaceTransitionController = null;
    
    /**
     * Callback provided by Launcher to allow us to query and update the state of its SmartSpace.
     */
    @org.jetbrains.annotations.Nullable()
    private com.android.systemui.shared.system.smartspace.ISmartspaceCallback launcherSmartspace;
    @org.jetbrains.annotations.Nullable()
    private android.view.View lockscreenSmartspace;
    
    /**
     * Cached state of the Launcher SmartSpace. Retrieving the state is an IPC, so we should avoid
     * unnecessary
     */
    @org.jetbrains.annotations.Nullable()
    private com.android.systemui.shared.system.smartspace.SmartspaceState mLauncherSmartspaceState;
    
    /**
     * The bounds of our SmartSpace when the shared element transition began. We'll interpolate
     * between this and [smartspaceDestinationBounds] as the dismiss amount changes.
     */
    private final android.graphics.Rect smartspaceOriginBounds = null;
    
    /**
     * The bounds of the Launcher's SmartSpace, which is where we are animating our SmartSpace.
     */
    private final android.graphics.Rect smartspaceDestinationBounds = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.shared.system.smartspace.SmartspaceTransitionController.Companion Companion = null;
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.shared.system.smartspace.ISmartspaceCallback getLauncherSmartspace() {
        return null;
    }
    
    public final void setLauncherSmartspace(@org.jetbrains.annotations.Nullable()
    com.android.systemui.shared.system.smartspace.ISmartspaceCallback p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.view.View getLockscreenSmartspace() {
        return null;
    }
    
    public final void setLockscreenSmartspace(@org.jetbrains.annotations.Nullable()
    android.view.View p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.shared.system.smartspace.SmartspaceState getMLauncherSmartspaceState() {
        return null;
    }
    
    public final void setMLauncherSmartspaceState(@org.jetbrains.annotations.Nullable()
    com.android.systemui.shared.system.smartspace.SmartspaceState p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.shared.system.smartspace.ISmartspaceTransitionController createExternalInterface() {
        return null;
    }
    
    /**
     * Updates [mLauncherSmartspaceState] and returns it. This will trigger a binder call, so use the
     * cached [mLauncherSmartspaceState] if possible.
     */
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.shared.system.smartspace.SmartspaceState updateLauncherSmartSpaceState() {
        return null;
    }
    
    public final void prepareForUnlockTransition() {
    }
    
    public final void setProgressToDestinationBounds(float progress) {
    }
    
    /**
     * Whether we're capable of performing the Smartspace shared element transition when we unlock.
     * This is true if:
     *
     * - The Launcher registered a Smartspace with us, it's reporting non-empty bounds on screen.
     * - Launcher is behind the keyguard, and the Smartspace is visible on the currently selected
     *  page.
     */
    public final boolean isSmartspaceTransitionPossible() {
        return false;
    }
    
    public SmartspaceTransitionController() {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000b\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0006\u0010\u0003\u001a\u00020\u0004"}, d2 = {"Lcom/android/systemui/shared/system/smartspace/SmartspaceTransitionController$Companion;", "", "()V", "isLauncherUnderneath", ""})
    public static final class Companion {
        
        public final boolean isLauncherUnderneath() {
            return false;
        }
        
        private Companion() {
            super();
        }
    }
}