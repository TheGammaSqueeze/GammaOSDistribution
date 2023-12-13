/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.tv.tuner;
/**
 * FrontendInfo interface that carries tuner frontend information.
 *
 * <p>This is used to update the TunerResourceManager and pass Frontend
 * information from HAL to the client side.
 *
 * {@hide}
 */
public class TunerFrontendInfo implements android.os.Parcelable
{
  /**
       * Frontend Handle
       */
  public int handle = 0;
  /**
       * Frontend Type
       */
  public int type = 0;
  /**
       * Minimum Frequency in Hertz
       */
  public int minFrequency = 0;
  /**
       * Maximum Frequency in Hertz
       */
  public int maxFrequency = 0;
  /**
       * Minimum symbols per second
       */
  public int minSymbolRate = 0;
  /**
       * Maximum symbols per second
       */
  public int maxSymbolRate = 0;
  /**
       * Range in Hertz
       */
  public int acquireRange = 0;
  /**
       * Frontends are assigned with the same exclusiveGroupId if they can't
       * function at same time. For instance, they share same hardware module.
       */
  public int exclusiveGroupId = 0;
  /**
       * A list of supported status types which client can inquiry
       */
  public int[] statusCaps;
  /**
       * Frontend Capabilities
       */
  public android.media.tv.tuner.TunerFrontendCapabilities caps;
  public static final android.os.Parcelable.Creator<TunerFrontendInfo> CREATOR = new android.os.Parcelable.Creator<TunerFrontendInfo>() {
    @Override
    public TunerFrontendInfo createFromParcel(android.os.Parcel _aidl_source) {
      TunerFrontendInfo _aidl_out = new TunerFrontendInfo();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public TunerFrontendInfo[] newArray(int _aidl_size) {
      return new TunerFrontendInfo[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(handle);
    _aidl_parcel.writeInt(type);
    _aidl_parcel.writeInt(minFrequency);
    _aidl_parcel.writeInt(maxFrequency);
    _aidl_parcel.writeInt(minSymbolRate);
    _aidl_parcel.writeInt(maxSymbolRate);
    _aidl_parcel.writeInt(acquireRange);
    _aidl_parcel.writeInt(exclusiveGroupId);
    _aidl_parcel.writeIntArray(statusCaps);
    if ((caps!=null)) {
      _aidl_parcel.writeInt(1);
      caps.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    int _aidl_end_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.setDataPosition(_aidl_start_pos);
    _aidl_parcel.writeInt(_aidl_end_pos - _aidl_start_pos);
    _aidl_parcel.setDataPosition(_aidl_end_pos);
  }
  public final void readFromParcel(android.os.Parcel _aidl_parcel)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    int _aidl_parcelable_size = _aidl_parcel.readInt();
    try {
      if (_aidl_parcelable_size < 0) return;
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      handle = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      type = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      minFrequency = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      maxFrequency = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      minSymbolRate = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      maxSymbolRate = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      acquireRange = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      exclusiveGroupId = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      statusCaps = _aidl_parcel.createIntArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        caps = android.media.tv.tuner.TunerFrontendCapabilities.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        caps = null;
      }
    } finally {
      if (_aidl_start_pos > (Integer.MAX_VALUE - _aidl_parcelable_size)) {
        throw new android.os.BadParcelableException("Overflow in the size of parcelable");
      }
      _aidl_parcel.setDataPosition(_aidl_start_pos + _aidl_parcelable_size);
    }
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    _mask |= describeContents(caps);
    return _mask;
  }
  private int describeContents(Object _v) {
    if (_v == null) return 0;
    if (_v instanceof android.os.Parcelable) {
      return ((android.os.Parcelable) _v).describeContents();
    }
    return 0;
  }
}
