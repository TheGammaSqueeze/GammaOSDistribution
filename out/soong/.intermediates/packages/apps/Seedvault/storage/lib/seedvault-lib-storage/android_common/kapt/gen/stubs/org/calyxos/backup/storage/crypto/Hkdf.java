package org.calyxos.backup.storage.crypto;

import java.nio.ByteBuffer;
import java.security.GeneralSecurityException;
import javax.crypto.Mac;
import javax.crypto.SecretKey;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u0012\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u00c0\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\'\u0010\b\u001a\u00020\t2\u0006\u0010\n\u001a\u00020\u000b2\b\u0010\f\u001a\u0004\u0018\u00010\t2\u0006\u0010\r\u001a\u00020\u0006H\u0000\u00a2\u0006\u0002\b\u000eR\u000e\u0010\u0003\u001a\u00020\u0004X\u0080T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0006X\u0080T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/crypto/Hkdf;", "", "()V", "ALGORITHM_HMAC", "", "KEY_SIZE", "", "KEY_SIZE_BYTES", "expand", "", "secretKey", "Ljavax/crypto/SecretKey;", "info", "outLengthBytes", "expand$main"})
public final class Hkdf {
    private static final int KEY_SIZE = 256;
    public static final int KEY_SIZE_BYTES = 32;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String ALGORITHM_HMAC = "HmacSHA256";
    @org.jetbrains.annotations.NotNull()
    public static final org.calyxos.backup.storage.crypto.Hkdf INSTANCE = null;
    
    /**
     * Step 2 of RFC 5869.
     *
     * Based on the Apache2 licensed HKDF library by Patrick Favre-Bulle.
     * Link: https://github.com/patrickfav/hkdf
     *
     * @param secretKey a pseudorandom key of at least hmac hash length in bytes (usually, the output from the extract step)
     * @param info            optional context and application specific information; may be null
     * @param outLengthBytes  length of output keying material in bytes (must be <= 255 * mac hash length)
     * @return new byte array of output keying material (OKM)
     */
    @org.jetbrains.annotations.NotNull()
    public final byte[] expand$main(@org.jetbrains.annotations.NotNull()
    javax.crypto.SecretKey secretKey, @org.jetbrains.annotations.Nullable()
    byte[] info, int outLengthBytes) throws java.security.GeneralSecurityException {
        return null;
    }
    
    private Hkdf() {
        super();
    }
}