package org.calyxos.backup.storage.restore;

import android.content.ContentValues;
import android.content.Context;
import android.media.MediaScannerConnection;
import android.net.Uri;
import android.provider.MediaStore.MediaColumns;
import android.util.Log;
import org.calyxos.backup.storage.api.MediaType;
import org.calyxos.backup.storage.api.RestoreObserver;
import org.calyxos.backup.storage.backup.BackupMediaFile;
import org.calyxos.backup.storage.scanner.MediaScanner;
import java.io.File;
import java.io.IOException;
import java.io.OutputStream;

@kotlin.Suppress(names = {"BlockingMethodInNonBlockingContext"})
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000f\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0005\n\u0002\u0018\u0002\b\u0000\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0010\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\rH\u0002JL\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u001121\u0010\u0012\u001a-\b\u0001\u0012\u0013\u0012\u00110\u0014\u00a2\u0006\f\b\u0015\u0012\b\b\u0016\u0012\u0004\b\b(\u0017\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u000f0\u0018\u0012\u0006\u0012\u0004\u0018\u00010\u00010\u0013H\u0082@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0019J^\u0010\u000e\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\u001a2\b\u0010\u001b\u001a\u0004\u0018\u00010\u001c2\u0006\u0010\u001d\u001a\u00020\u001e21\u0010\u0012\u001a-\b\u0001\u0012\u0013\u0012\u00110\u0014\u00a2\u0006\f\b\u0015\u0012\b\b\u0016\u0012\u0004\b\b(\u0017\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u000f0\u0018\u0012\u0006\u0012\u0004\u0018\u00010\u00010\u0013H\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u001fJL\u0010\u000e\u001a\u00020\u000f2\u0006\u0010 \u001a\u00020\u001a21\u0010\u0012\u001a-\b\u0001\u0012\u0013\u0012\u00110\u0014\u00a2\u0006\f\b\u0015\u0012\b\b\u0016\u0012\u0004\b\b(\u0017\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u000f0\u0018\u0012\u0006\u0012\u0004\u0018\u00010\u00010\u0013H\u0082@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010!J\u0018\u0010\"\u001a\u00020\u000b2\u0006\u0010\u0010\u001a\u00020\u00112\u0006\u0010#\u001a\u00020$H\u0002R\u0016\u0010\u0007\u001a\n \t*\u0004\u0018\u00010\b0\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lorg/calyxos/backup/storage/restore/FileRestore;", "", "context", "Landroid/content/Context;", "mediaScanner", "Lorg/calyxos/backup/storage/scanner/MediaScanner;", "(Landroid/content/Context;Lorg/calyxos/backup/storage/scanner/MediaScanner;)V", "contentResolver", "Landroid/content/ContentResolver;", "kotlin.jvm.PlatformType", "indexFile", "", "file", "Ljava/io/File;", "restoreFile", "", "mediaFile", "Lorg/calyxos/backup/storage/backup/BackupMediaFile;", "streamWriter", "Lkotlin/Function2;", "Ljava/io/OutputStream;", "Lkotlin/ParameterName;", "name", "outputStream", "Lkotlin/coroutines/Continuation;", "(Lorg/calyxos/backup/storage/backup/BackupMediaFile;Lkotlin/jvm/functions/Function2;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "Lorg/calyxos/backup/storage/restore/RestorableFile;", "observer", "Lorg/calyxos/backup/storage/api/RestoreObserver;", "tag", "", "(Lorg/calyxos/backup/storage/restore/RestorableFile;Lorg/calyxos/backup/storage/api/RestoreObserver;Ljava/lang/String;Lkotlin/jvm/functions/Function2;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "docFile", "(Lorg/calyxos/backup/storage/restore/RestorableFile;Lkotlin/jvm/functions/Function2;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "setLastModifiedOnMediaFile", "uri", "Landroid/net/Uri;"})
public final class FileRestore {
    private final android.content.ContentResolver contentResolver = null;
    private final android.content.Context context = null;
    private final org.calyxos.backup.storage.scanner.MediaScanner mediaScanner = null;
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Object restoreFile(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.restore.RestorableFile file, @org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.api.RestoreObserver observer, @org.jetbrains.annotations.NotNull()
    java.lang.String tag, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function2<? super java.io.OutputStream, ? super kotlin.coroutines.Continuation<? super java.lang.Long>, ? extends java.lang.Object> streamWriter, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p4) {
        return null;
    }
    
    private final void setLastModifiedOnMediaFile(org.calyxos.backup.storage.backup.BackupMediaFile mediaFile, android.net.Uri uri) {
    }
    
    private final void indexFile(java.io.File file) {
    }
    
    public FileRestore(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.scanner.MediaScanner mediaScanner) {
        super();
    }
}