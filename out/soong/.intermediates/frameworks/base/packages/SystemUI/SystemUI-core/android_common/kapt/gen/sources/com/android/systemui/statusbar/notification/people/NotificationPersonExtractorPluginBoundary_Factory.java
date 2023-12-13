package com.android.systemui.statusbar.notification.people;

import com.android.systemui.statusbar.policy.ExtensionController;
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
public final class NotificationPersonExtractorPluginBoundary_Factory implements Factory<NotificationPersonExtractorPluginBoundary> {
  private final Provider<ExtensionController> extensionControllerProvider;

  public NotificationPersonExtractorPluginBoundary_Factory(
      Provider<ExtensionController> extensionControllerProvider) {
    this.extensionControllerProvider = extensionControllerProvider;
  }

  @Override
  public NotificationPersonExtractorPluginBoundary get() {
    return newInstance(extensionControllerProvider.get());
  }

  public static NotificationPersonExtractorPluginBoundary_Factory create(
      Provider<ExtensionController> extensionControllerProvider) {
    return new NotificationPersonExtractorPluginBoundary_Factory(extensionControllerProvider);
  }

  public static NotificationPersonExtractorPluginBoundary newInstance(
      ExtensionController extensionController) {
    return new NotificationPersonExtractorPluginBoundary(extensionController);
  }
}
