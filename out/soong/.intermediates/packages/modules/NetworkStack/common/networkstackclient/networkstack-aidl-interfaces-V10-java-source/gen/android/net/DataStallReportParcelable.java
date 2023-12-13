/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.net;
public class DataStallReportParcelable implements android.os.Parcelable
{
  public long timestampMillis = 0L;
  public int detectionMethod = 1;
  public int tcpPacketFailRate = 2;
  public int tcpMetricsCollectionPeriodMillis = 3;
  public int dnsConsecutiveTimeouts = 4;
  public static final android.os.Parcelable.Creator<DataStallReportParcelable> CREATOR = new android.os.Parcelable.Creator<DataStallReportParcelable>() {
    @Override
    public DataStallReportParcelable createFromParcel(android.os.Parcel _aidl_source) {
      DataStallReportParcelable _aidl_out = new DataStallReportParcelable();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public DataStallReportParcelable[] newArray(int _aidl_size) {
      return new DataStallReportParcelable[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeLong(timestampMillis);
    _aidl_parcel.writeInt(detectionMethod);
    _aidl_parcel.writeInt(tcpPacketFailRate);
    _aidl_parcel.writeInt(tcpMetricsCollectionPeriodMillis);
    _aidl_parcel.writeInt(dnsConsecutiveTimeouts);
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
      timestampMillis = _aidl_parcel.readLong();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      detectionMethod = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      tcpPacketFailRate = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      tcpMetricsCollectionPeriodMillis = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      dnsConsecutiveTimeouts = _aidl_parcel.readInt();
    } finally {
      if (_aidl_start_pos > (Integer.MAX_VALUE - _aidl_parcelable_size)) {
        throw new android.os.BadParcelableException("Overflow in the size of parcelable");
      }
      _aidl_parcel.setDataPosition(_aidl_start_pos + _aidl_parcelable_size);
    }
  }
  @Override
  public String toString() {
    java.util.StringJoiner _aidl_sj = new java.util.StringJoiner(", ", "{", "}");
    _aidl_sj.add("timestampMillis: " + (timestampMillis));
    _aidl_sj.add("detectionMethod: " + (detectionMethod));
    _aidl_sj.add("tcpPacketFailRate: " + (tcpPacketFailRate));
    _aidl_sj.add("tcpMetricsCollectionPeriodMillis: " + (tcpMetricsCollectionPeriodMillis));
    _aidl_sj.add("dnsConsecutiveTimeouts: " + (dnsConsecutiveTimeouts));
    return "android.net.DataStallReportParcelable" + _aidl_sj.toString()  ;
  }
  @Override
  public int describeContents() {
    int _mask = 0;
    return _mask;
  }
}
