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

import android.annotation.UserIdInt;
import android.content.Context;
import android.content.pm.UserInfo;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.Drawable;
import android.os.UserHandle;
import android.os.UserManager;

import com.android.car.admin.ui.UserAvatarView;
import com.android.car.settings.R;
import com.android.internal.util.UserIcons;

/**
 * Simple class for providing icons for profiles in Settings.
 */
public class ProfileIconProvider {

    /**
     * Gets a scaled rounded icon for the given profile to use in settings.  If a profile does
     * not have an icon saved, this method will default to a generic icon and update UserManager to
     * use that icon.
     *
     * @param userInfo User for which the icon is requested.
     * @param context Context to use for resources
     * @return {@link Drawable} representing the icon for the user.
     */
    public Drawable getRoundedProfileIcon(UserInfo userInfo, Context context) {
        UserManager userManager = UserManager.get(context);
        Resources res = context.getResources();
        Bitmap icon = userManager.getUserIcon(userInfo.id);

        if (icon == null) {
            icon = assignDefaultIcon(userManager, res, userInfo);
        }

        return new BitmapDrawable(res, icon);
    }

    /** Returns a scaled, rounded, default icon for the Guest profile */
    public Drawable getRoundedGuestDefaultIcon(Resources resources) {
        Bitmap icon = getGuestProfileDefaultIcon(resources);
        return new BitmapDrawable(resources, icon);
    }

    /**
     * Assigns a default icon to a profile according to the user's id. Handles Guest icon and
     * non-guest profile icons.
     *
     * @param userManager {@link UserManager} to set user icon
     * @param resources {@link Resources} to grab icons from
     * @param userInfo User whose avatar is set to default icon.
     * @return Bitmap of the profile icon.
     */
    public Bitmap assignDefaultIcon(
            UserManager userManager, Resources resources, UserInfo userInfo) {
        Bitmap bitmap = userInfo.isGuest()
                ? getGuestProfileDefaultIcon(resources)
                : getProfileDefaultIcon(resources, userInfo.id);
        userManager.setUserIcon(userInfo.id, bitmap);
        return bitmap;
    }

    // TODO (b/179802719): refactor this method into getRoundedUserIcon().
    /**
     * Gets badge to profile icon Drawable if the profile is managed.
     *
     * @param context to use for the avatar view
     * @param userInfo User for which the icon is requested and badge is set
     * @return {@link Drawable} with badge
     */
    public Drawable getDrawableWithBadge(Context context, UserInfo userInfo) {
        Drawable userIcon = getRoundedProfileIcon(userInfo, context);
        int iconSize = userIcon.getIntrinsicWidth();
        UserAvatarView userAvatarView = new UserAvatarView(context);
        float badgeToIconSizeRatio =
                context.getResources().getDimension(R.dimen.profile_switcher_managed_badge_size)
                        / context.getResources().getDimension(
                        R.dimen.profile_switcher_image_avatar_size);
        userAvatarView.setBadgeDiameter(iconSize * badgeToIconSizeRatio);
        float badgePadding = context.getResources().getDimension(
                R.dimen.profile_switcher_managed_badge_margin);
        userAvatarView.setBadgeMargin(badgePadding);
        userAvatarView.setDrawableWithBadge(userIcon, userInfo.id);
        Drawable badgedIcon = userAvatarView.getUserIconDrawable();
        badgedIcon.setBounds(0, 0, iconSize, iconSize);
        return badgedIcon;
    }

    /**
     * Gets a bitmap representing the profile's default avatar.
     *
     * @param resources The resources to pull from
     * @param id The id of the user to get the icon for.  Pass {@link UserHandle#USER_NULL} for
     *           Guest user.
     * @return Default profile icon
     */
    private Bitmap getProfileDefaultIcon(Resources resources, @UserIdInt int id) {
        return UserIcons.convertToBitmap(
                UserIcons.getDefaultUserIcon(resources, id, /* light= */ false));
    }

    private Bitmap getGuestProfileDefaultIcon(Resources resources) {
        return getProfileDefaultIcon(resources, UserHandle.USER_NULL);
    }
}
