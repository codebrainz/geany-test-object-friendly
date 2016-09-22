#include "helloplugin.h"
#include <geanyplugin.h>

G_MODULE_EXPORT void
geany_load_module(GeanyPlugin *plugin)
{
	plugin->info->name = "Hello Plugin";
	plugin->info->description = "A stupid plugin";
	plugin->info->version = "one";
	plugin->info->author = "Anonymous";

	plugin->funcs->init_swapped = (GeanyPluginSwappedInitFunc) hello_plugin_activate;
	plugin->funcs->cleanup_swapped = (GeanyPluginSwappedCleanupFunc) hello_plugin_deactivate;
	plugin->funcs->configure_swapped = (GeanyPluginSwappedConfigureFunc) hello_plugin_configure;
	plugin->funcs->help_swapped = (GeanyPluginSwappedHelpFunc) hello_plugin_help;

	GEANY_PLUGIN_REGISTER_OBJECT(plugin, 232, HELLO_TYPE_PLUGIN, "plugin", plugin, NULL);
}
