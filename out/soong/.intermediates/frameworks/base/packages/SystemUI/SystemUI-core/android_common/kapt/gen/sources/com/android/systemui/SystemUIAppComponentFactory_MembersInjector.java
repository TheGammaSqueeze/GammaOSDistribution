package com.android.systemui;

import com.android.systemui.dagger.ContextComponentHelper;
import dagger.MembersInjector;
import dagger.internal.InjectedFieldSignature;
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
public final class SystemUIAppComponentFactory_MembersInjector implements MembersInjector<SystemUIAppComponentFactory> {
  private final Provider<ContextComponentHelper> mComponentHelperProvider;

  public SystemUIAppComponentFactory_MembersInjector(
      Provider<ContextComponentHelper> mComponentHelperProvider) {
    this.mComponentHelperProvider = mComponentHelperProvider;
  }

  public static MembersInjector<SystemUIAppComponentFactory> create(
      Provider<ContextComponentHelper> mComponentHelperProvider) {
    return new SystemUIAppComponentFactory_MembersInjector(mComponentHelperProvider);
  }

  @Override
  public void injectMembers(SystemUIAppComponentFactory instance) {
    injectMComponentHelper(instance, mComponentHelperProvider.get());
  }

  @InjectedFieldSignature("com.android.systemui.SystemUIAppComponentFactory.mComponentHelper")
  public static void injectMComponentHelper(SystemUIAppComponentFactory instance,
      ContextComponentHelper mComponentHelper) {
    instance.mComponentHelper = mComponentHelper;
  }
}
