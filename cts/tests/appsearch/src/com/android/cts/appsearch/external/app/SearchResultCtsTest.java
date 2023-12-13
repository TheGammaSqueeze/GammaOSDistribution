/*
 * Copyright 2021 The Android Open Source Project
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

package android.app.appsearch.cts.app;

import static com.google.common.truth.Truth.assertThat;

import android.app.appsearch.SearchResult;

import com.android.server.appsearch.testing.AppSearchEmail;

import org.junit.Test;

public class SearchResultCtsTest {

    @Test
    public void testBuildSearchResult() {
        SearchResult.MatchRange exactMatchRange = new SearchResult.MatchRange(3, 8);
        SearchResult.MatchRange snippetMatchRange = new SearchResult.MatchRange(1, 10);
        SearchResult.MatchInfo matchInfo =
                new SearchResult.MatchInfo.Builder("body")
                        .setExactMatchRange(exactMatchRange)
                        .setSnippetRange(snippetMatchRange)
                        .build();

        AppSearchEmail email =
                new AppSearchEmail.Builder("namespace1", "id1").setBody("Hello World.").build();
        SearchResult searchResult =
                new SearchResult.Builder("packageName", "databaseName")
                        .setGenericDocument(email)
                        .addMatchInfo(matchInfo)
                        .setRankingSignal(2.9)
                        .build();

        assertThat(searchResult.getPackageName()).isEqualTo("packageName");
        assertThat(searchResult.getDatabaseName()).isEqualTo("databaseName");
        assertThat(searchResult.getRankingSignal()).isEqualTo(2.9);
        assertThat(searchResult.getGenericDocument()).isEqualTo(email);
        assertThat(searchResult.getMatchInfos()).hasSize(1);
        SearchResult.MatchInfo actualMatchInfo = searchResult.getMatchInfos().get(0);
        assertThat(actualMatchInfo.getPropertyPath()).isEqualTo("body");
        assertThat(actualMatchInfo.getExactMatchRange()).isEqualTo(exactMatchRange);
        assertThat(actualMatchInfo.getSnippetRange()).isEqualTo(snippetMatchRange);
        assertThat(actualMatchInfo.getExactMatch()).isEqualTo("lo Wo");
        assertThat(actualMatchInfo.getSnippet()).isEqualTo("ello Worl");
        assertThat(actualMatchInfo.getFullText()).isEqualTo("Hello World.");
    }

    @Test
    public void testMatchRange() {
        SearchResult.MatchRange matchRange = new SearchResult.MatchRange(13, 47);
        assertThat(matchRange.getStart()).isEqualTo(13);
        assertThat(matchRange.getEnd()).isEqualTo(47);
    }
}
