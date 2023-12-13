package org.calyxos.backup.storage.crypto;

import com.google.crypto.tink.subtle.AesGcmHkdfStreaming;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.ByteBuffer;
import java.security.GeneralSecurityException;
import javax.crypto.SecretKey;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000F\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u0005\n\u0002\b\u0002\n\u0002\u0010\u0012\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0018\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\r2\b\b\u0002\u0010\u000e\u001a\u00020\u000bJ\u001f\u0010\u000f\u001a\u00020\u000b2\u0006\u0010\u0010\u001a\u00020\u00042\b\b\u0002\u0010\u0011\u001a\u00020\bH\u0000\u00a2\u0006\u0002\b\u0012J\u001f\u0010\u0013\u001a\u00020\u000b2\u0006\u0010\u0014\u001a\u00020\u00152\b\b\u0002\u0010\u0011\u001a\u00020\bH\u0000\u00a2\u0006\u0002\b\u0016J \u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u000b2\u0006\u0010\u001a\u001a\u00020\u00182\b\b\u0002\u0010\u001b\u001a\u00020\u000bJ \u0010\u001c\u001a\u00020\u001d2\u0006\u0010\u0019\u001a\u00020\u000b2\u0006\u0010\u001e\u001a\u00020\u001d2\b\b\u0002\u0010\u001b\u001a\u00020\u000bJ\n\u0010\u001f\u001a\u00020\u000b*\u00020\u0015R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\bX\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/crypto/StreamCrypto;", "", "()V", "INFO_STREAM_KEY", "", "SIZE_SEGMENT", "", "TYPE_CHUNK", "", "TYPE_SNAPSHOT", "deriveStreamKey", "", "masterKey", "Ljavax/crypto/SecretKey;", "info", "getAssociatedDataForChunk", "chunkId", "version", "getAssociatedDataForChunk$main", "getAssociatedDataForSnapshot", "timestamp", "", "getAssociatedDataForSnapshot$main", "newDecryptingStream", "Ljava/io/InputStream;", "secret", "inputStream", "associatedData", "newEncryptingStream", "Ljava/io/OutputStream;", "outputStream", "toByteArray"})
public final class StreamCrypto {
    private static final java.lang.String INFO_STREAM_KEY = "stream key";
    private static final int SIZE_SEGMENT = 1048576;
    private static final byte TYPE_CHUNK = (byte)0;
    private static final byte TYPE_SNAPSHOT = (byte)1;
    @org.jetbrains.annotations.NotNull()
    public static final org.calyxos.backup.storage.crypto.StreamCrypto INSTANCE = null;
    
    @org.jetbrains.annotations.NotNull()
    public final byte[] deriveStreamKey(@org.jetbrains.annotations.NotNull()
    javax.crypto.SecretKey masterKey, @org.jetbrains.annotations.NotNull()
    byte[] info) throws java.security.GeneralSecurityException {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final byte[] getAssociatedDataForChunk$main(@org.jetbrains.annotations.NotNull()
    java.lang.String chunkId, byte version) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final byte[] getAssociatedDataForSnapshot$main(long timestamp, byte version) {
        return null;
    }
    
    /**
     * Returns a [AesGcmHkdfStreaming] encrypting stream
     * that gets encrypted with the given secret.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.io.OutputStream newEncryptingStream(@org.jetbrains.annotations.NotNull()
    byte[] secret, @org.jetbrains.annotations.NotNull()
    java.io.OutputStream outputStream, @org.jetbrains.annotations.NotNull()
    byte[] associatedData) throws java.io.IOException, java.security.GeneralSecurityException {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.io.InputStream newDecryptingStream(@org.jetbrains.annotations.NotNull()
    byte[] secret, @org.jetbrains.annotations.NotNull()
    java.io.InputStream inputStream, @org.jetbrains.annotations.NotNull()
    byte[] associatedData) throws java.io.IOException, java.security.GeneralSecurityException {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final byte[] toByteArray(long $this$toByteArray) {
        return null;
    }
    
    private StreamCrypto() {
        super();
    }
}