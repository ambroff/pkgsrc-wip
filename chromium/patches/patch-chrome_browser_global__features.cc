$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/global_features.cc.orig	2024-09-24 20:49:18.448981300 +0000
+++ chrome/browser/global_features.cc
@@ -10,7 +10,7 @@
 #include "build/build_config.h"
 #include "chrome/browser/permissions/system/platform_handle.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // This causes a gn error on Android builds, because gn does not understand
 // buildflags, so we include it only on platforms where it is used.
 #include "components/user_education/common/user_education_features.h"  // nogncheck
@@ -49,7 +49,7 @@ void GlobalFeatures::ReplaceGlobalFeatur
 
 void GlobalFeatures::Init() {
   system_permissions_platform_handle_ = CreateSystemPermissionsPlatformHandle();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (user_education::features::IsWhatsNewV2()) {
     whats_new_registry_ = CreateWhatsNewRegistry();
   }
@@ -61,7 +61,7 @@ GlobalFeatures::CreateSystemPermissionsP
   return system_permission_settings::PlatformHandle::Create();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<whats_new::WhatsNewRegistry>
 GlobalFeatures::CreateWhatsNewRegistry() {
   return whats_new::CreateWhatsNewRegistry();
