package com.android.systemui.statusbar.notification.row;

import android.content.Context;
import com.android.systemui.statusbar.policy.HeadsUpManager;
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
public final class ExpandableNotificationRowDragController_Factory implements Factory<ExpandableNotificationRowDragController> {
  private final Provider<Context> contextProvider;

  private final Provider<HeadsUpManager> headsUpManagerProvider;

  public ExpandableNotificationRowDragController_Factory(Provider<Context> contextProvider,
      Provider<HeadsUpManager> headsUpManagerProvider) {
    this.contextProvider = contextProvider;
    this.headsUpManagerProvider = headsUpManagerProvider;
  }

  @Override
  public ExpandableNotificationRowDragController get() {
    return newInstance(contextProvider.get(), headsUpManagerProvider.get());
  }

  public static ExpandableNotificationRowDragController_Factory create(
      Provider<Context> contextProvider, Provider<HeadsUpManager> headsUpManagerProvider) {
    return new ExpandableNotificationRowDragController_Factory(contextProvider, headsUpManagerProvider);
  }

  public static ExpandableNotificationRowDragController newInstance(Context context,
      HeadsUpManager headsUpManager) {
    return new ExpandableNotificationRowDragController(context, headsUpManager);
  }
}
