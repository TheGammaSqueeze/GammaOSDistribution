package com.android.systemui.statusbar.notification.people;

import android.content.Context;
import android.database.ContentObserver;
import android.net.Uri;
import android.os.Handler;
import android.os.UserHandle;
import android.provider.Settings;
import android.view.View;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.plugins.ActivityStarter;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000:\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\b\u0007\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u0001B\u0019\b\u0007\u0012\b\b\u0001\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0007J\u0016\u0010\r\u001a\u00020\u000e2\f\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00020\u0010H\u0016J\u0016\u0010\u0011\u001a\u00020\u00122\f\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00020\u0010H\u0002R\u0016\u0010\b\u001a\n \n*\u0004\u0018\u00010\t0\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u000b\u001a\n \n*\u0004\u0018\u00010\f0\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/people/PeopleHubSettingChangeDataSourceImpl;", "Lcom/android/systemui/statusbar/notification/people/DataSource;", "", "handler", "Landroid/os/Handler;", "context", "Landroid/content/Context;", "(Landroid/os/Handler;Landroid/content/Context;)V", "contentResolver", "Landroid/content/ContentResolver;", "kotlin.jvm.PlatformType", "settingUri", "Landroid/net/Uri;", "registerListener", "Lcom/android/systemui/statusbar/notification/people/Subscription;", "listener", "Lcom/android/systemui/statusbar/notification/people/DataListener;", "updateListener", ""})
@com.android.systemui.dagger.SysUISingleton()
public final class PeopleHubSettingChangeDataSourceImpl implements com.android.systemui.statusbar.notification.people.DataSource<java.lang.Boolean> {
    private final android.net.Uri settingUri = null;
    private final android.content.ContentResolver contentResolver = null;
    private final android.os.Handler handler = null;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.statusbar.notification.people.Subscription registerListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.DataListener<? super java.lang.Boolean> listener) {
        return null;
    }
    
    private final void updateListener(com.android.systemui.statusbar.notification.people.DataListener<? super java.lang.Boolean> listener) {
    }
    
    @javax.inject.Inject()
    public PeopleHubSettingChangeDataSourceImpl(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    android.os.Handler handler, @org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
}