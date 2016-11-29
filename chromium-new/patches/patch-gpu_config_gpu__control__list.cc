$NetBSD$

--- gpu/config/gpu_control_list.cc.orig	2016-11-10 20:02:15.000000000 +0000
+++ gpu/config/gpu_control_list.cc
@@ -19,7 +19,11 @@
 #include "base/sys_info.h"
 #include "gpu/config/gpu_info.h"
 #include "gpu/config/gpu_util.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace gpu {
 namespace {
@@ -1154,7 +1158,7 @@ GpuControlList::GpuControlListEntry::GLT
 GpuControlList::GpuControlListEntry::GetDefaultGLType() {
 #if defined(OS_CHROMEOS)
   return kGLTypeGL;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return kGLTypeGL;
 #elif defined(OS_MACOSX)
   return kGLTypeGL;
@@ -1593,7 +1597,7 @@ GpuControlList::OsType GpuControlList::G
   return kOsWin;
 #elif defined(OS_ANDROID)
   return kOsAndroid;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return kOsLinux;
 #elif defined(OS_MACOSX)
   return kOsMacosx;
