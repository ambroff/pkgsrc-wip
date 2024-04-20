$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_polyline.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/libslic3r/test_polyline.cpp
@@ -1,7 +1,7 @@
 /**
 * Ported from xs/t/09_polyline.t
 */
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
 
 #include "libslic3r/Point.hpp"
 #include "libslic3r/Polyline.hpp"
