package com.android.systemui.privacy;

import android.content.Context;
import android.util.AttributeSet;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.LinearLayout;
import com.android.settingslib.Utils;
import com.android.systemui.R;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u00002\u00020\u0001B/\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\n\b\u0002\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u0012\b\b\u0002\u0010\u0006\u001a\u00020\u0007\u0012\b\b\u0002\u0010\b\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\tJ\u0010\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u001aH\u0002J\b\u0010\u001b\u001a\u00020\u0018H\u0014J\b\u0010\u001c\u001a\u00020\u0018H\u0002J\u0010\u0010\u001d\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u001aH\u0002R\u000e\u0010\n\u001a\u00020\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082.\u00a2\u0006\u0002\n\u0000R0\u0010\u0012\u001a\b\u0012\u0004\u0012\u00020\u00110\u00102\f\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00110\u0010@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0013\u0010\u0014\"\u0004\b\u0015\u0010\u0016"}, d2 = {"Lcom/android/systemui/privacy/OngoingPrivacyChip;", "Landroid/widget/FrameLayout;", "context", "Landroid/content/Context;", "attrs", "Landroid/util/AttributeSet;", "defStyleAttrs", "", "defStyleRes", "(Landroid/content/Context;Landroid/util/AttributeSet;II)V", "iconColor", "iconMargin", "iconSize", "iconsContainer", "Landroid/widget/LinearLayout;", "value", "", "Lcom/android/systemui/privacy/PrivacyItem;", "privacyList", "getPrivacyList", "()Ljava/util/List;", "setPrivacyList", "(Ljava/util/List;)V", "generateContentDescription", "", "builder", "Lcom/android/systemui/privacy/PrivacyChipBuilder;", "onFinishInflate", "updateResources", "updateView"})
public final class OngoingPrivacyChip extends android.widget.FrameLayout {
    private int iconMargin = 0;
    private int iconSize = 0;
    private int iconColor = 0;
    private android.widget.LinearLayout iconsContainer;
    @org.jetbrains.annotations.NotNull()
    private java.util.List<com.android.systemui.privacy.PrivacyItem> privacyList;
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<com.android.systemui.privacy.PrivacyItem> getPrivacyList() {
        return null;
    }
    
    public final void setPrivacyList(@org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.privacy.PrivacyItem> value) {
    }
    
    @java.lang.Override()
    protected void onFinishInflate() {
    }
    
    private final void updateView(com.android.systemui.privacy.PrivacyChipBuilder builder) {
    }
    
    private final void generateContentDescription(com.android.systemui.privacy.PrivacyChipBuilder builder) {
    }
    
    private final void updateResources() {
    }
    
    public OngoingPrivacyChip(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs, int defStyleAttrs, int defStyleRes) {
        super(null);
    }
    
    public OngoingPrivacyChip(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs, int defStyleAttrs) {
        super(null);
    }
    
    public OngoingPrivacyChip(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs) {
        super(null);
    }
    
    public OngoingPrivacyChip(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super(null);
    }
}