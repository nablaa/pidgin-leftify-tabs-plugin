# Pidgin leftify tabs plugin

This plugin moves a conversation tab to the leftmost position whenever
it receives a new message. New conversations are also spawned to the leftmost
position in tab row.

## Compiling plugin

Install pre-requisite packages. In Ubuntu:

	sudo apt-get build-dep pidgin
	sudo apt-get install pidgin-dev libpurple-dev

Download Pidgin source and compile it:

	./configure
	make

Move `leftify_tabs.c` to `pidgin/plugins` inside Pidgin source directory and
make the plugin there:

	cd pidgin/plugins
	make leftify_tabs.so

## Installing plugin

Copy compiled plugin file to your own Pidgin plugin directory:

	cp leftify_tabs.so ~/.purple/plugins

Enable plugin from Pidgin plugins list.
