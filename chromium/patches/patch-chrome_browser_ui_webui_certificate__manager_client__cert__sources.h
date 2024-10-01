$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/certificate_manager/client_cert_sources.h.orig	2024-09-24 20:49:21.043209000 +0000
+++ chrome/browser/ui/webui/certificate_manager/client_cert_sources.h
@@ -17,7 +17,7 @@ CreatePlatformClientCertSource(
     mojo::Remote<certificate_manager_v2::mojom::CertificateManagerPage>*
         remote_client);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<CertificateManagerPageHandler::CertSource>
 CreateProvisionedClientCertSource(Profile* profile);
 #endif
