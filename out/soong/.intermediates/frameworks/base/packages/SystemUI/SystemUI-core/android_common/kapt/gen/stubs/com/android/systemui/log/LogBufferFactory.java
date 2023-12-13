package com.android.systemui.log;

import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dump.DumpManager;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0000\b\u0007\u0018\u00002\u00020\u0001B\u0017\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\"\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\f2\b\b\u0002\u0010\r\u001a\u00020\fH\u0007R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/log/LogBufferFactory;", "", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "logcatEchoTracker", "Lcom/android/systemui/log/LogcatEchoTracker;", "(Lcom/android/systemui/dump/DumpManager;Lcom/android/systemui/log/LogcatEchoTracker;)V", "create", "Lcom/android/systemui/log/LogBuffer;", "name", "", "maxPoolSize", "", "flexSize"})
@com.android.systemui.dagger.SysUISingleton()
public final class LogBufferFactory {
    private final com.android.systemui.dump.DumpManager dumpManager = null;
    private final com.android.systemui.log.LogcatEchoTracker logcatEchoTracker = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.log.LogBuffer create(@org.jetbrains.annotations.NotNull()
    java.lang.String name, int maxPoolSize, int flexSize) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.log.LogBuffer create(@org.jetbrains.annotations.NotNull()
    java.lang.String name, int maxPoolSize) {
        return null;
    }
    
    @javax.inject.Inject()
    public LogBufferFactory(@org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.log.LogcatEchoTracker logcatEchoTracker) {
        super();
    }
}