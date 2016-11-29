$NetBSD$

--- chrome/browser/download/download_query.cc.orig	2016-11-10 20:02:10.000000000 +0000
+++ chrome/browser/download/download_query.cc
@@ -28,7 +28,11 @@
 #include "components/url_formatter/url_formatter.h"
 #include "content/public/browser/content_browser_client.h"
 #include "content/public/browser/download_item.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "url/gurl.h"
 
 using content::DownloadDangerType;
