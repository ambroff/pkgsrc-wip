$NetBSD: patch-aclocal.m4,v 1.2 2013/12/20 10:00:31 thomasklausner Exp $

pkgsrc does not have a new enough metapost, so prefer a building package
with possible problems to a non-building one.

--- aclocal.m4.orig	2013-11-26 06:59:49.000000000 +0000
+++ aclocal.m4
@@ -1171,9 +1171,9 @@ AC_DEFUN(STEPMAKE_TEXMF, [
 	ver=`STEPMAKE_GET_VERSION($METAPOST)`
 	num=`STEPMAKE_NUMERIC_VERSION($ver)`
 	# Avoid buggy metapost versions: 1.600 <= x < 1.803
-	if test "$num" -ge "1600000" -a "$num" -lt "1803000"; then
-            STEPMAKE_ADD_ENTRY($1, ["mpost (due to a bug in metapost, versions 1.600 <= x < 1.803 are not supported; installed: $ver)"])
-	fi
+	#if test "$num" -ge "1600000" -a "$num" -lt "1803000"; then
+            #STEPMAKE_ADD_ENTRY($1, ["mpost (due to a bug in metapost, versions 1.600 <= x < 1.803 are not supported; installed: $ver)"])
+	#fi
     fi
 
     AC_MSG_CHECKING(for working metafont mode)
