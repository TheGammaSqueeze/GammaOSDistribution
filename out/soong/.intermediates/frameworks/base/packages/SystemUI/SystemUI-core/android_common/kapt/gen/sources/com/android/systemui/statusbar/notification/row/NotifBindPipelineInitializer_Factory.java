package com.android.systemui.statusbar.notification.row;

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
public final class NotifBindPipelineInitializer_Factory implements Factory<NotifBindPipelineInitializer> {
  private final Provider<NotifBindPipeline> pipelineProvider;

  private final Provider<RowContentBindStage> stageProvider;

  public NotifBindPipelineInitializer_Factory(Provider<NotifBindPipeline> pipelineProvider,
      Provider<RowContentBindStage> stageProvider) {
    this.pipelineProvider = pipelineProvider;
    this.stageProvider = stageProvider;
  }

  @Override
  public NotifBindPipelineInitializer get() {
    return newInstance(pipelineProvider.get(), stageProvider.get());
  }

  public static NotifBindPipelineInitializer_Factory create(
      Provider<NotifBindPipeline> pipelineProvider, Provider<RowContentBindStage> stageProvider) {
    return new NotifBindPipelineInitializer_Factory(pipelineProvider, stageProvider);
  }

  public static NotifBindPipelineInitializer newInstance(NotifBindPipeline pipeline,
      RowContentBindStage stage) {
    return new NotifBindPipelineInitializer(pipeline, stage);
  }
}
