package com.android.permissioncontroller.permission.ui.handheld;

import android.app.Activity;
import android.content.res.Configuration;
import android.graphics.Color;
import android.graphics.ImageDecoder;
import android.graphics.Paint;
import android.graphics.Path;
import android.graphics.PixelFormat;
import android.graphics.PorterDuff;
import android.graphics.PorterDuffXfermode;
import android.graphics.drawable.AnimatedImageDrawable;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.Icon;
import android.os.Bundle;
import android.os.UserHandle;
import android.text.method.LinkMovementMethod;
import android.transition.ChangeBounds;
import android.transition.TransitionManager;
import android.util.SparseIntArray;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.view.WindowManager.LayoutParams;
import android.view.accessibility.AccessibilityNodeInfo;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
import com.android.permissioncontroller.R;
import com.android.permissioncontroller.permission.ui.GrantPermissionsViewHandler;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00a4\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u0018\n\u0000\n\u0002\u0010\u0011\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\r\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0016\n\u0002\u0018\u0002\n\u0000\u0018\u0000 T2\u00020\u00012\u00020\u0002:\u0001TB\u001d\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u00a2\u0006\u0002\u0010\tJ\b\u00104\u001a\u00020+H\u0016J\u0010\u00105\u001a\u0002062\u0006\u00107\u001a\u00020\fH\u0002J\b\u00108\u001a\u000209H\u0002J\u0010\u0010:\u001a\u0002092\u0006\u0010;\u001a\u00020<H\u0016J\b\u0010=\u001a\u000209H\u0016J\u0010\u0010>\u001a\u0002092\u0006\u0010?\u001a\u00020+H\u0016J\u0010\u0010@\u001a\u0002092\u0006\u0010A\u001a\u00020)H\u0002J\u0010\u0010B\u001a\u0002092\u0006\u0010C\u001a\u00020<H\u0016J\u0012\u0010D\u001a\u0002092\b\u0010E\u001a\u0004\u0018\u00010\u000fH\u0002J\u0012\u0010F\u001a\u0002092\b\u0010E\u001a\u0004\u0018\u00010\u000fH\u0002J\u0010\u0010G\u001a\u00020\u00002\u0006\u0010H\u001a\u000200H\u0016J\b\u0010I\u001a\u000209H\u0002J\b\u0010J\u001a\u000209H\u0002J\b\u0010K\u001a\u000209H\u0002J\b\u0010L\u001a\u000209H\u0002J\b\u0010M\u001a\u000209H\u0002JN\u0010N\u001a\u0002092\u0006\u0010%\u001a\u00020\u00062\u0006\u0010 \u001a\u00020\f2\u0006\u0010#\u001a\u00020\f2\b\u0010O\u001a\u0004\u0018\u00010\"2\b\u0010P\u001a\u0004\u0018\u00010\u001a2\b\u0010\u0019\u001a\u0004\u0018\u00010\u001a2\u0006\u0010\u000e\u001a\u00020\u000f2\u0006\u0010-\u001a\u00020\u000fH\u0016J\u0010\u0010Q\u001a\u0002092\u0006\u0010R\u001a\u00020SH\u0016R\u0014\u0010\n\u001a\b\u0012\u0004\u0012\u00020\f0\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0018\u0010\u0010\u001a\n\u0012\u0006\u0012\u0004\u0018\u00010\u00120\u0011X\u0082\u000e\u00a2\u0006\u0004\n\u0002\u0010\u0013R\u0010\u0010\u0014\u001a\u0004\u0018\u00010\u0015X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0016\u001a\u0004\u0018\u00010\u0015X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0017\u001a\u0004\u0018\u00010\u0018X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0019\u001a\u0004\u0018\u00010\u001aX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u001b\u001a\u0004\u0018\u00010\u001cX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u001d\u001a\u0004\u0018\u00010\u0015X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u001e\u001a\u0004\u0018\u00010\u0015X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u001f\u001a\u0004\u0018\u00010\u0018X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010 \u001a\u00020\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010!\u001a\u0004\u0018\u00010\"X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010#\u001a\u00020\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010$\u001a\u0004\u0018\u00010\u001aX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010%\u001a\u0004\u0018\u00010\u0006X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010&\u001a\u0004\u0018\u00010\'X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010(\u001a\u00020)X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0018\u0010*\u001a\n\u0012\u0006\u0012\u0004\u0018\u00010+0\u0011X\u0082\u000e\u00a2\u0006\u0004\n\u0002\u0010,R\u000e\u0010-\u001a\u00020\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010.\u001a\u0004\u0018\u00010\u001cX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010/\u001a\u0004\u0018\u000100X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u00101\u001a\u0004\u0018\u000102X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u00103\u001a\u00020\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/handheld/GrantPermissionsViewHandlerImpl;", "Lcom/android/permissioncontroller/permission/ui/GrantPermissionsViewHandler;", "Landroid/view/View$OnClickListener;", "mActivity", "Landroid/app/Activity;", "mAppPackageName", "", "mUserHandle", "Landroid/os/UserHandle;", "(Landroid/app/Activity;Ljava/lang/String;Landroid/os/UserHandle;)V", "LOCATION_ACCURACY_DIALOGS", "", "", "LOCATION_ACCURACY_IMAGE_DIAMETER", "buttonVisibilities", "", "buttons", "", "Landroid/widget/Button;", "[Landroid/widget/Button;", "coarseOffDrawable", "Landroid/graphics/drawable/AnimatedImageDrawable;", "coarseOnDrawable", "coarseRadioButton", "Landroid/widget/RadioButton;", "detailMessage", "", "detailMessageView", "Landroid/widget/TextView;", "fineOffDrawable", "fineOnDrawable", "fineRadioButton", "groupCount", "groupIcon", "Landroid/graphics/drawable/Icon;", "groupIndex", "groupMessage", "groupName", "iconView", "Landroid/widget/ImageView;", "isLocationPermissionDialogActionClicked", "", "locationViews", "Landroid/view/View;", "[Landroid/view/View;", "locationVisibilities", "messageView", "resultListener", "Lcom/android/permissioncontroller/permission/ui/GrantPermissionsViewHandler$ResultListener;", "rootView", "Landroid/view/ViewGroup;", "selectedPrecision", "createView", "getDrawableFromId", "Landroid/graphics/drawable/Drawable;", "drawableId", "initializeAnimatedImages", "", "loadInstanceState", "savedInstanceState", "Landroid/os/Bundle;", "onBackPressed", "onClick", "view", "runLocationAccuracyAnimation", "isFineSelected", "saveInstanceState", "arguments", "setButtonVisibilities", "visibilities", "setLocationVisibilities", "setResultListener", "listener", "updateAll", "updateButtons", "updateDescription", "updateDetailDescription", "updateLocationVisibilities", "updateUi", "icon", "message", "updateWindowAttributes", "outLayoutParams", "Landroid/view/WindowManager$LayoutParams;", "Companion"})
public final class GrantPermissionsViewHandlerImpl implements com.android.permissioncontroller.permission.ui.GrantPermissionsViewHandler, android.view.View.OnClickListener {
    private final java.util.List<java.lang.Integer> LOCATION_ACCURACY_DIALOGS = null;
    private final int LOCATION_ACCURACY_IMAGE_DIAMETER = 0;
    private com.android.permissioncontroller.permission.ui.GrantPermissionsViewHandler.ResultListener resultListener;
    private java.lang.String groupName;
    private int groupCount = 0;
    private int groupIndex = 0;
    private android.graphics.drawable.Icon groupIcon;
    private java.lang.CharSequence groupMessage;
    private java.lang.CharSequence detailMessage;
    private final boolean[] buttonVisibilities = null;
    private final boolean[] locationVisibilities = null;
    private int selectedPrecision = 0;
    private boolean isLocationPermissionDialogActionClicked = false;
    private android.widget.RadioButton coarseRadioButton;
    private android.widget.RadioButton fineRadioButton;
    private android.graphics.drawable.AnimatedImageDrawable coarseOffDrawable;
    private android.graphics.drawable.AnimatedImageDrawable coarseOnDrawable;
    private android.graphics.drawable.AnimatedImageDrawable fineOffDrawable;
    private android.graphics.drawable.AnimatedImageDrawable fineOnDrawable;
    private android.widget.ImageView iconView;
    private android.widget.TextView messageView;
    private android.widget.TextView detailMessageView;
    private android.widget.Button[] buttons;
    private android.view.View[] locationViews;
    private android.view.ViewGroup rootView;
    private final android.app.Activity mActivity = null;
    private final java.lang.String mAppPackageName = null;
    private final android.os.UserHandle mUserHandle = null;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String ARG_GROUP_NAME = "ARG_GROUP_NAME";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String ARG_GROUP_COUNT = "ARG_GROUP_COUNT";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String ARG_GROUP_INDEX = "ARG_GROUP_INDEX";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String ARG_GROUP_ICON = "ARG_GROUP_ICON";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String ARG_GROUP_MESSAGE = "ARG_GROUP_MESSAGE";
    private static final java.lang.String ARG_GROUP_DETAIL_MESSAGE = "ARG_GROUP_DETAIL_MESSAGE";
    private static final java.lang.String ARG_DIALOG_BUTTON_VISIBILITIES = "ARG_DIALOG_BUTTON_VISIBILITIES";
    private static final java.lang.String ARG_DIALOG_LOCATION_VISIBILITIES = "ARG_DIALOG_LOCATION_VISIBILITIES";
    private static final java.lang.String ARG_DIALOG_SELECTED_PRECISION = "ARG_DIALOG_SELECTED_PRECISION";
    private static final long SWITCH_TIME_MILLIS = 75L;
    private static final long ANIMATION_DURATION_MILLIS = 200L;
    private static final android.util.SparseIntArray BUTTON_RES_ID_TO_NUM = null;
    private static final android.util.SparseIntArray LOCATION_RES_ID_TO_NUM = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.ui.handheld.GrantPermissionsViewHandlerImpl.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.permissioncontroller.permission.ui.handheld.GrantPermissionsViewHandlerImpl setResultListener(@org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.ui.GrantPermissionsViewHandler.ResultListener listener) {
        return null;
    }
    
