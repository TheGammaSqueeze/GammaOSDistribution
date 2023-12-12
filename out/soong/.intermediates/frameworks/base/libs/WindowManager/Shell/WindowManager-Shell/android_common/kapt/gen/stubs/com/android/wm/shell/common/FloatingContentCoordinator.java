package com.android.wm.shell.common;

import android.graphics.Rect;
import android.util.Log;
import com.android.wm.shell.common.FloatingContentCoordinator.FloatingContent;
import java.util.HashMap;

/**
 * Coordinates the positions and movement of floating content, such as PIP and Bubbles, to ensure
 * that they don't overlap. If content does overlap due to content appearing or moving, the
 * coordinator will ask content to move to resolve the conflict.
 *
 * After implementing [FloatingContent], content should call [onContentAdded] to begin coordination.
 * Subsequently, call [onContentMoved] whenever the content moves, and the coordinator will move
 * other content out of the way. [onContentRemoved] should be called when the content is removed or
 * no longer visible.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000.\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010%\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u001e\n\u0000\n\u0002\u0010\u0002\n\u0002\b\n\u0018\u0000 \u00152\u00020\u0001:\u0002\u0015\u0016B\u0005\u00a2\u0006\u0002\u0010\u0002J\f\u0010\t\u001a\b\u0012\u0004\u0012\u00020\u00060\nJ\u0010\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u0005H\u0002J\u000e\u0010\u000e\u001a\u00020\f2\u0006\u0010\u000f\u001a\u00020\u0005J\u000e\u0010\u0010\u001a\u00020\f2\u0006\u0010\u0011\u001a\u00020\u0005J\u000e\u0010\u0012\u001a\u00020\f2\u0006\u0010\u0013\u001a\u00020\u0005J\b\u0010\u0014\u001a\u00020\fH\u0002R\u001a\u0010\u0003\u001a\u000e\u0012\u0004\u0012\u00020\u0005\u0012\u0004\u0012\u00020\u00060\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/wm/shell/common/FloatingContentCoordinator;", "", "()V", "allContentBounds", "", "Lcom/android/wm/shell/common/FloatingContentCoordinator$FloatingContent;", "Landroid/graphics/Rect;", "currentlyResolvingConflicts", "", "getOccupiedBounds", "", "maybeMoveConflictingContent", "", "fromContent", "onContentAdded", "newContent", "onContentMoved", "content", "onContentRemoved", "removedContent", "updateContentBounds", "Companion", "FloatingContent"})
public final class FloatingContentCoordinator {
    
    /**
     * The bounds of all pieces of floating content added to the coordinator.
     */
    private final java.util.Map<com.android.wm.shell.common.FloatingContentCoordinator.FloatingContent, android.graphics.Rect> allContentBounds = null;
    
    /**
     * Whether we are currently resolving conflicts by asking content to move. If we are, we'll
     * temporarily ignore calls to [onContentMoved] - those calls are from the content that is
     * moving to new, conflict-free bounds, so we don't need to perform conflict detection
     * calculations in response.
     */
    private boolean currentlyResolvingConflicts = false;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.wm.shell.common.FloatingContentCoordinator.Companion Companion = null;
    
    /**
     * Makes the coordinator aware of a new piece of floating content, and moves any existing
     * content out of the way, if necessary.
     *
     * If you don't want your new content to move existing content, use [getOccupiedBounds] to find
     * an unoccupied area, and move the content there before calling this method.
     */
    public final void onContentAdded(@org.jetbrains.annotations.NotNull()
    com.android.wm.shell.common.FloatingContentCoordinator.FloatingContent newContent) {
    }
    
    /**
     * Called to notify the coordinator that a piece of floating content has moved (or is animating)
     * to a new position, and that any conflicting floating content should be moved out of the way.
     *
     * The coordinator will call [FloatingContent.getFloatingBoundsOnScreen] to find the new bounds
     * for the moving content. If you're animating the content, be sure that your implementation of
     * getFloatingBoundsOnScreen returns the bounds to which it's animating, not the content's
     * current bounds.
     *
     * If the animation moving this content is cancelled or updated, you'll need to call this method
     * again, to ensure that content is moved out of the way of the latest bounds.
     *
     * @param content The content that has moved.
     */
    public final void onContentMoved(@org.jetbrains.annotations.NotNull()
    com.android.wm.shell.common.FloatingContentCoordinator.FloatingContent content) {
    }
    
    /**
     * Called to notify the coordinator that a piece of floating content has been removed or is no
     * longer visible.
     */
    public final void onContentRemoved(@org.jetbrains.annotations.NotNull()
    com.android.wm.shell.common.FloatingContentCoordinator.FloatingContent removedContent) {
    }
    
    /**
     * Returns a set of Rects that represent the bounds of all of the floating content on the
     * screen.
     *
     * [onContentAdded] will move existing content out of the way if the added content intersects
     * existing content. That's fine - but if your specific starting position is not important, you
     * can use this function to find unoccupied space for your content before calling
     * [onContentAdded], so that moving existing content isn't necessary.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.Collection<android.graphics.Rect> getOccupiedBounds() {
        return null;
    }
    
    /**
     * Identifies any pieces of content that are now overlapping with the given content, and asks
     * them to move out of the way.
     */
    private final void maybeMoveConflictingContent(com.android.wm.shell.common.FloatingContentCoordinator.FloatingContent fromContent) {
    }
    
    /**
     * Update [allContentBounds] by calling [FloatingContent.getFloatingBoundsOnScreen] for all
     * content and saving the result.
     */
    private final void updateContentBounds() {
    }
    
    public FloatingContentCoordinator() {
        super();
    }
    
    /**
     * Finds new bounds for the given content, either above or below its current position. The
     * new bounds won't intersect with the newly overlapping rect or the exclusion rects, and
     * will be within the allowed bounds unless no possible position exists.
     *
     * You can use this method to help find a new position for your content when the coordinator
     * calls [FloatingContent.moveToAreaExcluding].
     *
     * @param contentRect The bounds of the content for which we're finding a new home.
     * @param newlyOverlappingRect The bounds of the content that forced this relocation by
     * intersecting with the content we now need to move. If the overlapping content is
     * overlapping the top half of this content, we'll try to move this content downward if
     * possible (since the other content is 'pushing' it down), and vice versa.
     * @param exclusionRects Any other areas that we need to avoid when finding a new home for
     * the content. These areas must be non-overlapping with each other.
     * @param allowedBounds The area within which we're allowed to find new bounds for the
     * content.
     * @return New bounds for the content that don't intersect the exclusion rects or the
     * newly overlapping rect, and that is within bounds - or an empty Rect if no in-bounds
     * position exists.
     */
    @org.jetbrains.annotations.NotNull()
    public static final android.graphics.Rect findAreaForContentVertically(@org.jetbrains.annotations.NotNull()
    android.graphics.Rect contentRect, @org.jetbrains.annotations.NotNull()
    android.graphics.Rect newlyOverlappingRect, @org.jetbrains.annotations.NotNull()
    java.util.Collection<android.graphics.Rect> exclusionRects, @org.jetbrains.annotations.NotNull()
    android.graphics.Rect allowedBounds) {
        return null;
    }
    
    /**
     * Represents a piece of floating content, such as PIP or the Bubbles stack. Provides methods
     * that allow the [FloatingContentCoordinator] to determine the current location of the content,
     * as well as the ability to ask it to move out of the way of other content.
     *
     * The default implementation of [calculateNewBoundsOnOverlap] moves the content up or down,
     * depending on the position of the conflicting content. You can override this method if you
     * want your own custom conflict resolution logic.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\bf\u0018\u00002\u00020\u0001J\u001e\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00032\f\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00030\u0006H\u0017J\b\u0010\u0007\u001a\u00020\u0003H&J\b\u0010\b\u001a\u00020\u0003H&J\u0010\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\u0003H&\u00f8\u0001\u0000\u0082\u0002\u0007\n\u0005\b\u0091(0\u0001"}, d2 = {"Lcom/android/wm/shell/common/FloatingContentCoordinator$FloatingContent;", "", "calculateNewBoundsOnOverlap", "Landroid/graphics/Rect;", "overlappingContentBounds", "otherContentBounds", "", "getAllowedFloatingBoundsRegion", "getFloatingBoundsOnScreen", "moveToBounds", "", "bounds"})
    public static abstract interface FloatingContent {
        
        /**
         * Return the bounds claimed by this content. This should include the bounds occupied by the
         * content itself, as well as any padding, if desired. The coordinator will ensure that no
         * other content is located within these bounds.
         *
         * If the content is animating, this method should return the bounds to which the content is
         * animating. If that animation is cancelled, or updated, be sure that your implementation
         * of this method returns the appropriate bounds, and call [onContentMoved] so that the
         * coordinator moves other content out of the way.
         */
        @org.jetbrains.annotations.NotNull()
        public abstract android.graphics.Rect getFloatingBoundsOnScreen();
        
        /**
         * Return the area within which this floating content is allowed to move. When resolving
         * conflicts, the coordinator will never ask your content to move to a position where any
         * part of the content would be out of these bounds.
         */
        @org.jetbrains.annotations.NotNull()
        public abstract android.graphics.Rect getAllowedFloatingBoundsRegion();
        
        /**
         * Called when the coordinator needs this content to move to the given bounds. It's up to
         * you how to do that.
         *
         * Note that if you start an animation to these bounds, [getFloatingBoundsOnScreen] should
         * return the destination bounds, not the in-progress animated bounds. This is so the
         * coordinator knows where floating content is going to be and can resolve conflicts
         * accordingly.
         */
        public abstract void moveToBounds(@org.jetbrains.annotations.NotNull()
        android.graphics.Rect bounds);
        
        /**
         * Called by the coordinator when it needs to find a new home for this floating content,
         * because a new or moving piece of content is now overlapping with it.
         *
         * [findAreaForContentVertically] and [findAreaForContentAboveOrBelow] are helpful utility
         * functions that will find new bounds for your content automatically. Unless you require
         * specific conflict resolution logic, these should be sufficient. By default, this method
         * delegates to [findAreaForContentVertically].
         *
         * @param overlappingContentBounds The bounds of the other piece of content, which
         * necessitated this content's relocation. Your new position must not overlap with these
         * bounds.
         * @param otherContentBounds The bounds of any other pieces of floating content. Your new
         * position must not overlap with any of these either. These bounds are guaranteed to be
         * non-overlapping.
         * @return The new bounds for this content.
         */
        @org.jetbrains.annotations.NotNull()
        public default android.graphics.Rect calculateNewBoundsOnOverlap(@org.jetbrains.annotations.NotNull()
        android.graphics.Rect overlappingContentBounds, @org.jetbrains.annotations.NotNull()
        java.util.List<android.graphics.Rect> otherContentBounds) {
            return null;
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\"\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u001e\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0006\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J$\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u00042\f\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\u00040\u00072\u0006\u0010\b\u001a\u00020\tJ.\u0010\n\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u00042\u0006\u0010\u000b\u001a\u00020\u00042\f\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\u00040\u00072\u0006\u0010\f\u001a\u00020\u0004H\u0007J\u0018\u0010\r\u001a\u00020\t2\u0006\u0010\u000e\u001a\u00020\u00042\u0006\u0010\u000f\u001a\u00020\u0004H\u0002"}, d2 = {"Lcom/android/wm/shell/common/FloatingContentCoordinator$Companion;", "", "()V", "findAreaForContentAboveOrBelow", "Landroid/graphics/Rect;", "contentRect", "exclusionRects", "", "findAbove", "", "findAreaForContentVertically", "newlyOverlappingRect", "allowedBounds", "rectsIntersectVertically", "r1", "r2"})
    public static final class Companion {
        
        /**
         * Finds new bounds for the given content, either above or below its current position. The
         * new bounds won't intersect with the newly overlapping rect or the exclusion rects, and
         * will be within the allowed bounds unless no possible position exists.
         *
         * You can use this method to help find a new position for your content when the coordinator
         * calls [FloatingContent.moveToAreaExcluding].
         *
         * @param contentRect The bounds of the content for which we're finding a new home.
         * @param newlyOverlappingRect The bounds of the content that forced this relocation by
         * intersecting with the content we now need to move. If the overlapping content is
         * overlapping the top half of this content, we'll try to move this content downward if
         * possible (since the other content is 'pushing' it down), and vice versa.
         * @param exclusionRects Any other areas that we need to avoid when finding a new home for
         * the content. These areas must be non-overlapping with each other.
         * @param allowedBounds The area within which we're allowed to find new bounds for the
         * content.
         * @return New bounds for the content that don't intersect the exclusion rects or the
         * newly overlapping rect, and that is within bounds - or an empty Rect if no in-bounds
         * position exists.
         */
        @org.jetbrains.annotations.NotNull()
        public final android.graphics.Rect findAreaForContentVertically(@org.jetbrains.annotations.NotNull()
        android.graphics.Rect contentRect, @org.jetbrains.annotations.NotNull()
        android.graphics.Rect newlyOverlappingRect, @org.jetbrains.annotations.NotNull()
        java.util.Collection<android.graphics.Rect> exclusionRects, @org.jetbrains.annotations.NotNull()
        android.graphics.Rect allowedBounds) {
            return null;
        }
        
        /**
         * Finds a new position for the given content, either above or below its current position
         * depending on whether [findAbove] is true or false, respectively. This new position will
         * not intersect with any of the [exclusionRects].
         *
         * This method is useful as a helper method for implementing your own conflict resolution
         * logic. Otherwise, you'd want to use [findAreaForContentVertically], which takes screen
         * bounds and conflicting bounds' location into account when deciding whether to move to new
         * bounds above or below the current bounds.
         *
         * @param contentRect The content we're finding an area for.
         * @param exclusionRects The areas we need to avoid when finding a new area for the content.
         * These areas must be non-overlapping with each other.
         * @param findAbove Whether we are finding an area above the content's current position,
         * rather than an area below it.
         */
        @org.jetbrains.annotations.NotNull()
        public final android.graphics.Rect findAreaForContentAboveOrBelow(@org.jetbrains.annotations.NotNull()
        android.graphics.Rect contentRect, @org.jetbrains.annotations.NotNull()
        java.util.Collection<android.graphics.Rect> exclusionRects, boolean findAbove) {
            return null;
        }
        
        /**
         * Returns whether or not the two Rects share any of the same space on the X axis.
         */
        private final boolean rectsIntersectVertically(android.graphics.Rect r1, android.graphics.Rect r2) {
            return false;
        }
        
        private Companion() {
            super();
        }
    }
}