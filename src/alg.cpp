// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
 BST<std::string> tree;
  std::ifstream file(filename);
  std::string fail;
  while (!file.eof()) {
    int f = file.get();
    if (f >= 65 && f <= 90) {
      f += 32;
      fail += f;
    } else if (f >= 97 && f <= 122) {
      fail += f;
    } else {
      tree.add(fail);
      fail = "";
    }
  }
  file.close();
  return tree;
}
