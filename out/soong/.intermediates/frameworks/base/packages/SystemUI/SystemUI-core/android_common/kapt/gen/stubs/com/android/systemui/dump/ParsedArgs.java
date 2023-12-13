package com.android.systemui.dump;

import android.content.Context;
import android.os.SystemClock;
import android.os.Trace;
import com.android.systemui.R;
import com.android.systemui.log.LogBuffer;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010 \n\u0002\b\n\n\u0002\u0010\u000b\n\u0002\b\n\n\u0002\u0010\b\n\u0002\b\u0004\b\u0002\u0018\u00002\u00020\u0001B!\u0012\f\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u0012\f\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00040\u0006\u00a2\u0006\u0002\u0010\u0007R\u001c\u0010\b\u001a\u0004\u0018\u00010\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\t\u0010\n\"\u0004\b\u000b\u0010\fR\u001c\u0010\r\u001a\u0004\u0018\u00010\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000e\u0010\n\"\u0004\b\u000f\u0010\fR\u001a\u0010\u0010\u001a\u00020\u0011X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0012\u0010\u0013\"\u0004\b\u0014\u0010\u0015R\u0017\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00040\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\u0017R\u0019\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u00a2\u0006\n\n\u0002\u0010\u001a\u001a\u0004\b\u0018\u0010\u0019R\u001a\u0010\u001b\u001a\u00020\u001cX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001d\u0010\u001e\"\u0004\b\u001f\u0010 "}, d2 = {"Lcom/android/systemui/dump/ParsedArgs;", "", "rawArgs", "", "", "nonFlagArgs", "", "([Ljava/lang/String;Ljava/util/List;)V", "command", "getCommand", "()Ljava/lang/String;", "setCommand", "(Ljava/lang/String;)V", "dumpPriority", "getDumpPriority", "setDumpPriority", "listOnly", "", "getListOnly", "()Z", "setListOnly", "(Z)V", "getNonFlagArgs", "()Ljava/util/List;", "getRawArgs", "()[Ljava/lang/String;", "[Ljava/lang/String;", "tailLength", "", "getTailLength", "()I", "setTailLength", "(I)V"})
final class ParsedArgs {
    @org.jetbrains.annotations.Nullable()
    private java.lang.String dumpPriority;
    private int tailLength = 0;
    @org.jetbrains.annotations.Nullable()
    private java.lang.String command;
    private boolean listOnly = false;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String[] rawArgs = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<java.lang.String> nonFlagArgs = null;
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String getDumpPriority() {
        return null;
    }
    
    public final void setDumpPriority(@org.jetbrains.annotations.Nullable()
    java.lang.String p0) {
    }
    
    public final int getTailLength() {
        return 0;
    }
    
    public final void setTailLength(int p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String getCommand() {
        return null;
    }
    
    public final void setCommand(@org.jetbrains.annotations.Nullable()
    java.lang.String p0) {
    }
    
    public final boolean getListOnly() {
        return false;
    }
    
    public final void setListOnly(boolean p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String[] getRawArgs() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<java.lang.String> getNonFlagArgs() {
        return null;
    }
    
    public ParsedArgs(@org.jetbrains.annotations.NotNull()
    java.lang.String[] rawArgs, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> nonFlagArgs) {
        super();
    }
}