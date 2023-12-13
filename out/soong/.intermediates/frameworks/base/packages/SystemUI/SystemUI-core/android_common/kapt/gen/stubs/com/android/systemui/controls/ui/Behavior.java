package com.android.systemui.controls.ui;

import java.lang.System;

/**
 * All controls need to respond to changes in state and handle user-generated events.
 * Implementations of this interface provide these different means by adding their own
 * event handlers, and will update the control ui as they see fit.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\"\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\bf\u0018\u00002\u00020\u0001J\u001a\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u0007H&J\u0010\u0010\b\u001a\u00020\u00032\u0006\u0010\t\u001a\u00020\nH&"}, d2 = {"Lcom/android/systemui/controls/ui/Behavior;", "", "bind", "", "cws", "Lcom/android/systemui/controls/ui/ControlWithState;", "colorOffset", "", "initialize", "cvh", "Lcom/android/systemui/controls/ui/ControlViewHolder;"})
public abstract interface Behavior {
    
    /**
     * Only called once per instance
     */
    public abstract void initialize(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh);
    
    /**
     * Will be invoked on every update provided to the Control
     *
     * @param cws ControlWithState, as loaded from favorites and/or the application
     * @param colorOffset An additional flag to control rendering color. See [RenderInfo]
     */
    public abstract void bind(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlWithState cws, int colorOffset);
    
    /**
     * All controls need to respond to changes in state and handle user-generated events.
     * Implementations of this interface provide these different means by adding their own
     * event handlers, and will update the control ui as they see fit.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 3)
    public final class DefaultImpls {
    }
}