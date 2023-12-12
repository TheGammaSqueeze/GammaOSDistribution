package com.android.permissioncontroller.permission.data;

import android.util.Log;
import androidx.annotation.MainThread;
import androidx.lifecycle.LiveData;
import androidx.lifecycle.MediatorLiveData;
import androidx.lifecycle.Observer;
import com.android.permissioncontroller.permission.utils.KotlinUtils;
import kotlinx.coroutines.GlobalScope;

/**
 * A MediatorLiveData which tracks how long it has been inactive, compares new values before setting
 * its value (avoiding unnecessary updates), and can calculate the set difference between a list
 * and a map (used when determining whether or not to add a LiveData as a source).
 *
 * @param isStaticVal Whether or not this LiveData value is expected to change
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000n\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0006\n\u0002\u0010!\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\t\n\u0002\b\u0006\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\n\n\u0002\u0018\u0002\n\u0002\u0010\"\n\u0002\b\u0003\n\u0002\u0010\u001e\n\u0000\n\u0002\u0010%\n\u0000\n\u0002\u0018\u0002\n\u0002\b\n\b&\u0018\u0000 >*\u0004\b\u0000\u0010\u00012\b\u0012\u0004\u0012\u0002H\u00010\u00022\u00020\u0003:\u0001>B\u000f\u0012\b\b\u0002\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J,\u0010\u0016\u001a\u00020\u0017\"\u0004\b\u0001\u0010\u00182\f\u0010\u0019\u001a\b\u0012\u0004\u0012\u0002H\u00180\u001a2\u000e\u0010\u001b\u001a\n\u0012\u0006\b\u0000\u0012\u0002H\u00180\u001cH\u0016J>\u0010\u001d\u001a\u00020\u0017\"\u0004\b\u0001\u0010\u00182\f\u0010\u0019\u001a\b\u0012\u0004\u0012\u0002H\u00180\u001a2\u000e\u0010\u001b\u001a\n\u0012\u0006\b\u0000\u0012\u0002H\u00180\u001c2\u0010\b\u0002\u0010\u001e\u001a\n\u0018\u00010\u001fj\u0004\u0018\u0001` H\u0002J%\u0010!\u001a\u00028\u00002\b\b\u0002\u0010\"\u001a\u00020\u00052\b\b\u0002\u0010#\u001a\u00020\u0005H\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010$J\b\u0010%\u001a\u00020\u0017H\u0014J\b\u0010&\u001a\u00020\u0017H\u0014J\b\u0010\'\u001a\u00020\u0017H%J\u001c\u0010(\u001a\u00020\u0017\"\u0004\b\u0001\u0010\u00182\f\u0010)\u001a\b\u0012\u0004\u0012\u0002H\u00180\u001aH\u0016J\u0080\u0001\u0010*\u001a\u001a\u0012\n\u0012\b\u0012\u0004\u0012\u0002H-0,\u0012\n\u0012\b\u0012\u0004\u0012\u0002H-0,0+\"\u0004\b\u0001\u0010-\"\f\b\u0002\u0010.*\u0006\u0012\u0002\b\u00030\u001a2\f\u0010/\u001a\b\u0012\u0004\u0012\u0002H-002\u0012\u00101\u001a\u000e\u0012\u0004\u0012\u0002H-\u0012\u0004\u0012\u0002H.022\u0012\u00103\u001a\u000e\u0012\u0004\u0012\u0002H-\u0012\u0004\u0012\u0002H.042\u0016\b\u0002\u00105\u001a\u0010\u0012\u0004\u0012\u0002H-\u0012\u0004\u0012\u00020\u0017\u0018\u000104J\u0017\u00106\u001a\u00020\u00172\b\u00107\u001a\u0004\u0018\u00018\u0000H\u0017\u00a2\u0006\u0002\u00108J\b\u00109\u001a\u00020\u0017H\u0007J!\u0010:\u001a\u00020\u00052\b\u0010;\u001a\u0004\u0018\u00018\u00002\b\u0010<\u001a\u0004\u0018\u00018\u0000H\u0014\u00a2\u0006\u0002\u0010=R\u001e\u0010\b\u001a\u00020\u00052\u0006\u0010\u0007\u001a\u00020\u0005@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\tR\u001e\u0010\n\u001a\u00020\u00052\u0006\u0010\u0007\u001a\u00020\u0005@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\tR\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0018\u0010\u000b\u001a\f\u0012\b\u0012\u0006\u0012\u0002\b\u00030\u00000\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082D\u00a2\u0006\u0002\n\u0000R\u001e\u0010\u000f\u001a\u0004\u0018\u00010\u0010X\u0096\u000e\u00a2\u0006\u0010\n\u0002\u0010\u0015\u001a\u0004\b\u0011\u0010\u0012\"\u0004\b\u0013\u0010\u0014\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "T", "Landroidx/lifecycle/MediatorLiveData;", "Lcom/android/permissioncontroller/permission/data/DataRepository$InactiveTimekeeper;", "isStaticVal", "", "(Z)V", "<set-?>", "isInitialized", "()Z", "isStale", "sources", "", "stacktraceExceptionMessage", "", "timeWentInactive", "", "getTimeWentInactive", "()Ljava/lang/Long;", "setTimeWentInactive", "(Ljava/lang/Long;)V", "Ljava/lang/Long;", "addSource", "", "S", "source", "Landroidx/lifecycle/LiveData;", "onChanged", "Landroidx/lifecycle/Observer;", "addSourceWithError", "e", "Ljava/lang/IllegalStateException;", "Lkotlin/IllegalStateException;", "getInitializedValue", "staleOk", "forceUpdate", "(ZZLkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onActive", "onInactive", "onUpdate", "removeSource", "toRemote", "setSourcesToDifference", "Lkotlin/Pair;", "", "K", "V", "desired", "", "have", "", "getLiveDataFun", "Lkotlin/Function1;", "onUpdateFun", "setValue", "newValue", "(Ljava/lang/Object;)V", "update", "valueNotEqual", "valOne", "valTwo", "(Ljava/lang/Object;Ljava/lang/Object;)Z", "Companion"})
public abstract class SmartUpdateMediatorLiveData<T extends java.lang.Object> extends androidx.lifecycle.MediatorLiveData<T> implements com.android.permissioncontroller.permission.data.DataRepository.InactiveTimekeeper {
    
    /**
     * Boolean, whether or not the value of this uiDataLiveData has been explicitly set yet.
     * Differentiates between "null value because liveData is new" and "null value because
     * liveData is invalid"
     */
    private boolean isInitialized = false;
    
    /**
     * Boolean, whether or not this liveData has a stale value or not. Every time the liveData goes
     * inactive, its data becomes stale, until it goes active again, and is explicitly set.
     */
    private boolean isStale = true;
    private final java.util.List<com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<?>> sources = null;
    private final java.lang.String stacktraceExceptionMessage = "Caller of coroutine";
    @org.jetbrains.annotations.Nullable()
    private java.lang.Long timeWentInactive;
    private final boolean isStaticVal = false;
    public static final boolean DEBUG_UPDATES = false;
    private static final java.lang.String LOG_TAG = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData.Companion Companion = null;
    
    public final boolean isInitialized() {
        return false;
    }
    
    public final boolean isStale() {
        return false;
    }
    
    @androidx.annotation.MainThread()
    @java.lang.Override()
    public void setValue(@org.jetbrains.annotations.Nullable()
    T newValue) {
    }
    
    /**
     * Update the value of this LiveData.
     *
     * This usually results in an IPC when active and no action otherwise.
     */
    @androidx.annotation.MainThread()
    public final void update() {
    }
    
    @androidx.annotation.MainThread()
    protected abstract void onUpdate();
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Long getTimeWentInactive() {
        return null;
    }
    
    @java.lang.Override()
    public void setTimeWentInactive(@org.jetbrains.annotations.Nullable()
    java.lang.Long p0) {
    }
    
    /**
     * Some LiveDatas have types, like Drawables which do not have a non-default equals method.
     * Those classes can override this method to change when the value is set upon calling setValue.
     *
     * @param valOne The first T to be compared
     * @param valTwo The second T to be compared
     *
     * @return True if the two values are different, false otherwise
     */
    protected boolean valueNotEqual(@org.jetbrains.annotations.Nullable()
    T valOne, @org.jetbrains.annotations.Nullable()
    T valTwo) {
        return false;
    }
    
    @java.lang.Override()
    public <S extends java.lang.Object>void addSource(@org.jetbrains.annotations.NotNull()
    androidx.lifecycle.LiveData<S> source, @org.jetbrains.annotations.NotNull()
    androidx.lifecycle.Observer<? super S> onChanged) {
    }
    
    private final <S extends java.lang.Object>void addSourceWithError(androidx.lifecycle.LiveData<S> source, androidx.lifecycle.Observer<? super S> onChanged, java.lang.IllegalStateException e) {
    }
    
    @java.lang.Override()
    public <S extends java.lang.Object>void removeSource(@org.jetbrains.annotations.NotNull()
    androidx.lifecycle.LiveData<S> toRemote) {
    }
    
    /**
     * Gets the difference between a list and a map of livedatas, and then will add as a source all
     * livedatas which are in the list, but not the map, and will remove all livedatas which are in
     * the map, but not the list
     *
     * @param desired The list of liveDatas we want in our map, represented by a key
     * @param have The map of livedatas we currently have as sources
     * @param getLiveDataFun A function to turn a key into a liveData
     * @param onUpdateFun An optional function which will update differently based on different
     * LiveDatas. If blank, will simply call update.
     *
     * @return a pair of (all keys added, all keys removed)
     */
    @org.jetbrains.annotations.NotNull()
    public final <K extends java.lang.Object, V extends androidx.lifecycle.LiveData<?>>kotlin.Pair<java.util.Set<K>, java.util.Set<K>> setSourcesToDifference(@org.jetbrains.annotations.NotNull()
    java.util.Collection<? extends K> desired, @org.jetbrains.annotations.NotNull()
    java.util.Map<K, V> have, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super K, ? extends V> getLiveDataFun, @org.jetbrains.annotations.Nullable()
    kotlin.jvm.functions.Function1<? super K, kotlin.Unit> onUpdateFun) {
        return null;
    }
    
    @java.lang.Override()
    protected void onActive() {
    }
    
    @java.lang.Override()
    protected void onInactive() {
    }
    
    /**
     * Get the [initialized][isInitialized] value, suspending until one is available
     *
     * @param staleOk whether [isStale] value is ok to return
     * @param forceUpdate whether to call [update] (usually triggers an IPC)
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Object getInitializedValue(boolean staleOk, boolean forceUpdate, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super T> p2) {
        return null;
    }
    
    public SmartUpdateMediatorLiveData(boolean isStaticVal) {
        super();
    }
    
    public SmartUpdateMediatorLiveData() {
        super();
    }
    
    @org.jetbrains.annotations.Nullable()
    public java.lang.Long getTimeInactive() {
        return null;
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u0019\u0010\u0005\u001a\n \u0007*\u0004\u0018\u00010\u00060\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\t"}, d2 = {"Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData$Companion;", "", "()V", "DEBUG_UPDATES", "", "LOG_TAG", "", "kotlin.jvm.PlatformType", "getLOG_TAG", "()Ljava/lang/String;"})
    public static final class Companion {
        
        public final java.lang.String getLOG_TAG() {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}