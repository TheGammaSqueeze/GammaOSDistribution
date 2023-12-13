/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media;
/**
 * The audio descriptor that descibes playback/capture capabilities according to
 * a particular standard.
 *
 * {@hide}
 */
public class ExtraAudioDescriptor implements android.os.Parcelable
{
  public int standard;
  public byte[] audioDescriptor;
  public int encapsulationType;
  public static final android.os.Parcelable.Creator<ExtraAudioDescriptor> CREATOR = new android.os.Parcelable.Creator<ExtraAudioDescriptor>() {
    @Override
    public ExtraAudioDescriptor createFromParcel(android.os.Parcel _aidl_source) {
      ExtraAudioDescriptor _aidl_out = new ExtraAudioDescriptor();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public ExtraAudioDescriptor[] newArray(int _aidl_size) {
      return new ExtraAudioDescriptor[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(standard);
    _aidl_parcel.writeByteArray(audioDescriptor);
    _aidl_parcel.writeInt(encapsulationType);
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
      standard = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      audioDescriptor = _aidl_parcel.createByteArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      encapsulationType = _aidl_parcel.readInt();
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
