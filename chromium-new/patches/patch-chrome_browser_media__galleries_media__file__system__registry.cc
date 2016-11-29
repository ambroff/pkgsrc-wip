$NetBSD$

--- chrome/browser/media_galleries/media_file_system_registry.cc.orig	2016-11-10 20:02:10.000000000 +0000
+++ chrome/browser/media_galleries/media_file_system_registry.cc
@@ -757,7 +757,10 @@ class MediaFileSystemRegistry::MediaFile
 // Constructor in 'private' section because depends on private class definition.
 MediaFileSystemRegistry::MediaFileSystemRegistry()
     : file_system_context_(new MediaFileSystemContextImpl) {
-  StorageMonitor::GetInstance()->AddObserver(this);
+  // This conditional is needed for shutdown.  Destructors
+  // try to get the media file system registry.
+  if (StorageMonitor::GetInstance())
+    StorageMonitor::GetInstance()->AddObserver(this);
 }
 
 MediaFileSystemRegistry::~MediaFileSystemRegistry() {
