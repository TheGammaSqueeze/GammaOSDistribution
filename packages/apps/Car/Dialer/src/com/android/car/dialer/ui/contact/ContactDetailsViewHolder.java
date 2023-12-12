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

package com.android.car.dialer.ui.contact;

import android.app.Activity;
import android.content.ActivityNotFoundException;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ResolveInfo;
import android.content.res.Resources;
import android.graphics.drawable.Drawable;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.recyclerview.widget.RecyclerView;

import com.android.car.apps.common.BackgroundImageView;
import com.android.car.apps.common.LetterTileDrawable;
import com.android.car.apps.common.util.ViewUtils;
import com.android.car.dialer.R;
import com.android.car.dialer.log.L;
import com.android.car.dialer.telecom.UiCallManager;
import com.android.car.dialer.ui.view.ContactAvatarOutputlineProvider;
import com.android.car.telephony.common.Contact;
import com.android.car.telephony.common.PhoneNumber;
import com.android.car.telephony.common.PostalAddress;
import com.android.car.telephony.common.TelecomUtils;

import com.bumptech.glide.Glide;
import com.bumptech.glide.load.DataSource;
import com.bumptech.glide.load.engine.GlideException;
import com.bumptech.glide.request.RequestListener;
import com.bumptech.glide.request.RequestOptions;
import com.bumptech.glide.request.target.Target;

import java.util.List;

import dagger.assisted.Assisted;
import dagger.assisted.AssistedFactory;
import dagger.assisted.AssistedInject;

/**
 * ViewHolder for {@link ContactDetailsFragment}.
 */
class ContactDetailsViewHolder extends RecyclerView.ViewHolder {
    private static final String TAG = "CD.ContactDetailsVH";

    private final UiCallManager mUiCallManager;

    // Applies to all
    @NonNull
    private final TextView mTitle;

    // Applies to header
    @Nullable
    private final ImageView mAvatarView;
    @Nullable
    private final BackgroundImageView mBackgroundImageView;

    // Applies to phone number items and address items
    @Nullable
    private final TextView mText;

    // Applies to phone number items
    @Nullable
    private final View mCallActionView;
    @Nullable
    private final ImageView mFavoriteActionView;
    @Nullable
    private final View mSmsActionView;
    @Nullable
    private final View mSmsActionDividerView;

    // Applies to address items
    @Nullable
    private final View mAddressView;
    @Nullable
    private final View mNavigationButton;
    @Nullable
    private final View mDivider;

    @NonNull
    private final ContactDetailsAdapter.PhoneNumberPresenter mPhoneNumberPresenter;

    @AssistedInject
    ContactDetailsViewHolder(
            @Assisted @NonNull View v,
            @Assisted @NonNull ContactDetailsAdapter.PhoneNumberPresenter phoneNumberPresenter,
            UiCallManager uiCallManager) {
        super(v);
        mUiCallManager = uiCallManager;
        mCallActionView = v.findViewById(R.id.call_action_id);
        mFavoriteActionView = v.findViewById(R.id.contact_details_favorite_button);
        mSmsActionView = v.findViewById(R.id.contact_details_sms_button);
        mSmsActionDividerView = v.findViewById(R.id.divider1);
        mAddressView = v.findViewById(R.id.address_button);
        mNavigationButton = v.findViewById(R.id.navigation_button);
        mDivider = v.findViewById(R.id.divider);
        mTitle = v.findViewById(R.id.title);
        mText = v.findViewById(R.id.text);
        mAvatarView = v.findViewById(R.id.avatar);
        if (mAvatarView != null) {
            mAvatarView.setOutlineProvider(ContactAvatarOutputlineProvider.get());
        }
        mBackgroundImageView = v.findViewById(R.id.background_image);

        mPhoneNumberPresenter = phoneNumberPresenter;
    }

    public void bind(Context context, Contact contact) {
        if (contact == null) {
            ViewUtils.setText(mTitle, R.string.error_contact_deleted);
            LetterTileDrawable letterTile = TelecomUtils.createLetterTile(context, null, null);
            if (mAvatarView != null) {
                mAvatarView.setImageDrawable(letterTile);
            }
            if (mBackgroundImageView != null) {
                mBackgroundImageView.setAlpha(context.getResources().getFloat(
                        R.dimen.config_background_image_error_alpha));
                mBackgroundImageView.setBackgroundColor(letterTile.getColor());
            }
            return;
        }

        ViewUtils.setText(mTitle, contact.getDisplayName());

        if (mAvatarView == null && mBackgroundImageView == null) {
            return;
        }

        LetterTileDrawable letterTile = TelecomUtils.createLetterTile(context,
                contact.getInitials(), contact.getDisplayName());
        Glide.with(context)
                .load(contact.getAvatarUri())
                .apply(new RequestOptions().centerCrop().error(letterTile))
                .listener(new RequestListener<Drawable>() {
                    @Override
                    public boolean onLoadFailed(@Nullable GlideException e, Object model,
                            Target<Drawable> target, boolean isFirstResource) {
                        if (mBackgroundImageView != null) {
                            mBackgroundImageView.setAlpha(context.getResources().getFloat(
                                    R.dimen.config_background_image_error_alpha));
                            mBackgroundImageView.setBackgroundColor(letterTile.getColor());
                        }
                        return false;
                    }

                    @Override
                    public boolean onResourceReady(Drawable resource, Object model,
                            Target<Drawable> target, DataSource dataSource,
                            boolean isFirstResource) {
                        if (mBackgroundImageView != null) {
                            mBackgroundImageView.setAlpha(context.getResources().getFloat(
                                    R.dimen.config_background_image_alpha));
                            mBackgroundImageView.setBackgroundDrawable(resource, false);
                        }
                        return false;
                    }
                }).into(mAvatarView);
    }

