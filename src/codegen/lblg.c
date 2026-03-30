#include "lblg.h"

#include "../common/common.h"
#include "../parser/token.h"

void lblg_init(struct label_generator_t *lblg) {
    lblg->n = 0;
    lblg->cap = 1;
    lblg->labels = (char **)malloc(sizeof(char *));
    log_assert(lblg->labels != NULL);
}

void lblg_destroy(struct label_generator_t *lblg) {
    for (size_t i = 0; i < lblg->n; i++) {
        free(lblg->labels[i]);
    }
    free(lblg->labels);
}

const char *lblg_gen(struct label_generator_t *lblg) {
    if (lblg->n == lblg->cap) {
        lblg->cap *= 2;
        lblg->labels =
            (char **)realloc(lblg->labels, sizeof(char *) * lblg->cap);
        log_assert(lblg->labels != NULL);
    }

    log_assert(-1 != asprintf(lblg->labels + lblg->n, ".bbb_L%zu", lblg->n));
    return lblg->labels[lblg->n++];
}
