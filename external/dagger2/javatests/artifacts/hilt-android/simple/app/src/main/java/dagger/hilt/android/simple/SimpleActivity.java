/*
 * Copyright (C) 2020 The Dagger Authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package dagger.hilt.android.simple;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.widget.Button;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;
import dagger.hilt.android.AndroidEntryPoint;
import dagger.hilt.android.simple.feature.FeatureActivity;
import dagger.hilt.android.simple.lib.Thing;
import javax.inject.Inject;

/** The main activity of the application. */
@AndroidEntryPoint
public class SimpleActivity extends AppCompatActivity {
  private static final String TAG = SimpleActivity.class.getSimpleName();

  @Inject @UserName String userName;
  @Inject @Model String model;
  @Inject Thing thing;

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    Log.i(TAG, "Injected with userName and model: " + userName + ", " + model);

    setContentView(R.layout.activity_main);

    ((TextView) findViewById(R.id.greeting))
        .setText(getResources().getString(R.string.welcome, userName, model));

    Button featureButton = (Button) findViewById(R.id.goto_feature);
    featureButton.setOnClickListener(
        view -> startActivity(new Intent(this, FeatureActivity.class)));
  }
}
