# $Id: Makefile,v 1.499 2003/09/25 16:09:48 xtraeme Exp $
# $NetBSD: Makefile,v 1.499 2003/09/25 16:09:48 xtraeme Exp $

COMMENT=	WIP pkgsrc packages

SUBDIR+=	4stAttack
SUBDIR+=	PPower4
SUBDIR+=	Radiator
SUBDIR+=	Radiator-all
SUBDIR+=	Redland-rdf
SUBDIR+=	WEPCrack
SUBDIR+=	XFree86
SUBDIR+=	XFree86-clients
SUBDIR+=	XFree86-docs
SUBDIR+=	XFree86-fonts100dpi
SUBDIR+=	XFree86-fonts75dpi
SUBDIR+=	XFree86-fontsCyrillic
SUBDIR+=	XFree86-fontsEncodings
SUBDIR+=	XFree86-fontsMisc
SUBDIR+=	XFree86-fontsScalable
SUBDIR+=	XFree86-fontserver
SUBDIR+=	XFree86-libs
SUBDIR+=	XFree86-man
SUBDIR+=	XFree86-server
SUBDIR+=	abuse_sdl
SUBDIR+=	acid
SUBDIR+=	adodb
SUBDIR+=	afterstep2
SUBDIR+=	aget
SUBDIR+=	allegro
SUBDIR+=	amap
SUBDIR+=	amavisd-new
SUBDIR+=	amsn
SUBDIR+=	aolserver
SUBDIR+=	ap-bunzip2
SUBDIR+=	ap-frontpage
SUBDIR+=	ap-ometer
SUBDIR+=	ap-security
SUBDIR+=	ap2-python
SUBDIR+=	ap2-security
SUBDIR+=	ap2-xslt
SUBDIR+=	apotheke
SUBDIR+=	argouml
SUBDIR+=	armagetron
SUBDIR+=	asfrecorder
SUBDIR+=	atasm
SUBDIR+=	autoproject
SUBDIR+=	avida2
SUBDIR+=	axe
SUBDIR+=	barnyard
SUBDIR+=	bastard
SUBDIR+=	bc
SUBDIR+=	beast
SUBDIR+=	billardgl
SUBDIR+=	bin86
SUBDIR+=	boost-base
SUBDIR+=	boost-thread
SUBDIR+=	bub-n-bros
SUBDIR+=	bugzilla
SUBDIR+=	busybox
SUBDIR+=	byacc
SUBDIR+=	cawf
SUBDIR+=	ccrypt
SUBDIR+=	cdl3
SUBDIR+=	cdpr
SUBDIR+=	cgdb
SUBDIR+=	cgic
SUBDIR+=	cherokee
SUBDIR+=	chksniff
SUBDIR+=	chmlib
SUBDIR+=	cjk-latex
SUBDIR+=	cjk-latex-chinese
SUBDIR+=	cjk-latex-japanese
SUBDIR+=	cjk-latex-korean
SUBDIR+=	cops
SUBDIR+=	cvsd
SUBDIR+=	cyrus-imapd22
SUBDIR+=	dancer-ircd
SUBDIR+=	darcnes-svgalib
SUBDIR+=	darkice
SUBDIR+=	dasm
SUBDIR+=	dbf
SUBDIR+=	dfbpoint
SUBDIR+=	dfbsee
SUBDIR+=	dfm
SUBDIR+=	directfb
SUBDIR+=	directory-administrator
SUBDIR+=	distella
SUBDIR+=	dnsmasq
SUBDIR+=	dpkg
SUBDIR+=	drweb
SUBDIR+=	drweb-clients-shared
SUBDIR+=	drweb-dc
SUBDIR+=	drweb-smf
SUBDIR+=	drwright
SUBDIR+=	dumb
SUBDIR+=	dzt
SUBDIR+=	eag
SUBDIR+=	ed
SUBDIR+=	eic
SUBDIR+=	elvis
SUBDIR+=	elvis-x11
SUBDIR+=	emirror
SUBDIR+=	entropy
SUBDIR+=	ezbounce
SUBDIR+=	festival-gaim
SUBDIR+=	fluxconf
SUBDIR+=	fluxspace
SUBDIR+=	fragroute
SUBDIR+=	freeglut
SUBDIR+=	freenet-tools
SUBDIR+=	fribidi
SUBDIR+=	frontpage
SUBDIR+=	fsv
SUBDIR+=	fwbuilder
SUBDIR+=	galib
SUBDIR+=	gcompris
SUBDIR+=	gdbada
SUBDIR+=	gdrdao
SUBDIR+=	geeklog
SUBDIR+=	gift
SUBDIR+=	giftcurs
SUBDIR+=	giftui
SUBDIR+=	gimp-current
SUBDIR+=	gkrellm-launch
SUBDIR+=	gkrellm-reminder
SUBDIR+=	gkrellm2
SUBDIR+=	gkrellm2-flynn
SUBDIR+=	gkrellm2-launch
SUBDIR+=	gkrellm2-leds
SUBDIR+=	gkrellm2-multiping
SUBDIR+=	gkrellm2-server
SUBDIR+=	gkrellm2-share
SUBDIR+=	gkrellm2-snmp
SUBDIR+=	gkrellm2-volume
SUBDIR+=	gkrellm2-xmms
SUBDIR+=	gl-117
SUBDIR+=	glaxium
SUBDIR+=	gnome2-extras
SUBDIR+=	gnome2-pkgview
SUBDIR+=	gnome2-system-monitor
SUBDIR+=	gnome2-themes-extra
SUBDIR+=	gnomeicu
SUBDIR+=	gnucash-docs
SUBDIR+=	gnunet
SUBDIR+=	gotmail
SUBDIR+=	gov2
SUBDIR+=	grip
SUBDIR+=	gstreamer-player
SUBDIR+=	gtick
SUBDIR+=	gtk-engines-thinice
SUBDIR+=	gtk-sharp
SUBDIR+=	gtk-theme-switch
SUBDIR+=	gtk2-engines-mist
SUBDIR+=	gtkpod
SUBDIR+=	gurlchecker
SUBDIR+=	hasciicam
SUBDIR+=	ht
SUBDIR+=	ht2html
SUBDIR+=	html2latex
SUBDIR+=	httrack
SUBDIR+=	hydra
SUBDIR+=	hydrogen
SUBDIR+=	ices
SUBDIR+=	icmpchat
SUBDIR+=	idled
SUBDIR+=	igal
SUBDIR+=	iisemulator
SUBDIR+=	ike-scan
SUBDIR+=	ilohamail
SUBDIR+=	imake
SUBDIR+=	imhangul
SUBDIR+=	imhangul_status_applet
SUBDIR+=	ion-devel
SUBDIR+=	ion-dock
SUBDIR+=	ish
SUBDIR+=	jabberd
SUBDIR+=	jabberd2
SUBDIR+=	jakarta-log4j
SUBDIR+=	jazz
SUBDIR+=	jdk12
SUBDIR+=	jdk12-openjit
SUBDIR+=	jdk13
SUBDIR+=	jdk13-openjit
SUBDIR+=	jigdo
SUBDIR+=	kannel-gateway
SUBDIR+=	kapital
SUBDIR+=	kgpg
SUBDIR+=	kmplayer
SUBDIR+=	koffice-i18n-de
SUBDIR+=	koffice-i18n-es
SUBDIR+=	korelib
SUBDIR+=	kvirc
SUBDIR+=	lash
SUBDIR+=	lbdb
SUBDIR+=	ldapbrowser
SUBDIR+=	ldapdns
SUBDIR+=	lde
SUBDIR+=	libdialog
SUBDIR+=	libdisasm
SUBDIR+=	libfwbuilder
SUBDIR+=	libgringotts
SUBDIR+=	libhydrogen
SUBDIR+=	libneural
SUBDIR+=	libogg-nightly
SUBDIR+=	libshout
SUBDIR+=	libvc
SUBDIR+=	libvorbis-nightly
SUBDIR+=	libwpd
SUBDIR+=	libxfce4gui
SUBDIR+=	libxfce4mcs
SUBDIR+=	libxfce4util
SUBDIR+=	liferea
SUBDIR+=	lincvs
SUBDIR+=	links-hacked
SUBDIR+=	linux-modutils
SUBDIR+=	linux-nfs-utils
SUBDIR+=	liquidwar
SUBDIR+=	lletters
SUBDIR+=	lmarbles
SUBDIR+=	mailfilter
SUBDIR+=	mailman
SUBDIR+=	man-db
SUBDIR+=	map-browse
SUBDIR+=	mathomatic
SUBDIR+=	mc
SUBDIR+=	mcats
SUBDIR+=	mcats-iodbc
SUBDIR+=	memtester
SUBDIR+=	mhonarc
SUBDIR+=	mit-krb5
SUBDIR+=	mixer.tk
SUBDIR+=	mixmaster
SUBDIR+=	monkey-bubble
SUBDIR+=	mopac
SUBDIR+=	mplusfonts
SUBDIR+=	mtf
SUBDIR+=	muse
SUBDIR+=	mutella
SUBDIR+=	mutt-devel
SUBDIR+=	mutt-vc-query
SUBDIR+=	mysql3-client
SUBDIR+=	mysql3-server
SUBDIR+=	mysql4-client
SUBDIR+=	mysql4-server
SUBDIR+=	nabi
SUBDIR+=	nagios-base
SUBDIR+=	nagios-plugin-ldap
SUBDIR+=	nagios-plugin-mysql
SUBDIR+=	nagios-plugin-pgsql
SUBDIR+=	nagios-plugin-snmp
SUBDIR+=	nagios-plugins
SUBDIR+=	nautilus-media
SUBDIR+=	navigatrix
SUBDIR+=	ncps
SUBDIR+=	net-tools
SUBDIR+=	netbeans-ide
SUBDIR+=	netkit-base
SUBDIR+=	newsx
SUBDIR+=	nikto
SUBDIR+=	noip
SUBDIR+=	ntp4-dev
SUBDIR+=	nvtv
SUBDIR+=	nvtv-gtk2
SUBDIR+=	obconf
SUBDIR+=	oinkmaster
SUBDIR+=	opax
SUBDIR+=	openbox3
SUBDIR+=	openvpn
SUBDIR+=	p5-CDDB
SUBDIR+=	p5-Chart
SUBDIR+=	p5-Class-Factory-Util
SUBDIR+=	p5-Class-MethodMaker
SUBDIR+=	p5-Class-Singleton
SUBDIR+=	p5-DBI-Shell
SUBDIR+=	p5-Data-TemporaryBag
SUBDIR+=	p5-DateTime
SUBDIR+=	p5-DateTime-Event-Cron
SUBDIR+=	p5-DateTime-LeapSecond
SUBDIR+=	p5-DateTime-Set
SUBDIR+=	p5-DateTime-TimeZone
SUBDIR+=	p5-File-Tail
SUBDIR+=	p5-GeoIP
SUBDIR+=	p5-GnuPG-Interface
SUBDIR+=	p5-HTML-Latex
SUBDIR+=	p5-HTTP-GHTTP
SUBDIR+=	p5-IO-Tee
SUBDIR+=	p5-Net-Pcap
SUBDIR+=	p5-SWF-File
SUBDIR+=	p5-Scalar-List-Utils
SUBDIR+=	p5-Set-Crontab
SUBDIR+=	p5-Set-Infinite
SUBDIR+=	p5-String-Approx
SUBDIR+=	p5-Text-Reform
SUBDIR+=	p5-Tk-TableMatrix
SUBDIR+=	p5-gtk2
SUBDIR+=	palm-db-tools
SUBDIR+=	pdb2ldif
SUBDIR+=	pdns
SUBDIR+=	pear-Date
SUBDIR+=	pear-HTML_Common
SUBDIR+=	pear-HTML_Select
SUBDIR+=	pear-Log
SUBDIR+=	perl58
SUBDIR+=	perltidy
SUBDIR+=	pgp6
SUBDIR+=	pgpenvelope
SUBDIR+=	php-jpgraph
#SUBDIR+=	php4			# not a package
SUBDIR+=	php4-exif
SUBDIR+=	php4-mysql4
SUBDIR+=	picasm
SUBDIR+=	picprog
SUBDIR+=	pinball
SUBDIR+=	plugger
SUBDIR+=	pnet
SUBDIR+=	pnetlib
SUBDIR+=	poedit
SUBDIR+=	portmap
SUBDIR+=	postal
SUBDIR+=	ppp
SUBDIR+=	premake
SUBDIR+=	procps
SUBDIR+=	prtunnel
SUBDIR+=	psh
SUBDIR+=	pts
SUBDIR+=	py23-html-docs
SUBDIR+=	py-OpenGL
SUBDIR+=	py-OpenSSL
SUBDIR+=	py-RXP
SUBDIR+=	py-SimpleParse
SUBDIR+=	py-albatross
SUBDIR+=	py-biggles
SUBDIR+=	py-elementtree
SUBDIR+=	py-game
SUBDIR+=	py-generateDS
SUBDIR+=	py-gnosis-utils
SUBDIR+=	py-gopherd
SUBDIR+=	py-libpcap
SUBDIR+=	py-psyco
SUBDIR+=	py-spark
SUBDIR+=	py-spreadmodule
SUBDIR+=	py-twisted
SUBDIR+=	q3-urbanterror
SUBDIR+=	qico
SUBDIR+=	qinx
SUBDIR+=	qn-x11
SUBDIR+=	rapidsvn
SUBDIR+=	rc.subr
SUBDIR+=	rcorder
SUBDIR+=	regexxer
SUBDIR+=	ripmime
SUBDIR+=	rlpr
SUBDIR+=	rolo
SUBDIR+=	rosegarden-current
SUBDIR+=	samba3
SUBDIR+=	scm
SUBDIR+=	scons
SUBDIR+=	scponly
SUBDIR+=	shoutcast
SUBDIR+=	slocate
SUBDIR+=	slrn-pl
SUBDIR+=	smtpscan
SUBDIR+=	socat
SUBDIR+=	speedx
SUBDIR+=	sredird
SUBDIR+=	srvx
SUBDIR+=	stickynotes-applet
SUBDIR+=	strace
SUBDIR+=	streamripper
SUBDIR+=	sudoscript
SUBDIR+=	superkaramba
SUBDIR+=	svgalib
SUBDIR+=	sysklogd
SUBDIR+=	sysvinit
SUBDIR+=	tads
SUBDIR+=	tcc
SUBDIR+=	tendra
SUBDIR+=	tetrinet
SUBDIR+=	tetrinetx
SUBDIR+=	tex-foiltex
SUBDIR+=	tex-prosper
SUBDIR+=	thaixfonts
SUBDIR+=	thcrut
SUBDIR+=	theme-gtk-bluecurve
SUBDIR+=	theora-nightly
SUBDIR+=	thy
SUBDIR+=	tinc
SUBDIR+=	tinylogin
SUBDIR+=	toppler
SUBDIR+=	totem
SUBDIR+=	treecc
SUBDIR+=	tsm
SUBDIR+=	tutos
SUBDIR+=	tuxtype2
SUBDIR+=	typhoon
SUBDIR+=	uclibc
SUBDIR+=	udhcp
SUBDIR+=	umix
SUBDIR+=	unmo3
SUBDIR+=	upx
SUBDIR+=	vba
SUBDIR+=	vcdgear
SUBDIR+=	viewcvs
SUBDIR+=	vixie-cron
SUBDIR+=	vlc
SUBDIR+=	vmac
SUBDIR+=	vmsbackup
SUBDIR+=	vte
SUBDIR+=	weewm
SUBDIR+=	wmclockmon
SUBDIR+=	wmitime
SUBDIR+=	wmnetload
SUBDIR+=	words
SUBDIR+=	xawtv
SUBDIR+=	xchm
SUBDIR+=	xevil
SUBDIR+=	xfce4
SUBDIR+=	xfce4-artwork
SUBDIR+=	xfce4-desktop
SUBDIR+=	xfce4-fm
SUBDIR+=	xfce4-fm-icons
SUBDIR+=	xfce4-gtk2-engines
SUBDIR+=	xfce4-iconbox
SUBDIR+=	xfce4-mcs-manager
SUBDIR+=	xfce4-mcs-plugins
SUBDIR+=	xfce4-minicmd-plugin
SUBDIR+=	xfce4-mixer
SUBDIR+=	xfce4-netload-plugin
SUBDIR+=	xfce4-panel
SUBDIR+=	xfce4-print
SUBDIR+=	xfce4-showdesktop-plugin
SUBDIR+=	xfce4-systemload-plugin
SUBDIR+=	xfce4-systray
SUBDIR+=	xfce4-themes
SUBDIR+=	xfce4-toys
SUBDIR+=	xfce4-trigger-launcher
SUBDIR+=	xfce4-utils
SUBDIR+=	xfce4-wm
SUBDIR+=	xfce4-wm-themes
SUBDIR+=	xmail
SUBDIR+=	xml2doc
SUBDIR+=	xmmsctrl
SUBDIR+=	xmms-dumb
SUBDIR+=	xmms-modplug
SUBDIR+=	xmms-pitch
SUBDIR+=	xplore
SUBDIR+=	xsh
SUBDIR+=	yafray
SUBDIR+=	zebra-pj
SUBDIR+=	zenity
SUBDIR+=	zinf

.include "../mk/bsd.pkg.subdir.mk"
