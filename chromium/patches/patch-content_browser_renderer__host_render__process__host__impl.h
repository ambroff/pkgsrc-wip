$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/renderer_host/render_process_host_impl.h.orig	2024-09-24 20:49:28.254841800 +0000
+++ content/browser/renderer_host/render_process_host_impl.h
@@ -102,7 +102,7 @@
 #include "media/fuchsia_media_codec_provider_impl.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/browser/child_thread_type_switcher_linux.h"
 #include "media/mojo/mojom/video_encode_accelerator.mojom.h"
 #endif
@@ -611,7 +611,7 @@ class CONTENT_EXPORT RenderProcessHostIm
   // Sets this RenderProcessHost to be guest only. For Testing only.
   void SetForGuestsOnlyForTesting();
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   // Launch the zygote early in the browser startup.
   static void EarlyZygoteLaunch();
 #endif  // BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_MAC)
@@ -976,7 +976,7 @@ class CONTENT_EXPORT RenderProcessHostIm
     std::unique_ptr<service_manager::BinderRegistry> binders_;
     mojo::Receiver<mojom::ChildProcessHost> receiver_{this};
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     mojo::Remote<media::mojom::VideoEncodeAcceleratorProviderFactory>
         video_encode_accelerator_factory_remote_;
     ChildThreadTypeSwitcher child_thread_type_switcher_;
