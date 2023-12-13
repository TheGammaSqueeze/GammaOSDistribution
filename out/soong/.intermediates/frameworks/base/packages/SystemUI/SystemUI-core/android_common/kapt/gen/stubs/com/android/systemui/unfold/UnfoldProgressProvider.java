package com.android.systemui.unfold;

import com.android.systemui.unfold.UnfoldTransitionProgressProvider.TransitionProgressListener;
import com.android.wm.shell.unfold.ShellUnfoldProgressProvider;
import com.android.wm.shell.unfold.ShellUnfoldProgressProvider.UnfoldListener;
import java.util.concurrent.Executor;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\"\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0018\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nH\u0016R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/unfold/UnfoldProgressProvider;", "Lcom/android/wm/shell/unfold/ShellUnfoldProgressProvider;", "unfoldProgressProvider", "Lcom/android/systemui/unfold/UnfoldTransitionProgressProvider;", "(Lcom/android/systemui/unfold/UnfoldTransitionProgressProvider;)V", "addListener", "", "executor", "Ljava/util/concurrent/Executor;", "listener", "Lcom/android/wm/shell/unfold/ShellUnfoldProgressProvider$UnfoldListener;"})
public final class UnfoldProgressProvider implements com.android.wm.shell.unfold.ShellUnfoldProgressProvider {
    private final com.android.systemui.unfold.UnfoldTransitionProgressProvider unfoldProgressProvider = null;
    
    @java.lang.Override()
    public void addListener(@org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor executor, @org.jetbrains.annotations.NotNull()
    com.android.wm.shell.unfold.ShellUnfoldProgressProvider.UnfoldListener listener) {
    }
    
    public UnfoldProgressProvider(@org.jetbrains.annotations.NotNull()
    com.android.systemui.unfold.UnfoldTransitionProgressProvider unfoldProgressProvider) {
        super();
    }
}