package com.android.systemui.statusbar.notification.people;

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
public final class PeopleHubViewModelFactoryDataSourceImpl_Factory implements Factory<PeopleHubViewModelFactoryDataSourceImpl> {
  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<DataSource<PeopleHubModel>> dataSourceProvider;

  public PeopleHubViewModelFactoryDataSourceImpl_Factory(
      Provider<ActivityStarter> activityStarterProvider,
      Provider<DataSource<PeopleHubModel>> dataSourceProvider) {
    this.activityStarterProvider = activityStarterProvider;
    this.dataSourceProvider = dataSourceProvider;
  }

  @Override
  public PeopleHubViewModelFactoryDataSourceImpl get() {
    return newInstance(activityStarterProvider.get(), dataSourceProvider.get());
  }

  public static PeopleHubViewModelFactoryDataSourceImpl_Factory create(
      Provider<ActivityStarter> activityStarterProvider,
      Provider<DataSource<PeopleHubModel>> dataSourceProvider) {
    return new PeopleHubViewModelFactoryDataSourceImpl_Factory(activityStarterProvider, dataSourceProvider);
  }

  public static PeopleHubViewModelFactoryDataSourceImpl newInstance(ActivityStarter activityStarter,
      DataSource<PeopleHubModel> dataSource) {
    return new PeopleHubViewModelFactoryDataSourceImpl(activityStarter, dataSource);
  }
}
