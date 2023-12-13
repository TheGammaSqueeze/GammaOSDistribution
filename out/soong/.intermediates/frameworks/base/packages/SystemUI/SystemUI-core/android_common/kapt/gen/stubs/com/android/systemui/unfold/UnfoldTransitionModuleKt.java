package com.android.systemui.unfold;

import android.content.Context;
import android.hardware.SensorManager;
import android.hardware.devicestate.DeviceStateManager;
import android.os.Handler;
import android.view.IWindowManager;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.keyguard.LifecycleScreenStatusProvider;
import com.android.systemui.unfold.config.UnfoldTransitionConfig;
import com.android.systemui.unfold.util.NaturalRotationUnfoldProgressProvider;
import com.android.systemui.unfold.util.ScopedUnfoldTransitionProgressProvider;
import com.android.wm.shell.unfold.ShellUnfoldProgressProvider;
import dagger.Lazy;
import dagger.Module;
import dagger.Provides;
import java.util.Optional;
import java.util.concurrent.Executor;
import javax.inject.Named;
import javax.inject.Singleton;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0006\n\u0000\n\u0002\u0010\u000e\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000"}, d2 = {"UNFOLD_STATUS_BAR", ""})
public final class UnfoldTransitionModuleKt {
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String UNFOLD_STATUS_BAR = "unfold_status_bar";
}