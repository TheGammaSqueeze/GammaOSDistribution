package com.android.systemui.log;

import java.lang.System;

/**
 * Generic data class for storing messages logged to a [LogBuffer]
 *
 * Each LogMessage has a few standard fields ([level], [tag], and [timestamp]). The rest are generic
 * data slots that may or may not be used, depending on the nature of the specific message being
 * logged.
 *
 * When a message is logged, the code doing the logging stores data in one or more of the generic
 * fields ([str1], [int1], etc). When it comes time to dump the message to logcat/bugreport/etc, the
 * [printer] function reads the data stored in the generic fields and converts that to a human-
 * readable string. Thus, for every log type there must be a specialized initializer function that
 * stores data specific to that log type and a specialized printer function that prints that data.
 *
 * See [LogBuffer.log] for more information.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000B\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u000e\n\u0002\u0010\u0006\n\u0002\b\u0005\n\u0002\u0010\b\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\t\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\b\u0011\bf\u0018\u00002\u00020\u0001R\u0018\u0010\u0002\u001a\u00020\u0003X\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b\u0004\u0010\u0005\"\u0004\b\u0006\u0010\u0007R\u0018\u0010\b\u001a\u00020\u0003X\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b\t\u0010\u0005\"\u0004\b\n\u0010\u0007R\u0018\u0010\u000b\u001a\u00020\u0003X\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b\f\u0010\u0005\"\u0004\b\r\u0010\u0007R\u0018\u0010\u000e\u001a\u00020\u0003X\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b\u000f\u0010\u0005\"\u0004\b\u0010\u0010\u0007R\u0018\u0010\u0011\u001a\u00020\u0012X\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b\u0013\u0010\u0014\"\u0004\b\u0015\u0010\u0016R\u0018\u0010\u0017\u001a\u00020\u0018X\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b\u0019\u0010\u001a\"\u0004\b\u001b\u0010\u001cR\u0018\u0010\u001d\u001a\u00020\u0018X\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b\u001e\u0010\u001a\"\u0004\b\u001f\u0010\u001cR\u0012\u0010 \u001a\u00020!X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\"\u0010#R\u0018\u0010$\u001a\u00020%X\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b&\u0010\'\"\u0004\b(\u0010)R\u0018\u0010*\u001a\u00020%X\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b+\u0010\'\"\u0004\b,\u0010)R#\u0010-\u001a\u0013\u0012\u0004\u0012\u00020\u0000\u0012\u0004\u0012\u00020/0.\u00a2\u0006\u0002\b0X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b1\u00102R\u001a\u00103\u001a\u0004\u0018\u00010/X\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b4\u00105\"\u0004\b6\u00107R\u001a\u00108\u001a\u0004\u0018\u00010/X\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b9\u00105\"\u0004\b:\u00107R\u001a\u0010;\u001a\u0004\u0018\u00010/X\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b<\u00105\"\u0004\b=\u00107R\u0012\u0010>\u001a\u00020/X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b?\u00105R\u0012\u0010@\u001a\u00020%X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\bA\u0010\'"}, d2 = {"Lcom/android/systemui/log/LogMessage;", "", "bool1", "", "getBool1", "()Z", "setBool1", "(Z)V", "bool2", "getBool2", "setBool2", "bool3", "getBool3", "setBool3", "bool4", "getBool4", "setBool4", "double1", "", "getDouble1", "()D", "setDouble1", "(D)V", "int1", "", "getInt1", "()I", "setInt1", "(I)V", "int2", "getInt2", "setInt2", "level", "Lcom/android/systemui/log/LogLevel;", "getLevel", "()Lcom/android/systemui/log/LogLevel;", "long1", "", "getLong1", "()J", "setLong1", "(J)V", "long2", "getLong2", "setLong2", "printer", "Lkotlin/Function1;", "", "Lkotlin/ExtensionFunctionType;", "getPrinter", "()Lkotlin/jvm/functions/Function1;", "str1", "getStr1", "()Ljava/lang/String;", "setStr1", "(Ljava/lang/String;)V", "str2", "getStr2", "setStr2", "str3", "getStr3", "setStr3", "tag", "getTag", "timestamp", "getTimestamp"})
public abstract interface LogMessage {
    
    @org.jetbrains.annotations.NotNull()
    public abstract com.android.systemui.log.LogLevel getLevel();
    
    @org.jetbrains.annotations.NotNull()
    public abstract java.lang.String getTag();
    
    public abstract long getTimestamp();
    
    @org.jetbrains.annotations.NotNull()
    public abstract kotlin.jvm.functions.Function1<com.android.systemui.log.LogMessage, java.lang.String> getPrinter();
    
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.String getStr1();
    
    public abstract void setStr1(@org.jetbrains.annotations.Nullable()
    java.lang.String p0);
    
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.String getStr2();
    
    public abstract void setStr2(@org.jetbrains.annotations.Nullable()
    java.lang.String p0);
    
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.String getStr3();
    
    public abstract void setStr3(@org.jetbrains.annotations.Nullable()
    java.lang.String p0);
    
    public abstract int getInt1();
    
    public abstract void setInt1(int p0);
    
    public abstract int getInt2();
    
    public abstract void setInt2(int p0);
    
    public abstract long getLong1();
    
    public abstract void setLong1(long p0);
    
    public abstract long getLong2();
    
    public abstract void setLong2(long p0);
    
    public abstract double getDouble1();
    
    public abstract void setDouble1(double p0);
    
    public abstract boolean getBool1();
    
    public abstract void setBool1(boolean p0);
    
    public abstract boolean getBool2();
    
    public abstract void setBool2(boolean p0);
    
    public abstract boolean getBool3();
    
    public abstract void setBool3(boolean p0);
    
    public abstract boolean getBool4();
    
    public abstract void setBool4(boolean p0);
}