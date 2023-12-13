package com.android.systemui;

import java.lang.System;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001e\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\bf\u0018\u00002\u00020\u0001:\u0001\tJ\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&J\b\u0010\u0006\u001a\u00020\u0003H&J\u0010\u0010\u0007\u001a\u00020\b2\u0006\u0010\u0004\u001a\u00020\u0005H&"}, d2 = {"Lcom/android/systemui/BootCompleteCache;", "", "addListener", "", "listener", "Lcom/android/systemui/BootCompleteCache$BootCompleteListener;", "isBootComplete", "removeListener", "", "BootCompleteListener"})
public abstract interface BootCompleteCache {
    
    public abstract boolean isBootComplete();
    
    public abstract boolean addListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.BootCompleteCache.BootCompleteListener listener);
    
    public abstract void removeListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.BootCompleteCache.BootCompleteListener listener);
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u000e\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\bf\u0018\u00002\u00020\u0001J\b\u0010\u0002\u001a\u00020\u0003H&"}, d2 = {"Lcom/android/systemui/BootCompleteCache$BootCompleteListener;", "", "onBootComplete", ""})
    public static abstract interface BootCompleteListener {
        
        public abstract void onBootComplete();
    }
}