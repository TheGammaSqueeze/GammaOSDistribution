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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000d\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\u0006\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u0001:\u0001-B%\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\u0002\u00a2\u0006\u0002\u0010\nJ\u0010\u0010 \u001a\u00020!2\u0006\u0010\"\u001a\u00020\u0010H\u0002J\u0010\u0010#\u001a\u00020!2\u0006\u0010$\u001a\u00020\u0018H\u0002J\b\u0010%\u001a\u00020!H\u0014J\b\u0010&\u001a\u00020!H\u0014J\u001d\u0010\'\u001a\u0004\u0018\u00010(2\f\u0010)\u001a\b\u0012\u0004\u0012\u00020!0*H\u0002\u00a2\u0006\u0002\u0010+J\b\u0010,\u001a\u00020!H\u0002R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\r\u001a\u0004\u0018\u00010\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001e\u0010\u0011\u001a\u00020\u00102\u0006\u0010\u000f\u001a\u00020\u0010@BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\b\u0012\u0010\u0013R\u000e\u0010\u0014\u001a\u00020\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0016\u001a\u00020\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0017\u001a\u00020\u0018X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0019\u001a\u00020\u00108BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u001a\u0010\u001bR\u000e\u0010\u001c\u001a\u00020\u001dX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u001e\u001a\u00020\u00108BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u001f\u0010\u001bR\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/policy/VariableDateViewController;", "Lcom/android/systemui/util/ViewController;", "Lcom/android/systemui/statusbar/policy/VariableDateView;", "systemClock", "Lcom/android/systemui/util/time/SystemClock;", "broadcastDispatcher", "Lcom/android/systemui/broadcast/BroadcastDispatcher;", "timeTickHandler", "Landroid/os/Handler;", "view", "(Lcom/android/systemui/util/time/SystemClock;Lcom/android/systemui/broadcast/BroadcastDispatcher;Landroid/os/Handler;Lcom/android/systemui/statusbar/policy/VariableDateView;)V", "currentTime", "Ljava/util/Date;", "dateFormat", "Landroid/icu/text/DateFormat;", "value", "", "datePattern", "setDatePattern", "(Ljava/lang/String;)V", "intentReceiver", "Landroid/content/BroadcastReceiver;", "lastText", "lastWidth", "", "longerPattern", "getLongerPattern", "()Ljava/lang/String;", "onMeasureListener", "Lcom/android/systemui/statusbar/policy/VariableDateView$OnMeasureListener;", "shorterPattern", "getShorterPattern", "changePattern", "", "newPattern", "maybeChangeFormat", "availableWidth", "onViewAttached", "onViewDetached", "post", "", "block", "Lkotlin/Function0;", "(Lkotlin/jvm/functions/Function0;)Ljava/lang/Boolean;", "updateClock", "Factory"})
public final class VariableDateViewController extends com.android.systemui.util.ViewController<com.android.systemui.statusbar.policy.VariableDateView> {
    private android.icu.text.DateFormat dateFormat;
    private java.lang.String datePattern;
    private int lastWidth = java.lang.Integer.MAX_VALUE;
    private java.lang.String lastText = "";
    private java.util.Date currentTime;
    private final android.content.BroadcastReceiver intentReceiver = null;
    private final com.android.systemui.statusbar.policy.VariableDateView.OnMeasureListener onMeasureListener = null;
    private final com.android.systemui.util.time.SystemClock systemClock = null;
    private final com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher = null;
    private final android.os.Handler timeTickHandler = null;
    
    private final void setDatePattern(java.lang.String value) {
    }
    
    private final java.lang.String getLongerPattern() {
        return null;
    }
    
    private final java.lang.String getShorterPattern() {
        return null;
    }
    
    private final java.lang.Boolean post(kotlin.jvm.functions.Function0<kotlin.Unit> block) {
        return null;
    }
    
    @java.lang.Override()
    protected void onViewAttached() {
    }
    
    @java.lang.Override()
    protected void onViewDetached() {
    }
    
    private final void updateClock() {
    }
    
    private final void maybeChangeFormat(int availableWidth) {
    }
    
    private final void changePattern(java.lang.String newPattern) {
    }
    
    public VariableDateViewController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.util.time.SystemClock systemClock, @org.jetbrains.annotations.NotNull()
    com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher, @org.jetbrains.annotations.NotNull()
    android.os.Handler timeTickHandler, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.VariableDateView view) {
        super(null);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B!\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\b\b\u0001\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\u000e\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\fR\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/policy/VariableDateViewController$Factory;", "", "systemClock", "Lcom/android/systemui/util/time/SystemClock;", "broadcastDispatcher", "Lcom/android/systemui/broadcast/BroadcastDispatcher;", "handler", "Landroid/os/Handler;", "(Lcom/android/systemui/util/time/SystemClock;Lcom/android/systemui/broadcast/BroadcastDispatcher;Landroid/os/Handler;)V", "create", "Lcom/android/systemui/statusbar/policy/VariableDateViewController;", "view", "Lcom/android/systemui/statusbar/policy/VariableDateView;"})
    public static final class Factory {
        private final com.android.systemui.util.time.SystemClock systemClock = null;
        private final com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher = null;
        private final android.os.Handler handler = null;
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.statusbar.policy.VariableDateViewController create(@org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.policy.VariableDateView view) {
            return null;
        }
        
        @javax.inject.Inject()
        public Factory(@org.jetbrains.annotations.NotNull()
        com.android.systemui.util.time.SystemClock systemClock, @org.jetbrains.annotations.NotNull()
        com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher, @org.jetbrains.annotations.NotNull()
        @javax.inject.Named(value = "time_tick_handler")
        android.os.Handler handler) {
            super();
        }
    }
}