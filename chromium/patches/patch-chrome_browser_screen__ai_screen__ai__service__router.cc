$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/screen_ai/screen_ai_service_router.cc.orig	2024-09-24 20:49:19.713092300 +0000
+++ chrome/browser/screen_ai/screen_ai_service_router.cc
@@ -297,7 +297,7 @@ void ScreenAIServiceRouter::LaunchIfNotR
   base::FilePath binary_path = state_instance->get_component_binary_path();
 #if BUILDFLAG(IS_WIN)
   std::vector<base::FilePath> preload_libraries = {binary_path};
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::vector<std::string> extra_switches = {
       base::StringPrintf("--%s=%s", screen_ai::GetBinaryPathSwitch(),
                          binary_path.MaybeAsASCII().c_str())};
@@ -311,7 +311,7 @@ void ScreenAIServiceRouter::LaunchIfNotR
           .WithPreloadedLibraries(
               preload_libraries,
               content::ServiceProcessHostPreloadLibraries::GetPassKey())
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           .WithExtraCommandLineSwitches(extra_switches)
 #endif  // BUILDFLAG(IS_WIN)
           .Pass());
