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

package com.android.car.ui;

import static androidx.test.espresso.Espresso.onView;
import static androidx.test.espresso.assertion.ViewAssertions.doesNotExist;
import static androidx.test.espresso.assertion.ViewAssertions.matches;
import static androidx.test.espresso.matcher.ViewMatchers.isDisplayed;
import static androidx.test.espresso.matcher.ViewMatchers.withText;

import static com.android.car.ui.core.CarUi.MIN_TARGET_API;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

import android.annotation.TargetApi;
import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.Context;
import android.database.Cursor;
import android.view.View;

import androidx.test.espresso.Root;
import androidx.test.ext.junit.rules.ActivityScenarioRule;

import com.android.car.ui.recyclerview.CarUiContentListItem;
import com.android.car.ui.recyclerview.CarUiListItemAdapter;
import com.android.car.ui.recyclerview.CarUiRadioButtonListItem;
import com.android.car.ui.recyclerview.CarUiRadioButtonListItemAdapter;
import com.android.car.ui.test.R;

import org.hamcrest.Description;
import org.hamcrest.TypeSafeMatcher;
import org.junit.Rule;
import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.function.Function;

@TargetApi(MIN_TARGET_API)
public class AlertDialogBuilderTest {

    @Rule
    public ActivityScenarioRule<TestActivity> mActivityRule =
            new ActivityScenarioRule<>(TestActivity.class);

    @Test
    public void test_AlertDialogBuilder_works() {
        String title = "Test message from AlertDialogBuilder";
        String subtitle = "Subtitle from AlertDialogBuilder";
        runOnUiThread(activity ->
                new AlertDialogBuilder(activity)
                        .setMessage(title)
                        .setSubtitle(subtitle)
                        .show());

        AlertDialog dialog = checkDefaultButtonExists(true,
                runOnUiThread(activity -> new AlertDialogBuilder(activity)
                        .setMessage(title)
                        .setSubtitle(subtitle)));
        onView(withText(title))
                .inRoot(RootWithDecorMatcher.get(dialog))
                .check(matches(isDisplayed()));
        onView(withText(subtitle))
                .inRoot(RootWithDecorMatcher.get(dialog))
                .check(matches(isDisplayed()));
    }

    @Test
    public void test_simplePropertiesWithResources_work() {
        AlertDialog dialog = runOnUiThread(activity ->
                new AlertDialogBuilder(activity)
                        .setTitle(R.string.title)
                        .setSubtitle(R.string.subtitle)
                        .setIcon(R.drawable.ic_launcher)
                        .setMessage(R.string.message)
                        .setPositiveButton(R.string.positive, (d, which) -> {})
                        .setNegativeButton(R.string.negative, (d, which) -> {})
                        .setNeutralButton(R.string.neutral, (d, which) -> {})
                        .show());
        assertNotNull(dialog);
        onView(withText(R.string.title))
                .inRoot(RootWithDecorMatcher.get(dialog))
                .check(matches(isDisplayed()));
        onView(withText(R.string.subtitle))
                .inRoot(RootWithDecorMatcher.get(dialog))
                .check(matches(isDisplayed()));
        onView(withText(R.string.message))
                .inRoot(RootWithDecorMatcher.get(dialog))
                .check(matches(isDisplayed()));
        onView(withText(R.string.positive))
                .inRoot(RootWithDecorMatcher.get(dialog))
                .check(matches(isDisplayed()));
        onView(withText(R.string.negative))
                .inRoot(RootWithDecorMatcher.get(dialog))
                .check(matches(isDisplayed()));
        onView(withText(R.string.neutral))
                .inRoot(RootWithDecorMatcher.get(dialog))
                .check(matches(isDisplayed()));
    }

    @Test
    public void test_simplePropertiesWithStrings_work() {
        AlertDialog dialog = runOnUiThread(activity ->
                new AlertDialogBuilder(activity)
                        .setTitle("Title!!")
                        .setSubtitle("Subtitle!!")
                        .setIcon(activity.getDrawable(R.drawable.ic_launcher))
                        .setMessage("Message!!")
                        .setPositiveButton("Positive!!", (d, which) -> {})
                        .setNegativeButton("Negative!!", (d, which) -> {})
                        .setNeutralButton("Neutral!!", (d, which) -> {})
                        .show());
        assertNotNull(dialog);
        onView(withText("Title!!"))
                .inRoot(RootWithDecorMatcher.get(dialog))
                .check(matches(isDisplayed()));
        onView(withText("Subtitle!!"))
                .inRoot(RootWithDecorMatcher.get(dialog))
                .check(matches(isDisplayed()));
        onView(withText("Message!!"))
                .inRoot(RootWithDecorMatcher.get(dialog))
                .check(matches(isDisplayed()));
        onView(withText("Positive!!"))
                .inRoot(RootWithDecorMatcher.get(dialog))
                .check(matches(isDisplayed()));
        onView(withText("Negative!!"))
                .inRoot(RootWithDecorMatcher.get(dialog))
                .check(matches(isDisplayed()));
        onView(withText("Neutral!!"))
                .inRoot(RootWithDecorMatcher.get(dialog))
                .check(matches(isDisplayed()));
    }

