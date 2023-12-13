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

package com.android.car.settings.profiles;

import android.car.user.CarUserManager;
import android.car.user.UserCreationResult;
import android.car.userlib.UserHelper;
import android.car.util.concurrent.AsyncFuture;
import android.content.Context;
import android.content.pm.UserInfo;
import android.os.AsyncTask;

import com.android.car.settings.common.Logger;

import java.util.concurrent.ExecutionException;

/**
 * Task to add a new profile to the device
 */
public class AddNewProfileTask extends AsyncTask<String, Void, UserInfo> {
    private static final Logger LOG = new Logger(AddNewProfileTask.class);

    private final Context mContext;
    private final CarUserManager mCarUserManager;
    private final AddNewProfileListener mAddNewProfileListener;

    public AddNewProfileTask(Context context, CarUserManager carUserManager,
            AddNewProfileListener addNewProfileListener) {
        mContext = context;
        mCarUserManager = carUserManager;
        mAddNewProfileListener = addNewProfileListener;
    }

    @Override
    protected UserInfo doInBackground(String... profileNames) {
        AsyncFuture<UserCreationResult> future = mCarUserManager.createUser(profileNames[0],
                /* flags= */ 0);
        try {
            UserCreationResult result = future.get();
            if (result.isSuccess()) {
                UserInfo user = result.getUser();
                if (user != null) {
                    UserHelper.setDefaultNonAdminRestrictions(mContext, user, /* enable= */ true);
                    UserHelper.assignDefaultIcon(mContext, user);
                } else {
                    LOG.wtf("Inconsistent state: successful future with null profile - "
                            + result.toString());
                }
                return user;
            }
        } catch (InterruptedException | ExecutionException e) {
            if (e instanceof InterruptedException) {
                Thread.currentThread().interrupt();
            }
            LOG.e("Error creating new profile: ", e);
        }
        return null;
    }

    @Override
    protected void onPreExecute() { }

    @Override
    protected void onPostExecute(UserInfo user) {
        if (user != null) {
            mAddNewProfileListener.onProfileAddedSuccess();
            mCarUserManager.switchUser(user.id);
        } else {
            mAddNewProfileListener.onProfileAddedFailure();
        }
    }

    /**
     * Interface for getting notified when AddNewProfileTask has been completed.
     */
    public interface AddNewProfileListener {
        /**
         * Invoked in AddNewProfileTask.onPostExecute after the profile has been created
         * successfully.
         */
        void onProfileAddedSuccess();

        /**
         * Invoked in AddNewProfileTask.onPostExecute if new profile creation failed.
         */
        void onProfileAddedFailure();
    }
}
