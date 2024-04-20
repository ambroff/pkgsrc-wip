$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_triangulation.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/libslic3r/test_triangulation.cpp
@@ -1,4 +1,4 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
 
 #include <libslic3r/Triangulation.hpp>
 #include <libslic3r/SVG.hpp> // only debug visualization
