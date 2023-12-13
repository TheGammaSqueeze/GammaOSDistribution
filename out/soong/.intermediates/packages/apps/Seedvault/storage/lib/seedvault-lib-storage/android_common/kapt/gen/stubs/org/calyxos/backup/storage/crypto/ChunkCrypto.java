package org.calyxos.backup.storage.crypto;

import org.calyxos.backup.storage.backup.Chunker;
import java.security.GeneralSecurityException;
import java.security.KeyStore;
import javax.crypto.Mac;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u0012\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\b\u00c0\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0018\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\b\b\u0002\u0010\t\u001a\u00020\u0006J\u000e\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\u0006R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/crypto/ChunkCrypto;", "", "()V", "INFO_CHUNK_ID", "", "deriveChunkIdKey", "", "masterKey", "Ljavax/crypto/SecretKey;", "info", "getMac", "Ljavax/crypto/Mac;", "chunkKey"})
public final class ChunkCrypto {
    private static final java.lang.String INFO_CHUNK_ID = "Chunk ID calculation";
    @org.jetbrains.annotations.NotNull()
    public static final org.calyxos.backup.storage.crypto.ChunkCrypto INSTANCE = null;
    
    /**
     * We are deriving a dedicated key for chunk ID derivation,
     * because using a [ByteArray] instead of a key inside the [KeyStore]
     * is orders of magnitude faster.
     */
    @org.jetbrains.annotations.NotNull()
    public final byte[] deriveChunkIdKey(@org.jetbrains.annotations.NotNull()
    javax.crypto.SecretKey masterKey, @org.jetbrains.annotations.NotNull()
    byte[] info) throws java.security.GeneralSecurityException {
        return null;
    }
    
    /**
     * Gets a re-usable [Mac] instance to be used with [Chunker.makeChunks].
     */
    @org.jetbrains.annotations.NotNull()
    public final javax.crypto.Mac getMac(@org.jetbrains.annotations.NotNull()
    byte[] chunkKey) throws java.security.GeneralSecurityException {
        return null;
    }
    
    private ChunkCrypto() {
        super();
    }
}