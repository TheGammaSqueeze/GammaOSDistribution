/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.system.keystore2;
/** @hide */
public class CreateOperationResponse implements android.os.Parcelable
{
  public android.system.keystore2.IKeystoreOperation iOperation;
  public android.system.keystore2.OperationChallenge operationChallenge;
  public android.system.keystore2.KeyParameters parameters;
  public byte[] upgradedBlob;
  @Override
   public final int getStability() { return android.os.Parcelable.PARCELABLE_STABILITY_VINTF; }
  public static final android.os.Parcelable.Creator<CreateOperationResponse> CREATOR = new android.os.Parcelable.Creator<CreateOperationResponse>() {
    @Override
    public CreateOperationResponse createFromParcel(android.os.Parcel _aidl_source) {
      CreateOperationResponse _aidl_out = new CreateOperationResponse();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public CreateOperationResponse[] newArray(int _aidl_size) {
      return new CreateOperationResponse[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeStrongBinder((((iOperation!=null))?(iOperation.asBinder()):(null)));
    if ((operationChallenge!=null)) {
      _aidl_parcel.writeInt(1);
      operationChallenge.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    if ((parameters!=null)) {
      _aidl_parcel.writeInt(1);
      parameters.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    _aidl_parcel.writeByteArray(upgradedBlob);
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
      iOperation = android.system.keystore2.IKeystoreOperation.Stub.asInterface(_aidl_parcel.readStrongBinder());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        operationChallenge = android.system.keystore2.OperationChallenge.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        operationChallenge = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        parameters = android.system.keystore2.KeyParameters.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        parameters = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      upgradedBlob = _aidl_parcel.createByteArray();
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
    _mask |= describeContents(operationChallenge);
    _mask |= describeContents(parameters);
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
