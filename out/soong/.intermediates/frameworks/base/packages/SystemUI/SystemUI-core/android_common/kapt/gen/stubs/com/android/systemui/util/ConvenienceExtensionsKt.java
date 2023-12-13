package com.android.systemui.util;

import android.util.IndentingPrintWriter;
import android.view.ViewGroup;
import java.io.PrintWriter;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000.\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\u001a)\u0010\u0007\u001a\u00020\b*\u00020\t2\u0017\u0010\n\u001a\u0013\u0012\u0004\u0012\u00020\t\u0012\u0004\u0012\u00020\b0\u000b\u00a2\u0006\u0002\b\fH\u0086\b\u00f8\u0001\u0000\u001a0\u0010\r\u001a\b\u0012\u0004\u0012\u0002H\u000e0\u0001\"\u0004\b\u0000\u0010\u000e*\b\u0012\u0004\u0012\u0002H\u000e0\u00012\u0012\u0010\u000f\u001a\u000e\u0012\u0004\u0012\u0002H\u000e\u0012\u0004\u0012\u00020\u00100\u000b\"#\u0010\u0000\u001a\u0010\u0012\f\u0012\n \u0003*\u0004\u0018\u00010\u00020\u00020\u0001*\u00020\u00048F\u00a2\u0006\u0006\u001a\u0004\b\u0005\u0010\u0006\u0082\u0002\u0007\n\u0005\b\u009920\u0001"}, d2 = {"children", "Lkotlin/sequences/Sequence;", "Landroid/view/View;", "kotlin.jvm.PlatformType", "Landroid/view/ViewGroup;", "getChildren", "(Landroid/view/ViewGroup;)Lkotlin/sequences/Sequence;", "indentIfPossible", "", "Ljava/io/PrintWriter;", "block", "Lkotlin/Function1;", "Lkotlin/ExtensionFunctionType;", "takeUntil", "T", "pred", ""})
public final class ConvenienceExtensionsKt {
    
    @org.jetbrains.annotations.NotNull()
    public static final kotlin.sequences.Sequence<android.view.View> getChildren(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup $this$children) {
        return null;
    }
    
    /**
     * Inclusive version of [Iterable.takeWhile]
     */
    @org.jetbrains.annotations.NotNull()
    public static final <T extends java.lang.Object>kotlin.sequences.Sequence<T> takeUntil(@org.jetbrains.annotations.NotNull()
    kotlin.sequences.Sequence<? extends T> $this$takeUntil, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super T, java.lang.Boolean> pred) {
        return null;
    }
    
    /**
     * If `this` is an [IndentingPrintWriter], it will process block inside an indentation level.
     *
     * If not, this will just process block.
     */
    public static final void indentIfPossible(@org.jetbrains.annotations.NotNull()
    java.io.PrintWriter $this$indentIfPossible, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super java.io.PrintWriter, kotlin.Unit> block) {
    }
}