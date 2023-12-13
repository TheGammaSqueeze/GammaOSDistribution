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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\t\b\u00c7\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0012\u0010\u0003\u001a\u00020\u00042\b\b\u0001\u0010\u0005\u001a\u00020\u0006H\u0007J\u0012\u0010\u0007\u001a\u00020\b2\b\b\u0001\u0010\u0005\u001a\u00020\u0006H\u0007J\u0016\u0010\t\u001a\u00020\u00062\f\u0010\n\u001a\b\u0012\u0004\u0012\u00020\f0\u000bH\u0007J\u0012\u0010\r\u001a\u00020\u00042\b\b\u0001\u0010\u0005\u001a\u00020\u0006H\u0007J\u0012\u0010\u000e\u001a\u00020\b2\b\b\u0001\u0010\u0005\u001a\u00020\u0006H\u0007J\u0016\u0010\u000f\u001a\u00020\u00062\f\u0010\n\u001a\b\u0012\u0004\u0012\u00020\f0\u000bH\u0007J\u0012\u0010\u0010\u001a\u00020\u00042\b\b\u0001\u0010\u0005\u001a\u00020\u0006H\u0007J\u0012\u0010\u0011\u001a\u00020\b2\b\b\u0001\u0010\u0005\u001a\u00020\u0006H\u0007J\u0016\u0010\u0012\u001a\u00020\u00062\f\u0010\n\u001a\b\u0012\u0004\u0012\u00020\f0\u000bH\u0007J\u0012\u0010\u0013\u001a\u00020\u00042\b\b\u0001\u0010\u0005\u001a\u00020\u0006H\u0007J\u0012\u0010\u0014\u001a\u00020\b2\b\b\u0001\u0010\u0005\u001a\u00020\u0006H\u0007J\u0016\u0010\u0015\u001a\u00020\u00062\f\u0010\n\u001a\b\u0012\u0004\u0012\u00020\f0\u000bH\u0007"}, d2 = {"Lcom/android/systemui/statusbar/notification/dagger/NotificationSectionHeadersModule;", "", "()V", "providesAlertingHeaderController", "Lcom/android/systemui/statusbar/notification/collection/render/SectionHeaderController;", "subcomponent", "Lcom/android/systemui/statusbar/notification/dagger/SectionHeaderControllerSubcomponent;", "providesAlertingHeaderNodeController", "Lcom/android/systemui/statusbar/notification/collection/render/NodeController;", "providesAlertingHeaderSubcomponent", "builder", "Ljavax/inject/Provider;", "Lcom/android/systemui/statusbar/notification/dagger/SectionHeaderControllerSubcomponent$Builder;", "providesIncomingHeaderController", "providesIncomingHeaderNodeController", "providesIncomingHeaderSubcomponent", "providesPeopleHeaderController", "providesPeopleHeaderNodeController", "providesPeopleHeaderSubcomponent", "providesSilentHeaderController", "providesSilentHeaderNodeController", "providesSilentHeaderSubcomponent"})
@dagger.Module(subcomponents = {com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent.class})
public final class NotificationSectionHeadersModule {
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.notification.dagger.NotificationSectionHeadersModule INSTANCE = null;
    
    @org.jetbrains.annotations.NotNull()
    @IncomingHeader()
    @com.android.systemui.dagger.SysUISingleton()
    @dagger.Provides()
    public static final com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent providesIncomingHeaderSubcomponent(@org.jetbrains.annotations.NotNull()
    javax.inject.Provider<com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent.Builder> builder) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @AlertingHeader()
    @com.android.systemui.dagger.SysUISingleton()
    @dagger.Provides()
    public static final com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent providesAlertingHeaderSubcomponent(@org.jetbrains.annotations.NotNull()
    javax.inject.Provider<com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent.Builder> builder) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @PeopleHeader()
    @com.android.systemui.dagger.SysUISingleton()
    @dagger.Provides()
    public static final com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent providesPeopleHeaderSubcomponent(@org.jetbrains.annotations.NotNull()
    javax.inject.Provider<com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent.Builder> builder) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @SilentHeader()
    @com.android.systemui.dagger.SysUISingleton()
    @dagger.Provides()
    public static final com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent providesSilentHeaderSubcomponent(@org.jetbrains.annotations.NotNull()
    javax.inject.Provider<com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent.Builder> builder) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @SilentHeader()
    @dagger.Provides()
    public static final com.android.systemui.statusbar.notification.collection.render.NodeController providesSilentHeaderNodeController(@org.jetbrains.annotations.NotNull()
    @SilentHeader()
    com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent subcomponent) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @SilentHeader()
    @dagger.Provides()
    public static final com.android.systemui.statusbar.notification.collection.render.SectionHeaderController providesSilentHeaderController(@org.jetbrains.annotations.NotNull()
    @SilentHeader()
    com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent subcomponent) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @AlertingHeader()
    @dagger.Provides()
    public static final com.android.systemui.statusbar.notification.collection.render.NodeController providesAlertingHeaderNodeController(@org.jetbrains.annotations.NotNull()
    @AlertingHeader()
    com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent subcomponent) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @AlertingHeader()
    @dagger.Provides()
    public static final com.android.systemui.statusbar.notification.collection.render.SectionHeaderController providesAlertingHeaderController(@org.jetbrains.annotations.NotNull()
    @AlertingHeader()
    com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent subcomponent) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @PeopleHeader()
    @dagger.Provides()
    public static final com.android.systemui.statusbar.notification.collection.render.NodeController providesPeopleHeaderNodeController(@org.jetbrains.annotations.NotNull()
    @PeopleHeader()
    com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent subcomponent) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @PeopleHeader()
    @dagger.Provides()
    public static final com.android.systemui.statusbar.notification.collection.render.SectionHeaderController providesPeopleHeaderController(@org.jetbrains.annotations.NotNull()
    @PeopleHeader()
    com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent subcomponent) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @IncomingHeader()
    @dagger.Provides()
    public static final com.android.systemui.statusbar.notification.collection.render.NodeController providesIncomingHeaderNodeController(@org.jetbrains.annotations.NotNull()
    @IncomingHeader()
    com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent subcomponent) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @IncomingHeader()
    @dagger.Provides()
    public static final com.android.systemui.statusbar.notification.collection.render.SectionHeaderController providesIncomingHeaderController(@org.jetbrains.annotations.NotNull()
    @IncomingHeader()
    com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent subcomponent) {
        return null;
    }
    
    private NotificationSectionHeadersModule() {
        super();
    }
}