package org.calyxos.backup.storage.restore;

import android.util.Log;
import org.calyxos.backup.storage.api.RestoreObserver;
import org.calyxos.backup.storage.api.StoragePlugin;
import org.calyxos.backup.storage.api.StoredSnapshot;
import org.calyxos.backup.storage.crypto.StreamCrypto;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.zip.ZipInputStream;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0006\n\u0000\n\u0002\u0010\u000e\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"TAG", ""})
public final class ZipChunkRestoreKt {
    private static final java.lang.String TAG = "ZipChunkRestore";
}