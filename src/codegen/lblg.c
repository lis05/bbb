#include "lblg.h"

void lblg_init(struct label_generator_t *lblg NONULL) MEMSAFE {
    lblg->n = 0;
    lblg->cap = 1;
    lblg->labels = (char **)calloc_safe(1, sizeof(char *));
}

void lblg_destroy(struct label_generator_t *lblg NONULL) MEMSAFE {
    for (size_t i = 0; i < lblg->n; i++) {
        free(lblg->labels[i]);
    }
    free(lblg->labels);
}

const char *NONULL NOFREE lblg_gen(struct label_generator_t *lblg NONULL) MEMSAFE {
    if (lblg->n == lblg->cap) {
        lblg->cap *= 2;
        lblg->labels =
            (char **)realloc_safe(lblg->labels, sizeof(char *) * lblg->cap);
    }

    lblg->labels[lblg->n] = asprintf_safe("._L%zu", lblg->n);
    return lblg->labels[lblg->n++];
}

const char *NONULL NOFREE lblg_gen_double_lit() MEMSAFE {
    static struct label_generator_t *lblg = NULL;
    if (lblg == NULL) {
        lblg = (struct label_generator_t *)calloc_safe(
            1, sizeof(struct label_generator_t));
        lblg_init(lblg);
    }

    if (lblg->n == lblg->cap) {
        lblg->cap *= 2;
        lblg->labels =
            (char **)realloc_safe(lblg->labels, sizeof(char *) * lblg->cap);
    }

    static size_t cnt = 0;

    lblg->labels[lblg->n] = asprintf_safe("_double_lit_%zu", cnt++);
    return lblg->labels[lblg->n++];
}

const char *NONULL NOFREE lblg_gen_string_lit() MEMSAFE {
    static struct label_generator_t *lblg = NULL;
    if (lblg == NULL) {
        lblg = (struct label_generator_t *)calloc_safe(
            1, sizeof(struct label_generator_t));
        lblg_init(lblg);
    }

    if (lblg->n == lblg->cap) {
        lblg->cap *= 2;
        lblg->labels =
            (char **)realloc_safe(lblg->labels, sizeof(char *) * lblg->cap);
    }

    static size_t cnt = 0;

    lblg->labels[lblg->n] = asprintf_safe("_str_lit_%zu", cnt++);
    return lblg->labels[lblg->n++];
}
