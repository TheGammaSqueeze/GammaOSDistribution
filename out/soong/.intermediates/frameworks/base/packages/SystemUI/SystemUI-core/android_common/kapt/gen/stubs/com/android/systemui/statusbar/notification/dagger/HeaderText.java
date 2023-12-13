package com.android.systemui.statusbar.notification.dagger;

import android.annotation.StringRes;
import android.provider.Settings;
import com.android.systemui.R;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.statusbar.notification.collection.render.NodeController;
import com.android.systemui.statusbar.notification.collection.render.SectionHeaderController;
import com.android.systemui.statusbar.notification.collection.render.SectionHeaderNodeControllerImpl;
import dagger.Binds;
import dagger.BindsInstance;
import dagger.Module;
import dagger.Provides;
import dagger.Subcomponent;
import javax.inject.Provider;
import javax.inject.Qualifier;
import javax.inject.Scope;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\b\n\u0002\u0018\u0002\n\u0002\u0010\u001b\b\u0087\u0002\u0018\u00002\u00020\u0001B\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/dagger/HeaderText;", ""})
@java.lang.annotation.Retention(value = java.lang.annotation.RetentionPolicy.CLASS)
@kotlin.annotation.Retention(value = kotlin.annotation.AnnotationRetention.BINARY)
@javax.inject.Qualifier()
public abstract @interface HeaderText {
}