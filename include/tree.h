// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include<vector>
#include<algorithm>

class Tree {
 private:
    struct Node {
         char ch;
         std::vector<Node*>children;
     };
    Node* root = nullptr;
    std::vector<std::vector<char>>permutations;
    void createTree(Node* root, const std::vector<char>& arg) {
         for (auto& symb : arg) {
             Node* temp = new Node;
             temp->ch = symb;
             root->children.push_back(temp);
             std::vector<char>child = arg;
             child.erase(std::find(child.begin(), child.end(), symb));
             createTree(temp, child);
         }
     }
    void createPermutations(Node* root, std::vector<char> arg) {
         if (root->ch != ' ') {
             arg.push_back(root->ch);
         } else if (root->children.empty()) {
             permutations.push_back(arg);
         } else {
             for (Node* child : root->children)
                 createPermutations(child, arg);
         }
     }
 public:
    std::vector<std::vector<char>> getAllPermutations() const {
         return permutations;
     }
    Tree(std::vector<char>& arg) {
         root = new Node;
         createTree(root, arg);
         createPermutations(root, {});
     }
};

#endif  // INCLUDE_TREE_H_
