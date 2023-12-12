package com.android.systemui.privacy;

import android.content.Context;
import android.graphics.drawable.LayerDrawable;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowInsets;
import android.widget.ImageView;
import android.widget.TextView;
import com.android.settingslib.Utils;
import com.android.systemui.R;
import com.android.systemui.statusbar.phone.SystemUIDialog;
import java.lang.ref.WeakReference;
import java.util.concurrent.atomic.AtomicBoolean;

/**
 * Dialog to show ongoing and recent app ops usage.
 *
 * @see PrivacyDialogController
 * @param context A context to create the dialog
 * @param list list of elements to show in the dialog. The elements will show in the same order they
 *            appear in the list
 * @param activityStarter a callback to start an activity for a given package name and user id
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000x\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0010\b\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u00002\u00020\u0001:\u0002+,B5\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\f\u0010\u0004\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005\u0012\u0018\u0010\u0007\u001a\u0014\u0012\u0004\u0012\u00020\t\u0012\u0004\u0012\u00020\n\u0012\u0004\u0012\u00020\u000b0\b\u00a2\u0006\u0002\u0010\fJ\u000e\u0010\u001b\u001a\u00020\u000b2\u0006\u0010\u001c\u001a\u00020\u0012J\u0010\u0010\u001d\u001a\u00020\u001e2\u0006\u0010\u001f\u001a\u00020\u0006H\u0002J\u0010\u0010 \u001a\u00020!2\u0006\u0010\"\u001a\u00020#H\u0002J\u0010\u0010$\u001a\u00020\n2\u0006\u0010%\u001a\u00020&H\u0002J\u0012\u0010\'\u001a\u00020\u000b2\b\u0010(\u001a\u0004\u0018\u00010)H\u0014J\b\u0010*\u001a\u00020\u000bH\u0014R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u000f\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00120\u00110\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0015\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0016\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0004\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0017\u001a\n \u0018*\u0004\u0018\u00010\t0\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0019\u001a\u00020\u001aX\u0082.\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/privacy/PrivacyDialog;", "Lcom/android/systemui/statusbar/phone/SystemUIDialog;", "context", "Landroid/content/Context;", "list", "", "Lcom/android/systemui/privacy/PrivacyDialog$PrivacyElement;", "activityStarter", "Lkotlin/Function2;", "", "", "", "(Landroid/content/Context;Ljava/util/List;Lkotlin/jvm/functions/Function2;)V", "clickListener", "Landroid/view/View$OnClickListener;", "dismissListeners", "", "Ljava/lang/ref/WeakReference;", "Lcom/android/systemui/privacy/PrivacyDialog$OnDialogDismissed;", "dismissed", "Ljava/util/concurrent/atomic/AtomicBoolean;", "enterpriseText", "iconColorSolid", "phonecall", "kotlin.jvm.PlatformType", "rootView", "Landroid/view/ViewGroup;", "addOnDismissListener", "listener", "createView", "Landroid/view/View;", "element", "getDrawableForType", "Landroid/graphics/drawable/LayerDrawable;", "type", "Lcom/android/systemui/privacy/PrivacyType;", "getStringIdForState", "active", "", "onCreate", "savedInstanceState", "Landroid/os/Bundle;", "onStop", "OnDialogDismissed", "PrivacyElement"})
public final class PrivacyDialog extends com.android.systemui.statusbar.phone.SystemUIDialog {
    private final java.util.List<java.lang.ref.WeakReference<com.android.systemui.privacy.PrivacyDialog.OnDialogDismissed>> dismissListeners = null;
    private final java.util.concurrent.atomic.AtomicBoolean dismissed = null;
    private final int iconColorSolid = 0;
    private final java.lang.String enterpriseText = null;
    private final java.lang.String phonecall = null;
    private android.view.ViewGroup rootView;
    private final android.view.View.OnClickListener clickListener = null;
    private final java.util.List<com.android.systemui.privacy.PrivacyDialog.PrivacyElement> list = null;
    
    @java.lang.Override()
    protected void onCreate(@org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState) {
    }
    
    /**
     * Add a listener that will be called when the dialog is dismissed.
     *
     * If the dialog has already been dismissed, the listener will be called immediately, in the
     * same thread.
     */
    public final void addOnDismissListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.privacy.PrivacyDialog.OnDialogDismissed listener) {
    }
    
    @java.lang.Override()
    protected void onStop() {
    }
    
    private final android.view.View createView(com.android.systemui.privacy.PrivacyDialog.PrivacyElement element) {
        return null;
    }
    
    private final int getStringIdForState(boolean active) {
        return 0;
    }
    
    private final android.graphics.drawable.LayerDrawable getDrawableForType(com.android.systemui.privacy.PrivacyType type) {
        return null;
    }
    
    public PrivacyDialog(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.privacy.PrivacyDialog.PrivacyElement> list, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function2<? super java.lang.String, ? super java.lang.Integer, kotlin.Unit> activityStarter) {
        super(null);
    }
    
    /**
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\r\n\u0002\b\u0002\n\u0002\u0010\t\n\u0000\n\u0002\u0010\u000b\n\u0002\b\t\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0018\b\u0086\b\u0018\u00002\u00020\u0001BO\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\b\u0010\n\u001a\u0004\u0018\u00010\t\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\r\u001a\u00020\u000e\u0012\u0006\u0010\u000f\u001a\u00020\u000e\u0012\u0006\u0010\u0010\u001a\u00020\u000e\u00a2\u0006\u0002\u0010\u0011J\t\u0010$\u001a\u00020\u0003H\u00c6\u0003J\t\u0010%\u001a\u00020\u0005H\u00c6\u0003J\t\u0010&\u001a\u00020\u0007H\u00c6\u0003J\t\u0010\'\u001a\u00020\tH\u00c6\u0003J\u000b\u0010(\u001a\u0004\u0018\u00010\tH\u00c6\u0003J\t\u0010)\u001a\u00020\fH\u00c6\u0003J\t\u0010*\u001a\u00020\u000eH\u00c6\u0003J\t\u0010+\u001a\u00020\u000eH\u00c6\u0003J\t\u0010,\u001a\u00020\u000eH\u00c6\u0003Je\u0010-\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00072\b\b\u0002\u0010\b\u001a\u00020\t2\n\b\u0002\u0010\n\u001a\u0004\u0018\u00010\t2\b\b\u0002\u0010\u000b\u001a\u00020\f2\b\b\u0002\u0010\r\u001a\u00020\u000e2\b\b\u0002\u0010\u000f\u001a\u00020\u000e2\b\b\u0002\u0010\u0010\u001a\u00020\u000eH\u00c6\u0001J\u0013\u0010.\u001a\u00020\u000e2\b\u0010/\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u00100\u001a\u00020\u0007H\u00d6\u0001J\b\u00101\u001a\u00020\u0005H\u0016R\u0011\u0010\r\u001a\u00020\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0013R\u0011\u0010\b\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0014\u0010\u0015R\u0013\u0010\n\u001a\u0004\u0018\u00010\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\u0015R\u0012\u0010\u0017\u001a\u00060\u0018j\u0002`\u0019X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u000f\u001a\u00020\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001a\u0010\u0013R\u0011\u0010\u000b\u001a\u00020\f\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001b\u0010\u001cR\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001d\u0010\u001eR\u0011\u0010\u0010\u001a\u00020\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001f\u0010\u0013R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b \u0010!R\u0011\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\"\u0010#"}, d2 = {"Lcom/android/systemui/privacy/PrivacyDialog$PrivacyElement;", "", "type", "Lcom/android/systemui/privacy/PrivacyType;", "packageName", "", "userId", "", "applicationName", "", "attribution", "lastActiveTimestamp", "", "active", "", "enterprise", "phoneCall", "(Lcom/android/systemui/privacy/PrivacyType;Ljava/lang/String;ILjava/lang/CharSequence;Ljava/lang/CharSequence;JZZZ)V", "getActive", "()Z", "getApplicationName", "()Ljava/lang/CharSequence;", "getAttribution", "builder", "Ljava/lang/StringBuilder;", "Lkotlin/text/StringBuilder;", "getEnterprise", "getLastActiveTimestamp", "()J", "getPackageName", "()Ljava/lang/String;", "getPhoneCall", "getType", "()Lcom/android/systemui/privacy/PrivacyType;", "getUserId", "()I", "component1", "component2", "component3", "component4", "component5", "component6", "component7", "component8", "component9", "copy", "equals", "other", "hashCode", "toString"})
    public static final class PrivacyElement {
        private final java.lang.StringBuilder builder = null;
        @org.jetbrains.annotations.NotNull()
        private final com.android.systemui.privacy.PrivacyType type = null;
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String packageName = null;
        private final int userId = 0;
        @org.jetbrains.annotations.NotNull()
        private final java.lang.CharSequence applicationName = null;
        @org.jetbrains.annotations.Nullable()
        private final java.lang.CharSequence attribution = null;
        private final long lastActiveTimestamp = 0L;
        private final boolean active = false;
        private final boolean enterprise = false;
        private final boolean phoneCall = false;
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.privacy.PrivacyType getType() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getPackageName() {
            return null;
        }
        
        public final int getUserId() {
            return 0;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.CharSequence getApplicationName() {
            return null;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final java.lang.CharSequence getAttribution() {
            return null;
        }
        
        public final long getLastActiveTimestamp() {
            return 0L;
        }
        
        public final boolean getActive() {
            return false;
        }
        
        public final boolean getEnterprise() {
            return false;
        }
        
        public final boolean getPhoneCall() {
            return false;
        }
        
        public PrivacyElement(@org.jetbrains.annotations.NotNull()
        com.android.systemui.privacy.PrivacyType type, @org.jetbrains.annotations.NotNull()
        java.lang.String packageName, int userId, @org.jetbrains.annotations.NotNull()
        java.lang.CharSequence applicationName, @org.jetbrains.annotations.Nullable()
        java.lang.CharSequence attribution, long lastActiveTimestamp, boolean active, boolean enterprise, boolean phoneCall) {
            super();
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.privacy.PrivacyType component1() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String component2() {
            return null;
        }
        
        public final int component3() {
            return 0;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.CharSequence component4() {
            return null;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final java.lang.CharSequence component5() {
            return null;
        }
        
        public final long component6() {
            return 0L;
        }
        
        public final boolean component7() {
            return false;
        }
        
        public final boolean component8() {
            return false;
        }
        
        public final boolean component9() {
            return false;
        }
        
        /**
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.privacy.PrivacyDialog.PrivacyElement copy(@org.jetbrains.annotations.NotNull()
        com.android.systemui.privacy.PrivacyType type, @org.jetbrains.annotations.NotNull()
        java.lang.String packageName, int userId, @org.jetbrains.annotations.NotNull()
        java.lang.CharSequence applicationName, @org.jetbrains.annotations.Nullable()
        java.lang.CharSequence attribution, long lastActiveTimestamp, boolean active, boolean enterprise, boolean phoneCall) {
            return null;
        }
        
        /**
         */
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        /**
         */
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
    
    /**
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u000e\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\bf\u0018\u00002\u00020\u0001J\b\u0010\u0002\u001a\u00020\u0003H&"}, d2 = {"Lcom/android/systemui/privacy/PrivacyDialog$OnDialogDismissed;", "", "onDialogDismissed", ""})
    public static abstract interface OnDialogDismissed {
        
        public abstract void onDialogDismissed();
    }
}