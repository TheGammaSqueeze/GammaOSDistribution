package com.android.systemui.controls.controller;

import android.service.controls.actions.ControlAction;
import android.service.controls.IControlsActionCallback;
import android.service.controls.IControlsProvider;
import android.service.controls.IControlsSubscriber;
import android.service.controls.IControlsSubscription;
import android.service.controls.actions.ControlActionWrapper;
import android.util.Log;

/**
 * Wrapper for the service calls.
 *
 * Calling all [IControlsProvider] methods through here will wrap them in a try/catch block.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000T\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0010 \n\u0000\u0018\u0000 \u001f2\u00020\u0001:\u0001\u001fB\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u001e\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\u0007\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\rJ\u0017\u0010\u000e\u001a\u00020\b2\f\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00110\u0010H\u0082\bJ\u000e\u0010\u0012\u001a\u00020\b2\u0006\u0010\u0013\u001a\u00020\u0014J\u000e\u0010\u0015\u001a\u00020\b2\u0006\u0010\u0016\u001a\u00020\u0017J\u000e\u0010\u0018\u001a\u00020\b2\u0006\u0010\u0016\u001a\u00020\u0017J\u0016\u0010\u0019\u001a\u00020\b2\u0006\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u001a\u001a\u00020\u001bJ\u001c\u0010\u001c\u001a\u00020\b2\f\u0010\u001d\u001a\b\u0012\u0004\u0012\u00020\n0\u001e2\u0006\u0010\u0016\u001a\u00020\u0017R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006"}, d2 = {"Lcom/android/systemui/controls/controller/ServiceWrapper;", "", "service", "Landroid/service/controls/IControlsProvider;", "(Landroid/service/controls/IControlsProvider;)V", "getService", "()Landroid/service/controls/IControlsProvider;", "action", "", "controlId", "", "Landroid/service/controls/actions/ControlAction;", "cb", "Landroid/service/controls/IControlsActionCallback;", "callThroughService", "block", "Lkotlin/Function0;", "", "cancel", "subscription", "Landroid/service/controls/IControlsSubscription;", "load", "subscriber", "Landroid/service/controls/IControlsSubscriber;", "loadSuggested", "request", "num", "", "subscribe", "controlIds", "", "Companion"})
public final class ServiceWrapper {
    @org.jetbrains.annotations.NotNull()
    private final android.service.controls.IControlsProvider service = null;
    private static final java.lang.String TAG = "ServiceWrapper";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.controller.ServiceWrapper.Companion Companion = null;
    
    private final boolean callThroughService(kotlin.jvm.functions.Function0<kotlin.Unit> block) {
        return false;
    }
    
    public final boolean load(@org.jetbrains.annotations.NotNull()
    android.service.controls.IControlsSubscriber subscriber) {
        return false;
    }
    
    public final boolean loadSuggested(@org.jetbrains.annotations.NotNull()
    android.service.controls.IControlsSubscriber subscriber) {
        return false;
    }
    
    public final boolean subscribe(@org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> controlIds, @org.jetbrains.annotations.NotNull()
    android.service.controls.IControlsSubscriber subscriber) {
        return false;
    }
    
    public final boolean request(@org.jetbrains.annotations.NotNull()
    android.service.controls.IControlsSubscription subscription, long num) {
        return false;
    }
    
    public final boolean cancel(@org.jetbrains.annotations.NotNull()
    android.service.controls.IControlsSubscription subscription) {
        return false;
    }
    
    public final boolean action(@org.jetbrains.annotations.NotNull()
    java.lang.String controlId, @org.jetbrains.annotations.NotNull()
    android.service.controls.actions.ControlAction action, @org.jetbrains.annotations.NotNull()
    android.service.controls.IControlsActionCallback cb) {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.service.controls.IControlsProvider getService() {
        return null;
    }
    
    public ServiceWrapper(@org.jetbrains.annotations.NotNull()
    android.service.controls.IControlsProvider service) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/controller/ServiceWrapper$Companion;", "", "()V", "TAG", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}