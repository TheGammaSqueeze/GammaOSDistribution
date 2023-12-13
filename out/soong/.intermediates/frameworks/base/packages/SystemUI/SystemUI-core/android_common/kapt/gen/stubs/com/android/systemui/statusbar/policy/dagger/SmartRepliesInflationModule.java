package com.android.systemui.statusbar.policy.dagger;

import com.android.systemui.statusbar.policy.SmartActionInflater;
import com.android.systemui.statusbar.policy.SmartActionInflaterImpl;
import com.android.systemui.statusbar.policy.SmartReplyInflater;
import com.android.systemui.statusbar.policy.SmartReplyInflaterImpl;
import com.android.systemui.statusbar.policy.SmartReplyStateInflater;
import com.android.systemui.statusbar.policy.SmartReplyStateInflaterImpl;
import dagger.Binds;
import dagger.Module;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\bg\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H\'J\u0010\u0010\u0006\u001a\u00020\u00072\u0006\u0010\u0004\u001a\u00020\bH\'J\u0010\u0010\t\u001a\u00020\n2\u0006\u0010\u0004\u001a\u00020\u000bH\'"}, d2 = {"Lcom/android/systemui/statusbar/policy/dagger/SmartRepliesInflationModule;", "", "bindSmartActionsInflater", "Lcom/android/systemui/statusbar/policy/SmartActionInflater;", "impl", "Lcom/android/systemui/statusbar/policy/SmartActionInflaterImpl;", "bindSmartReplyInflater", "Lcom/android/systemui/statusbar/policy/SmartReplyInflater;", "Lcom/android/systemui/statusbar/policy/SmartReplyInflaterImpl;", "bindsInflatedSmartRepliesProvider", "Lcom/android/systemui/statusbar/policy/SmartReplyStateInflater;", "Lcom/android/systemui/statusbar/policy/SmartReplyStateInflaterImpl;"})
@dagger.Module()
public abstract interface SmartRepliesInflationModule {
    
    @org.jetbrains.annotations.NotNull()
    @dagger.Binds()
    public abstract com.android.systemui.statusbar.policy.SmartActionInflater bindSmartActionsInflater(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.SmartActionInflaterImpl impl);
    
    @org.jetbrains.annotations.NotNull()
    @dagger.Binds()
    public abstract com.android.systemui.statusbar.policy.SmartReplyInflater bindSmartReplyInflater(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.SmartReplyInflaterImpl impl);
    
    @org.jetbrains.annotations.NotNull()
    @dagger.Binds()
    public abstract com.android.systemui.statusbar.policy.SmartReplyStateInflater bindsInflatedSmartRepliesProvider(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.SmartReplyStateInflaterImpl impl);
}