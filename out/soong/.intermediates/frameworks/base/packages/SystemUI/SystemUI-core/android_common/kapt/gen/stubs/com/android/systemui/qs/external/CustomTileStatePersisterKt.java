package com.android.systemui.qs.external;

import android.content.ComponentName;
import android.content.Context;
import android.service.quicksettings.Tile;
import android.util.Log;
import com.android.internal.annotations.VisibleForTesting;
import org.json.JSONException;
import org.json.JSONObject;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0018\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\u001a\u0010\u0010\u0006\u001a\u00020\u00072\u0006\u0010\b\u001a\u00020\u0001H\u0001\u001a\u0010\u0010\t\u001a\u00020\u00012\u0006\u0010\n\u001a\u00020\u0007H\u0001\u001a\u0016\u0010\u000b\u001a\u0004\u0018\u00010\u0001*\u00020\f2\u0006\u0010\r\u001a\u00020\u0001H\u0002\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0003\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0004\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0005\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"CONTENT_DESCRIPTION", "", "LABEL", "STATE", "STATE_DESCRIPTION", "SUBTITLE", "readTileFromString", "Landroid/service/quicksettings/Tile;", "stateString", "writeToString", "tile", "getStringOrNull", "Lorg/json/JSONObject;", "name"})
public final class CustomTileStatePersisterKt {
    private static final java.lang.String STATE = "state";
    private static final java.lang.String LABEL = "label";
    private static final java.lang.String SUBTITLE = "subtitle";
    private static final java.lang.String CONTENT_DESCRIPTION = "content_description";
    private static final java.lang.String STATE_DESCRIPTION = "state_description";
    
    @org.jetbrains.annotations.NotNull()
    @com.android.internal.annotations.VisibleForTesting()
    public static final android.service.quicksettings.Tile readTileFromString(@org.jetbrains.annotations.NotNull()
    java.lang.String stateString) {
        return null;
    }
    
    private static final java.lang.String getStringOrNull(org.json.JSONObject $this$getStringOrNull, java.lang.String name) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @com.android.internal.annotations.VisibleForTesting()
    public static final java.lang.String writeToString(@org.jetbrains.annotations.NotNull()
    android.service.quicksettings.Tile tile) {
        return null;
    }
}