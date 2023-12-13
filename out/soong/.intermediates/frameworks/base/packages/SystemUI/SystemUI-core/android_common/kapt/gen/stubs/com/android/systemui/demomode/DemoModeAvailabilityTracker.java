package com.android.systemui.demomode;

import android.content.Context;
import android.database.ContentObserver;
import android.os.Handler;
import android.os.Looper;
import android.provider.Settings;

/**
 * Class to track the availability of [DemoMode]. Use this class to track the availability and
 * on/off state for DemoMode
 *
 * This class works by wrapping a content observer for the relevant keys related to DemoMode
 * availability and current on/off state, and triggering callbacks.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\t\n\u0002\u0010\u0002\n\u0002\b\u0004\b&\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\b\u0010\u0011\u001a\u00020\nH\u0002J\b\u0010\u0012\u001a\u00020\nH\u0002J\b\u0010\u0013\u001a\u00020\u0014H&J\b\u0010\u0015\u001a\u00020\u0014H&J\b\u0010\u0016\u001a\u00020\u0014H&J\u0006\u0010\u0017\u001a\u00020\u0014J\u0006\u0010\u0018\u001a\u00020\u0014R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\bR\u001a\u0010\t\u001a\u00020\nX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\t\u0010\u000b\"\u0004\b\f\u0010\rR\u001a\u0010\u000e\u001a\u00020\nX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000e\u0010\u000b\"\u0004\b\u000f\u0010\rR\u000e\u0010\u0010\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/demomode/DemoModeAvailabilityTracker;", "", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "allowedObserver", "Landroid/database/ContentObserver;", "getContext", "()Landroid/content/Context;", "isDemoModeAvailable", "", "()Z", "setDemoModeAvailable", "(Z)V", "isInDemoMode", "setInDemoMode", "onObserver", "checkIsDemoModeAllowed", "checkIsDemoModeOn", "onDemoModeAvailabilityChanged", "", "onDemoModeFinished", "onDemoModeStarted", "startTracking", "stopTracking"})
public abstract class DemoModeAvailabilityTracker {
    private boolean isInDemoMode = false;
    private boolean isDemoModeAvailable = false;
    private final android.database.ContentObserver allowedObserver = null;
    private final android.database.ContentObserver onObserver = null;
    @org.jetbrains.annotations.NotNull()
    private final android.content.Context context = null;
    
    public final boolean isInDemoMode() {
        return false;
    }
    
    public final void setInDemoMode(boolean p0) {
    }
    
    public final boolean isDemoModeAvailable() {
        return false;
    }
    
    public final void setDemoModeAvailable(boolean p0) {
    }
    
    public final void startTracking() {
    }
    
    public final void stopTracking() {
    }
    
    public abstract void onDemoModeAvailabilityChanged();
    
    public abstract void onDemoModeStarted();
    
    public abstract void onDemoModeFinished();
    
    private final boolean checkIsDemoModeAllowed() {
        return false;
    }
    
    private final boolean checkIsDemoModeOn() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.Context getContext() {
        return null;
    }
    
    public DemoModeAvailabilityTracker(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
}