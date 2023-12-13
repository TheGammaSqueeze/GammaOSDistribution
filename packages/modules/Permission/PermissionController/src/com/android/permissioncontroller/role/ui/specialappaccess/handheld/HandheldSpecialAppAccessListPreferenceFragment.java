/*
 * Copyright (C) 2019 The Android Open Source Project
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

package com.android.permissioncontroller.role.ui.specialappaccess.handheld;

import android.content.Context;
import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.preference.PreferenceFragmentCompat;

import com.android.permissioncontroller.role.ui.TwoTargetPreference;
import com.android.permissioncontroller.role.ui.handheld.SettingsButtonPreference;
import com.android.permissioncontroller.role.ui.specialappaccess.SpecialAppAccessListChildFragment;

/**
 * Handheld fragment for the list of special app accesses.
 * <p>
 * Must be added as a child fragment and its parent fragment must implement {@link Parent}.
 */
public class HandheldSpecialAppAccessListPreferenceFragment extends PreferenceFragmentCompat
        implements SpecialAppAccessListChildFragment.Parent {

    /**
     * Create a new instance of this fragment.
     *
     * @return a new instance of this fragment
     */
    @NonNull
    public static HandheldSpecialAppAccessListPreferenceFragment newInstance() {
        return new HandheldSpecialAppAccessListPreferenceFragment();
    }

    @Override
    public void onActivityCreated(@Nullable Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);

        if (savedInstanceState == null) {
            SpecialAppAccessListChildFragment fragment =
                    SpecialAppAccessListChildFragment.newInstance();
            getChildFragmentManager().beginTransaction()
                    .add(fragment, null)
                    .commit();
        }
    }

    @Override
    public void onCreatePreferences(@Nullable Bundle savedInstanceState, @Nullable String rootKey) {
        // Preferences will be added by the child fragment later.
    }

    @NonNull
    @Override
    public TwoTargetPreference createPreference(@NonNull Context context) {
        return new SettingsButtonPreference(context);
    }

    @Override
    public void onPreferenceScreenChanged() {
        requireParent().onPreferenceScreenChanged();
    }

    @NonNull
    private Parent requireParent() {
        //noinspection unchecked
        return (Parent) requireParentFragment();
    }

    /**
     * Interface that the parent fragment must implement.
     */
    public interface Parent {

        /**
         * Callback when changes have been made to the {@link PreferenceScreen} of the parent
         * {@link PreferenceFragmentCompat}.
         */
        void onPreferenceScreenChanged();
    }
}
