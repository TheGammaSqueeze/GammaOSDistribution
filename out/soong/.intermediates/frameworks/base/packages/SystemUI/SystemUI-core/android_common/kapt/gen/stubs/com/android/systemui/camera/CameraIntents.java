package com.android.systemui.camera;

import android.content.Context;
import android.content.Intent;
import android.provider.MediaStore;
import android.text.TextUtils;
import com.android.systemui.R;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\f\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\u0018\u0000 \u00032\u00020\u0001:\u0001\u0003B\u0005\u00a2\u0006\u0002\u0010\u0002"}, d2 = {"Lcom/android/systemui/camera/CameraIntents;", "", "()V", "Companion"})
public final class CameraIntents {
    @org.jetbrains.annotations.NotNull()
    private static final java.lang.String DEFAULT_SECURE_CAMERA_INTENT_ACTION = "android.media.action.STILL_IMAGE_CAMERA_SECURE";
    @org.jetbrains.annotations.NotNull()
    private static final java.lang.String DEFAULT_INSECURE_CAMERA_INTENT_ACTION = "android.media.action.STILL_IMAGE_CAMERA";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.camera.CameraIntents.Companion Companion = null;
    
    public CameraIntents() {
        super();
    }
    
    @org.jetbrains.annotations.Nullable()
    public static final java.lang.String getOverrideCameraPackage(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public static final android.content.Intent getInsecureCameraIntent(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public static final android.content.Intent getSecureCameraIntent(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return null;
    }
    
    public static final boolean isSecureCameraIntent(@org.jetbrains.annotations.Nullable()
    android.content.Intent intent) {
        return false;
    }
    
    public static final boolean isInsecureCameraIntent(@org.jetbrains.annotations.Nullable()
    android.content.Intent intent) {
        return false;
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\fH\u0007J\u0012\u0010\r\u001a\u0004\u0018\u00010\u00042\u0006\u0010\u000b\u001a\u00020\fH\u0007J\u0010\u0010\u000e\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\fH\u0007J\u0012\u0010\u000f\u001a\u00020\u00102\b\u0010\u0011\u001a\u0004\u0018\u00010\nH\u0007J\u0012\u0010\u0012\u001a\u00020\u00102\b\u0010\u0011\u001a\u0004\u0018\u00010\nH\u0007R\u0014\u0010\u0003\u001a\u00020\u0004X\u0086D\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006R\u0014\u0010\u0007\u001a\u00020\u0004X\u0086D\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\u0006"}, d2 = {"Lcom/android/systemui/camera/CameraIntents$Companion;", "", "()V", "DEFAULT_INSECURE_CAMERA_INTENT_ACTION", "", "getDEFAULT_INSECURE_CAMERA_INTENT_ACTION", "()Ljava/lang/String;", "DEFAULT_SECURE_CAMERA_INTENT_ACTION", "getDEFAULT_SECURE_CAMERA_INTENT_ACTION", "getInsecureCameraIntent", "Landroid/content/Intent;", "context", "Landroid/content/Context;", "getOverrideCameraPackage", "getSecureCameraIntent", "isInsecureCameraIntent", "", "intent", "isSecureCameraIntent"})
    public static final class Companion {
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getDEFAULT_SECURE_CAMERA_INTENT_ACTION() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getDEFAULT_INSECURE_CAMERA_INTENT_ACTION() {
            return null;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final java.lang.String getOverrideCameraPackage(@org.jetbrains.annotations.NotNull()
        android.content.Context context) {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.content.Intent getInsecureCameraIntent(@org.jetbrains.annotations.NotNull()
        android.content.Context context) {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.content.Intent getSecureCameraIntent(@org.jetbrains.annotations.NotNull()
        android.content.Context context) {
            return null;
        }
        
        public final boolean isSecureCameraIntent(@org.jetbrains.annotations.Nullable()
        android.content.Intent intent) {
            return false;
        }
        
        public final boolean isInsecureCameraIntent(@org.jetbrains.annotations.Nullable()
        android.content.Intent intent) {
            return false;
        }
        
        private Companion() {
            super();
        }
    }
}