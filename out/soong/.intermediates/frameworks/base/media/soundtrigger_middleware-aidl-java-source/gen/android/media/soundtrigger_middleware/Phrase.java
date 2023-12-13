/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.soundtrigger_middleware;
/**
 * Key phrase descriptor.
 *
 * {@hide}
 */
public class Phrase implements android.os.Parcelable
{
  /** Unique keyphrase ID assigned at enrollment time. */
  public int id = 0;
  /** Recognition modes supported by this key phrase (bitfield of RecognitionMode enum). */
  public int recognitionModes = 0;
  /** List of users IDs associated with this key phrase. */
  public int[] users;
  /** Locale - Java Locale style (e.g. en_US). */
  public java.lang.String locale;
  /** Phrase text. */
  public java.lang.String text;
  public static final android.os.Parcelable.Creator<Phrase> CREATOR = new android.os.Parcelable.Creator<Phrase>() {
    @Override
    public Phrase createFromParcel(android.os.Parcel _aidl_source) {
      Phrase _aidl_out = new Phrase();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public Phrase[] newArray(int _aidl_size) {
      return new Phrase[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeInt(id);
    _aidl_parcel.writeInt(recognitionModes);
    _aidl_parcel.writeIntArray(users);
    _aidl_parcel.writeString(locale);
    _aidl_parcel.writeString(text);
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
      id = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      recognitionModes = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      users = _aidl_parcel.createIntArray();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      locale = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      text = _aidl_parcel.readString();
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
