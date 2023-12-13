package org.calyxos.backup.storage.plugin.saf;

import android.annotation.SuppressLint;
import android.content.ContentResolver;
import android.content.Context;
import android.database.ContentObserver;
import android.database.Cursor;
import android.net.Uri;
import android.util.Log;
import androidx.annotation.VisibleForTesting;
import androidx.documentfile.provider.DocumentFile;
import kotlinx.coroutines.TimeoutCancellationException;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000T\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0000\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J+\u0010\u0005\u001a\u00020\u00062\b\b\u0002\u0010\u0007\u001a\u00020\b2\u000e\u0010\t\u001a\n\u0012\u0006\u0012\u0004\u0018\u00010\u00060\nH\u0087@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u000bJ \u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\r2\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u0012H\u0007J\u0012\u0010\u0013\u001a\u00020\r*\u00020\r2\u0006\u0010\u0014\u001a\u00020\u0004J\u001a\u0010\u0015\u001a\u00020\r*\u00020\r2\u0006\u0010\u0014\u001a\u00020\u00042\u0006\u0010\u0016\u001a\u00020\u0004J\'\u0010\u0017\u001a\u0004\u0018\u00010\r*\u00020\r2\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0018\u001a\u00020\u0004H\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0019J\u0012\u0010\u001a\u001a\u00020\u001b*\u00020\r2\u0006\u0010\u001c\u001a\u00020\u001dJ\u0012\u0010\u001e\u001a\u00020\u001f*\u00020\r2\u0006\u0010\u001c\u001a\u00020\u001dJ#\u0010 \u001a\b\u0012\u0004\u0012\u00020\r0!*\u00020\r2\u0006\u0010\u000f\u001a\u00020\u0010H\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\"R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lorg/calyxos/backup/storage/plugin/saf/DocumentFileExt;", "", "()V", "TAG", "", "getLoadedCursor", "Landroid/database/Cursor;", "timeout", "", "query", "Lkotlin/Function0;", "(JLkotlin/jvm/functions/Function0;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "getTreeDocumentFile", "Landroidx/documentfile/provider/DocumentFile;", "parent", "context", "Landroid/content/Context;", "uri", "Landroid/net/Uri;", "createDirectoryOrThrow", "name", "createFileOrThrow", "mimeType", "findFileBlocking", "displayName", "(Landroidx/documentfile/provider/DocumentFile;Landroid/content/Context;Ljava/lang/String;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "getInputStream", "Ljava/io/InputStream;", "contentResolver", "Landroid/content/ContentResolver;", "getOutputStream", "Ljava/io/OutputStream;", "listFilesBlocking", "", "(Landroidx/documentfile/provider/DocumentFile;Landroid/content/Context;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;"})
public final class DocumentFileExt {
    private static final java.lang.String TAG = "DocumentFileExt";
    @org.jetbrains.annotations.NotNull()
    public static final org.calyxos.backup.storage.plugin.saf.DocumentFileExt INSTANCE = null;
    
    @org.jetbrains.annotations.NotNull()
    public final java.io.InputStream getInputStream(@org.jetbrains.annotations.NotNull()
    androidx.documentfile.provider.DocumentFile $this$getInputStream, @org.jetbrains.annotations.NotNull()
    android.content.ContentResolver contentResolver) throws java.io.IOException {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.io.OutputStream getOutputStream(@org.jetbrains.annotations.NotNull()
    androidx.documentfile.provider.DocumentFile $this$getOutputStream, @org.jetbrains.annotations.NotNull()
    android.content.ContentResolver contentResolver) throws java.io.IOException {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final androidx.documentfile.provider.DocumentFile createDirectoryOrThrow(@org.jetbrains.annotations.NotNull()
    androidx.documentfile.provider.DocumentFile $this$createDirectoryOrThrow, @org.jetbrains.annotations.NotNull()
    java.lang.String name) throws java.io.IOException {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final androidx.documentfile.provider.DocumentFile createFileOrThrow(@org.jetbrains.annotations.NotNull()
    androidx.documentfile.provider.DocumentFile $this$createFileOrThrow, @org.jetbrains.annotations.NotNull()
    java.lang.String name, @org.jetbrains.annotations.NotNull()
    java.lang.String mimeType) throws java.io.IOException {
        return null;
    }
    
    /**
     * Works like [DocumentFile.listFiles] except
     * that it waits until the DocumentProvider has a result.
     * This prevents getting an empty list even though there are children to be listed.
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Object listFilesBlocking(@org.jetbrains.annotations.NotNull()
    androidx.documentfile.provider.DocumentFile $this$listFilesBlocking, @org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super java.util.List<? extends androidx.documentfile.provider.DocumentFile>> p2) {
        return null;
    }
    
    /**
     * An extremely dirty reflection hack to instantiate a TreeDocumentFile with a parent.
     *
     * All other public ways to get a TreeDocumentFile only work from [Uri]s
     * (e.g. [DocumentFile.fromTreeUri]) and always set parent to null.
     *
     * We have a test for this method to ensure CI will alert us when this reflection breaks.
     * Also, [DocumentFile] is part of AndroidX, so we control the dependency and notice when it fails.
     */
    @org.jetbrains.annotations.NotNull()
    @android.annotation.SuppressLint(value = {"CheckedExceptions"})
    @androidx.annotation.VisibleForTesting()
    public final androidx.documentfile.provider.DocumentFile getTreeDocumentFile(@org.jetbrains.annotations.NotNull()
    androidx.documentfile.provider.DocumentFile parent, @org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    android.net.Uri uri) {
        return null;
    }
    
    /**
     * Same as [DocumentFile.findFile] only that it re-queries when the first result was stale.
     *
     * Most documents providers including Nextcloud are listing the full directory content
     * when querying for a specific file in a directory,
     * so there is no point in trying to optimize the query by not listing all children.
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Object findFileBlocking(@org.jetbrains.annotations.NotNull()
    androidx.documentfile.provider.DocumentFile $this$findFileBlocking, @org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.lang.String displayName, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super androidx.documentfile.provider.DocumentFile> p3) {
        return null;
    }
    
    /**
     * Returns a cursor for the given query while ensuring that the cursor was loaded.
     *
     * When the SAF backend is a cloud storage provider (e.g. Nextcloud),
     * it can happen that the query returns an outdated (e.g. empty) cursor
     * which will only be updated in response to this query.
     *
     * See: https://commonsware.com/blog/2019/12/14/scoped-storage-stories-listfiles-woe.html
     *
     * This method uses a [suspendCancellableCoroutine] to wait for the result of a [ContentObserver]
     * registered on the cursor in case the cursor is still loading ([EXTRA_LOADING]).
     * If the cursor is not loading, it will be returned right away.
     *
     * @param timeout an optional time-out in milliseconds
     * @throws TimeoutCancellationException if there was no result before the time-out
     * @throws IOException if the query returns null
     */
    @org.jetbrains.annotations.Nullable()
    @androidx.annotation.VisibleForTesting()
    public final java.lang.Object getLoadedCursor(long timeout, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<? extends android.database.Cursor> query, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super android.database.Cursor> p2) {
        return null;
    }
    
    private DocumentFileExt() {
        super();
    }
}