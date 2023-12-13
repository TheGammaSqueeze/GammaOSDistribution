package com.android.systemui.qs;

import com.android.systemui.qs.dagger.QSScope;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0002\b\u0006\n\u0002\u0010\u0002\b\u0007\u0018\u00002\u00020\u0001B\u001f\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\b\u0010\u0010\u001a\u00020\u0011H\u0002R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R$\u0010\u000b\u001a\u00020\n2\u0006\u0010\t\u001a\u00020\n@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\f\u0010\r\"\u0004\b\u000e\u0010\u000f"}, d2 = {"Lcom/android/systemui/qs/QSSquishinessController;", "", "qsAnimator", "Lcom/android/systemui/qs/QSAnimator;", "qsPanelController", "Lcom/android/systemui/qs/QSPanelController;", "quickQSPanelController", "Lcom/android/systemui/qs/QuickQSPanelController;", "(Lcom/android/systemui/qs/QSAnimator;Lcom/android/systemui/qs/QSPanelController;Lcom/android/systemui/qs/QuickQSPanelController;)V", "value", "", "squishiness", "getSquishiness", "()F", "setSquishiness", "(F)V", "updateSquishiness", ""})
@com.android.systemui.qs.dagger.QSScope()
public final class QSSquishinessController {
    
    /**
     * Fraction from 0 to 1, where 0 is collapsed and 1 expanded.
     */
    private float squishiness = 1.0F;
    private final com.android.systemui.qs.QSAnimator qsAnimator = null;
    private final com.android.systemui.qs.QSPanelController qsPanelController = null;
    private final com.android.systemui.qs.QuickQSPanelController quickQSPanelController = null;
    
    public final float getSquishiness() {
        return 0.0F;
    }
    
    public final void setSquishiness(float value) {
    }
    
    /**
     * Change the height of all tiles and repositions their siblings.
     */
    private final void updateSquishiness() {
    }
    
    @javax.inject.Inject()
    public QSSquishinessController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.qs.QSAnimator qsAnimator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.qs.QSPanelController qsPanelController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.qs.QuickQSPanelController quickQSPanelController) {
        super();
    }
}