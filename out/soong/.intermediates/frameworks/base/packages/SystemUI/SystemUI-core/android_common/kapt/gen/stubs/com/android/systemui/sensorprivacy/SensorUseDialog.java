package com.android.systemui.sensorprivacy;

import android.content.Context;
import android.content.DialogInterface;
import android.content.res.Resources;
import android.text.Html;
import android.view.LayoutInflater;
import android.view.View;
import android.view.WindowManager;
import android.widget.ImageView;
import com.android.internal.widget.DialogTitle;
import com.android.systemui.R;
import com.android.systemui.statusbar.phone.SystemUIDialog;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0007\u0018\u00002\u00020\u0001B%\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nR\u0011\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u0011\u0010\b\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000eR\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010"}, d2 = {"Lcom/android/systemui/sensorprivacy/SensorUseDialog;", "Lcom/android/systemui/statusbar/phone/SystemUIDialog;", "context", "Landroid/content/Context;", "sensor", "", "clickListener", "Landroid/content/DialogInterface$OnClickListener;", "dismissListener", "Landroid/content/DialogInterface$OnDismissListener;", "(Landroid/content/Context;ILandroid/content/DialogInterface$OnClickListener;Landroid/content/DialogInterface$OnDismissListener;)V", "getClickListener", "()Landroid/content/DialogInterface$OnClickListener;", "getDismissListener", "()Landroid/content/DialogInterface$OnDismissListener;", "getSensor", "()I"})
public final class SensorUseDialog extends com.android.systemui.statusbar.phone.SystemUIDialog {
    private final int sensor = 0;
    @org.jetbrains.annotations.NotNull()
    private final android.content.DialogInterface.OnClickListener clickListener = null;
    @org.jetbrains.annotations.NotNull()
    private final android.content.DialogInterface.OnDismissListener dismissListener = null;
    
    public final int getSensor() {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.DialogInterface.OnClickListener getClickListener() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.DialogInterface.OnDismissListener getDismissListener() {
        return null;
    }
    
    public SensorUseDialog(@org.jetbrains.annotations.NotNull()
    android.content.Context context, int sensor, @org.jetbrains.annotations.NotNull()
    android.content.DialogInterface.OnClickListener clickListener, @org.jetbrains.annotations.NotNull()
    android.content.DialogInterface.OnDismissListener dismissListener) {
        super(null);
    }
}