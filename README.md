# Pidgin leftify tabs plugin

When you have many conversation tabs open, not all of them can fit at the same
time to the tab bar. This is a problem, because it is easy to miss new messages
in tabs that are not visible. This plugin tries to solve this problem by moving
tabs to left whenever a new message arrives.

When a new message is received, the currently active tab is moved to the
leftmost position in the tab bar and the tab receiving the message is moved
next to it.

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
