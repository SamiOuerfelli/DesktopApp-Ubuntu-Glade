## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = admin_user

admin_user_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	fonction_sami.c fonction_sami.h \
	bureau.c bureau.h \
	function.c function.h \
	reclamation.c reclamation.h \
	CRUD.c CRUD.h


admin_user_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

