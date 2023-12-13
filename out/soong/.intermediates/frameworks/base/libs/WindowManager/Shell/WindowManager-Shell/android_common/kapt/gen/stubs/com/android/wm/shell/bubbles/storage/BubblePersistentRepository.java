package com.android.wm.shell.bubbles.storage;

import android.content.Context;
import android.util.AtomicFile;
import android.util.Log;
import android.util.SparseArray;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u001a\u0010\u0007\u001a\u00020\b2\u0012\u0010\t\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\f0\u000b0\nJ\u0012\u0010\r\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\f0\u000b0\nR\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/wm/shell/bubbles/storage/BubblePersistentRepository;", "", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "bubbleFile", "Landroid/util/AtomicFile;", "persistsToDisk", "", "bubbles", "Landroid/util/SparseArray;", "", "Lcom/android/wm/shell/bubbles/storage/BubbleEntity;", "readFromDisk"})
public final class BubblePersistentRepository {
    private final android.util.AtomicFile bubbleFile = null;
    
    public final boolean persistsToDisk(@org.jetbrains.annotations.NotNull()
    android.util.SparseArray<java.util.List<com.android.wm.shell.bubbles.storage.BubbleEntity>> bubbles) {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.util.SparseArray<java.util.List<com.android.wm.shell.bubbles.storage.BubbleEntity>> readFromDisk() {
        return null;
    }
    
    public BubblePersistentRepository(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
}