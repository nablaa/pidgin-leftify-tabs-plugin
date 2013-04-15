#define PURPLE_PLUGINS

#include <glib.h>

#include "notify.h"
#include "plugin.h"
#include "version.h"
#include "gtkplugin.h"
#include "gtkconv.h"


static void move_conversation_tabs_to_left(PurpleConversation *conv) {
    gint position = 0; // Leftmost position
    PidginConversation *gtkconv;
    PidginWindow *win;
    gint current_page;

    if (!conv) {
        return;
    }

    gtkconv = PIDGIN_CONVERSATION(conv);
    if (!gtkconv || !gtkconv->tab_cont) {
        return;
    }

    win = pidgin_conv_get_window(gtkconv);
    if (!win || !win->notebook) {
        return;
    }

    // Move the current tab to the leftmost position and the tab with activity
    // next to it.
    current_page = gtk_notebook_get_current_page(GTK_NOTEBOOK(win->notebook));
    gtk_notebook_reorder_child(GTK_NOTEBOOK(win->notebook),
                               gtk_notebook_get_nth_page(GTK_NOTEBOOK(win->notebook),
                                                         current_page),
                               position);

    gtk_notebook_reorder_child(GTK_NOTEBOOK(win->notebook),
                               gtkconv->tab_cont, position + 1);
}

static void
received_im_msg_cb(PurpleAccount *account, char *sender, char *message,
                   PurpleConversation *conv, PurpleMessageFlags flags) {
    move_conversation_tabs_to_left(conv);
}

static void
conversation_created_cb(PurpleConversation *conv) {
    move_conversation_tabs_to_left(conv);
}

static void
received_chat_msg_cb(PurpleAccount *account, char *sender, char *message,
                     PurpleConversation *conv, PurpleMessageFlags flags) {
    move_conversation_tabs_to_left(conv);
}

static void
got_attention_cb(PurpleAccount *account, const char *who,
                 PurpleConversation *conv, guint type) {
    move_conversation_tabs_to_left(conv);
}

static gboolean
plugin_load(PurplePlugin *plugin) {
    void *convs_handle;
    convs_handle = purple_conversations_get_handle();

    purple_signal_connect(convs_handle, "received-im-msg", plugin,
                          PURPLE_CALLBACK(received_im_msg_cb), NULL);

    purple_signal_connect(convs_handle, "conversation-created", plugin,
                          PURPLE_CALLBACK(conversation_created_cb), NULL);

    purple_signal_connect(convs_handle, "received-chat-msg", plugin,
                          PURPLE_CALLBACK(received_chat_msg_cb), NULL);

    purple_signal_connect(convs_handle, "got-attention", plugin,
                          PURPLE_CALLBACK(got_attention_cb), NULL);

    return TRUE;
}

static PurplePluginInfo info = {
    PURPLE_PLUGIN_MAGIC,
    PURPLE_MAJOR_VERSION,
    PURPLE_MINOR_VERSION,
    PURPLE_PLUGIN_STANDARD,
    PIDGIN_PLUGIN_TYPE,
    0,
    NULL,
    PURPLE_PRIORITY_DEFAULT,

    "gtk-nablaa-leftify_tabs",
    "Leftify tabs",
    "0.1",

    "Moves tab to leftmost position when messages arrive",
    "A tab is moved to the leftmost position whenever a message arrives",
    "Miika-Petteri Matikainen <miikapetteri@gmail.com>",
    "http://github.com/nablaa/pidgin-leftify-tabs-plugin",

    plugin_load,
    NULL,
    NULL,

    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

static void
init_plugin(PurplePlugin *plugin) {
}

PURPLE_INIT_PLUGIN(leftify_tabs, init_plugin, info)
