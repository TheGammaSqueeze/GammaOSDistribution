package com.android.wm.shell.dagger;

import com.android.wm.shell.transition.ShellTransitions;
import com.android.wm.shell.transition.Transitions;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class WMShellBaseModule_ProvideRemoteTransitionsFactory implements Factory<ShellTransitions> {
  private final Provider<Transitions> transitionsProvider;

  public WMShellBaseModule_ProvideRemoteTransitionsFactory(
      Provider<Transitions> transitionsProvider) {
    this.transitionsProvider = transitionsProvider;
  }

  @Override
  public ShellTransitions get() {
    return provideRemoteTransitions(transitionsProvider.get());
  }

  public static WMShellBaseModule_ProvideRemoteTransitionsFactory create(
      Provider<Transitions> transitionsProvider) {
    return new WMShellBaseModule_ProvideRemoteTransitionsFactory(transitionsProvider);
  }

  public static ShellTransitions provideRemoteTransitions(Transitions transitions) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideRemoteTransitions(transitions));
  }
}
