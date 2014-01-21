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
