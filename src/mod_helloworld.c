#include "base.h"
#include "log.h"
#include "buffer.h"

#include "plugin.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct { PLUGIN_DATA; /* no config */ } plugin_data;

INIT_FUNC(mod_helloworld_init) {

	plugin_data *p;
	p = calloc(1, sizeof(*p));
	puts("Hello World!!!");
	return p;

}

FREE_FUNC(mod_helloworld_free) {

	plugin_data *p = p_d;
	UNUSED(srv);
	if (p) free(p);
	return HANDLER_GO_ON;

}

int mod_helloworld_plugin_init(plugin *p);
int mod_helloworld_plugin_init(plugin *p) {

	p->version = LIGHTTPD_VERSION_ID;
	p->name = buffer_init_string("helloworld");
	p->init = mod_helloworld_init;
	p->cleanup = mod_helloworld_free;
	p->data = NULL;

return 0;

}
