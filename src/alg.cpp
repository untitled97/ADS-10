// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"
#include <string>
#include <vector>

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<std::vector<char>> permutations = tree.getAllPermutations();
    if (n > permutations.size())
        return {};
    return permutations[n - 1];
}

