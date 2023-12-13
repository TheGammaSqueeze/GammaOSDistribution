package com.android.searchlauncher;

import android.appwidget.AppWidgetManager;
import android.appwidget.AppWidgetProviderInfo;
import android.content.Context;
import android.os.Bundle;
import android.os.Process;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.android.launcher3.R;
import com.android.launcher3.qsb.QsbContainerView;

public class SmartspaceQsbWidget extends QsbContainerView {

    public static final String WIDGET_PACKAGE_NAME = "com.google.android.googlequicksearchbox";

    // To replace search bar with "At A Glance" widget, change to this package:
    // com.google.android.apps.gsa.staticplugins.smartspace.widget.SmartspaceWidgetProvider
    private static final String WIDGET_CLASS_NAME =
            "com.google.android.googlequicksearchbox.SearchWidgetProvider";

    public SmartspaceQsbWidget(Context context) {
        this(context, null);
    }

    public SmartspaceQsbWidget(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public SmartspaceQsbWidget(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
    }

    /**
     * A fragment to display the QSB.
     */
    public static class SmartSpaceFragment extends QsbFragment {

        private static final int SMART_SPACE_WIDGET_HOST_ID = 1027;

        public SmartSpaceFragment() {
            mKeyWidgetId = "smart_space_widget_id";
        }

        @Override
        protected QsbWidgetHost createHost() {
            return new QsbWidgetHost(getContext(), SMART_SPACE_WIDGET_HOST_ID,
                    (c) -> new SmartSpaceHostView(c));
        }

        @Override
        protected AppWidgetProviderInfo getSearchWidgetProvider() {
            for (AppWidgetProviderInfo info : AppWidgetManager.getInstance(getContext())
                    .getInstalledProvidersForPackage(WIDGET_PACKAGE_NAME, Process.myUserHandle())) {
                if (WIDGET_CLASS_NAME.equals(info.provider.getClassName())) {
                    return info;
                }
            }
            return null;
        }

        @Override
        protected View getDefaultView(ViewGroup container, boolean showSetupIcon) {
            return getDateView(container);
        }

        @Override
        protected Bundle createBindOptions() {
            Bundle opts = super.createBindOptions();
            opts.putString("attached-launcher-identifier", getContext().getPackageName());
            opts.putBoolean("com.google.android.apps.gsa.widget.PREINSTALLED", true);
            return opts;
        }
    }

    public static View getDateView(ViewGroup parent) {
        return LayoutInflater.from(parent.getContext())
                .inflate(R.layout.smart_space_date_view, parent, false);
    }
}