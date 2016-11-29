$NetBSD$

--- chrome/browser/extensions/api/input_ime/input_ime_api.h.orig	2016-11-10 20:02:10.000000000 +0000
+++ chrome/browser/extensions/api/input_ime/input_ime_api.h
@@ -28,7 +28,7 @@
 
 #if defined(OS_CHROMEOS)
 #include "chrome/browser/extensions/api/input_ime/input_ime_api_chromeos.h"
-#elif defined(OS_LINUX) || defined(OS_WIN)
+#elif defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "chrome/browser/extensions/api/input_ime/input_ime_api_nonchromeos.h"
 #endif  // defined(OS_CHROMEOS)
 
