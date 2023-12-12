/*
 * Copyright (C) 2020 Google Inc.
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

package com.android.car.carlauncher.homescreen.audio;

import static androidx.test.espresso.Espresso.onView;
import static androidx.test.espresso.assertion.ViewAssertions.matches;
import static androidx.test.espresso.matcher.ViewMatchers.isDescendantOfA;
import static androidx.test.espresso.matcher.ViewMatchers.isDisplayed;
import static androidx.test.espresso.matcher.ViewMatchers.withId;
import static androidx.test.espresso.matcher.ViewMatchers.withText;

import static org.hamcrest.CoreMatchers.allOf;
import static org.hamcrest.CoreMatchers.instanceOf;
import static org.hamcrest.CoreMatchers.is;
import static org.hamcrest.CoreMatchers.not;

import android.graphics.Bitmap;
import android.graphics.drawable.BitmapDrawable;

import androidx.test.ext.junit.runners.AndroidJUnit4;
import androidx.test.rule.ActivityTestRule;

import com.android.car.apps.common.CrossfadeImageView;
import com.android.car.carlauncher.CarLauncher;
import com.android.car.carlauncher.R;
import com.android.car.carlauncher.homescreen.ui.CardHeader;
import com.android.car.carlauncher.homescreen.ui.DescriptiveTextView;
import com.android.car.carlauncher.homescreen.ui.DescriptiveTextWithControlsView;
import com.android.car.carlauncher.homescreen.ui.TextBlockView;

import org.junit.Rule;
import org.junit.Test;
import org.junit.runner.RunWith;

@RunWith(AndroidJUnit4.class)
public class AudioFragmentTest {

    private static final CardHeader CARD_HEADER = new CardHeader("Test App Name", null);
    private static final BitmapDrawable BITMAP = new BitmapDrawable(
            Bitmap.createBitmap(/* width = */100, /* height = */100, Bitmap.Config.ARGB_8888));
    private static final String AUDIO_VIEW_TITLE = "Test song title";
    private static final String AUDIO_VIEW_SUBTITLE = "Test artist name";
    private static final long AUDIO_START_TIME = 1L;
    private static final DescriptiveTextView DESCRIPTIVE_TEXT_VIEW = new DescriptiveTextView(
            /* image = */ null, "Primary Text", "Secondary Text");
    private static final TextBlockView TEXT_BLOCK_VIEW = new TextBlockView("Text");

    private final DescriptiveTextWithControlsView
            mDescriptiveTextWithControlsView = new DescriptiveTextWithControlsView(BITMAP,
            AUDIO_VIEW_TITLE,
            AUDIO_VIEW_SUBTITLE);
    private final DescriptiveTextWithControlsView.Control mControl =
            new DescriptiveTextWithControlsView.Control(BITMAP, v -> {
            });
    private final DescriptiveTextWithControlsView
            mDescriptiveTextWithControlsViewWithButtons = new DescriptiveTextWithControlsView(
            BITMAP, AUDIO_VIEW_TITLE, AUDIO_VIEW_SUBTITLE, AUDIO_START_TIME, mControl,
            mControl, mControl);

    @Rule
    public ActivityTestRule<CarLauncher> mActivityTestRule =
            new ActivityTestRule<CarLauncher>(CarLauncher.class);

    @Test
    public void updateContentAndHeaderView_audioContentNoControls_showsMediaPlaybackControlsBar() {
        AudioFragment fragment = (AudioFragment) mActivityTestRule.getActivity()
                .getSupportFragmentManager().findFragmentById(R.id.bottom_card);
        mActivityTestRule.getActivity().runOnUiThread(fragment::hideCard);
        fragment.updateContentView(mDescriptiveTextWithControlsView);
        // Card is only made visible when the header is updated
        // But content should still be updated so it is correct when card is next made visible
        onView(allOf(withId(R.id.card_view), isDescendantOfA(withId(R.id.bottom_card))))
                .check(matches(not(isDisplayed())));

        // Now the card is made visible and we verify that content has been updated
        fragment.updateHeaderView(CARD_HEADER);
        onView(allOf(withId(R.id.card_background),
                isDescendantOfA(withId(R.id.bottom_card)))).check(matches(isDisplayed()));
        onView(allOf(withId(R.id.card_background_image), is(instanceOf(CrossfadeImageView.class)),
                isDescendantOfA(withId(R.id.bottom_card)))).check(matches(isDisplayed()));
        onView(allOf(withId(R.id.media_layout),
                isDescendantOfA(withId(R.id.bottom_card)))).check(matches(isDisplayed()));
        onView(allOf(withId(R.id.primary_text), withText(AUDIO_VIEW_TITLE),
                isDescendantOfA(withId(R.id.media_layout)),
                isDescendantOfA(withId(R.id.bottom_card)))).check(matches(isDisplayed()));
        onView(allOf(withId(R.id.secondary_text), withText(AUDIO_VIEW_SUBTITLE),
                isDescendantOfA(withId(R.id.media_layout)),
                isDescendantOfA(withId(R.id.bottom_card)))).check(matches(isDisplayed()));
        onView(allOf(withId(R.id.optional_timer), isDescendantOfA(withId(R.id.bottom_card)),
                isDescendantOfA(withId(R.id.media_layout)))).check(
                matches(not(isDisplayed())));
        onView(allOf(withId(R.id.media_playback_controls_bar),
                isDescendantOfA(withId(R.id.media_layout)),
                isDescendantOfA(withId(R.id.bottom_card)))).check(matches(isDisplayed()));
        onView(allOf(withId(R.id.descriptive_text_with_controls_layout),
                isDescendantOfA(withId(R.id.bottom_card)))).check(matches(not(isDisplayed())));
    }

    @Test
    public void updateContentAndHeaderView_audioContentWithControls_showsControlBar() {
        AudioFragment fragment = (AudioFragment) mActivityTestRule.getActivity()
                .getSupportFragmentManager().findFragmentById(R.id.bottom_card);
        mActivityTestRule.getActivity().runOnUiThread(fragment::hideCard);
        fragment.updateHeaderView(CARD_HEADER);
        fragment.updateContentView(mDescriptiveTextWithControlsViewWithButtons);

        onView(allOf(withId(R.id.optional_timer),
                isDescendantOfA(withId(R.id.descriptive_text_with_controls_layout)),
                isDescendantOfA(withId(R.id.bottom_card)))).check(matches(isDisplayed()));
        onView(allOf(withId(R.id.button_left),
                isDescendantOfA(withId(R.id.descriptive_text_with_controls_layout)),
                isDescendantOfA(withId(R.id.bottom_card)))).check(matches(isDisplayed()));
        onView(allOf(withId(R.id.button_center),
                isDescendantOfA(withId(R.id.descriptive_text_with_controls_layout)),
                isDescendantOfA(withId(R.id.bottom_card)))).check(matches(isDisplayed()));
        onView(allOf(withId(R.id.button_right),
                isDescendantOfA(withId(R.id.descriptive_text_with_controls_layout)),
                isDescendantOfA(withId(R.id.bottom_card)))).check(matches(isDisplayed()));
        onView(allOf(withId(R.id.media_playback_controls_bar),
                isDescendantOfA(withId(R.id.media_layout)),
                isDescendantOfA(withId(R.id.bottom_card)))).check(matches(not(isDisplayed())));
        onView(allOf(withId(R.id.media_layout), isDescendantOfA(withId(R.id.bottom_card)))).check(
                matches(not(isDisplayed())));
    }

    @Test
    public void updateContentView_descriptiveText_hidesPlaybackControlsBar() {
        AudioFragment fragment = (AudioFragment) mActivityTestRule.getActivity()
                .getSupportFragmentManager().findFragmentById(R.id.bottom_card);
        fragment.updateContentView(mDescriptiveTextWithControlsView);
        fragment.updateContentView(DESCRIPTIVE_TEXT_VIEW);

        onView(allOf(withId(R.id.card_background),
                isDescendantOfA(withId(R.id.bottom_card)))).check(matches(not(isDisplayed())));
        onView(allOf(withId(R.id.card_background_image), is(instanceOf(CrossfadeImageView.class)),
                isDescendantOfA(withId(R.id.bottom_card)))).check(matches(not(isDisplayed())));
        onView(allOf(withId(R.id.descriptive_text_layout),
                isDescendantOfA(withId(R.id.bottom_card)))).check(matches(isDisplayed()));
        onView(allOf(withId(R.id.descriptive_text_with_controls_layout),
                isDescendantOfA(withId(R.id.bottom_card)))).check(matches(not(isDisplayed())));
        onView(allOf(withId(R.id.media_layout), isDescendantOfA(withId(R.id.bottom_card)))).check(
                matches(not(isDisplayed())));
    }

    @Test
    public void updateContentView_textBlock_hidesPlaybackControlsBar() {
        AudioFragment fragment = (AudioFragment) mActivityTestRule.getActivity()
                .getSupportFragmentManager().findFragmentById(R.id.bottom_card);
        fragment.updateContentView(mDescriptiveTextWithControlsView);
        fragment.updateContentView(TEXT_BLOCK_VIEW);

        onView(allOf(withId(R.id.card_background),
                isDescendantOfA(withId(R.id.bottom_card)))).check(matches(not(isDisplayed())));
        onView(allOf(withId(R.id.card_background_image), is(instanceOf(CrossfadeImageView.class)),
                isDescendantOfA(withId(R.id.bottom_card)))).check(matches(not(isDisplayed())));
        onView(allOf(withId(R.id.text_block_layout),
                isDescendantOfA(withId(R.id.bottom_card)))).check(matches(isDisplayed()));
        onView(allOf(withId(R.id.descriptive_text_with_controls_layout),
                isDescendantOfA(withId(R.id.bottom_card)))).check(matches(not(isDisplayed())));
        onView(allOf(withId(R.id.media_layout), isDescendantOfA(withId(R.id.bottom_card)))).check(
                matches(not(isDisplayed())));
    }
}
