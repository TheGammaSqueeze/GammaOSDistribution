package com.android.permissioncontroller.permission.service;

import android.os.Looper;
import androidx.lifecycle.LifecycleObserver;
import androidx.lifecycle.LifecycleOwner;
import androidx.lifecycle.LifecycleRegistry;
import java.lang.IllegalStateException;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0010\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nH\u0016J\u0010\u0010\u000b\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nH\u0016R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/service/CheckLifecycleRegistry;", "Landroidx/lifecycle/LifecycleRegistry;", "provider", "Landroidx/lifecycle/LifecycleOwner;", "(Landroidx/lifecycle/LifecycleOwner;)V", "observerLock", "", "addObserver", "", "observer", "Landroidx/lifecycle/LifecycleObserver;", "removeObserver"})
public final class CheckLifecycleRegistry extends androidx.lifecycle.LifecycleRegistry {
    private final java.lang.Object observerLock = null;
    
    @java.lang.Override()
    public void addObserver(@org.jetbrains.annotations.NotNull()
    androidx.lifecycle.LifecycleObserver observer) {
    }
    
    @java.lang.Override()
    public void removeObserver(@org.jetbrains.annotations.NotNull()
    androidx.lifecycle.LifecycleObserver observer) {
    }
    
    public CheckLifecycleRegistry(@org.jetbrains.annotations.NotNull()
    androidx.lifecycle.LifecycleOwner provider) {
        super(null);
    }
}