    public void bind(Context context, Contact contact, PhoneNumber phoneNumber, Activity activity) {
        mTitle.setText(phoneNumber.getRawNumber());

        // Present the phone number type and local favorite state.
        CharSequence readableLabel = phoneNumber.getReadableLabel(context.getResources());
        CharSequence favoriteLabel = phoneNumber.isFavorite() ? context.getString(
                R.string.local_favorite_number_description, readableLabel) : readableLabel;
        if (phoneNumber.isPrimary()) {
            mText.setText(context.getString(R.string.primary_number_description, favoriteLabel));
            mText.setTextAppearance(R.style.TextAppearance_DefaultNumberLabel);
        } else {
            mText.setText(favoriteLabel);
            mText.setTextAppearance(R.style.TextAppearance_ContactDetailsListSubtitle);
        }

        mCallActionView.setOnClickListener(
                v -> mUiCallManager.placeCall(phoneNumber.getRawNumber()));

        boolean showSmsButton = context.getResources().getBoolean(
                R.bool.config_show_contact_details_send_message_button);
        if (showSmsButton) {
            mSmsActionView.setOnClickListener(
                    v -> mUiCallManager.placeSms(
                            activity, phoneNumber.getRawNumber(), contact.getDisplayName(),
                            Long.toString(contact.getRawContactId())));
        }
        mSmsActionDividerView.setVisibility(showSmsButton ? View.VISIBLE : View.GONE);
        mSmsActionView.setVisibility(showSmsButton ? View.VISIBLE : View.GONE);

        if (phoneNumber.isFavorite() || !contact.isStarred()) {
            // If the phone number is marked as favorite locally, enable the action button to
            // allow users to remove from local favorites.
            // If the phone number is not a local favorite or a favorite from phone, allow users
            // to mark it as favorite locally.
            ViewUtils.setActivated(mFavoriteActionView, phoneNumber.isFavorite());
            ViewUtils.setEnabled(mFavoriteActionView, true);
            ViewUtils.setOnClickListener(mFavoriteActionView, v -> {
                mPhoneNumberPresenter.onClick(contact, phoneNumber);
                mFavoriteActionView.setActivated(!mFavoriteActionView.isActivated());
            });
        } else {
            // The contact is favorite contact downloaded from phone. Disable the favorite action
            // button so the phone numbers can not be marked as favorite locally as it is not
            // necessary.
            ViewUtils.setActivated(mFavoriteActionView, false);
            ViewUtils.setEnabled(mFavoriteActionView, false);
            ViewUtils.setOnClickListener(mFavoriteActionView, null);
        }
    }

    public void bind(Context context, @NonNull PostalAddress postalAddress) {
        String address = postalAddress.getFormattedAddress();
        Resources resources = context.getResources();

        mTitle.setText(address);
        ViewUtils.setText(mText, postalAddress.getReadableLabel(resources));

        mAddressView.setOnClickListener(
                v -> openMapWithMapIntent(context, postalAddress.getAddressIntent(resources)));

        Intent intent = postalAddress.getNavigationIntent(resources);
        List<ResolveInfo> infos = context.getPackageManager().queryIntentActivities(intent, 0);

        if (infos.size() > 0) {
            mDivider.setVisibility(View.VISIBLE);
            mNavigationButton.setVisibility(View.VISIBLE);
            mNavigationButton.setOnClickListener(v -> openMapWithMapIntent(context, intent));
        } else {
            mDivider.setVisibility(View.GONE);
            mNavigationButton.setVisibility(View.GONE);
        }
    }

    private void openMapWithMapIntent(Context context, Intent mapIntent) {
        try {
            context.startActivity(mapIntent);
        } catch (ActivityNotFoundException e) {
            L.w(TAG, "Map is not available.");
        }
    }

    /**
     * Factory to create {@link ContactDetailsViewHolder} instances via the {@link AssistedInject}
     * constructor.
     */
    @AssistedFactory
    interface Factory {
        ContactDetailsViewHolder create(@NonNull View v,
                @NonNull ContactDetailsAdapter.PhoneNumberPresenter phoneNumberPresenter);
    }
}
