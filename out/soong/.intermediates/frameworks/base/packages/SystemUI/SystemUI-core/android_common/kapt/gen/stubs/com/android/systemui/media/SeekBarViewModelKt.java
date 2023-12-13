package com.android.systemui.media;

import android.media.MediaMetadata;
import android.media.session.MediaController;
import android.media.session.PlaybackState;
import android.os.SystemClock;
import android.view.GestureDetector;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewConfiguration;
import android.widget.SeekBar;
import androidx.annotation.AnyThread;
import androidx.annotation.WorkerThread;
import androidx.core.view.GestureDetectorCompat;
import androidx.lifecycle.LiveData;
import androidx.lifecycle.MutableLiveData;
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.util.concurrency.RepeatableExecutor;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u001a\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\u001a\u0014\u0010\u0004\u001a\u00020\u0003*\u00020\u00052\u0006\u0010\u0006\u001a\u00020\u0003H\u0002\u001a\f\u0010\u0007\u001a\u00020\b*\u00020\u0005H\u0002\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0003X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"MIN_FLING_VELOCITY_SCALE_FACTOR", "", "POSITION_UPDATE_INTERVAL_MILLIS", "", "computePosition", "Landroid/media/session/PlaybackState;", "duration", "isInMotion", ""})
public final class SeekBarViewModelKt {
    private static final long POSITION_UPDATE_INTERVAL_MILLIS = 100L;
    private static final int MIN_FLING_VELOCITY_SCALE_FACTOR = 10;
    
    private static final boolean isInMotion(android.media.session.PlaybackState $this$isInMotion) {
        return false;
    }
    
    /**
     * Gets the playback position while accounting for the time since the [PlaybackState] was last
     * retrieved.
     *
     * This method closely follows the implementation of
     * [MediaSessionRecord#getStateWithUpdatedPosition].
     */
    private static final long computePosition(android.media.session.PlaybackState $this$computePosition, long duration) {
        return 0L;
    }
}