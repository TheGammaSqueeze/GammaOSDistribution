package com.android.systemui.log.dagger;

import android.content.ContentResolver;
import android.os.Looper;
import com.android.systemui.log.LogcatEchoTracker;
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
public final class LogModule_ProvideLogcatEchoTrackerFactory implements Factory<LogcatEchoTracker> {
  private final Provider<ContentResolver> contentResolverProvider;

  private final Provider<Looper> looperProvider;

  public LogModule_ProvideLogcatEchoTrackerFactory(
      Provider<ContentResolver> contentResolverProvider, Provider<Looper> looperProvider) {
    this.contentResolverProvider = contentResolverProvider;
    this.looperProvider = looperProvider;
  }

  @Override
  public LogcatEchoTracker get() {
    return provideLogcatEchoTracker(contentResolverProvider.get(), looperProvider.get());
  }

  public static LogModule_ProvideLogcatEchoTrackerFactory create(
      Provider<ContentResolver> contentResolverProvider, Provider<Looper> looperProvider) {
    return new LogModule_ProvideLogcatEchoTrackerFactory(contentResolverProvider, looperProvider);
  }

  public static LogcatEchoTracker provideLogcatEchoTracker(ContentResolver contentResolver,
      Looper looper) {
    return Preconditions.checkNotNullFromProvides(LogModule.provideLogcatEchoTracker(contentResolver, looper));
  }
}
