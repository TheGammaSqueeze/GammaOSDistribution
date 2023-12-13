/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net.netd.aidl;
/** @hide */
public class NativeUidRangeConfig implements android.os.Parcelable
{
  public final int netId;
  public final android.net.UidRangeParcel[] uidRanges;
  public final int subPriority;
  public static final class Builder
  {
    private int netId = 0;
    public Builder setNetId(int netId) {
      this.netId = netId;
      return this;
    }
    private android.net.UidRangeParcel[] uidRanges;
    public Builder setUidRanges(android.net.UidRangeParcel[] uidRanges) {
      this.uidRanges = uidRanges;
      return this;
    }
    private int subPriority = 0;
    public Builder setSubPriority(int subPriority) {
      this.subPriority = subPriority;
      return this;
    }
    public android.net.netd.aidl.NativeUidRangeConfig build() {
      return new android.net.netd.aidl.NativeUidRangeConfig(netId, uidRanges, subPriority);
    }
  }
  public static final android.os.Parcelable.Creator<NativeUidRangeConfig> CREATOR = new android.os.Parcelable.Creator<NativeUidRangeConfig>() {
    @Override
    public NativeUidRangeConfig createFromParcel(android.os.Parcel _aidl_source) {
      return internalCreateFromParcel(_aidl_source);
    }
    @Override
    public NativeUidRangeConfig[] newArray(int _aidl_size) {
      return new NativeUidRangeConfig[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(netId);
    _aidl_parcel.writeTypedArray(uidRanges, 0);
    _aidl_parcel.writeInt(subPriority);
    int _aidl_end_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.setDataPosition(_aidl_start_pos);
    _aidl_parcel.writeInt(_aidl_end_pos - _aidl_start_pos);
    _aidl_parcel.setDataPosition(_aidl_end_pos);
  }
  public NativeUidRangeConfig(int netId, android.net.UidRangeParcel[] uidRanges, int subPriority)
  {
    this.netId = netId;
    this.uidRanges = uidRanges;
    this.subPriority = subPriority;
  }
  private static NativeUidRangeConfig internalCreateFromParcel(android.os.Parcel _aidl_parcel)
  {
    Builder _aidl_parcelable_builder = new Builder();
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    int _aidl_parcelable_size = _aidl_parcel.readInt();
    try {
      if (_aidl_parcelable_size < 0) return _aidl_parcelable_builder.build();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return _aidl_parcelable_builder.build();
      int _aidl_temp_netId;
      _aidl_temp_netId = _aidl_parcel.readInt();
      _aidl_parcelable_builder.setNetId(_aidl_temp_netId);
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return _aidl_parcelable_builder.build();
      android.net.UidRangeParcel[] _aidl_temp_uidRanges;
      _aidl_temp_uidRanges = _aidl_parcel.createTypedArray(android.net.UidRangeParcel.CREATOR);
      _aidl_parcelable_builder.setUidRanges(_aidl_temp_uidRanges);
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return _aidl_parcelable_builder.build();
      int _aidl_temp_subPriority;
      _aidl_temp_subPriority = _aidl_parcel.readInt();
      _aidl_parcelable_builder.setSubPriority(_aidl_temp_subPriority);
    } finally {
      if (_aidl_start_pos > (Integer.MAX_VALUE - _aidl_parcelable_size)) {
        throw new android.os.BadParcelableException("Overflow in the size of parcelable");
      }
      _aidl_parcel.setDataPosition(_aidl_start_pos + _aidl_parcelable_size);
      return _aidl_parcelable_builder.build();
    }
  }
  @Override
  public String toString() {
    java.util.StringJoiner _aidl_sj = new java.util.StringJoiner(", ", "{", "}");
    _aidl_sj.add("netId: " + (netId));
    _aidl_sj.add("uidRanges: " + (java.util.Arrays.toString(uidRanges)));
    _aidl_sj.add("subPriority: " + (subPriority));
    return "android.net.netd.aidl.NativeUidRangeConfig" + _aidl_sj.toString()  ;
  }
  @Override
  public boolean equals(Object other) {
    if (this == other) return true;
    if (other == null) return false;
    if (!(other instanceof NativeUidRangeConfig)) return false;
    NativeUidRangeConfig that = (NativeUidRangeConfig)other;
    if (!java.util.Objects.deepEquals(netId, that.netId)) return false;
    if (!java.util.Objects.deepEquals(uidRanges, that.uidRanges)) return false;
    if (!java.util.Objects.deepEquals(subPriority, that.subPriority)) return false;
    return true;
  }

  @Override
  public int hashCode() {
    return java.util.Arrays.deepHashCode(java.util.Arrays.asList(netId, uidRanges, subPriority).toArray());
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    _mask |= describeContents(uidRanges);
    return _mask;
  }
  private int describeContents(Object _v) {
    if (_v == null) return 0;
    Class<?> _clazz = _v.getClass();
    if (_clazz.isArray() && _clazz.getComponentType() == Object.class) {
      int _mask = 0;
      for (Object o : (Object[]) _v) {
        _mask |= describeContents(o);
      }
      return _mask;
    }
    if (_v instanceof android.os.Parcelable) {
      return ((android.os.Parcelable) _v).describeContents();
    }
    return 0;
  }
}