    @Test
    public void test_setCursor_works() {
        FakeCursor cursor = new FakeCursor(Arrays.asList("Item 1", "Item 2"), "items");
        AlertDialog dialog = runOnUiThread(activity ->
                new AlertDialogBuilder(activity)
                        .setCursor(cursor, (d, which) -> {}, "items")
                        .show());
        assertNotNull(dialog);
        onView(withText("Item 1"))
                .inRoot(RootWithDecorMatcher.get(dialog))
                .check(matches(isDisplayed()));
        onView(withText("Item 2"))
                .inRoot(RootWithDecorMatcher.get(dialog))
                .check(matches(isDisplayed()));
    }

    @Test
    public void test_getContext_works() {
        Context context = runOnUiThread(activity ->
                new AlertDialogBuilder(activity).getContext());
        assertNotNull(context);
    }

    @Test
    public void test_setCarUiRadioButtons_works() {
        CarUiRadioButtonListItem item1 = new CarUiRadioButtonListItem();
        item1.setTitle("Item 1");
        CarUiRadioButtonListItem item2 = new CarUiRadioButtonListItem();
        item2.setTitle("Item 2");

        AlertDialog dialog = runOnUiThread(activity ->
                new AlertDialogBuilder(activity)
                        .setSingleChoiceItems(
                                new CarUiRadioButtonListItemAdapter(Arrays.asList(item1, item2)))
                        .show());
        assertNotNull(dialog);
        onView(withText("Item 1"))
                .inRoot(RootWithDecorMatcher.get(dialog))
                .check(matches(isDisplayed()));
        onView(withText("Item 2"))
                .inRoot(RootWithDecorMatcher.get(dialog))
                .check(matches(isDisplayed()));
    }

    @Test
    public void test_showSingleListChoiceItem_StringArray_hidesDefaultButton() {
        AlertDialogBuilder builder = runOnUiThread(activity -> new AlertDialogBuilder(activity)
                .setAllowDismissButton(false)
                .setSingleChoiceItems(new CharSequence[]{"Item 1", "Item 2"}, 0,
                        (dialog, which) -> {}));

        checkDefaultButtonExists(false, builder);
    }

    @Test
    public void test_showSingleListChoiceItem_StringArrayResource_hidesDefaultButton() {
        AlertDialogBuilder builder = runOnUiThread(activity -> new AlertDialogBuilder(activity)
                .setAllowDismissButton(false)
                .setSingleChoiceItems(R.array.test_string_array, 0, (dialog, which) -> {}));

        checkDefaultButtonExists(false, builder);
    }

    @Test
    public void test_singleListChoiceItems_CarUiRadioButtonListItemAdapter_forcesDefaultButton() {
        CarUiRadioButtonListItem item1 = new CarUiRadioButtonListItem();
        item1.setTitle("Item 1");
        CarUiRadioButtonListItem item2 = new CarUiRadioButtonListItem();
        item2.setTitle("Item 2");
        CarUiRadioButtonListItem item3 = new CarUiRadioButtonListItem();
        item3.setTitle("Item 3");

        CarUiRadioButtonListItemAdapter adapter = new CarUiRadioButtonListItemAdapter(
                Arrays.asList(item1, item2, item3));
        AlertDialogBuilder builder = runOnUiThread(activity -> new AlertDialogBuilder(activity)
                .setAllowDismissButton(false)
                .setSingleChoiceItems(adapter));

        checkDefaultButtonExists(true, builder);
    }

    @Test
    public void test_showSingleListChoiceItem_cursor_hidesDefaultButton() {
        Cursor cursor = new FakeCursor(Arrays.asList("Item 1", "Item 2"), "ColumnName");
        AlertDialogBuilder builder = runOnUiThread(activity -> new AlertDialogBuilder(activity)
                .setTitle("Title")
                .setAllowDismissButton(false)
                .setSingleChoiceItems(cursor, 0, "ColumnName", (dialog, which) -> {}));

        checkDefaultButtonExists(false, builder);
    }

    @Test
    public void test_setItems_StringArrayResource_hidesDefaultButton() {
        AlertDialogBuilder builder = runOnUiThread(activity -> new AlertDialogBuilder(activity)
                .setAllowDismissButton(false)
                .setItems(R.array.test_string_array, (dialog, which) -> {}));

        checkDefaultButtonExists(false, builder);
    }

