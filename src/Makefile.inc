TGT_INSTALL := $(TGT_INSTALL) src-install
DIST        := $(DIST) src

DISTCLEAN   := $(DISTCLEAN) \
               src/bin/clicraft \
               src/lib/defaults.sh \
               src/etc/clicraft-defaults.conf

INSTALLDIRS := $(INSTALLDIRS) \
               $(DESTDIR)${bindir} \
               $(DESTDIR)${CONFDIR}/action.d \
               $(DESTDIR)${EXECDIR}/action.d \
               $(DESTDIR)${SERVER_DIR}

UNINSTALL := $(UNINSTALL) \
             $(DESTDIR)$(bindir)/clicraft \
             $(DESTDIR)$(EXECDIR)/functions.sh \
             $(DESTDIR)$(EXECDIR)/defaults.sh \
             $(DESTDIR)$(EXECDIR)/action.d/*.sh \
             $(DESTDIR)$(EXECDIR)/defaults.sh \
             $(DESTDIR)$(CONFDIR)/clicraft-defaults.conf \
             $(DESTDIR)$(CONFDIR)/action.d/*.sh.example

.PHONY: src-install
src-install:
	$(INSTALL_PROGRAM) src/bin/clicraft                $(DESTDIR)$(bindir)/clicraft
	$(INSTALL_DATA) src/lib/functions.sh               $(DESTDIR)$(EXECDIR)/functions.sh
	$(INSTALL_DATA) src/lib/defaults.sh                $(DESTDIR)$(EXECDIR)/defaults.sh
	$(INSTALL_DATA) src/lib/action.d/*.sh              $(DESTDIR)$(EXECDIR)/action.d/
	$(INSTALL_DATA) src/etc/clicraft-defaults.conf     $(DESTDIR)$(CONFDIR)/clicraft-defaults.conf
	$(INSTALL_DATA) src/etc/action.d/*.sh.example      $(DESTDIR)$(CONFDIR)/action.d/
	
# vim: set ft=make: