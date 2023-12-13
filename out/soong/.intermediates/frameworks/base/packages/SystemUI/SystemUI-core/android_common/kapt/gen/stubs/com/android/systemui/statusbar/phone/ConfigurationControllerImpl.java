package com.android.systemui.statusbar.phone;

import android.content.Context;
import android.content.pm.ActivityInfo;
import android.content.res.Configuration;
import android.graphics.Rect;
import android.os.LocaleList;
import com.android.systemui.statusbar.policy.ConfigurationController;
import java.util.ArrayList;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000L\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u0007\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\u0006\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0010\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u0010H\u0016J\b\u0010\u001a\u001a\u00020\nH\u0016J\b\u0010\u001b\u001a\u00020\u0018H\u0016J\u0010\u0010\u001c\u001a\u00020\u00182\u0006\u0010\u001d\u001a\u00020\fH\u0016J\u0010\u0010\u001e\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u0010H\u0016R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u0006X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u000e\u001a\b\u0012\u0004\u0012\u00020\u00100\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0011\u001a\u0004\u0018\u00010\u0012X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0013\u001a\u0004\u0018\u00010\u0014X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0015\u001a\u00020\u0006X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0016\u001a\u00020\u0006X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/phone/ConfigurationControllerImpl;", "Lcom/android/systemui/statusbar/policy/ConfigurationController;", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "density", "", "fontScale", "", "inCarMode", "", "lastConfig", "Landroid/content/res/Configuration;", "layoutDirection", "listeners", "", "Lcom/android/systemui/statusbar/policy/ConfigurationController$ConfigurationListener;", "localeList", "Landroid/os/LocaleList;", "maxBounds", "Landroid/graphics/Rect;", "smallestScreenWidth", "uiMode", "addCallback", "", "listener", "isLayoutRtl", "notifyThemeChanged", "onConfigurationChanged", "newConfig", "removeCallback"})
public final class ConfigurationControllerImpl implements com.android.systemui.statusbar.policy.ConfigurationController {
    private final java.util.List<com.android.systemui.statusbar.policy.ConfigurationController.ConfigurationListener> listeners = null;
    private final android.content.res.Configuration lastConfig = null;
    private int density = 0;
    private int smallestScreenWidth = 0;
    private android.graphics.Rect maxBounds;
    private float fontScale = 0.0F;
    private final boolean inCarMode = false;
    private int uiMode = 0;
    private android.os.LocaleList localeList;
    private final android.content.Context context = null;
    private int layoutDirection;
    
    @java.lang.Override()
    public void notifyThemeChanged() {
    }
    
    @java.lang.Override()
    public void onConfigurationChanged(@org.jetbrains.annotations.NotNull()
    android.content.res.Configuration newConfig) {
    }
    
    @java.lang.Override()
    public void addCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.ConfigurationController.ConfigurationListener listener) {
    }
    
    @java.lang.Override()
    public void removeCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.ConfigurationController.ConfigurationListener listener) {
    }
    
    @java.lang.Override()
    public boolean isLayoutRtl() {
        return false;
    }
    
    public ConfigurationControllerImpl(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
}