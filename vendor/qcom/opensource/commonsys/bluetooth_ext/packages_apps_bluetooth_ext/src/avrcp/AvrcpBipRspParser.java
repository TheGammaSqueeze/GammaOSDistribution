/*
 * Copyright (c) 2015-2016, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *           * Redistributions of source code must retain the above copyright
 *             notice, this list of conditions and the following disclaimer.
 *           * Redistributions in binary form must reproduce the above
 *           * copyright notice, this list of conditions and the following
 *             disclaimer in the documentation and/or other materials provided
 *             with the distribution.
 *           * Neither the name of The Linux Foundation nor the names of its
 *             contributors may be used to endorse or promote products derived
 *             from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

package com.android.bluetooth.avrcp;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.StringWriter;
import java.io.UnsupportedEncodingException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Objects;
import java.util.Random;

import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserException;
import org.xmlpull.v1.XmlPullParserFactory;
import org.xmlpull.v1.XmlSerializer;

import com.android.bluetooth.Utils;
import com.android.internal.util.FastXmlSerializer;

import android.content.ContentUris;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteException;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.graphics.ImageFormat;
import android.graphics.Rect;
import android.graphics.YuvImage;
import android.media.ExifInterface;
import android.media.MediaMetadata;
import android.net.Uri;
import android.os.Environment;
import android.os.ParcelFileDescriptor;
import android.provider.MediaStore;
import android.text.TextUtils;
import android.util.Log;
import android.util.Size;

public class AvrcpBipRspParser {
    private String TAG = "AvrcpBipParser";

    private final boolean D = true;
    private static final boolean V = AvrcpBipRsp.V;
    private Context mContext;
    private static final int COVER_ART_MAX_ITEMS = 12;
    private static Map<String, String> mArtHandleMap = new HashMap<String, String>();
    private static Map<String, AvrcpBipRspCoverArtAttributes> mCoverArtAttributesMap
            = new LinkedHashMap<String, AvrcpBipRspCoverArtAttributes>(
            0, 0.75f /* default load factor */, true);
    private int BIP_THUMB_WIDTH = 200;
    private int BIP_THUMB_HEIGHT = 200;
    private int MIN_SUPPORTED_WIDTH = 100;
    private int MIN_SUPPORTED_HEIGHT = 100;
    private int MAX_SUPPORTED_WIDTH = 1280;
    private int MAX_SUPPORTED_HEIGHT = 1080;
    private int MAX_IMG_HANDLE = 10000000;

    public AvrcpBipRspParser(Context context, String tag) {
        setTag(tag);
        mContext = context;
        if (!Utils.isPtsTestMode()) {
            mArtHandleMap.clear();
            mCoverArtAttributesMap.clear();
        }
    }

    private void setTag(String tag){
        try {
            TAG += "_" + tag.replaceAll(":","").substring(6,12);
        } catch (Exception e) {
            Log.w(TAG, "tag generation failed ", e);
        }
    }

    private class AvrcpBipRspCoverArtAttributes {
        private String mVersion = "1.0";
        private String mNativeEncoding = "";
        private String mNativePixel = "";
        private String mNativeSize = "";
        private int mWidth = 0;
        private int mHeight = 0;
        private Bitmap mBitMap = null;
        private String mTitle ="";

        public String getmTitle() {
            return mTitle;
        }

        public void setmTitle(String title) {
            this.mTitle = title;
       }

        public Bitmap getmBitMap() {
            return mBitMap;
        }

        public void setmBitMap(Bitmap mBitMap) {
            this.mBitMap = mBitMap;
        }

        public void setWidth(int width) {
            mWidth = width;
        }
        public void setHeight(int height) {
            mHeight = height;
        }
        public void setNativeEncoding(String nativeEncoding) {
            mNativeEncoding = nativeEncoding;
        }
        public void setNativePixel(String nativePixel) {
            mNativePixel = nativePixel;
        }
        public void setNativeSize(String nativeSize) {
            mNativeSize = nativeSize;
        }
        public int getWidth() {
            return mWidth;
        }
        public int getHeigth() {
            return mHeight;
        }
        public String getVersion() {
            return mVersion;
        }
        public String getNativeEncoding() {
            return mNativeEncoding;
        }
        public String getNativePixel() {
            return mNativePixel;
        }
        public String getNativeSize() {
            return mNativeSize;
        }
    };

    public String getImgHandle(MediaMetadata data) {
        long artHandle = -1;
        String imageHandle = "";
        if (data.containsKey(MediaMetadata.METADATA_KEY_ALBUM_ART)) {
            String title = data.getString(MediaMetadata.METADATA_KEY_TITLE);
            if (TextUtils.isEmpty(title)) {
                title = data.getString(MediaMetadata.METADATA_KEY_ALBUM_ARTIST);
                Log.w(TAG, " getImgHandle title " + title + " replaced with album Artist");
            }
            if (TextUtils.isEmpty(title)) {
                Log.w(TAG, " getImgHandle title Empty ");
                return "";
            }
            if (mArtHandleMap.containsKey(title)) {
                imageHandle = mArtHandleMap.get(title);
            } else {
                Bitmap tempBitmap = data.getBitmap(MediaMetadata.METADATA_KEY_ALBUM_ART);
                if (tempBitmap != null) {
                    /* Create a scaled version of the image for now, as consumers don't need
                       anything larger than this at the moment. */
                    Bitmap bitmap = Bitmap.createScaledBitmap(tempBitmap, BIP_THUMB_WIDTH,
                            BIP_THUMB_HEIGHT, false);
                    int w = bitmap.getWidth();
                    int h = bitmap.getHeight();
                    Random rnd = new Random();
                    int val = rnd.nextInt(MAX_IMG_HANDLE);
                    imageHandle = String.format("%07d", val);
                    AvrcpBipRspCoverArtAttributes coverArtAttributes = new
                            AvrcpBipRspCoverArtAttributes();
                    coverArtAttributes.setmBitMap(bitmap);
                    coverArtAttributes.setmTitle(title);
                    coverArtAttributes.setWidth(w);
                    coverArtAttributes.setHeight(h);
                    // DEFAULT encoding as JPEG
                    coverArtAttributes.setNativeEncoding("JPEG");
                    coverArtAttributes.setNativeSize(Integer.toString(bitmap.getByteCount()));
                    coverArtAttributes.setNativePixel(w + "*" + h);
                    mCoverArtAttributesMap.put(imageHandle, coverArtAttributes);
                    mArtHandleMap.put(title, imageHandle);
                    if (V)
                        Log.v(TAG, "getImgHandle imgHandle :" + imageHandle
                                + " title " + title + ", coverArtAttributes  "
                                + coverArtAttributes);
                    trimToSize();
                }
            }
        }
        return imageHandle;
    }

    String getImgHandle(String title) {
        return mArtHandleMap.containsKey(title) ?
                mArtHandleMap.get(title) : "";
    }

    /**
     * Get the cover artwork image bytes in the native format
     */
    public byte[] getImage(Bitmap bitmap) {
        if (bitmap == null) return null;
        byte[] bytes = null;
        ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
        bitmap.compress(Bitmap.CompressFormat.JPEG, 100, outputStream);
        bytes = outputStream.toByteArray();
        return bytes;
    }

    private class AvrcpBipRspImgDescriptor {
        public String mVersion;
        public String mEncoding;
        public String mPixel;
        public String mMaxSize;
        public String mTransformation;
        public static final String DEFAULT_VERSION = "1.0";
        private String DEFAULT_ENCODING = "JPEG";
        private String DEFAULT_PIXEL = "";

        private AvrcpBipRspImgDescriptor(HashMap<String, String> attrs) {
            mVersion = attrs.get("version");
            mEncoding = attrs.get("encoding");
            mPixel = attrs.get("pixel");
            mMaxSize = attrs.get("maxsize");
            mTransformation = attrs.get("transformation");
        }

        public AvrcpBipRspImgDescriptor() {
            mVersion = DEFAULT_VERSION;
            mEncoding = DEFAULT_ENCODING;
            mPixel = DEFAULT_PIXEL;
        }

        @Override
        public String toString() {
            return "AvrcpBipRspImgDescriptor [mVersion=" + mVersion + ", mEncoding="
                + mEncoding + ", mPixel=" + mPixel  + ", mMaxSize=" + mMaxSize
                + ", mTransformation=" + mTransformation + ", DEFAULT_ENCODING="
                + DEFAULT_ENCODING + ", DEFAULT_PIXEL=" + DEFAULT_PIXEL + "]";
        }
    };

    private AvrcpBipRspImgDescriptor parseImgDescXml(String imgDescXml) {
        AvrcpBipRspImgDescriptor ev = null;
        if (imgDescXml == null)
            return ev;
        try {
            InputStream is = new ByteArrayInputStream(imgDescXml.getBytes("UTF-8"));
            try {
                XmlPullParser imgDescParser = XmlPullParserFactory.newInstance().newPullParser();
                imgDescParser.setInput(is, "UTF-8");

                HashMap<String, String> attrs = new HashMap<String, String>();
                int event = imgDescParser.getEventType();
                while (event != XmlPullParser.END_DOCUMENT) {
                    switch (event) {
                        case XmlPullParser.START_TAG:
                            if (imgDescParser.getName().equals("image-descriptor")) {
                                if (V) Log.v(TAG, "image-descriptor version: " +
                                    imgDescParser.getAttributeValue(0));
                                attrs.put(imgDescParser.getAttributeName(0),
                                    imgDescParser.getAttributeValue(0));
                            }

                            if (imgDescParser.getName().equals("image")) {
                                for (int i = 0; i < imgDescParser.getAttributeCount(); i++) {
                                    attrs.put(imgDescParser.getAttributeName(i),
                                        imgDescParser.getAttributeValue(i));
                                    if (V) Log.v(TAG, "image " + imgDescParser.getAttributeName(i) +
                                        " " + imgDescParser.getAttributeValue(i));
                                }
                                ev = new AvrcpBipRspImgDescriptor(attrs);
                                // return immediately, only one event should be here
                                return ev;
                            }
                            break;
                    }

                    event = imgDescParser.next();
                }
                if (V) Log.v(TAG, "attrs " + attrs);

            } catch (XmlPullParserException | IOException | IllegalArgumentException e) {
                Log.e(TAG, "Error when parsing XML", e);
            }
        } catch (UnsupportedEncodingException e) {
            Log.e(TAG, "UnsupportedEncodingException", e);
        }
        if (V) Log.v(TAG, "parseImgDescXml returning " + ev);
        return ev;
    }

    private AvrcpBipRspImgDescriptor validateImgDescriptor(AvrcpBipRspImgDescriptor imgDesc) {
        int width = 0, height = 0;
        int minWidth = 0, minHeight = 0;
        int maxWidth = 0, maxHeigth = 0;
        AvrcpBipRspImgDescriptor imgDes = imgDesc;

        if (V) {
            Log.v(TAG, "validateImgDescriptor :" + imgDesc);
        } else {
            Log.d(TAG, "validateImgDescriptor ");
        }
        /* check if the pixel field is range or discrete */
        if ((imgDesc.mPixel.indexOf("-") == -1)) {
            /* Check if the pixel fields contains only 1 "*". */
            if ((imgDesc.mPixel.indexOf("*") == -1) ||
                (imgDesc.mPixel.indexOf("*") != imgDesc.mPixel.lastIndexOf("*"))) {
                Log.e(TAG, "validateImgDescriptor: pixel field is invalid: " +  imgDesc.mPixel);
                return null;
            }
            try {
                width = Integer.parseInt(imgDesc.mPixel.substring(
                        0, imgDesc.mPixel.indexOf("*")));
                height = Integer.parseInt(imgDesc.mPixel.substring(
                        imgDesc.mPixel.lastIndexOf("*") + 1));
                if ((width < MIN_SUPPORTED_WIDTH || width > MAX_SUPPORTED_WIDTH) ||
                    ((height < MIN_SUPPORTED_HEIGHT || height > MAX_SUPPORTED_HEIGHT))) {
                    Log.e(TAG, "validateImgDescriptor: pixel width or height is " +
                        "invalid: " +  imgDesc.mPixel);
                    return null;
                }
            } catch (NumberFormatException e) {
                Log.e(TAG, "exception while parsing pixel: " + imgDesc.mPixel);
                return null;
            }
        } else {
            /* check if the pixel range contains only single "-" */
            if (imgDesc.mPixel.indexOf("-") != imgDesc.mPixel.lastIndexOf("-")) {
                Log.e(TAG, "validateImgDescriptor: Invalid pixel range");
                return null;
            }
            /* Pixel is specified as range from client, parse it */
            /* Split the strings before and after "-" */
            String minRange = imgDesc.mPixel.substring(0, imgDesc.mPixel.indexOf("-"));
            String maxRange = imgDesc.mPixel.substring(imgDesc.mPixel.indexOf("-") + 1);
            if (D) Log.d(TAG, "minRange: " +  minRange + " maxRange: " + maxRange);
            try {
                minWidth = Integer.parseInt(minRange.substring(0,
                    minRange.indexOf("*")));
                minHeight = Integer.parseInt(minRange.substring(
                    minRange.lastIndexOf("*") + 1));
                maxWidth = Integer.parseInt(maxRange.substring(
                    0, maxRange.indexOf("*")));
                maxHeigth = Integer.parseInt(maxRange.substring(
                    maxRange.lastIndexOf("*") + 1));
                if ((maxWidth < minWidth || maxHeigth < minHeight)) {
                    Log.e(TAG, "validateImgDescriptor: Invalid pixel range: " + minRange + " - " +
                        maxRange);
                    return null;
                } else if ((maxWidth < MIN_SUPPORTED_WIDTH || minWidth > MAX_SUPPORTED_WIDTH) ||
                    ((maxHeigth < MIN_SUPPORTED_HEIGHT || minHeight > MAX_SUPPORTED_HEIGHT))) {
                    Log.e(TAG, "validateImgDescriptor: Invalid pixel range: " + minRange + " - " +
                        maxRange);
                    return null;
                } else if ((minWidth >= MIN_SUPPORTED_WIDTH) &&
                    (minHeight >= MIN_SUPPORTED_HEIGHT) && (maxWidth > MAX_SUPPORTED_WIDTH) &&
                    (maxHeigth > MAX_SUPPORTED_HEIGHT)) {
                    width = MAX_SUPPORTED_WIDTH;
                    height = MAX_SUPPORTED_HEIGHT;
                } else if ((minWidth < MIN_SUPPORTED_WIDTH) &&
                    (minHeight < MIN_SUPPORTED_HEIGHT) && (maxWidth >= MAX_SUPPORTED_WIDTH) &&
                    (maxHeigth >= MAX_SUPPORTED_HEIGHT)) {
                    width = MAX_SUPPORTED_WIDTH;
                    height = MAX_SUPPORTED_HEIGHT;
                } else if ((minWidth >= MIN_SUPPORTED_WIDTH) &&
                    (minHeight >= MIN_SUPPORTED_HEIGHT) && (maxWidth < MAX_SUPPORTED_WIDTH) &&
                    (maxHeigth < MAX_SUPPORTED_HEIGHT)) {
                    width = maxWidth;
                    height = maxHeigth;
                } else if ((minWidth < MIN_SUPPORTED_WIDTH) &&
                    (minHeight < MIN_SUPPORTED_HEIGHT) && (maxWidth <= MAX_SUPPORTED_WIDTH) &&
                    (maxHeigth <= MAX_SUPPORTED_HEIGHT)) {
                    width = maxWidth;
                    height = maxHeigth;
                } else {
                    Log.e(TAG, "validateImgDescriptor: Invalid pixel range: " + minRange + " - " +
                        maxRange);
                    return null;
                }
            } catch (NumberFormatException e) {
                Log.e(TAG, "exception while parsing pixel range: " + minRange + " - " +
                        maxRange);
                return null;
            }
        }
        if (imgDesc.mTransformation != null &&
            !((imgDesc.mTransformation.equals("stretch")) ||
            (imgDesc.mTransformation.equals("fill")) ||
            (imgDesc.mTransformation.equals("crop")))) {
            Log.e(TAG, "validateImgDescriptor: transformation is invalid: " +
                imgDesc.mTransformation);
            return null;
        }
        if (V) Log.v(TAG, "validateImgDescriptor: before imgDesc.mPixel = " + imgDesc.mPixel);
        /* Update the pixel value now */
        imgDes.mPixel = width + "*" + height;
        if (D) Log.d(TAG, "validateImgDescriptor: imgDesc.mPixel = " + imgDes.mPixel);
        return imgDes;
    }

    boolean getImgThumb(OutputStream out, String imgHandle, int maxChunkSize) {
        boolean retVal = false;
        AvrcpBipRspCoverArtAttributes artAttributes = mCoverArtAttributesMap.get(imgHandle);
        if (artAttributes == null) {
            Log.w(TAG, "getImgThumb: imageHandle =" +  imgHandle + " is not in hashmap");
            return false;
        }
        Bitmap bm = artAttributes.getmBitMap();
        if (bm != null) {
            try {
                byte[] bytes = getImage(bm);
                int bytesToWrite = 0;
                int bytesWritten  = 0;
                while (bytesWritten < bytes.length) {
                    bytesToWrite = Math.min(maxChunkSize, bytes.length - bytesWritten);
                    out.write(bytes, bytesWritten, bytesToWrite);
                    bytesWritten += bytesToWrite;
                }
                /* Flush the data to output stream */
                out.flush();
                retVal = true;
            } catch (Exception e) {
                Log.w(TAG, "Exception = " + e);
            } finally {
                try {
                    if (out != null) {
                        out.close();
                    }
                } catch (IOException e) {
                    Log.w(TAG, "Exception = " + e);
                }
            }
        }
        if (D) Log.d(TAG, "getImgThumb: returning " + retVal);
        return retVal;
    }

    boolean getImg(OutputStream out, String imgHandle,
                    String imgDescXmlString, int maxChunkSize) {
        boolean retVal = false;
        if (mCoverArtAttributesMap.get(imgHandle) == null) {
            Log.w(TAG, "getImg: imageHandle =" +  imgHandle + " is not found");
            return retVal;
        }
        if (V) Log.v(TAG,"Enter getImg " + imgDescXmlString);
        AvrcpBipRspImgDescriptor imgDesc = new AvrcpBipRspImgDescriptor();
        if (imgDescXmlString != null) {
            /* As per SPEC, image-descriptor can be empty */
            if (!(imgDescXmlString.equals(""))) {
                imgDesc = parseImgDescXml(imgDescXmlString);
                if (imgDesc == null) {
                    Log.w(TAG, " getImg imgDesc null");
                    return retVal;
                }
                if (!(imgDesc.mVersion.equals(AvrcpBipRspImgDescriptor.DEFAULT_VERSION) &&
                    imgDesc.mEncoding != null && imgDesc.mPixel != null)) {
                    Log.w(TAG, " getImg imgDesc not valid :" + imgDesc);
                    return retVal;
                }
            }
        }
        int width;
        int height;
        if (V) Log.v(TAG,"getImg: imgDesc.mPixel = " + imgDesc.mPixel);
        if (imgDesc.mPixel.equals("")) {
            // remote device is willing to accept any pixel values, send
            // the default pixels of image
            width = mCoverArtAttributesMap.get(imgHandle).getWidth();
            height = mCoverArtAttributesMap.get(imgHandle).getHeigth();
        } else {
            imgDesc = validateImgDescriptor(imgDesc);
            if (imgDesc != null) {
                try {
                    //Get Width and Height from Image Descriptor Object
                    width = Integer.parseInt(imgDesc.mPixel.substring(
                            0, imgDesc.mPixel.indexOf("*")));
                    height = Integer.parseInt(imgDesc.mPixel.substring(
                            imgDesc.mPixel.lastIndexOf("*") + 1));
                } catch (NumberFormatException e) {
                    Log.e(TAG, "exception while parsing pixel");
                    return retVal;
                }
            } else {
                /* Image descriptor cannot be parsed to valid fields */
                Log.e(TAG,"getImg: imgDesc is not valid!!");
                return retVal;
            }
        }
        if (D) Log.d(TAG,"getImg: imgHandle = " + imgHandle + " width = "
            + width + " height = " + height + " encoding = " +
                imgDesc.mEncoding);
        if (!imgDesc.mEncoding.equals("") && !imgDesc.mEncoding.toUpperCase().equals("JPEG")) {
            Log.w(TAG," Invalid Encoding ");
            return retVal;
        }

        Bitmap bm = getScaledBitmap(mCoverArtAttributesMap.get(imgHandle).getmBitMap(),
                width, height);
        if (bm != null) {
            try {
                byte[] bytes = getImage(bm);
                int bytesToWrite = 0;
                int bytesWritten  = 0;
                while (bytesWritten < bytes.length) {
                    bytesToWrite = Math.min(maxChunkSize, bytes.length - bytesWritten);
                    out.write(bytes, bytesWritten, bytesToWrite);
                    bytesWritten += bytesToWrite;
                }
                /* Flush the data to output stream */
                out.flush();
                retVal = true;
            } catch (Exception e) {
                Log.e(TAG, "Exception = " + e);
                e.printStackTrace();
            } finally {
                try {
                    if (out != null) {
                        out.close();
                    }
                } catch (IOException e) {
                    Log.e(TAG, "Exception = " + e);
                }
            }
        }
        if (V) Log.v(TAG,"getImg: returning " + retVal);
        return retVal;
    }

    boolean isImgHandleValid(String imgHandle) {
        return mArtHandleMap.containsValue(imgHandle) ? true : false;
    }

    /* Encode the Image Properties into the StringBuilder reference.
     * */
    byte[] encode(String imgHandle)
            throws IllegalArgumentException, IllegalStateException, IOException
    {
        AvrcpBipRspCoverArtAttributes artAttributes = mCoverArtAttributesMap.get(imgHandle);
        /* Check if we have the image handle in map, if not return null */
        if (artAttributes == null) {
            Log.w(TAG, "encode: imageHandle =" +  imgHandle + " is not in hashmap");
            return null;
        }
        StringWriter sw = new StringWriter();
        XmlSerializer xmlMsgElement = new FastXmlSerializer();
        // construct the XML tag for a single msg in the msglisting
        try {
            xmlMsgElement.setOutput(sw);
            xmlMsgElement.startDocument("UTF-8", true);
            xmlMsgElement.setFeature("http://xmlpull.org/v1/doc/features.html#indent-output", true);
            xmlMsgElement.startTag(null, "image-properties");
            xmlMsgElement.attribute(null, "version", artAttributes.getVersion());
            xmlMsgElement.attribute(null, "handle", imgHandle);
            xmlMsgElement.startTag(null, "native");
            xmlMsgElement.attribute(null, "encoding", artAttributes.getNativeEncoding());
            xmlMsgElement.attribute(null, "pixel", artAttributes.getNativePixel());
            xmlMsgElement.attribute(null, "size", artAttributes.getNativeSize());
            xmlMsgElement.endTag(null, "native");
            xmlMsgElement.startTag(null, "variant");
            xmlMsgElement.attribute(null, "encoding", "JPEG");
            xmlMsgElement.attribute(null, "pixel", MIN_SUPPORTED_WIDTH + "*" + MIN_SUPPORTED_WIDTH +
                "-" + MAX_SUPPORTED_WIDTH + "*" + MAX_SUPPORTED_HEIGHT);
            xmlMsgElement.endTag(null, "variant");
            xmlMsgElement.startTag(null, "variant");
            xmlMsgElement.attribute(null, "encoding", "PNG");
            xmlMsgElement.attribute(null, "pixel", MIN_SUPPORTED_WIDTH + "*" + MIN_SUPPORTED_WIDTH +
                "-" + MAX_SUPPORTED_WIDTH + "*" + MAX_SUPPORTED_HEIGHT);
            xmlMsgElement.endTag(null, "variant");
            xmlMsgElement.endTag(null, "image-properties");
            xmlMsgElement.endDocument();
        } catch (IllegalArgumentException | IllegalStateException | IOException e) {
            Log.w(TAG, "encode :" + e);
        }
        if (V) Log.v(TAG, "Image properties XML = " + sw.toString());
        return sw.toString().getBytes("UTF-8");
    }

    /**
     * Covert a Bitmap to a byte array with an image format without lossy compression
     */
    private byte[] toByteArray(Bitmap bitmap) {
        if (bitmap == null) return null;
        ByteArrayOutputStream buffer = new ByteArrayOutputStream(
                    bitmap.getWidth() * bitmap.getHeight());
        bitmap.compress(Bitmap.CompressFormat.PNG, 100, buffer);
        return buffer.toByteArray();
    }

    private void trimToSize() {
        while (mArtHandleMap.size() > COVER_ART_MAX_ITEMS) {
            Map.Entry<String, String> entry = mArtHandleMap.entrySet().iterator().next();
            String imageHandle = entry.getKey();
            String val = entry.getValue();
            if (D) Log.d(TAG, "trimToSize Evicting " + imageHandle + " -> " + val);
            mArtHandleMap.remove(imageHandle);
            mCoverArtAttributesMap.remove(val);
        }
    }

    private Bitmap getScaledBitmap(Bitmap bip, int w, int h) {
        if (bip != null) {
            if (bip.getWidth() != w || bip.getHeight() != h) {
                return Bitmap.createScaledBitmap(bip, w, h, true);
            } else {
                return bip;
            }
        } else {
            return null;
        }
    }

    /**
    * Get the cover artwork image bytes as a 200 x 200 JPEG thumbnail
    */
    public byte[] getThumbnail(Bitmap bitmap) {
        if (bitmap == null) return null;
        byte[] bytes = null;
        ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
        bitmap.compress(Bitmap.CompressFormat.JPEG, 100, outputStream);
        bytes = outputStream.toByteArray();
        return bytes;
    }
}
