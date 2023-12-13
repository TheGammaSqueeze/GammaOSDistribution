package com.android.systemui.keyguard;

import com.android.systemui.unfold.updates.screen.ScreenStatusProvider;
import com.android.systemui.unfold.updates.screen.ScreenStatusProvider.ScreenListener;
import javax.inject.Inject;
import javax.inject.Singleton;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0003\b\u0007\u0018\u00002\u00020\u00012\u00020\u0002B\u000f\b\u0007\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005J\u0010\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\bH\u0016J\b\u0010\f\u001a\u00020\nH\u0016J\u0010\u0010\r\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\bH\u0016R\u0014\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/keyguard/LifecycleScreenStatusProvider;", "Lcom/android/systemui/unfold/updates/screen/ScreenStatusProvider;", "Lcom/android/systemui/keyguard/ScreenLifecycle$Observer;", "screenLifecycle", "Lcom/android/systemui/keyguard/ScreenLifecycle;", "(Lcom/android/systemui/keyguard/ScreenLifecycle;)V", "listeners", "", "Lcom/android/systemui/unfold/updates/screen/ScreenStatusProvider$ScreenListener;", "addCallback", "", "listener", "onScreenTurnedOn", "removeCallback"})
@javax.inject.Singleton()
public final class LifecycleScreenStatusProvider implements com.android.systemui.unfold.updates.screen.ScreenStatusProvider, com.android.systemui.keyguard.ScreenLifecycle.Observer {
    private final java.util.List<com.android.systemui.unfold.updates.screen.ScreenStatusProvider.ScreenListener> listeners = null;
    
    @java.lang.Override()
    public void removeCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.unfold.updates.screen.ScreenStatusProvider.ScreenListener listener) {
    }
    
    @java.lang.Override()
    public void addCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.unfold.updates.screen.ScreenStatusProvider.ScreenListener listener) {
    }
    
    @java.lang.Override()
    public void onScreenTurnedOn() {
    }
    
    @javax.inject.Inject()
    public LifecycleScreenStatusProvider(@org.jetbrains.annotations.NotNull()
    com.android.systemui.keyguard.ScreenLifecycle screenLifecycle) {
        super();
    }
}