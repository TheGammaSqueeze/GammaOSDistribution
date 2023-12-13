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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\bf\u0018\u00002\u00020\u0001J\u0012\u0010\u001b\u001a\u00020\t2\b\u0010\u001c\u001a\u0004\u0018\u00010\u0000H\u0016J\u0012\u0010\u001d\u001a\u00020\u001e2\b\u0010\u001c\u001a\u0004\u0018\u00010\u0000H\u0016R\u001a\u0010\u0002\u001a\u0004\u0018\u00010\u0003X\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b\u0004\u0010\u0005\"\u0004\b\u0006\u0010\u0007R\u0012\u0010\b\u001a\u00020\tX\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\n\u0010\u000bR\u0012\u0010\f\u001a\u00020\rX\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u000e\u0010\u000fR\u0012\u0010\u0010\u001a\u00020\tX\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0011\u0010\u000bR-\u0010\u0012\u001a\u001d\u0012\u0013\u0012\u00110\u0014\u00a2\u0006\f\b\u0015\u0012\b\b\u0016\u0012\u0004\b\b(\u0017\u0012\u0004\u0012\u00020\u00180\u0013X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0019\u0010\u001a"}, d2 = {"Lcom/android/systemui/statusbar/events/StatusEvent;", "", "contentDescription", "", "getContentDescription", "()Ljava/lang/String;", "setContentDescription", "(Ljava/lang/String;)V", "forceVisible", "", "getForceVisible", "()Z", "priority", "", "getPriority", "()I", "showAnimation", "getShowAnimation", "viewCreator", "Lkotlin/Function1;", "Landroid/content/Context;", "Lkotlin/ParameterName;", "name", "context", "Landroid/view/View;", "getViewCreator", "()Lkotlin/jvm/functions/Function1;", "shouldUpdateFromEvent", "other", "updateFromEvent", ""})
public abstract interface StatusEvent {
    
    public abstract int getPriority();
    
    public abstract boolean getForceVisible();
    
    public abstract boolean getShowAnimation();
    
    @org.jetbrains.annotations.NotNull()
    public abstract kotlin.jvm.functions.Function1<android.content.Context, android.view.View> getViewCreator();
    
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.String getContentDescription();
    
    public abstract void setContentDescription(@org.jetbrains.annotations.Nullable()
    java.lang.String p0);
    
    public abstract void updateFromEvent(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.events.StatusEvent other);
    
    public abstract boolean shouldUpdateFromEvent(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.events.StatusEvent other);
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 3)
    public final class DefaultImpls {
        
        public static void updateFromEvent(@org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.events.StatusEvent $this, @org.jetbrains.annotations.Nullable()
        com.android.systemui.statusbar.events.StatusEvent other) {
        }
        
        public static boolean shouldUpdateFromEvent(@org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.events.StatusEvent $this, @org.jetbrains.annotations.Nullable()
        com.android.systemui.statusbar.events.StatusEvent other) {
            return false;
        }
    }
}