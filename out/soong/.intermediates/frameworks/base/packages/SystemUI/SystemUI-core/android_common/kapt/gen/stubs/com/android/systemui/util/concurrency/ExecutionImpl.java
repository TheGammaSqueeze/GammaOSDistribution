package com.android.systemui.util.concurrency;

import android.os.Looper;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001e\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000b\u0018\u00002\u00020\u0001B\u0007\b\u0007\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u0006\u001a\u00020\u0007H\u0016J\b\u0010\b\u001a\u00020\tH\u0016R\u0016\u0010\u0003\u001a\n \u0005*\u0004\u0018\u00010\u00040\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/util/concurrency/ExecutionImpl;", "Lcom/android/systemui/util/concurrency/Execution;", "()V", "mainLooper", "Landroid/os/Looper;", "kotlin.jvm.PlatformType", "assertIsMainThread", "", "isMainThread", ""})
public final class ExecutionImpl implements com.android.systemui.util.concurrency.Execution {
    private final android.os.Looper mainLooper = null;
    
    @java.lang.Override()
    public void assertIsMainThread() {
    }
    
    @java.lang.Override()
    public boolean isMainThread() {
        return false;
    }
    
    @javax.inject.Inject()
    public ExecutionImpl() {
        super();
    }
}