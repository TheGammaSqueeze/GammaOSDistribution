/*
 * Copyright (C) 2020 The Android Open Source Project
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

package com.android.car.messenger.core.ui.conversationlist;

import android.graphics.drawable.Drawable;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.android.car.messenger.common.Conversation;

/** UI Conversation Item represents the UI layer for a Conversation Item row */
public class UIConversationItem {

    @NonNull String mConversationId;
    @NonNull String mTitle;
    @NonNull String mTextPreview;
    @Nullable Drawable mSubtitleIcon;
    @NonNull String mTextMetadata;
    long mLastMessageTimestamp;
    @Nullable Drawable mAvatar;
    boolean mIsMuted;
    boolean mShowMuteIcon;
    boolean mShowReplyIcon;
    boolean mShowPlayIcon;
    boolean mUseUnreadTheme;
    @NonNull Conversation mConversation;

    public UIConversationItem(
            @NonNull String conversationId,
            @NonNull String title,
            @NonNull String textPreview,
            @Nullable Drawable subtitleIcon,
            @NonNull String textMetadata,
            long lastMessageTimestamp,
            @Nullable Drawable avatar,
            boolean showMuteIcon,
            boolean showReplyIcon,
            boolean showPlayIcon,
            boolean useUnreadTheme,
            boolean isMuted,
            @NonNull Conversation conversation) {
        this.mConversationId = conversationId;
        this.mTitle = title;
        this.mTextPreview = textPreview;
        this.mSubtitleIcon = subtitleIcon;
        this.mTextMetadata = textMetadata;
        this.mLastMessageTimestamp = lastMessageTimestamp;
        this.mAvatar = avatar;
        this.mShowMuteIcon = showMuteIcon;
        this.mShowReplyIcon = showReplyIcon;
        this.mShowPlayIcon = showPlayIcon;
        this.mUseUnreadTheme = useUnreadTheme;
        this.mIsMuted = isMuted;
        this.mConversation = conversation;
    }

    /** Returns conversation id */
    @NonNull
    public String getConversationId() {
        return mConversationId;
    }

    /** Returns human readable title for conversation */
    @NonNull
    public String getTitle() {
        return mTitle;
    }

    /** Returns text preview for the conversation */
    @NonNull
    public String getTextPreview() {
        return mTextPreview;
    }

    /**
     * Returns icon to show by the corner of the subtitle. This can be null if nothing should be
     * shown.
     */
    @Nullable
    public Drawable getSubtitleIcon() {
        return mSubtitleIcon;
    }

    /** Gets text metadata */
    @NonNull
    public String getTextMetadata() {
        return mTextMetadata;
    }

    /** Gets last message timestamp */
    public long getLastMessageTimestamp() {
        return mLastMessageTimestamp;
    }

    /** Returns the avatar for the conversation */
    @Nullable
    public Drawable getAvatar() {
        return mAvatar;
    }

    /** Returns true, if mute icon should be shown, false otherwise */
    public boolean shouldShowMuteIcon() {
        return mShowMuteIcon;
    }

    /** Returns true, if conversation is muted or false otherwise */
    public boolean isMuted() {
        return mIsMuted;
    }

    /** Returns true, if reply icon should be shown, false otherwise */
    public boolean shouldShowReplyIcon() {
        return mShowReplyIcon;
    }

    /** Returns true, if play icon should be shown, false otherwise */
    public boolean shouldShowPlayIcon() {
        return mShowPlayIcon;
    }

    /** Returns true, if unread theme should be used, false otherwise */
    public boolean shouldUseUnreadTheme() {
        return mUseUnreadTheme;
    }

    /** Returns the conversation object */
    @NonNull
    public Conversation getConversation() {
        return mConversation;
    }
}
