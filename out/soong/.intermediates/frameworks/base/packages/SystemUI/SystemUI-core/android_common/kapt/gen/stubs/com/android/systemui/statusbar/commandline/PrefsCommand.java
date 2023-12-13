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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0002\b\u0002\b\u0002\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u001e\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\n2\f\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\r0\fH\u0016J\u0010\u0010\u000e\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nH\u0016J\u0010\u0010\u000f\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nH\u0002R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006"}, d2 = {"Lcom/android/systemui/statusbar/commandline/PrefsCommand;", "Lcom/android/systemui/statusbar/commandline/Command;", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "getContext", "()Landroid/content/Context;", "execute", "", "pw", "Ljava/io/PrintWriter;", "args", "", "", "help", "listPrefs"})
final class PrefsCommand implements com.android.systemui.statusbar.commandline.Command {
    @org.jetbrains.annotations.NotNull()
    private final android.content.Context context = null;
    
    @java.lang.Override()
    public void help(@org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw) {
    }
    
    @java.lang.Override()
    public void execute(@org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> args) {
    }
    
    private final void listPrefs(java.io.PrintWriter pw) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.Context getContext() {
        return null;
    }
    
    public PrefsCommand(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
}