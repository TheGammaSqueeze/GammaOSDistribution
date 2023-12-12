package com.android.systemui.log;

import java.lang.System;

/**
 * Recyclable implementation of [LogMessage].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000N\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\b\n\u0002\b\u0004\n\u0002\u0010\u0006\n\u0000\n\u0002\u0010\u000b\n\u0002\bE\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0003\b\u0086\b\u0018\u0000 b2\u00020\u0001:\u0001bB\u009c\u0001\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0017\u0010\b\u001a\u0013\u0012\u0004\u0012\u00020\u0001\u0012\u0004\u0012\u00020\u00050\t\u00a2\u0006\u0002\b\n\u0012\b\u0010\u000b\u001a\u0004\u0018\u00010\u0005\u0012\b\u0010\f\u001a\u0004\u0018\u00010\u0005\u0012\b\u0010\r\u001a\u0004\u0018\u00010\u0005\u0012\u0006\u0010\u000e\u001a\u00020\u000f\u0012\u0006\u0010\u0010\u001a\u00020\u000f\u0012\u0006\u0010\u0011\u001a\u00020\u0007\u0012\u0006\u0010\u0012\u001a\u00020\u0007\u0012\u0006\u0010\u0013\u001a\u00020\u0014\u0012\u0006\u0010\u0015\u001a\u00020\u0016\u0012\u0006\u0010\u0017\u001a\u00020\u0016\u0012\u0006\u0010\u0018\u001a\u00020\u0016\u0012\u0006\u0010\u0019\u001a\u00020\u0016\u00a2\u0006\u0002\u0010\u001aJ\t\u0010I\u001a\u00020\u0003H\u00c6\u0003J\t\u0010J\u001a\u00020\u0007H\u00c6\u0003J\t\u0010K\u001a\u00020\u0007H\u00c6\u0003J\t\u0010L\u001a\u00020\u0014H\u00c6\u0003J\t\u0010M\u001a\u00020\u0016H\u00c6\u0003J\t\u0010N\u001a\u00020\u0016H\u00c6\u0003J\t\u0010O\u001a\u00020\u0016H\u00c6\u0003J\t\u0010P\u001a\u00020\u0016H\u00c6\u0003J\t\u0010Q\u001a\u00020\u0005H\u00c6\u0003J\t\u0010R\u001a\u00020\u0007H\u00c6\u0003J\u001a\u0010S\u001a\u0013\u0012\u0004\u0012\u00020\u0001\u0012\u0004\u0012\u00020\u00050\t\u00a2\u0006\u0002\b\nH\u00c6\u0003J\u000b\u0010T\u001a\u0004\u0018\u00010\u0005H\u00c6\u0003J\u000b\u0010U\u001a\u0004\u0018\u00010\u0005H\u00c6\u0003J\u000b\u0010V\u001a\u0004\u0018\u00010\u0005H\u00c6\u0003J\t\u0010W\u001a\u00020\u000fH\u00c6\u0003J\t\u0010X\u001a\u00020\u000fH\u00c6\u0003J\u00c0\u0001\u0010Y\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00072\u0019\b\u0002\u0010\b\u001a\u0013\u0012\u0004\u0012\u00020\u0001\u0012\u0004\u0012\u00020\u00050\t\u00a2\u0006\u0002\b\n2\n\b\u0002\u0010\u000b\u001a\u0004\u0018\u00010\u00052\n\b\u0002\u0010\f\u001a\u0004\u0018\u00010\u00052\n\b\u0002\u0010\r\u001a\u0004\u0018\u00010\u00052\b\b\u0002\u0010\u000e\u001a\u00020\u000f2\b\b\u0002\u0010\u0010\u001a\u00020\u000f2\b\b\u0002\u0010\u0011\u001a\u00020\u00072\b\b\u0002\u0010\u0012\u001a\u00020\u00072\b\b\u0002\u0010\u0013\u001a\u00020\u00142\b\b\u0002\u0010\u0015\u001a\u00020\u00162\b\b\u0002\u0010\u0017\u001a\u00020\u00162\b\b\u0002\u0010\u0018\u001a\u00020\u00162\b\b\u0002\u0010\u0019\u001a\u00020\u0016H\u00c6\u0001J\u0013\u0010Z\u001a\u00020\u00162\b\u0010[\u001a\u0004\u0018\u00010\\H\u00d6\u0003J\t\u0010]\u001a\u00020\u000fH\u00d6\u0001J7\u0010^\u001a\u00020_2\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0006\u001a\u00020\u00072\u0017\u0010`\u001a\u0013\u0012\u0004\u0012\u00020\u0001\u0012\u0004\u0012\u00020\u00050\t\u00a2\u0006\u0002\b\nJ\t\u0010a\u001a\u00020\u0005H\u00d6\u0001R\u001a\u0010\u0015\u001a\u00020\u0016X\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001b\u0010\u001c\"\u0004\b\u001d\u0010\u001eR\u001a\u0010\u0017\u001a\u00020\u0016X\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001f\u0010\u001c\"\u0004\b \u0010\u001eR\u001a\u0010\u0018\u001a\u00020\u0016X\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b!\u0010\u001c\"\u0004\b\"\u0010\u001eR\u001a\u0010\u0019\u001a\u00020\u0016X\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b#\u0010\u001c\"\u0004\b$\u0010\u001eR\u001a\u0010\u0013\u001a\u00020\u0014X\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b%\u0010&\"\u0004\b\'\u0010(R\u001a\u0010\u000e\u001a\u00020\u000fX\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b)\u0010*\"\u0004\b+\u0010,R\u001a\u0010\u0010\u001a\u00020\u000fX\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b-\u0010*\"\u0004\b.\u0010,R\u001a\u0010\u0002\u001a\u00020\u0003X\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b/\u00100\"\u0004\b1\u00102R\u001a\u0010\u0011\u001a\u00020\u0007X\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b3\u00104\"\u0004\b5\u00106R\u001a\u0010\u0012\u001a\u00020\u0007X\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b7\u00104\"\u0004\b8\u00106R+\u0010\b\u001a\u0013\u0012\u0004\u0012\u00020\u0001\u0012\u0004\u0012\u00020\u00050\t\u00a2\u0006\u0002\b\nX\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b9\u0010:\"\u0004\b;\u0010<R\u001c\u0010\u000b\u001a\u0004\u0018\u00010\u0005X\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b=\u0010>\"\u0004\b?\u0010@R\u001c\u0010\f\u001a\u0004\u0018\u00010\u0005X\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bA\u0010>\"\u0004\bB\u0010@R\u001c\u0010\r\u001a\u0004\u0018\u00010\u0005X\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bC\u0010>\"\u0004\bD\u0010@R\u001a\u0010\u0004\u001a\u00020\u0005X\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bE\u0010>\"\u0004\bF\u0010@R\u001a\u0010\u0006\u001a\u00020\u0007X\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bG\u00104\"\u0004\bH\u00106"}, d2 = {"Lcom/android/systemui/log/LogMessageImpl;", "Lcom/android/systemui/log/LogMessage;", "level", "Lcom/android/systemui/log/LogLevel;", "tag", "", "timestamp", "", "printer", "Lkotlin/Function1;", "Lkotlin/ExtensionFunctionType;", "str1", "str2", "str3", "int1", "", "int2", "long1", "long2", "double1", "", "bool1", "", "bool2", "bool3", "bool4", "(Lcom/android/systemui/log/LogLevel;Ljava/lang/String;JLkotlin/jvm/functions/Function1;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;IIJJDZZZZ)V", "getBool1", "()Z", "setBool1", "(Z)V", "getBool2", "setBool2", "getBool3", "setBool3", "getBool4", "setBool4", "getDouble1", "()D", "setDouble1", "(D)V", "getInt1", "()I", "setInt1", "(I)V", "getInt2", "setInt2", "getLevel", "()Lcom/android/systemui/log/LogLevel;", "setLevel", "(Lcom/android/systemui/log/LogLevel;)V", "getLong1", "()J", "setLong1", "(J)V", "getLong2", "setLong2", "getPrinter", "()Lkotlin/jvm/functions/Function1;", "setPrinter", "(Lkotlin/jvm/functions/Function1;)V", "getStr1", "()Ljava/lang/String;", "setStr1", "(Ljava/lang/String;)V", "getStr2", "setStr2", "getStr3", "setStr3", "getTag", "setTag", "getTimestamp", "setTimestamp", "component1", "component10", "component11", "component12", "component13", "component14", "component15", "component16", "component2", "component3", "component4", "component5", "component6", "component7", "component8", "component9", "copy", "equals", "other", "", "hashCode", "reset", "", "renderer", "toString", "Factory"})
public final class LogMessageImpl implements com.android.systemui.log.LogMessage {
    @org.jetbrains.annotations.NotNull()
    private com.android.systemui.log.LogLevel level;
    @org.jetbrains.annotations.NotNull()
    private java.lang.String tag;
    private long timestamp;
    @org.jetbrains.annotations.NotNull()
    private kotlin.jvm.functions.Function1<? super com.android.systemui.log.LogMessage, java.lang.String> printer;
    @org.jetbrains.annotations.Nullable()
    private java.lang.String str1;
    @org.jetbrains.annotations.Nullable()
    private java.lang.String str2;
    @org.jetbrains.annotations.Nullable()
    private java.lang.String str3;
    private int int1;
    private int int2;
    private long long1;
    private long long2;
    private double double1;
    private boolean bool1;
    private boolean bool2;
    private boolean bool3;
    private boolean bool4;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.log.LogMessageImpl.Factory Factory = null;
    
    public final void reset(@org.jetbrains.annotations.NotNull()
    java.lang.String tag, @org.jetbrains.annotations.NotNull()
    com.android.systemui.log.LogLevel level, long timestamp, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super com.android.systemui.log.LogMessage, java.lang.String> renderer) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.log.LogLevel getLevel() {
        return null;
    }
    
    public void setLevel(@org.jetbrains.annotations.NotNull()
    com.android.systemui.log.LogLevel p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String getTag() {
        return null;
    }
    
    public void setTag(@org.jetbrains.annotations.NotNull()
    java.lang.String p0) {
    }
    
    @java.lang.Override()
    public long getTimestamp() {
        return 0L;
    }
    
    public void setTimestamp(long p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public kotlin.jvm.functions.Function1<com.android.systemui.log.LogMessage, java.lang.String> getPrinter() {
        return null;
    }
    
    public void setPrinter(@org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super com.android.systemui.log.LogMessage, java.lang.String> p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.String getStr1() {
        return null;
    }
    
    @java.lang.Override()
    public void setStr1(@org.jetbrains.annotations.Nullable()
    java.lang.String p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.String getStr2() {
        return null;
    }
    
    @java.lang.Override()
    public void setStr2(@org.jetbrains.annotations.Nullable()
    java.lang.String p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.String getStr3() {
        return null;
    }
    
    @java.lang.Override()
    public void setStr3(@org.jetbrains.annotations.Nullable()
    java.lang.String p0) {
    }
    
    @java.lang.Override()
    public int getInt1() {
        return 0;
    }
    
    @java.lang.Override()
    public void setInt1(int p0) {
    }
    
    @java.lang.Override()
    public int getInt2() {
        return 0;
    }
    
    @java.lang.Override()
    public void setInt2(int p0) {
    }
    
    @java.lang.Override()
    public long getLong1() {
        return 0L;
    }
    
    @java.lang.Override()
    public void setLong1(long p0) {
    }
    
    @java.lang.Override()
    public long getLong2() {
        return 0L;
    }
    
    @java.lang.Override()
    public void setLong2(long p0) {
    }
    
    @java.lang.Override()
    public double getDouble1() {
        return 0.0;
    }
    
    @java.lang.Override()
    public void setDouble1(double p0) {
    }
    
    @java.lang.Override()
    public boolean getBool1() {
        return false;
    }
    
    @java.lang.Override()
    public void setBool1(boolean p0) {
    }
    
    @java.lang.Override()
    public boolean getBool2() {
        return false;
    }
    
    @java.lang.Override()
    public void setBool2(boolean p0) {
    }
    
    @java.lang.Override()
    public boolean getBool3() {
        return false;
    }
    
    @java.lang.Override()
    public void setBool3(boolean p0) {
    }
    
    @java.lang.Override()
    public boolean getBool4() {
        return false;
    }
    
    @java.lang.Override()
    public void setBool4(boolean p0) {
    }
    
    public LogMessageImpl(@org.jetbrains.annotations.NotNull()
    com.android.systemui.log.LogLevel level, @org.jetbrains.annotations.NotNull()
    java.lang.String tag, long timestamp, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super com.android.systemui.log.LogMessage, java.lang.String> printer, @org.jetbrains.annotations.Nullable()
    java.lang.String str1, @org.jetbrains.annotations.Nullable()
    java.lang.String str2, @org.jetbrains.annotations.Nullable()
    java.lang.String str3, int int1, int int2, long long1, long long2, double double1, boolean bool1, boolean bool2, boolean bool3, boolean bool4) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.log.LogLevel component1() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String component2() {
        return null;
    }
    
    public final long component3() {
        return 0L;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final kotlin.jvm.functions.Function1<com.android.systemui.log.LogMessage, java.lang.String> component4() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String component5() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String component6() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String component7() {
        return null;
    }
    
    public final int component8() {
        return 0;
    }
    
    public final int component9() {
        return 0;
    }
    
    public final long component10() {
        return 0L;
    }
    
    public final long component11() {
        return 0L;
    }
    
    public final double component12() {
        return 0.0;
    }
    
    public final boolean component13() {
        return false;
    }
    
    public final boolean component14() {
        return false;
    }
    
    public final boolean component15() {
        return false;
    }
    
    public final boolean component16() {
        return false;
    }
    
    /**
     * Recyclable implementation of [LogMessage].
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.log.LogMessageImpl copy(@org.jetbrains.annotations.NotNull()
    com.android.systemui.log.LogLevel level, @org.jetbrains.annotations.NotNull()
    java.lang.String tag, long timestamp, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super com.android.systemui.log.LogMessage, java.lang.String> printer, @org.jetbrains.annotations.Nullable()
    java.lang.String str1, @org.jetbrains.annotations.Nullable()
    java.lang.String str2, @org.jetbrains.annotations.Nullable()
    java.lang.String str3, int int1, int int2, long long1, long long2, double double1, boolean bool1, boolean bool2, boolean bool3, boolean bool4) {
        return null;
    }
    
    /**
     * Recyclable implementation of [LogMessage].
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    /**
     * Recyclable implementation of [LogMessage].
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * Recyclable implementation of [LogMessage].
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0006\u0010\u0003\u001a\u00020\u0004"}, d2 = {"Lcom/android/systemui/log/LogMessageImpl$Factory;", "", "()V", "create", "Lcom/android/systemui/log/LogMessageImpl;"})
    public static final class Factory {
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.log.LogMessageImpl create() {
            return null;
        }
        
        private Factory() {
            super();
        }
    }
}