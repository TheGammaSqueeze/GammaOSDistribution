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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000P\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\b\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u0002\u0018\u00002\u00020\u0001B\u000f\u0012\b\b\u0002\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0012\u0010%\u001a\u00020\u00032\b\u0010&\u001a\u0004\u0018\u00010\u0001H\u0016J\b\u0010\'\u001a\u00020\u0006H\u0016J\u0012\u0010(\u001a\u00020)2\b\u0010&\u001a\u0004\u0018\u00010\u0001H\u0016R\u001c\u0010\u0005\u001a\u0004\u0018\u00010\u0006X\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0007\u0010\b\"\u0004\b\t\u0010\nR\u0014\u0010\u000b\u001a\u00020\u0003X\u0096D\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\rR\u0014\u0010\u000e\u001a\u00020\u000fX\u0096D\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\u0011R\u0010\u0010\u0012\u001a\u0004\u0018\u00010\u0013X\u0082\u000e\u00a2\u0006\u0002\n\u0000R \u0010\u0014\u001a\b\u0012\u0004\u0012\u00020\u00160\u0015X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0017\u0010\u0018\"\u0004\b\u0019\u0010\u001aR\u0014\u0010\u0002\u001a\u00020\u0003X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001b\u0010\rR/\u0010\u001c\u001a\u001d\u0012\u0013\u0012\u00110\u001e\u00a2\u0006\f\b\u001f\u0012\b\b \u0012\u0004\b\b(!\u0012\u0004\u0012\u00020\"0\u001dX\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b#\u0010$"}, d2 = {"Lcom/android/systemui/statusbar/events/PrivacyEvent;", "Lcom/android/systemui/statusbar/events/StatusEvent;", "showAnimation", "", "(Z)V", "contentDescription", "", "getContentDescription", "()Ljava/lang/String;", "setContentDescription", "(Ljava/lang/String;)V", "forceVisible", "getForceVisible", "()Z", "priority", "", "getPriority", "()I", "privacyChip", "Lcom/android/systemui/privacy/OngoingPrivacyChip;", "privacyItems", "", "Lcom/android/systemui/privacy/PrivacyItem;", "getPrivacyItems", "()Ljava/util/List;", "setPrivacyItems", "(Ljava/util/List;)V", "getShowAnimation", "viewCreator", "Lkotlin/Function1;", "Landroid/content/Context;", "Lkotlin/ParameterName;", "name", "context", "Landroid/view/View;", "getViewCreator", "()Lkotlin/jvm/functions/Function1;", "shouldUpdateFromEvent", "other", "toString", "updateFromEvent", ""})
public final class PrivacyEvent implements com.android.systemui.statusbar.events.StatusEvent {
    @org.jetbrains.annotations.Nullable()
    private java.lang.String contentDescription;
    private final int priority = 100;
    private final boolean forceVisible = true;
    @org.jetbrains.annotations.NotNull()
    private java.util.List<com.android.systemui.privacy.PrivacyItem> privacyItems;
    private com.android.systemui.privacy.OngoingPrivacyChip privacyChip;
    @org.jetbrains.annotations.NotNull()
    private final kotlin.jvm.functions.Function1<android.content.Context, android.view.View> viewCreator = null;
    private final boolean showAnimation = false;
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.String getContentDescription() {
        return null;
    }
    
    @java.lang.Override()
    public void setContentDescription(@org.jetbrains.annotations.Nullable()
    java.lang.String p0) {
    }
    
    @java.lang.Override()
    public int getPriority() {
        return 0;
    }
    
    @java.lang.Override()
    public boolean getForceVisible() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<com.android.systemui.privacy.PrivacyItem> getPrivacyItems() {
        return null;
    }
    
    public final void setPrivacyItems(@org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.privacy.PrivacyItem> p0) {
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
    
    @java.lang.Override()
    public boolean shouldUpdateFromEvent(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.events.StatusEvent other) {
        return false;
    }
    
    @java.lang.Override()
    public void updateFromEvent(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.events.StatusEvent other) {
    }
    
    @java.lang.Override()
    public boolean getShowAnimation() {
        return false;
    }
    
    public PrivacyEvent(boolean showAnimation) {
        super();
    }
    
    public PrivacyEvent() {
        super();
    }
}