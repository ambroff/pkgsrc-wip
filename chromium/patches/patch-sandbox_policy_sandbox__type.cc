$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- sandbox/policy/sandbox_type.cc.orig	2024-09-24 20:49:34.311373200 +0000
+++ sandbox/policy/sandbox_type.cc
@@ -38,7 +38,7 @@ bool IsUnsandboxedSandboxType(Sandbox sa
 #endif
     case Sandbox::kAudio:
       return false;
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
       return false;
 #endif
@@ -62,7 +62,7 @@ bool IsUnsandboxedSandboxType(Sandbox sa
 #if BUILDFLAG(IS_MAC)
     case Sandbox::kMirroring:
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
     case Sandbox::kHardwareVideoDecoding:
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -73,7 +73,7 @@ bool IsUnsandboxedSandboxType(Sandbox sa
     case Sandbox::kLibassistant:
 #endif  // BUILDFLAG(ENABLE_CROS_LIBASSISTANT)
 #endif  // // BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) | BUILDFLAG(IS_BSD)
     case Sandbox::kZygoteIntermediateSandbox:
     case Sandbox::kHardwareVideoEncoding:
 #endif
@@ -130,7 +130,7 @@ void SetCommandLineFlagsForSandboxType(b
 #endif
     case Sandbox::kPrintCompositor:
     case Sandbox::kAudio:
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
 #endif
 #if BUILDFLAG(IS_WIN)
@@ -141,10 +141,10 @@ void SetCommandLineFlagsForSandboxType(b
     case Sandbox::kMediaFoundationCdm:
     case Sandbox::kWindowsSystemProxyResolver:
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
     case Sandbox::kHardwareVideoDecoding:
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kHardwareVideoEncoding:
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -169,7 +169,7 @@ void SetCommandLineFlagsForSandboxType(b
           switches::kServiceSandboxType,
           StringFromUtilitySandboxType(sandbox_type));
       break;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kZygoteIntermediateSandbox:
       break;
 #endif
@@ -209,7 +209,7 @@ sandbox::mojom::Sandbox SandboxTypeFromC
     return Sandbox::kUtility;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Intermediate process gains a sandbox later.
   if (process_type == switches::kZygoteProcessType)
     return Sandbox::kZygoteIntermediateSandbox;
@@ -257,7 +257,7 @@ std::string StringFromUtilitySandboxType
       return switches::kUtilitySandbox;
     case Sandbox::kAudio:
       return switches::kAudioSandbox;
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
       return switches::kVideoCaptureSandbox;
 #endif
@@ -287,11 +287,11 @@ std::string StringFromUtilitySandboxType
     case Sandbox::kMirroring:
       return switches::kMirroringSandbox;
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
     case Sandbox::kHardwareVideoDecoding:
       return switches::kHardwareVideoDecodingSandbox;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kHardwareVideoEncoding:
       return switches::kHardwareVideoEncodingSandbox;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -310,7 +310,7 @@ std::string StringFromUtilitySandboxType
       // The following are not utility processes so should not occur.
     case Sandbox::kRenderer:
     case Sandbox::kGpu:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kZygoteIntermediateSandbox:
 #endif
       NOTREACHED_IN_MIGRATION();
@@ -382,15 +382,15 @@ sandbox::mojom::Sandbox UtilitySandboxTy
   if (sandbox_string == switches::kScreenAISandbox)
     return Sandbox::kScreenAI;
 #endif
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   if (sandbox_string == switches::kVideoCaptureSandbox)
     return Sandbox::kVideoCapture;
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   if (sandbox_string == switches::kHardwareVideoDecodingSandbox)
     return Sandbox::kHardwareVideoDecoding;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (sandbox_string == switches::kHardwareVideoEncodingSandbox)
     return Sandbox::kHardwareVideoEncoding;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
