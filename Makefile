CC = gcc
CFLAGS += -O2 -Werror -Wall -Wextra -Wno-missing-braces \
          -Wno-missing-field-initializers -Wformat=2 -Wswitch-default \
          -Wswitch-enum -Wcast-align -Wpointer-arith -Wbad-function-cast \
          -Wstrict-overflow=5 -Winline -Wundef -Wnested-externs -Wcast-qual \
          -Wshadow -Wunreachable-code -Wlogical-op -Wfloat-equal \
          -Wstrict-aliasing=2 -Wredundant-decls \
          -Wold-style-definition -Wno-unused-parameter -std=c99

GTK_CFLAGS = `pkg-config --cflags glib-2.0`
GTK_CFLAGS += `pkg-config --cflags gtk+-2.0`
PIDGIN_CFLAGS += `pkg-config --cflags pidgin`

GTK_LIBS = `pkg-config --libs glib-2.0`
GTK_LIBS += `pkg-config --libs gtk+-2.0`
PIDGIN_LIBS += `pkg-config --libs pidgin`

PLUGIN_DIR = ~/.purple/plugins/

leftify_tabs.so: leftify_tabs.o
	$(CC) $(LDFLAGS) -shared $(CFLAGS) $? -o $@ $(PIDGIN_LIBS) $(GTK_LIBS)

leftify_tabs.o: leftify_tabs.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@ $(PIDGIN_CFLAGS) $(GTK_CFLAGS)

clean:
	rm -f leftify_tabs.so
	rm -f *.o

install: leftify_tabs.so
	@echo "Installing leftify_tabs.so"
	mkdir -p $(PLUGIN_DIR)
	cp leftify_tabs.so $(PLUGIN_DIR)
	@echo "Plugin installed to ~/.purple/plugins/"
