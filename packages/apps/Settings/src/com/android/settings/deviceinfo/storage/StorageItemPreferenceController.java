/*
 * Copyright (C) 2016 The Android Open Source Project
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

package com.android.settings.deviceinfo.storage;

import static com.android.settings.dashboard.profileselector.ProfileSelectFragment.PERSONAL_TAB;
import static com.android.settings.dashboard.profileselector.ProfileSelectFragment.WORK_TAB;

import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.content.res.TypedArray;
import android.graphics.drawable.Drawable;
import android.net.TrafficStats;
import android.net.Uri;
import android.os.Bundle;
import android.os.UserHandle;
import android.os.UserManager;
import android.os.storage.VolumeInfo;
import android.util.Log;
import android.util.SparseArray;
import android.widget.Toast;

import androidx.annotation.VisibleForTesting;
import androidx.fragment.app.Fragment;
import androidx.preference.Preference;
import androidx.preference.PreferenceScreen;

import com.android.settings.R;
import com.android.settings.Settings;
import com.android.settings.SettingsActivity;
import com.android.settings.Utils;
import com.android.settings.applications.manageapplications.ManageApplications;
import com.android.settings.core.PreferenceControllerMixin;
import com.android.settings.core.SubSettingLauncher;
import com.android.settings.deviceinfo.StorageItemPreference;
import com.android.settings.deviceinfo.storage.StorageUtils.SystemInfoFragment;
import com.android.settings.overlay.FeatureFactory;
import com.android.settingslib.core.AbstractPreferenceController;
import com.android.settingslib.core.instrumentation.MetricsFeatureProvider;
import com.android.settingslib.deviceinfo.StorageMeasurement;
import com.android.settingslib.deviceinfo.StorageVolumeProvider;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Map;

/**
 * StorageItemPreferenceController handles the storage line items which summarize the storage
 * categorization breakdown.
 */
