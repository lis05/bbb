#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "common/common.h"
#include "parser/token.h"

static struct option const long_opts[] = {{"help", 0, NULL, 'h'}};

static const char *const short_opts = "-hov";

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
	);
    // clang-format on
}

int main(int argc, char **argv) {
    char  short_option;
    char *source = NULL, *dest = NULL;
	int verbosity = LOG_LEVEL_ERROR;

    int parse_dest = 0;

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
            if (source == NULL) {
                source = argv[optind - 1];
            } else if (parse_dest && dest == NULL) {
                dest = argv[optind - 1];
                parse_dest = 0;
            } else {
                log_crit("Invalid argument: %s\n", argv[optind - 1]);
            }
            break;
        default:
            log_crit("Failed parsing options.\n");
        }
    }

    if (dest == NULL) {
        dest = "out.asm";
    }

	log_debug("src: %s\n", source);
	log_debug("dest: %s\n", dest);

    return 0;
}
