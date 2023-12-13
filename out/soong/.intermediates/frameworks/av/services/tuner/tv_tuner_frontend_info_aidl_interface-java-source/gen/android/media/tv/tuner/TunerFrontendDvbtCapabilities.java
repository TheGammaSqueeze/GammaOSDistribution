/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.tv.tuner;
/**
 * DVBT Frontend Capabilities interface.
 *
 * {@hide}
 */
public class TunerFrontendDvbtCapabilities implements android.os.Parcelable
{
  /**
       * Transmission Mode capability
       */
  public int transmissionModeCap = 0;
  /**
       * Bandwidth capability
       */
  public int bandwidthCap = 0;
  /**
       * Constellation capability
       */
  public int constellationCap = 0;
  /**
       * Code Rate capability
       */
  public int codeRateCap = 0;
  /**
       * Hierarchy Type capability
       */
  public int hierarchyCap = 0;
  /**
       * Guard Interval capability
       */
  public int guardIntervalCap = 0;
  /**
       * T2 Support capability
       */
  public boolean isT2Supported = false;
  /**
       * Miso Support capability
       */
  public boolean isMisoSupported = false;
  public static final android.os.Parcelable.Creator<TunerFrontendDvbtCapabilities> CREATOR = new android.os.Parcelable.Creator<TunerFrontendDvbtCapabilities>() {
    @Override
    public TunerFrontendDvbtCapabilities createFromParcel(android.os.Parcel _aidl_source) {
      TunerFrontendDvbtCapabilities _aidl_out = new TunerFrontendDvbtCapabilities();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public TunerFrontendDvbtCapabilities[] newArray(int _aidl_size) {
      return new TunerFrontendDvbtCapabilities[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(transmissionModeCap);
    _aidl_parcel.writeInt(bandwidthCap);
    _aidl_parcel.writeInt(constellationCap);
    _aidl_parcel.writeInt(codeRateCap);
    _aidl_parcel.writeInt(hierarchyCap);
    _aidl_parcel.writeInt(guardIntervalCap);
    _aidl_parcel.writeInt(((isT2Supported)?(1):(0)));
    _aidl_parcel.writeInt(((isMisoSupported)?(1):(0)));
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
      transmissionModeCap = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      bandwidthCap = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      constellationCap = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      codeRateCap = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      hierarchyCap = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      guardIntervalCap = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      isT2Supported = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      isMisoSupported = (0!=_aidl_parcel.readInt());
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
    return _mask;
  }
}
