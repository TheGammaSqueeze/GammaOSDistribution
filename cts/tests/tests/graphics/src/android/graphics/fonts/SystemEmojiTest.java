/*
 * Copyright (C) 2021 The Android Open Source Project
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

package android.graphics.fonts;

import static com.google.common.truth.Truth.assertThat;

import android.test.suitebuilder.annotation.SmallTest;

import androidx.test.runner.AndroidJUnit4;

import org.junit.Test;
import org.junit.runner.RunWith;

import java.io.File;
import java.io.IOException;

@SmallTest
@RunWith(AndroidJUnit4.class)
public class SystemEmojiTest {
    @Test
    public void uniquePostScript() throws IOException {
        File emojiFont = null;
        for (Font font : SystemFonts.getAvailableFonts()) {
            if (font.getFile().getName().equals("NotoColorEmoji.ttf")) {
                emojiFont = font.getFile();
            }
        }

        // NotoColorEmoji.ttf should be always available as a fallback font even if another emoji
        // font files are installed in the system.
        assertThat(emojiFont).isNotNull();

        assertThat(FontFileTestUtil.containsEmojiCompatMetadata(emojiFont)).isTrue();
    }
}
