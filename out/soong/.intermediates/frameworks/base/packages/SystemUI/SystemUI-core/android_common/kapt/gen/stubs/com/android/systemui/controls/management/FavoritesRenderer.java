package com.android.systemui.controls.management;

import android.content.ComponentName;
import android.content.res.Resources;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import androidx.lifecycle.Lifecycle;
import androidx.lifecycle.LifecycleOwner;
import androidx.recyclerview.widget.RecyclerView;
import com.android.systemui.R;
import com.android.systemui.controls.ControlsServiceInfo;
import java.text.Collator;
import java.util.concurrent.Executor;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\u0018\u00002\u00020\u0001B!\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0012\u0010\u0004\u001a\u000e\u0012\u0004\u0012\u00020\u0006\u0012\u0004\u0012\u00020\u00070\u0005\u00a2\u0006\u0002\u0010\bJ\u0010\u0010\t\u001a\u0004\u0018\u00010\n2\u0006\u0010\u000b\u001a\u00020\u0006R\u001a\u0010\u0004\u001a\u000e\u0012\u0004\u0012\u00020\u0006\u0012\u0004\u0012\u00020\u00070\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/management/FavoritesRenderer;", "", "resources", "Landroid/content/res/Resources;", "favoriteFunction", "Lkotlin/Function1;", "Landroid/content/ComponentName;", "", "(Landroid/content/res/Resources;Lkotlin/jvm/functions/Function1;)V", "renderFavoritesForComponent", "", "component"})
public final class FavoritesRenderer {
    private final android.content.res.Resources resources = null;
    private final kotlin.jvm.functions.Function1<android.content.ComponentName, java.lang.Integer> favoriteFunction = null;
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String renderFavoritesForComponent(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName component) {
        return null;
    }
    
    public FavoritesRenderer(@org.jetbrains.annotations.NotNull()
    android.content.res.Resources resources, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super android.content.ComponentName, java.lang.Integer> favoriteFunction) {
        super();
    }
}