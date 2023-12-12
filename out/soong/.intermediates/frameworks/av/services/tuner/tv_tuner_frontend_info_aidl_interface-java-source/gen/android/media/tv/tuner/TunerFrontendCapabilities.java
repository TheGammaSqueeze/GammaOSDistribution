/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.tv.tuner;

/**
 * Frontend Capabilities interface.
 *
 * Use a group of vectors as the workaround for Union structure that is not fully supported
 * in AIDL currently.
 *
 * Client may use FrontendInfo.type as the discriminar to check the corresponding vector. If
 * the vector is not null, it contains valid value.
 *
 * {@hide}
 */
public final class TunerFrontendCapabilities implements android.os.Parcelable {
  // tags for union fields
  public final static int analogCaps = 0;  // android.media.tv.tuner.TunerFrontendAnalogCapabilities analogCaps;
  public final static int atscCaps = 1;  // android.media.tv.tuner.TunerFrontendAtscCapabilities atscCaps;
  public final static int atsc3Caps = 2;  // android.media.tv.tuner.TunerFrontendAtsc3Capabilities atsc3Caps;
  public final static int cableCaps = 3;  // android.media.tv.tuner.TunerFrontendCableCapabilities cableCaps;
  public final static int dvbsCaps = 4;  // android.media.tv.tuner.TunerFrontendDvbsCapabilities dvbsCaps;
  public final static int dvbtCaps = 5;  // android.media.tv.tuner.TunerFrontendDvbtCapabilities dvbtCaps;
  public final static int isdbsCaps = 6;  // android.media.tv.tuner.TunerFrontendIsdbsCapabilities isdbsCaps;
  public final static int isdbs3Caps = 7;  // android.media.tv.tuner.TunerFrontendIsdbs3Capabilities isdbs3Caps;
  public final static int isdbtCaps = 8;  // android.media.tv.tuner.TunerFrontendIsdbtCapabilities isdbtCaps;

  private int _tag;
  private Object _value;

  public TunerFrontendCapabilities() {
    android.media.tv.tuner.TunerFrontendAnalogCapabilities _value = null;
    this._tag = analogCaps;
    this._value = _value;
  }

  private TunerFrontendCapabilities(android.os.Parcel _aidl_parcel) {
    readFromParcel(_aidl_parcel);
  }

  private TunerFrontendCapabilities(int _tag, Object _value) {
    this._tag = _tag;
    this._value = _value;
  }

  public int getTag() {
    return _tag;
  }

  // android.media.tv.tuner.TunerFrontendAnalogCapabilities analogCaps;

  /**
       * Analog Frontend Capabilities
       */
  public static TunerFrontendCapabilities analogCaps(android.media.tv.tuner.TunerFrontendAnalogCapabilities _value) {
    return new TunerFrontendCapabilities(analogCaps, _value);
  }

  public android.media.tv.tuner.TunerFrontendAnalogCapabilities getAnalogCaps() {
    _assertTag(analogCaps);
    return (android.media.tv.tuner.TunerFrontendAnalogCapabilities) _value;
  }

  public void setAnalogCaps(android.media.tv.tuner.TunerFrontendAnalogCapabilities _value) {
    _set(analogCaps, _value);
  }

  // android.media.tv.tuner.TunerFrontendAtscCapabilities atscCaps;

  /**
       * ATSC Frontend Capabilities
       */
  public static TunerFrontendCapabilities atscCaps(android.media.tv.tuner.TunerFrontendAtscCapabilities _value) {
    return new TunerFrontendCapabilities(atscCaps, _value);
  }

  public android.media.tv.tuner.TunerFrontendAtscCapabilities getAtscCaps() {
    _assertTag(atscCaps);
    return (android.media.tv.tuner.TunerFrontendAtscCapabilities) _value;
  }

  public void setAtscCaps(android.media.tv.tuner.TunerFrontendAtscCapabilities _value) {
    _set(atscCaps, _value);
  }

  // android.media.tv.tuner.TunerFrontendAtsc3Capabilities atsc3Caps;

  /**
       * ATSC3 Frontend Capabilities
       */
  public static TunerFrontendCapabilities atsc3Caps(android.media.tv.tuner.TunerFrontendAtsc3Capabilities _value) {
    return new TunerFrontendCapabilities(atsc3Caps, _value);
  }

  public android.media.tv.tuner.TunerFrontendAtsc3Capabilities getAtsc3Caps() {
    _assertTag(atsc3Caps);
    return (android.media.tv.tuner.TunerFrontendAtsc3Capabilities) _value;
  }

