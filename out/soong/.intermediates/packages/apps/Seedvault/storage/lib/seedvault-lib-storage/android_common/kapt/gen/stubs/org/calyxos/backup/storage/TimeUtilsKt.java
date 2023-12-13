package org.calyxos.backup.storage;

import android.util.Log;
import kotlin.contracts.ExperimentalContracts;
import kotlin.contracts.InvocationKind;
import kotlin.time.Duration;
import kotlin.time.DurationUnit;
import kotlin.time.ExperimentalTime;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u001a\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0010\u000e\n\u0000\u001a/\u0010\u0000\u001a\u00020\u00012\f\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003H\u0080\b\u00f8\u0001\u0000\u00f8\u0001\u0001\u0082\u0002\n\n\b\b\u0001\u0012\u0002\u0010\u0001 \u0001\u00a2\u0006\u0002\u0010\u0005\u001a:\u0010\u0000\u001a\u0002H\u0006\"\u0004\b\u0000\u0010\u00062\u0006\u0010\u0007\u001a\u00020\b2\f\u0010\u0002\u001a\b\u0012\u0004\u0012\u0002H\u00060\u0003H\u0080\b\u00f8\u0001\u0001\u0082\u0002\n\n\b\b\u0001\u0012\u0002\u0010\u0002 \u0001\u00a2\u0006\u0002\u0010\t\u0082\u0002\u000b\n\u0002\b\u0019\n\u0005\b\u009920\u0001"}, d2 = {"measure", "Lkotlin/time/Duration;", "block", "Lkotlin/Function0;", "", "(Lkotlin/jvm/functions/Function0;)D", "T", "text", "", "(Ljava/lang/String;Lkotlin/jvm/functions/Function0;)Ljava/lang/Object;"})
public final class TimeUtilsKt {
    
    /**
     * We don't use [kotlin.time.measureTime] or [kotlin.time.measureTimedValue],
     * because those are not available in the Kotlin version shipped with Android 11.
     * So when building with AOSP 11, things will blow up.
     */
    @kotlin.OptIn(markerClass = {kotlin.contracts.ExperimentalContracts.class, kotlin.time.ExperimentalTime.class})
    public static final double measure(@org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<kotlin.Unit> block) {
        return 0.0;
    }
    
    @kotlin.OptIn(markerClass = {kotlin.contracts.ExperimentalContracts.class, kotlin.time.ExperimentalTime.class})
    public static final <T extends java.lang.Object>T measure(@org.jetbrains.annotations.NotNull()
    java.lang.String text, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<? extends T> block) {
        return null;
    }
}