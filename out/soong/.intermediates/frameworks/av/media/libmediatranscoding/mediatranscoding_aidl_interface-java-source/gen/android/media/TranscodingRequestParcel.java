/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media;
/**
 * TranscodingRequest contains the desired configuration for the transcoding.
 *
 * {@hide}
 *///TODO(hkuang): Implement the parcelable.
public class TranscodingRequestParcel implements android.os.Parcelable
{
  /**
       * The absolute file path of the source file.
       */
  public java.lang.String sourceFilePath;
  /**
       * The filedescrptor of the sourceFilePath. If the source Fd is provided, transcoding service
       * will use this fd instead of calling back to client side to open the sourceFilePath. It is
       * client's responsibility to make sure sourceFd is opened from sourceFilePath.
       */
  public android.os.ParcelFileDescriptor sourceFd;
  /**
       * The absolute file path of the destination file.
       */
  public java.lang.String destinationFilePath;
  /**
       * The filedescrptor of the destinationFilePath. If the destination Fd is provided, transcoding
       * service will use this fd instead of calling back to client side to open the
       * destinationFilePath. It is client's responsibility to make sure destinationFd is opened
       * from destinationFilePath.
       */
  public android.os.ParcelFileDescriptor destinationFd;
  /**
       * The UID of the client that this transcoding request is for. Only privileged caller could
       * set this Uid as only they could do the transcoding on behalf of the client.
       * -1 means not available.
       */
  public int clientUid = -1;
  /**
       * The PID of the client that this transcoding request is for. Only privileged caller could
       * set this Uid as only they could do the transcoding on behalf of the client.
       * -1 means not available.
       */
  public int clientPid = -1;
  /**
       * The package name of the client whom this transcoding request is for.
       */
  public java.lang.String clientPackageName;
  /**
       * Type of the transcoding.
       */
  public int transcodingType;
  /**
       * Requested video track format for the transcoding.
       * Note that the transcoding service will try to fulfill the requested format as much as
       * possbile, while subject to hardware and software limitation. The final video track format
       * will be available in the TranscodingSessionParcel when the session is finished.
       */
  public android.media.TranscodingVideoTrackFormat requestedVideoTrackFormat;
  /**
       * Priority of this transcoding. Service will schedule the transcoding based on the priority.
       */
  public int priority;
  /**
       * Whether to receive update on progress and change of awaitNumSessions.
       * Default to false.
       */
  public boolean requestProgressUpdate = false;
  /**
       * Whether to receive update on session's start/stop/pause/resume.
       * Default to false.
       */
  public boolean requestSessionEventUpdate = false;
  /**
       * Whether this request is for testing.
       */
  public boolean isForTesting = false;
  /**
       * Test configuration. This will be available only when isForTesting is set to true.
       */
  public android.media.TranscodingTestConfig testConfig;
  /**
        * Whether to get the stats of the transcoding.
        * If this is enabled, the TranscodingSessionStats will be returned in TranscodingResultParcel
        * upon transcoding finishes.
        */
  public boolean enableStats = false;
  public static final android.os.Parcelable.Creator<TranscodingRequestParcel> CREATOR = new android.os.Parcelable.Creator<TranscodingRequestParcel>() {
    @Override
    public TranscodingRequestParcel createFromParcel(android.os.Parcel _aidl_source) {
      TranscodingRequestParcel _aidl_out = new TranscodingRequestParcel();
      _aidl_out.readFromParcel(_aidl_source);
      return _aidl_out;
    }
    @Override
    public TranscodingRequestParcel[] newArray(int _aidl_size) {
      return new TranscodingRequestParcel[_aidl_size];
    }
  };
  @Override public final void writeToParcel(android.os.Parcel _aidl_parcel, int _aidl_flag)
  {
    int _aidl_start_pos = _aidl_parcel.dataPosition();
    _aidl_parcel.writeInt(0);
    _aidl_parcel.writeString(sourceFilePath);
    if ((sourceFd!=null)) {
      _aidl_parcel.writeInt(1);
      sourceFd.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    _aidl_parcel.writeString(destinationFilePath);
    if ((destinationFd!=null)) {
      _aidl_parcel.writeInt(1);
      destinationFd.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    _aidl_parcel.writeInt(clientUid);
    _aidl_parcel.writeInt(clientPid);
    _aidl_parcel.writeString(clientPackageName);
    _aidl_parcel.writeInt(transcodingType);
    if ((requestedVideoTrackFormat!=null)) {
      _aidl_parcel.writeInt(1);
      requestedVideoTrackFormat.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    _aidl_parcel.writeInt(priority);
    _aidl_parcel.writeInt(((requestProgressUpdate)?(1):(0)));
    _aidl_parcel.writeInt(((requestSessionEventUpdate)?(1):(0)));
    _aidl_parcel.writeInt(((isForTesting)?(1):(0)));
    if ((testConfig!=null)) {
      _aidl_parcel.writeInt(1);
      testConfig.writeToParcel(_aidl_parcel, 0);
    }
    else {
      _aidl_parcel.writeInt(0);
    }
    _aidl_parcel.writeInt(((enableStats)?(1):(0)));
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
      sourceFilePath = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        sourceFd = android.os.ParcelFileDescriptor.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        sourceFd = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      destinationFilePath = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        destinationFd = android.os.ParcelFileDescriptor.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        destinationFd = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      clientUid = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      clientPid = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      clientPackageName = _aidl_parcel.readString();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      transcodingType = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        requestedVideoTrackFormat = android.media.TranscodingVideoTrackFormat.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        requestedVideoTrackFormat = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      priority = _aidl_parcel.readInt();
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      requestProgressUpdate = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      requestSessionEventUpdate = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      isForTesting = (0!=_aidl_parcel.readInt());
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      if ((0!=_aidl_parcel.readInt())) {
        testConfig = android.media.TranscodingTestConfig.CREATOR.createFromParcel(_aidl_parcel);
      }
      else {
        testConfig = null;
      }
      if (_aidl_parcel.dataPosition() - _aidl_start_pos >= _aidl_parcelable_size) return;
      enableStats = (0!=_aidl_parcel.readInt());
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
    _mask |= describeContents(sourceFd);
    _mask |= describeContents(destinationFd);
    _mask |= describeContents(requestedVideoTrackFormat);
    _mask |= describeContents(testConfig);
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
