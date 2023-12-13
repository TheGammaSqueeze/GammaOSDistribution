package com.android.systemui.statusbar.events;

import android.content.Context;
import android.graphics.Color;
import android.graphics.drawable.ColorDrawable;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.ImageView;
import com.android.settingslib.graph.ThemedBatteryDrawable;
import com.android.systemui.R;
import com.android.systemui.privacy.OngoingPrivacyChip;
import com.android.systemui.privacy.PrivacyItem;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000<\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u001c\u001a\u00020\u0004H\u0016R\u001c\u0010\u0003\u001a\u0004\u0018\u00010\u0004X\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0005\u0010\u0006\"\u0004\b\u0007\u0010\bR\u0014\u0010\t\u001a\u00020\nX\u0096D\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u0014\u0010\r\u001a\u00020\u000eX\u0096D\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010R\u0014\u0010\u0011\u001a\u00020\nX\u0096D\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\fR/\u0010\u0013\u001a\u001d\u0012\u0013\u0012\u00110\u0015\u00a2\u0006\f\b\u0016\u0012\b\b\u0017\u0012\u0004\b\b(\u0018\u0012\u0004\u0012\u00020\u00190\u0014X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001a\u0010\u001b"}, d2 = {"Lcom/android/systemui/statusbar/events/BatteryEvent;", "Lcom/android/systemui/statusbar/events/StatusEvent;", "()V", "contentDescription", "", "getContentDescription", "()Ljava/lang/String;", "setContentDescription", "(Ljava/lang/String;)V", "forceVisible", "", "getForceVisible", "()Z", "priority", "", "getPriority", "()I", "showAnimation", "getShowAnimation", "viewCreator", "Lkotlin/Function1;", "Landroid/content/Context;", "Lkotlin/ParameterName;", "name", "context", "Landroid/view/View;", "getViewCreator", "()Lkotlin/jvm/functions/Function1;", "toString"})
public final class BatteryEvent implements com.android.systemui.statusbar.events.StatusEvent {
    private final int priority = 50;
    private final boolean forceVisible = false;
    private final boolean showAnimation = true;
    @org.jetbrains.annotations.Nullable()
    private java.lang.String contentDescription = "";
    @org.jetbrains.annotations.NotNull()
    private final kotlin.jvm.functions.Function1<android.content.Context, android.view.View> viewCreator = null;
    
    @java.lang.Override()
    public int getPriority() {
        return 0;
    }
    
    @java.lang.Override()
    public boolean getForceVisible() {
        return false;
    }
    
    @java.lang.Override()
    public boolean getShowAnimation() {
        return false;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.String getContentDescription() {
        return null;
    }
    
    @java.lang.Override()
    public void setContentDescription(@org.jetbrains.annotations.Nullable()
    java.lang.String p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public kotlin.jvm.functions.Function1<android.content.Context, android.view.View> getViewCreator() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    public BatteryEvent() {
        super();
    }
    
    public void updateFromEvent(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.events.StatusEvent other) {
    }
    
    public boolean shouldUpdateFromEvent(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.events.StatusEvent other) {
        return false;
    }
}