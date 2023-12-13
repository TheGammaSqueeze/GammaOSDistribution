package com.android.libraries.entitlement.http;

import android.net.Network;
import androidx.annotation.Nullable;
import com.google.common.collect.ImmutableListMultimap;
import javax.annotation.processing.Generated;
import org.json.JSONObject;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_HttpRequest extends HttpRequest {

  private final String url;

  private final String requestMethod;

  private final JSONObject postData;

  private final ImmutableListMultimap<String, String> requestProperties;

  private final int timeoutInSec;

  private final Network network;

  private AutoValue_HttpRequest(
      String url,
      String requestMethod,
      JSONObject postData,
      ImmutableListMultimap<String, String> requestProperties,
      int timeoutInSec,
      @Nullable Network network) {
    this.url = url;
    this.requestMethod = requestMethod;
    this.postData = postData;
    this.requestProperties = requestProperties;
    this.timeoutInSec = timeoutInSec;
    this.network = network;
  }

  @Override
  public String url() {
    return url;
  }

  @Override
  public String requestMethod() {
    return requestMethod;
  }

  @Override
  public JSONObject postData() {
    return postData;
  }

  @Override
  public ImmutableListMultimap<String, String> requestProperties() {
    return requestProperties;
  }

  @Override
  public int timeoutInSec() {
    return timeoutInSec;
  }

  @Nullable
  @Override
  public Network network() {
    return network;
  }

  @Override
  public String toString() {
    return "HttpRequest{"
        + "url=" + url + ", "
        + "requestMethod=" + requestMethod + ", "
        + "postData=" + postData + ", "
        + "requestProperties=" + requestProperties + ", "
        + "timeoutInSec=" + timeoutInSec + ", "
        + "network=" + network
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof HttpRequest) {
      HttpRequest that = (HttpRequest) o;
      return this.url.equals(that.url())
          && this.requestMethod.equals(that.requestMethod())
          && this.postData.equals(that.postData())
          && this.requestProperties.equals(that.requestProperties())
          && this.timeoutInSec == that.timeoutInSec()
          && (this.network == null ? that.network() == null : this.network.equals(that.network()));
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= url.hashCode();
    h$ *= 1000003;
    h$ ^= requestMethod.hashCode();
    h$ *= 1000003;
    h$ ^= postData.hashCode();
    h$ *= 1000003;
    h$ ^= requestProperties.hashCode();
    h$ *= 1000003;
    h$ ^= timeoutInSec;
    h$ *= 1000003;
    h$ ^= (network == null) ? 0 : network.hashCode();
    return h$;
  }

  static final class Builder extends HttpRequest.Builder {
    private String url;
    private String requestMethod;
    private JSONObject postData;
    private ImmutableListMultimap.Builder<String, String> requestPropertiesBuilder$;
    private ImmutableListMultimap<String, String> requestProperties;
    private Integer timeoutInSec;
    private Network network;
    Builder() {
    }
    @Override
    public HttpRequest.Builder setUrl(String url) {
      if (url == null) {
        throw new NullPointerException("Null url");
      }
      this.url = url;
      return this;
    }
    @Override
    public HttpRequest.Builder setRequestMethod(String requestMethod) {
      if (requestMethod == null) {
        throw new NullPointerException("Null requestMethod");
      }
      this.requestMethod = requestMethod;
      return this;
    }
    @Override
    public HttpRequest.Builder setPostData(JSONObject postData) {
      if (postData == null) {
        throw new NullPointerException("Null postData");
      }
      this.postData = postData;
      return this;
    }
    @Override
    ImmutableListMultimap.Builder<String, String> requestPropertiesBuilder() {
      if (requestPropertiesBuilder$ == null) {
        requestPropertiesBuilder$ = ImmutableListMultimap.builder();
      }
      return requestPropertiesBuilder$;
    }
    @Override
    public HttpRequest.Builder setTimeoutInSec(int timeoutInSec) {
      this.timeoutInSec = timeoutInSec;
      return this;
    }
    @Override
    public HttpRequest.Builder setNetwork(@Nullable Network network) {
      this.network = network;
      return this;
    }
    @Override
    public HttpRequest build() {
      if (requestPropertiesBuilder$ != null) {
        this.requestProperties = requestPropertiesBuilder$.build();
      } else if (this.requestProperties == null) {
        this.requestProperties = ImmutableListMultimap.of();
      }
      String missing = "";
      if (this.url == null) {
        missing += " url";
      }
      if (this.requestMethod == null) {
        missing += " requestMethod";
      }
      if (this.postData == null) {
        missing += " postData";
      }
      if (this.timeoutInSec == null) {
        missing += " timeoutInSec";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_HttpRequest(
          this.url,
          this.requestMethod,
          this.postData,
          this.requestProperties,
          this.timeoutInSec,
          this.network);
    }
  }

}
