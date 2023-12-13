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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0000\bf\u0018\u00002\u00020\u0001J\u001e\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\f\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007H&J\u0010\u0010\t\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&"}, d2 = {"Lcom/android/systemui/statusbar/commandline/Command;", "", "execute", "", "pw", "Ljava/io/PrintWriter;", "args", "", "", "help"})
public abstract interface Command {
    
    public abstract void execute(@org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> args);
    
    public abstract void help(@org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw);
}