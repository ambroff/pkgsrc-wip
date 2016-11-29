$NetBSD$

--- cc/layers/scrollbar_layer_impl_base.cc.orig	2016-11-10 20:02:09.000000000 +0000
+++ cc/layers/scrollbar_layer_impl_base.cc
@@ -174,8 +174,8 @@ gfx::Rect ScrollbarLayerImplBase::Comput
   int thumb_offset = TrackStart();
   if (maximum > 0) {
     float ratio = clamped_current_pos / maximum;
-    float max_offset = track_length - thumb_length;
-    thumb_offset += static_cast<int>(ratio * max_offset);
+    float _max_offset = track_length - thumb_length;
+    thumb_offset += static_cast<int>(ratio * _max_offset);
   }
 
   float thumb_thickness_adjustment =
