$NetBSD$

--- chrome/browser/renderer_preferences_util.cc.orig	2016-11-10 20:02:10.000000000 +0000
+++ chrome/browser/renderer_preferences_util.cc
@@ -18,7 +18,7 @@
 #include "content/public/common/webrtc_ip_handling_policy.h"
 #include "third_party/skia/include/core/SkColor.h"
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #include "ui/gfx/font_render_params.h"
 #endif
 
@@ -26,7 +26,7 @@
 #include "ui/views/controls/textfield/textfield.h"
 #endif
 
-#if defined(USE_AURA) && defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(USE_AURA) && (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/themes/theme_service.h"
 #include "chrome/browser/themes/theme_service_factory.h"
 #include "ui/views/linux_ui/linux_ui.h"
@@ -120,7 +120,7 @@ void UpdateFromSystemSettings(content::R
   prefs->caret_blink_interval = views::Textfield::GetCaretBlinkMs() / 1000.0;
 #endif
 
-#if defined(USE_AURA) && defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(USE_AURA) && (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   views::LinuxUI* linux_ui = views::LinuxUI::instance();
   if (linux_ui) {
     if (ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme()) {
@@ -142,7 +142,7 @@ void UpdateFromSystemSettings(content::R
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WIN) || defined(OS_BSD)
   CR_DEFINE_STATIC_LOCAL(const gfx::FontRenderParams, params,
       (gfx::GetFontRenderParams(gfx::FontRenderParamsQuery(), NULL)));
   prefs->should_antialias_text = params.antialiasing;
