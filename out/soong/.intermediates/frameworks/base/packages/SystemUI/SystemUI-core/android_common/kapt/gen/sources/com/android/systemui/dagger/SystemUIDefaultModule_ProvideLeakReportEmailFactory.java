package com.android.systemui.dagger;

import androidx.annotation.Nullable;
import dagger.internal.Factory;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class SystemUIDefaultModule_ProvideLeakReportEmailFactory implements Factory<String> {
  @Override
  @Nullable
  public String get() {
    return provideLeakReportEmail();
  }

  public static SystemUIDefaultModule_ProvideLeakReportEmailFactory create() {
    return InstanceHolder.INSTANCE;
  }

  @Nullable
  public static String provideLeakReportEmail() {
    return SystemUIDefaultModule.provideLeakReportEmail();
  }

  private static final class InstanceHolder {
    private static final SystemUIDefaultModule_ProvideLeakReportEmailFactory INSTANCE = new SystemUIDefaultModule_ProvideLeakReportEmailFactory();
  }
}
