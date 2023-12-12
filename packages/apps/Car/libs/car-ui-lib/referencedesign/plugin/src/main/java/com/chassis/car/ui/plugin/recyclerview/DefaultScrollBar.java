/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.chassis.car.ui.plugin.recyclerview;

import static com.chassis.car.ui.plugin.Utils.getFloat;

import static java.lang.Math.max;
import static java.lang.Math.min;

import android.content.Context;
import android.content.res.Resources;
import android.os.Handler;
import android.os.Looper;
import android.util.SparseIntArray;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.AccelerateDecelerateInterpolator;
import android.view.animation.Interpolator;

import androidx.annotation.IntRange;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.annotation.VisibleForTesting;
import androidx.recyclerview.widget.OrientationHelper;
import androidx.recyclerview.widget.RecyclerView;
import androidx.recyclerview.widget.RecyclerView.LayoutManager;

import com.chassis.car.ui.plugin.R;

/**
 * <p>Inspired by {@link androidx.car.widget.PagedListView}. Most pagination and scrolling logic
 * has been ported from the PLV with minor updates.
 */
/* package */ final class DefaultScrollBar {

    private float mButtonDisabledAlpha;
    private SnapHelper mSnapHelper;

    private View mScrollView;
    private View mScrollTrack;
    private View mScrollThumb;
    private View mUpButton;
    private View mDownButton;
    private int mScrollbarThumbMinHeight;

    private Context mContext;
    private RecyclerView mRecyclerView;

    private final Interpolator mPaginationInterpolator = new AccelerateDecelerateInterpolator();

    private final Handler mHandler = new Handler(Looper.getMainLooper());

    private OrientationHelper mOrientationHelper;

    private OnContinuousScrollListener mPageUpOnContinuousScrollListener;
    private OnContinuousScrollListener mPageDownOnContinuousScrollListener;

    public void initialize(Context context, RecyclerView rv, View scrollView) {
        mContext = context;
        mRecyclerView = rv;

        mScrollView = scrollView;

        Resources res = context.getResources();

        mButtonDisabledAlpha = getFloat(res, R.dimen.button_disabled_alpha);
        mScrollbarThumbMinHeight = (int) context.getResources()
                .getDimension(R.dimen.scrollbar_min_thumb_height);

        mUpButton = mScrollView.requireViewById(R.id.scrollbar_page_up);
        View.OnClickListener paginateUpButtonOnClickListener = v -> pageUp();
        mUpButton.setOnClickListener(paginateUpButtonOnClickListener);
        mPageUpOnContinuousScrollListener = new OnContinuousScrollListener(context,
                paginateUpButtonOnClickListener);
        mUpButton.setOnTouchListener(mPageUpOnContinuousScrollListener);

        mDownButton = mScrollView.requireViewById(R.id.scrollbar_page_down);
        View.OnClickListener paginateDownButtonOnClickListener = v -> pageDown();
        mDownButton.setOnClickListener(paginateDownButtonOnClickListener);
        mPageDownOnContinuousScrollListener = new OnContinuousScrollListener(context,
                paginateDownButtonOnClickListener);
        mDownButton.setOnTouchListener(mPageDownOnContinuousScrollListener);

        mScrollTrack = mScrollView.requireViewById(R.id.scrollbar_track);
        mScrollThumb = mScrollView.requireViewById(R.id.scrollbar_thumb);

        mSnapHelper = new SnapHelper(context);
        getRecyclerView().setOnFlingListener(null);
        mSnapHelper.attachToRecyclerView(getRecyclerView());

        // enables fast scrolling.
        FastScroller fastScroller = new FastScroller(mRecyclerView, mScrollTrack, mScrollView);
        fastScroller.enable();

        getRecyclerView().addOnScrollListener(mRecyclerViewOnScrollListener);

        mScrollView.setVisibility(View.GONE);
        mScrollView.addOnLayoutChangeListener(
                (View v,
                        int left,
                        int top,
                        int right,
                        int bottom,
                        int oldLeft,
                        int oldTop,
                        int oldRight,
                        int oldBottom) -> mHandler.post(this::updatePaginationButtons));

        if (mRecyclerView.getAdapter() != null) {
            adapterChanged(mRecyclerView.getAdapter());
        }
    }

    public RecyclerView getRecyclerView() {
        return mRecyclerView;
    }

    public void requestLayout() {
        mScrollView.requestLayout();
    }

    public void setPadding(int paddingStart, int paddingEnd) {
        mScrollView.setPadding(mScrollView.getPaddingLeft(), paddingStart,
                mScrollView.getPaddingRight(), paddingEnd);
    }

    public void adapterChanged(@Nullable RecyclerView.Adapter<?> adapter) {
        try {
            if (mRecyclerView.getAdapter() != null) {
                mRecyclerView.getAdapter().unregisterAdapterDataObserver(mAdapterChangeObserver);
            }
        } catch (IllegalStateException e) {
            // adapter was not registered and we're trying to unregister again. ignore.
        }

        try {
            if (adapter != null) {
                adapter.registerAdapterDataObserver(mAdapterChangeObserver);
            }
        } catch (IllegalStateException e) {
            // adapter is already registered. and we're trying to register again. ignore.
        }
    }

    /**
     * Sets whether or not the up button on the scroll bar is clickable.
     *
     * @param enabled {@code true} if the up button is enabled.
     */
    private void setUpEnabled(boolean enabled) {
        // If the button is held down the button is disabled, the MotionEvent.ACTION_UP event on
        // button release will not be sent to cancel pending scrolls. Manually cancel any pending
        // scroll.
        if (!enabled) {
            mPageUpOnContinuousScrollListener.cancelPendingScroll();
        }

        mUpButton.setEnabled(enabled);
        mUpButton.setAlpha(enabled ? 1f : mButtonDisabledAlpha);
    }

    /**
     * Sets whether or not the down button on the scroll bar is clickable.
     *
     * @param enabled {@code true} if the down button is enabled.
     */
    private void setDownEnabled(boolean enabled) {
        // If the button is held down the button is disabled, the MotionEvent.ACTION_UP event on
        // button release will not be sent to cancel pending scrolls. Manually cancel any pending
        // scroll.
        if (!enabled) {
            mPageDownOnContinuousScrollListener.cancelPendingScroll();
        }

        mDownButton.setEnabled(enabled);
        mDownButton.setAlpha(enabled ? 1f : mButtonDisabledAlpha);
    }

    /**
     * Returns whether or not the down button on the scroll bar is clickable.
     *
     * @return {@code true} if the down button is enabled. {@code false} otherwise.
     */
    private boolean isDownEnabled() {
        return mDownButton.isEnabled();
    }

    /**
     * Sets the range, offset and extent of the scroll bar. The range represents the size of a
     * container for the scrollbar thumb; offset is the distance from the start of the container to
     * where the thumb should be; and finally, extent is the size of the thumb.
     *
     * <p>These values can be expressed in arbitrary units, so long as they share the same units.
     * The values should also be positive.
     *
     * @param range  The range of the scrollbar's thumb
     * @param offset The offset of the scrollbar's thumb
     * @param extent The extent of the scrollbar's thumb
     */
    private void setParameters(
            @IntRange(from = 0) int range,
            @IntRange(from = 0) int offset,
            @IntRange(from = 0) int extent) {
        // Not laid out yet, so values cannot be calculated.
        if (!mScrollView.isLaidOut()) {
            return;
        }

        // If the scroll bars aren't visible, then no need to update.
        if (mScrollView.getVisibility() != View.VISIBLE || range == 0) {
            return;
        }

        int thumbLength = calculateScrollThumbLength(range, extent);
        int thumbOffset = calculateScrollThumbOffset(range, offset, thumbLength);

        // Sets the size of the thumb and request a redraw if needed.
        ViewGroup.LayoutParams lp = mScrollThumb.getLayoutParams();

        if (lp.height != thumbLength || thumbLength < mScrollThumb.getHeight()) {
            lp.height = thumbLength;
            mScrollThumb.requestLayout();
        }

        moveY(mScrollThumb, thumbOffset);
    }

    /**
     * Calculates and returns how big the scroll bar thumb should be based on the given range and
     * extent.
     *
     * @param range  The total amount of space the scroll bar is allowed to roam over.
     * @param extent The amount of space that the scroll bar takes up relative to the range.
     * @return The height of the scroll bar thumb in pixels.
     */
    private int calculateScrollThumbLength(int range, int extent) {
        // Scale the length by the available space that the thumb can fill.
        return max(Math.round(((float) extent / range) * mScrollTrack.getHeight()),
                min(mScrollbarThumbMinHeight, mScrollTrack.getHeight()));
    }

    /**
     * Calculates and returns how much the scroll thumb should be offset from the top of where it
     * has been laid out.
     *
     * @param range       The total amount of space the scroll bar is allowed to roam over.
     * @param offset      The amount the scroll bar should be offset, expressed in the same units as
     *                    the given range.
     * @param thumbLength The current length of the thumb in pixels.
     * @return The amount the thumb should be offset in pixels.
     */
    private int calculateScrollThumbOffset(int range, int offset, int thumbLength) {
        // Ensure that if the user has reached the bottom of the list, then the scroll bar is
        // aligned to the bottom as well. Otherwise, scale the offset appropriately.
        // This offset will be a value relative to the parent of this scrollbar, so start by where
        // the top of scrollbar track is.
        return mScrollTrack.getTop()
                + (isDownEnabled()
                ? Math.round(((float) offset / range) * (mScrollTrack.getHeight() - thumbLength))
                : mScrollTrack.getHeight() - thumbLength);
    }

    /**
     * Moves the given view to the specified 'y' position.
     */
    private void moveY(final View view, float newPosition) {
        view.animate()
                .y(newPosition)
                .setDuration(/* duration= */ 0)
                .setInterpolator(mPaginationInterpolator)
                .start();
    }

    private final RecyclerView.OnScrollListener mRecyclerViewOnScrollListener =
            new RecyclerView.OnScrollListener() {
                @Override
                public void onScrolled(@NonNull RecyclerView recyclerView, int dx, int dy) {
                    updatePaginationButtons();
                    cacheChildrenHeight(recyclerView.getLayoutManager());
                }
            };
    private final SparseIntArray mChildHeightByAdapterPosition = new SparseIntArray();

    private final RecyclerView.AdapterDataObserver mAdapterChangeObserver =
            new RecyclerView.AdapterDataObserver() {
                @Override
                public void onChanged() {
                    clearCachedHeights();
                }
                @Override
                public void onItemRangeChanged(int positionStart, int itemCount, Object payload) {
                    clearCachedHeights();
                }
                @Override
                public void onItemRangeChanged(int positionStart, int itemCount) {
                    clearCachedHeights();
                }
                @Override
                public void onItemRangeInserted(int positionStart, int itemCount) {
                    clearCachedHeights();
                }
                @Override
                public void onItemRangeMoved(int fromPosition, int toPosition, int itemCount) {
                    clearCachedHeights();
                }
                @Override
                public void onItemRangeRemoved(int positionStart, int itemCount) {
                    clearCachedHeights();
                }
            };

    private void clearCachedHeights() {
        mChildHeightByAdapterPosition.clear();
        cacheChildrenHeight(getLayoutManager());
    }

    private void cacheChildrenHeight(@Nullable LayoutManager layoutManager) {
        if (layoutManager == null) {
            return;
        }
        for (int i = 0; i < layoutManager.getChildCount(); i++) {
            View child = layoutManager.getChildAt(i);
            if (child != null) {
                int childPosition = layoutManager.getPosition(child);
                if (mChildHeightByAdapterPosition.indexOfKey(childPosition) < 0) {
                    mChildHeightByAdapterPosition.put(childPosition, child.getHeight());
                }
            }
        }
    }

    private int estimateNextPositionScrollUp(int currentPos, int scrollDistance,
            OrientationHelper orientationHelper) {
        int nextPos = 0;
        int distance = 0;
        for (int i = currentPos - 1; i >= 0; i--) {
            if (mChildHeightByAdapterPosition.indexOfKey(i) < 0) {
                // Use the average height estimate when there is not enough data
                nextPos = mSnapHelper.estimateNextPositionDiffForScrollDistance(
                        orientationHelper, -scrollDistance);
                break;
            }
            if ((distance + mChildHeightByAdapterPosition.get(i)) > Math.abs(scrollDistance)) {
                nextPos = i - currentPos + 1;
                break;
            }
            distance += mChildHeightByAdapterPosition.get(i);
        }
        return nextPos;
    }

    private OrientationHelper getOrientationHelper(LayoutManager layoutManager) {
        if (mOrientationHelper == null || mOrientationHelper.getLayoutManager() != layoutManager) {
            // RecyclerViewImpl is assumed to be a list that always vertically scrolls.
            mOrientationHelper = OrientationHelper.createVerticalHelper(layoutManager);
        }
        return mOrientationHelper;
    }

    /**
     * Scrolls the contents of the RecyclerView up a page. A page is defined as the height of the
     * {@code RecyclerViewImpl}.
     *
     * <p>The resulting first item in the list will be snapped to so that it is completely visible.
     * If this is not possible due to the first item being taller than the containing {@code
     * RecyclerViewImpl}, then the snapping will not occur.
     */
    void pageUp() {
        int currentOffset = computeVerticalScrollOffset();
        LayoutManager layoutManager = getLayoutManager();
        if (layoutManager == null || layoutManager.getChildCount() == 0 || currentOffset == 0) {
            return;
        }

        // Use OrientationHelper to calculate scroll distance in order to match snapping behavior.
        OrientationHelper orientationHelper = getOrientationHelper(layoutManager);
        int scrollDistance = orientationHelper.getTotalSpace();

        View currentPosView = getFirstMostVisibleChild(orientationHelper);
        int currentPos = currentPosView != null ? getLayoutManager().getPosition(
                currentPosView) : 0;
        int nextPos = estimateNextPositionScrollUp(currentPos,
                scrollDistance - Math.max(0, orientationHelper.getStartAfterPadding()
                        - orientationHelper.getDecoratedStart(currentPosView)), orientationHelper);
        if (nextPos == 0) {
            // Distance should always be positive. Negate its value to scroll up.
            smoothScrollBy(0, -scrollDistance);
        } else {
            smoothScrollToPosition(Math.max(0, currentPos + nextPos));
        }
    }

    private View getFirstMostVisibleChild(OrientationHelper helper) {
        float mostVisiblePercent = 0;
        View mostVisibleView = null;

        for (int i = 0; i < getLayoutManager().getChildCount(); i++) {
            View child = getLayoutManager().getChildAt(i);
            float visiblePercentage = SnapHelper.getPercentageVisible(child, helper);
            if (visiblePercentage == 1f) {
                mostVisibleView = child;
                break;
            } else if (visiblePercentage > mostVisiblePercent) {
                mostVisiblePercent = visiblePercentage;
                mostVisibleView = child;
            }
        }

        return mostVisibleView;
    }

    /**
     * Scrolls the contents of the RecyclerView down a page. A page is defined as the height of the
     * {@code RecyclerViewImpl}.
     *
     * <p>This method will attempt to bring the last item in the list as the first item. If the
     * current first item in the list is taller than the {@code RecyclerViewImpl}, then it will be
     * scrolled the length of a page, but not snapped to.
     */
    void pageDown() {
        LayoutManager layoutManager = getLayoutManager();
        if (layoutManager == null || layoutManager.getChildCount() == 0) {
            return;
        }

        OrientationHelper orientationHelper = getOrientationHelper(layoutManager);
        int screenSize = orientationHelper.getTotalSpace();
        int scrollDistance = screenSize;

        View currentPosView = getFirstMostVisibleChild(orientationHelper);

        // If current view is partially visible and bottom of the view is below visible area of
        // the recyclerview either scroll down one page (screenSize) or enough to align the bottom
        // of the view with the bottom of the recyclerview. Note that this will not cause a snap,
        // because the current view is already snapped to the top or it wouldn't be the most
        // visible view.
        if (layoutManager.isViewPartiallyVisible(currentPosView,
                /* completelyVisible= */ false, /* acceptEndPointInclusion= */ false)
                        && orientationHelper.getDecoratedEnd(currentPosView)
                                > orientationHelper.getEndAfterPadding()) {
            scrollDistance = Math.min(screenSize,
                    orientationHelper.getDecoratedEnd(currentPosView)
                            - orientationHelper.getEndAfterPadding());
        }

        // Iterate over the childview (bottom to top) and stop when we find the first
        // view that we can snap to and the scroll size is less than max scroll size (screenSize)
        for (int i = layoutManager.getChildCount() - 1; i >= 0; i--) {
            View child = layoutManager.getChildAt(i);

            // Ignore the child if it's above the currentview, as scrolldown will only move down.
            // Note that in case of gridview, child will not be the same as the currentview.
            if (orientationHelper.getDecoratedStart(child)
                    <= orientationHelper.getDecoratedStart(currentPosView)) {
                break;
            }

            // Ignore the child if the scroll distance is bigger than the max scroll size
            if (orientationHelper.getDecoratedStart(child)
                    - orientationHelper.getStartAfterPadding() <= screenSize) {
                // If the child is already fully visible we can scroll even further.
                if (orientationHelper.getDecoratedEnd(child)
                        <= orientationHelper.getEndAfterPadding()) {
                    scrollDistance = orientationHelper.getDecoratedEnd(child)
                            - orientationHelper.getStartAfterPadding();
                } else {
                    scrollDistance = orientationHelper.getDecoratedStart(child)
                            - orientationHelper.getStartAfterPadding();
                }
                break;
            }
        }

        smoothScrollBy(0, scrollDistance);
    }

    /**
     * Determines if scrollbar should be visible or not and shows/hides it accordingly. If this is
     * being called as a result of adapter changes, it should be called after the new layout has
     * been calculated because the method of determining scrollbar visibility uses the current
     * layout. If this is called after an adapter change but before the new layout, the visibility
     * determination may not be correct.
     */
    private void updatePaginationButtons() {
        LayoutManager layoutManager = getLayoutManager();

        if (layoutManager == null) {
            mScrollView.setVisibility(View.GONE);
            return;
        }

        boolean isAtStart = isAtStart();
        boolean isAtEnd = isAtEnd();

        // enable/disable the button before the view is shown. So there is no flicker.
        setUpEnabled(!isAtStart);
        setDownEnabled(!isAtEnd);

        boolean isScrollViewVisiblePreUpdate = mScrollView.getVisibility() == View.VISIBLE;
        boolean isLayoutRequired = false;

        if ((isAtStart && isAtEnd) || layoutManager.getItemCount() == 0) {
            mScrollView.setVisibility(View.GONE);
        } else {
            OrientationHelper orientationHelper = getOrientationHelper(layoutManager);
            int screenSize = orientationHelper.getTotalSpace();
            int touchTargetSize = (int) mContext.getResources()
                    .getDimension(R.dimen.scrollbar_button_size);
            ViewGroup.MarginLayoutParams upButtonLayoutParam =
                    (ViewGroup.MarginLayoutParams) mUpButton.getLayoutParams();
            int upButtonMargin = upButtonLayoutParam.topMargin
                    + upButtonLayoutParam.bottomMargin;
            ViewGroup.MarginLayoutParams downButtonLayoutParam =
                    (ViewGroup.MarginLayoutParams) mDownButton.getLayoutParams();
            int downButtonMargin = downButtonLayoutParam.topMargin
                    + downButtonLayoutParam.bottomMargin;
            int margin = upButtonMargin + downButtonMargin;
            if (screenSize < 2 * touchTargetSize + margin) {
                if (isScrollViewVisiblePreUpdate) {
                    isLayoutRequired = true;
                }
                mScrollView.setVisibility(View.GONE);
            } else {
                ViewGroup.MarginLayoutParams trackLayoutParam =
                        (ViewGroup.MarginLayoutParams) mScrollTrack.getLayoutParams();
                int trackMargin = trackLayoutParam.topMargin
                        + trackLayoutParam.bottomMargin;
                margin += trackMargin;
                // touchTargetSize (for up button) + touchTargetSize (for down button)
                // + max(touchTargetSize, mScrollbarThumbMinHeight)
                // + margin (all margins added together)
                if (screenSize < 2 * touchTargetSize
                        + max(touchTargetSize, mScrollbarThumbMinHeight) + margin) {
                    mScrollTrack.setVisibility(View.INVISIBLE);
                    mScrollThumb.setVisibility(View.INVISIBLE);
                } else {
                    mScrollTrack.setVisibility(View.VISIBLE);
                    mScrollThumb.setVisibility(View.VISIBLE);
                }

                if (!isScrollViewVisiblePreUpdate) {
                    isLayoutRequired = true;
                }
                mScrollView.setVisibility(View.VISIBLE);
            }
        }

        if (layoutManager.canScrollVertically()) {
            setParameters(
                    computeVerticalScrollRange(),
                    computeVerticalScrollOffset(),
                    computeVerticalScrollExtent());
        } else {
            setParameters(
                    computeHorizontalScrollRange(),
                    computeHorizontalScrollOffset(),
                    computeHorizontalScrollExtent());
        }

        mScrollView.invalidate();
        // updatePaginationButtons() is called from onLayoutChangeListener, request layout only when
        // required to avoid infinite loop.
        if (isLayoutRequired) {
            // If currently performing a layout pass, layout update may not be picked up until the
            // next layout pass. Schedule another layout pass to ensure changes take affect.
            mScrollView.post(() -> mScrollView.requestLayout());
        }
    }

    /**
     * Returns {@code true} if the RecyclerView is completely displaying the first item.
     */
    public boolean isAtStart() {
        return mSnapHelper.isAtStart(getLayoutManager());
    }

    public void setHighlightThumb(boolean highlight) {
        mScrollThumb.setActivated(highlight);
    }

    /**
     * Returns {@code true} if the RecyclerView is completely displaying the last item.
     */
    boolean isAtEnd() {
        return mSnapHelper.isAtEnd(getLayoutManager());
    }

    @VisibleForTesting
    LayoutManager getLayoutManager() {
        return getRecyclerView().getLayoutManager();
    }

    @VisibleForTesting
    void smoothScrollToPosition(int max) {
        getRecyclerView().smoothScrollToPosition(max);
    }

    @VisibleForTesting
    void smoothScrollBy(int dx, int dy) {
        getRecyclerView().smoothScrollBy(dx, dy);
    }

    @VisibleForTesting
    int computeVerticalScrollRange() {
        return getRecyclerView().computeVerticalScrollRange();
    }

    @VisibleForTesting
    int computeVerticalScrollOffset() {
        return getRecyclerView().computeVerticalScrollOffset();
    }

    @VisibleForTesting
    int computeVerticalScrollExtent() {
        return getRecyclerView().computeVerticalScrollExtent();
    }

    @VisibleForTesting
    int computeHorizontalScrollRange() {
        return getRecyclerView().computeHorizontalScrollRange();
    }

    @VisibleForTesting
    int computeHorizontalScrollOffset() {
        return getRecyclerView().computeHorizontalScrollOffset();
    }

    @VisibleForTesting
    int computeHorizontalScrollExtent() {
        return getRecyclerView().computeHorizontalScrollExtent();
    }
}
