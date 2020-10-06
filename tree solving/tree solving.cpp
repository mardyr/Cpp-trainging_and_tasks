// tree solving.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>


struct Node {
    int data;
    Node* left, * right;
    Node(int data) : data{ data }, left{ nullptr }, right{ nullptr }{}
};

void preOrder(Node* root)
{
    if (!root) 
    {
        return;
    }

    preOrder(root->left);
    std::cout << root->data << " ";
    preOrder(root->right);

}


int main()
{
    std::cout << "Hello World!\n";
}

