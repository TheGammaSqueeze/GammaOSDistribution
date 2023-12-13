package com.android.systemui.doze;

import com.android.systemui.classifier.FalsingCollector;
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
public final class DozeFalsingManagerAdapter_Factory implements Factory<DozeFalsingManagerAdapter> {
  private final Provider<FalsingCollector> falsingCollectorProvider;

  public DozeFalsingManagerAdapter_Factory(Provider<FalsingCollector> falsingCollectorProvider) {
    this.falsingCollectorProvider = falsingCollectorProvider;
  }

  @Override
  public DozeFalsingManagerAdapter get() {
    return newInstance(falsingCollectorProvider.get());
  }

  public static DozeFalsingManagerAdapter_Factory create(
      Provider<FalsingCollector> falsingCollectorProvider) {
    return new DozeFalsingManagerAdapter_Factory(falsingCollectorProvider);
  }

  public static DozeFalsingManagerAdapter newInstance(FalsingCollector falsingCollector) {
    return new DozeFalsingManagerAdapter(falsingCollector);
  }
}
