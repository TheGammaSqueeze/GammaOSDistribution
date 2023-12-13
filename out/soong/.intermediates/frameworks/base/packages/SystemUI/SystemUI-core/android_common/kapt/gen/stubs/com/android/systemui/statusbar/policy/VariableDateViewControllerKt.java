package com.android.systemui.statusbar.policy;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.icu.text.DateFormat;
import android.icu.text.DisplayContext;
import android.icu.util.Calendar;
import android.os.Handler;
import android.os.HandlerExecutor;
import android.os.UserHandle;
import android.text.TextUtils;
import android.util.Log;
import androidx.annotation.VisibleForTesting;
import com.android.systemui.Dependency;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.util.ViewController;
import com.android.systemui.util.time.SystemClock;
import java.text.FieldPosition;
import java.text.ParsePosition;
import java.util.Date;
import java.util.Locale;
import javax.inject.Inject;
import javax.inject.Named;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u001c\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\u001a\u0012\u0010\u0006\u001a\u00020\u00032\b\u0010\u0007\u001a\u0004\u0018\u00010\u0005H\u0001\u001a\u001a\u0010\b\u001a\u00020\u00052\b\u0010\t\u001a\u0004\u0018\u00010\n2\u0006\u0010\u000b\u001a\u00020\u0003H\u0001\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0004\u001a\u00020\u0005X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"DEBUG", "", "EMPTY_FORMAT", "Landroid/icu/text/DateFormat;", "TAG", "", "getFormatFromPattern", "pattern", "getTextForFormat", "date", "Ljava/util/Date;", "format"})
public final class VariableDateViewControllerKt {
    private static final android.icu.text.DateFormat EMPTY_FORMAT = null;
    private static final boolean DEBUG = false;
    private static final java.lang.String TAG = "VariableDateViewController";
    
    @org.jetbrains.annotations.NotNull()
    @androidx.annotation.VisibleForTesting()
    public static final java.lang.String getTextForFormat(@org.jetbrains.annotations.Nullable()
    java.util.Date date, @org.jetbrains.annotations.NotNull()
    android.icu.text.DateFormat format) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @androidx.annotation.VisibleForTesting()
    public static final android.icu.text.DateFormat getFormatFromPattern(@org.jetbrains.annotations.Nullable()
    java.lang.String pattern) {
        return null;
    }
}