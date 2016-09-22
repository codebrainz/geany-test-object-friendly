#include "helloplugin.h"
#include <geanyplugin.h>

static gboolean init_wrapper(GeanyPlugin *plugin, gpointer pdata)
{
	return hello_plugin_activate(pdata, plugin);
}

static void cleanup_wrapper(GeanyPlugin *plugin, gpointer pdata)
{
	hello_plugin_deactivate(pdata, plugin);
}

static GtkWidget *configure_wrapper(GeanyPlugin *plugin, GtkDialog *dialog, gpointer pdata)
{
	return hello_plugin_configure(pdata, dialog, plugin);
}

static void help_wrapper(GeanyPlugin *plugin, gpointer pdata)
{
	hello_plugin_help(pdata, plugin);
}

G_MODULE_EXPORT void
geany_load_module(GeanyPlugin *plugin)
{
	plugin->info->name = "Hello Plugin";
	plugin->info->description = "A stupid plugin";
	plugin->info->version = "one";
	plugin->info->author = "Anonymous";

	plugin->funcs->init = init_wrapper;
	plugin->funcs->cleanup = cleanup_wrapper;
	plugin->funcs->configure = configure_wrapper;
	plugin->funcs->help = help_wrapper;

	plugin_module_make_resident(plugin);
	GEANY_PLUGIN_REGISTER_FULL(plugin, 230, g_object_new(HELLO_TYPE_PLUGIN, "plugin", plugin, NULL), g_object_unref);
}
