#include "xdg_helper.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
    xdg_helper_init(argc, argv);

    printf("Config path: '%s'\n", xdg_helper_get(XDG_HELPER_CONFIG_PATH));
    printf("Data path: '%s'\n", xdg_helper_get(XDG_HELPER_DATA_PATH));
    printf("Cache path: '%s'\n", xdg_helper_get(XDG_HELPER_CACHE_PATH));

    return 0;
}
