package com.android.systemui.dump;

import android.content.Context;
import android.os.SystemClock;
import android.os.Trace;
import com.android.systemui.R;
import com.android.systemui.log.LogBuffer;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u000e\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\u0002\"\u0016\u0010\u0000\u001a\b\u0012\u0004\u0012\u00020\u00020\u0001X\u0082\u0004\u00a2\u0006\u0004\n\u0002\u0010\u0003\"\u0016\u0010\u0004\u001a\b\u0012\u0004\u0012\u00020\u00020\u0001X\u0082\u0004\u00a2\u0006\u0004\n\u0002\u0010\u0003"}, d2 = {"COMMANDS", "", "", "[Ljava/lang/String;", "PRIORITY_OPTIONS"})
public final class DumpHandlerKt {
    private static final java.lang.String[] PRIORITY_OPTIONS = {"CRITICAL", "HIGH", "NORMAL"};
    private static final java.lang.String[] COMMANDS = {"bugreport-critical", "bugreport-normal", "buffers", "dumpables"};
}