package com.android.permissioncontroller.permission.data;

import android.app.Application;
import android.app.usage.UsageStats;
import android.app.usage.UsageStatsManager;
import android.os.UserHandle;
import com.android.permissioncontroller.PermissionControllerApplication;
import com.android.permissioncontroller.permission.utils.Utils;

/**
 * A livedata which tracks the usage stats for all packages for all users in a given length of time.
 *
 * @param app The current application
 * @param searchTimeMs The length of time, in milliseconds, that this LiveData will track. The time
 * will start when the liveData is loaded, and extend backwards searchTimeMs milliseconds.
 * @param interval The interval to measure in. Default is monthly.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000<\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010$\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\u0018\u0000 \u00122\u001a\u0012\u0016\u0012\u0014\u0012\u0004\u0012\u00020\u0003\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00050\u00040\u00020\u0001:\u0001\u0012B!\b\u0002\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\b\b\u0002\u0010\n\u001a\u00020\u000b\u00a2\u0006\u0002\u0010\fJ\u0019\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u0010H\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0011R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lcom/android/permissioncontroller/permission/data/UsageStatsLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartAsyncMediatorLiveData;", "", "Landroid/os/UserHandle;", "", "Landroid/app/usage/UsageStats;", "app", "Landroid/app/Application;", "searchTimeMs", "", "interval", "", "(Landroid/app/Application;JI)V", "loadDataAndPostValue", "", "job", "Lkotlinx/coroutines/Job;", "(Lkotlinx/coroutines/Job;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "Companion"})
public final class UsageStatsLiveData extends com.android.permissioncontroller.permission.data.SmartAsyncMediatorLiveData<java.util.Map<android.os.UserHandle, ? extends java.util.List<? extends android.app.usage.UsageStats>>> {
    private final android.app.Application app = null;
    private final long searchTimeMs = 0L;
    private final int interval = 0;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.UsageStatsLiveData.Companion Companion = null;
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object loadDataAndPostValue(@org.jetbrains.annotations.NotNull()
    kotlinx.coroutines.Job job, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1) {
        return null;
    }
    
    private UsageStatsLiveData(android.app.Application app, long searchTimeMs, int interval) {
        super(false, false);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\t\n\u0002\u0010\b\n\u0002\u0018\u0002\n\u0002\b\u0005\b\u0086\u0003\u0018\u00002\u001a\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00040\u0002\u0012\u0004\u0012\u00020\u00050\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0006J\u0011\u0010\u0007\u001a\u00020\u00052\u0006\u0010\b\u001a\u00020\u0003H\u0086\u0002J\u001c\u0010\t\u001a\u00020\u00052\u0012\u0010\n\u001a\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00040\u0002H\u0014"}, d2 = {"Lcom/android/permissioncontroller/permission/data/UsageStatsLiveData$Companion;", "Lcom/android/permissioncontroller/permission/data/DataRepository;", "Lkotlin/Pair;", "", "", "Lcom/android/permissioncontroller/permission/data/UsageStatsLiveData;", "()V", "get", "interval", "newValue", "key"})
    public static final class Companion extends com.android.permissioncontroller.permission.data.DataRepository<kotlin.Pair<? extends java.lang.Long, ? extends java.lang.Integer>, com.android.permissioncontroller.permission.data.UsageStatsLiveData> {
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        protected com.android.permissioncontroller.permission.data.UsageStatsLiveData newValue(@org.jetbrains.annotations.NotNull()
        kotlin.Pair<java.lang.Long, java.lang.Integer> key) {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.data.UsageStatsLiveData get(long interval) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}