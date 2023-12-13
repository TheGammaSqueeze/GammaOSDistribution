package org.calyxos.backup.storage.prune;

import android.util.Log;
import org.calyxos.backup.storage.api.BackupObserver;
import org.calyxos.backup.storage.api.StoragePlugin;
import org.calyxos.backup.storage.api.StoredSnapshot;
import org.calyxos.backup.storage.crypto.StreamCrypto;
import org.calyxos.backup.storage.db.Db;
import org.calyxos.backup.storage.plugin.SnapshotRetriever;
import java.io.IOException;
import java.security.GeneralSecurityException;
import kotlin.time.ExperimentalTime;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\b\n\u0000\n\u0002\u0010\u000e\n\u0000\"\u0016\u0010\u0000\u001a\n \u0002*\u0004\u0018\u00010\u00010\u0001X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"TAG", "", "kotlin.jvm.PlatformType"})
public final class PrunerKt {
    private static final java.lang.String TAG = null;
}