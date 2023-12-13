package com.android.systemui.util.wrapper;

import com.android.systemui.dagger.SysUISingleton;
import dagger.Binds;
import dagger.Module;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\'\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\'"}, d2 = {"Lcom/android/systemui/util/wrapper/UtilWrapperModule;", "", "()V", "bindRotationPolicyWrapper", "Lcom/android/systemui/util/wrapper/RotationPolicyWrapper;", "impl", "Lcom/android/systemui/util/wrapper/RotationPolicyWrapperImpl;"})
@dagger.Module()
public abstract class UtilWrapperModule {
    
    @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.SysUISingleton()
    @dagger.Binds()
    public abstract com.android.systemui.util.wrapper.RotationPolicyWrapper bindRotationPolicyWrapper(@org.jetbrains.annotations.NotNull()
    com.android.systemui.util.wrapper.RotationPolicyWrapperImpl impl);
    
    public UtilWrapperModule() {
        super();
    }
}