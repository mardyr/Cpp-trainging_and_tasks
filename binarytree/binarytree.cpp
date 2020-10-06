// binarytree.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

struct BinaryTree
{
    int data;
    BinaryTree* left;
    BinaryTree* right;
    BinaryTree(int d) : data{ d }, left{ nullptr }, right{ nullptr }{}
};
int maxDepth(BinaryTree* node)
{
    if (node == nullptr) return 0;
    else
    {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        if (lDepth > rDepth) return (lDepth + 1);
        else return(rDepth + 1);
    }
}

int main()
{
    BinaryTree* root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->left = new BinaryTree(4);
    root->left->right = new BinaryTree(5);
    root->right->left = new BinaryTree(6);
    root->right->right = new BinaryTree(7);

    std::cout << maxDepth(root);
    return 0;
}

