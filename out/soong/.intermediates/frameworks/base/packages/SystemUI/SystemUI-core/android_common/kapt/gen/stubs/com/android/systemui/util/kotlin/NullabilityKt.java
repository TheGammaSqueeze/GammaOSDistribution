package com.android.systemui.util.kotlin;

import java.util.Optional;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u001a\n\u0002\b\u0003\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\u001aA\u0010\u0000\u001a\u0004\u0018\u0001H\u0001\"\b\b\u0000\u0010\u0002*\u00020\u0003\"\u0004\b\u0001\u0010\u00012\b\u0010\u0004\u001a\u0004\u0018\u0001H\u00022\u0012\u0010\u0005\u001a\u000e\u0012\u0004\u0012\u0002H\u0002\u0012\u0004\u0012\u0002H\u00010\u0006H\u0086\b\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0007\u001a \u0010\b\u001a\u0004\u0018\u0001H\u0002\"\u0004\b\u0000\u0010\u0002*\b\u0012\u0004\u0012\u0002H\u00020\tH\u0086\b\u00a2\u0006\u0002\u0010\n\u0082\u0002\u0007\n\u0005\b\u009920\u0001"}, d2 = {"transform", "R", "T", "", "value", "block", "Lkotlin/Function1;", "(Ljava/lang/Object;Lkotlin/jvm/functions/Function1;)Ljava/lang/Object;", "getOrNull", "Ljava/util/Optional;", "(Ljava/util/Optional;)Ljava/lang/Object;"})
public final class NullabilityKt {
    
    /**
     * If [value] is not null, then returns block(value). Otherwise returns null.
     */
    @org.jetbrains.annotations.Nullable()
    public static final <T extends java.lang.Object, R extends java.lang.Object>R transform(@org.jetbrains.annotations.Nullable()
    T value, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super T, ? extends R> block) {
        return null;
    }
    
    /**
     * Assists type-checking to unpack a Java Optional into T?
     */
    @org.jetbrains.annotations.Nullable()
    public static final <T extends java.lang.Object>T getOrNull(@org.jetbrains.annotations.NotNull()
    java.util.Optional<T> $this$getOrNull) {
        return null;
    }
}