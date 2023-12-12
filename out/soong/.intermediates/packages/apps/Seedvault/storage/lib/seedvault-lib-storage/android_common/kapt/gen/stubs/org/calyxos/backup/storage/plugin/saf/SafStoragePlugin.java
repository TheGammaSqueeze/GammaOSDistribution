package org.calyxos.backup.storage.plugin.saf;

import android.annotation.SuppressLint;
import android.content.Context;
import android.provider.Settings;
import android.util.Log;
import androidx.documentfile.provider.DocumentFile;
import org.calyxos.backup.storage.api.StoragePlugin;
import org.calyxos.backup.storage.api.StoredSnapshot;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

/**
 * @param appContext application context provided by the storage module
 */
@kotlin.Suppress(names = {"BlockingMethodInNonBlockingContext"})
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000j\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\"\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010 \n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0002\b\u000b\n\u0002\u0018\u0002\n\u0002\b\u0002\b&\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004JB\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u000e\u001a\u00020\u000b2\"\u0010\u0012\u001a\u001e\u0012\u0004\u0012\u00020\u0014\u0012\u0004\u0012\u00020\u000b0\u0013j\u000e\u0012\u0004\u0012\u00020\u0014\u0012\u0004\u0012\u00020\u000b`\u00152\f\u0010\u0016\u001a\b\u0012\u0004\u0012\u00020\u00140\u0017H\u0002J\u0019\u0010\u0018\u001a\u00020\u00112\u0006\u0010\u0019\u001a\u00020\u001aH\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u001bJ\u001f\u0010\u001c\u001a\u00020\u00112\f\u0010\u001d\u001a\b\u0012\u0004\u0012\u00020\u00140\u001eH\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u001fJ\u0017\u0010 \u001a\b\u0012\u0004\u0012\u00020\u00140\u001eH\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010!J\u0019\u0010\"\u001a\u00020#2\u0006\u0010\u0019\u001a\u00020\u001aH\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u001bJ\u0010\u0010$\u001a\u00020%2\u0006\u0010&\u001a\u00020\'H\u0016J\u0017\u0010(\u001a\b\u0012\u0004\u0012\u00020\u001a0\u001eH\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010!J!\u0010)\u001a\u00020#2\u0006\u0010*\u001a\u00020\u001a2\u0006\u0010+\u001a\u00020\u0014H\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010,J\u0010\u0010-\u001a\u00020%2\u0006\u0010+\u001a\u00020\u0014H\u0016J\u0016\u0010.\u001a\b\u0012\u0004\u0012\u00020\u00140\u001e2\u0006\u0010/\u001a\u00020\u000bH\u0002J\u0017\u00100\u001a\b\u0012\u0004\u0012\u00020\u001a0\u001eH\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010!J\u0019\u0010\f\u001a\u00020\u000b2\u0006\u0010\u0019\u001a\u00020\u001aH\u0082@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u001bJ[\u00101\u001a\u00020\u00112\u0006\u0010\n\u001a\u00020\u000b2\"\u0010\u0012\u001a\u001e\u0012\u0004\u0012\u00020\u0014\u0012\u0004\u0012\u00020\u000b0\u0013j\u000e\u0012\u0004\u0012\u00020\u0014\u0012\u0004\u0012\u00020\u000b`\u00152\u001c\b\u0002\u00102\u001a\u0016\u0012\u0004\u0012\u00020\u000b\u0012\u0004\u0012\u00020\u0014\u0012\u0004\u0012\u00020\u0011\u0018\u000103H\u0082@\u00f8\u0001\u0000\u00a2\u0006\u0002\u00104J\u0010\u00105\u001a\u00020\u00142\u0006\u0010&\u001a\u00020\'H\u0002R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u0007\u001a\u00020\u0003X\u00a4\u0004\u00a2\u0006\u0006\u001a\u0004\b\b\u0010\tR\u0016\u0010\n\u001a\u0004\u0018\u00010\u000b8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\f\u0010\rR\u0014\u0010\u000e\u001a\u0004\u0018\u00010\u000bX\u00a4\u0004\u00a2\u0006\u0006\u001a\u0004\b\u000f\u0010\r\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lorg/calyxos/backup/storage/plugin/saf/SafStoragePlugin;", "Lorg/calyxos/backup/storage/api/StoragePlugin;", "appContext", "Landroid/content/Context;", "(Landroid/content/Context;)V", "cache", "Lorg/calyxos/backup/storage/plugin/saf/SafCache;", "context", "getContext", "()Landroid/content/Context;", "folder", "Landroidx/documentfile/provider/DocumentFile;", "getFolder", "()Landroidx/documentfile/provider/DocumentFile;", "root", "getRoot", "createMissingChunkFolders", "", "chunkFolders", "Ljava/util/HashMap;", "", "Lkotlin/collections/HashMap;", "expectedChunkFolders", "", "deleteBackupSnapshot", "storedSnapshot", "Lorg/calyxos/backup/storage/api/StoredSnapshot;", "(Lorg/calyxos/backup/storage/api/StoredSnapshot;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "deleteChunks", "chunkIds", "", "(Ljava/util/List;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "getAvailableChunkIds", "(Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "getBackupSnapshotInputStream", "Ljava/io/InputStream;", "getBackupSnapshotOutputStream", "Ljava/io/OutputStream;", "timestamp", "", "getBackupSnapshotsForRestore", "getChunkInputStream", "snapshot", "chunkId", "(Lorg/calyxos/backup/storage/api/StoredSnapshot;Ljava/lang/String;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "getChunkOutputStream", "getChunksFromFolder", "chunkFolder", "getCurrentBackupSnapshots", "populateChunkFolders", "fileOp", "Lkotlin/Function2;", "(Landroidx/documentfile/provider/DocumentFile;Ljava/util/HashMap;Lkotlin/jvm/functions/Function2;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "timestampToSnapshot"})
public abstract class SafStoragePlugin implements org.calyxos.backup.storage.api.StoragePlugin {
    private final org.calyxos.backup.storage.plugin.saf.SafCache cache = null;
    private final android.content.Context appContext = null;
    
    /**
     * Attention: This context could be unexpected. E.g. the system user's application context,
     * in the case of USB storage, if INTERACT_ACROSS_USERS_FULL permission is granted.
     * Use [appContext], if you need the context of the current app and user
     * and [context] for all file access.
     */
    @org.jetbrains.annotations.NotNull()
    protected abstract android.content.Context getContext();
    
    @org.jetbrains.annotations.Nullable()
    protected abstract androidx.documentfile.provider.DocumentFile getRoot();
    
    private final androidx.documentfile.provider.DocumentFile getFolder() {
        return null;
    }
    
    private final java.lang.String timestampToSnapshot(long timestamp) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object getAvailableChunkIds(@org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super java.util.List<java.lang.String>> p0) {
        return null;
    }
    
    private final java.util.List<java.lang.String> getChunksFromFolder(androidx.documentfile.provider.DocumentFile chunkFolder) {
        return null;
    }
    
    private final void createMissingChunkFolders(androidx.documentfile.provider.DocumentFile root, java.util.HashMap<java.lang.String, androidx.documentfile.provider.DocumentFile> chunkFolders, java.util.Set<java.lang.String> expectedChunkFolders) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.io.OutputStream getChunkOutputStream(@org.jetbrains.annotations.NotNull()
    java.lang.String chunkId) throws java.io.IOException {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.io.OutputStream getBackupSnapshotOutputStream(long timestamp) throws java.io.IOException {
        return null;
    }
    
    /**
     * *********************** Restore
     */
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object getBackupSnapshotsForRestore(@org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super java.util.List<org.calyxos.backup.storage.api.StoredSnapshot>> p0) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object getBackupSnapshotInputStream(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoredSnapshot p0, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super java.io.InputStream> p1) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object getChunkInputStream(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoredSnapshot p0, @org.jetbrains.annotations.NotNull()
    java.lang.String p1, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super java.io.InputStream> p2) {
        return null;
    }
    
    /**
     * *********************** Pruning
     */
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object getCurrentBackupSnapshots(@org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super java.util.List<org.calyxos.backup.storage.api.StoredSnapshot>> p0) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object deleteBackupSnapshot(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoredSnapshot p0, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object deleteChunks(@org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> p0, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1) {
        return null;
    }
    
    public SafStoragePlugin(@org.jetbrains.annotations.NotNull()
    android.content.Context appContext) {
        super();
    }
}