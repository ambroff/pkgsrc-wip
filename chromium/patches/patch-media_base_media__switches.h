$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/base/media_switches.h.orig	2024-09-24 20:49:31.676142000 +0000
+++ media/base/media_switches.h
@@ -44,7 +44,7 @@ MEDIA_EXPORT extern const char kDisableB
 MEDIA_EXPORT extern const char kReportVp9AsAnUnsupportedMimeType[];
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD) || \
-    BUILDFLAG(IS_SOLARIS)
+    BUILDFLAG(IS_SOLARIS) || BUILDFLAG(IS_NETBSD)
 MEDIA_EXPORT extern const char kAlsaInputDevice[];
 MEDIA_EXPORT extern const char kAlsaOutputDevice[];
 #endif
@@ -327,13 +327,26 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kPlatf
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kPlaybackSpeedButton);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kPreloadMediaEngagementData);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kPreloadMetadataSuspend);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kPulseaudioLoopbackForCast);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kPulseaudioLoopbackForScreenShare);
+
+enum class AudioBackend {
+  kAuto,
+  kPulseAudio,
+  kSndio,
+  kAudioIO,
+  kAlsa
+};
+
+MEDIA_EXPORT BASE_DECLARE_FEATURE(kAudioBackend);
+MEDIA_EXPORT extern const base::FeatureParam<
+    AudioBackend>
+    kAudioBackendParam;
 #endif  // BUILDFLAG(IS_LINUX)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kRecordMediaEngagementScores);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kRecordWebAudioEngagement);
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kReduceHardwareVideoDecoderBuffers);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kResumeBackgroundVideo);
@@ -348,7 +361,7 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kUnifi
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseAndroidOverlayForSecureOnly);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseDecoderStreamForWebRTC);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseFakeDeviceForMediaStream);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kVaapiVideoDecodeLinux);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kVaapiVideoDecodeLinuxGL);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kVaapiVideoEncodeLinux);
@@ -367,7 +380,7 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kVaapi
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kVaapiVp8TemporalLayerHWEncoding);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kVaapiVp9SModeHWEncoding);
 #endif  // defined(ARCH_CPU_X86_FAMILY) && BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kV4L2FlatStatefulVideoDecoder);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kV4L2H264TemporalLayerHWEncoding);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
@@ -507,7 +520,7 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseOu
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseGTFOOutOfProcessVideoDecoding);
 #endif  // BUILDFLAG(ALLOW_OOP_VIDEO_DECODER)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseOutOfProcessVideoEncoding);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
