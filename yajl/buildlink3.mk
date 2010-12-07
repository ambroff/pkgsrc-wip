# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/12/07 21:18:00 pallegra Exp $
BUILDLINK_TREE+=	yajl

.if !defined(YAJL_BUILDLINK3_MK)
YAJL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yajl+=	yajl>=1.0.9
BUILDLINK_PKGSRCDIR.yajl?=	../../wip/yajl
.endif	# YAJL_BUILDLINK3_MK

BUILDLINK_TREE+=	-yajl
