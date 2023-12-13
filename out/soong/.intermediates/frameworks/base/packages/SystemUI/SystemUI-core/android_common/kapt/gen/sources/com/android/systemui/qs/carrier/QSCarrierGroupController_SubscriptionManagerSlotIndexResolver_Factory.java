package com.android.systemui.qs.carrier;

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
public final class QSCarrierGroupController_SubscriptionManagerSlotIndexResolver_Factory implements Factory<QSCarrierGroupController.SubscriptionManagerSlotIndexResolver> {
  @Override
  public QSCarrierGroupController.SubscriptionManagerSlotIndexResolver get() {
    return newInstance();
  }

  public static QSCarrierGroupController_SubscriptionManagerSlotIndexResolver_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static QSCarrierGroupController.SubscriptionManagerSlotIndexResolver newInstance() {
    return new QSCarrierGroupController.SubscriptionManagerSlotIndexResolver();
  }

  private static final class InstanceHolder {
    private static final QSCarrierGroupController_SubscriptionManagerSlotIndexResolver_Factory INSTANCE = new QSCarrierGroupController_SubscriptionManagerSlotIndexResolver_Factory();
  }
}
