// Binary tree.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

struct Binary
{
    int data;
    Binary *left, *right;
    Binary(int data) : data{ data }, left{ nullptr }, right{ nullptr }{}
};

char tree[10];
void root(char key)
{
    if (tree[1] != '\0') std::cout << "Tree already had a root\n";
    else tree[1] = key;
}

void setleft(char key, int parent)
{
    if (tree[parent] == '\0') std::cout << "Can not set child at " << (parent * 2) << " , no parent found\n";
    else tree[(parent * 2)] = key;

}

void setright(char key, int parent)
{
    if (tree[parent] == '\0') std::cout << "Can not set child at " << (parent * 2) + 1 << " , no parent found\n";
    else tree[(parent * 2) + 1] = key;

}
void printTree() {
    for (int i = 1; i < sizeof(tree); i++)
    {
        if (tree[i] != '\0') std::cout << tree[i] << " ";
        else std::cout << "-";
    }
}

int main()
{
    std::cout << sizeof(tree) << std::endl;
    root('A');
    setleft('B', 1);
    setright('C', 1);
    setleft('D', 2);
    setright('E', 2);
    setright('F', 3);
    printTree();


    /*
    Binary *root = new Binary(1);
    Binary *left = new Binary(2);
    Binary *right = new Binary(3);
    Binary *left_left = new Binary(4);
    Binary *left_right = new Binary(5);
    Binary *right_left = new Binary(6);
    Binary* right_right = new Binary(7);

    root ->left = left;
    root->right = right;
    left->left = left_left;
    left->right = left_right;
    right->left = right_left;
    right->right = right_right;
    */
}

