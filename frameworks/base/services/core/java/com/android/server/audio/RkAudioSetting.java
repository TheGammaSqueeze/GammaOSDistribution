package com.android.server.audio;

import android.os.RemoteException;

public class RkAudioSetting {
    private static native int nativeGetSelect(int device);
    private static native int nativeGetMode(int device);
    private static native int nativeGetFormat(int device, String format);

    private static native void nativeSetSelect(int device);
    private static native void nativeSetMode(int device, int mode);
    private static native void nativeSetFormat(int device, int close, String format);
    private static native void nativeupdataFormatForEdid();

    /**
    * @hide
    */
    public RkAudioSetting() {

    }

    /**
    * @hide
    */
    public int getSelect(int device) throws RemoteException {
        return nativeGetSelect(device);
    }

    /**
    * @hide
    */
    public void setSelect(int device) throws RemoteException {
        nativeSetSelect(device);
    }

    /**
    * @hide
    */
    public void updataFormatForEdid() throws RemoteException {
        nativeupdataFormatForEdid();
    }

    /**
    * @hide
    */
    public int getMode(int device) throws RemoteException {
        return nativeGetMode(device);
    }

    /**
    * @hide
    */
    public void setMode(int device, int mode) throws RemoteException {
        nativeSetMode(device, mode);
    }

    /**
    * @hide
    */
    public int getFormat(int device, String format) throws RemoteException {
        return nativeGetFormat(device, format);
    }

    /**
    * @hide
    */
    public void setFormat(int device, int close, String format) throws RemoteException {
        nativeSetFormat(device, close, format);
    }
}
