package com.android.systemui.statusbar.notification.stack;

import android.annotation.ColorInt;
import android.content.Context;
import android.util.AttributeSet;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import com.android.systemui.R;
import com.android.systemui.plugins.statusbar.NotificationMenuRowPlugin;
import com.android.systemui.statusbar.notification.people.DataListener;
import com.android.systemui.statusbar.notification.people.PersonViewModel;
import com.android.systemui.statusbar.notification.row.StackScrollerDecorView;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000l\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u0007\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0003\u0018\u00002\u00020\u00012\u00020\u0002:\u00010B\u0015\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0007J\u0018\u0010\u001a\u001a\u00020\u001b2\u0006\u0010\u001c\u001a\u00020\u001d2\u0006\u0010\u001e\u001a\u00020\u001dH\u0014J\n\u0010\u001f\u001a\u0004\u0018\u00010 H\u0016J\b\u0010!\u001a\u00020\"H\u0014J\n\u0010#\u001a\u0004\u0018\u00010\"H\u0014J\b\u0010$\u001a\u00020\tH\u0016J\b\u0010%\u001a\u00020\tH\u0016J\b\u0010&\u001a\u00020\u001bH\u0014J\b\u0010\'\u001a\u00020\u001bH\u0016J\u000e\u0010(\u001a\u00020\u001b2\u0006\u0010)\u001a\u00020*J\u000e\u0010+\u001a\u00020\u001b2\u0006\u0010,\u001a\u00020-J\u0010\u0010.\u001a\u00020\u001b2\u0006\u0010/\u001a\u00020\u001dH\u0016R$\u0010\n\u001a\u00020\t2\u0006\u0010\b\u001a\u00020\t@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000b\u0010\f\"\u0004\b\r\u0010\u000eR\u000e\u0010\u000f\u001a\u00020\u0010X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082.\u00a2\u0006\u0002\n\u0000R:\u0010\u0017\u001a\u0010\u0012\f\u0012\n\u0012\u0006\u0012\u0004\u0018\u00010\u00160\u00150\u00142\u0014\u0010\u0013\u001a\u0010\u0012\f\u0012\n\u0012\u0006\u0012\u0004\u0018\u00010\u00160\u00150\u0014@BX\u0086.\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0018\u0010\u0019"}, d2 = {"Lcom/android/systemui/statusbar/notification/stack/PeopleHubView;", "Lcom/android/systemui/statusbar/notification/row/StackScrollerDecorView;", "Lcom/android/systemui/statusbar/notification/stack/SwipeableView;", "context", "Landroid/content/Context;", "attrs", "Landroid/util/AttributeSet;", "(Landroid/content/Context;Landroid/util/AttributeSet;)V", "value", "", "canSwipe", "getCanSwipe", "()Z", "setCanSwipe", "(Z)V", "contents", "Landroid/view/ViewGroup;", "label", "Landroid/widget/TextView;", "<set-?>", "Lkotlin/sequences/Sequence;", "Lcom/android/systemui/statusbar/notification/people/DataListener;", "Lcom/android/systemui/statusbar/notification/people/PersonViewModel;", "personViewAdapters", "getPersonViewAdapters", "()Lkotlin/sequences/Sequence;", "applyContentTransformation", "", "contentAlpha", "", "translationY", "createMenu", "Lcom/android/systemui/plugins/statusbar/NotificationMenuRowPlugin;", "findContentView", "Landroid/view/View;", "findSecondaryView", "hasFinishedInitialization", "needsClippingToShelf", "onFinishInflate", "resetTranslation", "setOnHeaderClickListener", "listener", "Landroid/view/View$OnClickListener;", "setTextColor", "color", "", "setTranslation", "translation", "PersonDataListenerImpl"})
public final class PeopleHubView extends com.android.systemui.statusbar.notification.row.StackScrollerDecorView implements com.android.systemui.statusbar.notification.stack.SwipeableView {
    private android.view.ViewGroup contents;
    private android.widget.TextView label;
    private kotlin.sequences.Sequence<? extends com.android.systemui.statusbar.notification.people.DataListener<? super com.android.systemui.statusbar.notification.people.PersonViewModel>> personViewAdapters;
    private boolean canSwipe = false;
    
    @org.jetbrains.annotations.NotNull()
    public final kotlin.sequences.Sequence<com.android.systemui.statusbar.notification.people.DataListener<com.android.systemui.statusbar.notification.people.PersonViewModel>> getPersonViewAdapters() {
        return null;
    }
    
    @java.lang.Override()
    protected void onFinishInflate() {
    }
    
    public final void setTextColor(@android.annotation.ColorInt()
    int color) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    protected android.view.View findContentView() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    protected android.view.View findSecondaryView() {
        return null;
    }
    
    @java.lang.Override()
    public boolean hasFinishedInitialization() {
        return false;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public com.android.systemui.plugins.statusbar.NotificationMenuRowPlugin createMenu() {
        return null;
    }
    
    @java.lang.Override()
    public void resetTranslation() {
    }
    
    @java.lang.Override()
    public void setTranslation(float translation) {
    }
    
    public final boolean getCanSwipe() {
        return false;
    }
    
    public final void setCanSwipe(boolean value) {
    }
    
    @java.lang.Override()
    public boolean needsClippingToShelf() {
        return false;
    }
    
    @java.lang.Override()
    protected void applyContentTransformation(float contentAlpha, float translationY) {
    }
    
    public final void setOnHeaderClickListener(@org.jetbrains.annotations.NotNull()
    android.view.View.OnClickListener listener) {
    }
    
    public PeopleHubView(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    android.util.AttributeSet attrs) {
        super(null, null);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u0002\n\u0000\b\u0082\u0004\u0018\u00002\n\u0012\u0006\u0012\u0004\u0018\u00010\u00020\u0001B\r\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005J\u0012\u0010\b\u001a\u00020\t2\b\u0010\n\u001a\u0004\u0018\u00010\u0002H\u0016R\u0011\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0006\u0010\u0007"}, d2 = {"Lcom/android/systemui/statusbar/notification/stack/PeopleHubView$PersonDataListenerImpl;", "Lcom/android/systemui/statusbar/notification/people/DataListener;", "Lcom/android/systemui/statusbar/notification/people/PersonViewModel;", "avatarView", "Landroid/widget/ImageView;", "(Lcom/android/systemui/statusbar/notification/stack/PeopleHubView;Landroid/widget/ImageView;)V", "getAvatarView", "()Landroid/widget/ImageView;", "onDataChanged", "", "data"})
    final class PersonDataListenerImpl implements com.android.systemui.statusbar.notification.people.DataListener<com.android.systemui.statusbar.notification.people.PersonViewModel> {
        @org.jetbrains.annotations.NotNull()
        private final android.widget.ImageView avatarView = null;
        
        @java.lang.Override()
        public void onDataChanged(@org.jetbrains.annotations.Nullable()
        com.android.systemui.statusbar.notification.people.PersonViewModel data) {
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.widget.ImageView getAvatarView() {
            return null;
        }
        
        public PersonDataListenerImpl(@org.jetbrains.annotations.NotNull()
        android.widget.ImageView avatarView) {
            super();
        }
    }
}