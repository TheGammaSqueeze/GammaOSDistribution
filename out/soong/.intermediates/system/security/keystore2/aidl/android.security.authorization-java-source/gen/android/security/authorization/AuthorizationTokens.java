/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.security.authorization;
/**
 * This parcelable is returned by `IKeystoreAuthorization::getAuthTokensForCredStore`.
 * @hide
 */
public class AuthorizationTokens implements android.os.Parcelable
{
  /**
       * HardwareAuthToken provided by an authenticator.
       */
  public android.hardware.security.keymint.HardwareAuthToken authToken;
  /**
       * TimeStampToken provided by a SecureClock.
       */
  public android.hardware.security.secureclock.TimeStampToken timestampToken;
  public static final android.os.Parcelable.Creator<AuthorizationTokens> CREATOR = new android.os.Parcelable.Creator<AuthorizationTokens>() {
    @Override
    public AuthorizationTokens createFromParcel(android.os.Parcel _aidl_source) {
      AuthorizationTokens _aidl_out = new AuthorizationTokens();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public AuthorizationTokens[] newArray(int _aidl_size) {
      return new AuthorizationTokens[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    if ((authToken!=null)) {
      _aidl_parcel.writeInt(1);
      authToken.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    if ((timestampToken!=null)) {
      _aidl_parcel.writeInt(1);
      timestampToken.writeToParcel(_aidl_parcel, 0);
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
      if ((0!=_aidl_parcel.readInt())) {
        authToken = android.hardware.security.keymint.HardwareAuthToken.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        authToken = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        timestampToken = android.hardware.security.secureclock.TimeStampToken.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        timestampToken = null;
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
    _mask |= describeContents(authToken);
    _mask |= describeContents(timestampToken);
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
