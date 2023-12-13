package com.android.systemui.privacy;

import android.content.Context;
import com.android.systemui.R;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000F\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000e\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B\u001b\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\f\u0010\u0004\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005\u00a2\u0006\u0002\u0010\u0007J\u0014\u0010\u0014\u001a\u0010\u0012\f\u0012\n \u0010*\u0004\u0018\u00010\u00150\u00150\u0005J\u0006\u0010\u0016\u001a\u00020\u000fJ\u001c\u0010\u0017\u001a\u00060\u0018j\u0002`\u0019\"\u0004\b\u0000\u0010\u001a*\b\u0012\u0004\u0012\u0002H\u001a0\u0005H\u0002R)\u0010\b\u001a\u001a\u0012\u0016\u0012\u0014\u0012\u0004\u0012\u00020\n\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u000b0\u00050\t0\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\rR\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u000e\u001a\n \u0010*\u0004\u0018\u00010\u000f0\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0011\u001a\n \u0010*\u0004\u0018\u00010\u000f0\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0017\u0010\u0012\u001a\b\u0012\u0004\u0012\u00020\u000b0\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0013\u0010\r"}, d2 = {"Lcom/android/systemui/privacy/PrivacyChipBuilder;", "", "context", "Landroid/content/Context;", "itemsList", "", "Lcom/android/systemui/privacy/PrivacyItem;", "(Landroid/content/Context;Ljava/util/List;)V", "appsAndTypes", "Lkotlin/Pair;", "Lcom/android/systemui/privacy/PrivacyApplication;", "Lcom/android/systemui/privacy/PrivacyType;", "getAppsAndTypes", "()Ljava/util/List;", "lastSeparator", "", "kotlin.jvm.PlatformType", "separator", "types", "getTypes", "generateIcons", "Landroid/graphics/drawable/Drawable;", "joinTypes", "joinWithAnd", "Ljava/lang/StringBuilder;", "Lkotlin/text/StringBuilder;", "T"})
public final class PrivacyChipBuilder {
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<kotlin.Pair<com.android.systemui.privacy.PrivacyApplication, java.util.List<com.android.systemui.privacy.PrivacyType>>> appsAndTypes = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<com.android.systemui.privacy.PrivacyType> types = null;
    private final java.lang.String separator = null;
    private final java.lang.String lastSeparator = null;
    private final android.content.Context context = null;
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<kotlin.Pair<com.android.systemui.privacy.PrivacyApplication, java.util.List<com.android.systemui.privacy.PrivacyType>>> getAppsAndTypes() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<com.android.systemui.privacy.PrivacyType> getTypes() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<android.graphics.drawable.Drawable> generateIcons() {
        return null;
    }
    
    private final <T extends java.lang.Object>java.lang.StringBuilder joinWithAnd(java.util.List<? extends T> $this$joinWithAnd) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String joinTypes() {
        return null;
    }
    
    public PrivacyChipBuilder(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.privacy.PrivacyItem> itemsList) {
        super();
    }
}