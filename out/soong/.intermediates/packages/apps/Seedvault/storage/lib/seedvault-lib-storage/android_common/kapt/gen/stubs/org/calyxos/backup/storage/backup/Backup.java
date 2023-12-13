package org.calyxos.backup.storage.backup;

import android.content.Context;
import android.os.Build;
import android.text.format.Formatter;
import android.util.Log;
import org.calyxos.backup.storage.api.BackupObserver;
import org.calyxos.backup.storage.api.StoragePlugin;
import org.calyxos.backup.storage.crypto.ChunkCrypto;
import org.calyxos.backup.storage.crypto.StreamCrypto;
import org.calyxos.backup.storage.db.Db;
import org.calyxos.backup.storage.scanner.FileScanner;
import org.calyxos.backup.storage.scanner.FileScannerResult;
import java.io.IOException;
import java.security.GeneralSecurityException;
import kotlin.time.Duration;
import kotlin.time.ExperimentalTime;

@kotlin.Suppress(names = {"BlockingMethodInNonBlockingContext"})
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0090\u0001\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0012\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\b\u0000\u0018\u0000 12\u00020\u0001:\u00011BA\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\b\b\u0002\u0010\f\u001a\u00020\r\u0012\b\b\u0002\u0010\u000e\u001a\u00020\u000f\u00a2\u0006\u0002\u0010\u0010J;\u0010$\u001a\u00020%2\u0006\u0010&\u001a\u00020\'2\u0016\u0010(\u001a\u0012\u0012\u0004\u0012\u00020*0)j\b\u0012\u0004\u0012\u00020*`+2\b\u0010,\u001a\u0004\u0018\u00010-H\u0082@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010.J\u001b\u0010/\u001a\u00020%2\b\u0010,\u001a\u0004\u0018\u00010-H\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u00100R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0015\u001a\n \u0017*\u0004\u0018\u00010\u00160\u0016X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0018\u001a\u00020\u0019X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001a\u001a\u00020\u001bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001c\u001a\u00020\u001dX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001e\u001a\u00020\u001fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010 \u001a\u00020!X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\"\u001a\u00020#X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lorg/calyxos/backup/storage/backup/Backup;", "", "context", "Landroid/content/Context;", "db", "Lorg/calyxos/backup/storage/db/Db;", "fileScanner", "Lorg/calyxos/backup/storage/scanner/FileScanner;", "storagePlugin", "Lorg/calyxos/backup/storage/api/StoragePlugin;", "cacheRepopulater", "Lorg/calyxos/backup/storage/backup/ChunksCacheRepopulater;", "chunkSizeMax", "", "streamCrypto", "Lorg/calyxos/backup/storage/crypto/StreamCrypto;", "(Landroid/content/Context;Lorg/calyxos/backup/storage/db/Db;Lorg/calyxos/backup/storage/scanner/FileScanner;Lorg/calyxos/backup/storage/api/StoragePlugin;Lorg/calyxos/backup/storage/backup/ChunksCacheRepopulater;ILorg/calyxos/backup/storage/crypto/StreamCrypto;)V", "chunkWriter", "Lorg/calyxos/backup/storage/backup/ChunkWriter;", "chunksCache", "Lorg/calyxos/backup/storage/db/ChunksCache;", "contentResolver", "Landroid/content/ContentResolver;", "kotlin.jvm.PlatformType", "fileBackup", "Lorg/calyxos/backup/storage/backup/FileBackup;", "filesCache", "Lorg/calyxos/backup/storage/db/FilesCache;", "hasMediaAccessPerm", "", "mac", "Ljavax/crypto/Mac;", "smallFileBackup", "Lorg/calyxos/backup/storage/backup/SmallFileBackup;", "streamKey", "", "backupFiles", "", "filesResult", "Lorg/calyxos/backup/storage/scanner/FileScannerResult;", "availableChunkIds", "Ljava/util/HashSet;", "", "Lkotlin/collections/HashSet;", "backupObserver", "Lorg/calyxos/backup/storage/api/BackupObserver;", "(Lorg/calyxos/backup/storage/scanner/FileScannerResult;Ljava/util/HashSet;Lorg/calyxos/backup/storage/api/BackupObserver;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "runBackup", "(Lorg/calyxos/backup/storage/api/BackupObserver;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "Companion"})
public final class Backup {
    private final android.content.ContentResolver contentResolver = null;
    private final org.calyxos.backup.storage.db.FilesCache filesCache = null;
    private final org.calyxos.backup.storage.db.ChunksCache chunksCache = null;
    private final javax.crypto.Mac mac = null;
    private final byte[] streamKey = null;
    private final org.calyxos.backup.storage.backup.ChunkWriter chunkWriter = null;
    private final boolean hasMediaAccessPerm = false;
    private final org.calyxos.backup.storage.backup.FileBackup fileBackup = null;
    private final org.calyxos.backup.storage.backup.SmallFileBackup smallFileBackup = null;
    private final android.content.Context context = null;
    private final org.calyxos.backup.storage.db.Db db = null;
    private final org.calyxos.backup.storage.scanner.FileScanner fileScanner = null;
    private final org.calyxos.backup.storage.api.StoragePlugin storagePlugin = null;
    private final org.calyxos.backup.storage.backup.ChunksCacheRepopulater cacheRepopulater = null;
    private final org.calyxos.backup.storage.crypto.StreamCrypto streamCrypto = null;
    public static final byte VERSION = (byte)0;
    public static final int CHUNK_SIZE_MAX = 15728640;
    public static final int SMALL_FILE_SIZE_MAX = 2097152;
    private static final java.lang.String TAG = "Backup";
    @org.jetbrains.annotations.NotNull()
    public static final org.calyxos.backup.storage.backup.Backup.Companion Companion = null;
    
    @org.jetbrains.annotations.Nullable()
    @kotlin.OptIn(markerClass = {kotlin.time.ExperimentalTime.class})
    public final java.lang.Object runBackup(@org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.api.BackupObserver backupObserver, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1) {
        return null;
    }
    
    public Backup(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.db.Db db, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.scanner.FileScanner fileScanner, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoragePlugin storagePlugin, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.backup.ChunksCacheRepopulater cacheRepopulater, int chunkSizeMax, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.crypto.StreamCrypto streamCrypto) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001e\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u0005\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0086T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/backup/Backup$Companion;", "", "()V", "CHUNK_SIZE_MAX", "", "SMALL_FILE_SIZE_MAX", "TAG", "", "VERSION", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}