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
package com.android.car.notification.template;

import static android.app.Notification.EXTRA_SUBSTITUTE_APP_NAME;

import android.annotation.Nullable;
import android.app.Notification;
import android.car.drivingstate.CarUxRestrictions;
import android.car.drivingstate.CarUxRestrictionsManager;
import android.content.Context;
import android.content.pm.PackageManager;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.drawable.Drawable;
import android.service.notification.StatusBarNotification;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.cardview.widget.CardView;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import androidx.recyclerview.widget.SimpleItemAnimator;

import com.android.car.notification.AlertEntry;
import com.android.car.notification.CarNotificationItemTouchListener;
import com.android.car.notification.CarNotificationViewAdapter;
import com.android.car.notification.NotificationClickHandlerFactory;
import com.android.car.notification.NotificationGroup;
import com.android.car.notification.R;

import java.util.ArrayList;
import java.util.List;

/**
 * ViewHolder that binds a list of notifications as a grouped notification.
 */
public class GroupNotificationViewHolder extends CarNotificationBaseViewHolder
        implements CarUxRestrictionsManager.OnUxRestrictionsChangedListener {
    private static final String TAG = "GroupNotificationViewHolder";

    private final Context mContext;
    private final CardView mCardView;
    private final View mHeaderDividerView;
    private final View mExpandedGroupHeader;
    private final TextView mExpandedGroupHeaderTextView;
    private final ImageView mToggleIcon;
    private final TextView mExpansionFooterView;
    private final View mExpansionFooterGroup;
    private final RecyclerView mNotificationListView;
    private final CarNotificationViewAdapter mAdapter;
    private final Drawable mExpandDrawable;
    private final Drawable mCollapseDrawable;
    private final Paint mPaint;
    private final int mDividerHeight;
    private final CarNotificationHeaderView mGroupHeaderView;
    private final View mTouchInterceptorView;
    private final boolean mUseLauncherIcon;
    private final int mExpandedGroupNotificationIncrementSize;
    private final String mShowLessText;

    private AlertEntry mSummaryNotification;
    private NotificationGroup mNotificationGroup;
    private String mHeaderName;
    private int mNumberOfShownNotifications;
    private List<NotificationGroup> mNotificationGroupsShown;
    private FocusRequestStates mCurrentFocusRequestState;

    public GroupNotificationViewHolder(
            View view, NotificationClickHandlerFactory clickHandlerFactory) {
        super(view, clickHandlerFactory);
        mContext = view.getContext();

        mCurrentFocusRequestState = FocusRequestStates.NONE;
        mCardView = itemView.findViewById(R.id.card_view);
        mCardView.addOnAttachStateChangeListener(new View.OnAttachStateChangeListener() {
            @Override
            public void onViewAttachedToWindow(View v) {
                if (v.isInTouchMode()) {
                    return;
                }
                if (mCurrentFocusRequestState != FocusRequestStates.CARD_VIEW) {
                    return;
                }
                v.requestFocus();
            }

            @Override
            public void onViewDetachedFromWindow(View v) {
                // no-op
            }
        });
        mGroupHeaderView = view.findViewById(R.id.group_header);
        mExpandedGroupHeader = view.findViewById(R.id.expanded_group_header);
        mExpandedGroupHeader.addOnAttachStateChangeListener(new View.OnAttachStateChangeListener() {
            @Override
            public void onViewAttachedToWindow(View v) {
                if (v.isInTouchMode()) {
                    return;
                }
                if (mCurrentFocusRequestState != FocusRequestStates.EXPANDED_GROUP_HEADER) {
                    return;
                }
                v.requestFocus();
            }

            @Override
            public void onViewDetachedFromWindow(View v) {
                // no-op
            }
        });
        mHeaderDividerView = view.findViewById(R.id.header_divider);
        mToggleIcon = view.findViewById(R.id.group_toggle_icon);
        mExpansionFooterView = view.findViewById(R.id.expansion_footer);
        mExpansionFooterGroup = view.findViewById(R.id.expansion_footer_holder);
        mExpandedGroupHeaderTextView = view.findViewById(R.id.expanded_group_header_text);
        mNotificationListView = view.findViewById(R.id.notification_list);
        mTouchInterceptorView = view.findViewById(R.id.touch_interceptor_view);

        mExpandDrawable = mContext.getDrawable(R.drawable.expand_more);
        mCollapseDrawable = mContext.getDrawable(R.drawable.expand_less);

        mPaint = new Paint();
        mPaint.setColor(mContext.getColor(R.color.notification_list_divider_color));
        mDividerHeight = mContext.getResources().getDimensionPixelSize(
                R.dimen.notification_list_divider_height);
        mUseLauncherIcon = mContext.getResources().getBoolean(R.bool.config_useLauncherIcon);
        mExpandedGroupNotificationIncrementSize = mContext.getResources()
                .getInteger(R.integer.config_expandedGroupNotificationIncrementSize);
        mShowLessText = mContext.getString(R.string.collapse_group);

        mNotificationListView.setLayoutManager(new LinearLayoutManager(mContext));
        mNotificationListView.addItemDecoration(new GroupedNotificationItemDecoration());
        ((SimpleItemAnimator) mNotificationListView.getItemAnimator())
                .setSupportsChangeAnimations(false);
        mNotificationListView.setNestedScrollingEnabled(false);
        mAdapter = new CarNotificationViewAdapter(mContext, /* isGroupNotificationAdapter= */
                true, /* notificationItemController= */ null);
        mAdapter.setClickHandlerFactory(clickHandlerFactory);
        mNotificationListView.addOnItemTouchListener(
                new CarNotificationItemTouchListener(view.getContext(), mAdapter));
        mNotificationListView.setAdapter(mAdapter);
    }

    /**
     * Because this view holder does not call {@link CarNotificationBaseViewHolder#bind},
     * we need to override this method.
     */
    @Override
    public AlertEntry getAlertEntry() {
        return mSummaryNotification;
    }

    /**
     * Returns the notification group for this viewholder.
     *
     * @return NotificationGroup {@link NotificationGroup}.
     */
    public NotificationGroup getNotificationGroup() {
        return mNotificationGroup;
    }

    /**
     * Group notification view holder is special in that it requires extra data to bind,
     * therefore the standard bind() method is not used. We are calling super.reset()
     * directly and binding the onclick listener manually because the card's on click behavior is
     * different when collapsed/expanded.
     */
    public void bind(NotificationGroup group, CarNotificationViewAdapter parentAdapter,
            boolean isExpanded) {
        reset();

        mNotificationGroup = group;
        mSummaryNotification = mNotificationGroup.getGroupSummaryNotification();
        mHeaderName = loadHeaderAppName(mSummaryNotification.getStatusBarNotification());
        mExpandedGroupHeaderTextView.setText(mHeaderName);

        // Bind the notification's data to the headerView.
        mGroupHeaderView.bind(mSummaryNotification, /* isInGroup= */ false);
        // Set the header's UI attributes (i.e. smallIconColor, etc.) based on the BaseViewHolder.
        bindHeader(mGroupHeaderView, /* isInGroup= */ false);

        // use the same view pool with all the grouped notifications
        // to increase the number of the shared views and reduce memory cost
        // the view pool is created and stored in the root adapter
        mNotificationListView.setRecycledViewPool(parentAdapter.getViewPool());

        // notification cards
        if (isExpanded) {
            mNumberOfShownNotifications = 0;
            // show header divider
            mHeaderDividerView.setVisibility(View.VISIBLE);

            mNotificationGroupsShown = new ArrayList<>();
            mNumberOfShownNotifications =
                    addNextPageOfNotificationsToList(mNotificationGroupsShown);

            if (mUseLauncherIcon) {
                mExpandedGroupHeader.setVisibility(View.VISIBLE);
            } else {
                mExpandedGroupHeader.setVisibility(View.GONE);
            }
        } else {
            mExpandedGroupHeader.setVisibility(View.GONE);
            // hide header divider
            mHeaderDividerView.setVisibility(View.GONE);

            NotificationGroup newGroup = new NotificationGroup();
            newGroup.setSeen(mNotificationGroup.isSeen());

            if (mUseLauncherIcon) {
                // Only show first notification since notification header is not being used.
                newGroup.addNotification(mNotificationGroup.getChildNotifications().get(0));
                mNumberOfShownNotifications = 1;
            } else {
                // Only show group summary notification
                newGroup.addNotification(mNotificationGroup.getGroupSummaryNotification());
                // If the group summary notification is automatically generated,
                // it does not contain a summary of the titles of the child notifications.
                // Therefore, we generate a list of the child notification titles from
                // the parent notification group, and pass them on.
                newGroup.setChildTitles(mNotificationGroup.generateChildTitles());
                mNumberOfShownNotifications = 0;
            }

            List<NotificationGroup> list = new ArrayList<>();
            list.add(newGroup);
            mNotificationGroupsShown = list;
        }
        mAdapter.setNotifications(mNotificationGroupsShown,
                /* setRecyclerViewListHeadersAndFooters= */ false);

        updateExpansionIcon(isExpanded);
        updateOnClickListener(parentAdapter, isExpanded);
        if (isExpanded) {
            if (mUseLauncherIcon) {
                if (!itemView.isInTouchMode()) {
                    mCurrentFocusRequestState = FocusRequestStates.EXPANDED_GROUP_HEADER;
                } else {
                    mCurrentFocusRequestState = FocusRequestStates.NONE;
                }
            }
        } else {
            if (mUseLauncherIcon) {
                if (!itemView.isInTouchMode()) {
                    mCurrentFocusRequestState = FocusRequestStates.CARD_VIEW;
                } else {
                    mCurrentFocusRequestState = FocusRequestStates.NONE;
                }
            }
        }
    }

    private void updateExpansionIcon(boolean isExpanded) {
        // expansion button in the group header
        if (mNotificationGroup.getChildCount() == 0) {
            mToggleIcon.setVisibility(View.GONE);
            return;
        }
        mExpansionFooterGroup.setVisibility(View.VISIBLE);
        if (mUseLauncherIcon) {
            mToggleIcon.setVisibility(View.GONE);
        } else {
            mToggleIcon.setImageDrawable(isExpanded ? mCollapseDrawable : mExpandDrawable);
            mToggleIcon.setVisibility(View.VISIBLE);
        }

        // Don't allow most controls to be focused when collapsed.
        mNotificationListView.setDescendantFocusability(isExpanded
                ? ViewGroup.FOCUS_BEFORE_DESCENDANTS : ViewGroup.FOCUS_BLOCK_DESCENDANTS);
        mNotificationListView.setFocusable(false);
        mGroupHeaderView.setFocusable(isExpanded);
        mExpansionFooterView.setFocusable(isExpanded);

        int unshownCount = mNotificationGroup.getChildCount() - mNumberOfShownNotifications;
        String footerText = mContext
                .getString(R.string.show_more_from_app, unshownCount, mHeaderName);
        mExpansionFooterView.setText(footerText);

        // expansion button in the group footer
        if (isExpanded) {
            hideDismissButton();
            return;
        }

        updateDismissButton(getAlertEntry(), /* isHeadsUp= */ false);
    }

    private void updateOnClickListener(CarNotificationViewAdapter parentAdapter,
            boolean isExpanded) {

        View.OnClickListener expansionClickListener = view -> {
            boolean isExpanding = !isExpanded;
            parentAdapter.setExpanded(mNotificationGroup.getGroupKey(), mNotificationGroup.isSeen(),
                    isExpanding);
            mAdapter.notifyDataSetChanged();
            if (!itemView.isInTouchMode()) {
                if (isExpanding) {
                    mCurrentFocusRequestState = FocusRequestStates.EXPANDED_GROUP_HEADER;
                } else {
                    mCurrentFocusRequestState = FocusRequestStates.CARD_VIEW;
                }
            } else {
                mCurrentFocusRequestState = FocusRequestStates.NONE;
            }
        };

        View.OnClickListener paginationClickListener = view -> {
            if (!itemView.isInTouchMode() && mUseLauncherIcon) {
                mCurrentFocusRequestState = FocusRequestStates.CHILD_NOTIFICATION;
                mNotificationListView.smoothScrollToPosition(mNumberOfShownNotifications - 1);
                mNotificationListView
                        .findViewHolderForAdapterPosition(mNumberOfShownNotifications - 1)
                        .itemView.requestFocus();
            } else {
                mCurrentFocusRequestState = FocusRequestStates.NONE;
            }
            mNumberOfShownNotifications =
                    addNextPageOfNotificationsToList(mNotificationGroupsShown);
            mAdapter.setNotifications(mNotificationGroupsShown,
                    /* setRecyclerViewListHeadersAndFooters= */ false);
            updateExpansionIcon(isExpanded);
            updateOnClickListener(parentAdapter, isExpanded);
        };

        if (isExpanded) {
            mCardView.setOnClickListener(null);
            mCardView.setClickable(false);
            mCardView.setFocusable(false);
            if (mNumberOfShownNotifications == mNotificationGroup.getChildCount()) {
                mExpansionFooterView.setOnClickListener(expansionClickListener);
                mExpansionFooterView.setText(mShowLessText);
            } else {
                mExpansionFooterView.setOnClickListener(paginationClickListener);
            }
        } else {
            mCardView.setOnClickListener(expansionClickListener);
            mExpansionFooterView.setOnClickListener(expansionClickListener);
        }
        mGroupHeaderView.setOnClickListener(expansionClickListener);
        mExpandedGroupHeader.setOnClickListener(expansionClickListener);
        mTouchInterceptorView.setOnClickListener(expansionClickListener);
        mTouchInterceptorView.setVisibility(isExpanded ? View.GONE : View.VISIBLE);
    }

    // Returns new size of group list
    private int addNextPageOfNotificationsToList(List<NotificationGroup> groups) {
        int pageEnd = mNumberOfShownNotifications + mExpandedGroupNotificationIncrementSize;
        for (int i = mNumberOfShownNotifications; i < mNotificationGroup.getChildCount()
                && i < pageEnd; i++) {
            AlertEntry notification = mNotificationGroup.getChildNotifications().get(i);
            NotificationGroup notificationGroup = new NotificationGroup();
            notificationGroup.addNotification(notification);
            notificationGroup.setSeen(mNotificationGroup.isSeen());
            groups.add(notificationGroup);
        }
        return groups.size();
    }

    @Override
    public boolean isDismissible() {
        return mNotificationGroup == null || mNotificationGroup.isDismissible();
    }

    @Override
    void reset() {
        super.reset();
        mCardView.setOnClickListener(null);
        mGroupHeaderView.reset();
    }

    @Override
    public void onUxRestrictionsChanged(CarUxRestrictions restrictionInfo) {
        mAdapter.setCarUxRestrictions(mAdapter.getCarUxRestrictions());
    }

    private class GroupedNotificationItemDecoration extends RecyclerView.ItemDecoration {

        @Override
        public void onDrawOver(Canvas c, RecyclerView parent, RecyclerView.State state) {
            // not drawing the divider for the last item
            for (int i = 0; i < parent.getChildCount() - 1; i++) {
                drawDivider(c, parent.getChildAt(i));
            }
        }

        /**
         * Draws a divider under {@code container}.
         */
        private void drawDivider(Canvas c, View container) {
            int left = container.getLeft();
            int right = container.getRight();
            int bottom = container.getBottom() + mDividerHeight;
            int top = bottom - mDividerHeight;

            c.drawRect(left, top, right, bottom, mPaint);
        }
    }

    /**
     * Fetches the application label given the notification. If the notification is a system
     * generated message notification that is posting on behalf of another application, that
     * application's name is used.
     *
     * The system permission {@link android.Manifest.permission#SUBSTITUTE_NOTIFICATION_APP_NAME}
     * is required to post on behalf of another application. The notification extra should also
     * contain a key {@link Notification#EXTRA_SUBSTITUTE_APP_NAME} with the value of
     * the appropriate application name.
     *
     * @return application label. Returns {@code null} when application name is not found.
     */
    @Nullable
    private String loadHeaderAppName(StatusBarNotification sbn) {
        Context packageContext = sbn.getPackageContext(mContext);
        PackageManager pm = packageContext.getPackageManager();
        Notification notification = sbn.getNotification();
        CharSequence name = pm.getApplicationLabel(packageContext.getApplicationInfo());
        String subName = notification.extras.getString(EXTRA_SUBSTITUTE_APP_NAME);
        if (subName != null) {
            // Only system packages which lump together a bunch of unrelated stuff may substitute a
            // different name to make the purpose of the notification more clear.
            // The correct package label should always be accessible via SystemUI.
            String pkg = sbn.getPackageName();
            if (PackageManager.PERMISSION_GRANTED == pm.checkPermission(
                    android.Manifest.permission.SUBSTITUTE_NOTIFICATION_APP_NAME, pkg)) {
                name = subName;
            } else {
                Log.w(TAG, "warning: pkg "
                        + pkg + " attempting to substitute app name '" + subName
                        + "' without holding perm "
                        + android.Manifest.permission.SUBSTITUTE_NOTIFICATION_APP_NAME);
            }
        }
        if (TextUtils.isEmpty(name)) {
            return null;
        }
        return String.valueOf(name);
    }

    private enum FocusRequestStates {
        CHILD_NOTIFICATION,
        EXPANDED_GROUP_HEADER,
        CARD_VIEW,
        NONE,
    }
}
