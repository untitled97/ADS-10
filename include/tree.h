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
	 std::vector<std::vector<char>>permutation;
	 void createTree(Node* root, const std::vector<char>& arg) {
		 for (const auto& symb : arg) {
			 Node* temp = new Node;
			 temp->ch = symb;
			 root->children.push_back(temp);
			 std::vector<char> new_vector(arg);
			 new_vector.erase(std::find(new_vector.begin(), new_vector.end(), symb));
			 createTree(temp, new_vector);
		 }
	 }
	 void makePerm(Node*, std::vector<char>);
	 void createTreePerm(const std::vector<char>&);
 public:
	 explicit Tree(const std::vector<char>&)
	 std::vector<std::vector<char>> getPerm() const;
};

#endif  // INCLUDE_TREE_H_
