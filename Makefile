# nuff - fork of a presentation tool
# See LICENSE file for copyright and license details.

include config.mk

SRC = nuff.c drw.c util.c
OBJ = ${SRC:.c=.o}

all: options nuff

options:
	@echo nuff build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

config.h:
	cp config.def.h config.h

.c.o:
	@echo CC $<
	@${CC} -c ${CFLAGS} $<

${OBJ}: config.h config.mk

nuff: ${OBJ}
	@echo CC -o $@
	@${CC} -o $@ ${OBJ} ${LDFLAGS}

cscope: ${SRC} config.h
	@echo cScope
	@cscope -R -b || echo cScope not installed

clean:
	@echo cleaning
	@rm -f nuff ${OBJ} nuff-${VERSION}.tar.gz

dist: clean
	@echo creating dist tarball
	@mkdir -p nuff-${VERSION}
	@cp -R LICENSE Makefile config.mk config.def.h ${SRC} nuff-${VERSION}
	@tar -cf nuff-${VERSION}.tar nuff-${VERSION}
	@gzip nuff-${VERSION}.tar
	@rm -rf nuff-${VERSION}

install: all
	@echo installing executable file to ${DESTDIR}${PREFIX}/bin
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f nuff ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/nuff
	@echo installing manual page to ${DESTDIR}${MANPREFIX}/man1
	@mkdir -p ${DESTDIR}${MANPREFIX}/man1
	@cp nuff.1 ${DESTDIR}${MANPREFIX}/man1/nuff.1
	@chmod 644 ${DESTDIR}${MANPREFIX}/man1/nuff.1

uninstall:
	@echo removing executable file from ${DESTDIR}${PREFIX}/bin
	@rm -f ${DESTDIR}${PREFIX}/bin/nuff

.PHONY: all options clean dist install uninstall cscope
