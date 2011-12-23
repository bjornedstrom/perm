/* Copyright (c) 2011 Björn Edström <be@bjrn.se>
   All rights reserved.
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

int usage(char *name)
{
	fprintf(stderr, "Usage: %s [N]\n"
		"Print all permutations to standard output\n",
		name);
	return 1;
}

int main(int argc, char** argv)
{
	std::vector<std::string> ar;

	if (argc == 2) {
		int n = atoi(argv[1]);

		if (n <= 0 || n > 10000) {
			return usage(argv[0]);
		}

		for (int i = 1; i <= n; i++) {
			char nums[8];
			sprintf(nums, "%d", i);
			ar.push_back(nums);
		}
	} else if (argc == 1) {
		std::string line;
		while (std::cin >> line) {
			ar.push_back(line);
		}
	} else {
		return usage(argv[0]);
	}

	size_t s = ar.size();
	do {
		for (size_t i = 0; i < s; i++) {
			printf("%s ", ar[i].c_str());
		}
		printf("\n");
	} while (std::next_permutation(ar.begin(), ar.end()));

	return 0;
}
