package com.android.systemui.qs.tileimpl;

import android.animation.ArgbEvaluator;
import android.animation.PropertyValuesHolder;
import android.animation.ValueAnimator;
import android.content.Context;
import android.content.res.ColorStateList;
import android.content.res.Configuration;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.RippleDrawable;
import android.service.quicksettings.Tile;
import android.text.TextUtils;
import android.util.Log;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.accessibility.AccessibilityEvent;
import android.view.accessibility.AccessibilityNodeInfo;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.Switch;
import android.widget.TextView;
import androidx.annotation.VisibleForTesting;
import com.android.settingslib.Utils;
import com.android.systemui.FontSizeUtils;
import com.android.systemui.R;
import com.android.systemui.animation.LaunchableView;
import com.android.systemui.plugins.qs.QSIconView;
import com.android.systemui.plugins.qs.QSTile;
import com.android.systemui.plugins.qs.QSTile.BooleanState;
import com.android.systemui.plugins.qs.QSTileView;
import java.util.Objects;

@androidx.annotation.VisibleForTesting()
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010$\n\u0002\u0010\u000e\n\u0002\u0010\b\n\u0002\b\u0002\b\u00c1\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0007\u001a\u00020\u00062\b\u0010\b\u001a\u0004\u0018\u00010\u0005R\u001c\u0010\u0003\u001a\u0010\u0012\u0006\u0012\u0004\u0018\u00010\u0005\u0012\u0004\u0012\u00020\u00060\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/tileimpl/SubtitleArrayMapping;", "", "()V", "subtitleIdsMap", "", "", "", "getSubtitleId", "spec"})
public final class SubtitleArrayMapping {
    private static final java.util.Map<java.lang.String, java.lang.Integer> subtitleIdsMap = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.qs.tileimpl.SubtitleArrayMapping INSTANCE = null;
    
    public final int getSubtitleId(@org.jetbrains.annotations.Nullable()
    java.lang.String spec) {
        return 0;
    }
    
    private SubtitleArrayMapping() {
        super();
    }
}