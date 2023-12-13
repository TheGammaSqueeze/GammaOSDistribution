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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000z\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0012\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u0000\u0018\u00002\u00020\u0001B/\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\b\b\u0002\u0010\n\u001a\u00020\u000b\u00a2\u0006\u0002\u0010\fJ \u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u00132\u0006\u0010\u0014\u001a\u00020\u0015H\u0002J\u0010\u0010\u0016\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\u000bH\u0002J*\u0010\u0019\u001a\u00020\u001a2\u0006\u0010\u0010\u001a\u00020\u00112\f\u0010\u001b\u001a\b\u0012\u0004\u0012\u00020\u00130\u001c2\f\u0010\u001d\u001a\b\u0012\u0004\u0012\u00020\u001e0\u001cJ$\u0010\u001f\u001a\u00020\u000f2\u0006\u0010 \u001a\u00020\u001e2\u0012\u0010!\u001a\u000e\u0012\u0004\u0012\u00020\u0015\u0012\u0004\u0012\u00020\u000f0\"H\u0002J\u001e\u0010#\u001a\u00020\u000f2\u0006\u0010$\u001a\u00020%2\u0006\u0010\u0018\u001a\u00020\u000b2\u0006\u0010\u0010\u001a\u00020\u0011J$\u0010&\u001a\u00020\'2\u0006\u0010\u0012\u001a\u00020(2\u0006\u0010)\u001a\u00020*2\f\u0010\u001d\u001a\b\u0012\u0004\u0012\u00020\u001e0\u001cR\u000e\u0010\r\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/backup/ChunkWriter;", "", "streamCrypto", "Lorg/calyxos/backup/storage/crypto/StreamCrypto;", "streamKey", "", "chunksCache", "Lorg/calyxos/backup/storage/db/ChunksCache;", "storagePlugin", "Lorg/calyxos/backup/storage/api/StoragePlugin;", "bufferSize", "", "(Lorg/calyxos/backup/storage/crypto/StreamCrypto;[BLorg/calyxos/backup/storage/db/ChunksCache;Lorg/calyxos/backup/storage/api/StoragePlugin;I)V", "buffer", "copyChunkFromInputStream", "", "inputStream", "Ljava/io/InputStream;", "chunk", "Lorg/calyxos/backup/storage/backup/Chunk;", "outputStream", "Ljava/io/OutputStream;", "createNewZipEntry", "Ljava/util/zip/ZipEntry;", "counter", "writeChunk", "Lorg/calyxos/backup/storage/backup/ChunkWriterResult;", "chunks", "", "missingChunkIds", "", "writeChunkData", "chunkId", "writer", "Lkotlin/Function1;", "writeNewZipEntry", "zipOutputStream", "Ljava/util/zip/ZipOutputStream;", "writeZipChunk", "", "Lorg/calyxos/backup/storage/backup/ZipChunk;", "zip", "Ljava/io/ByteArrayOutputStream;"})
public final class ChunkWriter {
    private final byte[] buffer = null;
    private final org.calyxos.backup.storage.crypto.StreamCrypto streamCrypto = null;
    private final byte[] streamKey = null;
    private final org.calyxos.backup.storage.db.ChunksCache chunksCache = null;
    private final org.calyxos.backup.storage.api.StoragePlugin storagePlugin = null;
    private final int bufferSize = 0;
    
    @org.jetbrains.annotations.NotNull()
    public final org.calyxos.backup.storage.backup.ChunkWriterResult writeChunk(@org.jetbrains.annotations.NotNull()
    java.io.InputStream inputStream, @org.jetbrains.annotations.NotNull()
    java.util.List<org.calyxos.backup.storage.backup.Chunk> chunks, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> missingChunkIds) {
        return null;
    }
    
    private final void writeChunkData(java.lang.String chunkId, kotlin.jvm.functions.Function1<? super java.io.OutputStream, kotlin.Unit> writer) {
    }
    
    private final void copyChunkFromInputStream(java.io.InputStream inputStream, org.calyxos.backup.storage.backup.Chunk chunk, java.io.OutputStream outputStream) throws java.io.IOException {
    }
    
    /**
     * Writes the zip chunk to backup storage.
     *
     * @return true if the chunk was written or false, if it was present already.
     */
    public final boolean writeZipChunk(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.backup.ZipChunk chunk, @org.jetbrains.annotations.NotNull()
    java.io.ByteArrayOutputStream zip, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> missingChunkIds) {
        return false;
    }
    
    public final void writeNewZipEntry(@org.jetbrains.annotations.NotNull()
    java.util.zip.ZipOutputStream zipOutputStream, int counter, @org.jetbrains.annotations.NotNull()
    java.io.InputStream inputStream) throws java.io.IOException {
    }
    
    private final java.util.zip.ZipEntry createNewZipEntry(int counter) {
        return null;
    }
    
    public ChunkWriter(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.crypto.StreamCrypto streamCrypto, @org.jetbrains.annotations.NotNull()
    byte[] streamKey, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.db.ChunksCache chunksCache, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoragePlugin storagePlugin, int bufferSize) {
        super();
    }
}