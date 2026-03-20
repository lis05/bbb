#include "layout.h"
#include "../parser/error.h"

static size_t layouts_size;
static size_t layouts_cap;
static const char *layout_names;
static struct layout_t *layouts;

static void layouts_init() {
    if (layouts == 0) {
        layouts_count = 0;
        layouts_cap = 1;
        layout_names = (const char **)malloc(sizeof(const char *));
        log_assert(layout_names != NULL);
        layouts = (struct layout_t*)malloc(sizeof(struct layout_t));
        log_assert(layouts != NULL);
    }
}

void layouts_register(const char *name, struct layout_t layout) {
    layouts_init();

    if (layouts_size == layouts_cap) {
        layouts_cap *= 2;
        layout_names = (const char **)malloc(sizeof(const char *) * layouts_cap);
        log_assert(layout_names != NULL);
        layouts = (struct layout_t*)realloc(sizeof(struct layout_t) * layouts_cap);
        log_assert(layouts != NULL);
    }

    layouts[layouts_size++] = layout;
}
    
int layouts_has(const char *name);
struct layout_t layouts_find(const char *name);

int layout_has_field(const struct layout_t &layout, const char *name);
size_t layout_get_offset(const struct layout_t &layout, const char *name);
