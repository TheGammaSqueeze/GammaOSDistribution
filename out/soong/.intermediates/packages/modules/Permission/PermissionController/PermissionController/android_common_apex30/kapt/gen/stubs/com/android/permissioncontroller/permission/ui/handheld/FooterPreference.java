package com.android.permissioncontroller.permission.ui.handheld;

import android.content.Context;
import android.util.AttributeSet;
import android.widget.TextView;
import androidx.preference.Preference;
import androidx.preference.PreferenceViewHolder;
import com.android.permissioncontroller.R;

/**
 * A Preference for the footer of a screen. Has two summaries, and adjusted spacing and icon
 * placement.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000:\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0004\n\u0002\u0010\r\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B\u000f\b\u0016\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004B\u0017\b\u0016\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0007B\u001f\b\u0016\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nB\'\b\u0016\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\u000b\u001a\u00020\t\u00a2\u0006\u0002\u0010\fJ\u0012\u0010\u0016\u001a\u00020\u00172\b\u0010\u0018\u001a\u0004\u0018\u00010\u0019H\u0016R$\u0010\u000f\u001a\u00020\u000e2\u0006\u0010\r\u001a\u00020\u000e@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0010\u0010\u0011\"\u0004\b\u0012\u0010\u0013R\u0010\u0010\u0014\u001a\u0004\u0018\u00010\u0015X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/handheld/FooterPreference;", "Landroidx/preference/Preference;", "c", "Landroid/content/Context;", "(Landroid/content/Context;)V", "a", "Landroid/util/AttributeSet;", "(Landroid/content/Context;Landroid/util/AttributeSet;)V", "attr", "", "(Landroid/content/Context;Landroid/util/AttributeSet;I)V", "res", "(Landroid/content/Context;Landroid/util/AttributeSet;II)V", "value", "", "secondSummary", "getSecondSummary", "()Ljava/lang/CharSequence;", "setSecondSummary", "(Ljava/lang/CharSequence;)V", "secondSummaryView", "Landroid/widget/TextView;", "onBindViewHolder", "", "holder", "Landroidx/preference/PreferenceViewHolder;"})
public final class FooterPreference extends androidx.preference.Preference {
    @org.jetbrains.annotations.NotNull()
    private java.lang.CharSequence secondSummary = "";
    private android.widget.TextView secondSummaryView;
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.CharSequence getSecondSummary() {
        return null;
    }
    
    public final void setSecondSummary(@org.jetbrains.annotations.NotNull()
    java.lang.CharSequence value) {
    }
    
    @java.lang.Override()
    public void onBindViewHolder(@org.jetbrains.annotations.Nullable()
    androidx.preference.PreferenceViewHolder holder) {
    }
    
    public FooterPreference(@org.jetbrains.annotations.NotNull()
    android.content.Context c) {
        super(null, null, 0, 0);
    }
    
    public FooterPreference(@org.jetbrains.annotations.NotNull()
    android.content.Context c, @org.jetbrains.annotations.NotNull()
    android.util.AttributeSet a) {
        super(null, null, 0, 0);
    }
    
    public FooterPreference(@org.jetbrains.annotations.NotNull()
    android.content.Context c, @org.jetbrains.annotations.NotNull()
    android.util.AttributeSet a, int attr) {
        super(null, null, 0, 0);
    }
    
    public FooterPreference(@org.jetbrains.annotations.NotNull()
    android.content.Context c, @org.jetbrains.annotations.NotNull()
    android.util.AttributeSet a, int attr, int res) {
        super(null, null, 0, 0);
    }
}