package com.android.permissioncontroller.permission.data;

import android.os.Binder;
import kotlinx.coroutines.GlobalScope;

/**
 * A LiveData which loads its data in a background AsyncTask. It will cancel current tasks, if new
 * requests come during execution
 *
 * @param isStaticVal Whether or not this LiveData value is expected to change
 * @param alwaysUpdateOnActive Whether or not this LiveData should update upon going active
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\u0007\b&\u0018\u0000*\u0004\b\u0000\u0010\u00012\b\u0012\u0004\u0012\u0002H\u00010\u0002B\u0019\u0012\b\b\u0002\u0010\u0003\u001a\u00020\u0004\u0012\b\b\u0002\u0010\u0005\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0006J\b\u0010\u000b\u001a\u00020\fH\u0002J\u0019\u0010\r\u001a\u00020\f2\u0006\u0010\u000e\u001a\u00020\bH\u00a6@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u000fJ\b\u0010\u0010\u001a\u00020\fH\u0014J\b\u0010\u0011\u001a\u00020\fH\u0014J\b\u0010\u0012\u001a\u00020\fH\u0014J\b\u0010\u0013\u001a\u00020\fH\u0016R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0007\u001a\u0004\u0018\u00010\bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lcom/android/permissioncontroller/permission/data/SmartAsyncMediatorLiveData;", "T", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "isStaticVal", "", "alwaysUpdateOnActive", "(ZZ)V", "currentJob", "Lkotlinx/coroutines/Job;", "jobQueued", "jobRunning", "cancelJobIfRunning", "", "loadDataAndPostValue", "job", "(Lkotlinx/coroutines/Job;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onActive", "onInactive", "onUpdate", "updateAsync"})
public abstract class SmartAsyncMediatorLiveData<T extends java.lang.Object> extends com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<T> {
    private kotlinx.coroutines.Job currentJob;
    private volatile boolean jobQueued = false;
    private volatile boolean jobRunning = false;
    private final boolean alwaysUpdateOnActive = false;
    
    /**
     * The main function which will load data. It should periodically check isCancelled to see if
     * it should stop working. If data is loaded, it should call "postValue".
     */
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.Object loadDataAndPostValue(@org.jetbrains.annotations.NotNull()
    kotlinx.coroutines.Job job, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1);
    
    @java.lang.Override()
    protected void onUpdate() {
    }
    
    public void updateAsync() {
    }
    
    @java.lang.Override()
    protected void onActive() {
    }
    
    @java.lang.Override()
    protected void onInactive() {
    }
    
    private final void cancelJobIfRunning() {
    }
    
    public SmartAsyncMediatorLiveData(boolean isStaticVal, boolean alwaysUpdateOnActive) {
        super(false);
    }
    
    public SmartAsyncMediatorLiveData() {
        super(false);
    }
}