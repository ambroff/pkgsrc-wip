# $NetBSD: $

BUILDLINK_TREE+=	libsml

.if !defined(LIBSML_BUILDLINK3_MK)
LIBSML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsml+=	libsml>=1.1.3
BUILDLINK_PKGSRCDIR.libsml?=	../../wip/libsml

.endif # LIBSML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsml
