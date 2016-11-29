$NetBSD$

--- third_party/WebKit/Source/wtf/Atomics.h.orig	2016-11-10 20:02:27.000000000 +0000
+++ third_party/WebKit/Source/wtf/Atomics.h
@@ -137,7 +137,7 @@ ALWAYS_INLINE void atomicSetOneToZero(in
 #if defined(THREAD_SANITIZER)
 // The definitions below assume an LP64 data model. This is fine because
 // TSan is only supported on x86_64 Linux.
-#if CPU(64BIT) && OS(LINUX)
+#if CPU(64BIT) && (OS(LINUX) || OS(BSD))
 ALWAYS_INLINE void releaseStore(volatile int* ptr, int value)
 {
     __tsan_atomic32_store(ptr, value, __tsan_memory_order_release);
