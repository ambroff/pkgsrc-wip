$NetBSD$

Copy distutils distro config file to virtualenv.
https://github.com/pypa/virtualenv/issues/2313

--- src/virtualenv/create/via_global_ref/api.py.orig	2022-02-24 11:00:44.000000000 +0000
+++ src/virtualenv/create/via_global_ref/api.py
@@ -4,6 +4,9 @@ import logging
 import os
 from abc import ABCMeta
 
+from shutil import copy
+from sysconfig import get_paths
+
 from six import add_metaclass
 
 from virtualenv.info import fs_supports_symlink
@@ -97,7 +100,10 @@ class ViaGlobalRefApi(Creator):
             dest_path = self.purelib / "_virtualenv.py"
             logging.debug("create %s", ensure_text(str(dest_path)))
             dest_path.write_text(text)
-
+        distutils_distro_config = get_paths()["platlib"] + "/_distutils_system_mod.py"
+        if os.path.exists(distutils_distro_config):
+            copy(distutils_distro_config, self.platlib)
+            
     def env_patch_text(self):
         """Patch the distutils package to not be derailed by its configuration files"""
         with self.app_data.ensure_extracted(Path(__file__).parent / "_virtualenv.py") as resolved_path:
