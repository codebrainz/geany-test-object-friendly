#pragma once

#include <gtk/gtk.h>

#define HELLO_TYPE_PLUGIN hello_plugin_get_type()
G_DECLARE_FINAL_TYPE(HelloPlugin, hello_plugin, HELLO, PLUGIN, GObject)

gboolean hello_plugin_activate(HelloPlugin *self, gpointer unused);
void hello_plugin_deactivate(HelloPlugin *self, gpointer unused);
GtkWidget *hello_plugin_configure(HelloPlugin *self, GtkDialog *dialog, gpointer unused);
void hello_plugin_help(HelloPlugin *self, gpointer unused);

