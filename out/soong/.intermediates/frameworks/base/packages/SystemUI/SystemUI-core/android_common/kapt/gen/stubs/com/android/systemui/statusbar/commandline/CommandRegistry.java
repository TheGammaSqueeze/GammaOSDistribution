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

/**
 * Registry / dispatcher for incoming shell commands. See [StatusBarManagerService] and
 * [StatusBarShellCommand] for how things are set up. Commands come in here by way of the service
 * like so:
 *
 * `adb shell cmd statusbar <command>`
 *
 * Where `cmd statusbar` send the shell command through to StatusBarManagerService, and
 * <command> is either processed in system server, or sent through to IStatusBar (CommandQueue)
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000R\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010%\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0011\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0007\u0018\u00002\u00020\u0001B\u0019\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\b\b\u0001\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0010\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u0014H\u0002J\b\u0010\u0015\u001a\u00020\u0012H\u0002J!\u0010\u0016\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u00142\f\u0010\u0017\u001a\b\u0012\u0004\u0012\u00020\t0\u0018\u00a2\u0006\u0002\u0010\u0019J\u001c\u0010\u001a\u001a\u00020\u00122\u0006\u0010\u001b\u001a\u00020\t2\f\u0010\u001c\u001a\b\u0012\u0004\u0012\u00020\u001e0\u001dJ$\u0010\u001a\u001a\u00020\u00122\u0006\u0010\u001b\u001a\u00020\t2\f\u0010\u001c\u001a\b\u0012\u0004\u0012\u00020\u001e0\u001d2\u0006\u0010\u001f\u001a\u00020\u0005J\u000e\u0010 \u001a\u00020\u00122\u0006\u0010!\u001a\u00020\tR\u001a\u0010\u0007\u001a\u000e\u0012\u0004\u0012\u00020\t\u0012\u0004\u0012\u00020\n0\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u000e\u0010\r\u001a\u00020\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010"}, d2 = {"Lcom/android/systemui/statusbar/commandline/CommandRegistry;", "", "context", "Landroid/content/Context;", "mainExecutor", "Ljava/util/concurrent/Executor;", "(Landroid/content/Context;Ljava/util/concurrent/Executor;)V", "commandMap", "", "", "Lcom/android/systemui/statusbar/commandline/CommandWrapper;", "getContext", "()Landroid/content/Context;", "initialized", "", "getMainExecutor", "()Ljava/util/concurrent/Executor;", "help", "", "pw", "Ljava/io/PrintWriter;", "initializeCommands", "onShellCommand", "args", "", "(Ljava/io/PrintWriter;[Ljava/lang/String;)V", "registerCommand", "name", "commandFactory", "Lkotlin/Function0;", "Lcom/android/systemui/statusbar/commandline/Command;", "executor", "unregisterCommand", "command"})
@com.android.systemui.dagger.SysUISingleton()
public final class CommandRegistry {
    private final java.util.Map<java.lang.String, com.android.systemui.statusbar.commandline.CommandWrapper> commandMap = null;
    private boolean initialized = false;
    @org.jetbrains.annotations.NotNull()
    private final android.content.Context context = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.concurrent.Executor mainExecutor = null;
    
    /**
     * Register a [Command] for a given name. The name here is the top-level namespace for
     * the registered command. A command could look like this for instance:
     *
     * `adb shell cmd statusbar notifications list`
     *
     * Where `notifications` is the command that signifies which receiver to send the remaining args
     * to.
     *
     * @param command String name of the command to register. Currently does not support aliases
     * @param receiverFactory Creates an instance of the receiver on every command
     * @param executor Pass an executor to offload your `receive` to another thread
     */
    public final synchronized void registerCommand(@org.jetbrains.annotations.NotNull()
    java.lang.String name, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<? extends com.android.systemui.statusbar.commandline.Command> commandFactory, @org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor executor) {
    }
    
    /**
     * Register a [Command] for a given name, to be executed on the main thread.
     */
    public final synchronized void registerCommand(@org.jetbrains.annotations.NotNull()
    java.lang.String name, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<? extends com.android.systemui.statusbar.commandline.Command> commandFactory) {
    }
    
    /**
     * Unregister a receiver
     */
    public final synchronized void unregisterCommand(@org.jetbrains.annotations.NotNull()
    java.lang.String command) {
    }
    
    private final void initializeCommands() {
    }
    
    /**
     * Receive a shell command and dispatch to the appropriate [Command]. Blocks until finished.
     */
    public final void onShellCommand(@org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    private final void help(java.io.PrintWriter pw) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.Context getContext() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.concurrent.Executor getMainExecutor() {
        return null;
    }
    
    @javax.inject.Inject()
    public CommandRegistry(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    java.util.concurrent.Executor mainExecutor) {
        super();
    }
}