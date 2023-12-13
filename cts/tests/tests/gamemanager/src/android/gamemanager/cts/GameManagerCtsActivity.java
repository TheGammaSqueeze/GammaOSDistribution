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

package android.gamemanager.cts;

import android.app.Activity;
import android.app.GameManager;
import android.content.Context;
import android.os.Bundle;

public class GameManagerCtsActivity extends Activity {

    private static final String TAG = "GameManagerCtsActivity";

    Context mContext;
    GameManager mGameManager;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mContext = getApplicationContext();
        mGameManager = mContext.getSystemService(GameManager.class);
    }

    public String getPackageName() {
        return mContext.getPackageName();
    }

    public int getGameMode() {
        return mGameManager.getGameMode();
    }

}
