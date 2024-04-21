#include <iostream>

using namespace std;

// Узел двоичного дерева поиска
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Функция для создания нового узла
TreeNode* createNode(int val) {
    return new TreeNode(val);
}

// Функция для вставки нового элемента в дерево
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return createNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Функция для поиска элемента в дереве
bool search(TreeNode* root, int val) {
    if (root == nullptr) {
        return false;
    }

    if (root->val == val) {
        return true;
    } else if (val < root->val) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

int main() {
    // Создание простого двоичного дерева поиска
    TreeNode* root = nullptr;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 4);

    // Поиск элемента в дереве
    int key = 4;
    if (search(root, key)) {
        cout << "Элемент " << key << " найден в дереве." << endl;
    } else {
        cout << "Элемент " << key << " не найден в дереве." << endl;
    }

    return 0;
}
