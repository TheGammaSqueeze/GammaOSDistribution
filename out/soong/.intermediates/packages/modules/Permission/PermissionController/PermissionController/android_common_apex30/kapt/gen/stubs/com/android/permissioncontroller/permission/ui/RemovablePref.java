package com.android.permissioncontroller.permission.ui;

import java.lang.System;

/**
 * Preference with a clickable UI component for removal.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/RemovablePref;", "", "setRemoveClickRunnable", "", "runnable", "Ljava/lang/Runnable;"})
public abstract interface RemovablePref {
    
    /**
     * Sets the action to run when the remove UI component is clicked.
     */
    public abstract void setRemoveClickRunnable(@org.jetbrains.annotations.NotNull()
    java.lang.Runnable runnable);
}