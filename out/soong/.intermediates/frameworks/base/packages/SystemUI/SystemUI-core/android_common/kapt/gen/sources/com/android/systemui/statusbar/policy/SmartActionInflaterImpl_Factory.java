package com.android.systemui.statusbar.policy;

import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.statusbar.SmartReplyController;
import dagger.internal.Factory;
import javax.annotation.processing.Generated;
import javax.inject.Provider;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class SmartActionInflaterImpl_Factory implements Factory<SmartActionInflaterImpl> {
  private final Provider<SmartReplyConstants> constantsProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<SmartReplyController> smartReplyControllerProvider;

  private final Provider<HeadsUpManager> headsUpManagerProvider;

  public SmartActionInflaterImpl_Factory(Provider<SmartReplyConstants> constantsProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<SmartReplyController> smartReplyControllerProvider,
      Provider<HeadsUpManager> headsUpManagerProvider) {
    this.constantsProvider = constantsProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.smartReplyControllerProvider = smartReplyControllerProvider;
    this.headsUpManagerProvider = headsUpManagerProvider;
  }

  @Override
  public SmartActionInflaterImpl get() {
    return newInstance(constantsProvider.get(), activityStarterProvider.get(), smartReplyControllerProvider.get(), headsUpManagerProvider.get());
  }

  public static SmartActionInflaterImpl_Factory create(
      Provider<SmartReplyConstants> constantsProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<SmartReplyController> smartReplyControllerProvider,
      Provider<HeadsUpManager> headsUpManagerProvider) {
    return new SmartActionInflaterImpl_Factory(constantsProvider, activityStarterProvider, smartReplyControllerProvider, headsUpManagerProvider);
  }

  public static SmartActionInflaterImpl newInstance(SmartReplyConstants constants,
      ActivityStarter activityStarter, SmartReplyController smartReplyController,
      HeadsUpManager headsUpManager) {
    return new SmartActionInflaterImpl(constants, activityStarter, smartReplyController, headsUpManager);
  }
}
