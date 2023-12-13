package com.android.systemui.statusbar.notification.collection.coalescer;

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
public final class GroupCoalescerLogger_Factory implements Factory<GroupCoalescerLogger> {
  private final Provider<LogBuffer> bufferProvider;

  public GroupCoalescerLogger_Factory(Provider<LogBuffer> bufferProvider) {
    this.bufferProvider = bufferProvider;
  }

  @Override
  public GroupCoalescerLogger get() {
    return newInstance(bufferProvider.get());
  }

  public static GroupCoalescerLogger_Factory create(Provider<LogBuffer> bufferProvider) {
    return new GroupCoalescerLogger_Factory(bufferProvider);
  }

  public static GroupCoalescerLogger newInstance(LogBuffer buffer) {
    return new GroupCoalescerLogger(buffer);
  }
}
