/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.soundtrigger_middleware;
/**
 * A recognition confidence level.
 * This type is used to represent either a threshold or an actual detection confidence level.
 *
 * {@hide}
 */
public class ConfidenceLevel implements android.os.Parcelable
{
  /** user ID. */
  public int userId = 0;
  /**
       * Confidence level in percent (0 - 100).
       * <ul>
       * <li>Min level for recognition configuration
       * <li>Detected level for recognition event.
       * </ul>
       */
  public int levelPercent = 0;
  public static final android.os.Parcelable.Creator<ConfidenceLevel> CREATOR = new android.os.Parcelable.Creator<ConfidenceLevel>() {
    @Override
    public ConfidenceLevel createFromParcel(android.os.Parcel _aidl_source) {
      ConfidenceLevel _aidl_out = new ConfidenceLevel();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public ConfidenceLevel[] newArray(int _aidl_size) {
      return new ConfidenceLevel[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(userId);
    _aidl_parcel.writeInt(levelPercent);
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
      userId = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      levelPercent = _aidl_parcel.readInt();
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
