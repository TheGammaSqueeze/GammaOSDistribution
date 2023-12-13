package com.android.systemui.statusbar.phone;

import com.android.systemui.Dumpable;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.util.concurrency.DelayableExecutor;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import javax.inject.Inject;

/**
 * A class that manages if the status bar (clock + notifications + signal cluster) should be visible
 * or not when showing the bouncer.
 *
 * We want to hide it when:
 * • User swipes up on the keyguard
 * • Locked activity that doesn't show a status bar requests the bouncer.
 *
 * [getShouldHideStatusBarIconsForBouncer] is the main exported method for this class. The other
 * methods set state variables that are used in the calculation or manually trigger an update.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000L\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0007\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\n\b\u0007\u0018\u00002\u00020\u0001B!\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\b\b\u0001\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ-\u0010\u0014\u001a\u00020\u00152\u0006\u0010\u0016\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\u00192\u000e\u0010\u001a\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u001c0\u001bH\u0016\u00a2\u0006\u0002\u0010\u001dJ\u0006\u0010\u001e\u001a\u00020\nJ\u000e\u0010\u001f\u001a\u00020\u00152\u0006\u0010\t\u001a\u00020\nJ\u000e\u0010 \u001a\u00020\u00152\u0006\u0010\f\u001a\u00020\rJ\u000e\u0010!\u001a\u00020\u00152\u0006\u0010\u000f\u001a\u00020\nJ\u000e\u0010\"\u001a\u00020\u00152\u0006\u0010\u0010\u001a\u00020\nJ\u000e\u0010#\u001a\u00020\u00152\u0006\u0010\u0011\u001a\u00020\nJ\u000e\u0010$\u001a\u00020\u00152\u0006\u0010\u0012\u001a\u00020\nJ\u000e\u0010%\u001a\u00020\u00152\u0006\u0010&\u001a\u00020\nR\u000e\u0010\t\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/phone/StatusBarHideIconsForBouncerManager;", "Lcom/android/systemui/Dumpable;", "commandQueue", "Lcom/android/systemui/statusbar/CommandQueue;", "mainExecutor", "Lcom/android/systemui/util/concurrency/DelayableExecutor;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "(Lcom/android/systemui/statusbar/CommandQueue;Lcom/android/systemui/util/concurrency/DelayableExecutor;Lcom/android/systemui/dump/DumpManager;)V", "bouncerShowing", "", "bouncerWasShowingWhenHidden", "displayId", "", "hideIconsForBouncer", "isOccluded", "panelExpanded", "statusBarWindowHidden", "topAppHidesStatusBar", "wereIconsJustHidden", "dump", "", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "getShouldHideStatusBarIconsForBouncer", "setBouncerShowingAndTriggerUpdate", "setDisplayId", "setIsOccludedAndTriggerUpdate", "setPanelExpandedAndTriggerUpdate", "setStatusBarWindowHidden", "setTopAppHidesStatusBarAndTriggerUpdate", "updateHideIconsForBouncer", "animate"})
@com.android.systemui.dagger.SysUISingleton()
public final class StatusBarHideIconsForBouncerManager implements com.android.systemui.Dumpable {
    private boolean panelExpanded = false;
    private boolean isOccluded = false;
    private boolean bouncerShowing = false;
    private boolean topAppHidesStatusBar = false;
    private boolean statusBarWindowHidden = false;
    private int displayId = 0;
    private boolean hideIconsForBouncer = false;
    private boolean bouncerWasShowingWhenHidden = false;
    private boolean wereIconsJustHidden = false;
    private final com.android.systemui.statusbar.CommandQueue commandQueue = null;
    private final com.android.systemui.util.concurrency.DelayableExecutor mainExecutor = null;
    
    /**
     * Returns true if the status bar icons should be hidden in the bouncer.
     */
    public final boolean getShouldHideStatusBarIconsForBouncer() {
        return false;
    }
    
    public final void setStatusBarWindowHidden(boolean statusBarWindowHidden) {
    }
    
    public final void setDisplayId(int displayId) {
    }
    
    public final void setPanelExpandedAndTriggerUpdate(boolean panelExpanded) {
    }
    
    public final void setIsOccludedAndTriggerUpdate(boolean isOccluded) {
    }
    
    public final void setBouncerShowingAndTriggerUpdate(boolean bouncerShowing) {
    }
    
    public final void setTopAppHidesStatusBarAndTriggerUpdate(boolean topAppHidesStatusBar) {
    }
    
    /**
     * Updates whether the status bar icons should be hidden in the bouncer. May trigger
     * [commandQueue.recomputeDisableFlags] if the icon visibility status changes.
     */
    public final void updateHideIconsForBouncer(boolean animate) {
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    @javax.inject.Inject()
    public StatusBarHideIconsForBouncerManager(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.CommandQueue commandQueue, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    com.android.systemui.util.concurrency.DelayableExecutor mainExecutor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager) {
        super();
    }
}