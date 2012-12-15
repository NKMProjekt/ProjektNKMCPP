## Process this file with automake to produce Makefile.in
## Created by Anjuta

SUBDIRS = src 

tetrisdocdir = ${prefix}/doc/tetris
tetrisdoc_DATA = \
	README\
	COPYING\
	AUTHORS\
	ChangeLog\
	INSTALL\
	NEWS


EXTRA_DIST = $(tetrisdoc_DATA)


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(tetrisdocdir)
