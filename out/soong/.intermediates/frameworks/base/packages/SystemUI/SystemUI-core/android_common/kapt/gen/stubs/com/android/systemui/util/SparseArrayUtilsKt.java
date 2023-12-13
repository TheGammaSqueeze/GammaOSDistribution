package com.android.systemui.util;

import android.util.SparseArray;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u00008\n\u0000\n\u0002\u0010$\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\u001a\"\u0010\u0000\u001a\u000e\u0012\u0004\u0012\u00020\u0002\u0012\u0004\u0012\u0002H\u00030\u0001\"\u0004\b\u0000\u0010\u0003*\b\u0012\u0004\u0012\u0002H\u00030\u0004\u001a=\u0010\u0005\u001a\b\u0012\u0004\u0012\u0002H\u00030\u0004\"\u0004\b\u0000\u0010\u0003*\b\u0012\u0004\u0012\u0002H\u00030\u00062\u0014\b\u0004\u0010\u0007\u001a\u000e\u0012\u0004\u0012\u0002H\u0003\u0012\u0004\u0012\u00020\u00020\bH\u0086\b\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\t\u001aa\u0010\n\u001a\b\u0012\u0004\u0012\u0002H\u000b0\u0004\"\u0004\b\u0000\u0010\u0003\"\u0004\b\u0001\u0010\u000b*\u000e\u0012\u0004\u0012\u0002H\u0003\u0012\u0004\u0012\u00020\u00020\f2\u0006\u0010\r\u001a\u0002H\u000b2\b\b\u0002\u0010\u000e\u001a\u00020\u00022\u001a\b\u0004\u0010\u000f\u001a\u0014\u0012\u0004\u0012\u0002H\u000b\u0012\u0004\u0012\u0002H\u0003\u0012\u0004\u0012\u0002H\u000b0\u0010H\u0086\b\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0011\u001a2\u0010\u0012\u001a\b\u0012\u0004\u0012\u0002H\u00030\u0004\"\u0004\b\u0000\u0010\u0003*\u0014\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0002\u0012\u0004\u0012\u0002H\u00030\u00140\u00132\b\b\u0002\u0010\u000e\u001a\u00020\u0002\u0082\u0002\u0007\n\u0005\b\u009920\u0001"}, d2 = {"asMap", "", "", "T", "Landroid/util/SparseArray;", "associateByToSparseArray", "", "keySelector", "Lkotlin/Function1;", "([Ljava/lang/Object;Lkotlin/jvm/functions/Function1;)Landroid/util/SparseArray;", "foldToSparseArray", "R", "Lkotlin/collections/Grouping;", "initial", "size", "operation", "Lkotlin/Function2;", "(Lkotlin/collections/Grouping;Ljava/lang/Object;ILkotlin/jvm/functions/Function2;)Landroid/util/SparseArray;", "toSparseArray", "Lkotlin/sequences/Sequence;", "Lkotlin/Pair;"})
public final class SparseArrayUtilsKt {
    
    /**
     * Transforms a sequence of Key/Value pairs into a SparseArray.
     *
     * See [kotlin.collections.toMap].
     */
    @org.jetbrains.annotations.NotNull()
    public static final <T extends java.lang.Object>android.util.SparseArray<T> toSparseArray(@org.jetbrains.annotations.NotNull()
    kotlin.sequences.Sequence<? extends kotlin.Pair<java.lang.Integer, ? extends T>> $this$toSparseArray, int size) {
        return null;
    }
    
    /**
     * Transforms an [Array] into a [SparseArray], by applying each element to [keySelector] in order to
     * generate the index at which it will be placed. If two elements produce the same index, the latter
     * replaces the former in the final result.
     *
     * See [Array.associateBy].
     */
    @org.jetbrains.annotations.NotNull()
    public static final <T extends java.lang.Object>android.util.SparseArray<T> associateByToSparseArray(@org.jetbrains.annotations.NotNull()
    T[] $this$associateByToSparseArray, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super T, java.lang.Integer> keySelector) {
        return null;
    }
    
    /**
     * Folds a [Grouping] into a [SparseArray]. See [Grouping.fold].
     */
    @org.jetbrains.annotations.NotNull()
    public static final <T extends java.lang.Object, R extends java.lang.Object>android.util.SparseArray<R> foldToSparseArray(@org.jetbrains.annotations.NotNull()
    kotlin.collections.Grouping<T, java.lang.Integer> $this$foldToSparseArray, R initial, int size, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function2<? super R, ? super T, ? extends R> operation) {
        return null;
    }
    
    /**
     * Wraps this [SparseArray] into an immutable [Map], the methods of which forward to this
     * [SparseArray].
     */
    @org.jetbrains.annotations.NotNull()
    public static final <T extends java.lang.Object>java.util.Map<java.lang.Integer, T> asMap(@org.jetbrains.annotations.NotNull()
    android.util.SparseArray<T> $this$asMap) {
        return null;
    }
}