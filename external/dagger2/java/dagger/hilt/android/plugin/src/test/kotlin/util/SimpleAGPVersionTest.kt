package util

import com.google.common.truth.Truth.assertThat
import dagger.hilt.android.plugin.util.SimpleAGPVersion
import org.junit.Test

class SimpleAGPVersionTest {

  @Test
  fun parsing() {
    assertThat(SimpleAGPVersion.parse("4.2"))
      .isEqualTo(SimpleAGPVersion(4, 2))
    assertThat(SimpleAGPVersion.parse("4.2.1"))
      .isEqualTo(SimpleAGPVersion(4, 2))
    assertThat(SimpleAGPVersion.parse("7.0.0-alpha01"))
      .isEqualTo(SimpleAGPVersion(7, 0))
  }

  @Test
  fun comparing() {
    assertThat(SimpleAGPVersion(4, 2))
      .isEqualTo(SimpleAGPVersion(4, 2))
    assertThat(SimpleAGPVersion(4, 2))
      .isGreaterThan(SimpleAGPVersion(3, 4))
    assertThat(SimpleAGPVersion(4, 2))
      .isLessThan(SimpleAGPVersion(7, 0))

    assertThat(SimpleAGPVersion.parse("4.2.1"))
      .isEqualTo(SimpleAGPVersion.parse("4.2.2"))
    assertThat(SimpleAGPVersion.parse("4.2.1"))
      .isGreaterThan(SimpleAGPVersion.parse("3.4.1"))
    assertThat(SimpleAGPVersion.parse("4.2.1"))
      .isLessThan(SimpleAGPVersion.parse("7.0.1"))

    assertThat(SimpleAGPVersion.parse("4.2.1"))
      .isLessThan(SimpleAGPVersion.parse("7.0.0-alpha01"))
    assertThat(SimpleAGPVersion.parse("7.0.0-alpha01"))
      .isEqualTo(SimpleAGPVersion.parse("7.0.0-alpha02"))
  }
}
