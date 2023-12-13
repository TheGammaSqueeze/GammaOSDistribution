package com.android.systemui.dump;

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
public final class SystemUIAuxiliaryDumpService_Factory implements Factory<SystemUIAuxiliaryDumpService> {
  private final Provider<DumpHandler> dumpHandlerProvider;

  public SystemUIAuxiliaryDumpService_Factory(Provider<DumpHandler> dumpHandlerProvider) {
    this.dumpHandlerProvider = dumpHandlerProvider;
  }

  @Override
  public SystemUIAuxiliaryDumpService get() {
    return newInstance(dumpHandlerProvider.get());
  }

  public static SystemUIAuxiliaryDumpService_Factory create(
      Provider<DumpHandler> dumpHandlerProvider) {
    return new SystemUIAuxiliaryDumpService_Factory(dumpHandlerProvider);
  }

  public static SystemUIAuxiliaryDumpService newInstance(DumpHandler dumpHandler) {
    return new SystemUIAuxiliaryDumpService(dumpHandler);
  }
}
