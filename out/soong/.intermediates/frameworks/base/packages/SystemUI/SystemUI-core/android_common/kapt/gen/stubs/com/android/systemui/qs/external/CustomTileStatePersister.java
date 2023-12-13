package com.android.systemui.qs.external;

import android.content.ComponentName;
import android.content.Context;
import android.service.quicksettings.Tile;
import android.util.Log;
import com.android.internal.annotations.VisibleForTesting;
import org.json.JSONException;
import org.json.JSONObject;
import javax.inject.Inject;

/**
 * Persists and retrieves state for [CustomTile].
 *
 * This class will persists to a fixed [SharedPreference] file a state for a pair of [ComponentName]
 * and user id ([TileServiceKey]).
 *
 * It persists the state from a [Tile] necessary to present the view in the same state when
 * retrieved, with the exception of the icon.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000.\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u0000 \u00102\u00020\u0001:\u0001\u0010B\u000f\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0016\u0010\b\u001a\u00020\t2\u0006\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\rJ\u0010\u0010\u000e\u001a\u0004\u0018\u00010\r2\u0006\u0010\n\u001a\u00020\u000bJ\u000e\u0010\u000f\u001a\u00020\t2\u0006\u0010\n\u001a\u00020\u000bR\u0016\u0010\u0005\u001a\n \u0007*\u0004\u0018\u00010\u00060\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/external/CustomTileStatePersister;", "", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "sharedPreferences", "Landroid/content/SharedPreferences;", "kotlin.jvm.PlatformType", "persistState", "", "key", "Lcom/android/systemui/qs/external/TileServiceKey;", "tile", "Landroid/service/quicksettings/Tile;", "readState", "removeState", "Companion"})
public final class CustomTileStatePersister {
    private final android.content.SharedPreferences sharedPreferences = null;
    private static final java.lang.String FILE_NAME = "custom_tiles_state";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.qs.external.CustomTileStatePersister.Companion Companion = null;
    
    /**
     * Read the state from [SharedPreferences].
     *
     * Returns `null` if the tile has no saved state.
     *
     * Any fields that have not been saved will be set to `null`
     */
    @org.jetbrains.annotations.Nullable()
    public final android.service.quicksettings.Tile readState(@org.jetbrains.annotations.NotNull()
    com.android.systemui.qs.external.TileServiceKey key) {
        return null;
    }
    
    /**
     * Persists the state into [SharedPreferences].
     *
     * The implementation does not store fields that are `null` or icons.
     */
    public final void persistState(@org.jetbrains.annotations.NotNull()
    com.android.systemui.qs.external.TileServiceKey key, @org.jetbrains.annotations.NotNull()
    android.service.quicksettings.Tile tile) {
    }
    
    /**
     * Removes the state for a given tile, user pair.
     *
     * Used when the tile is removed by the user.
     */
    public final void removeState(@org.jetbrains.annotations.NotNull()
    com.android.systemui.qs.external.TileServiceKey key) {
    }
    
    @javax.inject.Inject()
    public CustomTileStatePersister(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/external/CustomTileStatePersister$Companion;", "", "()V", "FILE_NAME", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}