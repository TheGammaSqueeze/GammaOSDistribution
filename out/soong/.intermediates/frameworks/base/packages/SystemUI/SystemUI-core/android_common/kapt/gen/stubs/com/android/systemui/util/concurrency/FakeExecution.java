package com.android.systemui.util.concurrency;

import android.os.Looper;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0000\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\b\u0010\t\u001a\u00020\nH\u0016J\b\u0010\u000b\u001a\u00020\u0004H\u0016R\u001a\u0010\u0003\u001a\u00020\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0005\u0010\u0006\"\u0004\b\u0007\u0010\b"}, d2 = {"Lcom/android/systemui/util/concurrency/FakeExecution;", "Lcom/android/systemui/util/concurrency/Execution;", "()V", "simulateMainThread", "", "getSimulateMainThread", "()Z", "setSimulateMainThread", "(Z)V", "assertIsMainThread", "", "isMainThread"})
public final class FakeExecution implements com.android.systemui.util.concurrency.Execution {
    private boolean simulateMainThread = true;
    
    public final boolean getSimulateMainThread() {
        return false;
    }
    
    public final void setSimulateMainThread(boolean p0) {
    }
    
    @java.lang.Override()
    public void assertIsMainThread() {
    }
    
    @java.lang.Override()
    public boolean isMainThread() {
        return false;
    }
    
    public FakeExecution() {
        super();
    }
}