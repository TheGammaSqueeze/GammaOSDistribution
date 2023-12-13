/* GENERATED SOURCE. DO NOT MODIFY. */
package com.android.org.bouncycastle.jcajce.provider.symmetric.util;

import java.util.concurrent.atomic.AtomicBoolean;

import javax.crypto.interfaces.PBEKey;
import javax.crypto.spec.PBEKeySpec;
import javax.security.auth.Destroyable;

import com.android.org.bouncycastle.asn1.ASN1ObjectIdentifier;
import com.android.org.bouncycastle.crypto.CipherParameters;
import com.android.org.bouncycastle.crypto.PBEParametersGenerator;
import com.android.org.bouncycastle.crypto.params.KeyParameter;
import com.android.org.bouncycastle.crypto.params.ParametersWithIV;
import com.android.org.bouncycastle.util.Arrays;

/**
 * @hide This class is not part of the Android public SDK API
 */
public class BCPBEKey
    implements PBEKey, Destroyable
{
    private final AtomicBoolean hasBeenDestroyed = new AtomicBoolean(false);

    String              algorithm;
    ASN1ObjectIdentifier oid;
    int                 type;
    int                 digest;
    int                 keySize;
    int                 ivSize;

    private final char[] password;
    private final byte[] salt;
    private final int iterationCount;

    private final CipherParameters    param;

    boolean             tryWrong = false;

    /**
     * @param param
     */
    public BCPBEKey(
        String algorithm,
        ASN1ObjectIdentifier oid,
        int type,
        int digest,
        int keySize,
        int ivSize,
        PBEKeySpec pbeKeySpec,
        CipherParameters param)
    {
        this.algorithm = algorithm;
        this.oid = oid;
        this.type = type;
        this.digest = digest;
        this.keySize = keySize;
        this.ivSize = ivSize;
        this.password = pbeKeySpec.getPassword();
        this.iterationCount = pbeKeySpec.getIterationCount();
        this.salt = pbeKeySpec.getSalt();
        this.param = param;
    }

    public BCPBEKey(String algName, CipherParameters param)
    {
        this.algorithm = algName;
        this.param = param;
        this.password = null;
        this.iterationCount = -1;
        this.salt = null;
    }

    public String getAlgorithm()
    {
        checkDestroyed(this);

        return algorithm;
    }

    public String getFormat()
    {
        return "RAW";
    }

    public byte[] getEncoded()
    {
        checkDestroyed(this);

        if (param != null)
        {
            KeyParameter    kParam;
            
            if (param instanceof ParametersWithIV)
            {
                kParam = (KeyParameter)((ParametersWithIV)param).getParameters();
            }
            else
            {
                kParam = (KeyParameter)param;
            }
            
            return kParam.getKey();
        }
        else
        {
            if (type == PBE.PKCS12)
            {
                return PBEParametersGenerator.PKCS12PasswordToBytes(password);
            }
            else if (type == PBE.PKCS5S2_UTF8)
            {
                return PBEParametersGenerator.PKCS5PasswordToUTF8Bytes(password);
            }
            else
            {   
                return PBEParametersGenerator.PKCS5PasswordToBytes(password);
            }
        }
    }
    
    int getType()
    {
        checkDestroyed(this);

        return type;
    }
    
    int getDigest()
    {
        checkDestroyed(this);

        return digest;
    }
    
    int getKeySize()
    {
        checkDestroyed(this);

        return keySize;
    }
    
    public int getIvSize()
    {
        checkDestroyed(this);

        return ivSize;
    }
    
    public CipherParameters getParam()
    {
        checkDestroyed(this);

        return param;
    }

    /* (non-Javadoc)
     * @see javax.crypto.interfaces.PBEKey#getPassword()
     */
    public char[] getPassword()
    {
        checkDestroyed(this);

        if (password == null)
        {
            throw new IllegalStateException("no password available");
        }

        return Arrays.clone(password);
    }

    /* (non-Javadoc)
     * @see javax.crypto.interfaces.PBEKey#getSalt()
     */
    public byte[] getSalt()
    {
        checkDestroyed(this);

        return Arrays.clone(salt);
    }

    /* (non-Javadoc)
     * @see javax.crypto.interfaces.PBEKey#getIterationCount()
     */
    public int getIterationCount()
    {
        checkDestroyed(this);

        return iterationCount;
    }
    
    public ASN1ObjectIdentifier getOID()
    {
        checkDestroyed(this);

        return oid;
    }
    
    public void setTryWrongPKCS12Zero(boolean tryWrong)
    {
        this.tryWrong = tryWrong; 
    }
    
    boolean shouldTryWrongPKCS12()
    {
        return tryWrong;
    }

    public void destroy()
    {
        if (!hasBeenDestroyed.getAndSet(true))
        {
            if (password != null)
            {
                Arrays.fill(password, (char)0);
            }
            if (salt != null)
            {
                Arrays.fill(salt, (byte)0);
            }
        }
    }

    public boolean isDestroyed()
    {
        return hasBeenDestroyed.get();
    }

    static void checkDestroyed(Destroyable destroyable)
    {
        if (destroyable.isDestroyed())
        {
            throw new IllegalStateException("key has been destroyed");
        }
    }
}
