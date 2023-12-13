package com.android.systemui.qs;

import android.content.Context;
import android.util.AttributeSet;
import com.android.systemui.R;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0005\b\u0016\u0018\u00002\u00020\u0001B\u0017\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\b\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u00a2\u0006\u0002\u0010\u0006J\u000e\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\bJ\b\u0010\n\u001a\u00020\u000bH\u0016J\u0018\u0010\f\u001a\u00020\u000b2\u0006\u0010\r\u001a\u00020\b2\u0006\u0010\u000e\u001a\u00020\bH\u0016J\b\u0010\u000f\u001a\u00020\u000bH\u0016J\b\u0010\u0010\u001a\u00020\u000bH\u0014"}, d2 = {"Lcom/android/systemui/qs/SideLabelTileLayout;", "Lcom/android/systemui/qs/TileLayout;", "context", "Landroid/content/Context;", "attrs", "Landroid/util/AttributeSet;", "(Landroid/content/Context;Landroid/util/AttributeSet;)V", "getPhantomTopPosition", "", "index", "isFull", "", "updateMaxRows", "allowedHeight", "tilesCount", "updateResources", "useSidePadding"})
public class SideLabelTileLayout extends com.android.systemui.qs.TileLayout {
    
    @java.lang.Override()
    public boolean updateResources() {
        return false;
    }
    
    @java.lang.Override()
    public boolean isFull() {
        return false;
    }
    
    @java.lang.Override()
    protected boolean useSidePadding() {
        return false;
    }
    
    /**
     * Return the position from the top of the layout of the tile with this index.
     *
     * This will return a position even for indices that go beyond [maxTiles], continuing the rows
     * beyond that.
     */
    public final int getPhantomTopPosition(int index) {
        return 0;
    }
    
    @java.lang.Override()
    public boolean updateMaxRows(int allowedHeight, int tilesCount) {
        return false;
    }
    
    public SideLabelTileLayout(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs) {
        super(null);
    }
}