$NetBSD$

--- chrome/browser/ui/exclusive_access/exclusive_access_bubble.cc.orig	2016-11-10 20:02:11.000000000 +0000
+++ chrome/browser/ui/exclusive_access/exclusive_access_bubble.cc
@@ -19,7 +19,7 @@
 
 // NOTE(koz): Linux doesn't use the thick shadowed border, so we add padding
 // here.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const int ExclusiveAccessBubble::kPaddingPx = 8;
 #else
 const int ExclusiveAccessBubble::kPaddingPx = 15;
