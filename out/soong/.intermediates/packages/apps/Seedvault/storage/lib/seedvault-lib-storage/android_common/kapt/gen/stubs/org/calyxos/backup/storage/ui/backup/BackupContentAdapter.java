package org.calyxos.backup.storage.ui.backup;

import android.provider.MediaStore;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;
import androidx.appcompat.widget.SwitchCompat;
import androidx.recyclerview.widget.RecyclerView;
import androidx.recyclerview.widget.RecyclerView.Adapter;
import org.calyxos.backup.storage.R;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000@\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\b\u0004\b\u0000\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u0001:\u0003\u0017\u0018\u0019B\r\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005J\b\u0010\t\u001a\u00020\nH\u0016J\u0010\u0010\u000b\u001a\u00020\n2\u0006\u0010\f\u001a\u00020\nH\u0016J\u0018\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u00022\u0006\u0010\f\u001a\u00020\nH\u0016J\u0018\u0010\u0010\u001a\u00020\u00022\u0006\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\nH\u0016J\u001b\u0010\u0014\u001a\u00020\u000e2\f\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0015H\u0000\u00a2\u0006\u0002\b\u0016R\u0014\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/ui/backup/BackupContentAdapter;", "Landroidx/recyclerview/widget/RecyclerView$Adapter;", "Lorg/calyxos/backup/storage/ui/backup/BackupContentAdapter$ViewHolder;", "listener", "Lorg/calyxos/backup/storage/ui/backup/ContentClickListener;", "(Lorg/calyxos/backup/storage/ui/backup/ContentClickListener;)V", "items", "Ljava/util/ArrayList;", "Lorg/calyxos/backup/storage/ui/backup/BackupContentItem;", "getItemCount", "", "getItemViewType", "position", "onBindViewHolder", "", "holder", "onCreateViewHolder", "parent", "Landroid/view/ViewGroup;", "viewType", "setItems", "", "setItems$main", "CustomHolder", "MediaHolder", "ViewHolder"})
public final class BackupContentAdapter extends androidx.recyclerview.widget.RecyclerView.Adapter<org.calyxos.backup.storage.ui.backup.BackupContentAdapter.ViewHolder> {
    private final java.util.ArrayList<org.calyxos.backup.storage.ui.backup.BackupContentItem> items = null;
    private final org.calyxos.backup.storage.ui.backup.ContentClickListener listener = null;
    
    @java.lang.Override()
    public int getItemViewType(int position) {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public org.calyxos.backup.storage.ui.backup.BackupContentAdapter.ViewHolder onCreateViewHolder(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup parent, int viewType) {
        return null;
    }
    
    @java.lang.Override()
    public void onBindViewHolder(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.ui.backup.BackupContentAdapter.ViewHolder holder, int position) {
    }
    
    @java.lang.Override()
    public int getItemCount() {
        return 0;
    }
    
    public final void setItems$main(@org.jetbrains.annotations.NotNull()
    java.util.List<org.calyxos.backup.storage.ui.backup.BackupContentItem> items) {
    }
    
    public BackupContentAdapter(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.ui.backup.ContentClickListener listener) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\b \u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0010\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u0010H\u0016R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0007\u001a\u00020\bX\u0084\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\nR\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/ui/backup/BackupContentAdapter$ViewHolder;", "Landroidx/recyclerview/widget/RecyclerView$ViewHolder;", "view", "Landroid/view/View;", "(Landroid/view/View;)V", "icon", "Landroid/widget/ImageView;", "layout", "Landroid/view/ViewGroup;", "getLayout", "()Landroid/view/ViewGroup;", "title", "Landroid/widget/TextView;", "bind", "", "item", "Lorg/calyxos/backup/storage/ui/backup/BackupContentItem;"})
    public static abstract class ViewHolder extends androidx.recyclerview.widget.RecyclerView.ViewHolder {
        @org.jetbrains.annotations.NotNull()
        private final android.view.ViewGroup layout = null;
        private final android.widget.ImageView icon = null;
        private final android.widget.TextView title = null;
        
        @org.jetbrains.annotations.NotNull()
        protected final android.view.ViewGroup getLayout() {
            return null;
        }
        
        public void bind(@org.jetbrains.annotations.NotNull()
        org.calyxos.backup.storage.ui.backup.BackupContentItem item) {
        }
        
        public ViewHolder(@org.jetbrains.annotations.NotNull()
        android.view.View view) {
            super(null);
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\"\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\b\u0080\u0004\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0010\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nH\u0016R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/ui/backup/BackupContentAdapter$MediaHolder;", "Lorg/calyxos/backup/storage/ui/backup/BackupContentAdapter$ViewHolder;", "view", "Landroid/view/View;", "(Lorg/calyxos/backup/storage/ui/backup/BackupContentAdapter;Landroid/view/View;)V", "switch", "Landroidx/appcompat/widget/SwitchCompat;", "bind", "", "item", "Lorg/calyxos/backup/storage/ui/backup/BackupContentItem;"})
    public final class MediaHolder extends org.calyxos.backup.storage.ui.backup.BackupContentAdapter.ViewHolder {
        
        @java.lang.Override()
        public void bind(@org.jetbrains.annotations.NotNull()
        org.calyxos.backup.storage.ui.backup.BackupContentItem item) {
        }
        
        public MediaHolder(@org.jetbrains.annotations.NotNull()
        android.view.View view) {
            super(null);
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\"\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\b\u0080\u0004\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0010\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nH\u0016R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/ui/backup/BackupContentAdapter$CustomHolder;", "Lorg/calyxos/backup/storage/ui/backup/BackupContentAdapter$ViewHolder;", "view", "Landroid/view/View;", "(Lorg/calyxos/backup/storage/ui/backup/BackupContentAdapter;Landroid/view/View;)V", "overflow", "Landroid/widget/ImageButton;", "bind", "", "item", "Lorg/calyxos/backup/storage/ui/backup/BackupContentItem;"})
    public final class CustomHolder extends org.calyxos.backup.storage.ui.backup.BackupContentAdapter.ViewHolder {
        private final android.widget.ImageButton overflow = null;
        
        @java.lang.Override()
        public void bind(@org.jetbrains.annotations.NotNull()
        org.calyxos.backup.storage.ui.backup.BackupContentItem item) {
        }
        
        public CustomHolder(@org.jetbrains.annotations.NotNull()
        android.view.View view) {
            super(null);
        }
    }
}