package com.android.permissioncontroller.permission.data;

import android.app.Application;
import android.content.pm.PackageManager.NameNotFoundException;
import android.os.UserHandle;
import android.util.Log;
import com.android.permissioncontroller.PermissionControllerApplication;
import org.xmlpull.v1.XmlPullParser;
import java.io.FileNotFoundException;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\n\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0006\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0003\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0004\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0005\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0006\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0007\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"ANDROID_NS", "", "ATTRIBUTION_TAG", "LABEL_ATTR", "MANIFEST_FILE_NAME", "MANIFEST_TAG", "PKG_ATTR", "TAG_ATTR"})
public final class AttributionLabelLiveDataKt {
    private static final java.lang.String MANIFEST_FILE_NAME = "AndroidManifest.xml";
    private static final java.lang.String MANIFEST_TAG = "manifest";
    private static final java.lang.String PKG_ATTR = "package";
    private static final java.lang.String ATTRIBUTION_TAG = "attribution";
    private static final java.lang.String ANDROID_NS = "http://schemas.android.com/apk/res/android";
    private static final java.lang.String TAG_ATTR = "tag";
    private static final java.lang.String LABEL_ATTR = "label";
}