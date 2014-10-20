$NetBSD: patch-liboctave_oct-time.cc,v 1.1 2014/10/20 22:15:32 outpaddling Exp $

--- liboctave/oct-time.cc.orig	2011-09-01 13:38:52.000000000 +0000
+++ liboctave/oct-time.cc
@@ -79,7 +79,7 @@ octave_time::stamp (void)
 {
   struct timeval tp;
 
-  gnulib::gettimeofday (&tp, 0);
+  gettimeofday (&tp, 0);
 
   ot_unix_time = tp.tv_sec;
   ot_usec = tp.tv_usec;
