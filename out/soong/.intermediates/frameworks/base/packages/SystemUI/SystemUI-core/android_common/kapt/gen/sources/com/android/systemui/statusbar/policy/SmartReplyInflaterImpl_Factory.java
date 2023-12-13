package com.android.systemui.statusbar.policy;

import android.content.Context;
import com.android.systemui.statusbar.NotificationRemoteInputManager;
import com.android.systemui.statusbar.SmartReplyController;
import com.android.systemui.statusbar.phone.KeyguardDismissUtil;
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
public final class SmartReplyInflaterImpl_Factory implements Factory<SmartReplyInflaterImpl> {
  private final Provider<SmartReplyConstants> constantsProvider;

  private final Provider<KeyguardDismissUtil> keyguardDismissUtilProvider;

  private final Provider<NotificationRemoteInputManager> remoteInputManagerProvider;

  private final Provider<SmartReplyController> smartReplyControllerProvider;

  private final Provider<Context> contextProvider;

  public SmartReplyInflaterImpl_Factory(Provider<SmartReplyConstants> constantsProvider,
      Provider<KeyguardDismissUtil> keyguardDismissUtilProvider,
      Provider<NotificationRemoteInputManager> remoteInputManagerProvider,
      Provider<SmartReplyController> smartReplyControllerProvider,
      Provider<Context> contextProvider) {
    this.constantsProvider = constantsProvider;
    this.keyguardDismissUtilProvider = keyguardDismissUtilProvider;
    this.remoteInputManagerProvider = remoteInputManagerProvider;
    this.smartReplyControllerProvider = smartReplyControllerProvider;
    this.contextProvider = contextProvider;
  }

  @Override
  public SmartReplyInflaterImpl get() {
    return newInstance(constantsProvider.get(), keyguardDismissUtilProvider.get(), remoteInputManagerProvider.get(), smartReplyControllerProvider.get(), contextProvider.get());
  }

  public static SmartReplyInflaterImpl_Factory create(
      Provider<SmartReplyConstants> constantsProvider,
      Provider<KeyguardDismissUtil> keyguardDismissUtilProvider,
      Provider<NotificationRemoteInputManager> remoteInputManagerProvider,
      Provider<SmartReplyController> smartReplyControllerProvider,
      Provider<Context> contextProvider) {
    return new SmartReplyInflaterImpl_Factory(constantsProvider, keyguardDismissUtilProvider, remoteInputManagerProvider, smartReplyControllerProvider, contextProvider);
  }

  public static SmartReplyInflaterImpl newInstance(SmartReplyConstants constants,
      KeyguardDismissUtil keyguardDismissUtil, NotificationRemoteInputManager remoteInputManager,
      SmartReplyController smartReplyController, Context context) {
    return new SmartReplyInflaterImpl(constants, keyguardDismissUtil, remoteInputManager, smartReplyController, context);
  }
}
