package com.android.libraries.entitlement.http;

import com.google.common.collect.ImmutableList;
import java.util.List;
import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_HttpResponse extends HttpResponse {

  private final int contentType;

  private final String body;

  private final int responseCode;

  private final String responseMessage;

  private final ImmutableList<String> cookies;

  private AutoValue_HttpResponse(
      int contentType,
      String body,
      int responseCode,
      String responseMessage,
      ImmutableList<String> cookies) {
    this.contentType = contentType;
    this.body = body;
    this.responseCode = responseCode;
    this.responseMessage = responseMessage;
    this.cookies = cookies;
  }

  @Override
  public int contentType() {
    return contentType;
  }

  @Override
  public String body() {
    return body;
  }

  @Override
  public int responseCode() {
    return responseCode;
  }

  @Override
  public String responseMessage() {
    return responseMessage;
  }

  @Override
  public ImmutableList<String> cookies() {
    return cookies;
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof HttpResponse) {
      HttpResponse that = (HttpResponse) o;
      return this.contentType == that.contentType()
          && this.body.equals(that.body())
          && this.responseCode == that.responseCode()
          && this.responseMessage.equals(that.responseMessage())
          && this.cookies.equals(that.cookies());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= contentType;
    h$ *= 1000003;
    h$ ^= body.hashCode();
    h$ *= 1000003;
    h$ ^= responseCode;
    h$ *= 1000003;
    h$ ^= responseMessage.hashCode();
    h$ *= 1000003;
    h$ ^= cookies.hashCode();
    return h$;
  }

  static final class Builder extends HttpResponse.Builder {
    private Integer contentType;
    private String body;
    private Integer responseCode;
    private String responseMessage;
    private ImmutableList<String> cookies;
    Builder() {
    }
    @Override
    public HttpResponse.Builder setContentType(int contentType) {
      this.contentType = contentType;
      return this;
    }
    @Override
    public HttpResponse.Builder setBody(String body) {
      if (body == null) {
        throw new NullPointerException("Null body");
      }
      this.body = body;
      return this;
    }
    @Override
    public HttpResponse.Builder setResponseCode(int responseCode) {
      this.responseCode = responseCode;
      return this;
    }
    @Override
    public HttpResponse.Builder setResponseMessage(String responseMessage) {
      if (responseMessage == null) {
        throw new NullPointerException("Null responseMessage");
      }
      this.responseMessage = responseMessage;
      return this;
    }
    @Override
    public HttpResponse.Builder setCookies(List<String> cookies) {
      this.cookies = ImmutableList.copyOf(cookies);
      return this;
    }
    @Override
    public HttpResponse build() {
      String missing = "";
      if (this.contentType == null) {
        missing += " contentType";
      }
      if (this.body == null) {
        missing += " body";
      }
      if (this.responseCode == null) {
        missing += " responseCode";
      }
      if (this.responseMessage == null) {
        missing += " responseMessage";
      }
      if (this.cookies == null) {
        missing += " cookies";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_HttpResponse(
          this.contentType,
          this.body,
          this.responseCode,
          this.responseMessage,
          this.cookies);
    }
  }

}
