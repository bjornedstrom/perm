/* Copyright (c) 2011 Björn Edström <be@bjrn.se>
   All rights reserved.
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include <getopt.h>

#define VERSION "0.2.0"

int usage(char *name)
{
	fprintf(stderr, "Usage: %s [OPTION] [N]\n\
Print permutations to standard output\n\
\n\
  -l, --lex      lexigraphically permute\n\
  -h, --help     display this help and exit\n\
  -v, --version  output version information and exit\n\
\n\
See man page for more details\n\
",
		name);
	return 1;
}

int version(char *name)
{
	fprintf(stderr, "%s %s\n"
		"Copyright (c) 2011 Bjorn Edstrom <be@bjrn.se>\n",
		name, VERSION);
	return 1;
}

int main(int argc, char** argv)
{
	bool opt_lex = false;

	static struct option const long_options[] =
		{
			{"help", no_argument, NULL, 'h'},
			{"lex", no_argument, NULL, 'l'},
			{"version", no_argument, NULL, 'v'},
			{NULL, 0, NULL, 0}
		};

	int c;
	while ((c = getopt_long (argc, argv, "hlv", long_options, NULL)) != -1) {
		switch (c) {
		case 'l':
			opt_lex = true;
			break;
		case 'h':
			return usage(argv[0]);
		case 'v':
			return version(argv[0]);
		default:
			fprintf(stderr, "Try %s --help for more information.\n",
				argv[0]);
			return 1;
		}
	}

	std::vector<std::string> labels;
	std::vector<int> idx;

	if (optind + 1 == argc) {
		int n = atoi(argv[optind]);

		if (n <= 0 || n > 10000) {
			return usage(argv[0]);
		}

		for (int i = 1; i <= n; i++) {
			char nums[8];
			sprintf(nums, "%d", i);
			labels.push_back(nums);
			idx.push_back(i - 1);
		}
	} else if (optind == argc) {
		std::string line;
		int i = 0;
		while (std::cin >> line) {
			labels.push_back(line);
			idx.push_back(i);
			i++;
		}
	} else {
		return usage(argv[0]);
	}

	size_t s = idx.size();

	if (opt_lex) {
		do {
			for (size_t i = 0; i < s; i++) {
				printf("%s ", labels[i].c_str());
			}
			printf("\n");
		} while (std::next_permutation(labels.begin(), labels.end()));
	} else {
		do {
			for (size_t i = 0; i < s; i++) {
				printf("%s ", labels[idx[i]].c_str());
			}
			printf("\n");
		} while (std::next_permutation(idx.begin(), idx.end()));
	}

	return 0;
}
