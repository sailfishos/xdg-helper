/**
 * XDG Helper Library
 * Copyright (c) 2014 Jolla Ltd.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 **/

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
