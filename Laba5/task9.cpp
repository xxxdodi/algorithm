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

// Функция для обхода дерева в порядке "in-order"
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

// Функция для поиска минимального узла в дереве
TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Функция для удаления узла из дерева
TreeNode* deleteNode(TreeNode* root, int val) {
    if (root == nullptr) {
        return nullptr;
    }

    if (val < root->val) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->val) {
        root->right = deleteNode(root->right, val);
    } else {
        // Узел с одним или без детей
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Узел с двумя детьми: находим минимальный узел в правом поддереве
        TreeNode* temp = findMin(root->right);

        // Копируем значение минимального узла в текущий узел
        root->val = temp->val;

        // Удаляем минимальный узел в правом поддереве
        root->right = deleteNode(root->right, temp->val);
    }

    return root;
}

int main() {
    // Создание простого двоичного дерева поиска
    TreeNode* root = nullptr;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 4);

    // Обход дерева в порядке "in-order"
    cout << "Обход дерева в порядке in-order: ";
    inorderTraversal(root);
    cout << endl;

    // Удаление узла с ключом 3
    int key = 3;
    root = deleteNode(root, key);
    cout << "Дерево после удаления узла с ключом " << key << ": ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
