$NetBSD$

--- dtools/xtmReminder.c.orig	1997-05-04 21:09:51.000000000 +0000
+++ dtools/xtmReminder.c
@@ -580,7 +580,7 @@ static Widget
                                                    &help_casc[ index ] );
 
     XtAddCallback( menuHelpBu[ index ], XmNactivateCallback, 
-                   (XtCallbackProc) helpCB, (XtPointer) index );
+                   (XtCallbackProc) helpCB, (XtPointer)(intptr_t)index );
   }
 
   /* We can't do context sensitive help. */
@@ -1093,7 +1093,7 @@ static void
   /* Code. */
 
   /* About window? */
-  if( (int) call_data -> data == 6 ) {
+  if( (intptr_t) call_data -> data == 6 ) {
     xtmHlDisplayAboutWindow( reminder_ref -> reminderW );
 
     return;
@@ -1105,7 +1105,7 @@ static void
   /* Call the user callback. */
   (* reminder_ref -> helpCB)( reminder_ref -> reminderW, 
                               reminder_ref -> user_data,
-                              (int) call_data -> data );
+                              (intptr_t) call_data -> data );
 
 
   return;
