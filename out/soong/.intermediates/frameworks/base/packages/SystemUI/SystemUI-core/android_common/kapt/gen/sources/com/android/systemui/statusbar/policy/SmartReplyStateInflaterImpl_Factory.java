package com.android.systemui.statusbar.policy;

import com.android.systemui.shared.system.ActivityManagerWrapper;
import com.android.systemui.shared.system.DevicePolicyManagerWrapper;
import com.android.systemui.shared.system.PackageManagerWrapper;
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
public final class SmartReplyStateInflaterImpl_Factory implements Factory<SmartReplyStateInflaterImpl> {
  private final Provider<SmartReplyConstants> constantsProvider;

  private final Provider<ActivityManagerWrapper> activityManagerWrapperProvider;

  private final Provider<PackageManagerWrapper> packageManagerWrapperProvider;

  private final Provider<DevicePolicyManagerWrapper> devicePolicyManagerWrapperProvider;

  private final Provider<SmartReplyInflater> smartRepliesInflaterProvider;

  private final Provider<SmartActionInflater> smartActionsInflaterProvider;

  public SmartReplyStateInflaterImpl_Factory(Provider<SmartReplyConstants> constantsProvider,
      Provider<ActivityManagerWrapper> activityManagerWrapperProvider,
      Provider<PackageManagerWrapper> packageManagerWrapperProvider,
      Provider<DevicePolicyManagerWrapper> devicePolicyManagerWrapperProvider,
      Provider<SmartReplyInflater> smartRepliesInflaterProvider,
      Provider<SmartActionInflater> smartActionsInflaterProvider) {
    this.constantsProvider = constantsProvider;
    this.activityManagerWrapperProvider = activityManagerWrapperProvider;
    this.packageManagerWrapperProvider = packageManagerWrapperProvider;
    this.devicePolicyManagerWrapperProvider = devicePolicyManagerWrapperProvider;
    this.smartRepliesInflaterProvider = smartRepliesInflaterProvider;
    this.smartActionsInflaterProvider = smartActionsInflaterProvider;
  }

  @Override
  public SmartReplyStateInflaterImpl get() {
    return newInstance(constantsProvider.get(), activityManagerWrapperProvider.get(), packageManagerWrapperProvider.get(), devicePolicyManagerWrapperProvider.get(), smartRepliesInflaterProvider.get(), smartActionsInflaterProvider.get());
  }

  public static SmartReplyStateInflaterImpl_Factory create(
      Provider<SmartReplyConstants> constantsProvider,
      Provider<ActivityManagerWrapper> activityManagerWrapperProvider,
      Provider<PackageManagerWrapper> packageManagerWrapperProvider,
      Provider<DevicePolicyManagerWrapper> devicePolicyManagerWrapperProvider,
      Provider<SmartReplyInflater> smartRepliesInflaterProvider,
      Provider<SmartActionInflater> smartActionsInflaterProvider) {
    return new SmartReplyStateInflaterImpl_Factory(constantsProvider, activityManagerWrapperProvider, packageManagerWrapperProvider, devicePolicyManagerWrapperProvider, smartRepliesInflaterProvider, smartActionsInflaterProvider);
  }

  public static SmartReplyStateInflaterImpl newInstance(SmartReplyConstants constants,
      ActivityManagerWrapper activityManagerWrapper, PackageManagerWrapper packageManagerWrapper,
      DevicePolicyManagerWrapper devicePolicyManagerWrapper,
      SmartReplyInflater smartRepliesInflater, SmartActionInflater smartActionsInflater) {
    return new SmartReplyStateInflaterImpl(constants, activityManagerWrapper, packageManagerWrapper, devicePolicyManagerWrapper, smartRepliesInflater, smartActionsInflater);
  }
}
