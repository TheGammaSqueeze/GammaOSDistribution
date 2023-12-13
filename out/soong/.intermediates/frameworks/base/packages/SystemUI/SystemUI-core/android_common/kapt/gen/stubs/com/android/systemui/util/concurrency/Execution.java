package com.android.systemui.util.concurrency;

import android.os.Looper;
import javax.inject.Inject;

/**
 * Methods to check or assert that we're on the main thread
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000b\bf\u0018\u00002\u00020\u0001J\b\u0010\u0002\u001a\u00020\u0003H&J\b\u0010\u0004\u001a\u00020\u0005H&"}, d2 = {"Lcom/android/systemui/util/concurrency/Execution;", "", "assertIsMainThread", "", "isMainThread", ""})
public abstract interface Execution {
    
    public abstract void assertIsMainThread();
    
    public abstract boolean isMainThread();
}