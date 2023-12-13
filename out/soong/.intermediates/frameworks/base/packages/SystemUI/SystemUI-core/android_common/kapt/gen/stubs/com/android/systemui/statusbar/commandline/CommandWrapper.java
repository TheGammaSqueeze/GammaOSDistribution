package com.android.systemui.statusbar.commandline;

import android.content.Context;
import com.android.systemui.Prefs;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import java.io.PrintWriter;
import java.lang.IllegalStateException;
import java.util.concurrent.Executor;
import java.util.concurrent.FutureTask;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000.\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\t\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\b\u0082\b\u0018\u00002\u00020\u0001B\u001b\u0012\f\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0007J\u000f\u0010\f\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003H\u00c6\u0003J\t\u0010\r\u001a\u00020\u0006H\u00c6\u0003J#\u0010\u000e\u001a\u00020\u00002\u000e\b\u0002\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u00032\b\b\u0002\u0010\u0005\u001a\u00020\u0006H\u00c6\u0001J\u0013\u0010\u000f\u001a\u00020\u00102\b\u0010\u0011\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0012\u001a\u00020\u0013H\u00d6\u0001J\t\u0010\u0014\u001a\u00020\u0015H\u00d6\u0001R\u0017\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\tR\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000b"}, d2 = {"Lcom/android/systemui/statusbar/commandline/CommandWrapper;", "", "commandFactory", "Lkotlin/Function0;", "Lcom/android/systemui/statusbar/commandline/Command;", "executor", "Ljava/util/concurrent/Executor;", "(Lkotlin/jvm/functions/Function0;Ljava/util/concurrent/Executor;)V", "getCommandFactory", "()Lkotlin/jvm/functions/Function0;", "getExecutor", "()Ljava/util/concurrent/Executor;", "component1", "component2", "copy", "equals", "", "other", "hashCode", "", "toString", ""})
final class CommandWrapper {
    @org.jetbrains.annotations.NotNull()
    private final kotlin.jvm.functions.Function0<com.android.systemui.statusbar.commandline.Command> commandFactory = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.concurrent.Executor executor = null;
    
    @org.jetbrains.annotations.NotNull()
    public final kotlin.jvm.functions.Function0<com.android.systemui.statusbar.commandline.Command> getCommandFactory() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.concurrent.Executor getExecutor() {
        return null;
    }
    
    public CommandWrapper(@org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<? extends com.android.systemui.statusbar.commandline.Command> commandFactory, @org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor executor) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final kotlin.jvm.functions.Function0<com.android.systemui.statusbar.commandline.Command> component1() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.concurrent.Executor component2() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.commandline.CommandWrapper copy(@org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<? extends com.android.systemui.statusbar.commandline.Command> commandFactory, @org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor executor) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}