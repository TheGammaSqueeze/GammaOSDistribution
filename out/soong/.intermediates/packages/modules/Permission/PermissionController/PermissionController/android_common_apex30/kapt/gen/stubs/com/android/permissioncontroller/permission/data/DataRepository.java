package com.android.permissioncontroller.permission.data;

import android.app.ActivityManager;
import android.content.ComponentCallbacks2;
import android.content.res.Configuration;
import androidx.annotation.GuardedBy;
import androidx.annotation.MainThread;
import com.android.permissioncontroller.PermissionControllerApplication;
import java.util.concurrent.TimeUnit;

/**
 * A generalize data repository, which carries a component callback which trims its data in response
 * to memory pressure
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000J\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\t\n\u0002\b\u0003\n\u0002\u0010%\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0000\n\u0002\b\u0007\n\u0002\u0010\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0003\b&\u0018\u0000*\u0004\b\u0000\u0010\u0001*\b\b\u0001\u0010\u0002*\u00020\u00032\u00020\u0004:\u0001%B\u0005\u00a2\u0006\u0002\u0010\u0005J\u0016\u0010\u0015\u001a\u00028\u00012\u0006\u0010\u0016\u001a\u00028\u0000H\u0086\u0002\u00a2\u0006\u0002\u0010\u0017J\u0013\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u0016\u001a\u00028\u0000\u00a2\u0006\u0002\u0010\u001aJ\u0015\u0010\u001b\u001a\u00028\u00012\u0006\u0010\u0016\u001a\u00028\u0000H%\u00a2\u0006\u0002\u0010\u0017J\u0010\u0010\u001c\u001a\u00020\u00192\u0006\u0010\u001d\u001a\u00020\u001eH\u0016J\b\u0010\u001f\u001a\u00020\u0019H\u0016J\u0010\u0010 \u001a\u00020\u00192\u0006\u0010!\u001a\u00020\"H\u0016J\u0010\u0010#\u001a\u00020\u00192\u0006\u0010$\u001a\u00020\u0007H\u0002R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082D\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\"\u0010\n\u001a\u000e\u0012\u0004\u0012\u00028\u0000\u0012\u0004\u0012\u00028\u00010\u000b8\u0004X\u0085\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\rR\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0010\u001a\u00020\u0011X\u0084\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0013R\u000e\u0010\u0014\u001a\u00020\u000fX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/data/DataRepository;", "K", "V", "Lcom/android/permissioncontroller/permission/data/DataRepository$InactiveTimekeeper;", "Landroid/content/ComponentCallbacks2;", "()V", "TIME_THRESHOLD_ALL_NANOS", "", "TIME_THRESHOLD_LAX_NANOS", "TIME_THRESHOLD_TIGHT_NANOS", "data", "", "getData", "()Ljava/util/Map;", "isLowMemoryDevice", "", "lock", "", "getLock", "()Ljava/lang/Object;", "registered", "get", "key", "(Ljava/lang/Object;)Lcom/android/permissioncontroller/permission/data/DataRepository$InactiveTimekeeper;", "invalidateSingle", "", "(Ljava/lang/Object;)V", "newValue", "onConfigurationChanged", "newConfig", "Landroid/content/res/Configuration;", "onLowMemory", "onTrimMemory", "level", "", "trimInactiveData", "threshold", "InactiveTimekeeper"})
public abstract class DataRepository<K extends java.lang.Object, V extends com.android.permissioncontroller.permission.data.DataRepository.InactiveTimekeeper> implements android.content.ComponentCallbacks2 {
    
    /**
     * Deadlines for removal based on memory pressure. Live Data objects which have been inactive
     * for longer than the deadline will be removed.
     */
    private final long TIME_THRESHOLD_LAX_NANOS = 0L;
    private final long TIME_THRESHOLD_TIGHT_NANOS = 0L;
    private final long TIME_THRESHOLD_ALL_NANOS = 0L;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.Object lock = null;
    @org.jetbrains.annotations.NotNull()
    @androidx.annotation.GuardedBy(value = "lock")
    private final java.util.Map<K, V> data = null;
    
    /**
     * Whether or not this data repository has been registered as a component callback yet
     */
    private boolean registered = false;
    
    /**
     * Whether or not this device is a low-RAM device.
     */
    private boolean isLowMemoryDevice;
    
    @org.jetbrains.annotations.NotNull()
    protected final java.lang.Object getLock() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    protected final java.util.Map<K, V> getData() {
        return null;
    }
    
    /**
     * Get a value from this repository, creating it if needed
     *
     * @param key The key associated with the desired Value
     *
     * @return The cached or newly created Value for the given Key
     */
    @org.jetbrains.annotations.NotNull()
    public final V get(K key) {
        return null;
    }
    
    /**
     * Generate a new value type from the given data
     *
     * @param key Information about this value object, used to instantiate it
     *
     * @return The generated Value
     */
    @org.jetbrains.annotations.NotNull()
    @androidx.annotation.MainThread()
    protected abstract V newValue(K key);
    
    /**
     * Remove LiveData objects with no observer based on the severity of the memory pressure. If
     * this is a low RAM device, eject all caches always, including upon the UI closing.
     *
     * @param level The severity of the current memory pressure
     */
    @java.lang.Override()
    public void onTrimMemory(int level) {
    }
    
    @java.lang.Override()
    public void onLowMemory() {
    }
    
    @java.lang.Override()
    public void onConfigurationChanged(@org.jetbrains.annotations.NotNull()
    android.content.res.Configuration newConfig) {
    }
    
    public final void invalidateSingle(K key) {
    }
    
    private final void trimInactiveData(long threshold) {
    }
    
    public DataRepository() {
        super();
    }
    
    /**
     * Interface which describes an object which can track how long it has been inactive, and if
     * it has any observers.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0012\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\t\n\u0002\b\u0006\bf\u0018\u00002\u00020\u0001R\u0016\u0010\u0002\u001a\u0004\u0018\u00010\u00038VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0004\u0010\u0005R\u001a\u0010\u0006\u001a\u0004\u0018\u00010\u0003X\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b\u0007\u0010\u0005\"\u0004\b\b\u0010\t"}, d2 = {"Lcom/android/permissioncontroller/permission/data/DataRepository$InactiveTimekeeper;", "", "timeInactive", "", "getTimeInactive", "()Ljava/lang/Long;", "timeWentInactive", "getTimeWentInactive", "setTimeWentInactive", "(Ljava/lang/Long;)V"})
    public static abstract interface InactiveTimekeeper {
        
        /**
         * Long value representing the time this object went inactive, which is read only on the
         * main thread, so does not cause race conditions.
         */
        @org.jetbrains.annotations.Nullable()
        public abstract java.lang.Long getTimeWentInactive();
        
        /**
         * Long value representing the time this object went inactive, which is read only on the
         * main thread, so does not cause race conditions.
         */
        public abstract void setTimeWentInactive(@org.jetbrains.annotations.Nullable()
        java.lang.Long p0);
        
        @org.jetbrains.annotations.Nullable()
        public abstract java.lang.Long getTimeInactive();
        
        /**
         * Interface which describes an object which can track how long it has been inactive, and if
         * it has any observers.
         */
        @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 3)
        public static final class DefaultImpls {
            
            @org.jetbrains.annotations.Nullable()
            public static java.lang.Long getTimeInactive(@org.jetbrains.annotations.NotNull()
            com.android.permissioncontroller.permission.data.DataRepository.InactiveTimekeeper $this) {
                return null;
            }
        }
    }
}