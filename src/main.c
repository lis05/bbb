#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "codegen/gen.h"
#include "common/common.h"
#include "parser/ast.h"
#include "parser/parser.h"
#include "codegen/settings.h"

static struct option const long_opts[] = {{"help", 0, NULL, 'h'}};

static const char *const short_opts = "-hoOvpPlce";  // fix -o

static void print_help() {
    // clang-format off
	printf(
			"bbb compiler.\n"
			"\n"
			"Usage: bbb SOURCE [OPTIONS]"
			"\n"
			"Options:\n"
			"    -h, --help        print help\n"
			"    -v                increase verbosity level\n"
			"    -o FILE           set destination file\n"
            "    -O                print output to stdout rather than a file\n"
            "    -p                print parser output and stop\n"
            "    -P                print parser output\n"
            "    -l                print lexemes\n"
            ""
            "    -c                add explanatory comments to the generated nasm.\n"
            "    -e                messages print location in the source code.\n"
	);
    // clang-format on
}

int main(int argc, char **argv) {
    char  short_option;
    char *source = NULL, *dest = NULL;
    int   verbosity = LOG_LEVEL_ERROR;

    int print_output = 0;
    int stop_after_parser = 0;
    int parse_dest = 0;
    int print_parser = 0;

    opterr = 0;
    while ((short_option = getopt_long(argc, argv, short_opts, long_opts, 0)) !=
           -1) {
        switch (short_option) {
        case 'h':
            print_help();
            return 0;
        case 'v':
            set_log_level(++verbosity);
            break;
        case 'o':
            parse_dest = 1;
            continue;
        case 'O':
            print_output = 1;
            continue;
        case 'p':
            print_parser = 1;
            stop_after_parser = 1;
            continue;
        case 'P':
            print_parser = 1;
            continue;
        case 'l':
            print_lexemes = 1;
            continue;
        case 'c':
            add_explanatory_comments = 1;
            continue;
        case 'e':
            messages_print_location = 1;
            continue;
        case '?':
            if (optopt) {
                log_crit("Unrecognized option: -%c\n", optopt);
            } else if (argv[optind - 1]) {
                log_crit("Unrecognized option (possibly '%s')\n", argv[optind - 1]);
            } else {
                log_crit("Unrecognized option.\n");
            }
            break;
        case 1:
            if (parse_dest && dest == NULL) {
                dest = argv[optind - 1];
            } else if (source == NULL) {
                source = argv[optind - 1];
            } else {
                log_crit("Invalid argument: %s\n", argv[optind - 1]);
            }
            break;
        default:
            log_crit("Failed parsing options.\n");
        }
    }

    if (source == NULL) {
        log_msg("No source provided. Aborting.\n");
        return -1;
    }

    if (dest == NULL) {
        dest = "out.asm";
    }

    log_debug("src: %s\n", source);
    log_debug("dest: %s\n", dest);

    parser_init();
    struct program_node_t *prog = parser_parse(source);
    log_info("Parser has finished.\n");
    if (prog == NULL) {
        log_msg("Compilation did not succeed.\n");
        log_msg("Aborting.\n");
        return -1;
    }

    if (print_parser) {
        ast_print_program_node(prog, 0);
        if (stop_after_parser) {
            return 0;
        }
    }

    FILE *out = NULL;
    if (print_output) {
        out = stdout;
    } else if (dest != NULL) {
        out = fopen(dest, "w");
        if (out == NULL) {
            log_msg("Failed to write output to %s: %s\n", dest, strerror(errno));
            return -1;
        }
    }

    cb_t res = gen(prog);
    log_info("Codegen has finished.\n");
    if (!cb_is_valid(&res)) {
        log_msg("Codegen failed.\n");
        return -1;
    }

    cb_print(out, &res);

    if (out != stdout) {
        fclose(out);
    }
    return 0;
}
