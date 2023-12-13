/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.tv.tuner;
/**
 * ATSC3 Frontend Capabilities interface.
 *
 * {@hide}
 */
public class TunerFrontendAtsc3Capabilities implements android.os.Parcelable
{
  /**
       * Bandwidth capability
       */
  public int bandwidthCap = 0;
  /**
       * Modulation capability
       */
  public int modulationCap = 0;
  /**
       * TimeInterleaveMode capability
       */
  public int timeInterleaveModeCap = 0;
  /**
       * CodeRate capability
       */
  public int codeRateCap = 0;
  /**
       * FEC capability
       */
  public int fecCap = 0;
  /**
       * Demodulator Output Format capability
       */
  public int demodOutputFormatCap = 0;
  public static final android.os.Parcelable.Creator<TunerFrontendAtsc3Capabilities> CREATOR = new android.os.Parcelable.Creator<TunerFrontendAtsc3Capabilities>() {
    @Override
    public TunerFrontendAtsc3Capabilities createFromParcel(android.os.Parcel _aidl_source) {
      TunerFrontendAtsc3Capabilities _aidl_out = new TunerFrontendAtsc3Capabilities();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public TunerFrontendAtsc3Capabilities[] newArray(int _aidl_size) {
      return new TunerFrontendAtsc3Capabilities[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(bandwidthCap);
    _aidl_parcel.writeInt(modulationCap);
    _aidl_parcel.writeInt(timeInterleaveModeCap);
    _aidl_parcel.writeInt(codeRateCap);
    _aidl_parcel.writeInt(fecCap);
    _aidl_parcel.writeInt(demodOutputFormatCap);
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
      bandwidthCap = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      modulationCap = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      timeInterleaveModeCap = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      codeRateCap = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      fecCap = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      demodOutputFormatCap = _aidl_parcel.readInt();
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
