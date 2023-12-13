/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
/** @hide */
public class UidRangeParcel implements android.os.Parcelable
{
  public final int start;
  public final int stop;
  public static final class Builder
  {
    private int start = 0;
    public Builder setStart(int start) {
      this.start = start;
      return this;
    }
    private int stop = 0;
    public Builder setStop(int stop) {
      this.stop = stop;
      return this;
    }
    public android.net.UidRangeParcel build() {
      return new android.net.UidRangeParcel(start, stop);
    }
  }
  public static final android.os.Parcelable.Creator<UidRangeParcel> CREATOR = new android.os.Parcelable.Creator<UidRangeParcel>() {
    @Override
    public UidRangeParcel createFromParcel(android.os.Parcel _aidl_source) {
      return internalCreateFromParcel(_aidl_source);
    }
    @Override
    public UidRangeParcel[] newArray(int _aidl_size) {
      return new UidRangeParcel[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(start);
    _aidl_parcel.writeInt(stop);
    int _aidl_end_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.setDataPosition(_aidl_start_pos);
    _aidl_parcel.writeInt(_aidl_end_pos - _aidl_start_pos);
    _aidl_parcel.setDataPosition(_aidl_end_pos);
  }
  public UidRangeParcel(int start, int stop)
  {
    this.start = start;
    this.stop = stop;
  }
  private static UidRangeParcel internalCreateFromParcel(android.os.Parcel _aidl_parcel)
  {
    Builder _aidl_parcelable_builder = new Builder();
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    int _aidl_parcelable_size = _aidl_parcel.readInt();
    try {
      if (_aidl_parcelable_size < 0) return _aidl_parcelable_builder.build();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return _aidl_parcelable_builder.build();
      int _aidl_temp_start;
      _aidl_temp_start = _aidl_parcel.readInt();
      _aidl_parcelable_builder.setStart(_aidl_temp_start);
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return _aidl_parcelable_builder.build();
      int _aidl_temp_stop;
      _aidl_temp_stop = _aidl_parcel.readInt();
      _aidl_parcelable_builder.setStop(_aidl_temp_stop);
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
    _aidl_sj.add("start: " + (start));
    _aidl_sj.add("stop: " + (stop));
    return "android.net.UidRangeParcel" + _aidl_sj.toString()  ;
  }
  @Override
  public boolean equals(Object other) {
    if (this == other) return true;
    if (other == null) return false;
    if (!(other instanceof UidRangeParcel)) return false;
    UidRangeParcel that = (UidRangeParcel)other;
    if (!java.util.Objects.deepEquals(start, that.start)) return false;
    if (!java.util.Objects.deepEquals(stop, that.stop)) return false;
    return true;
  }

  @Override
  public int hashCode() {
    return java.util.Arrays.deepHashCode(java.util.Arrays.asList(start, stop).toArray());
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    return _mask;
  }
}
