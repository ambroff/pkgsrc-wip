$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/net/system_network_context_manager.cc.orig	2024-09-24 20:49:18.692002500 +0000
+++ chrome/browser/net/system_network_context_manager.cc
@@ -101,7 +101,7 @@
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "chrome/common/chrome_paths_internal.h"
 #include "chrome/grit/branded_strings.h"
 #include "ui/base/l10n/l10n_util.h"
@@ -145,7 +145,7 @@ SystemNetworkContextManager* g_system_ne
 // received a failed launch for a sandboxed network service.
 bool g_previously_failed_to_launch_sandboxed_service = false;
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Whether kerberos library loading will work in the network service due to the
 // sandbox.
 bool g_network_service_will_allow_gssapi_library_load = false;
@@ -153,7 +153,7 @@ bool g_network_service_will_allow_gssapi
 const char* kGssapiDesiredPref =
 #if BUILDFLAG(IS_CHROMEOS)
     prefs::kKerberosEnabled;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     prefs::kReceivedHttpAuthNegotiateHeader;
 #endif
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
@@ -199,7 +199,7 @@ network::mojom::HttpAuthDynamicParamsPtr
   auth_dynamic_params->basic_over_http_enabled =
       local_state->GetBoolean(prefs::kBasicAuthOverHttpEnabled);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   auth_dynamic_params->delegate_by_kdc_policy =
       local_state->GetBoolean(prefs::kAuthNegotiateDelegateByKdcPolicy);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
@@ -214,7 +214,7 @@ network::mojom::HttpAuthDynamicParamsPtr
       local_state->GetString(prefs::kAuthAndroidNegotiateAccountType);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auth_dynamic_params->allow_gssapi_library_load =
       local_state->GetBoolean(kGssapiDesiredPref);
 #endif  // BUILDFLAG(IS_CHROMEOS)
@@ -224,7 +224,7 @@ network::mojom::HttpAuthDynamicParamsPtr
 
 void OnNewHttpAuthDynamicParams(
     network::mojom::HttpAuthDynamicParamsPtr& params) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The kerberos library is incompatible with the network service sandbox, so
   // if library loading is now enabled, the network service needs to be
   // restarted. It will be restarted unsandboxed because is
@@ -266,11 +266,11 @@ NetworkSandboxState IsNetworkSandboxEnab
   if (g_previously_failed_to_launch_sandboxed_service) {
     return NetworkSandboxState::kDisabledBecauseOfFailedLaunch;
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* local_state = g_browser_process->local_state();
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The network service sandbox and the kerberos library are incompatible.
   // If kerberos is enabled by policy, disable the network service sandbox.
   if (g_network_service_will_allow_gssapi_library_load ||
@@ -286,7 +286,7 @@ NetworkSandboxState IsNetworkSandboxEnab
   }
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (local_state &&
       local_state->HasPrefPath(prefs::kNetworkServiceSandboxEnabled)) {
     return local_state->GetBoolean(prefs::kNetworkServiceSandboxEnabled)
@@ -516,7 +516,7 @@ void SystemNetworkContextManager::Delete
   g_system_network_context_manager = nullptr;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 SystemNetworkContextManager::GssapiLibraryLoadObserver::
     GssapiLibraryLoadObserver(SystemNetworkContextManager* owner)
     : owner_(owner) {}
@@ -574,7 +574,7 @@ SystemNetworkContextManager::SystemNetwo
   pref_change_registrar_.Add(prefs::kAllHttpAuthSchemesAllowedForOrigins,
                              auth_pref_callback);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   pref_change_registrar_.Add(prefs::kAuthNegotiateDelegateByKdcPolicy,
                              auth_pref_callback);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
@@ -588,7 +588,7 @@ SystemNetworkContextManager::SystemNetwo
                              auth_pref_callback);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   pref_change_registrar_.Add(kGssapiDesiredPref, auth_pref_callback);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 
@@ -658,7 +658,7 @@ void SystemNetworkContextManager::Regist
   registry->RegisterBooleanPref(prefs::kKerberosEnabled, false);
 #endif  // BUILDFLAG(IS_CHROMEOS_LACROS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kAuthNegotiateDelegateByKdcPolicy,
                                 false);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
@@ -683,11 +683,11 @@ void SystemNetworkContextManager::Regist
 
   registry->RegisterListPref(prefs::kExplicitlyAllowedNetworkPorts);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kNetworkServiceSandboxEnabled, true);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kReceivedHttpAuthNegotiateHeader, false);
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -740,7 +740,7 @@ void SystemNetworkContextManager::OnNetw
   OnNewHttpAuthDynamicParams(http_auth_dynamic_params);
   network_service->ConfigureHttpAuthPrefs(std::move(http_auth_dynamic_params));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   gssapi_library_loader_observer_.Install(network_service);
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -955,7 +955,7 @@ bool SystemNetworkContextManager::IsNetw
       break;
   }
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!enabled) {
     g_network_service_will_allow_gssapi_library_load = true;
   }
