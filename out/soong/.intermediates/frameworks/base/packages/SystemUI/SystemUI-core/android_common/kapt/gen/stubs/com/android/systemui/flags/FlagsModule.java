package com.android.systemui.flags;

import android.content.Context;
import android.os.Handler;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.util.settings.SettingsUtilModule;
import dagger.Module;
import dagger.Provides;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u00c7\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u001a\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u00062\b\b\u0001\u0010\u0007\u001a\u00020\bH\u0007"}, d2 = {"Lcom/android/systemui/flags/FlagsModule;", "", "()V", "provideFlagManager", "Lcom/android/systemui/flags/FlagManager;", "context", "Landroid/content/Context;", "handler", "Landroid/os/Handler;"})
@dagger.Module(includes = {com.android.systemui.util.settings.SettingsUtilModule.class})
public final class FlagsModule {
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.flags.FlagsModule INSTANCE = null;
    
    @org.jetbrains.annotations.NotNull()
    @dagger.Provides()
    public static final com.android.systemui.flags.FlagManager provideFlagManager(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    android.os.Handler handler) {
        return null;
    }
    
    private FlagsModule() {
        super();
    }
}