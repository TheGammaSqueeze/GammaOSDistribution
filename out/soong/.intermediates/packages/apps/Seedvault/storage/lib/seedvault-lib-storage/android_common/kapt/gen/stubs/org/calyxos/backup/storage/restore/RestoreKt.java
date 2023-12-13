package org.calyxos.backup.storage.restore;

import android.content.Context;
import android.util.Log;
import kotlinx.coroutines.flow.Flow;
import org.calyxos.backup.storage.api.RestoreObserver;
import org.calyxos.backup.storage.api.SnapshotItem;
import org.calyxos.backup.storage.api.SnapshotResult;
import org.calyxos.backup.storage.api.StoragePlugin;
import org.calyxos.backup.storage.api.StoredSnapshot;
import org.calyxos.backup.storage.backup.Backup;
import org.calyxos.backup.storage.backup.BackupSnapshot;
import org.calyxos.backup.storage.crypto.StreamCrypto;
import org.calyxos.backup.storage.plugin.SnapshotRetriever;
import java.io.IOException;
import java.io.InputStream;
import java.security.GeneralSecurityException;
import kotlin.time.ExperimentalTime;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0014\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0002\u0018\u0002\n\u0002\b\u0002\u001a\u001d\u0010\u0002\u001a\u00020\u0003*\u00020\u00042\n\b\u0002\u0010\u0005\u001a\u0004\u0018\u00010\u0003H\u0000\u00a2\u0006\u0002\u0010\u0006\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"TAG", "", "readVersion", "", "Ljava/io/InputStream;", "expectedVersion", "(Ljava/io/InputStream;Ljava/lang/Integer;)I"})
public final class RestoreKt {
    private static final java.lang.String TAG = "Restore";
    
    public static final int readVersion(@org.jetbrains.annotations.NotNull()
    java.io.InputStream $this$readVersion, @org.jetbrains.annotations.Nullable()
    java.lang.Integer expectedVersion) throws java.io.IOException, java.security.GeneralSecurityException {
        return 0;
    }
}