# $NetBSD: options.mk,v 1.21 2021/06/01 05:05:54 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.wine
PKG_SUPPORTED_OPTIONS=		alsa cups dbus gphoto2 pulseaudio sane vulkan x11
PKG_SUGGESTED_OPTIONS=		cups dbus sane x11
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	alsa
.if !empty(PKG_OPTIONS:Malsa)
PLIST.alsa=		yes
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-alsa
.endif

.if !empty(PKG_OPTIONS:Mcups)
.  include "../../print/libcups/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-cups
.endif

.if !empty(PKG_OPTIONS:Mdbus)
.  include "../../sysutils/dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-dbus
.endif

PLIST_VARS+=	gphoto2
.if !empty(PKG_OPTIONS:Mgphoto2)
PLIST.gphoto2=		yes
.  include "../../devel/libgphoto2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gphoto
.endif

PLIST_VARS+=	pulse
.if !empty(PKG_OPTIONS:Mpulseaudio)
PLIST.pulse=		yes
.  include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pulse
.endif

.if !empty(PKG_OPTIONS:Msane)
.  include "../../graphics/sane-backends/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-sane
.endif

.if !empty(PKG_OPTIONS:Mvulkan)
.  include "../../graphics/vulkan-headers/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-vulkan
.endif

PLIST_VARS+=	x11
.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=		yes
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libICE/buildlink3.mk"
.  include "../../x11/libXcomposite/buildlink3.mk"
.  include "../../x11/libXcursor/buildlink3.mk"
.  include "../../x11/libXext/buildlink3.mk"
.  include "../../x11/libXfixes/buildlink3.mk"
.  include "../../x11/libXi/buildlink3.mk"
.  include "../../x11/libXinerama/buildlink3.mk"
.  include "../../x11/libXrandr/buildlink3.mk"
.  include "../../x11/libXrender/buildlink3.mk"
.  include "../../x11/libXxf86vm/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif
