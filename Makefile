# Makefile for 'perm'

INSTALL=install -o root

all:
	g++ perm.cpp -o perm

install:
	$(INSTALL) -d $(DESTDIR)/usr/bin/
	$(INSTALL) perm $(DESTDIR)/usr/bin/
