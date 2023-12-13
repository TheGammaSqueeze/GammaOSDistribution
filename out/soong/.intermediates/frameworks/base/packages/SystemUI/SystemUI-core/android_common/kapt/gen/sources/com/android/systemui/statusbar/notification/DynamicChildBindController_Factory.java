package com.android.systemui.statusbar.notification;

import com.android.systemui.statusbar.notification.row.RowContentBindStage;
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
public final class DynamicChildBindController_Factory implements Factory<DynamicChildBindController> {
  private final Provider<RowContentBindStage> stageProvider;

  public DynamicChildBindController_Factory(Provider<RowContentBindStage> stageProvider) {
    this.stageProvider = stageProvider;
  }

  @Override
  public DynamicChildBindController get() {
    return newInstance(stageProvider.get());
  }

  public static DynamicChildBindController_Factory create(
      Provider<RowContentBindStage> stageProvider) {
    return new DynamicChildBindController_Factory(stageProvider);
  }

  public static DynamicChildBindController newInstance(RowContentBindStage stage) {
    return new DynamicChildBindController(stage);
  }
}
