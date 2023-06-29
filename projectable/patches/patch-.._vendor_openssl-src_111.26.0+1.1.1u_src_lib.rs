$NetBSD$

Provide defaults for the various NetBSD targets.

--- ../vendor/openssl-src-111.26.0+1.1.1u/src/lib.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/openssl-src-111.26.0+1.1.1u/src/lib.rs
@@ -239,6 +239,8 @@ impl Build {
             "aarch64-unknown-freebsd" => "BSD-generic64",
             "aarch64-unknown-linux-gnu" => "linux-aarch64",
             "aarch64-unknown-linux-musl" => "linux-aarch64",
+            "aarch64-unknown-netbsd" => "BSD-generic64",
+            "aarch64_be-unknown-netbsd" => "BSD-generic64",
             "aarch64-pc-windows-msvc" => "VC-WIN64-ARM",
             "arm-linux-androideabi" => "linux-armv4",
             "armv7-linux-androideabi" => "linux-armv4",
@@ -249,11 +251,13 @@ impl Build {
             "armv5te-unknown-linux-gnueabi" => "linux-armv4",
             "armv5te-unknown-linux-musleabi" => "linux-armv4",
             "armv6-unknown-freebsd" => "BSD-generic32",
+            "armv6-unknown-netbsd-eabihf" => "BSD-generic32",
             "armv7-unknown-freebsd" => "BSD-generic32",
             "armv7-unknown-linux-gnueabi" => "linux-armv4",
             "armv7-unknown-linux-musleabi" => "linux-armv4",
             "armv7-unknown-linux-gnueabihf" => "linux-armv4",
             "armv7-unknown-linux-musleabihf" => "linux-armv4",
+            "armv7-unknown-netbsd-eabihf" => "BSD-generic32",
             "asmjs-unknown-emscripten" => "gcc",
             "i586-unknown-linux-gnu" => "linux-elf",
             "i586-unknown-linux-musl" => "linux-elf",
@@ -264,6 +268,8 @@ impl Build {
             "i686-unknown-freebsd" => "BSD-x86-elf",
             "i686-unknown-linux-gnu" => "linux-elf",
             "i686-unknown-linux-musl" => "linux-elf",
+            "i686-unknown-netbsd" => "BSD-x86-elf",
+            "i586-unknown-netbsd" => "BSD-x86-elf",
             "loongarch64-unknown-linux-gnu" => "linux64-loongarch64",
             "mips-unknown-linux-gnu" => "linux-mips32",
             "mips-unknown-linux-musl" => "linux-mips32",
@@ -273,18 +279,21 @@ impl Build {
             "mips64el-unknown-linux-muslabi64" => "linux64-mips64",
             "mipsel-unknown-linux-gnu" => "linux-mips32",
             "mipsel-unknown-linux-musl" => "linux-mips32",
+            "mipsel-unknown-netbsd" => "NetBSD-generic32",
             "powerpc-unknown-freebsd" => "BSD-generic32",
             "powerpc-unknown-linux-gnu" => "linux-ppc",
             "powerpc-unknown-linux-gnuspe" => "linux-ppc",
             "powerpc64-unknown-freebsd" => "BSD-generic64",
             "powerpc64-unknown-linux-gnu" => "linux-ppc64",
             "powerpc64-unknown-linux-musl" => "linux-ppc64",
+            "powerpc64-unknown-freebsd" => "BSD-generic64",
             "powerpc64le-unknown-freebsd" => "BSD-generic64",
             "powerpc64le-unknown-linux-gnu" => "linux-ppc64le",
             "powerpc64le-unknown-linux-musl" => "linux-ppc64le",
             "riscv64gc-unknown-linux-gnu" => "linux-generic64",
             "s390x-unknown-linux-gnu" => "linux64-s390x",
             "s390x-unknown-linux-musl" => "linux64-s390x",
+            "sparc64-unknown-netbsd" => "BSD-generic64",
             "x86_64-apple-darwin" => "darwin64-x86_64-cc",
             "x86_64-linux-android" => "linux-x86_64",
             "x86_64-pc-windows-gnu" => "mingw64",
