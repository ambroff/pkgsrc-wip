$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/supervised_user/supervised_user_browser_utils.cc.orig	2024-09-24 20:49:19.852104400 +0000
+++ chrome/browser/supervised_user/supervised_user_browser_utils.cc
@@ -40,7 +40,7 @@
 #include "components/user_manager/user_type.h"
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
 #include "chromeos/startup/browser_params_proxy.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/supervised_user_verification_controller_client.h"
 #include "chrome/browser/supervised_user/supervised_user_verification_page.h"
 #endif
@@ -178,7 +178,7 @@ bool IsAuthenticatedSupervisedProfile(Pr
          supervised_user::ChildAccountService::AuthState::AUTHENTICATED;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 std::string CreateReauthenticationInterstitial(
     content::NavigationHandle& navigation_handle,
     SupervisedUserVerificationPage::VerificationPurpose verification_purpose) {
