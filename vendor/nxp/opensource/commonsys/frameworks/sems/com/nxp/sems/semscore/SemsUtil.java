/*
 * Copyright 2019 NXP
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.nxp.sems;

import android.util.Log;
import java.io.ByteArrayOutputStream;
import java.io.UnsupportedEncodingException;
import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;

public class SemsUtil {
  private static char HEXCHARS[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                                    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

  public static final String toHexString(byte b) {
    StringBuffer sb = new StringBuffer(2);
    sb.append(HEXCHARS[(b >> 4) & 0xF]);
    sb.append(HEXCHARS[b & 0xF]);
    return sb.toString();
  }

  public static final byte[] toByteArray(BigInteger bi, int length) {
    byte[] b = bi.toByteArray();

    if (b.length > length) {
      return Arrays.copyOfRange(b, b.length - length, b.length);
    }

    if (b.length < length) {
      byte[] a = new byte[length];
      System.arraycopy(b, 0, a, length - b.length, b.length);
      return a;
    }

    return b;
  }

  public static final String toHexString(BigInteger bi, int length) {
    return toHexString(toByteArray(bi, length));
  }

  public static final String toHexString(byte[] a) {
    StringBuffer sb = new StringBuffer(2 * a.length);
    for (byte b : a) {
      sb.append(HEXCHARS[(b >> 4) & 0xF]);
      sb.append(HEXCHARS[b & 0xF]);
    }
    return sb.toString();
  }

  public static byte[] parseHexString(String s) {
    try {
      ByteArrayOutputStream out = new ByteArrayOutputStream();

      while (!s.isEmpty()) {
        out.write(Integer.parseInt(s.substring(0, 2), 16));
        s = s.substring(2);
      }

      return out.toByteArray();
    } catch (Exception e) {
      return null;
    }
  }

  public static byte[] SHA1(byte[] in) {
    MessageDigest sha1 = null;
    try {
      sha1 = MessageDigest.getInstance("SHA1");
    } catch (Exception e) {
      System.err.println("SHA-1 not supported");
      System.exit(1);
    }
    sha1.reset();
    sha1.update(in);
    return sha1.digest();
  }

  public static byte[] toUTF8(String s) {
    if (s != null) {
      try {
        return s.getBytes("UTF-8");
      } catch (UnsupportedEncodingException e) {
        // Should never occur!
      }
    }

    return null;
  }

  public static String fromUTF8(byte[] a) {
    if (a != null) {
      try {
        return new String(a, "UTF-8");
      } catch (UnsupportedEncodingException e) {
        return "UnsupportedEncodingException";
      }
    }

    return null;
  }

  public static String toHexString(byte[] buffer, int offset, int length) {
    if (length <= 0) {
      return new String("No Data : length < = 0");
    } else {
      final char[] HEX_CHARS = "0123456789abcdef".toCharArray();
      char[] chars = new char[3 * length];
      for (int j = offset; j < offset + length; ++j) {
        chars[3 * (j - offset)] = HEX_CHARS[(buffer[j] & 0xF0) >>> 4];
        chars[3 * (j - offset) + 1] = HEX_CHARS[buffer[j] & 0x0F];
        chars[3 * (j - offset) + 2] = ' ';
      }
      return new String(chars);
    }
  }
  public static String bytArrayToHex(byte[] a) {
    StringBuilder sb = new StringBuilder();
    for (byte b : a)
      sb.append(String.format("%02X", b & 0xff));
    return sb.toString();
  }
  public static byte[] append(byte[] a, byte[] b) {
    byte[] result = new byte[a.length + b.length];
    System.arraycopy(a, 0, result, 0, a.length);
    System.arraycopy(b, 0, result, a.length, b.length);
    return result;
  }

  public static byte[] extract(byte[] buffer, int offset, int length) {
    byte[] result = new byte[length];
    System.arraycopy(buffer, offset, result, 0, length);
    return result;
  }

  public static boolean compare(byte[] a, byte[] b) {
    if (a == b)
      return true;
    if ((a == null) || (b == null))
      return false;
    if (a.length != b.length)
      return false;
    for (int i = 0; i < a.length; i++) {
      if (a[i] != b[i])
        return false;
    }
    return true;
  }

  public static byte[] makeCAPDU(int cla, int ins, int p1, int p2,
                                 byte[] cdata) {
    if (cdata == null) {
      return new byte[] {(byte)cla, (byte)ins, (byte)p1, (byte)p2, 0};
    } else {
      return append(new byte[] {(byte)cla, (byte)ins, (byte)p1, (byte)p2,
                                (byte)cdata.length},
                    cdata);
    }
  }

  public static final short SW_NO_ERROR = (short)0x9000;
  public static final short SW_FILE_NOT_FOUND = (short)0x6A82;

  public static short getSW(byte[] rapdu) {
    byte sw1 = rapdu[rapdu.length - 2];
    byte sw2 = rapdu[rapdu.length - 1];
    return (short)((sw1 << 8) + (sw2 & 0xFF));
  }

  public static byte[] getRDATA(byte[] rapdu) {
    return extract(rapdu, 0, rapdu.length - 2);
  }
}
