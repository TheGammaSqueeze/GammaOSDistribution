/*
 * Copyright (C) 2014 The CyanogenMod Project
 *               2017-2022 The LineageOS Project
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

package org.lineageos.lineageparts.profiles;

import android.os.Bundle;
import android.util.SparseArray;
import android.view.ViewGroup;

import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentActivity;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentPagerAdapter;

import org.lineageos.lineageparts.R;
import org.lineageos.lineageparts.profiles.triggers.BluetoothTriggerFragment;
import org.lineageos.lineageparts.profiles.triggers.NfcTriggerFragment;
import org.lineageos.lineageparts.profiles.triggers.WifiTriggerFragment;
import com.google.android.collect.Lists;

import java.lang.ref.WeakReference;
import java.util.List;

/**
 * A {@link androidx.fragment.app.FragmentPagerAdapter} class for swiping between playlists, recent,
 * artists, albums, songs, and genre {@link androidx.fragment.app.Fragment}s on phones.<br/>
 */
public class TriggerPagerAdapter extends FragmentPagerAdapter {

    private final SparseArray<WeakReference<Fragment>> mFragmentArray = new SparseArray<>();

    private final List<Holder> mHolderList = Lists.newArrayList();

    private final FragmentActivity mFragmentActivity;

    private int mCurrentPage;

    /**
     * Constructor of <code>PagerAdatper<code>
     *
     * @param activity The {@link androidx.fragment.app.FragmentActivity} of the
     *            {@link androidx.fragment.app.Fragment}.
     * @param fm the FragmentManager to use.
     */
    public TriggerPagerAdapter(FragmentActivity activity, FragmentManager fm) {
        super(fm);
        mFragmentActivity = activity;
    }

    /**
     * Method that adds a new fragment class to the viewer (the fragment is
     * internally instantiate)
     *
     * @param className The full qualified name of fragment class.
     * @param params The instantiate params.
     */
    @SuppressWarnings("synthetic-access")
    public void add(final Class<? extends Fragment> className, final Bundle params,
                    final int titleResId) {
        final Holder mHolder = new Holder();
        mHolder.mClassName = className.getName();
        mHolder.mParams = params;
        mHolder.mTitleResId = titleResId;

        final int mPosition = mHolderList.size();
        mHolderList.add(mPosition, mHolder);
        notifyDataSetChanged();
    }

    /**
     * Method that returns the {@link androidx.fragment.app.Fragment} in the argument
     * position.
     *
     * @param position The position of the fragment to return.
     * @return Fragment The {@link androidx.fragment.app.Fragment} in the argument position.
     */
    public Fragment getFragment(final int position) {
        final WeakReference<Fragment> mWeakFragment = mFragmentArray.get(position);
        if (mWeakFragment != null && mWeakFragment.get() != null) {
            return mWeakFragment.get();
        }
        return getItem(position);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Object instantiateItem(final ViewGroup container, final int position) {
        final Fragment mFragment = (Fragment)super.instantiateItem(container, position);
        final WeakReference<Fragment> mWeakFragment = mFragmentArray.get(position);
        if (mWeakFragment != null) {
            mWeakFragment.clear();
        }
        mFragmentArray.put(position, new WeakReference<Fragment>(mFragment));
        return mFragment;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Fragment getItem(final int position) {
        final Holder mCurrentHolder = mHolderList.get(position);
        return Fragment.instantiate(mFragmentActivity,
                mCurrentHolder.mClassName, mCurrentHolder.mParams);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void destroyItem(final ViewGroup container, final int position, final Object object) {
        super.destroyItem(container, position, object);
        final WeakReference<Fragment> mWeakFragment = mFragmentArray.get(position);
        if (mWeakFragment != null) {
            mWeakFragment.clear();
        }
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public int getCount() {
        return mHolderList.size();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public CharSequence getPageTitle(final int position) {
        return mFragmentActivity.getString(mHolderList.get(position).mTitleResId);
    }

    /**
     * Method that returns the current page position.
     *
     * @return int The current page.
     */
    public int getCurrentPage() {
        return mCurrentPage;
    }

    /**
     * Method that sets the current page position.
     *
     * @param currentPage The current page.
     */
    protected void setCurrentPage(final int currentPage) {
        mCurrentPage = currentPage;
    }

    /**
     * An enumeration of all the main fragments supported.
     */
    public enum TriggerFragments {
        /**
         * The artist fragment
         */
        WIFI(WifiTriggerFragment.class, R.string.profile_tabs_wifi),
        /**
         * The album fragment
         */
        BLUETOOTH(BluetoothTriggerFragment.class, R.string.profile_tabs_bluetooth),
        /**
         * The song fragment
         */
        NFC(NfcTriggerFragment.class, R.string.profile_tabs_nfc);

        private final Class<? extends Fragment> mFragmentClass;
        private final int mNameRes;

        /**
         * Constructor of <code>MusicFragments</code>
         *
         * @param fragmentClass The fragment class
         */
        TriggerFragments(final Class<? extends Fragment> fragmentClass, int nameRes) {
            mFragmentClass = fragmentClass;
            mNameRes = nameRes;
        }

        /**
         * Method that returns the fragment class.
         *
         * @return Class<? extends Fragment> The fragment class.
         */
        public Class<? extends Fragment> getFragmentClass() {
            return mFragmentClass;
        }

        public int getTitleRes() { return mNameRes; }
    }

    /**
     * A private class with information about fragment initialization
     */
    private final static class Holder {
        String mClassName;
        int mTitleResId;
        Bundle mParams;
    }
}
