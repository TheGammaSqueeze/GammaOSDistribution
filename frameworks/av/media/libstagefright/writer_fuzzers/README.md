# Fuzzer for writers

## Table of contents
+  [libwriterfuzzerbase](#WriterFuzzerBase)
+  [Amr Writer](#amrWriterFuzzer)
+  [MPEG4 Writer](#mpeg4WriterFuzzer)
+  [OGG Writer](#oggWriterFuzzer)
+  [WEBM Writer](#webmWriterFuzzer)

# <a name="WriterFuzzerBase"></a> Fuzzer for libwriterfuzzerbase
All the writers have a common API - creating a writer, adding a source for
all the tracks, etc. These common APIs have been abstracted in a base class
called `WriterFuzzerBase` to ensure code is reused between fuzzer plugins.

## Plugin Design Considerations
The fuzzer plugin for writers is designed based on the understanding of the
writer and tries to achieve the following:

##### Maximize code coverage
The configuration parameters are not hardcoded, but instead selected based on
incoming data. This ensures more code paths are reached by the fuzzer.

Fuzzer for writers supports the following parameters:
1. Track Mime (parameter name: `mime`)
2. Channel Count (parameter name: `channel-count`)
3. Sample Rate (parameter name: `sample-rate`)
4. Frame Height (parameter name: `height`)
5. Frame Width (parameter name: `width`)

| Parameter| Valid Values| Configured Value|
|------------- |-------------| ----- |
| `mime` | 0. `audio/3gpp` 1. `audio/amr-wb` 2. `audio/vorbis` 3. `audio/opus` 4. `audio/mp4a-latm` 5. `audio/mpeg` 6. `audio/mpeg-L1` 7. `audio/mpeg-L2` 8. `audio/midi` 9. `audio/qcelp` 10. `audio/g711-alaw` 11. `audio/g711-mlaw` 12. `audio/flac` 13. `audio/aac-adts` 14. `audio/gsm` 15. `audio/ac3` 16. `audio/eac3` 17. `audio/eac3-joc` 18. `audio/ac4` 19. `audio/scrambled` 20. `audio/alac` 21. `audio/x-ms-wma` 22. `audio/x-adpcm-ms` 23. `audio/x-adpcm-dvi-ima` 24. `video/avc` 25. `video/hevc` 26. `video/mp4v-es` 27. `video/3gpp` 28. `video/x-vnd.on2.vp8` 29. `video/x-vnd.on2.vp9` 30. `video/av01` 31. `video/mpeg2` 32. `video/dolby-vision` 33. `video/scrambled` 34. `video/divx` 35. `video/divx3` 36. `video/xvid` 37. `video/x-motion-jpeg` 38. `text/3gpp-tt` 39. `application/x-subrip` 40. `text/vtt` 41. `text/cea-608` 42. `text/cea-708` 43. `application/x-id3v4` | All the bits of 2nd byte of data for first track and 11th byte of data for second track and 20th byte of data for third track(if present) modulus 44 |
| `channel-count` | In the range `0 to INT32_MAX` | All the bits of 3rd byte to 6th bytes of data if first track is audio and 12th to 15th bytes of data if second track is audio |
| `sample-rate` | In the range `1 to INT32_MAX` | All the bits of 7th byte to 10th bytes of data if first track is audio and 16th to 19th bytes of data if second track is audio |
| `height` | In the range `0 to INT32_MAX` | All the bits of 3rd byte to 6th bytes of data if first track is video and 12th to 15th bytes of data if second track is video |
| `width` | In the range `0 to INT32_MAX` | All the bits of 7th byte to 10th bytes of data if first track is video and 16th to 19th bytes of data if second track is video |

This also ensures that the plugin is always deterministic for any given input.

##### Maximize utilization of input data
The plugin divides the entire input data into frames based on frame markers.
If no frame marker is found then the entire input data is treated as single frame.

This ensures that the plugin tolerates any kind of input (huge,
malformed, etc) and thereby increasing the chance of identifying vulnerabilities.

# <a name="amrWriterFuzzer"></a> Fuzzer for Amr Writer

## Plugin Design Considerations
The fuzzer plugin for AMR writer uses the `WriterFuzzerBase` class and
implements only the `createWriter` to create the AMR writer class.

##### Other considerations
 * Two fuzzer binaries - amrnb_writer_fuzzer and amrwb_writer_fuzzer are generated based on the presence of a flag - 'AMRNB'

# <a name="mpeg4WriterFuzzer"></a> Fuzzer for MPEG4 Writer

## Plugin Design Considerations
The fuzzer plugin for MPEG4 writer uses the `WriterFuzzerBase` class and
implements only the `createWriter` to create the MPEG4 writer class.

# <a name="oggWriterFuzzer"></a> Fuzzer for OGG Writer

## Plugin Design Considerations
The fuzzer plugin for OGG writer uses the `WriterFuzzerBase` class and
implements only the `createWriter` to create the OGG writer class.

# <a name="webmWriterFuzzer"></a> Fuzzer for WEBM Writer

## Plugin Design Considerations
The fuzzer plugin for WEBM writer uses the `WriterFuzzerBase` class and
implements only the `createWriter` to create the WEBM writer class.

## Build

This describes steps to build writer fuzzer binaries.

### Android

`*` = amrnb/amrwb/mpeg4/ogg/webm
#### Steps to build
Build the fuzzer
```
  $ mm -j$(nproc) *_writer_fuzzer
```

#### Steps to run
Create a directory CORPUS_DIR and copy some media files to that folder
Push this directory to device.

To run on device
```
  $ adb sync data
  $ adb shell /data/fuzz/arm64/*_writer_fuzzer/*_writer_fuzzer CORPUS_DIR
```


## References:
 * http://llvm.org/docs/LibFuzzer.html
 * https://github.com/google/oss-fuzz
