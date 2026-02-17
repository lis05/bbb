#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "common/error.h"
#include "parser/symtab.h"

static struct option const long_opts[] = {{"help", 0, nullptr, 'h'}};

static const char *const short_opts = "-ho";

static void print_help() {
    // clang-format off
	printf(
			"bbb compiler.\n"
			"\n"
			"Usage: bbb SOURCE [OPTIONS]"
			"\n"
			"Options:\n"
			"    -h, --help        print help\n"
			"    -o FILE           set destination file\n"
	);
    // clang-format on
}

int main(int argc, char **argv) {
    char  short_option;
    char *source = NULL, *dest = NULL;

	int parse_dest = 0;

    opterr = 0;
    while ((short_option = getopt_long(argc, argv, short_opts, long_opts, 0)) !=
           -1) {
        switch (short_option) {
        case 'h':
            print_help();
            return 0;
		case 'o':
			parse_dest = 1;
			continue;
        case '?':
            if (optopt) {
                quit("Unrecognized option: -%c\n", optopt);
            } else if (argv[optind - 1]) {
                quit("Unrecognized option (possibly '%s')\n", argv[optind - 1]);
            } else {
                quit("Unrecognized option.\n");
            }
			break;
        case 1:
			if (source == NULL) {
				source = argv[optind];
			}
			else if (parse_dest && dest == NULL) {
				dest = argv[optind];
				parse_dest = 0;
			}
			else {
				quit("Invalid argument: %s\n", argv[optind - 1]);
			}
			break;
        default:
            quit("Failed parsing options.\n");
        }
    }

	if (dest == NULL) {
		dest = "out.asm";
	}

    return 0;
}
