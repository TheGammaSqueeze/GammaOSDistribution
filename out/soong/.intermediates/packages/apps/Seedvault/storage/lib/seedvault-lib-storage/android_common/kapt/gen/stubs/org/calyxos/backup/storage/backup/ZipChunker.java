package org.calyxos.backup.storage.backup;

import org.calyxos.backup.storage.content.ContentFile;
import org.calyxos.backup.storage.db.CachedChunk;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.security.GeneralSecurityException;
import java.util.zip.ZipOutputStream;
import javax.crypto.Mac;

@kotlin.Suppress(names = {"BlockingMethodInNonBlockingContext"})
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000X\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\n\u0000\b\u0000\u0018\u00002\u00020\u0001B\u001f\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\b\b\u0002\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\u0016\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\f2\u0006\u0010\u0014\u001a\u00020\u0015J\u0014\u0010\u0016\u001a\u00020\u00172\f\u0010\u0018\u001a\b\u0012\u0004\u0012\u00020\u001a0\u0019J\u000e\u0010\u001b\u001a\u00020\u001c2\u0006\u0010\u0013\u001a\u00020\fJ\b\u0010\u001d\u001a\u00020\u0012H\u0002R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\n\u001a\b\u0012\u0004\u0012\u00020\f0\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/backup/ZipChunker;", "", "mac", "Ljavax/crypto/Mac;", "chunkWriter", "Lorg/calyxos/backup/storage/backup/ChunkWriter;", "chunkSizeMax", "", "(Ljavax/crypto/Mac;Lorg/calyxos/backup/storage/backup/ChunkWriter;I)V", "counter", "files", "Ljava/util/ArrayList;", "Lorg/calyxos/backup/storage/content/ContentFile;", "outputStream", "Ljava/io/ByteArrayOutputStream;", "zipOutputStream", "Ljava/util/zip/ZipOutputStream;", "addFile", "", "file", "inputStream", "Ljava/io/InputStream;", "finalizeAndReset", "Lorg/calyxos/backup/storage/backup/ZipChunk;", "missingChunkIds", "", "", "fitsFile", "", "reset"})
public final class ZipChunker {
    private final java.util.ArrayList<org.calyxos.backup.storage.content.ContentFile> files = null;
    private final java.io.ByteArrayOutputStream outputStream = null;
    private java.util.zip.ZipOutputStream zipOutputStream;
    private int counter = 1;
    private final javax.crypto.Mac mac = null;
    private final org.calyxos.backup.storage.backup.ChunkWriter chunkWriter = null;
    private final int chunkSizeMax = 0;
    
    public final boolean fitsFile(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.content.ContentFile file) {
        return false;
    }
    
    public final void addFile(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.content.ContentFile file, @org.jetbrains.annotations.NotNull()
    java.io.InputStream inputStream) throws java.io.IOException {
    }
    
    /**
     * Finalizes the operation and returns a [ZipChunk] including the previous files.
     * This zip chunk will be uploaded to the backup storage.
     *
     * This object gets reset for the next operation.
     */
    @org.jetbrains.annotations.NotNull()
    public final org.calyxos.backup.storage.backup.ZipChunk finalizeAndReset(@org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> missingChunkIds) {
        return null;
    }
    
    private final void reset() {
    }
    
    public ZipChunker(@org.jetbrains.annotations.NotNull()
    javax.crypto.Mac mac, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.backup.ChunkWriter chunkWriter, int chunkSizeMax) {
        super();
    }
}