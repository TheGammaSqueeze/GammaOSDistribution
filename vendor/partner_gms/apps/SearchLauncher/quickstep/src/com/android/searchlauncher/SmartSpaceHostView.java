package com.android.searchlauncher;

import static com.android.searchlauncher.SmartspaceQsbWidget.WIDGET_PACKAGE_NAME;
import static com.android.searchlauncher.SmartspaceQsbWidget.getDateView;
import static com.android.searchlauncher.SearchLauncherEnum.LAUNCHER_SEARCH_SMARTSPACE_PREFERENCES_TAP_OR_LONGPRESS;

import android.content.Context;
import android.content.Intent;
import android.content.pm.ResolveInfo;
import android.graphics.Rect;
import android.graphics.RectF;
import android.view.HapticFeedbackConstants;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnLongClickListener;
import android.view.ViewGroup;

import com.android.launcher3.CheckLongPressHelper;
import com.android.launcher3.Launcher;
import com.android.launcher3.R;
import com.android.launcher3.qsb.QsbWidgetHostView;
import com.android.launcher3.views.BaseDragLayer.TouchCompleteListener;
import com.android.launcher3.views.OptionsPopupView;
import com.android.launcher3.views.OptionsPopupView.OptionItem;

import java.util.Collections;

public class SmartSpaceHostView extends QsbWidgetHostView
        implements OnLongClickListener, TouchCompleteListener {

    private static final String SETTINGS_INTENT_ACTION =
            "com.google.android.apps.gsa.smartspace.SETTINGS";

    private final Launcher mLauncher;
    private final CheckLongPressHelper mLongPressHelper;

    public SmartSpaceHostView(Context context) {
        super(context);

        mLauncher = Launcher.getLauncher(context);
        mLongPressHelper = new CheckLongPressHelper(this, this);
    }

    @Override
    protected View getErrorView() {
        return getDateView(this);
    }

    @Override
    public boolean onLongClick(View view) {
        if (!hasSettings(view.getContext())) {
            return false;
        }
        performHapticFeedback(HapticFeedbackConstants.LONG_PRESS);
        Rect pos = new Rect();
        mLauncher.getDragLayer().getDescendantRectRelativeToSelf(this, pos);

        RectF centerPos = new RectF();
        centerPos.left = centerPos.right = pos.exactCenterX();

        // Set the top to match draglayer, so that the popup doesn't appear above the view.
        centerPos.top = 0;
        centerPos.bottom = pos.bottom;
        // Adjust the bottom to match the bottom most visible child
        centerPos.bottom = Math.min(findBottomRecur(this, pos.top, pos), centerPos.bottom);

        OptionItem item = new OptionItem(mLauncher,
                R.string.smartspace_preferences,
                R.drawable.ic_smartspace_preferences,
                LAUNCHER_SEARCH_SMARTSPACE_PREFERENCES_TAP_OR_LONGPRESS,
                this::openSettings);
        OptionsPopupView.show(mLauncher, centerPos, Collections.singletonList(item), false);
        return true;
    }

    private int findBottomRecur(View view, int max, Rect tempRect) {
        if (view.getVisibility() != VISIBLE) {
            return max;
        }
        if (view instanceof ViewGroup) {
            ViewGroup vg = (ViewGroup) view;
            for (int i = vg.getChildCount() - 1; i >= 0; i--) {
                max = Math.max(findBottomRecur(vg.getChildAt(i), max, tempRect), max);
            }
        }

        if (!view.willNotDraw()) {
            mLauncher.getDragLayer().getDescendantRectRelativeToSelf(view, tempRect);
            return Math.max(max, tempRect.bottom);
        }

        return max;
    }

    public boolean onInterceptTouchEvent(MotionEvent ev) {
        mLongPressHelper.onTouchEvent(ev);
        return mLongPressHelper.hasPerformedLongPress();
    }

    @Override
    public boolean onTouchEvent(MotionEvent ev) {
        mLongPressHelper.onTouchEvent(ev);
        // We want to keep receiving though events to be able to cancel long press on ACTION_UP
        return true;
    }

    @Override
    public void cancelLongPress() {
        super.cancelLongPress();
        mLongPressHelper.cancelLongPress();
    }

    @Override
    public void onTouchComplete() {
        if (!mLongPressHelper.hasPerformedLongPress()) {
            // If a long press has been performed, we don't want to clear the record of that since
            // we still may be receiving a touch up which we want to intercept
            mLongPressHelper.cancelLongPress();
        }
    }

    private boolean openSettings(View v) {
        v.getContext().startActivity(createSettingsIntent());
        return true;
    }

    public static boolean hasSettings(Context context) {
        ResolveInfo info = context.getPackageManager()
                .resolveActivity(createSettingsIntent(), 0);
        return info != null;
    }

    public static Intent createSettingsIntent() {
        return new Intent(SETTINGS_INTENT_ACTION)
                .setPackage(WIDGET_PACKAGE_NAME)
                .setFlags(Intent.FLAG_RECEIVER_FOREGROUND
                        | Intent.FLAG_ACTIVITY_NO_HISTORY
                        | Intent.FLAG_ACTIVITY_NEW_TASK
                        | Intent.FLAG_ACTIVITY_NEW_DOCUMENT);
    }

}