    @Test
    public void test_setItems_StringArray_hidesDefaultButton() {
        AlertDialogBuilder builder = runOnUiThread(activity -> new AlertDialogBuilder(activity)
                .setAllowDismissButton(false)
                .setItems(new CharSequence[]{"Item 1", "Item 2"}, (dialog, which) -> {}));

        checkDefaultButtonExists(false, builder);
    }

    @Test
    public void test_setAdapter_hidesDefaultButton() {
        CarUiContentListItem item1 = new CarUiContentListItem(CarUiContentListItem.Action.NONE);
        item1.setTitle("Item 1");
        CarUiContentListItem item2 = new CarUiContentListItem(CarUiContentListItem.Action.NONE);
        item2.setTitle("Item 2");
        CarUiContentListItem item3 = new CarUiContentListItem(CarUiContentListItem.Action.NONE);
        item3.setTitle("Item 3");

        CarUiListItemAdapter adapter = new CarUiListItemAdapter(
                Arrays.asList(item1, item2, item3));
        AlertDialogBuilder builder = runOnUiThread(activity -> new AlertDialogBuilder(activity)
                .setAllowDismissButton(false)
                .setAdapter(adapter));

        checkDefaultButtonExists(false, builder);
    }

    @Test
    public void test_multichoiceItems_StringArrayResource_forcesDefaultButton() {
        AlertDialogBuilder builder = runOnUiThread(activity -> new AlertDialogBuilder(activity)
                .setAllowDismissButton(false)
                .setMultiChoiceItems(R.array.test_string_array, null,
                        (dialog, which, isChecked) -> {}));

        checkDefaultButtonExists(true, builder);
    }

    @Test
    public void test_multichoiceItems_StringArray_forcesDefaultButton() {
        AlertDialogBuilder builder = runOnUiThread(activity -> new AlertDialogBuilder(activity)
                .setAllowDismissButton(false)
                .setMultiChoiceItems(new CharSequence[]{"Test 1", "Test 2"}, null,
                        (dialog, which, isChecked) -> {}));

        checkDefaultButtonExists(true, builder);
    }

    @Test
    public void test_multichoiceItems_Cursor_forcesDefaultButton() {
        Cursor cursor = new FakeCursor(Arrays.asList("Item 1", "Item 2"), "Label");
        AlertDialogBuilder builder = runOnUiThread(activity -> new AlertDialogBuilder(activity)
                .setAllowDismissButton(false)
                .setMultiChoiceItems(cursor, "isChecked", "Label",
                        (dialog, which, isChecked) -> {}));

        checkDefaultButtonExists(true, builder);
    }

    private AlertDialog checkDefaultButtonExists(boolean shouldExist, AlertDialogBuilder builder) {
        AtomicBoolean didThrowException = new AtomicBoolean(false);
        AlertDialog[] result = new AlertDialog[1];
        RuntimeException[] exception = new RuntimeException[1];
        mActivityRule.getScenario().onActivity(activity -> {
            try {
                result[0] = builder.create();
                result[0].show();
            } catch (RuntimeException e) {
                exception[0] = e;
                didThrowException.set(true);
            }
        });

        if (didThrowException.get()) {
            assertNotNull(exception[0]);
            assertEquals("The dialog must have at least one button to disable the dismiss button",
                    exception[0].getMessage());
            assertTrue(shouldExist);
            return result[0];
        }

        if (shouldExist) {
            onView(withText(R.string.car_ui_alert_dialog_default_button))
                    .inRoot(RootWithDecorMatcher.get(result[0]))
                    .check(matches(isDisplayed()));
        } else {
            onView(withText(R.string.car_ui_alert_dialog_default_button))
                    .inRoot(RootWithDecorMatcher.get(result[0]))
                    .check(doesNotExist());
        }

        return result[0];
    }

    private <T> T runOnUiThread(Function<Activity, T> block) {
        ArrayList<T> result = new ArrayList<>();
        mActivityRule.getScenario().onActivity(activity -> result.add(block.apply(activity)));

        if (result.isEmpty()) {
            return null;
        } else {
            return result.get(0);
        }
    }

    private static class RootWithDecorMatcher extends TypeSafeMatcher<Root> {

        private final View mView;

        static RootWithDecorMatcher get(Dialog dialog) {
            return new RootWithDecorMatcher(dialog.getWindow().getDecorView());
        }

        RootWithDecorMatcher(View view) {
            mView = view;
        }

        @Override
        public void describeTo(Description description) {
            description.appendText("is a root with a certain decor");
        }

        @Override
        protected boolean matchesSafely(Root item) {
            return item.getDecorView() == mView;
        }
    }
}
