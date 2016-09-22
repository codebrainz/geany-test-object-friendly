#include "helloplugin.h"
#include <geanyplugin.h>

struct _HelloPlugin
{
	GObject parent;
	GeanyPlugin *plugin;
};

G_DEFINE_TYPE(HelloPlugin, hello_plugin, G_TYPE_OBJECT)

static void hello_plugin_set_property(GObject *object, guint prop_id, const GValue *value, GParamSpec *pspec)
{
	if (prop_id == 1)
		HELLO_PLUGIN(object)->plugin = g_value_get_pointer(value);
	else
		G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
}

static void hello_plugin_get_property(GObject *object, guint prop_id, G_GNUC_UNUSED GValue *value, GParamSpec *pspec)
{
	G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
}

static void hello_plugin_class_init(HelloPluginClass *klass)
{
	GObjectClass *oclass = G_OBJECT_CLASS(klass);
	oclass->set_property = hello_plugin_set_property;
	oclass->get_property = hello_plugin_get_property;
	g_object_class_install_property(oclass, 1, g_param_spec_pointer("plugin", "Plugin", "The GeanyPlugin", G_PARAM_CONSTRUCT_ONLY | G_PARAM_WRITABLE));
}

static void hello_plugin_init(G_GNUC_UNUSED HelloPlugin *self)
{
}

gboolean hello_plugin_activate(HelloPlugin *self, G_GNUC_UNUSED gpointer unused)
{
	g_debug("HelloPlugin activated (instance=%p, plugin=%p)", (gpointer) self, (gpointer) self->plugin);
	return TRUE;
}

void hello_plugin_deactivate(HelloPlugin *self, G_GNUC_UNUSED gpointer unused)
{
	g_debug("HelloPlugin deactivated (instance=%p, plugin=%p)", (gpointer) self, (gpointer) self->plugin);
}

GtkWidget *hello_plugin_configure(HelloPlugin *self, G_GNUC_UNUSED GtkDialog *dialog, G_GNUC_UNUSED gpointer unused)
{
	g_debug("HelloPlugin configuring (instance=%p, plugin=%p)", (gpointer) self, (gpointer) self->plugin);
	return gtk_label_new("Nothing to see here");
}

void hello_plugin_help(HelloPlugin *self, G_GNUC_UNUSED gpointer unused)
{
	g_debug("HelloPlugin helping (instance=%p, plugin=%p)", (gpointer) self, (gpointer) self->plugin);
	dialogs_show_msgbox(GTK_MESSAGE_INFO, "Help yourself!");
}
