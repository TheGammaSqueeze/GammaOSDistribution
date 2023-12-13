/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.hardware.biometrics.face;
public class SensorProps implements android.os.Parcelable
{
  public android.hardware.biometrics.common.CommonProps commonProps;
  public byte sensorType = android.hardware.biometrics.face.FaceSensorType.UNKNOWN;
  public boolean halControlsPreview = false;
  public int previewDisplayId = 0;
  public int enrollPreviewWidth = 0;
  public int enrollPreviewHeight = 0;
  public float enrollTranslationX = 0.000000f;
  public float enrollTranslationY = 0.000000f;
  public float enrollPreviewScale = 0.000000f;
  public boolean supportsDetectInteraction = false;
  @Override
   public final int getStability() { return android.os.Parcelable.PARCELABLE_STABILITY_VINTF; }
  public static final android.os.Parcelable.Creator<SensorProps> CREATOR = new android.os.Parcelable.Creator<SensorProps>() {
    @Override
    public SensorProps createFromParcel(android.os.Parcel _aidl_source) {
      SensorProps _aidl_out = new SensorProps();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public SensorProps[] newArray(int _aidl_size) {
      return new SensorProps[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    if ((commonProps!=null)) {
      _aidl_parcel.writeInt(1);
      commonProps.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    _aidl_parcel.writeByte(sensorType);
    _aidl_parcel.writeInt(((halControlsPreview)?(1):(0)));
    _aidl_parcel.writeInt(previewDisplayId);
    _aidl_parcel.writeInt(enrollPreviewWidth);
    _aidl_parcel.writeInt(enrollPreviewHeight);
    _aidl_parcel.writeFloat(enrollTranslationX);
    _aidl_parcel.writeFloat(enrollTranslationY);
    _aidl_parcel.writeFloat(enrollPreviewScale);
    _aidl_parcel.writeInt(((supportsDetectInteraction)?(1):(0)));
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
      if ((0!=_aidl_parcel.readInt())) {
        commonProps = android.hardware.biometrics.common.CommonProps.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        commonProps = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      sensorType = _aidl_parcel.readByte();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      halControlsPreview = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      previewDisplayId = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      enrollPreviewWidth = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      enrollPreviewHeight = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      enrollTranslationX = _aidl_parcel.readFloat();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      enrollTranslationY = _aidl_parcel.readFloat();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      enrollPreviewScale = _aidl_parcel.readFloat();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      supportsDetectInteraction = (0!=_aidl_parcel.readInt());
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
    _mask |= describeContents(commonProps);
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
