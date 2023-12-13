package org.calyxos.backup.storage.backup;

import org.calyxos.backup.storage.content.ContentFile;
import org.calyxos.backup.storage.db.CachedChunk;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.security.GeneralSecurityException;
import java.util.zip.ZipOutputStream;
import javax.crypto.Mac;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0006\n\u0000\n\u0002\u0010\b\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"ZIP_CHUNK_SIZE_MAX", ""})
public final class ZipChunkerKt {
    private static final int ZIP_CHUNK_SIZE_MAX = 7340032;
}