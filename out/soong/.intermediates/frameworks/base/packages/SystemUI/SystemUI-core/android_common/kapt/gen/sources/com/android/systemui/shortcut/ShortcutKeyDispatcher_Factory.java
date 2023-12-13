package com.android.systemui.shortcut;

import android.content.Context;
import com.android.wm.shell.legacysplitscreen.LegacySplitScreen;
import dagger.internal.Factory;
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
public final class ShortcutKeyDispatcher_Factory implements Factory<ShortcutKeyDispatcher> {
  private final Provider<Context> contextProvider;

  private final Provider<Optional<LegacySplitScreen>> splitScreenOptionalProvider;

  public ShortcutKeyDispatcher_Factory(Provider<Context> contextProvider,
      Provider<Optional<LegacySplitScreen>> splitScreenOptionalProvider) {
    this.contextProvider = contextProvider;
    this.splitScreenOptionalProvider = splitScreenOptionalProvider;
  }

  @Override
  public ShortcutKeyDispatcher get() {
    return newInstance(contextProvider.get(), splitScreenOptionalProvider.get());
  }

  public static ShortcutKeyDispatcher_Factory create(Provider<Context> contextProvider,
      Provider<Optional<LegacySplitScreen>> splitScreenOptionalProvider) {
    return new ShortcutKeyDispatcher_Factory(contextProvider, splitScreenOptionalProvider);
  }

  public static ShortcutKeyDispatcher newInstance(Context context,
      Optional<LegacySplitScreen> splitScreenOptional) {
    return new ShortcutKeyDispatcher(context, splitScreenOptional);
  }
}
