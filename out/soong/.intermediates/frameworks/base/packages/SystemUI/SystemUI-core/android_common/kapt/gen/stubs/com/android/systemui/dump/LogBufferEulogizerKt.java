package com.android.systemui.dump;

import android.content.Context;
import android.util.Log;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.log.LogBuffer;
import com.android.systemui.util.io.Files;
import com.android.systemui.util.time.SystemClock;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UncheckedIOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.attribute.BasicFileAttributes;
import java.text.SimpleDateFormat;
import java.util.Locale;
import java.util.concurrent.TimeUnit;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0014\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0010\u000e\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082\u0004\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0004\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0005\u001a\u00020\u0006X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"DATE_FORMAT", "Ljava/text/SimpleDateFormat;", "MAX_AGE_TO_DUMP", "", "MIN_WRITE_GAP", "TAG", ""})
public final class LogBufferEulogizerKt {
    private static final java.lang.String TAG = "BufferEulogizer";
    private static final long MIN_WRITE_GAP = 0L;
    private static final long MAX_AGE_TO_DUMP = 0L;
    private static final java.text.SimpleDateFormat DATE_FORMAT = null;
}