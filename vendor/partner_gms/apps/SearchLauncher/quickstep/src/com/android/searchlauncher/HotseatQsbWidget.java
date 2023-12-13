/*
 * Copyright (C) 2018 The Android Open Source Project
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

package com.android.searchlauncher;

import android.content.Context;
import android.graphics.Rect;
import android.text.Selection;
import android.text.Spannable;
import android.text.SpannableString;
import android.text.SpannableStringBuilder;
import android.text.method.TextKeyListener;
import android.util.AttributeSet;
import android.view.KeyEvent;
import android.view.View;

import com.android.launcher3.DeviceProfile;
import com.android.launcher3.ExtendedEditText;
import com.android.launcher3.Insettable;
import com.android.launcher3.Launcher;
import com.android.launcher3.R;
import com.android.launcher3.allapps.AllAppsContainerView;
import com.android.launcher3.allapps.AllAppsStore;
import com.android.launcher3.allapps.AlphabeticalAppsList;
import com.android.launcher3.allapps.SearchUiManager;
import com.android.launcher3.allapps.search.AllAppsSearchBarController;
import com.android.launcher3.allapps.AllAppsGridAdapter.AdapterItem;
import com.android.launcher3.allapps.search.DefaultAppSearchAlgorithm;
import com.android.launcher3.graphics.TintedDrawableSpan;
import com.android.launcher3.qsb.QsbContainerView;
import com.android.launcher3.search.SearchCallback;
import com.android.launcher3.views.ActivityContext;

import java.util.ArrayList;

public class HotseatQsbWidget extends QsbContainerView implements Insettable, SearchUiManager,
        SearchCallback<AdapterItem>, AllAppsStore.OnUpdateListener {

    private final ActivityContext mActivity;

    // This value was used to position the QSB. We store it here for translationY animations.
    private final int mFixedTranslationY;
    private final int mMarginTopAdjusting;

    private final AllAppsSearchBarController mSearchBarController;
    private final SpannableStringBuilder mSearchQueryBuilder;

    private AlphabeticalAppsList mApps;
    private AllAppsContainerView mAppsView;

    private View mSearchWrapperView;
    private ExtendedEditText mFallbackSearchView;

    public HotseatQsbWidget(Context context) {
        this(context, null);
    }

    public HotseatQsbWidget(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public HotseatQsbWidget(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        mActivity = ActivityContext.lookupContext(context);

        mFixedTranslationY =
                getResources().getDimensionPixelSize(R.dimen.search_widget_hotseat_height) / 2;
        mMarginTopAdjusting = getResources().getDimensionPixelSize(R.dimen.search_widget_top_shift);

        mSearchBarController = new AllAppsSearchBarController();

        mSearchQueryBuilder = new SpannableStringBuilder();
        Selection.setSelection(mSearchQueryBuilder, 0);
    }

    @Override
    protected void onFinishInflate() {
        super.onFinishInflate();

        mFallbackSearchView = findViewById(R.id.fallback_search_view);
        mSearchWrapperView = findViewById(R.id.search_wrapper_view);

        // Update the hint to contain the icon.
        // Prefix the original hint with two spaces. The first space gets replaced by the icon
        // using span. The second space is used for a singe space character between the hint
        // and the icon.
        SpannableString spanned = new SpannableString("  " + mFallbackSearchView.getHint());
        spanned.setSpan(new TintedDrawableSpan(getContext(), R.drawable.ic_allapps_search),
                0, 1, Spannable.SPAN_EXCLUSIVE_INCLUSIVE);
        mFallbackSearchView.setHint(spanned);
    }

    @Override
    protected void onAttachedToWindow() {
        super.onAttachedToWindow();
        if (mAppsView != null) {
            mAppsView.getAppsStore().addUpdateListener(this);
        }
    }

    @Override
    protected void onDetachedFromWindow() {
        super.onDetachedFromWindow();
        if (mAppsView != null) {
            mAppsView.getAppsStore().removeUpdateListener(this);
        }
    }

    @Override
    public void setInsets(Rect insets) {
        setVisibility(mActivity.getDeviceProfile().isVerticalBarLayout() ? GONE : VISIBLE);

        MarginLayoutParams mlp = (MarginLayoutParams) getLayoutParams();
        mlp.topMargin = Math.max(-mFixedTranslationY, insets.top - mMarginTopAdjusting);

        Rect padding = mActivity.getDeviceProfile().getHotseatLayoutPadding(getContext());
        setPaddingUnchecked(padding.left, 0, padding.right, 0);


        requestLayout();
    }

    @Override
    public void initializeSearch(AllAppsContainerView appsView) {
        mApps = appsView.getApps();
        mAppsView = appsView;
        mSearchBarController.initialize(new DefaultAppSearchAlgorithm(getContext()),
                mFallbackSearchView, Launcher.cast(mActivity), this);
    }

    @Override
    public void onAppsUpdated() {
        mSearchBarController.refreshSearchResult();
    }

    @Override
    public void resetSearch() {
        mSearchBarController.reset();
    }

    @Override
    public void preDispatchKeyEvent(KeyEvent event) {
        // Determine if the key event was actual text, if so, focus the search bar and then dispatch
        // the key normally so that it can process this key event
        if (!mSearchBarController.isSearchFieldFocused() &&
                event.getAction() == KeyEvent.ACTION_DOWN) {
            final int unicodeChar = event.getUnicodeChar();
            final boolean isKeyNotWhitespace = unicodeChar > 0 &&
                    !Character.isWhitespace(unicodeChar) && !Character.isSpaceChar(unicodeChar);
            if (isKeyNotWhitespace) {
                boolean gotKey = TextKeyListener.getInstance().onKeyDown(this, mSearchQueryBuilder,
                        event.getKeyCode(), event);
                if (gotKey && mSearchQueryBuilder.length() > 0) {
                    mSearchBarController.focusSearchField();
                }
            }
        }
    }

    @Override
    public void onSearchResult(String query, ArrayList<AdapterItem> results) {
        if (results != null) {
            mApps.setSearchResults(results);
            notifyResultChanged();
            mAppsView.setLastSearchQuery(query);
        }
    }

    @Override
    public void onAppendSearchResult(String query, ArrayList<AdapterItem> items) {
        if (items != null) {
            mApps.appendSearchResults(items);
            notifyResultChanged();
        }
    }

    @Override
    public void clearSearchResult() {
        if (mApps.setSearchResults(null)) {
            notifyResultChanged();
        }

        // Clear the search query
        mSearchQueryBuilder.clear();
        mSearchQueryBuilder.clearSpans();
        Selection.setSelection(mSearchQueryBuilder, 0);
        mAppsView.onClearSearchResult();
    }

    private void notifyResultChanged() {
        mAppsView.onSearchResultsChanged();
    }

    public float getScrollRangeDelta(Rect insets) {
        if (mActivity.getDeviceProfile().isVerticalBarLayout()) {
            return 0;
        } else {
            DeviceProfile dp = mActivity.getDeviceProfile();
            // Position the QSB in the space between the bottom of the hotseat icons and the
            // bottom of the insets.
            float percentageOfAvailSpaceFromBottom = 0.45f;
            int center = (int) ((dp.hotseatBarSizePx - dp.hotseatCellHeightPx
                    - getLayoutParams().height - insets.bottom) * percentageOfAvailSpaceFromBottom);
            int bottomMargin = insets.bottom + center;
            int topMargin = Math.max(-mFixedTranslationY, insets.top - mMarginTopAdjusting);
            int myBot = getLayoutParams().height + topMargin + mFixedTranslationY;
            return bottomMargin + myBot;
        }
    }

    @Override
    protected void onLayout(boolean changed, int left, int top, int right, int bottom) {
        super.onLayout(changed, left, top, right, bottom);
        offsetTopAndBottom(mFixedTranslationY);
    }

    @Override
    public ExtendedEditText getEditText() {
        return mFallbackSearchView;
    }

    public static class HotseatQsbFragment extends QsbFragment {

        @Override
        public boolean isQsbEnabled() {
            return true;
        }
    }
}
