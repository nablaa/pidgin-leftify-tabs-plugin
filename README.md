# Pidgin leftify tabs plugin

When you have many conversation tabs open, not all of them can fit at the same
time to the tab bar. This is a problem, because it is easy to miss new messages
in tabs that are not visible. This plugin tries to solve this problem by moving
tabs to left whenever a new message arrives.

When a new message is received, the currently active tab is moved to the
leftmost position in the tab bar and the tab receiving the message is moved
next to it.

## Compiling and installing the plugin

Install pre-requisite `pidgin-devel` and `libpurple-devel` packages. On Ubuntu:

	sudo apt-get build-dep pidgin
	sudo apt-get install pidgin-dev libpurple-dev

Compiling the plugin

	make

Installing the plugin to `~/.purple/plugins/`

	make install

Enable plugin *Leftify Tabs* from Pidgin plugins list.
