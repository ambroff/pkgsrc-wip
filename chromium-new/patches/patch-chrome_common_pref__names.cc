$NetBSD$

--- chrome/common/pref_names.cc.orig	2016-11-10 20:02:11.000000000 +0000
+++ chrome/common/pref_names.cc
@@ -952,7 +952,7 @@ const char kForceSessionSync[] = "settin
 // only using an account that belongs to one of the domains from this pref.
 const char kAllowedDomainsForApps[] = "settings.allowed_domains_for_apps";
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // Linux specific preference on whether we should match the system theme.
 const char kUsesSystemTheme[] = "extensions.theme.use_system";
 #endif
@@ -1035,7 +1035,7 @@ const char kShowUpdatePromotionInfoBar[]
     "browser.show_update_promotion_info_bar";
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // Boolean that is false if we should show window manager decorations.  If
 // true, we draw a custom chrome frame (thicker title bar and blue border).
 const char kUseCustomChromeFrame[] = "browser.custom_chrome_frame";
@@ -1408,7 +1408,7 @@ const char kDownloadDefaultDirectory[] =
 // upgrade a unsafe location to a safe location.
 const char kDownloadDirUpgraded[] = "download.directory_upgrade";
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 const char kOpenPdfDownloadInSystemReader[] =
     "download.open_pdf_in_system_reader";
 #endif
