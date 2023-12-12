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

package com.android.car.dialer.ui.common;

import android.Manifest;
import android.bluetooth.BluetoothDevice;
import android.content.Context;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.net.Uri;
import android.provider.ContactsContract;
import android.text.TextUtils;

import androidx.annotation.Nullable;
import androidx.annotation.WorkerThread;
import androidx.lifecycle.LiveData;
import androidx.lifecycle.MediatorLiveData;

import com.android.car.dialer.livedata.SharedPreferencesLiveData;
import com.android.car.dialer.ui.common.entity.ContactSortingInfo;
import com.android.car.telephony.common.AsyncEntityLoader;
import com.android.car.telephony.common.Contact;
import com.android.car.telephony.common.InMemoryPhoneBook;
import com.android.car.telephony.common.QueryParam;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

import javax.inject.Named;

import dagger.assisted.Assisted;
import dagger.assisted.AssistedFactory;
import dagger.assisted.AssistedInject;
import dagger.hilt.android.qualifiers.ApplicationContext;

/**
 * Represents a list of {@link Contact} based on the search query
 */
public class ContactResultsLiveData extends
        MediatorLiveData<List<ContactResultsLiveData.ContactResultListItem>> implements
        AsyncEntityLoader.EntityConverter<List<ContactResultsLiveData.ContactResultListItem>> {
    private static final String[] CONTACT_DETAILS_PROJECTION = {
            ContactsContract.CommonDataKinds.Phone._ID,
            ContactsContract.CommonDataKinds.Phone.LOOKUP_KEY,
            ContactsContract.CommonDataKinds.Phone.NUMBER,
    };
    private final Context mContext;
    private final SearchQueryParamProvider mSearchQueryParamProvider;
    private final AsyncEntityLoader<List<ContactResultListItem>> mAsyncEntityLoader;
    private final LiveData<BluetoothDevice> mCurrentHfpDeviceLiveData;
    private final LiveData<String> mSearchQueryLiveData;
    private final SharedPreferencesLiveData mSortOrderPreferenceLiveData;
    private String mSearchQuery;
    private boolean mShowOnlyOneEntry;

    /**
     * @param searchQueryLiveData         represents a list of strings that are used to query the
     *                                    data
     * @param contactListLiveData         represents contact list for current connected hfp device
     * @param sortOrderPreferenceLiveData has the information on how to order the acquired contacts.
     * @param showOnlyOneEntry            determines whether to show only entry per contact.
     */
    @AssistedInject
    public ContactResultsLiveData(
            @ApplicationContext Context context,
            LiveData<List<Contact>> contactListLiveData,
            @Named("Hfp") LiveData<BluetoothDevice> currentHfpDeviceLiveData,
            @Assisted LiveData<String> searchQueryLiveData,
            @Assisted SharedPreferencesLiveData sortOrderPreferenceLiveData,
            @Assisted boolean showOnlyOneEntry) {
        mContext = context;
        mShowOnlyOneEntry = showOnlyOneEntry;
        mCurrentHfpDeviceLiveData = currentHfpDeviceLiveData;
        mSearchQueryParamProvider = new SearchQueryParamProvider(searchQueryLiveData);
        mAsyncEntityLoader = new AsyncEntityLoader<>(context, mSearchQueryParamProvider, this,
                (loader, contactResultListItems) -> setValue(contactResultListItems));

        addSource(contactListLiveData, this::onContactsChange);

        mSearchQueryLiveData = searchQueryLiveData;
        addSource(mSearchQueryLiveData, this::onSearchQueryChanged);

        mSortOrderPreferenceLiveData = sortOrderPreferenceLiveData;
        addSource(mSortOrderPreferenceLiveData, this::onSortOrderChanged);
    }

    @Override
    protected void onActive() {
        super.onActive();
        mAsyncEntityLoader.startLoading();
    }

    @Override
    protected void onInactive() {
        super.onInactive();
        mAsyncEntityLoader.reset();
    }

    private void onContactsChange(List<Contact> contactList) {
        if (contactList == null || contactList.isEmpty()) {
            mAsyncEntityLoader.cancelLoad();
            setValue(Collections.emptyList());
        } else {
            onSearchQueryChanged(mSearchQueryLiveData.getValue());
        }
    }

    private void onSearchQueryChanged(String searchQuery) {
        mSearchQuery = searchQuery;
        if (TextUtils.isEmpty(searchQuery)) {
            mAsyncEntityLoader.cancelLoad();
            setValue(Collections.emptyList());
        } else {
            mAsyncEntityLoader.forceLoad();
        }
    }

    private void onSortOrderChanged(SharedPreferences unusedSharedPreferences) {
        List<ContactResultListItem> contactResults = getValue();
        sort(contactResults);
        setValue(contactResults == null ? Collections.emptyList() : contactResults);
    }

    @WorkerThread
    @Override
    public List<ContactResultListItem> convertToEntity(@Nullable Cursor cursor) {
        if (cursor == null) {
            return Collections.emptyList();
        }

        List<ContactResultListItem> contactResults = new ArrayList<>();

        BluetoothDevice currentHfpDevice = mCurrentHfpDeviceLiveData.getValue();
        String accountName = currentHfpDevice == null ? null : currentHfpDevice.getAddress();
        while (cursor.moveToNext()) {
            int lookupKeyColIdx = cursor.getColumnIndex(
                    ContactsContract.CommonDataKinds.Phone.LOOKUP_KEY);
            int numberIdx = cursor.getColumnIndex(ContactsContract.CommonDataKinds.Phone.NUMBER);
            String lookupKey = cursor.getString(lookupKeyColIdx);
            String number = cursor.getString(numberIdx);
            Contact contact = InMemoryPhoneBook.get().lookupContactByKey(lookupKey, accountName);
            if (contact != null) {
                contactResults.add(new ContactResultListItem(contact, number, mSearchQuery));
            }
        }

        if (mShowOnlyOneEntry) {
            Set<Contact> set = new HashSet<>();
            contactResults = contactResults.stream()
                    .filter(o -> set.add(o.getContact()))
                    .collect(Collectors.toList());
        }

        sort(contactResults);

        return contactResults;
    }

    private void sort(List<ContactResultListItem> contactResults) {
        if (contactResults != null) {
            Collections.sort(contactResults, (o1, o2) -> ContactSortingInfo.getSortingInfo(
                    mContext, mSortOrderPreferenceLiveData).first.compare(o1.mContact,
                    o2.mContact));
        }
    }

    private static class SearchQueryParamProvider implements QueryParam.Provider {
        private final LiveData<String> mSearchQueryLiveData;

        private SearchQueryParamProvider(LiveData<String> searchQueryLiveData) {
            mSearchQueryLiveData = searchQueryLiveData;
        }

        @Nullable
        @Override
        public QueryParam getQueryParam() {
            Uri lookupUri = Uri.withAppendedPath(
                    ContactsContract.CommonDataKinds.Phone.CONTENT_FILTER_URI,
                    Uri.encode(mSearchQueryLiveData.getValue()));
            return new QueryParam(lookupUri, CONTACT_DETAILS_PROJECTION, null,
                    /* selectionArgs= */null, /* orderBy= */null,
                    Manifest.permission.READ_CONTACTS);
        }
    }

    /**
     * Represent a contact search result.
     */
    public static class ContactResultListItem {
        private final Contact mContact;
        private final String mNumber;
        private final String mSearchQuery;

        public ContactResultListItem(Contact contact, String number, String searchQuery) {
            mContact = contact;
            mNumber = number;
            mSearchQuery = searchQuery;
        }

        /**
         * Returns the contact.
         */
        public Contact getContact() {
            return mContact;
        }

        /**
         * Returns the number. It is a string read from column
         * {@link ContactsContract.CommonDataKinds.Phone#NUMBER}.
         */
        public String getNumber() {
            return mNumber;
        }

        /**
         * Returns the search query that initiates the search.
         */
        public String getSearchQuery() {
            return mSearchQuery;
        }
    }

    /**
     * Factory to create {@link ContactResultsLiveData} instances via the {@link AssistedInject}
     * constructor.
     */
    @AssistedFactory
    public interface Factory {
        /** Creates a {@link ContactResultsLiveData} instance. */
        ContactResultsLiveData create(LiveData<String> searchQueryLiveData,
                SharedPreferencesLiveData sortOrderPreferenceLiveData,
                boolean showOnlyOneEntry);
    }
}
