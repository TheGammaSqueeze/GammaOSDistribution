/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media;
/**
 * {@hide}
 */
public class MicrophoneInfoData implements android.os.Parcelable
{
  public java.lang.String deviceId;
  public int portId = 0;
  public int type = 0;
  public java.lang.String address;
  public int deviceLocation = 0;
  public int deviceGroup = 0;
  public int indexInTheGroup = 0;
  public float[] geometricLocation;
  public float[] orientation;
  public float[] frequencies;
  public float[] frequencyResponses;
  public int[] channelMapping;
  public float sensitivity = 0.000000f;
  public float maxSpl = 0.000000f;
  public float minSpl = 0.000000f;
  public int directionality = 0;
  public static final android.os.Parcelable.Creator<MicrophoneInfoData> CREATOR = new android.os.Parcelable.Creator<MicrophoneInfoData>() {
    @Override
    public MicrophoneInfoData createFromParcel(android.os.Parcel _aidl_source) {
      MicrophoneInfoData _aidl_out = new MicrophoneInfoData();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public MicrophoneInfoData[] newArray(int _aidl_size) {
      return new MicrophoneInfoData[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeString(deviceId);
    _aidl_parcel.writeInt(portId);
    _aidl_parcel.writeInt(type);
    _aidl_parcel.writeString(address);
    _aidl_parcel.writeInt(deviceLocation);
    _aidl_parcel.writeInt(deviceGroup);
    _aidl_parcel.writeInt(indexInTheGroup);
    _aidl_parcel.writeFloatArray(geometricLocation);
    _aidl_parcel.writeFloatArray(orientation);
    _aidl_parcel.writeFloatArray(frequencies);
    _aidl_parcel.writeFloatArray(frequencyResponses);
    _aidl_parcel.writeIntArray(channelMapping);
    _aidl_parcel.writeFloat(sensitivity);
    _aidl_parcel.writeFloat(maxSpl);
    _aidl_parcel.writeFloat(minSpl);
    _aidl_parcel.writeInt(directionality);
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
      deviceId = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      portId = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      type = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      address = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      deviceLocation = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      deviceGroup = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      indexInTheGroup = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      geometricLocation = _aidl_parcel.createFloatArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      orientation = _aidl_parcel.createFloatArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      frequencies = _aidl_parcel.createFloatArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      frequencyResponses = _aidl_parcel.createFloatArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      channelMapping = _aidl_parcel.createIntArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      sensitivity = _aidl_parcel.readFloat();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      maxSpl = _aidl_parcel.readFloat();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      minSpl = _aidl_parcel.readFloat();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      directionality = _aidl_parcel.readInt();
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
