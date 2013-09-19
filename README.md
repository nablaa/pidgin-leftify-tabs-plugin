# Pidgin leftify tabs plugin

When you have many conversation tabs open, not all of them can be visible at
the same time in the tab bar. This is a problem, because it is easy to miss new
messages that arrive to tabs that are not visible. This plugin tries to solve
this problem by moving a tab to left whenever a new message arrives to it.

When a new message is received, the currently open tab is moved to the
leftmost position in the tab bar and the tab receiving the message is moved
immediately next to it.

## Compiling and installing the plugin

Install pre-requisite `pidgin-devel` and `libpurple-devel` packages. On Ubuntu:

	sudo apt-get build-dep pidgin
	sudo apt-get install pidgin-dev libpurple-dev

Compiling the plugin

	make

Installing the plugin to `~/.purple/plugins/`

	make install

Enable plugin *Leftify Tabs* from Pidgin plugins list.
