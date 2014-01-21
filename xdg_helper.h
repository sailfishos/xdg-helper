#ifndef XDG_HELPER_H
#define XDG_HELPER_H

#ifdef __cplusplus
extern "C" {
#endif

// Library initialization. Call in main() with argc and argv.
void xdg_helper_init(int argc, char **argv);

// Path configuration. Use as first parameter to xdg_helper_get().
enum xdg_helper_path_t {
    XDG_HELPER_CONFIG_PATH,
    XDG_HELPER_DATA_PATH,
    XDG_HELPER_CACHE_PATH,
};

// Getter function. Don't free the returned string. Returns NULL on error.
const char *xdg_helper_get(enum xdg_helper_path_t which);

#ifdef __cplusplus
};
#endif

#endif /* XDG_HELPER_H */
