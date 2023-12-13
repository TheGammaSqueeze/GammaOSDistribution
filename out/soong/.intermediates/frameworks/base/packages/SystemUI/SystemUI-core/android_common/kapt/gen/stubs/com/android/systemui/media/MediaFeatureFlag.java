package com.android.systemui.media;

import android.content.Context;
import com.android.systemui.util.Utils;
import javax.inject.Inject;

/**
 * Provides access to the current value of the feature flag.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0002\u0018\u00002\u00020\u0001B\u000f\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0005\u001a\u00020\u00068F\u00a2\u0006\u0006\u001a\u0004\b\u0007\u0010\b"}, d2 = {"Lcom/android/systemui/media/MediaFeatureFlag;", "", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "enabled", "", "getEnabled", "()Z"})
public final class MediaFeatureFlag {
    private final android.content.Context context = null;
    
    public final boolean getEnabled() {
        return false;
    }
    
    @javax.inject.Inject()
    public MediaFeatureFlag(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
}