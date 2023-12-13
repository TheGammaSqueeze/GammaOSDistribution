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

import static java.util.Objects.requireNonNull;

import android.content.Context;
import android.content.Intent;
import android.content.pm.UserInfo;
import android.os.Bundle;

import androidx.annotation.XmlRes;

import com.android.car.settings.R;
import com.android.car.settings.common.SettingsFragment;

/**
 * This screen appears after the last admin on the device tries to delete themselves. (but only if
 * there are other profiles on the device)
 *
 * <p> It lets the Admin see a list of non-Admins on the device and choose a profile from the list
 * to upgrade to Admin.
 *
 * <p> After new admin has been selected and upgraded, the old Admin is removed.
 */
public class ChooseNewAdminFragment extends SettingsFragment {

    /**
     * Creates a new instance of {@link ChooseNewAdminFragment} that enables the last remaining
     * admin to choose a new Admin from a list of Non-Admins.
     *
     * @param adminInfo Admin that will get removed after new admin has been designated.
     */
    public static ChooseNewAdminFragment newInstance(UserInfo adminInfo) {
        ChooseNewAdminFragment profilesListFragment = new ChooseNewAdminFragment();
        Bundle bundle = new Bundle();
        bundle.putParcelable(Intent.EXTRA_USER, adminInfo);
        profilesListFragment.setArguments(bundle);
        return profilesListFragment;
    }

    @Override
    @XmlRes
    protected int getPreferenceScreenResId() {
        return R.xml.choose_new_admin_fragment;
    }

    @Override
    public void onAttach(Context context) {
        super.onAttach(context);
        UserInfo adminInfo = requireNonNull(getArguments()).getParcelable(
                Intent.EXTRA_USER);
        use(ChooseNewAdminPreferenceController.class, R.string.pk_choose_new_admin).setAdminInfo(
                adminInfo);
    }
}
