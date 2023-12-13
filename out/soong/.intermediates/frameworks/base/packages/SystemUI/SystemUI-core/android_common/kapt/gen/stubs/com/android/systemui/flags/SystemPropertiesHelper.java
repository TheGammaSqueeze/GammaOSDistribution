package com.android.systemui.flags;

import android.os.SystemProperties;
import com.android.systemui.dagger.SysUISingleton;
import javax.inject.Inject;

/**
 * Proxy to make {@link SystemProperties} easily testable.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\b\u0017\u0018\u00002\u00020\u0001B\u0007\b\u0007\u00a2\u0006\u0002\u0010\u0002J\u000e\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0004J\u0016\u0010\u0006\u001a\u00020\u00072\u0006\u0010\u0005\u001a\u00020\u00042\u0006\u0010\b\u001a\u00020\u0007J\u0016\u0010\t\u001a\u00020\n2\u0006\u0010\u0005\u001a\u00020\u00042\u0006\u0010\u000b\u001a\u00020\fJ\u0016\u0010\t\u001a\u00020\n2\u0006\u0010\u0005\u001a\u00020\u00042\u0006\u0010\u000b\u001a\u00020\u0004"}, d2 = {"Lcom/android/systemui/flags/SystemPropertiesHelper;", "", "()V", "get", "", "name", "getBoolean", "", "default", "set", "", "value", ""})
@com.android.systemui.dagger.SysUISingleton()
public class SystemPropertiesHelper {
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String get(@org.jetbrains.annotations.NotNull()
    java.lang.String name) {
        return null;
    }
    
    public final boolean getBoolean(@org.jetbrains.annotations.NotNull()
    java.lang.String name, boolean p1_772401952) {
        return false;
    }
    
    public final void set(@org.jetbrains.annotations.NotNull()
    java.lang.String name, @org.jetbrains.annotations.NotNull()
    java.lang.String value) {
    }
    
    public final void set(@org.jetbrains.annotations.NotNull()
    java.lang.String name, int value) {
    }
    
    @javax.inject.Inject()
    public SystemPropertiesHelper() {
        super();
    }
}