public class StorageItemPreferenceController extends AbstractPreferenceController implements
        PreferenceControllerMixin,
        EmptyTrashFragment.OnEmptyTrashCompleteListener {
    private static final String TAG = "StorageItemPreference";

    private static final String SYSTEM_FRAGMENT_TAG = "SystemInfo";

    @VisibleForTesting
    static final String PUBLIC_STORAGE_KEY = "pref_public_storage";
    @VisibleForTesting
    static final String IMAGES_KEY = "pref_images";
    @VisibleForTesting
    static final String VIDEOS_KEY = "pref_videos";
    @VisibleForTesting
    static final String AUDIO_KEY = "pref_audio";
    @VisibleForTesting
    static final String APPS_KEY = "pref_apps";
    @VisibleForTesting
    static final String GAMES_KEY = "pref_games";
    @VisibleForTesting
    static final String DOCUMENTS_AND_OTHER_KEY = "pref_documents_and_other";
    @VisibleForTesting
    static final String SYSTEM_KEY = "pref_system";
    @VisibleForTesting
    static final String TRASH_KEY = "pref_trash";

    @VisibleForTesting
    final Uri mImagesUri;
    @VisibleForTesting
    final Uri mVideosUri;
    @VisibleForTesting
    final Uri mAudioUri;
    @VisibleForTesting
    final Uri mDocumentsAndOtherUri;

    // This value should align with the design of storage_dashboard_fragment.xml
    private static final int LAST_STORAGE_CATEGORY_PREFERENCE_ORDER = 200;

    private PackageManager mPackageManager;
    private UserManager mUserManager;
    private final Fragment mFragment;
    private final MetricsFeatureProvider mMetricsFeatureProvider;
    private final StorageVolumeProvider mSvp;
    private VolumeInfo mVolume;
    private int mUserId;
    private long mUsedBytes;
    private long mTotalSize;

    private List<StorageItemPreference> mPrivateStorageItemPreferences;
    private PreferenceScreen mScreen;
    @VisibleForTesting
    Preference mPublicStoragePreference;
    @VisibleForTesting
    StorageItemPreference mImagesPreference;
    @VisibleForTesting
    StorageItemPreference mVideosPreference;
    @VisibleForTesting
    StorageItemPreference mAudioPreference;
    @VisibleForTesting
    StorageItemPreference mAppsPreference;
    @VisibleForTesting
    StorageItemPreference mGamesPreference;
    @VisibleForTesting
    StorageItemPreference mDocumentsAndOtherPreference;
    @VisibleForTesting
    StorageItemPreference mSystemPreference;
    @VisibleForTesting
    StorageItemPreference mTrashPreference;

    private boolean mIsWorkProfile;

    private static final String AUTHORITY_MEDIA = "com.android.providers.media.documents";

    public StorageItemPreferenceController(Context context, Fragment hostFragment,
            VolumeInfo volume, StorageVolumeProvider svp, boolean isWorkProfile) {
        super(context);
        mPackageManager = context.getPackageManager();
        mUserManager = context.getSystemService(UserManager.class);
        mFragment = hostFragment;
        mVolume = volume;
        mSvp = svp;
        mIsWorkProfile = isWorkProfile;
        mMetricsFeatureProvider = FeatureFactory.getFactory(context).getMetricsFeatureProvider();
        mUserId = getCurrentUserId();

        mImagesUri = Uri.parse(context.getResources()
                .getString(R.string.config_images_storage_category_uri));
        mVideosUri = Uri.parse(context.getResources()
                .getString(R.string.config_videos_storage_category_uri));
        mAudioUri = Uri.parse(context.getResources()
                .getString(R.string.config_audio_storage_category_uri));
        mDocumentsAndOtherUri = Uri.parse(context.getResources()
                .getString(R.string.config_documents_and_other_storage_category_uri));
    }

    @VisibleForTesting
    int getCurrentUserId() {
        return Utils.getCurrentUserId(mUserManager, mIsWorkProfile);
    }

    @Override
    public boolean isAvailable() {
        return true;
    }

    @Override
    public boolean handlePreferenceTreeClick(Preference preference) {
        if (preference.getKey() == null) {
            return false;
        }
        switch (preference.getKey()) {
            case PUBLIC_STORAGE_KEY:
                launchPublicStorageIntent();
                return true;
            case IMAGES_KEY:
                launchActivityWithUri(mImagesUri);
                return true;
            case VIDEOS_KEY:
                launchActivityWithUri(mVideosUri);
                return true;
            case AUDIO_KEY:
                launchActivityWithUri(mAudioUri);
                return true;
            case APPS_KEY:
                launchAppsIntent();
                return true;
            case GAMES_KEY:
                launchGamesIntent();
                return true;
            case DOCUMENTS_AND_OTHER_KEY:
                launchActivityWithUri(mDocumentsAndOtherUri);
                return true;
            case SYSTEM_KEY:
                final SystemInfoFragment dialog = new SystemInfoFragment();
                dialog.setTargetFragment(mFragment, 0);
                dialog.show(mFragment.getFragmentManager(), SYSTEM_FRAGMENT_TAG);
                return true;
            case TRASH_KEY:
                launchTrashIntent();
                return true;
            default:
                // Do nothing.
        }
        return super.handlePreferenceTreeClick(preference);
    }

    @Override
    public String getPreferenceKey() {
        return null;
    }

    /**
     * Sets the storage volume to use for when handling taps.
     */
    public void setVolume(VolumeInfo volume) {
        mVolume = volume;

        if (mPublicStoragePreference != null) {
            mPublicStoragePreference.setVisible(isValidPublicVolume());
        }

        // If isValidPrivateVolume() is true, these preferences will become visible at
        // onLoadFinished.
        if (!isValidPrivateVolume()) {
            setPrivateStorageCategoryPreferencesVisibility(false);
        }
    }

    // Stats data is only available on private volumes.
    private boolean isValidPrivateVolume() {
        return mVolume != null
                && mVolume.getType() == VolumeInfo.TYPE_PRIVATE
                && (mVolume.getState() == VolumeInfo.STATE_MOUNTED
                || mVolume.getState() == VolumeInfo.STATE_MOUNTED_READ_ONLY);
    }

    private boolean isValidPublicVolume() {
        // Stub volume is a volume that is maintained by external party such as the ChromeOS
        // processes in ARC++.
        return mVolume != null
                && (mVolume.getType() == VolumeInfo.TYPE_PUBLIC
                || mVolume.getType() == VolumeInfo.TYPE_STUB)
                && (mVolume.getState() == VolumeInfo.STATE_MOUNTED
                || mVolume.getState() == VolumeInfo.STATE_MOUNTED_READ_ONLY);
    }

    @VisibleForTesting
    void setPrivateStorageCategoryPreferencesVisibility(boolean visible) {
        if (mScreen == null) {
            return;
        }

        mImagesPreference.setVisible(visible);
        mVideosPreference.setVisible(visible);
        mAudioPreference.setVisible(visible);
        mAppsPreference.setVisible(visible);
        mGamesPreference.setVisible(visible);
        mSystemPreference.setVisible(visible);
        mTrashPreference.setVisible(visible);

        // If we don't have a shared volume for our internal storage (or the shared volume isn't
        // mounted as readable for whatever reason), we should hide the File preference.
        if (visible) {
            final VolumeInfo sharedVolume = mSvp.findEmulatedForPrivate(mVolume);
            mDocumentsAndOtherPreference.setVisible(sharedVolume != null
                    && sharedVolume.isMountedReadable());
        } else {
            mDocumentsAndOtherPreference.setVisible(false);
        }
    }

    private void updatePrivateStorageCategoryPreferencesOrder() {
        if (mScreen == null || !isValidPrivateVolume()) {
            return;
        }

        if (mPrivateStorageItemPreferences == null) {
            mPrivateStorageItemPreferences = new ArrayList<>();

            mPrivateStorageItemPreferences.add(mImagesPreference);
            mPrivateStorageItemPreferences.add(mVideosPreference);
            mPrivateStorageItemPreferences.add(mAudioPreference);
            mPrivateStorageItemPreferences.add(mAppsPreference);
            mPrivateStorageItemPreferences.add(mGamesPreference);
            mPrivateStorageItemPreferences.add(mDocumentsAndOtherPreference);
            mPrivateStorageItemPreferences.add(mSystemPreference);
            mPrivateStorageItemPreferences.add(mTrashPreference);
        }
        mScreen.removePreference(mImagesPreference);
        mScreen.removePreference(mVideosPreference);
        mScreen.removePreference(mAudioPreference);
        mScreen.removePreference(mAppsPreference);
        mScreen.removePreference(mGamesPreference);
        mScreen.removePreference(mDocumentsAndOtherPreference);
        mScreen.removePreference(mSystemPreference);
        mScreen.removePreference(mTrashPreference);

        // Sort display order by size.
        Collections.sort(mPrivateStorageItemPreferences,
                Comparator.comparingLong(StorageItemPreference::getStorageSize));
        int orderIndex = LAST_STORAGE_CATEGORY_PREFERENCE_ORDER;
        for (StorageItemPreference preference : mPrivateStorageItemPreferences) {
            preference.setOrder(orderIndex--);
            mScreen.addPreference(preference);
        }
    }

    /**
     * Sets the user id for which this preference controller is handling.
     */
    public void setUserId(UserHandle userHandle) {
        if (mIsWorkProfile && !mUserManager.isManagedProfile(userHandle.getIdentifier())) {
            throw new IllegalArgumentException("Only accept work profile userHandle");
        }
        mUserId = userHandle.getIdentifier();

        tintPreference(mPublicStoragePreference);
        tintPreference(mImagesPreference);
        tintPreference(mVideosPreference);
        tintPreference(mAudioPreference);
        tintPreference(mAppsPreference);
        tintPreference(mGamesPreference);
        tintPreference(mDocumentsAndOtherPreference);
        tintPreference(mSystemPreference);
        tintPreference(mTrashPreference);
    }

    private void tintPreference(Preference preference) {
        if (preference != null) {
            preference.setIcon(applyTint(mContext, preference.getIcon()));
        }
    }

    private static Drawable applyTint(Context context, Drawable icon) {
        TypedArray array =
                context.obtainStyledAttributes(new int[]{android.R.attr.colorControlNormal});
        icon = icon.mutate();
        icon.setTint(array.getColor(0, 0));
        array.recycle();
        return icon;
    }

    @Override
    public void displayPreference(PreferenceScreen screen) {
        mScreen = screen;
        mPublicStoragePreference = screen.findPreference(PUBLIC_STORAGE_KEY);
        mImagesPreference = screen.findPreference(IMAGES_KEY);
        mVideosPreference = screen.findPreference(VIDEOS_KEY);
        mAudioPreference = screen.findPreference(AUDIO_KEY);
        mAppsPreference = screen.findPreference(APPS_KEY);
        mGamesPreference = screen.findPreference(GAMES_KEY);
        mDocumentsAndOtherPreference = screen.findPreference(DOCUMENTS_AND_OTHER_KEY);
        mSystemPreference = screen.findPreference(SYSTEM_KEY);
        mTrashPreference = screen.findPreference(TRASH_KEY);
    }

    /** Fragments use it to set storage result and update UI of this controller. */
    public void onLoadFinished(SparseArray<StorageAsyncLoader.StorageResult> result, int userId) {
        final StorageAsyncLoader.StorageResult data = result.get(userId);

        mImagesPreference.setStorageSize(data.imagesSize, mTotalSize);
        mVideosPreference.setStorageSize(data.videosSize, mTotalSize);
        mAudioPreference.setStorageSize(data.audioSize, mTotalSize);
        mAppsPreference.setStorageSize(data.allAppsExceptGamesSize, mTotalSize);
        mGamesPreference.setStorageSize(data.gamesSize, mTotalSize);
        mDocumentsAndOtherPreference.setStorageSize(data.documentsAndOtherSize, mTotalSize);
        mTrashPreference.setStorageSize(data.trashSize, mTotalSize);

        if (mSystemPreference != null) {
            // Everything else that hasn't already been attributed is tracked as
            // belonging to system.
            long attributedSize = 0;
            for (int i = 0; i < result.size(); i++) {
                final StorageAsyncLoader.StorageResult otherData = result.valueAt(i);
                attributedSize +=
                        otherData.gamesSize
                                + otherData.audioSize
                                + otherData.videosSize
                                + otherData.imagesSize
                                + otherData.documentsAndOtherSize
                                + otherData.trashSize
                                + otherData.allAppsExceptGamesSize;
                attributedSize -= otherData.duplicateCodeSize;
            }

            final long systemSize = Math.max(TrafficStats.GB_IN_BYTES, mUsedBytes - attributedSize);
            mSystemPreference.setStorageSize(systemSize, mTotalSize);
        }

        updatePrivateStorageCategoryPreferencesOrder();
        setPrivateStorageCategoryPreferencesVisibility(true);
    }

    public void setUsedSize(long usedSizeBytes) {
        mUsedBytes = usedSizeBytes;
    }

    public void setTotalSize(long totalSizeBytes) {
        mTotalSize = totalSizeBytes;
    }

    private void launchPublicStorageIntent() {
        final Intent intent = mVolume.buildBrowseIntent();
        if (intent == null) {
            return;
        }
        mContext.startActivityAsUser(intent, new UserHandle(mUserId));
    }

    private void launchActivityWithUri(Uri dataUri) {
        final Intent intent = new Intent(Intent.ACTION_VIEW);
        intent.setData(dataUri);
        mContext.startActivityAsUser(intent, new UserHandle(mUserId));
    }

    private void launchAppsIntent() {
        final Bundle args = getWorkAnnotatedBundle(3);
        args.putString(ManageApplications.EXTRA_CLASSNAME,
                Settings.StorageUseActivity.class.getName());
        args.putString(ManageApplications.EXTRA_VOLUME_UUID, mVolume.getFsUuid());
        args.putString(ManageApplications.EXTRA_VOLUME_NAME, mVolume.getDescription());
        final Intent intent = new SubSettingLauncher(mContext)
                .setDestination(ManageApplications.class.getName())
                .setTitleRes(R.string.apps_storage)
                .setArguments(args)
                .setSourceMetricsCategory(mMetricsFeatureProvider.getMetricsCategory(mFragment))
                .toIntent();
        intent.putExtra(Intent.EXTRA_USER_ID, mUserId);
        Utils.launchIntent(mFragment, intent);
    }

    private void launchGamesIntent() {
        final Bundle args = getWorkAnnotatedBundle(1);
        args.putString(ManageApplications.EXTRA_CLASSNAME,
                Settings.GamesStorageActivity.class.getName());
        final Intent intent = new SubSettingLauncher(mContext)
                .setDestination(ManageApplications.class.getName())
                .setTitleRes(R.string.game_storage_settings)
                .setArguments(args)
                .setSourceMetricsCategory(mMetricsFeatureProvider.getMetricsCategory(mFragment))
                .toIntent();
        intent.putExtra(Intent.EXTRA_USER_ID, mUserId);
        Utils.launchIntent(mFragment, intent);
    }

    private Bundle getWorkAnnotatedBundle(int additionalCapacity) {
        final Bundle args = new Bundle(1 + additionalCapacity);
        args.putInt(SettingsActivity.EXTRA_SHOW_FRAGMENT_TAB,
                mIsWorkProfile ? WORK_TAB : PERSONAL_TAB);
        return args;
    }

    private void launchTrashIntent() {
        final Intent intent = new Intent("android.settings.VIEW_TRASH");

        if (mPackageManager.resolveActivityAsUser(intent, 0 /* flags */, mUserId) == null) {
            final long trashSize = mTrashPreference.getStorageSize();
            if (trashSize > 0) {
                new EmptyTrashFragment(mFragment, mUserId, trashSize,
                        this /* onEmptyTrashCompleteListener */).show();
            } else {
                Toast.makeText(mContext, R.string.storage_trash_dialog_empty_message,
                        Toast.LENGTH_SHORT).show();
            }
        } else {
            mContext.startActivityAsUser(intent, new UserHandle(mUserId));
        }
    }

    @Override
    public void onEmptyTrashComplete() {
        if (mTrashPreference == null) {
            return;
        }
        mTrashPreference.setStorageSize(0, mTotalSize);
        updatePrivateStorageCategoryPreferencesOrder();
    }

    private static long totalValues(StorageMeasurement.MeasurementDetails details, int userId,
            String... keys) {
        long total = 0;
        Map<String, Long> map = details.mediaSize.get(userId);
        if (map != null) {
            for (String key : keys) {
                if (map.containsKey(key)) {
                    total += map.get(key);
                }
            }
        } else {
            Log.w(TAG, "MeasurementDetails mediaSize array does not have key for user " + userId);
        }
        return total;
    }
}
