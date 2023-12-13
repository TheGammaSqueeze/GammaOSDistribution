package org.calyxos.backup.storage.api;

import android.content.Context;
import android.net.Uri;
import android.provider.MediaStore;
import android.util.Log;
import androidx.annotation.WorkerThread;
import androidx.room.Room;
import kotlinx.coroutines.CoroutineDispatcher;
import kotlinx.coroutines.Dispatchers;
import kotlinx.coroutines.flow.Flow;
import org.calyxos.backup.storage.backup.Backup;
import org.calyxos.backup.storage.backup.BackupSnapshot;
import org.calyxos.backup.storage.backup.ChunksCacheRepopulater;
import org.calyxos.backup.storage.db.Db;
import org.calyxos.backup.storage.plugin.SnapshotRetriever;
import org.calyxos.backup.storage.prune.Pruner;
import org.calyxos.backup.storage.prune.RetentionManager;
import org.calyxos.backup.storage.restore.FileRestore;
import org.calyxos.backup.storage.restore.Restore;
import org.calyxos.backup.storage.scanner.DocumentScanner;
import org.calyxos.backup.storage.scanner.FileScanner;
import org.calyxos.backup.storage.scanner.MediaScanner;
import java.io.IOException;
import java.util.concurrent.atomic.AtomicBoolean;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0006\n\u0000\n\u0002\u0010\u000e\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"TAG", ""})
public final class StorageBackupKt {
    private static final java.lang.String TAG = "StorageBackup";
}