  public void setAtsc3Caps(android.media.tv.tuner.TunerFrontendAtsc3Capabilities _value) {
    _set(atsc3Caps, _value);
  }

  // android.media.tv.tuner.TunerFrontendCableCapabilities cableCaps;

  /**
       * Cable Frontend Capabilities
       */
  public static TunerFrontendCapabilities cableCaps(android.media.tv.tuner.TunerFrontendCableCapabilities _value) {
    return new TunerFrontendCapabilities(cableCaps, _value);
  }

  public android.media.tv.tuner.TunerFrontendCableCapabilities getCableCaps() {
    _assertTag(cableCaps);
    return (android.media.tv.tuner.TunerFrontendCableCapabilities) _value;
  }

  public void setCableCaps(android.media.tv.tuner.TunerFrontendCableCapabilities _value) {
    _set(cableCaps, _value);
  }

  // android.media.tv.tuner.TunerFrontendDvbsCapabilities dvbsCaps;

  /**
       * DVBS Frontend Capabilities
       */
  public static TunerFrontendCapabilities dvbsCaps(android.media.tv.tuner.TunerFrontendDvbsCapabilities _value) {
    return new TunerFrontendCapabilities(dvbsCaps, _value);
  }

  public android.media.tv.tuner.TunerFrontendDvbsCapabilities getDvbsCaps() {
    _assertTag(dvbsCaps);
    return (android.media.tv.tuner.TunerFrontendDvbsCapabilities) _value;
  }

  public void setDvbsCaps(android.media.tv.tuner.TunerFrontendDvbsCapabilities _value) {
    _set(dvbsCaps, _value);
  }

  // android.media.tv.tuner.TunerFrontendDvbtCapabilities dvbtCaps;

  /**
       * DVBT Frontend Capabilities
       */
  public static TunerFrontendCapabilities dvbtCaps(android.media.tv.tuner.TunerFrontendDvbtCapabilities _value) {
    return new TunerFrontendCapabilities(dvbtCaps, _value);
  }

  public android.media.tv.tuner.TunerFrontendDvbtCapabilities getDvbtCaps() {
    _assertTag(dvbtCaps);
    return (android.media.tv.tuner.TunerFrontendDvbtCapabilities) _value;
  }

  public void setDvbtCaps(android.media.tv.tuner.TunerFrontendDvbtCapabilities _value) {
    _set(dvbtCaps, _value);
  }

  // android.media.tv.tuner.TunerFrontendIsdbsCapabilities isdbsCaps;

  /**
       * ISDB-S Frontend Capabilities
       */
  public static TunerFrontendCapabilities isdbsCaps(android.media.tv.tuner.TunerFrontendIsdbsCapabilities _value) {
    return new TunerFrontendCapabilities(isdbsCaps, _value);
  }

  public android.media.tv.tuner.TunerFrontendIsdbsCapabilities getIsdbsCaps() {
    _assertTag(isdbsCaps);
    return (android.media.tv.tuner.TunerFrontendIsdbsCapabilities) _value;
  }

  public void setIsdbsCaps(android.media.tv.tuner.TunerFrontendIsdbsCapabilities _value) {
    _set(isdbsCaps, _value);
  }

  // android.media.tv.tuner.TunerFrontendIsdbs3Capabilities isdbs3Caps;

  /**
       * ISDB-S3 Frontend Capabilities
       */
  public static TunerFrontendCapabilities isdbs3Caps(android.media.tv.tuner.TunerFrontendIsdbs3Capabilities _value) {
    return new TunerFrontendCapabilities(isdbs3Caps, _value);
  }

  public android.media.tv.tuner.TunerFrontendIsdbs3Capabilities getIsdbs3Caps() {
    _assertTag(isdbs3Caps);
    return (android.media.tv.tuner.TunerFrontendIsdbs3Capabilities) _value;
  }

  public void setIsdbs3Caps(android.media.tv.tuner.TunerFrontendIsdbs3Capabilities _value) {
    _set(isdbs3Caps, _value);
  }

  // android.media.tv.tuner.TunerFrontendIsdbtCapabilities isdbtCaps;

  /**
       * ISDB-T Frontend Capabilities
       */
  public static TunerFrontendCapabilities isdbtCaps(android.media.tv.tuner.TunerFrontendIsdbtCapabilities _value) {
    return new TunerFrontendCapabilities(isdbtCaps, _value);
  }

  public android.media.tv.tuner.TunerFrontendIsdbtCapabilities getIsdbtCaps() {
    _assertTag(isdbtCaps);
    return (android.media.tv.tuner.TunerFrontendIsdbtCapabilities) _value;
  }

