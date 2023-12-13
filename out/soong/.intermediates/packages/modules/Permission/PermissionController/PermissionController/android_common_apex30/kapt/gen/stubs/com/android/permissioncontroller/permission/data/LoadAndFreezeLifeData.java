package com.android.permissioncontroller.permission.data;

import androidx.lifecycle.SavedStateHandle;

/**
 * LiveData that loads wrapped value once. Once the wrapped data becomes non-stale it holds onto the
 * value forever.
 *
 * This even extends over live-cycle events as the data is stored in the {@link SaveStateHandle}.
 * This means that the data has to be writable to {@link SavedStateHandle} though, i.e.
 * Serialzable, Parcelable, list, set, map, or a literal
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0010\u0002\u0018\u0000*\u0004\b\u0000\u0010\u00012\b\u0012\u0004\u0012\u0002H\u00010\u0002B#\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\f\u0010\u0007\u001a\b\u0012\u0004\u0012\u00028\u00000\u0002\u00a2\u0006\u0002\u0010\bJ\b\u0010\t\u001a\u00020\nH\u0014R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0007\u001a\b\u0012\u0004\u0012\u00028\u00000\u0002X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/data/LoadAndFreezeLifeData;", "T", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "state", "Landroidx/lifecycle/SavedStateHandle;", "key", "", "wrapped", "(Landroidx/lifecycle/SavedStateHandle;Ljava/lang/String;Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;)V", "onUpdate", ""})
public final class LoadAndFreezeLifeData<T extends java.lang.Object> extends com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<T> {
    private final androidx.lifecycle.SavedStateHandle state = null;
    private final java.lang.String key = null;
    private final com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<T> wrapped = null;
    
    @java.lang.Override()
    protected void onUpdate() {
    }
    
    public LoadAndFreezeLifeData(@org.jetbrains.annotations.NotNull()
    androidx.lifecycle.SavedStateHandle state, @org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<T> wrapped) {
        super(false);
    }
}