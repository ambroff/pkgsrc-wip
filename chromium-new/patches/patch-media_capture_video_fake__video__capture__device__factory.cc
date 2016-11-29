$NetBSD$

--- media/capture/video/fake_video_capture_device_factory.cc.orig	2016-11-10 20:02:15.000000000 +0000
+++ media/capture/video/fake_video_capture_device_factory.cc
@@ -49,7 +49,7 @@ void FakeVideoCaptureDeviceFactory::GetD
   for (int n = 0; n < number_of_devices_; ++n) {
     device_descriptors->emplace_back(base::StringPrintf("fake_device_%d", n),
                                      base::StringPrintf("/dev/video%d", n),
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
                                      VideoCaptureApi::LINUX_V4L2_SINGLE_PLANE
 #elif defined(OS_MACOSX)
                                      VideoCaptureApi::MACOSX_AVFOUNDATION
