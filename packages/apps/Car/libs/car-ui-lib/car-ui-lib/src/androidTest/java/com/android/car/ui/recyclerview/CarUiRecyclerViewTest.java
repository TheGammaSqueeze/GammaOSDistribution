/*
 * Copyright (C) 2020 The Android Open Source Project
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

package com.android.car.ui.recyclerview;

import static android.car.drivingstate.CarUxRestrictions.UX_RESTRICTIONS_LIMIT_CONTENT;

import static androidx.core.math.MathUtils.clamp;
import static androidx.recyclerview.widget.RecyclerView.SCROLL_STATE_DRAGGING;
import static androidx.recyclerview.widget.RecyclerView.SCROLL_STATE_IDLE;
import static androidx.recyclerview.widget.RecyclerView.SCROLL_STATE_SETTLING;
import static androidx.test.espresso.Espresso.onView;
import static androidx.test.espresso.action.ViewActions.click;
import static androidx.test.espresso.assertion.PositionAssertions.isBottomAlignedWith;
import static androidx.test.espresso.assertion.PositionAssertions.isCompletelyAbove;
import static androidx.test.espresso.assertion.PositionAssertions.isCompletelyRightOf;
import static androidx.test.espresso.assertion.PositionAssertions.isLeftAlignedWith;
import static androidx.test.espresso.assertion.PositionAssertions.isRightAlignedWith;
import static androidx.test.espresso.assertion.PositionAssertions.isTopAlignedWith;
import static androidx.test.espresso.assertion.ViewAssertions.doesNotExist;
import static androidx.test.espresso.assertion.ViewAssertions.matches;
import static androidx.test.espresso.matcher.ViewMatchers.assertThat;
import static androidx.test.espresso.matcher.ViewMatchers.hasDescendant;
import static androidx.test.espresso.matcher.ViewMatchers.isCompletelyDisplayed;
import static androidx.test.espresso.matcher.ViewMatchers.isDisplayed;
import static androidx.test.espresso.matcher.ViewMatchers.isEnabled;
import static androidx.test.espresso.matcher.ViewMatchers.isRoot;
import static androidx.test.espresso.matcher.ViewMatchers.withContentDescription;
import static androidx.test.espresso.matcher.ViewMatchers.withId;
import static androidx.test.espresso.matcher.ViewMatchers.withText;
import static androidx.test.platform.app.InstrumentationRegistry.getInstrumentation;

import static com.android.car.ui.actions.CarUiRecyclerViewActions.scrollToPosition;
import static com.android.car.ui.actions.LowLevelActions.performDrag;
import static com.android.car.ui.actions.LowLevelActions.pressAndHold;
import static com.android.car.ui.actions.LowLevelActions.release;
import static com.android.car.ui.actions.LowLevelActions.touchDownAndUp;
import static com.android.car.ui.actions.ViewActions.waitForView;
import static com.android.car.ui.core.CarUi.MIN_TARGET_API;
import static com.android.car.ui.matchers.ViewMatchers.doesNotExistOrIsNotDisplayed;
import static com.android.car.ui.recyclerview.CarUiRecyclerView.ItemCap.UNLIMITED;
import static com.android.car.ui.utils.ViewUtils.setRotaryScrollEnabled;

import static org.hamcrest.Matchers.equalTo;
import static org.hamcrest.Matchers.greaterThan;
import static org.hamcrest.Matchers.greaterThanOrEqualTo;
import static org.hamcrest.Matchers.is;
import static org.hamcrest.Matchers.lessThanOrEqualTo;
import static org.hamcrest.Matchers.not;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertThrows;
import static org.junit.Assert.assertTrue;
import static org.mockito.ArgumentMatchers.any;
import static org.mockito.ArgumentMatchers.anyBoolean;
import static org.mockito.ArgumentMatchers.anyInt;
import static org.mockito.ArgumentMatchers.eq;
import static org.mockito.Mockito.atLeastOnce;
import static org.mockito.Mockito.doReturn;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.spy;
import static org.mockito.Mockito.times;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

import static java.lang.Math.abs;
import static java.lang.Math.max;

import android.annotation.TargetApi;
import android.car.drivingstate.CarUxRestrictions;
import android.content.Context;
import android.content.res.Resources;
import android.content.res.TypedArray;
import android.util.TypedValue;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.GridLayoutManager;
import androidx.recyclerview.widget.GridLayoutManager.SpanSizeLookup;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.LinearSnapHelper;
import androidx.recyclerview.widget.OrientationHelper;
import androidx.recyclerview.widget.RecyclerView;
import androidx.recyclerview.widget.RecyclerView.LayoutManager;
import androidx.recyclerview.widget.RecyclerView.LayoutParams;
import androidx.test.espresso.IdlingRegistry;
import androidx.test.espresso.IdlingResource;
import androidx.test.ext.junit.rules.ActivityScenarioRule;

import com.android.car.ui.TestActivity;
import com.android.car.ui.actions.LowLevelActions;
import com.android.car.ui.pluginsupport.PluginFactorySingleton;
import com.android.car.ui.recyclerview.decorations.grid.GridDividerItemDecoration;
import com.android.car.ui.test.R;
import com.android.car.ui.utils.CarUxRestrictionsUtil;

import org.junit.After;
import org.junit.Rule;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.mockito.ArgumentCaptor;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Objects;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * Unit tests for {@link CarUiRecyclerView}.
 */
@RunWith(Parameterized.class)
@TargetApi(MIN_TARGET_API)
public class CarUiRecyclerViewTest {
    @Parameterized.Parameters
    public static Object[] data() {
        // It's important to do no plugin first, so that the plugin will
        // still be enabled when this test finishes
        return new Object[]{false, true};
    }

    @Rule
    public ActivityScenarioRule<TestActivity> mActivityRule =
            new ActivityScenarioRule<>(TestActivity.class);

    private final boolean mIsPluginEnabled;

    public CarUiRecyclerViewTest(boolean pluginEnabled) {
        PluginFactorySingleton.setPluginEnabledForTesting(pluginEnabled);
        mIsPluginEnabled = pluginEnabled;
    }

    @After
    public void tearDown() {
        for (IdlingResource idlingResource : IdlingRegistry.getInstance().getResources()) {
            IdlingRegistry.getInstance().unregister(idlingResource);
        }

        LowLevelActions.tearDown();
    }

