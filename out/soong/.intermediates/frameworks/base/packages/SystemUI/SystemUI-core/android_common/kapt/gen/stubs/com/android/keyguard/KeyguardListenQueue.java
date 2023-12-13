package com.android.keyguard;

import androidx.annotation.VisibleForTesting;
import java.io.PrintWriter;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;
import kotlin.collections.ArrayDeque;

/**
 * Queue for verbose logging checks for the listening state.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000@\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B\u000f\u0012\b\b\u0002\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u000e\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\fJ\u001a\u0010\u0014\u001a\u00020\u00122\u0006\u0010\u0015\u001a\u00020\u00162\b\b\u0002\u0010\u0017\u001a\u00020\u0018H\u0007R\u0014\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\b\u001a\b\u0012\u0004\u0012\u00020\t0\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0017\u0010\n\u001a\b\u0012\u0004\u0012\u00020\f0\u000b8G\u00a2\u0006\u0006\u001a\u0004\b\r\u0010\u000eR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010"}, d2 = {"Lcom/android/keyguard/KeyguardListenQueue;", "", "sizePerModality", "", "(I)V", "faceQueue", "Lkotlin/collections/ArrayDeque;", "Lcom/android/keyguard/KeyguardFaceListenModel;", "fingerprintQueue", "Lcom/android/keyguard/KeyguardFingerprintListenModel;", "models", "", "Lcom/android/keyguard/KeyguardListenModel;", "getModels", "()Ljava/util/List;", "getSizePerModality", "()I", "add", "", "model", "print", "writer", "Ljava/io/PrintWriter;", "dateFormat", "Ljava/text/DateFormat;"})
public final class KeyguardListenQueue {
    private final kotlin.collections.ArrayDeque<com.android.keyguard.KeyguardFaceListenModel> faceQueue = null;
    private final kotlin.collections.ArrayDeque<com.android.keyguard.KeyguardFingerprintListenModel> fingerprintQueue = null;
    private final int sizePerModality = 0;
    
    @org.jetbrains.annotations.NotNull()
    @androidx.annotation.VisibleForTesting()
    public final java.util.List<com.android.keyguard.KeyguardListenModel> getModels() {
        return null;
    }
    
    /**
     * Push a [model] to the queue (will be logged until the queue exceeds [sizePerModality]).
     */
    public final void add(@org.jetbrains.annotations.NotNull()
    com.android.keyguard.KeyguardListenModel model) {
    }
    
    /**
     * Print verbose logs via the [writer].
     */
    public final void print(@org.jetbrains.annotations.NotNull()
    java.io.PrintWriter writer, @org.jetbrains.annotations.NotNull()
    java.text.DateFormat dateFormat) {
    }
    
    /**
     * Print verbose logs via the [writer].
     */
    public final void print(@org.jetbrains.annotations.NotNull()
    java.io.PrintWriter writer) {
    }
    
    public final int getSizePerModality() {
        return 0;
    }
    
    public KeyguardListenQueue(int sizePerModality) {
        super();
    }
    
    public KeyguardListenQueue() {
        super();
    }
}