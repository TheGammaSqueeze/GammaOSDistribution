package com.android.systemui.tv;

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
public final class TvSystemUIModule_ProvideLeakReportEmailFactory implements Factory<String> {
  @Override
  @Nullable
  public String get() {
    return provideLeakReportEmail();
  }

  public static TvSystemUIModule_ProvideLeakReportEmailFactory create() {
    return InstanceHolder.INSTANCE;
  }

  @Nullable
  public static String provideLeakReportEmail() {
    return TvSystemUIModule.provideLeakReportEmail();
  }

  private static final class InstanceHolder {
    private static final TvSystemUIModule_ProvideLeakReportEmailFactory INSTANCE = new TvSystemUIModule_ProvideLeakReportEmailFactory();
  }
}
