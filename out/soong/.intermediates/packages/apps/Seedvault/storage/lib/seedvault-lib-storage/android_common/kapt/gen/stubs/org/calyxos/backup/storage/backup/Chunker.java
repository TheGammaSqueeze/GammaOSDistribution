package org.calyxos.backup.storage.backup;

import org.calyxos.backup.storage.db.CachedChunk;
import java.io.IOException;
import java.io.InputStream;
import javax.crypto.Mac;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u0012\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u0000\u0018\u00002\u00020\u0001B\u001f\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\b\b\u0002\u0010\u0006\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0007J\u0014\u0010\n\u001a\b\u0012\u0004\u0012\u00020\f0\u000b2\u0006\u0010\r\u001a\u00020\u000eR\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/backup/Chunker;", "", "mac", "Ljavax/crypto/Mac;", "chunkSizeMax", "", "bufferSize", "(Ljavax/crypto/Mac;II)V", "buffer", "", "makeChunks", "", "Lorg/calyxos/backup/storage/backup/Chunk;", "inputStream", "Ljava/io/InputStream;"})
public final class Chunker {
    private final byte[] buffer = null;
    private final javax.crypto.Mac mac = null;
    private final int chunkSizeMax = 0;
    private final int bufferSize = 0;
    
    /**
     * Returns a list of chunks
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<org.calyxos.backup.storage.backup.Chunk> makeChunks(@org.jetbrains.annotations.NotNull()
    java.io.InputStream inputStream) {
        return null;
    }
    
    public Chunker(@org.jetbrains.annotations.NotNull()
    javax.crypto.Mac mac, int chunkSizeMax, int bufferSize) {
        super();
    }
}