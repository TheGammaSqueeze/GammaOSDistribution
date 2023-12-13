package com.android.systemui.media;

import android.text.format.DateUtils;
import androidx.annotation.UiThread;
import androidx.lifecycle.Observer;
import com.android.systemui.R;

/**
 * Observer for changes from SeekBarViewModel.
 *
 * <p>Updates the seek bar views in response to changes to the model.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\t\n\u0002\u0010\u0002\n\u0002\b\u0003\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u0001B\r\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005J\u0010\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u0002H\u0017J\u0010\u0010\u0013\u001a\u00020\u00112\u0006\u0010\u0014\u001a\u00020\u0007H\u0007R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\tR\u0011\u0010\n\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\tR\u0011\u0010\f\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\tR\u0011\u0010\u000e\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\t"}, d2 = {"Lcom/android/systemui/media/SeekBarObserver;", "Landroidx/lifecycle/Observer;", "Lcom/android/systemui/media/SeekBarViewModel$Progress;", "holder", "Lcom/android/systemui/media/PlayerViewHolder;", "(Lcom/android/systemui/media/PlayerViewHolder;)V", "seekBarDisabledHeight", "", "getSeekBarDisabledHeight", "()I", "seekBarDisabledVerticalPadding", "getSeekBarDisabledVerticalPadding", "seekBarEnabledMaxHeight", "getSeekBarEnabledMaxHeight", "seekBarEnabledVerticalPadding", "getSeekBarEnabledVerticalPadding", "onChanged", "", "data", "setVerticalPadding", "padding"})
public final class SeekBarObserver implements androidx.lifecycle.Observer<com.android.systemui.media.SeekBarViewModel.Progress> {
    private final int seekBarEnabledMaxHeight = 0;
    private final int seekBarDisabledHeight = 0;
    private final int seekBarEnabledVerticalPadding = 0;
    private final int seekBarDisabledVerticalPadding = 0;
    private final com.android.systemui.media.PlayerViewHolder holder = null;
    
    public final int getSeekBarEnabledMaxHeight() {
        return 0;
    }
    
    public final int getSeekBarDisabledHeight() {
        return 0;
    }
    
    public final int getSeekBarEnabledVerticalPadding() {
        return 0;
    }
    
    public final int getSeekBarDisabledVerticalPadding() {
        return 0;
    }
    
    /**
     * Updates seek bar views when the data model changes.
     */
    @androidx.annotation.UiThread()
    @java.lang.Override()
    public void onChanged(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.SeekBarViewModel.Progress data) {
    }
    
    @androidx.annotation.UiThread()
    public final void setVerticalPadding(int padding) {
    }
    
    public SeekBarObserver(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.PlayerViewHolder holder) {
        super();
    }
}