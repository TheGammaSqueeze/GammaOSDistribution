package com.android.wm.shell.dagger;

import com.android.wm.shell.draganddrop.DragAndDrop;
import com.android.wm.shell.draganddrop.DragAndDropController;
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
public final class WMShellBaseModule_ProvideDragAndDropFactory implements Factory<DragAndDrop> {
  private final Provider<DragAndDropController> dragAndDropControllerProvider;

  public WMShellBaseModule_ProvideDragAndDropFactory(
      Provider<DragAndDropController> dragAndDropControllerProvider) {
    this.dragAndDropControllerProvider = dragAndDropControllerProvider;
  }

  @Override
  public DragAndDrop get() {
    return provideDragAndDrop(dragAndDropControllerProvider.get());
  }

  public static WMShellBaseModule_ProvideDragAndDropFactory create(
      Provider<DragAndDropController> dragAndDropControllerProvider) {
    return new WMShellBaseModule_ProvideDragAndDropFactory(dragAndDropControllerProvider);
  }

  public static DragAndDrop provideDragAndDrop(DragAndDropController dragAndDropController) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideDragAndDrop(dragAndDropController));
  }
}