    @java.lang.Override()
    public void saveInstanceState(@org.jetbrains.annotations.NotNull()
    android.os.Bundle arguments) {
    }
    
    @java.lang.Override()
    public void loadInstanceState(@org.jetbrains.annotations.NotNull()
    android.os.Bundle savedInstanceState) {
    }
    
    @java.lang.Override()
    public void updateUi(@org.jetbrains.annotations.NotNull()
    java.lang.String groupName, int groupCount, int groupIndex, @org.jetbrains.annotations.Nullable()
    android.graphics.drawable.Icon icon, @org.jetbrains.annotations.Nullable()
    java.lang.CharSequence message, @org.jetbrains.annotations.Nullable()
    java.lang.CharSequence detailMessage, @org.jetbrains.annotations.NotNull()
    boolean[] buttonVisibilities, @org.jetbrains.annotations.NotNull()
    boolean[] locationVisibilities) {
    }
    
    private final void updateAll() {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.view.View createView() {
        return null;
    }
    
    private final void initializeAnimatedImages() {
    }
    
    private final android.graphics.drawable.Drawable getDrawableFromId(int drawableId) {
        return null;
    }
    
    @java.lang.Override()
    public void updateWindowAttributes(@org.jetbrains.annotations.NotNull()
    android.view.WindowManager.LayoutParams outLayoutParams) {
    }
    
    private final void setButtonVisibilities(boolean[] visibilities) {
    }
    
    private final void setLocationVisibilities(boolean[] visibilities) {
    }
    
    private final void updateDescription() {
    }
    
    private final void updateDetailDescription() {
    }
    
    private final void updateButtons() {
    }
    
    private final void updateLocationVisibilities() {
    }
    
    private final void runLocationAccuracyAnimation(boolean isFineSelected) {
    }
    
    @java.lang.Override()
    public void onClick(@org.jetbrains.annotations.NotNull()
    android.view.View view) {
    }
    
    @java.lang.Override()
    public void onBackPressed() {
    }
    
    public GrantPermissionsViewHandlerImpl(@org.jetbrains.annotations.NotNull()
    android.app.Activity mActivity, @org.jetbrains.annotations.NotNull()
    java.lang.String mAppPackageName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle mUserHandle) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\"\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\t\n\u0000\n\u0002\u0010\u000e\n\u0002\b\t\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0006X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0006X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0006X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u0006X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\u0006X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\u0006X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u0006X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u0006X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/handheld/GrantPermissionsViewHandlerImpl$Companion;", "", "()V", "ANIMATION_DURATION_MILLIS", "", "ARG_DIALOG_BUTTON_VISIBILITIES", "", "ARG_DIALOG_LOCATION_VISIBILITIES", "ARG_DIALOG_SELECTED_PRECISION", "ARG_GROUP_COUNT", "ARG_GROUP_DETAIL_MESSAGE", "ARG_GROUP_ICON", "ARG_GROUP_INDEX", "ARG_GROUP_MESSAGE", "ARG_GROUP_NAME", "BUTTON_RES_ID_TO_NUM", "Landroid/util/SparseIntArray;", "LOCATION_RES_ID_TO_NUM", "SWITCH_TIME_MILLIS"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}