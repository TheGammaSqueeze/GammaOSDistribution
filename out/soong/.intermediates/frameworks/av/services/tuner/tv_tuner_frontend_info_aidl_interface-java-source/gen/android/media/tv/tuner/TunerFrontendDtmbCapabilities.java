/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.tv.tuner;
/**
 * DTMB Frontend Capabilities interface.
 *
 * {@hide}
 */
public class TunerFrontendDtmbCapabilities implements android.os.Parcelable
{
  public int transmissionModeCap = 0;
  public int bandwidthCap = 0;
  public int modulationCap = 0;
  public int codeRateCap = 0;
  public int guardIntervalCap = 0;
  public int interleaveModeCap = 0;
  public static final android.os.Parcelable.Creator<TunerFrontendDtmbCapabilities> CREATOR = new android.os.Parcelable.Creator<TunerFrontendDtmbCapabilities>() {
    @Override
    public TunerFrontendDtmbCapabilities createFromParcel(android.os.Parcel _aidl_source) {
      TunerFrontendDtmbCapabilities _aidl_out = new TunerFrontendDtmbCapabilities();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public TunerFrontendDtmbCapabilities[] newArray(int _aidl_size) {
      return new TunerFrontendDtmbCapabilities[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(transmissionModeCap);
    _aidl_parcel.writeInt(bandwidthCap);
    _aidl_parcel.writeInt(modulationCap);
    _aidl_parcel.writeInt(codeRateCap);
    _aidl_parcel.writeInt(guardIntervalCap);
    _aidl_parcel.writeInt(interleaveModeCap);
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
      modulationCap = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      codeRateCap = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      guardIntervalCap = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      interleaveModeCap = _aidl_parcel.readInt();
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
