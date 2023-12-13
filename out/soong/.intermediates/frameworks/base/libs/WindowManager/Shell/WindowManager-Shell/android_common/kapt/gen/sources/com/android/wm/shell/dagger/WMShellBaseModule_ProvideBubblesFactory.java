package com.android.wm.shell.dagger;

import com.android.wm.shell.bubbles.BubbleController;
import com.android.wm.shell.bubbles.Bubbles;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import java.util.Optional;
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
public final class WMShellBaseModule_ProvideBubblesFactory implements Factory<Optional<Bubbles>> {
  private final Provider<Optional<BubbleController>> bubbleControllerProvider;

  public WMShellBaseModule_ProvideBubblesFactory(
      Provider<Optional<BubbleController>> bubbleControllerProvider) {
    this.bubbleControllerProvider = bubbleControllerProvider;
  }

  @Override
  public Optional<Bubbles> get() {
    return provideBubbles(bubbleControllerProvider.get());
  }

  public static WMShellBaseModule_ProvideBubblesFactory create(
      Provider<Optional<BubbleController>> bubbleControllerProvider) {
    return new WMShellBaseModule_ProvideBubblesFactory(bubbleControllerProvider);
  }

  public static Optional<Bubbles> provideBubbles(Optional<BubbleController> bubbleController) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideBubbles(bubbleController));
  }
}
