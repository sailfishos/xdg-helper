#include "xdg_helper.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>
#include <sys/types.h>
#include <string.h>
#include <pwd.h>

static char paths[3][MAXPATHLEN];
static const char *appname;

static void determine_path(char *target, const char *xdg_base,
        const char *home_fallback, const char *fallback)
{
    if (xdg_base) {
        snprintf(target, MAXPATHLEN, "%s/%s", xdg_base, appname);
    } else if (getenv("HOME")) {
        snprintf(target, MAXPATHLEN, "%s/%s/%s", getenv("HOME"),
                home_fallback, appname);
    } else if (getpwuid(getuid())) {
        snprintf(target, MAXPATHLEN, "%s/%s/%s", getpwuid(getuid())->pw_dir,
                home_fallback, appname);
    } else {
        snprintf(target, MAXPATHLEN, "%s/%s", fallback, appname);
    }
}

void xdg_helper_init(int argc, char **argv)
{
    // Determine the application name (basename of argv[0])
    const char *slash = strrchr(argv[0], '/');
    appname = slash ? (slash + 1) : argv[0];

    // http://standards.freedesktop.org/basedir-spec/basedir-spec-latest.html
    determine_path(paths[0], getenv("XDG_CONFIG_HOME"), ".config", "config");
    determine_path(paths[1], getenv("XDG_DATA_HOME"), ".local/share", "data");
    determine_path(paths[2], getenv("XDG_CACHE_HOME"), ".cache", "cache");
}

const char *xdg_helper_get(enum xdg_helper_path_t which)
{
    return (which < 0 || which > XDG_HELPER_CACHE_PATH) ? 0 : paths[which];
}
