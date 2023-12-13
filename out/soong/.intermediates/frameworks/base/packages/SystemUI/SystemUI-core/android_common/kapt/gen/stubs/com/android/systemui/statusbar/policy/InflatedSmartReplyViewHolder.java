package com.android.systemui.statusbar.policy;

import android.widget.Button;

/**
 * Holder for inflated smart replies and actions. These objects should be inflated on a background
 * thread, to later be accessed and modified on the (performance critical) UI thread.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0005\u0018\u00002\u00020\u0001B\u001f\u0012\b\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u0012\u000e\u0010\u0004\u001a\n\u0012\u0004\u0012\u00020\u0006\u0018\u00010\u0005\u00a2\u0006\u0002\u0010\u0007R\u0013\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\tR\u0019\u0010\u0004\u001a\n\u0012\u0004\u0012\u00020\u0006\u0018\u00010\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000b"}, d2 = {"Lcom/android/systemui/statusbar/policy/InflatedSmartReplyViewHolder;", "", "smartReplyView", "Lcom/android/systemui/statusbar/policy/SmartReplyView;", "smartSuggestionButtons", "", "Landroid/widget/Button;", "(Lcom/android/systemui/statusbar/policy/SmartReplyView;Ljava/util/List;)V", "getSmartReplyView", "()Lcom/android/systemui/statusbar/policy/SmartReplyView;", "getSmartSuggestionButtons", "()Ljava/util/List;"})
public final class InflatedSmartReplyViewHolder {
    @org.jetbrains.annotations.Nullable()
    private final com.android.systemui.statusbar.policy.SmartReplyView smartReplyView = null;
    @org.jetbrains.annotations.Nullable()
    private final java.util.List<android.widget.Button> smartSuggestionButtons = null;
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.policy.SmartReplyView getSmartReplyView() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.util.List<android.widget.Button> getSmartSuggestionButtons() {
        return null;
    }
    
    public InflatedSmartReplyViewHolder(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.policy.SmartReplyView smartReplyView, @org.jetbrains.annotations.Nullable()
    java.util.List<? extends android.widget.Button> smartSuggestionButtons) {
        super();
    }
}