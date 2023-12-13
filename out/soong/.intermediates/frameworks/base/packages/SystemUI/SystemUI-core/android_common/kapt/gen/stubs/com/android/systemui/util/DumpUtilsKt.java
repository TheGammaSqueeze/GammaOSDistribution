package com.android.systemui.util;

import android.util.IndentingPrintWriter;
import android.view.View;
import java.io.PrintWriter;
import java.util.function.Consumer;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000,\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\u001a\u000e\u0010\u0000\u001a\u00020\u00012\u0006\u0010\u0002\u001a\u00020\u0003\u001a\u001e\u0010\u0004\u001a\u00020\u0005*\u00020\u00062\f\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\u00050\bH\u0086\b\u00f8\u0001\u0000\u001a$\u0010\t\u001a\u00020\u0005*\u00020\n2\u0012\u0010\u0007\u001a\u000e\u0012\u0004\u0012\u00020\u0006\u0012\u0004\u0012\u00020\u00050\u000bH\u0086\b\u00f8\u0001\u0000\u001a\u0018\u0010\t\u001a\u00020\u0005*\u00020\n2\f\u0010\f\u001a\b\u0012\u0004\u0012\u00020\u00060\r\u0082\u0002\u0007\n\u0005\b\u009920\u0001"}, d2 = {"visibilityString", "", "visibility", "", "withIncreasedIndent", "", "Landroid/util/IndentingPrintWriter;", "block", "Lkotlin/Function0;", "withIndenting", "Ljava/io/PrintWriter;", "Lkotlin/Function1;", "consumer", "Ljava/util/function/Consumer;"})
public final class DumpUtilsKt {
    
    /**
     * Run some code that will print to an [IndentingPrintWriter] that wraps the given [PrintWriter].
     *
     * If the given [PrintWriter] is an [IndentingPrintWriter], the block will be passed that same
     * instance with [IndentingPrintWriter.increaseIndent] having been called, and calling
     * [IndentingPrintWriter.decreaseIndent] after completion of the block, so the passed [PrintWriter]
     * should not be used before the block completes.
     */
    public static final void withIndenting(@org.jetbrains.annotations.NotNull()
    java.io.PrintWriter $this$withIndenting, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super android.util.IndentingPrintWriter, kotlin.Unit> block) {
    }
    
    /**
     * Run some code that will print to an [IndentingPrintWriter] that wraps the given [PrintWriter].
     *
     * If the given [PrintWriter] is an [IndentingPrintWriter], the block will be passed that same
     * instance with [IndentingPrintWriter.increaseIndent] having been called, and calling
     * [IndentingPrintWriter.decreaseIndent] after completion of the block, so the passed [PrintWriter]
     * should not be used before the block completes.
     */
    public static final void withIndenting(@org.jetbrains.annotations.NotNull()
    java.io.PrintWriter $this$withIndenting, @org.jetbrains.annotations.NotNull()
    java.util.function.Consumer<android.util.IndentingPrintWriter> consumer) {
    }
    
    /**
     * Run some code inside a block, with [IndentingPrintWriter.increaseIndent] having been called on
     * the given argument, and calling [IndentingPrintWriter.decreaseIndent] after completion.
     */
    public static final void withIncreasedIndent(@org.jetbrains.annotations.NotNull()
    android.util.IndentingPrintWriter $this$withIncreasedIndent, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<kotlin.Unit> block) {
    }
    
    /**
     * Return a readable string for the visibility
     */
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String visibilityString(@android.view.View.Visibility()
    int visibility) {
        return null;
    }
}