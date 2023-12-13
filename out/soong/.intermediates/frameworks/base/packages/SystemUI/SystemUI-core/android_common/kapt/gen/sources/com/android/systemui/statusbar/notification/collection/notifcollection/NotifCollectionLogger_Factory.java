package com.android.systemui.statusbar.notification.collection.notifcollection;

import com.android.systemui.log.LogBuffer;
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
public final class NotifCollectionLogger_Factory implements Factory<NotifCollectionLogger> {
  private final Provider<LogBuffer> bufferProvider;

  public NotifCollectionLogger_Factory(Provider<LogBuffer> bufferProvider) {
    this.bufferProvider = bufferProvider;
  }

  @Override
  public NotifCollectionLogger get() {
    return newInstance(bufferProvider.get());
  }

  public static NotifCollectionLogger_Factory create(Provider<LogBuffer> bufferProvider) {
    return new NotifCollectionLogger_Factory(bufferProvider);
  }

  public static NotifCollectionLogger newInstance(LogBuffer buffer) {
    return new NotifCollectionLogger(buffer);
  }
}
