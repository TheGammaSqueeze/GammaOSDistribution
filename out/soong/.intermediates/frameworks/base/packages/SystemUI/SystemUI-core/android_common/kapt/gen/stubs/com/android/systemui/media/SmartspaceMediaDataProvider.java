package com.android.systemui.media;

import android.app.smartspace.SmartspaceTarget;
import android.util.Log;
import com.android.systemui.plugins.BcSmartspaceDataPlugin;
import com.android.systemui.plugins.BcSmartspaceDataPlugin.SmartspaceTargetListener;
import javax.inject.Inject;

/**
 * Provides SmartspaceTargets of media types for SystemUI media control.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0004\u0018\u00002\u00020\u0001B\u0007\b\u0007\u00a2\u0006\u0002\u0010\u0002J\u0016\u0010\t\u001a\u00020\n2\f\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\b0\u0007H\u0016J\u0010\u0010\f\u001a\u00020\n2\u0006\u0010\r\u001a\u00020\u0005H\u0016J\u0012\u0010\u000e\u001a\u00020\n2\b\u0010\r\u001a\u0004\u0018\u00010\u0005H\u0016R\u0014\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/SmartspaceMediaDataProvider;", "Lcom/android/systemui/plugins/BcSmartspaceDataPlugin;", "()V", "smartspaceMediaTargetListeners", "", "Lcom/android/systemui/plugins/BcSmartspaceDataPlugin$SmartspaceTargetListener;", "smartspaceMediaTargets", "", "Landroid/app/smartspace/SmartspaceTarget;", "onTargetsAvailable", "", "targets", "registerListener", "smartspaceTargetListener", "unregisterListener"})
public final class SmartspaceMediaDataProvider implements com.android.systemui.plugins.BcSmartspaceDataPlugin {
    private final java.util.List<com.android.systemui.plugins.BcSmartspaceDataPlugin.SmartspaceTargetListener> smartspaceMediaTargetListeners = null;
    private java.util.List<android.app.smartspace.SmartspaceTarget> smartspaceMediaTargets;
    
    @java.lang.Override()
    public void registerListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.BcSmartspaceDataPlugin.SmartspaceTargetListener smartspaceTargetListener) {
    }
    
    @java.lang.Override()
    public void unregisterListener(@org.jetbrains.annotations.Nullable()
    com.android.systemui.plugins.BcSmartspaceDataPlugin.SmartspaceTargetListener smartspaceTargetListener) {
    }
    
    /**
     * Updates Smartspace data and propagates it to any listeners.
     */
    @java.lang.Override()
    public void onTargetsAvailable(@org.jetbrains.annotations.NotNull()
    java.util.List<android.app.smartspace.SmartspaceTarget> targets) {
    }
    
    @javax.inject.Inject()
    public SmartspaceMediaDataProvider() {
        super();
    }
}