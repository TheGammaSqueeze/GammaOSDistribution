package com.android.systemui.classifier;

import android.view.accessibility.AccessibilityManager;
import com.android.internal.logging.MetricsLogger;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import dagger.internal.Factory;
import java.util.Set;
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
public final class BrightLineFalsingManager_Factory implements Factory<BrightLineFalsingManager> {
  private final Provider<FalsingDataProvider> falsingDataProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<Set<FalsingClassifier>> classifiersProvider;

  private final Provider<SingleTapClassifier> singleTapClassifierProvider;

  private final Provider<DoubleTapClassifier> doubleTapClassifierProvider;

  private final Provider<HistoryTracker> historyTrackerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<AccessibilityManager> accessibilityManagerProvider;

  private final Provider<Boolean> testHarnessProvider;

  public BrightLineFalsingManager_Factory(Provider<FalsingDataProvider> falsingDataProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<Set<FalsingClassifier>> classifiersProvider,
      Provider<SingleTapClassifier> singleTapClassifierProvider,
      Provider<DoubleTapClassifier> doubleTapClassifierProvider,
      Provider<HistoryTracker> historyTrackerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<AccessibilityManager> accessibilityManagerProvider,
      Provider<Boolean> testHarnessProvider) {
    this.falsingDataProvider = falsingDataProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.classifiersProvider = classifiersProvider;
    this.singleTapClassifierProvider = singleTapClassifierProvider;
    this.doubleTapClassifierProvider = doubleTapClassifierProvider;
    this.historyTrackerProvider = historyTrackerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.accessibilityManagerProvider = accessibilityManagerProvider;
    this.testHarnessProvider = testHarnessProvider;
  }

  @Override
  public BrightLineFalsingManager get() {
    return newInstance(falsingDataProvider.get(), metricsLoggerProvider.get(), classifiersProvider.get(), singleTapClassifierProvider.get(), doubleTapClassifierProvider.get(), historyTrackerProvider.get(), keyguardStateControllerProvider.get(), accessibilityManagerProvider.get(), testHarnessProvider.get());
  }

  public static BrightLineFalsingManager_Factory create(
      Provider<FalsingDataProvider> falsingDataProvider,
      Provider<MetricsLogger> metricsLoggerProvider,
      Provider<Set<FalsingClassifier>> classifiersProvider,
      Provider<SingleTapClassifier> singleTapClassifierProvider,
      Provider<DoubleTapClassifier> doubleTapClassifierProvider,
      Provider<HistoryTracker> historyTrackerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<AccessibilityManager> accessibilityManagerProvider,
      Provider<Boolean> testHarnessProvider) {
    return new BrightLineFalsingManager_Factory(falsingDataProvider, metricsLoggerProvider, classifiersProvider, singleTapClassifierProvider, doubleTapClassifierProvider, historyTrackerProvider, keyguardStateControllerProvider, accessibilityManagerProvider, testHarnessProvider);
  }

  public static BrightLineFalsingManager newInstance(FalsingDataProvider falsingDataProvider,
      MetricsLogger metricsLogger, Set<FalsingClassifier> classifiers,
      SingleTapClassifier singleTapClassifier, DoubleTapClassifier doubleTapClassifier,
      HistoryTracker historyTracker, KeyguardStateController keyguardStateController,
      AccessibilityManager accessibilityManager, boolean testHarness) {
    return new BrightLineFalsingManager(falsingDataProvider, metricsLogger, classifiers, singleTapClassifier, doubleTapClassifier, historyTracker, keyguardStateController, accessibilityManager, testHarness);
  }
}
