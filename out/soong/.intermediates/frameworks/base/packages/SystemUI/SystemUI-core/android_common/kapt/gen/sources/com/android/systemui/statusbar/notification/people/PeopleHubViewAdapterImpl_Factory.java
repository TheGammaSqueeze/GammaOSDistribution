package com.android.systemui.statusbar.notification.people;

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
public final class PeopleHubViewAdapterImpl_Factory implements Factory<PeopleHubViewAdapterImpl> {
  private final Provider<DataSource<PeopleHubViewModelFactory>> dataSourceProvider;

  public PeopleHubViewAdapterImpl_Factory(
      Provider<DataSource<PeopleHubViewModelFactory>> dataSourceProvider) {
    this.dataSourceProvider = dataSourceProvider;
  }

  @Override
  public PeopleHubViewAdapterImpl get() {
    return newInstance(dataSourceProvider.get());
  }

  public static PeopleHubViewAdapterImpl_Factory create(
      Provider<DataSource<PeopleHubViewModelFactory>> dataSourceProvider) {
    return new PeopleHubViewAdapterImpl_Factory(dataSourceProvider);
  }

  public static PeopleHubViewAdapterImpl newInstance(
      DataSource<PeopleHubViewModelFactory> dataSource) {
    return new PeopleHubViewAdapterImpl(dataSource);
  }
}
