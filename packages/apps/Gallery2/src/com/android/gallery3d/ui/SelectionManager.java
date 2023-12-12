/*
 * Copyright (C) 2010 The Android Open Source Project
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

package com.android.gallery3d.ui;

import com.android.gallery3d.app.AbstractGalleryActivity;
import com.android.gallery3d.app.AlbumSetDataLoader;
import com.android.gallery3d.app.TimeLineDataLoader;
import com.android.gallery3d.data.ContentListener;
import com.android.gallery3d.data.DataManager;
import com.android.gallery3d.data.MediaItem;
import com.android.gallery3d.data.MediaObject;
import com.android.gallery3d.data.MediaSet;
import com.android.gallery3d.data.Path;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class SelectionManager implements TimeLineDataLoader.DataListener, AlbumSetDataLoader.DataListener{
    @SuppressWarnings("unused")
    private static final String TAG = "SelectionManager";

    public static final int ENTER_SELECTION_MODE = 1;
    public static final int LEAVE_SELECTION_MODE = 2;
    public static final int SELECT_ALL_MODE = 3;

    private Set<Path> mClickedSet;
    private MediaSet mSourceMediaSet;
    private SelectionListener mListener;
    private DataManager mDataManager;
    private boolean mInverseSelection;
    private boolean mIsAlbumSet;
    private boolean mInSelectionMode;
    private boolean mAutoLeave = true;
    private int mTotal;
    /** mTotalSelectable is the count of items
     * exclude not selectable such as Title item in TimeLine. */
    private int mTotalSelectable;
    private TimeLineDataLoader mTimeLineDataLoader;
    private AlbumSetDataLoader mAlbumSetDataLoader;

    @Override
    public void onContentChanged(int index) {
    }

    @Override
    public void onSizeChanged(int size) {
        if (mInverseSelection) {
            selectAll();
        }
    }

    @Override
    public void onSizeChanged() {
        if (mInverseSelection) {
            selectAll();
        }
    }

    public interface SelectionListener {
        public void onSelectionModeChange(int mode);
        public void onSelectionChange(Path path, boolean selected);
    }

    public SelectionManager(AbstractGalleryActivity activity, boolean isAlbumSet) {
        mDataManager = activity.getDataManager();
        mClickedSet = new HashSet<Path>();
        mIsAlbumSet = isAlbumSet;
        mTotal = -1;
        mTotalSelectable = -1;
    }

    // Whether we will leave selection mode automatically once the number of
    // selected items is down to zero.
    public void setAutoLeaveSelectionMode(boolean enable) {
        mAutoLeave = enable;
    }

    public void setSelectionListener(SelectionListener listener) {
        mListener = listener;
    }

    public void selectAll() {
        mInverseSelection = true;
        mClickedSet.clear();
        mTotal = -1;
        mTotalSelectable = -1;
        enterSelectionMode();
        if (mListener != null) mListener.onSelectionModeChange(SELECT_ALL_MODE);
    }

    public void deSelectAll() {
        leaveSelectionMode();
        mInverseSelection = false;
        mClickedSet.clear();
    }

    public boolean inSelectAllMode() {
        return mInverseSelection;
    }

    public boolean inSelectionMode() {
        return mInSelectionMode;
    }

    public void enterSelectionMode() {
        if (mInSelectionMode) return;

        mInSelectionMode = true;
        if (mListener != null) mListener.onSelectionModeChange(ENTER_SELECTION_MODE);
        if (mAlbumSetDataLoader != null) {
            mAlbumSetDataLoader.setModelListener(this);
        }
        if (mTimeLineDataLoader != null) {
            mTimeLineDataLoader.setDataListener(this);
        }
    }

    public void leaveSelectionMode() {
        if (!mInSelectionMode) return;

        mInSelectionMode = false;
        mInverseSelection = false;
        mClickedSet.clear();
        if (mListener != null) mListener.onSelectionModeChange(LEAVE_SELECTION_MODE);
        if (mAlbumSetDataLoader != null) {
            mAlbumSetDataLoader.removeModelListener(this);
        }
        if (mTimeLineDataLoader != null) {
            mTimeLineDataLoader.removeDataListener(this);
        }
    }

    public boolean isItemSelected(Path itemId) {
        return mInverseSelection ^ mClickedSet.contains(itemId);
    }

    private int getTotalCount() {
        if (mSourceMediaSet == null) return -1;

        if (mTotal < 0) {
            mTotal = mIsAlbumSet
                    ? mSourceMediaSet.getSubMediaSetCount()
                    : mSourceMediaSet.getMediaItemCount();
        }
        return mTotal;
    }

    /**
     * Some items is not selectable. such as Title item in TimeLine.
     *
     * @return total selectable count.
     */
    private int getTotalSelectableCount() {
        if (mSourceMediaSet == null) return -1;
        if (mTotalSelectable < 0) {
            mTotalSelectable = mIsAlbumSet
                    ? mSourceMediaSet.getSubMediaSetCount()
                    : mSourceMediaSet.getSelectableItemCount();
        }
        return mTotalSelectable;
    }

    public int getSelectedCount() {
        int count = mClickedSet.size();
        if (mInverseSelection) {
            count = getTotalSelectableCount() - count;
        }
        return count;
    }

    public void toggle(Path path) {
        if (mClickedSet.contains(path)) {
            mClickedSet.remove(path);
        } else {
            enterSelectionMode();
            mClickedSet.add(path);
        }

        // Convert to inverse selection mode if everything is selected.
        int count = getSelectedCount();
        if (count == getTotalCount()) {
            selectAll();
        }

        if (mListener != null) mListener.onSelectionChange(path, isItemSelected(path));
        if (count == 0 && mAutoLeave) {
            leaveSelectionMode();
        }
    }

    public void toggleTimeLineSet(ArrayList<Path> paths) {
        if (mClickedSet.containsAll(paths))
            mClickedSet.removeAll(paths);
        else {
            enterSelectionMode();
            mClickedSet.addAll(paths);
        }
        int count = getSelectedCount();
        if (count == (mSourceMediaSet.getMediaItemCount() - mSourceMediaSet.getSubMediaSetCount()))
            selectAll();
        if (mListener != null) mListener.onSelectionChange(paths.get(0), isItemSelected(paths.get(0)));
        if (count == 0 && mAutoLeave)
            leaveSelectionMode();
    }
    private static boolean expandMediaSet(ArrayList<Path> items, MediaSet set, int maxSelection) {
        int subCount = set.getSubMediaSetCount();
        for (int i = 0; i < subCount; i++) {
            if (!expandMediaSet(items, set.getSubMediaSet(i), maxSelection)) {
                return false;
            }
        }
        int total = set.getMediaItemCount();
        int batch = 50;
        int index = 0;

        while (index < total) {
            int count = index + batch < total
                    ? batch
                    : total - index;
            ArrayList<MediaItem> list = set.getMediaItem(index, count);
            if (list != null
                    && list.size() > (maxSelection - items.size())) {
                return false;
            }
            for (MediaItem item : list) {
                items.add(item.getPath());
            }
            index += batch;
        }
        return true;
    }

    public ArrayList<Path> getSelected(boolean expandSet) {
        return getSelected(expandSet, Integer.MAX_VALUE);
    }

    public ArrayList<Path> getSelected(boolean expandSet, int maxSelection) {
        ArrayList<Path> selected = new ArrayList<Path>();
        if (mIsAlbumSet) {
            if (mInverseSelection) {
                int total = getTotalCount();
                for (int i = 0; i < total; i++) {
                    MediaSet set = mSourceMediaSet.getSubMediaSet(i);
                    Path id = set.getPath();
                    if (!mClickedSet.contains(id)) {
                        if (expandSet) {
                            if (!expandMediaSet(selected, set, maxSelection)) {
                                return null;
                            }
                        } else {
                            addPathIfSelectable(selected, id);
                            if (selected.size() > maxSelection) {
                                return null;
                            }
                        }
                    }
                }
            } else {
                for (Path id : mClickedSet) {
                    if (expandSet) {
                        if (!expandMediaSet(selected, mDataManager.getMediaSet(id),
                                maxSelection)) {
                            return null;
                        }
                    } else {
                        addPathIfSelectable(selected, id);
                        if (selected.size() > maxSelection) {
                            return null;
                        }
                    }
                }
            }
        } else {
            if (mInverseSelection) {
                int total = getTotalCount();
                int index = 0;
                while (index < total) {
                    int count = Math.min(total - index, MediaSet.MEDIAITEM_BATCH_FETCH_COUNT);
                    ArrayList<MediaItem> list = mSourceMediaSet.getMediaItem(index, count);
                    for (MediaItem item : list) {
                        Path id = item.getPath();
                        if (!mClickedSet.contains(id)) {
                            addPathIfSelectable(selected, id);
                            if (selected.size() > maxSelection) {
                                return null;
                            }
                        }
                    }
                    index += count;
                }
            } else {
                for (Path id : mClickedSet) {
                    addPathIfSelectable(selected, id);
                    if (selected.size() > maxSelection) {
                        return null;
                    }
                }
            }
        }
        return selected;
    }

    private void addPathIfSelectable(ArrayList<Path> selected, Path path) {
        if (mDataManager != null) {
            MediaObject mediaObject = mDataManager.getMediaObject(path);
            if (mediaObject != null && mediaObject.isSelectable()) {
                selected.add(path);
            }
        }
    }

    public void setSourceMediaSet(MediaSet set) {
        mSourceMediaSet = set;
        mTotal = -1;
    }

    public void setTimeLineDataLoader(TimeLineDataLoader loader) {
        mTimeLineDataLoader = loader;
    }

    public void setAlbumSetDataLoader(AlbumSetDataLoader loader) {
        mAlbumSetDataLoader = loader;
    }
}