    @Test
    public void testIsScrollbarPresent_scrollbarDisabled() {
        if (mIsPluginEnabled) {
            return;
        }

        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);
            doReturn(false).when(testableResources)
                    .getBoolean(R.bool.car_ui_scrollbar_enable);

            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(testableContext);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setAdapter(new TestAdapter(100));
        });

        onView(withId(getId("car_ui_scroll_bar"))).check(doesNotExist());
    }

    @Test
    public void testSmallRecyclerView_scrollbarDisabled() {
        if (mIsPluginEnabled) {
            return;
        }

        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);

            TypedArray typedArray = spy(activity.getBaseContext().obtainStyledAttributes(
                    null, R.styleable.CarUiRecyclerView));
            doReturn(typedArray).when(testableContext).obtainStyledAttributes(
                    any(),
                    eq(R.styleable.CarUiRecyclerView),
                    anyInt(),
                    anyInt());
            when(typedArray.getInt(eq(R.styleable.CarUiRecyclerView_carUiSize),
                    anyInt())).thenReturn(0); // Small size

            // Disable scrollbar
            doReturn(false).when(testableResources)
                    .getBoolean(R.bool.car_ui_scrollbar_enable);

            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(testableContext);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setAdapter(new TestAdapter(100));
        });

        onView(withId(getId("car_ui_scroll_bar"))).check(doesNotExist());
    }

    @Test
    public void testMediumRecyclerView_scrollbarDisabled() {
        if (mIsPluginEnabled) {
            return;
        }

        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);

            TypedArray typedArray = spy(activity.getBaseContext().obtainStyledAttributes(
                    null, R.styleable.CarUiRecyclerView));
            doReturn(typedArray).when(testableContext).obtainStyledAttributes(
                    any(),
                    eq(R.styleable.CarUiRecyclerView),
                    anyInt(),
                    anyInt());
            when(typedArray.getInt(eq(R.styleable.CarUiRecyclerView_carUiSize),
                    anyInt())).thenReturn(1); // Medium size

            // Disable scrollbar
            doReturn(false).when(testableResources)
                    .getBoolean(R.bool.car_ui_scrollbar_enable);

            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(testableContext);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setAdapter(new TestAdapter(100));
        });

        onView(withId(getId("car_ui_scroll_bar"))).check(doesNotExist());
    }

    @Test
    public void testLargeRecyclerView_scrollbarDisabled() {
        if (mIsPluginEnabled) {
            return;
        }

        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);

            TypedArray typedArray = spy(activity.getBaseContext().obtainStyledAttributes(
                    null, R.styleable.CarUiRecyclerView));
            doReturn(typedArray).when(testableContext).obtainStyledAttributes(
                    any(),
                    eq(R.styleable.CarUiRecyclerView),
                    anyInt(),
                    anyInt());
            when(typedArray.getInt(eq(R.styleable.CarUiRecyclerView_carUiSize),
                    anyInt())).thenReturn(2); // Large size

            // Disable scrollbar
            doReturn(false).when(testableResources)
                    .getBoolean(R.bool.car_ui_scrollbar_enable);

            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(testableContext);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setAdapter(new TestAdapter(100));
        });

        onView(withId(getId("car_ui_scroll_bar"))).check(doesNotExist());
    }

    @Test
    public void testPadding() {
        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(activity);
            ViewGroup container = activity.findViewById(R.id.test_container);
            int padding = 100;
            carUiRecyclerView.setPadding(padding, padding, padding, padding);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setAdapter(new TestAdapter(100));

            assertEquals(padding, carUiRecyclerView.getPaddingLeft());
            assertEquals(padding, carUiRecyclerView.getPaddingRight());
            assertEquals(padding, carUiRecyclerView.getPaddingTop());
            assertEquals(padding, carUiRecyclerView.getPaddingBottom());
        });
    }

    @Test
    public void testGridLayout() {
        // Ensure the CarUiRecyclerViewLayout constant matches the styleable attribute enum value
        assertEquals(CarUiRecyclerView.CarUiRecyclerViewLayout.GRID, 1);

        TestAdapter adapter = new TestAdapter(4);

        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);

            TypedArray typedArray = spy(activity.getBaseContext().obtainStyledAttributes(
                    null, R.styleable.CarUiRecyclerView));

            doReturn(typedArray).when(testableContext).obtainStyledAttributes(
                    any(),
                    eq(R.styleable.CarUiRecyclerView),
                    anyInt(),
                    anyInt());
            when(typedArray.getInt(eq(R.styleable.CarUiRecyclerView_layoutStyle), anyInt()))
                    .thenReturn(CarUiRecyclerView.CarUiRecyclerViewLayout.GRID);
            when(typedArray.getInt(eq(R.styleable.CarUiRecyclerView_numOfColumns), anyInt()))
                    .thenReturn(3);

            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(testableContext);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.post(() -> {
                container.addView(carUiRecyclerView.getView());
                carUiRecyclerView.setAdapter(adapter);
            });

            assertTrue(carUiRecyclerView.getLayoutStyle() instanceof CarUiGridLayoutStyle);
        });

        // Check that all items in the first row are top-aligned.
        onView(withText(adapter.getItemText(0))).check(
                isTopAlignedWith(withText(adapter.getItemText(1))));
        onView(withText(adapter.getItemText(1))).check(
                isTopAlignedWith(withText(adapter.getItemText(2))));

        // Check that all items in the first row are bottom-aligned.
        onView(withText(adapter.getItemText(0))).check(
                isBottomAlignedWith(withText(adapter.getItemText(1))));
        onView(withText(adapter.getItemText(1))).check(
                isBottomAlignedWith(withText(adapter.getItemText(2))));

        // Check that items in second row are rendered correctly below the first row.
        onView(withText(adapter.getItemText(0))).check(
                isCompletelyAbove(withText(adapter.getItemText(3))));
        onView(withText(adapter.getItemText(0))).check(
                isLeftAlignedWith(withText(adapter.getItemText(3))));
        onView(withText(adapter.getItemText(0))).check(
                isRightAlignedWith(withText(adapter.getItemText(3))));
    }

    @Test
    public void testLinearLayout() {
        // Ensure the CarUiRecyclerViewLayout constant matches the styleable attribute enum value
        assertEquals(CarUiRecyclerView.CarUiRecyclerViewLayout.LINEAR, 0);

        TestAdapter adapter = new TestAdapter(4);

        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);

            TypedArray typedArray = spy(activity.getBaseContext().obtainStyledAttributes(
                    null, R.styleable.CarUiRecyclerView));

            doReturn(typedArray).when(testableContext).obtainStyledAttributes(
                    any(),
                    eq(R.styleable.CarUiRecyclerView),
                    anyInt(),
                    anyInt());
            when(typedArray.getInt(eq(R.styleable.CarUiRecyclerView_layoutStyle), anyInt()))
                    .thenReturn(CarUiRecyclerView.CarUiRecyclerViewLayout.LINEAR);

            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(testableContext);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.post(() -> {
                container.addView(carUiRecyclerView.getView());
                carUiRecyclerView.setAdapter(adapter);
            });

            assertTrue(carUiRecyclerView.getLayoutStyle() instanceof CarUiLinearLayoutStyle);
        });

        // Check that item views are laid out linearly.
        onView(withText(adapter.getItemText(0))).check(
                isCompletelyAbove(withText(adapter.getItemText(1))));
        onView(withText(adapter.getItemText(1))).check(
                isCompletelyAbove(withText(adapter.getItemText(2))));
        onView(withText(adapter.getItemText(2))).check(
                isCompletelyAbove(withText(adapter.getItemText(3))));
    }

    @Test
    public void testStartAtFirstPosition() {
        TestAdapter adapter = new TestAdapter(100);
        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(activity);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(adapter);
        });

        // Check that the first item is completely displayed.
        onView(withText(adapter.getItemText(0))).check(matches(isCompletelyDisplayed()));
        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            assertEquals(0, carUiRecyclerView.findFirstCompletelyVisibleItemPosition());
        });
    }

    @Test
    public void testPositionAfterPadding() {
        TestAdapter adapter = new TestAdapter(100);
        int testPosition = 40;
        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(activity);
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(adapter);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.scrollToPosition(testPosition);
        });

        // Check that the scrolled to item is completely displayed.
        onView(withText(adapter.getItemText(testPosition))).check(matches(isCompletelyDisplayed()));
        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            assertEquals(testPosition, carUiRecyclerView.findFirstCompletelyVisibleItemPosition());

            int padding = 150;
            carUiRecyclerView.setPadding(padding, padding, padding, padding);
        });

        // Check that the scrolled to item is completely displayed.
        onView(withText(adapter.getItemText(testPosition))).check(matches(isCompletelyDisplayed()));
        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            assertEquals(testPosition, carUiRecyclerView.findFirstCompletelyVisibleItemPosition());
        });
    }

    @Test
    public void testPositionAfterPaddingRelative() {
        TestAdapter adapter = new TestAdapter(100);
        int testPosition = 40;
        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(activity);
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(adapter);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.scrollToPosition(testPosition);
        });

        // Check that the scrolled to item is completely displayed.
        onView(withText(adapter.getItemText(testPosition))).check(matches(isCompletelyDisplayed()));
        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            assertEquals(testPosition, carUiRecyclerView.findFirstCompletelyVisibleItemPosition());

            int padding = 150;
            carUiRecyclerView.setPaddingRelative(padding, padding, padding, padding);
        });

        // Check that the scrolled to item is completely displayed.
        onView(withText(adapter.getItemText(testPosition))).check(matches(isCompletelyDisplayed()));
        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            assertEquals(testPosition, carUiRecyclerView.findFirstCompletelyVisibleItemPosition());
        });
    }

    @Test
    public void testLayoutManagerSetInXml() {
        if (mIsPluginEnabled) {
            return;
        }

        // Inflate activity where a LayoutManger is set for a CarUiRecyclerView through a
        // styleable attribute.
        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_layout_manager_xml_test_activity));

        onView(withId(R.id.list)).check(matches(isDisplayed()));

        TestAdapter adapter = new TestAdapter(3);

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            setRotaryScrollEnabled(carUiRecyclerView.getView(), /* isVertical= */ true);
            carUiRecyclerView.setAdapter(adapter);
            carUiRecyclerView.setVisibility(View.VISIBLE);

            assertTrue(carUiRecyclerView.getLayoutStyle() instanceof CarUiGridLayoutStyle);
        });

        // Check that items in are displayed.
        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));
        onView(withText(adapter.getItemText(1))).check(matches(isDisplayed()));
        onView(withText(adapter.getItemText(2))).check(matches(isDisplayed()));
    }

    @Test
    public void testSetLayoutManager_shouldUpdateItemDecorations() {
        if (mIsPluginEnabled) {
            return;
        }

        TestAdapter adapter = new TestAdapter(4);
        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);

            TypedArray typedArray = spy(activity.getBaseContext().obtainStyledAttributes(
                    null, R.styleable.CarUiRecyclerView));

            doReturn(typedArray).when(testableContext).obtainStyledAttributes(
                    any(),
                    eq(R.styleable.CarUiRecyclerView),
                    anyInt(),
                    anyInt());
            when(typedArray.getBoolean(eq(R.styleable.CarUiRecyclerView_enableDivider),
                    anyBoolean()))
                    .thenReturn(true);
            when(typedArray.getInt(eq(R.styleable.CarUiRecyclerView_layoutStyle), anyInt()))
                    .thenReturn(CarUiRecyclerView.CarUiRecyclerViewLayout.GRID);
            when(typedArray.getInt(eq(R.styleable.CarUiRecyclerView_numOfColumns), anyInt()))
                    .thenReturn(3);

            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(testableContext);
            carUiRecyclerView.setId(listId);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setAdapter(adapter);
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            assertTrue(carUiRecyclerView.getLayoutStyle() instanceof CarUiGridLayoutStyle);
            assertEquals(carUiRecyclerView.getItemDecorationCount(), 1);
            assertTrue(
                    carUiRecyclerView.getItemDecorationAt(0) instanceof GridDividerItemDecoration);

            carUiRecyclerView.setLayoutStyle(new CarUiLinearLayoutStyle());
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            assertTrue(carUiRecyclerView.getLayoutStyle() instanceof CarUiLinearLayoutStyle);
            assertEquals(carUiRecyclerView.getItemDecorationCount(), 1);
            assertFalse(carUiRecyclerView.getItemDecorationAt(0)
                    instanceof GridDividerItemDecoration);
        });
    }

    @Test
    public void testVisibility_goneAtInflationWithChangeToVisible() {
        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_gone_test_activity));

        onView(withId(R.id.list)).check(matches(not(isDisplayed())));

        TestAdapter adapter = new TestAdapter(3);

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            carUiRecyclerView.setAdapter(adapter);
            carUiRecyclerView.setVisibility(View.VISIBLE);
        });

        // Check that items in are displayed.
        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));
        onView(withText(adapter.getItemText(1))).check(matches(isDisplayed()));
        onView(withText(adapter.getItemText(2))).check(matches(isDisplayed()));
    }

    @Test
    public void testVisibility_invisibleAtInflationWithChangeToVisible() {
        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_invisible_test_activity));

        onView(withId(R.id.list)).check(matches(not(isDisplayed())));

        TestAdapter adapter = new TestAdapter(3);

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            carUiRecyclerView.setAdapter(adapter);
            carUiRecyclerView.setVisibility(View.VISIBLE);
        });

        // Check that items in are displayed.
        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));
        onView(withText(adapter.getItemText(1))).check(matches(isDisplayed()));
        onView(withText(adapter.getItemText(2))).check(matches(isDisplayed()));
    }

    @Test
    public void testFirstItemAtTop_onInitialLoad() {
        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_test_activity));

        onView(withId(R.id.list)).check(matches(isDisplayed()));

        TestAdapter adapter = new TestAdapter(25);

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            activity.runOnUiThread(() -> carUiRecyclerView.setAdapter(adapter));
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            assertEquals(carUiRecyclerView.findFirstVisibleItemPosition(), 0);
        });
    }

    @Test
    public void testPageUpAndDownMoveSameDistance() {
        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_test_activity));

        onView(withId(R.id.list)).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            // Can't use OrientationHelper here, because it returns 0 when calling getTotalSpace
            // methods
            // until LayoutManager's onLayoutComplete is called. In this case waiting until the
            // first
            // item of the list is displayed guarantees that OrientationHelper is initialized
            // properly.
            int totalSpace = carUiRecyclerView.getHeight()
                    - carUiRecyclerView.getPaddingTop()
                    - carUiRecyclerView.getPaddingBottom();
            PerfectFitTestAdapter adapter = new PerfectFitTestAdapter(5, totalSpace);
            carUiRecyclerView.setAdapter(adapter);

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        onView(withText(PerfectFitTestAdapter.getItemText(0))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            // Recalculate total space
            int totalSpace = carUiRecyclerView.getHeight()
                    - carUiRecyclerView.getPaddingTop()
                    - carUiRecyclerView.getPaddingBottom();
            assertEquals(totalSpace, carUiRecyclerView.getTotalSpace());
        });

        // Move down one page so there will be sufficient pages for up and downs.
        onView(withId(getId("car_ui_scrollbar_page_down"))).perform(click());


        for (int i = 0; i < 3; i++) {
            onView(withId(getId("car_ui_scrollbar_page_down"))).perform(click());
            onView(withId(getId("car_ui_scrollbar_page_up"))).perform(click());
        }

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            int topPosition = carUiRecyclerView.findFirstVisibleItemPosition();
            assertEquals(carUiRecyclerView.findFirstVisibleItemPosition(), topPosition);
        });
    }

    @Test
    public void testContinuousScroll() {
        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_test_activity));

        onView(withId(R.id.list)).check(matches(isDisplayed()));

        TestAdapter adapter = new TestAdapter(50);

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            carUiRecyclerView.setAdapter(adapter);

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        // Press and hold the down button for 2 seconds to scroll the list to bottom.
        onView(withId(getId("car_ui_scrollbar_page_down"))).perform(pressAndHold());
        onView(isRoot()).perform(waitForView(withText("Sample item #49"), 3000));
        onView(withId(getId("car_ui_scrollbar_page_down"))).perform(release());

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            assertEquals(carUiRecyclerView.findLastCompletelyVisibleItemPosition(), 49);
        });
    }

    @Test
    public void testAlphaJumpToMiddleForThumbWhenTrackClicked() {
        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_test_activity));

        onView(withId(R.id.list)).check(matches(isDisplayed()));

        TestAdapter adapter = new TestAdapter(50);

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            carUiRecyclerView.setAdapter(adapter);

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        AtomicInteger trackViewHeight = new AtomicInteger();
        mActivityRule.getScenario().onActivity(activity -> {
            View trackView = activity.requireViewById(getId("car_ui_scrollbar_track"));
            trackViewHeight.set(trackView.getHeight());
        });

        // scroll to the middle
        onView(withId(getId("car_ui_scrollbar_track"))).perform(
                touchDownAndUp(0f, (trackViewHeight.get() / 2f)));
        onView(withText(adapter.getItemText(25))).check(matches(isDisplayed()));
    }

    @Test
    public void testAlphaJumpToEndAndStartForThumbWhenTrackClicked() {
        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_test_activity));

        onView(withId(R.id.list)).check(matches(isDisplayed()));

        TestAdapter adapter = new TestAdapter(50);

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            carUiRecyclerView.setAdapter(adapter);

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        AtomicInteger trackViewHeight = new AtomicInteger();
        mActivityRule.getScenario().onActivity(activity -> {
            View trackView = activity.requireViewById(getId("car_ui_scrollbar_track"));
            trackViewHeight.set(trackView.getHeight());
        });

        // scroll to the end
        onView(withId(getId("car_ui_scrollbar_track"))).perform(
                touchDownAndUp(0f, trackViewHeight.get() - 1));
        onView(withText(adapter.getItemText(49))).check(matches(isDisplayed()));

        // scroll to the start
        onView(withId(getId("car_ui_scrollbar_track"))).perform(
                touchDownAndUp(0f, 1));
        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));
    }

    @Test
    public void testThumbDragToCenter() {
        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_test_activity));

        onView(withId(R.id.list)).check(matches(isDisplayed()));

        TestAdapter adapter = new TestAdapter(50);

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            carUiRecyclerView.setAdapter(adapter);

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        AtomicInteger trackViewHeight = new AtomicInteger();
        AtomicInteger thumbViewHeight = new AtomicInteger();
        mActivityRule.getScenario().onActivity(activity -> {
            View trackView = activity.requireViewById(getId("car_ui_scrollbar_track"));
            View thumbView = activity.requireViewById(getId("car_ui_scrollbar_thumb"));

            trackViewHeight.set(trackView.getHeight());
            thumbViewHeight.set(thumbView.getHeight());
        });

        // if you drag too far in a single step you'll stop selecting the thumb view. Hence, drag
        // 5 units at a time for 200 intervals and stop at the center of the track by limitY.
        onView(withId(getId("car_ui_scrollbar_track"))).perform(
                performDrag(0f, (thumbViewHeight.get() / 2f), 0,
                        5, 200, Float.MAX_VALUE,
                        trackViewHeight.get() / 2f));
        onView(withText(adapter.getItemText(25))).check(matches(isDisplayed()));
    }

    @Test
    public void testPageUpButtonDisabledAtTop() {
        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_test_activity));

        onView(withId(R.id.list)).check(matches(isDisplayed()));

        TestAdapter adapter = new TestAdapter(50);

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            carUiRecyclerView.setAdapter(adapter);

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        // Initially page_up button is disabled.
        onView(withId(getId("car_ui_scrollbar_page_up"))).check(matches(not(isEnabled())));

        // Moving down, should enable the up bottom.
        onView(withId(getId("car_ui_scrollbar_page_down"))).check(matches(isEnabled()));
        onView(withId(getId("car_ui_scrollbar_page_down"))).perform(click());
        onView(withId(getId("car_ui_scrollbar_page_up"))).check(matches(isEnabled()));

        // Move back up; this should disable the up button again.
        onView(withId(getId("car_ui_scrollbar_page_up"))).perform(click()).check(
                matches(not(isEnabled())));
    }

    @Test
    public void testPageUpScrollsWithoutSnap() {
        CarUiRecyclerView.OnScrollListener scrollListener =
                mock(CarUiRecyclerView.OnScrollListener.class);
        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(activity);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(new TestAdapter(100));

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        // Scroll down a few pages so that you can perform page up operations.
        onView(withId(getId("car_ui_scrollbar_page_down"))).perform(click());
        onView(withId(getId("car_ui_scrollbar_page_down"))).perform(click());
        onView(withId(getId("car_ui_scrollbar_page_down"))).perform(click());
        onView(withId(getId("car_ui_scrollbar_page_down"))).perform(click());

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            // Set a mocked scroll listener on the CarUiRecyclerView
            carUiRecyclerView.addOnScrollListener(scrollListener);
        });

        onView(withId(getId("car_ui_scrollbar_page_up"))).perform(click());

        ArgumentCaptor<CarUiRecyclerView> captor = ArgumentCaptor.forClass(CarUiRecyclerView.class);

        // Verify that scroll operation only settles on the destination once. This means a single
        // smooth scroll to the destination. If the scroll includes a secondary snap after an
        // initial scroll, this callback will have more than one invocation.
        verify(scrollListener, times(1)).onScrollStateChanged(captor.capture(),
                eq(SCROLL_STATE_SETTLING));
        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            assertEquals(carUiRecyclerView, captor.getValue());
        });

        onView(withId(getId("car_ui_scrollbar_page_up"))).perform(click());

        // Make same verification as above for a second page up operation.
        verify(scrollListener, times(2)).onScrollStateChanged(
                captor.capture(), eq(SCROLL_STATE_SETTLING));
        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            assertEquals(carUiRecyclerView, captor.getValue());
        });
    }

    @Test
    public void testPageDownScrollsWithoutSnap() {
        CarUiRecyclerView.OnScrollListener scrollListener =
                mock(CarUiRecyclerView.OnScrollListener.class);

        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(activity);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(new TestAdapter(100));

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));

            // Set a mocked scroll listener on the CarUiRecyclerView
            carUiRecyclerView.addOnScrollListener(scrollListener);
        });

        onView(withId(getId("car_ui_scrollbar_page_down"))).perform(click());

        // Verify that scroll operation only settles on the destination once. This means a single
        // smooth scroll to the destination. If the scroll includes a secondary snap after an
        // initial scroll, this callback will have more than one invocation.
        ArgumentCaptor<CarUiRecyclerView> captor = ArgumentCaptor.forClass(CarUiRecyclerView.class);
        verify(scrollListener, times(1)).onScrollStateChanged(
                captor.capture(), eq(SCROLL_STATE_SETTLING));

        onView(withId(getId("car_ui_scrollbar_page_down"))).perform(click());

        // Make same verification as above for a second page down operation.
        verify(scrollListener, times(2)).onScrollStateChanged(
                captor.capture(), eq(SCROLL_STATE_SETTLING));
    }

    @Test
    public void testPageDownScrollsOverLongItem() {
        if (mIsPluginEnabled) {
            return;
        }

        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_test_activity));

        onView(withId(R.id.list)).check(matches(isDisplayed()));

        int itemCount = 100;
        // Position the long item in the middle.
        int longItemPosition = itemCount / 2;

        Map<Integer, TestAdapter.ItemHeight> heightOverrides = new HashMap<>();
        heightOverrides.put(longItemPosition, TestAdapter.ItemHeight.TALL);
        TestAdapter adapter = new TestAdapter(itemCount, heightOverrides);

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            carUiRecyclerView.setAdapter(adapter);

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        // Scroll to a position where long item is partially visible.
        // Scrolling from top, scrollToPosition() aligns the pos-1 item to bottom.
        onView(withId(R.id.list)).perform(scrollToPosition(longItemPosition - 1));
        // This is needed to make sure scroll is finished before looking for the long item.
        onView(withText(adapter.getItemText(longItemPosition - 1))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            int screenHeight = carUiRecyclerView.getTotalSpace();

            // Scroll by half the height of the screen so the long item is partially visible.
            carUiRecyclerView.scrollBy(0, screenHeight / 2);
        });

        onView(withText(adapter.getItemText(longItemPosition))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            OrientationHelper orientationHelper =
                    OrientationHelper.createVerticalHelper(carUiRecyclerView.getLayoutManager());
            // Verify long item is partially shown.
            View longItem = getLongItem(carUiRecyclerView);
            assertThat(
                    orientationHelper.getDecoratedStart(longItem),
                    is(greaterThan(carUiRecyclerView.getStartAfterPadding())));
        });

        onView(withId(getId("car_ui_scrollbar_page_down"))).perform(click());

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            OrientationHelper orientationHelper =
                    OrientationHelper.createVerticalHelper(carUiRecyclerView.getLayoutManager());
            // Verify long item is snapped to top.
            View longItem = getLongItem(carUiRecyclerView);
            assertThat(orientationHelper.getDecoratedStart(longItem),
                    is(equalTo(carUiRecyclerView.getStartAfterPadding())));
            assertThat(orientationHelper.getDecoratedEnd(longItem),
                    is(greaterThan(carUiRecyclerView.getEndAfterPadding())));
        });

        onView(withText(adapter.getItemText(longItemPosition))).check(matches(isDisplayed()));
        onView(withId(getId("car_ui_scrollbar_page_down"))).perform(click());

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            OrientationHelper orientationHelper =
                    OrientationHelper.createVerticalHelper(carUiRecyclerView.getLayoutManager());
            View longItem = getLongItem(carUiRecyclerView);
            // Verify long item end is aligned to bottom.
            assertThat(orientationHelper.getDecoratedEnd(longItem),
                    is(equalTo(carUiRecyclerView.getEndAfterPadding())));
        });

        onView(withId(getId("car_ui_scrollbar_page_down"))).perform(click());
        // Verify that the long item is no longer visible; Should be on the next child
        onView(hasDescendant(withText(adapter.getItemText(longItemPosition)))).check(
                doesNotExistOrIsNotDisplayed());
    }

    @Test
    public void testPageDownScrollsOverLongItemAtTheEnd() {
        if (mIsPluginEnabled) {
            return;
        }

        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_test_activity));

        onView(withId(R.id.list)).check(matches(isDisplayed()));

        int itemCount = 100;
        // Position the long item at the end.
        int longItemPosition = itemCount - 1;

        Map<Integer, TestAdapter.ItemHeight> heightOverrides = new HashMap<>();
        heightOverrides.put(longItemPosition, TestAdapter.ItemHeight.TALL);
        TestAdapter adapter = new TestAdapter(itemCount, heightOverrides);

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            // Setting top padding to any number greater than 0.
            // Not having padding will make this test pass all the time.
            // Also adding bottom padding to make sure the padding
            // after the last content is considered in calculations.
            carUiRecyclerView.setPadding(0, 1, 0, 1);
            carUiRecyclerView.setAdapter(adapter);

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        // 20 is just an arbitrary number to make sure we reach the end of the recyclerview.
        for (int i = 0; i < 20; i++) {
            onView(withId(getId("car_ui_scrollbar_page_down"))).perform(click());
        }

        onView(withId(getId("car_ui_scrollbar_page_down"))).check(matches(not(isEnabled())));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            OrientationHelper orientationHelper =
                    OrientationHelper.createVerticalHelper(carUiRecyclerView.getLayoutManager());
            View longItem = getLongItem(carUiRecyclerView);
            // Making sure we've reached end of the recyclerview, after
            // adding bottom padding
            assertThat(orientationHelper.getDecoratedEnd(longItem),
                    is(equalTo(carUiRecyclerView.getEndAfterPadding())));
        });
    }

    @Test
    public void testPageUpScrollsOverLongItem() {
        if (mIsPluginEnabled) {
            return;
        }

        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_test_activity));

        onView(withId(R.id.list)).check(matches(isDisplayed()));

        int itemCount = 100;
        // Position the long item in the middle.
        int longItemPosition = itemCount / 2;

        Map<Integer, TestAdapter.ItemHeight> heightOverrides = new HashMap<>();
        heightOverrides.put(longItemPosition, TestAdapter.ItemHeight.TALL);
        TestAdapter adapter = new TestAdapter(itemCount, heightOverrides);

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            carUiRecyclerView.setAdapter(adapter);

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        // Scroll to a position just below the long item.
        onView(withId(R.id.list)).perform(scrollToPosition(longItemPosition + 1));
        onView(withText(adapter.getItemText(longItemPosition + 1))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            OrientationHelper orientationHelper =
                    OrientationHelper.createVerticalHelper(carUiRecyclerView.getLayoutManager());
            // Verify long item is off-screen.
            View longItem = getLongItem(carUiRecyclerView);
            assertThat(
                    orientationHelper.getDecoratedEnd(longItem),
                    is(lessThanOrEqualTo(carUiRecyclerView.getEndAfterPadding())));
        });

        final AtomicBoolean check = new AtomicBoolean();
        final AtomicInteger topBeforeClick = new AtomicInteger();

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            OrientationHelper orientationHelper =
                    OrientationHelper.createVerticalHelper(carUiRecyclerView.getLayoutManager());
            View longItem = getLongItem(carUiRecyclerView);
            if (carUiRecyclerView.getStartAfterPadding() - orientationHelper.getDecoratedStart(
                    longItem)
                    < carUiRecyclerView.getTotalSpace()) {
                check.set(true);
            } else {
                topBeforeClick.set(orientationHelper.getDecoratedStart(longItem));
            }
        });

        onView(withId(getId("car_ui_scrollbar_page_up"))).perform(click());

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            View longItem = getLongItem(carUiRecyclerView);
            if (check.get()) {
                OrientationHelper orientationHelper =
                        OrientationHelper.createVerticalHelper(
                                carUiRecyclerView.getLayoutManager());
                assertThat(orientationHelper.getDecoratedStart(longItem),
                        is(greaterThanOrEqualTo(carUiRecyclerView.getStartAfterPadding())));
            } else {
                // Verify we scrolled 1 screen
                assertThat(carUiRecyclerView.getStartAfterPadding() - topBeforeClick.get(),
                        is(equalTo(carUiRecyclerView.getTotalSpace())));
            }
        });
    }

    @Test
    public void testPageDownScrollsOverVeryLongItem() {
        if (mIsPluginEnabled) {
            return;
        }

        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_test_activity));

        onView(withId(R.id.list)).check(matches(isDisplayed()));

        int itemCount = 100;
        // Position the long item in the middle.
        int longItemPosition = itemCount / 2;

        Map<Integer, TestAdapter.ItemHeight> heightOverrides = new HashMap<>();
        heightOverrides.put(longItemPosition, TestAdapter.ItemHeight.EXTRA_TALL);
        TestAdapter adapter = new TestAdapter(itemCount, heightOverrides);

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            carUiRecyclerView.setAdapter(adapter);

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        int screenHeight = Resources.getSystem().getDisplayMetrics().heightPixels;
        // Scroll to a position where long item is partially visible.
        // Scrolling from top, scrollToPosition() aligns the pos-1 item to bottom.
        onView(withId(R.id.list)).perform(scrollToPosition(longItemPosition - 1));

        onView(withText(adapter.getItemText(longItemPosition - 1)))
                .check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            // Scroll by half the height of the screen so the long item is partially visible.
            carUiRecyclerView.scrollBy(0, screenHeight / 2);
        });

        onView(withText(adapter.getItemText(longItemPosition))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            OrientationHelper orientationHelper =
                    OrientationHelper.createVerticalHelper(carUiRecyclerView.getLayoutManager());
            // Verify long item is partially shown.
            View longItem = getLongItem(carUiRecyclerView);
            assertThat(
                    orientationHelper.getDecoratedStart(longItem),
                    is(greaterThan(carUiRecyclerView.getStartAfterPadding())));
        });

        onView(withId(getId("car_ui_scrollbar_page_down"))).perform(click());

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            View longItem = getLongItem(carUiRecyclerView);
            OrientationHelper orientationHelper =
                    OrientationHelper.createVerticalHelper(carUiRecyclerView.getLayoutManager());
            // Verify long item is snapped to top.
            assertThat(orientationHelper.getDecoratedStart(longItem),
                    is(equalTo(carUiRecyclerView.getStartAfterPadding())));
            assertThat(orientationHelper.getDecoratedEnd(longItem),
                    is(greaterThan(carUiRecyclerView.getEndAfterPadding())));
        });

        onView(withId(getId("car_ui_scrollbar_page_down"))).perform(click());

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            OrientationHelper orientationHelper =
                    OrientationHelper.createVerticalHelper(carUiRecyclerView.getLayoutManager());
            View longItem = getLongItem(carUiRecyclerView);
            // Verify long item does not snap to bottom.
            assertThat(orientationHelper.getDecoratedEnd(longItem),
                    not(equalTo(carUiRecyclerView.getEndAfterPadding())));
        });
    }

    @Test
    public void testPageDownScrollsOverVeryLongItemAtTheEnd() {
        if (mIsPluginEnabled) {
            return;
        }

        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_test_activity));

        onView(withId(R.id.list)).check(matches(isDisplayed()));

        int itemCount = 100;
        // Position the long item at the end.
        int longItemPosition = itemCount - 1;

        Map<Integer, TestAdapter.ItemHeight> heightOverrides = new HashMap<>();
        heightOverrides.put(longItemPosition, TestAdapter.ItemHeight.EXTRA_TALL);
        TestAdapter adapter = new TestAdapter(itemCount, heightOverrides);

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            // Setting top padding to any number greater than 0.
            // Not having padding will make this test pass all the time.
            // Also adding bottom padding to make sure the padding
            // after the last content is considered in calculations.
            carUiRecyclerView.setPadding(0, 1, 0, 1);
            carUiRecyclerView.setAdapter(adapter);

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        // 20 is just an arbitrary number to make sure we reach the end of the recyclerview.
        for (int i = 0; i < 20; i++) {
            onView(withId(getId("car_ui_scrollbar_page_down"))).perform(click());
        }

        onView(withId(getId("car_ui_scrollbar_page_down"))).check(matches(not(isEnabled())));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            OrientationHelper orientationHelper =
                    OrientationHelper.createVerticalHelper(carUiRecyclerView.getLayoutManager());
            View longItem = getLongItem(carUiRecyclerView);
            // Making sure we've reached end of the recyclerview, after
            // adding bottom padding
            assertThat(orientationHelper.getDecoratedEnd(longItem),
                    is(equalTo(carUiRecyclerView.getEndAfterPadding())));
        });
    }

    @Test
    public void testPageDownMaintainsMinimumScrollThumbTrackHeight() {
        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_test_activity));

        onView(withId(R.id.list)).check(matches(isDisplayed()));

        int itemCount = 2500;
        TestAdapter adapter = new TestAdapter(itemCount);

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            carUiRecyclerView.setAdapter(adapter);
            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
            carUiRecyclerView.requestLayout();
        });

        onView(withId(getId("car_ui_scrollbar_page_down"))).perform(click());

        mActivityRule.getScenario().onActivity(activity -> {
            // Check that thumb track maintains minimum height
            int minThumbViewHeight = (int) activity.getResources()
                    .getDimension(R.dimen.car_ui_scrollbar_min_thumb_height);
            View thumbView = activity.requireViewById(getId("car_ui_scrollbar_thumb"));
            // Conversion from DP to pixel sometimes makes these two value differ by 1
            assertThat(abs(thumbView.getHeight() - minThumbViewHeight), is(lessThanOrEqualTo(1)));
        });
    }

    @Test
    public void testRecyclerView_canScrollVertically() {
        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_test_activity));

        onView(withId(R.id.list)).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            // Can't use OrientationHelper here, because it returns 0 when calling getTotalSpace
            // methods until LayoutManager's onLayoutComplete is called. In this case waiting until
            // the first item of the list is displayed guarantees that OrientationHelper is
            // initialized properly.
            int totalSpace = carUiRecyclerView.getHeight()
                    - carUiRecyclerView.getPaddingTop()
                    - carUiRecyclerView.getPaddingBottom();
            PerfectFitTestAdapter adapter = new PerfectFitTestAdapter(1, totalSpace);
            carUiRecyclerView.setAdapter(adapter);

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        onView(withText(PerfectFitTestAdapter.getItemText(0))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(R.id.list);
            int totalSpace = carUiRecyclerView.getHeight()
                    - carUiRecyclerView.getPaddingTop()
                    - carUiRecyclerView.getPaddingBottom();

            assertEquals(totalSpace, carUiRecyclerView.getTotalSpace());

            // Both scroll up and down are disabled
            assertFalse(carUiRecyclerView.getView().canScrollVertically(1));
            assertFalse(carUiRecyclerView.getView().canScrollVertically(-1));
        });
    }

    @Test
    public void testSetPaddingToRecyclerViewContainerWithScrollbar() {
        TestAdapter adapter = new TestAdapter(50);
        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(activity);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(adapter);
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));
        onView(withId(getId("car_ui_scroll_bar"))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            assertThat(carUiRecyclerView.getStartAfterPadding(), is(equalTo(0)));
            assertThat(carUiRecyclerView.getView().getPaddingLeft(), is(equalTo(0)));
            assertThat(carUiRecyclerView.getView().getPaddingRight(), is(equalTo(0)));
            // available space in recyclerview after applying paddings.
            int screenHeight = carUiRecyclerView.getTotalSpace();
            assertThat(carUiRecyclerView.getHeight(), is(equalTo(screenHeight)));

            View scrollbar = activity.findViewById(getId("car_ui_scroll_bar"));
            assertThat(scrollbar.getPaddingTop(), is(equalTo(0)));
            assertThat(scrollbar.getPaddingLeft(), is(equalTo(0)));
            assertThat(scrollbar.getPaddingRight(), is(equalTo(0)));
            assertThat(scrollbar.getPaddingBottom(), is(equalTo(0)));

            carUiRecyclerView.setPadding(20, 150, 30, 170);
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            assertThat(carUiRecyclerView.getView().getPaddingLeft(), is(equalTo(20)));
            assertThat(carUiRecyclerView.getView().getPaddingRight(), is(equalTo(30)));
            assertThat(carUiRecyclerView.getStartAfterPadding(), is(equalTo(150)));

            // available space in recyclerview after applying paddings.
            int screenHeight = carUiRecyclerView.getTotalSpace();
            assertThat(carUiRecyclerView.getHeight() - 150 - 170, is(equalTo(screenHeight)));

            View scrollbar = activity.findViewById(getId("car_ui_scroll_bar"));
            assertThat(scrollbar.getPaddingTop(), is(equalTo(150)));
            assertThat(scrollbar.getPaddingLeft(), is(equalTo(0)));
            assertThat(scrollbar.getPaddingRight(), is(equalTo(0)));
            assertThat(scrollbar.getPaddingBottom(), is(equalTo(170)));
        });
    }

    @Test
    public void testSetPaddingToRecyclerViewContainerWithoutScrollbar() {
        if (mIsPluginEnabled) {
            return;
        }

        TestAdapter adapter = new TestAdapter(5);
        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);
            // Disable scrollbar
            doReturn(false).when(testableResources)
                    .getBoolean(R.bool.car_ui_scrollbar_enable);

            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(testableContext);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(adapter);
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));
        onView(withId(getId("car_ui_scroll_bar"))).check(doesNotExist());

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            assertThat(carUiRecyclerView.getStartAfterPadding(), is(equalTo(0)));
            assertThat(carUiRecyclerView.getView().getPaddingLeft(), is(equalTo(0)));
            assertThat(carUiRecyclerView.getView().getPaddingRight(), is(equalTo(0)));
            // available space in recyclerview after applying paddings.
            int screenHeight = carUiRecyclerView.getTotalSpace();
            assertThat(carUiRecyclerView.getHeight(), is(equalTo(screenHeight)));

            carUiRecyclerView.setPadding(20, 150, 30, 170);
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            assertThat(carUiRecyclerView.getView().getPaddingLeft(), is(equalTo(20)));
            assertThat(carUiRecyclerView.getView().getPaddingRight(), is(equalTo(30)));
            assertThat(carUiRecyclerView.getStartAfterPadding(), is(equalTo(150)));
            // available space in recyclerview after applying paddings.
            int screenHeight = carUiRecyclerView.getTotalSpace();
            assertThat(carUiRecyclerView.getHeight() - 150 - 170, is(equalTo(screenHeight)));
        });
    }

    @Test
    public void testSetPaddingRelativeToRecyclerViewContainerWithScrollbar() {
        TestAdapter adapter = new TestAdapter(50);
        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(activity);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(adapter);
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));
        onView(withId(getId("car_ui_scroll_bar"))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            assertThat(carUiRecyclerView.getStartAfterPadding(), is(equalTo(0)));
            assertThat(carUiRecyclerView.getView().getPaddingStart(), is(equalTo(0)));
            assertThat(carUiRecyclerView.getView().getPaddingEnd(), is(equalTo(0)));
            // available space in recyclerview after applying paddings.
            int screenHeight = carUiRecyclerView.getTotalSpace();
            assertThat(carUiRecyclerView.getHeight(), is(equalTo(screenHeight)));

            View scrollbar = activity.findViewById(getId("car_ui_scroll_bar"));
            assertThat(scrollbar.getPaddingTop(), is(equalTo(0)));
            assertThat(scrollbar.getPaddingStart(), is(equalTo(0)));
            assertThat(scrollbar.getPaddingEnd(), is(equalTo(0)));
            assertThat(scrollbar.getPaddingBottom(), is(equalTo(0)));

            carUiRecyclerView.setPaddingRelative(20, 150, 30, 170);
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            assertThat(carUiRecyclerView.getView().getPaddingStart(), is(equalTo(20)));
            assertThat(carUiRecyclerView.getView().getPaddingEnd(), is(equalTo(30)));
            assertThat(carUiRecyclerView.getStartAfterPadding(), is(equalTo(150)));
            // available space in recyclerview after applying paddings.
            int screenHeight = carUiRecyclerView.getTotalSpace();
            assertThat(carUiRecyclerView.getHeight() - 150 - 170, is(equalTo(screenHeight)));

            View scrollbar = activity.findViewById(getId("car_ui_scroll_bar"));
            assertThat(scrollbar.getPaddingTop(), is(equalTo(150)));
            assertThat(scrollbar.getPaddingStart(), is(equalTo(0)));
            assertThat(scrollbar.getPaddingEnd(), is(equalTo(0)));
            assertThat(scrollbar.getPaddingBottom(), is(equalTo(170)));
        });
    }

    @Test
    public void testSetPaddingRelativeToRecyclerViewContainerWithoutScrollbar() {
        if (mIsPluginEnabled) {
            return;
        }

        TestAdapter adapter = new TestAdapter(5);
        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);
            // Disable scrollbar
            doReturn(false).when(testableResources)
                    .getBoolean(R.bool.car_ui_scrollbar_enable);


            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(testableContext);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(adapter);
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));
        onView(withId(getId("car_ui_scroll_bar"))).check(doesNotExist());

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            assertThat(carUiRecyclerView.getStartAfterPadding(), is(equalTo(0)));
            assertThat(carUiRecyclerView.getView().getPaddingStart(), is(equalTo(0)));
            assertThat(carUiRecyclerView.getView().getPaddingEnd(), is(equalTo(0)));
            // available space in recyclerview after applying paddings.
            int screenHeight = carUiRecyclerView.getTotalSpace();
            assertThat(carUiRecyclerView.getHeight(), is(equalTo(screenHeight)));

            carUiRecyclerView.setPaddingRelative(20, 150, 30, 170);
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            assertThat(carUiRecyclerView.getView().getPaddingStart(), is(equalTo(20)));
            assertThat(carUiRecyclerView.getView().getPaddingEnd(), is(equalTo(30)));
            assertThat(carUiRecyclerView.getStartAfterPadding(), is(equalTo(150)));
            // available space in recyclerview after applying paddings.
            int screenHeight = carUiRecyclerView.getTotalSpace();
            assertThat(carUiRecyclerView.getHeight() - 150 - 170, is(equalTo(screenHeight)));
        });
    }

    @Test
    public void testSetAlphaToRecyclerView() {
        if (mIsPluginEnabled) {
            return;
        }

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(activity);
            assertThat(carUiRecyclerView.getView().getAlpha(), is(equalTo(1.0f)));
            carUiRecyclerView.setAlpha(0.5f);
            assertThat(carUiRecyclerView.getView().getAlpha(), is(equalTo(0.5f)));
        });
    }

    @Test
    public void testScrollbarVisibility_tooSmallHeight() {
        if (mIsPluginEnabled) {
            return;
        }

        // Set to anything less than 2 * (minTouchSize + margin)
        // minTouchSize = R.dimen.car_ui_touch_target_size
        // margin is button up top margin or button down bottom margin
        int recyclerviewHeight = 1;

        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(activity);
            ViewGroup container = activity.findViewById(R.id.test_container);
            FrameLayout.LayoutParams lp = new FrameLayout.LayoutParams(-1, recyclerviewHeight);
            container.addView(carUiRecyclerView.getView(), lp);
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(new TestAdapter(100));
        });

        onView(withId(getId("car_ui_scroll_bar"))).check(matches(not(isDisplayed())));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            assertEquals(recyclerviewHeight, carUiRecyclerView.getTotalSpace());
        });
    }

    @Test
    public void testScrollbarVisibility_justEnoughToShowOnlyButtons() {
        Context context = getInstrumentation().getTargetContext();
        int listId = View.generateViewId();

        // R.dimen.car_ui_touch_target_size
        float minTouchSize = context.getResources().getDimension(R.dimen.car_ui_touch_target_size);
        // This value is hardcoded to 15dp in the layout.
        int margin = (int) dpToPixel(context, 15)
                + (int) context.getResources().getDimension(
                R.dimen.car_ui_scrollbar_separator_margin);
        // Set to 2 * (minTouchSize + margin)
        int recyclerviewHeight = 2 * (int) (minTouchSize + margin);


        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(activity);
            ViewGroup container = activity.findViewById(R.id.test_container);
            FrameLayout.LayoutParams lp = new FrameLayout.LayoutParams(-1, recyclerviewHeight);
            container.addView(carUiRecyclerView.getView(), lp);
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(new TestAdapter(100));
        });

        onView(withId(getId("car_ui_scroll_bar"))).check(matches(isDisplayed()));
        onView(withId(getId("car_ui_scrollbar_thumb"))).check(matches(not(isDisplayed())));
        onView(withId(getId("car_ui_scrollbar_track"))).check(matches(not(isDisplayed())));
        onView(withId(getId("car_ui_scrollbar_page_down"))).check(matches(isDisplayed()));
        onView(withId(getId("car_ui_scrollbar_page_up"))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            int screenHeight = carUiRecyclerView.getTotalSpace();
            assertEquals(recyclerviewHeight, screenHeight);
        });
    }

    @Test
    public void testScrollbarVisibility_enoughToShowEverything() {
        Context context = getInstrumentation().getTargetContext();
        int listId = View.generateViewId();

        int minTouchSize = (int) context.getResources().getDimension(
                R.dimen.car_ui_touch_target_size);
        int mScrollbarThumbMinHeight = (int) context.getResources()
                .getDimension(R.dimen.car_ui_scrollbar_min_thumb_height);
        // This value is hardcoded to 15dp in the layout.
        int margin = (int) dpToPixel(context, 15)
                + (int) context.getResources().getDimension(
                R.dimen.car_ui_scrollbar_separator_margin);
        int trackMargin = 2 * (int) context.getResources()
                .getDimension(R.dimen.car_ui_scrollbar_separator_margin);
        // Set to anything greater or equal to
        // 2 * minTouchSize + max(minTouchSize, mScrollbarThumbMinHeight) + 2 * margin
        int recyclerviewHeight =
                2 * minTouchSize
                        + max(minTouchSize, mScrollbarThumbMinHeight)
                        + 2 * margin + trackMargin;

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(activity);
            ViewGroup container = activity.findViewById(R.id.test_container);
            FrameLayout.LayoutParams lp = new FrameLayout.LayoutParams(-1, recyclerviewHeight);
            container.addView(carUiRecyclerView.getView(), lp);
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(new TestAdapter(100));
        });

        onView(withId(getId("car_ui_scroll_bar"))).check(matches(isDisplayed()));
        onView(withId(getId("car_ui_scrollbar_thumb"))).check(matches(isDisplayed()));
        onView(withId(getId("car_ui_scrollbar_track"))).check(matches(isDisplayed()));
        onView(withId(getId("car_ui_scrollbar_page_down"))).check(matches(isDisplayed()));
        onView(withId(getId("car_ui_scrollbar_page_up"))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            assertEquals(recyclerviewHeight, carUiRecyclerView.getTotalSpace());
        });
    }

    @Test
    public void testDefaultSize_noScrollbar() {
        if (mIsPluginEnabled) {
            return;
        }

        TestAdapter adapter = new TestAdapter(50);
        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);
            // Disable scrollbar
            doReturn(false).when(testableResources)
                    .getBoolean(R.bool.car_ui_scrollbar_enable);


            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(testableContext);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(adapter);
        });

        onView(withId(getId("car_ui_scroll_bar"))).check(doesNotExist());
        onView(withText(adapter.getItemText(0))).check(isLeftAlignedWith(withId(listId)));
        onView(withText(adapter.getItemText(0))).check(isRightAlignedWith(withId(listId)));
    }

    @Test
    public void testLargeSize_withScrollbar() {
        TestAdapter adapter = new TestAdapter(50);
        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);
            TypedArray typedArray = spy(activity.getBaseContext().obtainStyledAttributes(
                    null, R.styleable.CarUiRecyclerView));

            doReturn(typedArray).when(testableContext).obtainStyledAttributes(
                    any(),
                    eq(R.styleable.CarUiRecyclerView),
                    anyInt(),
                    anyInt());
            when(typedArray.getInt(eq(R.styleable.CarUiRecyclerView_carUiSize),
                    anyInt())).thenReturn(2); // Large size

            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(testableContext);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(adapter);
        });

        onView(withId(getId("car_ui_scroll_bar"))).check(matches(isDisplayed()));
        onView(withText(adapter.getItemText(0))).check(
                isCompletelyRightOf(withId(getId("car_ui_scroll_bar"))));
        onView(withText(adapter.getItemText(0))).check(
                matches(not(isRightAlignedWith(withId(listId)))));
    }

    @Test
    public void testMediumSize_withScrollbar() {

        TestAdapter adapter = new TestAdapter(50);
        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);
            TypedArray typedArray = spy(activity.getBaseContext().obtainStyledAttributes(
                    null, R.styleable.CarUiRecyclerView));

            doReturn(typedArray).when(testableContext).obtainStyledAttributes(
                    any(),
                    eq(R.styleable.CarUiRecyclerView),
                    anyInt(),
                    anyInt());
            when(typedArray.getInt(eq(R.styleable.CarUiRecyclerView_carUiSize),
                    anyInt())).thenReturn(1); // Medium size

            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(testableContext);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(adapter);
        });

        onView(withId(getId("car_ui_scroll_bar"))).check(matches(isDisplayed()));
        onView(withText(adapter.getItemText(0))).check(
                isCompletelyRightOf(withId(getId("car_ui_scroll_bar"))));
        onView(withText(adapter.getItemText(0))).check(isRightAlignedWith(withId(listId)));
    }

    @Test
    public void testSmallSize_oneItem() {
        TestAdapter adapter = new TestAdapter(1);
        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);
            TypedArray typedArray = spy(activity.getBaseContext().obtainStyledAttributes(
                    null, R.styleable.CarUiRecyclerView));

            doReturn(typedArray).when(testableContext).obtainStyledAttributes(
                    any(),
                    eq(R.styleable.CarUiRecyclerView),
                    anyInt(),
                    anyInt());
            when(typedArray.getInt(eq(R.styleable.CarUiRecyclerView_carUiSize),
                    anyInt())).thenReturn(0); // Small size

            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(testableContext);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(adapter);
        });

        onView(withId(getId("car_ui_scroll_bar"))).check(doesNotExistOrIsNotDisplayed());
        onView(withText(adapter.getItemText(0))).check(isLeftAlignedWith(withId(listId)));
        onView(withText(adapter.getItemText(0))).check(isRightAlignedWith(withId(listId)));
    }

    @Test
    public void testSmallSize_multipleItem() {
        TestAdapter adapter = new TestAdapter(50);
        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);
            TypedArray typedArray = spy(activity.getBaseContext().obtainStyledAttributes(
                    null, R.styleable.CarUiRecyclerView));

            doReturn(typedArray).when(testableContext).obtainStyledAttributes(
                    any(),
                    eq(R.styleable.CarUiRecyclerView),
                    anyInt(),
                    anyInt());
            when(typedArray.getInt(eq(R.styleable.CarUiRecyclerView_carUiSize),
                    anyInt())).thenReturn(0); // Small size

            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(testableContext);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(adapter);
        });

        onView(withId(getId("car_ui_scroll_bar"))).check(matches(isDisplayed()));
        onView(withText(adapter.getItemText(0))).check(
                isCompletelyRightOf(withId(getId("car_ui_scroll_bar"))));
        onView(withText(adapter.getItemText(0))).check(isRightAlignedWith(withId(listId)));
    }

    @Test
    public void testSameSizeItems_estimateNextPositionDiffForScrollDistance() {
        if (mIsPluginEnabled) {
            return;
        }

        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_test_activity));

        onView(withId(R.id.list)).check(matches(isDisplayed()));

        int itemCount = 100;
        TestAdapter adapter = new TestAdapter(itemCount);

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerViewImpl carUiRecyclerView = activity.requireViewById(R.id.list);
            carUiRecyclerView.setAdapter(adapter);

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerViewImpl carUiRecyclerView = activity.requireViewById(R.id.list);
            int firstViewHeight = carUiRecyclerView.getRecyclerViewChildAt(0).getHeight();
            int itemsToScroll = 10;
            OrientationHelper orientationHelper = OrientationHelper.createVerticalHelper(
                    carUiRecyclerView.getLayoutManager());
            CarUiSnapHelper snapHelper = new CarUiSnapHelper(activity);
            // Get an estimate of how many items CarUiSnapHelper says we need to scroll. The scroll
            // distance is set to 10 * height of the first item. Since all items have the items have
            // the same height, we're expecting to get exactly 10 back from CarUiSnapHelper.
            int estimate = snapHelper.estimateNextPositionDiffForScrollDistance(
                    orientationHelper, itemsToScroll * firstViewHeight);

            assertEquals(estimate, itemsToScroll);
        });
    }

    @Test
    public void testSameSizeItems_estimateNextPositionDiffForScrollDistance_zeroDistance() {
        if (mIsPluginEnabled) {
            return;
        }

        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_test_activity));

        onView(withId(R.id.list)).check(matches(isDisplayed()));

        int itemCount = 100;
        TestAdapter adapter = new TestAdapter(itemCount);

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerViewImpl carUiRecyclerView = activity.requireViewById(R.id.list);
            carUiRecyclerView.setAdapter(adapter);

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerViewImpl carUiRecyclerView = activity.requireViewById(R.id.list);
            OrientationHelper orientationHelper = OrientationHelper.createVerticalHelper(
                    carUiRecyclerView.getLayoutManager());
            int firstViewHeight = carUiRecyclerView.getRecyclerViewChildAt(0).getHeight();
            // the scroll distance has to be less than half of the size of the first view so that
            // recyclerview doesn't snap to the next view
            int distantToScroll = (firstViewHeight / 2) - 1;
            CarUiSnapHelper snapHelper = new CarUiSnapHelper(activity);
            int estimate = snapHelper.estimateNextPositionDiffForScrollDistance(
                    orientationHelper, distantToScroll);

            assertEquals(estimate, 0);
        });

    }

    @Test
    public void testSameSizeItems_estimateNextPositionDiffForScrollDistance_zeroHeight() {
        if (mIsPluginEnabled) {
            return;
        }

        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_test_activity));

        onView(withId(R.id.list)).check(matches(isDisplayed()));

        int itemCount = 1;
        Map<Integer, TestAdapter.ItemHeight> heightOverrides = new HashMap<>();
        heightOverrides.put(0, TestAdapter.ItemHeight.ZERO);
        TestAdapter adapter = new TestAdapter(itemCount, heightOverrides);

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerViewImpl carUiRecyclerView = activity.requireViewById(R.id.list);
            carUiRecyclerView.setAdapter(adapter);

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        onView(withContentDescription("ZERO")).check(matches(isEnabled()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerViewImpl carUiRecyclerView = activity.requireViewById(R.id.list);
            OrientationHelper orientationHelper = OrientationHelper.createVerticalHelper(
                    carUiRecyclerView.getLayoutManager());
            // 10 is an arbitrary number
            int distantToScroll = 10;
            CarUiSnapHelper snapHelper = new CarUiSnapHelper(activity);
            int estimate = snapHelper.estimateNextPositionDiffForScrollDistance(
                    orientationHelper, distantToScroll);

            assertEquals(estimate, 0);
        });
    }

    @Test
    public void testSameSizeItems_estimateNextPositionDiffForScrollDistance_zeroItems() {
        if (mIsPluginEnabled) {
            return;
        }

        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_test_activity));

        onView(withId(R.id.list)).check(matches(isDisplayed()));

        int itemCount = 0;
        TestAdapter adapter = new TestAdapter(itemCount);

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerViewImpl carUiRecyclerView = activity.requireViewById(R.id.list);
            carUiRecyclerView.setAdapter(adapter);

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerViewImpl carUiRecyclerView = activity.requireViewById(R.id.list);
            OrientationHelper orientationHelper = OrientationHelper.createVerticalHelper(
                    carUiRecyclerView.getLayoutManager());
            CarUiSnapHelper snapHelper = new CarUiSnapHelper(activity);
            int estimate = snapHelper.estimateNextPositionDiffForScrollDistance(
                    orientationHelper, 50);

            assertEquals(estimate, 50);
        });
    }

    @Test
    public void testEmptyList_calculateScrollDistanceClampToScreenSize() {
        if (mIsPluginEnabled) {
            return;
        }

        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_test_activity));

        int itemCount = 0;
        TestAdapter adapter = new TestAdapter(itemCount);

        onView(withId(R.id.list)).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerViewImpl carUiRecyclerView = activity.requireViewById(R.id.list);
            carUiRecyclerView.setAdapter(adapter);

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));

            LinearSnapHelper linearSnapHelper = new LinearSnapHelper();
            carUiRecyclerView.setOnFlingListener(null);
            linearSnapHelper.attachToRecyclerView(
                    ((CarUiRecyclerViewImpl) carUiRecyclerView).getRecyclerView());
            // 200 is just an arbitrary number. the intent is to make sure the return value is
            // smaller
            // than the layoutmanager height.
            int[] baseOutDist = linearSnapHelper.calculateScrollDistance(200, -200);

            CarUiSnapHelper carUiSnapHelper = new CarUiSnapHelper(activity);
            carUiRecyclerView.setOnFlingListener(null);
            carUiSnapHelper.attachToRecyclerView(
                    ((CarUiRecyclerViewImpl) carUiRecyclerView).getRecyclerView());
            int[] outDist = carUiSnapHelper.calculateScrollDistance(200, -200);

            assertEquals(outDist[0], baseOutDist[0]);
            assertEquals(outDist[1], baseOutDist[1]);
        });
    }

    @Test
    public void testCalculateScrollDistanceClampToScreenSize() {
        if (mIsPluginEnabled) {
            return;
        }

        mActivityRule.getScenario().onActivity(activity -> activity.setContentView(
                R.layout.car_ui_recycler_view_test_activity));

        onView(withId(R.id.list)).check(matches(isDisplayed()));

        int itemCount = 100;
        TestAdapter adapter = new TestAdapter(itemCount);

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerViewImpl carUiRecyclerView = activity.requireViewById(R.id.list);
            carUiRecyclerView.setAdapter(adapter);

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerViewImpl carUiRecyclerView = activity.requireViewById(R.id.list);
            LayoutManager layoutManager = carUiRecyclerView.getLayoutManager();
            OrientationHelper orientationHelper = OrientationHelper.createVerticalHelper(
                    layoutManager);

            LinearSnapHelper linearSnapHelper = new LinearSnapHelper();
            carUiRecyclerView.setOnFlingListener(null);
            linearSnapHelper.attachToRecyclerView(
                    ((CarUiRecyclerViewImpl) carUiRecyclerView).getRecyclerView());
            // 8000 is just an arbitrary number. the intent is to make sure the return value is
            // bigger
            // than the layoutmanager height.
            int[] baseOutDist = linearSnapHelper.calculateScrollDistance(8000, -8000);

            CarUiSnapHelper carUiSnapHelper = new CarUiSnapHelper(activity);
            carUiRecyclerView.setOnFlingListener(null);
            carUiSnapHelper.attachToRecyclerView(
                    ((CarUiRecyclerViewImpl) carUiRecyclerView).getRecyclerView());
            int[] outDist = carUiSnapHelper.calculateScrollDistance(8000, -8000);

            int lastChildPosition = carUiSnapHelper.isAtEnd(carUiRecyclerView.getLayoutManager())
                    ? 0 : carUiRecyclerView.getRecyclerViewChildCount() - 1;
            View lastChild = Objects.requireNonNull(
                    carUiRecyclerView.getRecyclerViewChildAt(lastChildPosition));
            float percentageVisible = CarUiSnapHelper
                    .getPercentageVisible(lastChild, orientationHelper);

            int maxDistance = carUiRecyclerView.getTotalSpace();
            if (percentageVisible > 0.f) {
                // The max and min distance is the total height of the RecyclerView minus the
                // height of
                // the last child. This ensures that each scroll will never scroll more than a
                // single
                // page on the RecyclerView. That is, the max scroll will make the last child the
                // first child and vice versa when scrolling the opposite way.
                maxDistance -= carUiRecyclerView.getLayoutManager()
                        .getDecoratedMeasuredHeight(lastChild);
            }
            int minDistance = -maxDistance;

            assertEquals(clamp(baseOutDist[0], minDistance, maxDistance), outDist[0]);
            assertEquals(clamp(baseOutDist[1], minDistance, maxDistance), outDist[1]);
        });
    }

    @Test
    public void testContinuousScrollListenerConstructor_negativeInitialDelay() {
        if (mIsPluginEnabled) {
            return;
        }

        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);
            doReturn(-1).when(testableResources)
                    .getInteger(R.integer.car_ui_scrollbar_longpress_initial_delay);

            IllegalArgumentException ex = assertThrows(IllegalArgumentException.class,
                    () -> CarUiRecyclerView.create(testableContext));
            assertEquals("negative intervals are not allowed", ex.getMessage());
        });
    }

    @Test
    public void testContinuousScrollListenerConstructor_negativeRepeatInterval() {
        if (mIsPluginEnabled) {
            return;
        }

        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);
            doReturn(-1).when(testableResources)
                    .getInteger(R.integer.car_ui_scrollbar_longpress_repeat_interval);

            IllegalArgumentException ex = assertThrows(IllegalArgumentException.class,
                    () -> CarUiRecyclerView.create(testableContext));
            assertEquals("negative intervals are not allowed", ex.getMessage());
        });
    }

    @Test
    public void testUnknownClass_createScrollBarFromConfig() {
        if (mIsPluginEnabled) {
            return;
        }

        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);
            doReturn("random.class").when(testableResources)
                    .getString(R.string.car_ui_scrollbar_component);

            RuntimeException ex = assertThrows(RuntimeException.class,
                    () -> CarUiRecyclerView.create(testableContext));
            assertEquals("Error loading scroll bar component: random.class", ex.getMessage());
        });
    }

    @Test
    public void testWrongType_createScrollBarFromConfig() {
        if (mIsPluginEnabled) {
            return;
        }

        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);
            // Basically return any class that exists but doesn't extend ScrollBar
            doReturn(CarUiRecyclerView.class.getName()).when(testableResources)
                    .getString(R.string.car_ui_scrollbar_component);

            RuntimeException ex = assertThrows(RuntimeException.class,
                    () -> CarUiRecyclerView.create(testableContext));
            assertEquals("Error creating scroll bar component: "
                    + CarUiRecyclerView.class.getName(), ex.getMessage());
        });
    }

    @Test
    public void testSetLinearLayoutStyle_setsLayoutManager() {
        if (mIsPluginEnabled) {
            return;
        }

        TestAdapter adapter = new TestAdapter(50);
        int listId = View.generateViewId();
        CarUiLayoutStyle layoutStyle = new CarUiLinearLayoutStyle();

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerViewImpl carUiRecyclerView =
                    (CarUiRecyclerViewImpl) CarUiRecyclerView.create(activity);
            carUiRecyclerView.setLayoutStyle(layoutStyle);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(adapter);
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerViewImpl carUiRecyclerView = activity.requireViewById(listId);
            assertTrue(carUiRecyclerView.getLayoutManager() instanceof LinearLayoutManager);
            assertEquals(
                    ((LinearLayoutManager) carUiRecyclerView.getLayoutManager()).getOrientation(),
                    layoutStyle.getOrientation());
            assertEquals(((LinearLayoutManager) carUiRecyclerView.getLayoutManager())
                    .getReverseLayout(), layoutStyle.getReverseLayout());
        });
    }

    @Test
    public void testSetGridLayoutStyle_setsLayoutManager() {
        if (mIsPluginEnabled) {
            return;
        }

        TestAdapter adapter = new TestAdapter(50);
        CarUiLayoutStyle layoutStyle = new CarUiGridLayoutStyle();
        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerViewImpl carUiRecyclerView =
                    (CarUiRecyclerViewImpl) CarUiRecyclerView.create(activity);
            carUiRecyclerView.setLayoutStyle(layoutStyle);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(adapter);
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerViewImpl carUiRecyclerView = activity.requireViewById(listId);
            assertTrue(carUiRecyclerView.getLayoutManager() instanceof GridLayoutManager);
            assertEquals(
                    ((GridLayoutManager) carUiRecyclerView.getLayoutManager()).getOrientation(),
                    layoutStyle.getOrientation());
            assertEquals(
                    ((GridLayoutManager) carUiRecyclerView.getLayoutManager()).getReverseLayout(),
                    layoutStyle.getReverseLayout());
            assertEquals(((GridLayoutManager) carUiRecyclerView.getLayoutManager()).getSpanCount(),
                    layoutStyle.getSpanCount());
        });
    }

    @Test
    public void testNegativeSpanCount_setSpanCount() {
        CarUiGridLayoutStyle layoutStyle = new CarUiGridLayoutStyle();
        AssertionError ex = assertThrows(AssertionError.class,
                () -> layoutStyle.setSpanCount((-1)));
        assertEquals("Span count must be bigger than 0", ex.getMessage());
    }

    @Test
    public void testSetGridLayoutStyle_setsLayoutManagerSpanSizeLookup() {
        CarUiGridLayoutStyle layoutStyle = new CarUiGridLayoutStyle();
        // has to bigger than span sizes for all the rows
        layoutStyle.setSpanCount(20);
        SpanSizeLookup spanSizeLookup = new SpanSizeLookup() {
            @Override
            public int getSpanSize(int position) {
                switch (position) {
                    case 0:
                        return 10;
                    case 1:
                        return 20;
                    default:
                        return 15;
                }
            }
        };
        layoutStyle.setSpanSizeLookup(spanSizeLookup);
        TestAdapter adapter = new TestAdapter(50);
        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(activity);
            carUiRecyclerView.setLayoutStyle(layoutStyle);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(adapter);
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            assertTrue(carUiRecyclerView.getLayoutStyle() instanceof CarUiGridLayoutStyle);
            assertEquals(
                    ((CarUiGridLayoutStyle) carUiRecyclerView.getLayoutStyle()).getSpanSizeLookup()
                            .getSpanSize(0), spanSizeLookup.getSpanSize(0));
            assertEquals(
                    ((CarUiGridLayoutStyle) carUiRecyclerView.getLayoutStyle()).getSpanSizeLookup()
                            .getSpanSize(1), spanSizeLookup.getSpanSize(1));
            assertEquals(
                    ((CarUiGridLayoutStyle) carUiRecyclerView.getLayoutStyle()).getSpanSizeLookup()
                            .getSpanSize(2), spanSizeLookup.getSpanSize(2));
        });
    }

    @Test
    public void testCarUiGridLayoutStyle_LayoutManagerFrom() {
        if (mIsPluginEnabled) {
            return;
        }

        TestAdapter adapter = new TestAdapter(50);
        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            GridLayoutManager layoutManager =
                    new GridLayoutManager(activity, 20, RecyclerView.VERTICAL, true);
            layoutManager.setSpanSizeLookup(new SpanSizeLookup() {
                @Override
                public int getSpanSize(int position) {
                    switch (position) {
                        case 0:
                            return 10;
                        case 1:
                            return 20;
                        default:
                            return 15;
                    }
                }
            });
            CarUiGridLayoutStyle layoutStyle = CarUiGridLayoutStyle.from(layoutManager);
            CarUiRecyclerViewImpl carUiRecyclerView =
                    (CarUiRecyclerViewImpl) CarUiRecyclerView.create(activity);
            carUiRecyclerView.setLayoutStyle(layoutStyle);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(adapter);
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerViewImpl carUiRecyclerView = activity.requireViewById(listId);
            assertTrue(carUiRecyclerView.getLayoutManager() instanceof GridLayoutManager);
            GridLayoutManager layoutManager =
                    (GridLayoutManager) carUiRecyclerView.getLayoutManager();
            assertEquals(
                    ((GridLayoutManager) carUiRecyclerView.getLayoutManager()).getOrientation(),
                    layoutManager.getOrientation());
            assertEquals(
                    ((GridLayoutManager) carUiRecyclerView.getLayoutManager()).getReverseLayout(),
                    layoutManager.getReverseLayout());
            assertEquals(((GridLayoutManager) carUiRecyclerView.getLayoutManager()).getSpanCount(),
                    layoutManager.getSpanCount());
            assertEquals(
                    ((GridLayoutManager) carUiRecyclerView.getLayoutManager()).getSpanSizeLookup()
                            .getSpanSize(0), layoutManager.getSpanSizeLookup().getSpanSize(0));
            assertEquals(
                    ((GridLayoutManager) carUiRecyclerView.getLayoutManager()).getSpanSizeLookup()
                            .getSpanSize(1), layoutManager.getSpanSizeLookup().getSpanSize(1));
            assertEquals(
                    ((GridLayoutManager) carUiRecyclerView.getLayoutManager()).getSpanSizeLookup()
                            .getSpanSize(2), layoutManager.getSpanSizeLookup().getSpanSize(2));
        });
    }

    @Test
    public void testCarUiGridLayoutStyle_fromLinearLayout_throwsException() {
        mActivityRule.getScenario().onActivity(activity -> {
            LinearLayoutManager layoutManager = new LinearLayoutManager(activity);
            AssertionError ex = assertThrows(AssertionError.class,
                    () -> CarUiGridLayoutStyle.from(layoutManager));
            assertEquals("GridLayoutManager required.", ex.getMessage());
        });
    }

    @Test
    public void testCarUiGridLayoutStyle_fromNull() {
        assertNull(CarUiGridLayoutStyle.from(null));
    }

    @Test
    public void testCarUiLinearLayoutStyle_LayoutManagerFrom() {
        if (mIsPluginEnabled) {
            return;
        }

        TestAdapter adapter = new TestAdapter(50);
        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            LinearLayoutManager layoutManager =
                    new LinearLayoutManager(activity, RecyclerView.VERTICAL, true);
            CarUiLinearLayoutStyle layoutStyle = CarUiLinearLayoutStyle.from(layoutManager);
            CarUiRecyclerViewImpl carUiRecyclerView =
                    (CarUiRecyclerViewImpl) CarUiRecyclerView.create(activity);
            carUiRecyclerView.setLayoutStyle(layoutStyle);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.addView(carUiRecyclerView.getView());
            carUiRecyclerView.setId(listId);
            carUiRecyclerView.setAdapter(adapter);
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerViewImpl carUiRecyclerView = activity.requireViewById(listId);
            LinearLayoutManager layoutManager =
                    (LinearLayoutManager) carUiRecyclerView.getLayoutManager();
            assertTrue(carUiRecyclerView.getLayoutManager() instanceof LinearLayoutManager);
            assertEquals(
                    ((LinearLayoutManager) carUiRecyclerView.getLayoutManager()).getOrientation(),
                    layoutManager.getOrientation());
            assertEquals(((LinearLayoutManager) carUiRecyclerView.getLayoutManager())
                    .getReverseLayout(), layoutManager.getReverseLayout());
        });
    }

    @Test
    public void testCarUiLinearLayoutStyle_fromGridLayout_throwsException() {
        mActivityRule.getScenario().onActivity(activity -> {
            NotLinearLayoutManager layoutManager = new NotLinearLayoutManager(activity);
            AssertionError ex = assertThrows(AssertionError.class,
                    () -> CarUiLinearLayoutStyle.from(layoutManager));
            assertEquals("LinearLayoutManager required.", ex.getMessage());
        });
    }

    @Test
    public void testCarUiLinearLayoutStyle_fromNull() {
        assertNull(CarUiGridLayoutStyle.from(null));
    }

    @Test
    public void testOnContinuousScrollListener_cancelCallback() {
        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);
            doReturn(0).when(testableResources)
                    .getInteger(R.integer.car_ui_scrollbar_longpress_initial_delay);
            View view = mock(View.class);
            OnClickListener clickListener = mock(OnClickListener.class);
            OnContinuousScrollListener listener = new OnContinuousScrollListener(
                    testableContext, clickListener);
            MotionEvent motionEvent = mock(MotionEvent.class);
            when(motionEvent.getAction()).thenReturn(MotionEvent.ACTION_DOWN);
            listener.onTouch(view, motionEvent);
            when(view.isEnabled()).thenReturn(false);
            when(motionEvent.getAction()).thenReturn(MotionEvent.ACTION_UP);
            listener.onTouch(view, motionEvent);
            verify(clickListener, times(1)).onClick(view);
        });
    }

    @Test
    public void testUxRestriction_withLimitedContent_setsMaxItems() {
        if (mIsPluginEnabled) {
            return;
        }

        TestAdapter.WithItemCap adapter = spy(new TestAdapter.WithItemCap(100));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUxRestrictionsUtil uxRestriction = CarUxRestrictionsUtil.getInstance(activity);
            CarUxRestrictions restriction = mock(CarUxRestrictions.class);
            when(restriction.getActiveRestrictions()).thenReturn(UX_RESTRICTIONS_LIMIT_CONTENT);
            when(restriction.getMaxCumulativeContentItems()).thenReturn(10);

            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(activity);
            ViewGroup container = activity.findViewById(R.id.test_container);
            uxRestriction.setUxRestrictions(restriction);
            carUiRecyclerView.setAdapter(adapter);
            container.addView(carUiRecyclerView.getView());

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));
        verify(adapter, atLeastOnce()).setMaxItems(10);
    }

    @Test
    public void testUxRestriction_withoutLimitedContent_setsUnlimitedMaxItems() {
        if (mIsPluginEnabled) {
            return;
        }

        TestAdapter.WithItemCap adapter = spy(new TestAdapter.WithItemCap(100));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUxRestrictionsUtil uxRestriction = CarUxRestrictionsUtil.getInstance(activity);
            CarUxRestrictions restriction = mock(CarUxRestrictions.class);
            when(restriction.getMaxCumulativeContentItems()).thenReturn(10);

            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(activity);
            ViewGroup container = activity.findViewById(R.id.test_container);
            container.post(() -> {
                uxRestriction.setUxRestrictions(restriction);
                carUiRecyclerView.setAdapter(adapter);
                container.addView(carUiRecyclerView.getView());
            });

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));
        verify(adapter, atLeastOnce()).setMaxItems(UNLIMITED);
    }

    @Test
    public void testPageUp_returnsWhen_verticalScrollOffsetIsZero() {
        if (mIsPluginEnabled) {
            return;
        }

        TestAdapter adapter = new TestAdapter(100);
        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);
            doReturn(TestScrollBar.class.getName()).when(testableResources)
                    .getString(R.string.car_ui_scrollbar_component);

            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(testableContext);
            ViewGroup container = activity.findViewById(R.id.test_container);
            carUiRecyclerView.setAdapter(adapter);
            carUiRecyclerView.setId(listId);
            container.addView(carUiRecyclerView.getView());

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        onView(withId(listId)).check(matches(isDisplayed()));
        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            // Scroll to a position so page up is enabled.
            carUiRecyclerView.scrollToPosition(20);
        });

        onView(withId(getId("car_ui_scrollbar_page_up"))).check(matches(isEnabled()));

        mActivityRule.getScenario().onActivity(activity -> {
            View v = activity.findViewById(getId("car_ui_scroll_bar"));
            TestScrollBar sb = (TestScrollBar) v.getTag();
            // We set this to simulate a case where layout manager is null
            sb.mReturnZeroVerticalScrollOffset = true;
        });

        onView(withId(getId("car_ui_scrollbar_page_up"))).perform(click());

        mActivityRule.getScenario().onActivity(activity -> {
            View v = activity.findViewById(getId("car_ui_scroll_bar"));
            TestScrollBar sb = (TestScrollBar) v.getTag();
            assertFalse(sb.mScrollWasCalled);
        });
    }

    @Test
    public void testPageUp_returnsWhen_layoutManagerIsNull() {
        if (mIsPluginEnabled) {
            return;
        }

        TestAdapter adapter = new TestAdapter(100);
        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);
            doReturn(TestScrollBar.class.getName()).when(testableResources)
                    .getString(R.string.car_ui_scrollbar_component);

            CarUiRecyclerView carUiRecyclerView = CarUiRecyclerView.create(testableContext);
            ViewGroup container = activity.findViewById(R.id.test_container);
            carUiRecyclerView.setAdapter(adapter);
            carUiRecyclerView.setId(listId);
            container.addView(carUiRecyclerView.getView());

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            // Scroll to a position so page up is enabled.
            carUiRecyclerView.scrollToPosition(20);
        });

        onView(withId(getId("car_ui_scrollbar_page_up"))).check(matches(isEnabled()));

        mActivityRule.getScenario().onActivity(activity -> {
            View v = activity.findViewById(getId("car_ui_scroll_bar"));
            TestScrollBar sb = (TestScrollBar) v.getTag();
            // We set this to simulate a case where layout manager is null
            sb.mReturnMockLayoutManager = true;
        });

        onView(withId(getId("car_ui_scrollbar_page_up"))).perform(click());

        mActivityRule.getScenario().onActivity(activity -> {
            View v = activity.findViewById(getId("car_ui_scroll_bar"));
            TestScrollBar sb = (TestScrollBar) v.getTag();
            assertFalse(sb.mScrollWasCalled);
        });
    }

    @Test
    public void testPageDown_returnsWhen_layoutManagerIsNullOrEmpty() {
        if (mIsPluginEnabled) {
            return;
        }

        TestAdapter adapter = new TestAdapter(100);
        int listId = View.generateViewId();

        mActivityRule.getScenario().onActivity(activity -> {
            Context testableContext = spy(activity);
            Resources testableResources = spy(activity.getResources());
            when(testableContext.getResources()).thenReturn(testableResources);
            doReturn(TestScrollBar.class.getName()).when(testableResources)
                    .getString(R.string.car_ui_scrollbar_component);

            CarUiRecyclerViewImpl carUiRecyclerView =
                    (CarUiRecyclerViewImpl) CarUiRecyclerView.create(testableContext);
            ViewGroup container = activity.findViewById(R.id.test_container);
            carUiRecyclerView.setAdapter(adapter);
            carUiRecyclerView.setId(listId);
            container.addView(carUiRecyclerView.getView());

            IdlingRegistry.getInstance().register(new ScrollIdlingResource(carUiRecyclerView));
        });

        onView(withText(adapter.getItemText(0))).check(matches(isDisplayed()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerView carUiRecyclerView = activity.requireViewById(listId);
            // Scroll to a position so page up is enabled.
            carUiRecyclerView.scrollToPosition(20);
        });

        onView(withId(getId("car_ui_scrollbar_page_down"))).check(matches(isEnabled()));

        mActivityRule.getScenario().onActivity(activity -> {
            CarUiRecyclerViewImpl carUiRecyclerView = activity.requireViewById(listId);
            View v = activity.findViewById(getId("car_ui_scroll_bar"));
            TestScrollBar sb = (TestScrollBar) v.getTag();
            // We set this to simulate a case where layout manager is empty
            sb.mReturnMockLayoutManager = true;
            sb.mMockLayoutManager = spy(carUiRecyclerView.getLayoutManager());
            when(sb.mMockLayoutManager.getChildCount()).thenReturn(0);
        });

        onView(withId(getId("car_ui_scrollbar_page_down"))).perform(click());

        mActivityRule.getScenario().onActivity(activity -> {
            View v = activity.findViewById(getId("car_ui_scroll_bar"));
            TestScrollBar sb = (TestScrollBar) v.getTag();
            assertFalse(sb.mScrollWasCalled);

            // We set this to simulate a case where layout manager is null
            sb.mReturnMockLayoutManager = true;
            sb.mMockLayoutManager = null;
        });

        onView(withId(getId("car_ui_scrollbar_page_down"))).perform(click());

        mActivityRule.getScenario().onActivity(activity -> {
            View v = activity.findViewById(getId("car_ui_scroll_bar"));
            TestScrollBar sb = (TestScrollBar) v.getTag();
            assertFalse(sb.mScrollWasCalled);
        });
    }

    static class TestScrollBar extends DefaultScrollBar {
        boolean mReturnMockLayoutManager = false;
        LayoutManager mMockLayoutManager = null;
        boolean mScrollWasCalled = false;
        boolean mReturnZeroVerticalScrollOffset = false;

        @Override
        public void initialize(Context context, RecyclerView rv, View scrollView) {
            super.initialize(context, rv, scrollView);

            scrollView.setTag(this);
        }

        @Override
        public LayoutManager getLayoutManager() {
            return mReturnMockLayoutManager ? mMockLayoutManager : super.getLayoutManager();
        }

        @Override
        void smoothScrollBy(int dx, int dy) {
            mScrollWasCalled = true;
        }

        @Override
        void smoothScrollToPosition(int max) {
            mScrollWasCalled = true;
        }

        @Override
        int computeVerticalScrollOffset() {
            return mReturnZeroVerticalScrollOffset ? 0 : super.computeVerticalScrollOffset();
        }
    }

    private static float dpToPixel(Context context, int dp) {
        return TypedValue.applyDimension(
                TypedValue.COMPLEX_UNIT_DIP,
                dp,
                context.getResources().getDisplayMetrics());
    }

    /**
     * Returns an item in the current list view whose height is taller than that of the
     * CarUiRecyclerView. If that item exists, then it is returned; otherwise an {@link
     * IllegalStateException} is thrown.
     *
     * @return An item that is taller than the CarUiRecyclerView.
     */
    private View getLongItem(CarUiRecyclerView recyclerView) {
        for (int i = 0; i < recyclerView.getRecyclerViewChildCount(); i++) {
            View item = recyclerView.getRecyclerViewChildAt(i);

            if (item.getHeight() > recyclerView.getTotalSpace()) {
                return item;
            }
        }

        throw new IllegalStateException(
                "No item found that is longer than the height of the CarUiRecyclerView.");
    }

    /**
     * A test adapter that handles inflating test views and binding data to it.
     */
    private static class TestAdapter extends RecyclerView.Adapter<TestViewHolder> {

        public enum ItemHeight {
            STANDARD,
            TALL,
            EXTRA_TALL,
            ZERO
        }

        protected final List<String> mData;
        private final Map<Integer, ItemHeight> mHeightOverrides;

        TestAdapter(int itemCount, Map<Integer, ItemHeight> overrides) {
            mHeightOverrides = overrides;
            mData = new ArrayList<>(itemCount);

            for (int i = 0; i < itemCount; i++) {
                mData.add(getItemText(i));
            }
        }

        TestAdapter(int itemCount) {
            this(itemCount, new HashMap<>());
        }

        String getItemText(int position) {
            if (position > mData.size()) {
                return null;
            }

            return String.format(Locale.US, "Sample item #%d", position);
        }

        @NonNull
        @Override
        public TestViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
            LayoutInflater inflater = LayoutInflater.from(parent.getContext());
            return new TestViewHolder(inflater, parent);
        }

        @Override
        public void onBindViewHolder(@NonNull TestViewHolder holder, int position) {
            ItemHeight height = ItemHeight.STANDARD;

            if (mHeightOverrides.containsKey(position)) {
                height = mHeightOverrides.get(position);
            }

            int screenHeight = Resources.getSystem().getDisplayMetrics().heightPixels;

            switch (height) {
                case ZERO:
                    ViewGroup.LayoutParams lp = holder.itemView.getLayoutParams();
                    holder.itemView.setContentDescription("ZERO");
                    lp.height = 0;
                    holder.itemView.setLayoutParams(lp);
                    break;
                case STANDARD:
                    break;
                case TALL:
                    holder.itemView.setMinimumHeight((int) (screenHeight * 1.1));
                    break;
                case EXTRA_TALL:
                    holder.itemView.setMinimumHeight((int) (screenHeight * 2.1));
                    break;
                default:
                    throw new IllegalStateException("Unexpected value: " + height);
            }

            holder.bind(mData.get(position));
        }

        @Override
        public int getItemCount() {
            return mData.size();
        }

        static class WithItemCap extends TestAdapter implements CarUiRecyclerView.ItemCap {
            private int mMaxItems = -1;

            WithItemCap(int itemCount,
                    Map<Integer, ItemHeight> overrides) {
                super(itemCount, overrides);
            }

            WithItemCap(int itemCount) {
                super(itemCount);
            }

            @Override
            public void setMaxItems(int maxItems) {
                mMaxItems = maxItems;
            }

            @Override
            public int getItemCount() {
                return mMaxItems >= 0 ? mMaxItems : mData.size();
            }
        }
    }

    private static class PerfectFitTestAdapter extends RecyclerView.Adapter<TestViewHolder> {
        private static final int MIN_HEIGHT = 30;
        private final List<String> mData;
        private final int mItemHeight;

        private int getMinHeightPerItemToFitScreen(int screenHeight) {
            // When the height is a prime number, there can only be 1 item per page
            int minHeight = screenHeight;
            for (int i = screenHeight; i >= 1; i--) {
                if (screenHeight % i == 0 && screenHeight / i >= MIN_HEIGHT) {
                    minHeight = screenHeight / i;
                    break;
                }
            }
            return minHeight;
        }

        PerfectFitTestAdapter(int numOfPages, int recyclerViewHeight) {
            mItemHeight = getMinHeightPerItemToFitScreen(recyclerViewHeight);
            int itemsPerPage = recyclerViewHeight / mItemHeight;
            int itemCount = itemsPerPage * numOfPages;
            mData = new ArrayList<>(itemCount);
            for (int i = 0; i < itemCount; i++) {
                mData.add(getItemText(i));
            }
        }

        public static String getItemText(int position) {
            return String.format(Locale.US, "Sample item #%d", position);
        }

        @NonNull
        @Override
        public TestViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
            LayoutInflater inflater = LayoutInflater.from(parent.getContext());
            return new TestViewHolder(inflater, parent);
        }

        @Override
        public void onBindViewHolder(@NonNull TestViewHolder holder, int position) {
            holder.itemView.getLayoutParams().height = mItemHeight;
            holder.bind(mData.get(position));
        }

        @Override
        public int getItemCount() {
            return mData.size();
        }
    }

    private static class TestViewHolder extends RecyclerView.ViewHolder {
        private final TextView mTextView;

        TestViewHolder(LayoutInflater inflater, ViewGroup parent) {
            super(inflater.inflate(R.layout.test_list_item, parent, false));
            mTextView = itemView.findViewById(R.id.text);
        }

        void bind(String text) {
            mTextView.setText(text);
        }
    }

    /**
     * An {@link IdlingResource} that will prevent assertions from running while the {@link
     * CarUiRecyclerView} is scrolling.
     */
    private static class ScrollIdlingResource implements IdlingResource {
        private boolean mIdle = true;
        private ResourceCallback mResourceCallback;

        ScrollIdlingResource(CarUiRecyclerView recyclerView) {
            recyclerView
                    .addOnScrollListener(
                            new CarUiRecyclerView.OnScrollListener() {
                                @Override
                                public void onScrollStateChanged(
                                        @NonNull CarUiRecyclerView recyclerView,
                                        int newState) {
                                    mIdle = (newState == SCROLL_STATE_IDLE
                                            // Treat dragging as idle, or Espresso will
                                            // block itself when swiping.
                                            || newState == SCROLL_STATE_DRAGGING);
                                    if (mIdle && mResourceCallback != null) {
                                        mResourceCallback.onTransitionToIdle();
                                    }
                                }

                                @Override
                                public void onScrolled(@NonNull CarUiRecyclerView recyclerView,
                                        int dx,
                                        int dy) {
                                }
                            });
        }

        @Override
        public String getName() {
            return ScrollIdlingResource.class.getName();
        }

        @Override
        public boolean isIdleNow() {
            return mIdle;
        }

        @Override
        public void registerIdleTransitionCallback(ResourceCallback callback) {
            mResourceCallback = callback;
        }
    }

    private static class NotLinearLayoutManager extends LayoutManager {
        NotLinearLayoutManager(Context mTestableContext) {
        }

        @Override
        public LayoutParams generateDefaultLayoutParams() {
            return null;
        }
    }

    private int getId(String resourceName) {
        if (mIsPluginEnabled) {
            Context pluginContext = PluginFactorySingleton.getPluginContext();
            return pluginContext.getResources().getIdentifier(
                    resourceName.replace("car_ui_", ""), "id", pluginContext.getPackageName());
        } else {
            Context context = getInstrumentation().getTargetContext();
            return context.getResources()
                    .getIdentifier(resourceName, "id", context.getPackageName());
        }
    }
}
