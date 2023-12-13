package com.android.systemui.statusbar.notification.collection.render;

import android.view.LayoutInflater;
import com.android.systemui.plugins.ActivityStarter;
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
public final class SectionHeaderNodeControllerImpl_Factory implements Factory<SectionHeaderNodeControllerImpl> {
  private final Provider<String> nodeLabelProvider;

  private final Provider<LayoutInflater> layoutInflaterProvider;

  private final Provider<Integer> headerTextResIdProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<String> clickIntentActionProvider;

  public SectionHeaderNodeControllerImpl_Factory(Provider<String> nodeLabelProvider,
      Provider<LayoutInflater> layoutInflaterProvider, Provider<Integer> headerTextResIdProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<String> clickIntentActionProvider) {
    this.nodeLabelProvider = nodeLabelProvider;
    this.layoutInflaterProvider = layoutInflaterProvider;
    this.headerTextResIdProvider = headerTextResIdProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.clickIntentActionProvider = clickIntentActionProvider;
  }

  @Override
  public SectionHeaderNodeControllerImpl get() {
    return newInstance(nodeLabelProvider.get(), layoutInflaterProvider.get(), headerTextResIdProvider.get(), activityStarterProvider.get(), clickIntentActionProvider.get());
  }

  public static SectionHeaderNodeControllerImpl_Factory create(Provider<String> nodeLabelProvider,
      Provider<LayoutInflater> layoutInflaterProvider, Provider<Integer> headerTextResIdProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<String> clickIntentActionProvider) {
    return new SectionHeaderNodeControllerImpl_Factory(nodeLabelProvider, layoutInflaterProvider, headerTextResIdProvider, activityStarterProvider, clickIntentActionProvider);
  }

  public static SectionHeaderNodeControllerImpl newInstance(String nodeLabel,
      LayoutInflater layoutInflater, int headerTextResId, ActivityStarter activityStarter,
      String clickIntentAction) {
    return new SectionHeaderNodeControllerImpl(nodeLabel, layoutInflater, headerTextResId, activityStarter, clickIntentAction);
  }
}