  public void setIsdbtCaps(android.media.tv.tuner.TunerFrontendIsdbtCapabilities _value) {
    _set(isdbtCaps, _value);
  }

  public static final android.os.Parcelable.Creator<TunerFrontendCapabilities> CREATOR = new android.os.Parcelable.Creator<TunerFrontendCapabilities>() {
    @Override
    public TunerFrontendCapabilities createFromParcel(android.os.Parcel _aidl_source) {
      return new TunerFrontendCapabilities(_aidl_source);
    }
    @Override
    public TunerFrontendCapabilities[] newArray(int _aidl_size) {
      return new TunerFrontendCapabilities[_aidl_size];
    }
  };

  @Override
  public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag) {
    _aidl_parcel.writeInt(_tag);
    switch (_tag) {
    case analogCaps:
      if ((getAnalogCaps()!=null)) {
        _aidl_parcel.writeInt(1);
        getAnalogCaps().writeToParcel(_aidl_parcel, 0);
      }
      else {
        _aidl_parcel.writeInt(0);
      }
      break;
    case atscCaps:
      if ((getAtscCaps()!=null)) {
        _aidl_parcel.writeInt(1);
        getAtscCaps().writeToParcel(_aidl_parcel, 0);
      }
      else {
        _aidl_parcel.writeInt(0);
      }
      break;
    case atsc3Caps:
      if ((getAtsc3Caps()!=null)) {
        _aidl_parcel.writeInt(1);
        getAtsc3Caps().writeToParcel(_aidl_parcel, 0);
      }
      else {
        _aidl_parcel.writeInt(0);
      }
      break;
    case cableCaps:
      if ((getCableCaps()!=null)) {
        _aidl_parcel.writeInt(1);
        getCableCaps().writeToParcel(_aidl_parcel, 0);
      }
      else {
        _aidl_parcel.writeInt(0);
      }
      break;
    case dvbsCaps:
      if ((getDvbsCaps()!=null)) {
        _aidl_parcel.writeInt(1);
        getDvbsCaps().writeToParcel(_aidl_parcel, 0);
      }
      else {
        _aidl_parcel.writeInt(0);
      }
      break;
    case dvbtCaps:
      if ((getDvbtCaps()!=null)) {
        _aidl_parcel.writeInt(1);
        getDvbtCaps().writeToParcel(_aidl_parcel, 0);
      }
      else {
        _aidl_parcel.writeInt(0);
      }
      break;
    case isdbsCaps:
      if ((getIsdbsCaps()!=null)) {
        _aidl_parcel.writeInt(1);
        getIsdbsCaps().writeToParcel(_aidl_parcel, 0);
      }
      else {
        _aidl_parcel.writeInt(0);
      }
      break;
    case isdbs3Caps:
      if ((getIsdbs3Caps()!=null)) {
        _aidl_parcel.writeInt(1);
        getIsdbs3Caps().writeToParcel(_aidl_parcel, 0);
      }
      else {
        _aidl_parcel.writeInt(0);
      }
      break;
    case isdbtCaps:
      if ((getIsdbtCaps()!=null)) {
        _aidl_parcel.writeInt(1);
        getIsdbtCaps().writeToParcel(_aidl_parcel, 0);
      }
      else {
        _aidl_parcel.writeInt(0);
      }
      break;
    }
  }

  public void readFromParcel(android.os.Parcel _aidl_parcel) {
    int _aidl_tag;
    _aidl_tag = _aidl_parcel.readInt();
    switch (_aidl_tag) {
    case analogCaps: {
      android.media.tv.tuner.TunerFrontendAnalogCapabilities _aidl_value;
      if ((0!=_aidl_parcel.readInt())) {
        _aidl_value = android.media.tv.tuner.TunerFrontendAnalogCapabilities.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        _aidl_value = null;
      }
      _set(_aidl_tag, _aidl_value);
      return; }
    case atscCaps: {
      android.media.tv.tuner.TunerFrontendAtscCapabilities _aidl_value;
      if ((0!=_aidl_parcel.readInt())) {
        _aidl_value = android.media.tv.tuner.TunerFrontendAtscCapabilities.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        _aidl_value = null;
      }
      _set(_aidl_tag, _aidl_value);
      return; }
    case atsc3Caps: {
      android.media.tv.tuner.TunerFrontendAtsc3Capabilities _aidl_value;
      if ((0!=_aidl_parcel.readInt())) {
        _aidl_value = android.media.tv.tuner.TunerFrontendAtsc3Capabilities.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        _aidl_value = null;
      }
      _set(_aidl_tag, _aidl_value);
      return; }
    case cableCaps: {
      android.media.tv.tuner.TunerFrontendCableCapabilities _aidl_value;
      if ((0!=_aidl_parcel.readInt())) {
        _aidl_value = android.media.tv.tuner.TunerFrontendCableCapabilities.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        _aidl_value = null;
      }
      _set(_aidl_tag, _aidl_value);
      return; }
    case dvbsCaps: {
      android.media.tv.tuner.TunerFrontendDvbsCapabilities _aidl_value;
      if ((0!=_aidl_parcel.readInt())) {
        _aidl_value = android.media.tv.tuner.TunerFrontendDvbsCapabilities.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        _aidl_value = null;
      }
      _set(_aidl_tag, _aidl_value);
      return; }
    case dvbtCaps: {
      android.media.tv.tuner.TunerFrontendDvbtCapabilities _aidl_value;
      if ((0!=_aidl_parcel.readInt())) {
        _aidl_value = android.media.tv.tuner.TunerFrontendDvbtCapabilities.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        _aidl_value = null;
      }
      _set(_aidl_tag, _aidl_value);
      return; }
    case isdbsCaps: {
      android.media.tv.tuner.TunerFrontendIsdbsCapabilities _aidl_value;
      if ((0!=_aidl_parcel.readInt())) {
        _aidl_value = android.media.tv.tuner.TunerFrontendIsdbsCapabilities.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        _aidl_value = null;
      }
      _set(_aidl_tag, _aidl_value);
      return; }
    case isdbs3Caps: {
      android.media.tv.tuner.TunerFrontendIsdbs3Capabilities _aidl_value;
      if ((0!=_aidl_parcel.readInt())) {
        _aidl_value = android.media.tv.tuner.TunerFrontendIsdbs3Capabilities.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        _aidl_value = null;
      }
      _set(_aidl_tag, _aidl_value);
      return; }
    case isdbtCaps: {
      android.media.tv.tuner.TunerFrontendIsdbtCapabilities _aidl_value;
      if ((0!=_aidl_parcel.readInt())) {
        _aidl_value = android.media.tv.tuner.TunerFrontendIsdbtCapabilities.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        _aidl_value = null;
      }
      _set(_aidl_tag, _aidl_value);
      return; }
    }
    throw new IllegalArgumentException("union: unknown tag: " + _aidl_tag);
  }

  @Override
  public int describeContents() {
    int _mask = 0;
    switch (getTag()) {
    case analogCaps:
      _mask |= describeContents(getAnalogCaps());
      break;
    case atscCaps:
      _mask |= describeContents(getAtscCaps());
      break;
    case atsc3Caps:
      _mask |= describeContents(getAtsc3Caps());
      break;
    case cableCaps:
      _mask |= describeContents(getCableCaps());
      break;
    case dvbsCaps:
      _mask |= describeContents(getDvbsCaps());
      break;
    case dvbtCaps:
      _mask |= describeContents(getDvbtCaps());
      break;
    case isdbsCaps:
      _mask |= describeContents(getIsdbsCaps());
      break;
    case isdbs3Caps:
      _mask |= describeContents(getIsdbs3Caps());
      break;
    case isdbtCaps:
      _mask |= describeContents(getIsdbtCaps());
      break;
    }
    return _mask;
  }
  private int describeContents(Object _v) {
    if (_v == null) return 0;
    if (_v instanceof android.os.Parcelable) {
      return ((android.os.Parcelable) _v).describeContents();
    }
    return 0;
  }

  private void _assertTag(int tag) {
    if (getTag() != tag) {
      throw new IllegalStateException("bad access: " + _tagString(tag) + ", " + _tagString(getTag()) + " is available.");
    }
  }

  private String _tagString(int _tag) {
    switch (_tag) {
    case analogCaps: return "analogCaps";
    case atscCaps: return "atscCaps";
    case atsc3Caps: return "atsc3Caps";
    case cableCaps: return "cableCaps";
    case dvbsCaps: return "dvbsCaps";
    case dvbtCaps: return "dvbtCaps";
    case isdbsCaps: return "isdbsCaps";
    case isdbs3Caps: return "isdbs3Caps";
    case isdbtCaps: return "isdbtCaps";
    }
    throw new IllegalStateException("unknown field: " + _tag);
  }

  private void _set(int _tag, Object _value) {
    this._tag = _tag;
    this._value = _value;
  }
}
