//Ana Coronel 
//A00838713
//Tarea #5


#ifndef BST_H
#define BST_H

#include <iostream>
#include <sstream>
#include <string>

template <class T>

class Node {
public:
    T val;
    Node<T>* left;
    Node<T>* right;

    Node(T value) : val(value), left(0), right(0) {}
};

template <class T>
class BST {
private:
    Node<T>* root;

    Node<T>* addNode(Node<T>* node, T value) {
        if (node == 0) {
            return new Node<T>(value);
        }
        
        if (value < node->val) {

            node->left = addNode(node->left, value);
        } else {

            node->right = addNode(node->right, value);
        }
        
        return node; 
    }

    std::string preorder(Node<T>* node, std::string& aux) {
        if (!node) return aux;
        aux += std::to_string(node->val) + " ";
        preorder(node->left, aux);
        preorder(node->right, aux);
        return aux;
    }

    std::string inorder(Node<T>* node, std::string& aux) {
        if (!node) return aux;
        inorder(node->left, aux);
        aux += std::to_string(node->val) + " ";
        inorder(node->right, aux);
        return aux;
    }

    std::string postorder(Node<T>* node, std::string& aux) {
        if (!node) return aux;
        postorder(node->left, aux);
        postorder(node->right, aux);
        aux += std::to_string(node->val) + " ";
        return aux;
    }

    std::string levelOrder(Node<T>* node, std::string& aux) {
        if (!node) return aux;
        int height = getHeight(node);
        for (int i = 1; i <= height; i++) levelOrderAux(node, i, aux);
        return aux;
    }

    void levelOrderAux(Node<T>* node, int level, std::string& aux) {
        if (!node) return;
        if (level == 1) aux += std::to_string(node->val) + " ";
        else {
            levelOrderAux(node->left, level - 1, aux);
            levelOrderAux(node->right, level - 1, aux);
        }
    }
//Height
    T high(T a, T b) {
        return (a > b) ? a : b;
    }

    int getHeight(Node<T>* node) {
        if (!node) return 0;
        return high(getHeight(node->left), getHeight(node->right)) + 1;
    }

    bool getAncestors(Node<T>* node, T value, std::string& aux) {
        if (!node) return false;
        if (node->val == value) return true;
        if (getAncestors(node->left, value, aux) || getAncestors(node->right, value, aux)) {
            aux = std::to_string(node->val) + " " + aux;
            return true;
        }
        return false;
    }

    int getLevel(Node<T>* node, T value, int level) {
        if (!node) return -1;
        if (node->val == value) return level;
        int leftLevel = getLevel(node->left, value, level + 1);
        return leftLevel != -1 ? leftLevel : getLevel(node->right, value, level + 1);
    }

public:
    BST() : root(nullptr) {}

    void add(T value) {
        root = addNode(root, value);
    }

    int height() {
        return getHeight(root);
    }

    std::string visit() {
        std::string aux = "";
        std::string preorderAux = "";
        std::string inorderAux = "";
        std::string postorderAux = "";
        std::string levelOrderAux = "";


        preorder(root, preorderAux);
        inorder(root, inorderAux);
        postorder(root, postorderAux);
        levelOrder(root, levelOrderAux);

        aux += "[" + (preorderAux.empty() ? "" : preorderAux.substr(0, preorderAux.size() - 1)) + "]\n";
        aux += "[" + (inorderAux.empty() ? "" : inorderAux.substr(0, inorderAux.size() - 1)) + "]\n";
        aux += "[" + (postorderAux.empty() ? "" : postorderAux.substr(0, postorderAux.size() - 1)) + "]\n";
        aux += "[" + (levelOrderAux.empty() ? "" : levelOrderAux.substr(0, levelOrderAux.size() - 1)) + "]";
        return aux;
    }

    std::string ancestors(T value) {

        std::string aux = "";
        if (!getAncestors(root, value, aux)) return "[]";
        return "[" + (aux.empty() ? "" : aux.substr(0, aux.size() - 1)) + "]";
    }

    int whatlevelamI(T value) {

        Node<T>* aux = root;
        int level = 1;

        while (value != aux->val) {
            if (value < aux->val) {
                level++;
                aux = aux->left;
            } else if (value > aux->val) {
                level++;
                aux = aux->right;
            }
        }
        return level;
    }
};

#endif
