package org.calyxos.backup.storage.backup;

import android.util.Log;
import org.calyxos.backup.storage.api.StoragePlugin;
import org.calyxos.backup.storage.crypto.StreamCrypto;
import org.calyxos.backup.storage.db.ChunksCache;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.file.attribute.FileTime;
import java.security.GeneralSecurityException;
import java.util.zip.ZipEntry;
import java.util.zip.ZipOutputStream;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0006\n\u0000\n\u0002\u0010\u000e\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"TAG", ""})
public final class ChunkWriterKt {
    private static final java.lang.String TAG = "ChunkWriter";
}