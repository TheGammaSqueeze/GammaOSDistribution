package com.android.wm.shell.bubbles.storage;

import android.os.UserHandle;
import android.util.SparseArray;
import android.util.Xml;
import com.android.internal.util.FastXmlSerializer;
import com.android.internal.util.XmlUtils;
import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlSerializer;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.StandardCharsets;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000B\n\u0000\n\u0002\u0010\u000e\n\u0002\b\n\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\u001a\u001a\u0010\u000f\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00120\u00110\u00102\u0006\u0010\u0013\u001a\u00020\u0014\u001a\u0012\u0010\u0015\u001a\u0004\u0018\u00010\u00122\u0006\u0010\u0016\u001a\u00020\u0017H\u0002\u001a\"\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u0013\u001a\u00020\u001a2\u0012\u0010\u001b\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00120\u00110\u0010\u001a\u0018\u0010\u001c\u001a\u00020\u00192\u0006\u0010\u001d\u001a\u00020\u001e2\u0006\u0010\u001f\u001a\u00020\u0012H\u0002\u001a\u0016\u0010 \u001a\u0004\u0018\u00010\u0001*\u00020\u00172\u0006\u0010!\u001a\u00020\u0001H\u0002\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0003\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0004\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0005\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0006\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0007\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\b\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\t\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\n\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u000b\u001a\u00020\fX\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\r\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u000e\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"ATTR_DESIRED_HEIGHT", "", "ATTR_DESIRED_HEIGHT_RES_ID", "ATTR_KEY", "ATTR_LOCUS", "ATTR_PACKAGE", "ATTR_SHORTCUT_ID", "ATTR_TASK_ID", "ATTR_TITLE", "ATTR_USER_ID", "ATTR_VERSION", "CURRENT_VERSION", "", "TAG_BUBBLE", "TAG_BUBBLES", "readXml", "Landroid/util/SparseArray;", "", "Lcom/android/wm/shell/bubbles/storage/BubbleEntity;", "stream", "Ljava/io/InputStream;", "readXmlEntry", "parser", "Lorg/xmlpull/v1/XmlPullParser;", "writeXml", "", "Ljava/io/OutputStream;", "bubbles", "writeXmlEntry", "serializer", "Lorg/xmlpull/v1/XmlSerializer;", "bubble", "getAttributeWithName", "name"})
public final class BubbleXmlHelperKt {
    private static final int CURRENT_VERSION = 2;
    private static final java.lang.String TAG_BUBBLES = "bs";
    private static final java.lang.String ATTR_VERSION = "v";
    private static final java.lang.String TAG_BUBBLE = "bb";
    private static final java.lang.String ATTR_USER_ID = "uid";
    private static final java.lang.String ATTR_PACKAGE = "pkg";
    private static final java.lang.String ATTR_SHORTCUT_ID = "sid";
    private static final java.lang.String ATTR_KEY = "key";
    private static final java.lang.String ATTR_DESIRED_HEIGHT = "h";
    private static final java.lang.String ATTR_DESIRED_HEIGHT_RES_ID = "hid";
    private static final java.lang.String ATTR_TITLE = "t";
    private static final java.lang.String ATTR_TASK_ID = "tid";
    private static final java.lang.String ATTR_LOCUS = "l";
    
    /**
     * Writes the bubbles in xml format into given output stream.
     */
    public static final void writeXml(@org.jetbrains.annotations.NotNull()
    java.io.OutputStream stream, @org.jetbrains.annotations.NotNull()
    android.util.SparseArray<java.util.List<com.android.wm.shell.bubbles.storage.BubbleEntity>> bubbles) {
    }
    
    /**
     * Creates a xml entry for given bubble in following format:
     * ```
     * <bb uid="0" pkg="com.example.messenger" sid="my-shortcut" key="my-key" />
     * ```
     */
    private static final void writeXmlEntry(org.xmlpull.v1.XmlSerializer serializer, com.android.wm.shell.bubbles.storage.BubbleEntity bubble) {
    }
    
    /**
     * Reads the bubbles from xml file.
     */
    @org.jetbrains.annotations.NotNull()
    public static final android.util.SparseArray<java.util.List<com.android.wm.shell.bubbles.storage.BubbleEntity>> readXml(@org.jetbrains.annotations.NotNull()
    java.io.InputStream stream) {
        return null;
    }
    
    private static final com.android.wm.shell.bubbles.storage.BubbleEntity readXmlEntry(org.xmlpull.v1.XmlPullParser parser) {
        return null;
    }
    
    private static final java.lang.String getAttributeWithName(org.xmlpull.v1.XmlPullParser $this$getAttributeWithName, java.lang.String name) {
        return null;
    }
}