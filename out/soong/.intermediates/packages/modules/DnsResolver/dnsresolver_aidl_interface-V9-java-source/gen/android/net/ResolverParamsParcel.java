/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
/** @hide */
public class ResolverParamsParcel implements android.os.Parcelable
{
  public int netId = 0;
  public int sampleValiditySeconds = 0;
  public int successThreshold = 0;
  public int minSamples = 0;
  public int maxSamples = 0;
  public int baseTimeoutMsec = 0;
  public int retryCount = 0;
  public java.lang.String[] servers;
  public java.lang.String[] domains;
  public java.lang.String tlsName;
  public java.lang.String[] tlsServers;
  public java.lang.String[] tlsFingerprints = {};
  public java.lang.String caCertificate = "";
  public int tlsConnectTimeoutMs = 0;
  public android.net.ResolverOptionsParcel resolverOptions;
  public int[] transportTypes = {};
  public static final android.os.Parcelable.Creator<ResolverParamsParcel> CREATOR = new android.os.Parcelable.Creator<ResolverParamsParcel>() {
    @Override
    public ResolverParamsParcel createFromParcel(android.os.Parcel _aidl_source) {
      ResolverParamsParcel _aidl_out = new ResolverParamsParcel();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public ResolverParamsParcel[] newArray(int _aidl_size) {
      return new ResolverParamsParcel[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(netId);
    _aidl_parcel.writeInt(sampleValiditySeconds);
    _aidl_parcel.writeInt(successThreshold);
    _aidl_parcel.writeInt(minSamples);
    _aidl_parcel.writeInt(maxSamples);
    _aidl_parcel.writeInt(baseTimeoutMsec);
    _aidl_parcel.writeInt(retryCount);
    _aidl_parcel.writeStringArray(servers);
    _aidl_parcel.writeStringArray(domains);
    _aidl_parcel.writeString(tlsName);
    _aidl_parcel.writeStringArray(tlsServers);
    _aidl_parcel.writeStringArray(tlsFingerprints);
    _aidl_parcel.writeString(caCertificate);
    _aidl_parcel.writeInt(tlsConnectTimeoutMs);
    if ((resolverOptions!=null)) {
      _aidl_parcel.writeInt(1);
      resolverOptions.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    _aidl_parcel.writeIntArray(transportTypes);
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
      netId = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      sampleValiditySeconds = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      successThreshold = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      minSamples = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      maxSamples = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      baseTimeoutMsec = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      retryCount = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      servers = _aidl_parcel.createStringArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      domains = _aidl_parcel.createStringArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      tlsName = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      tlsServers = _aidl_parcel.createStringArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      tlsFingerprints = _aidl_parcel.createStringArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      caCertificate = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      tlsConnectTimeoutMs = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        resolverOptions = android.net.ResolverOptionsParcel.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        resolverOptions = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      transportTypes = _aidl_parcel.createIntArray();
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
    _mask |= describeContents(resolverOptions);
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
