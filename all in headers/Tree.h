#ifndef CPPLABS_SPRING_MYTREE_H
#define CPPLABS_SPRING_MYTREE_H

#include "iostream"
#include "stack"
#include "algorithm"
#include "Container.h"
#include "Iterator.h"
using namespace std;

template <typename T,class Compare = less<T> >
class Tree
{
    typedef MyIterator<T> iterator;
    typedef MyIterator<const T> const_iterator;

private:
    Container<T> *root;
    int treeSize = 0;

protected:
    Container<T>* next(Container<T> *node){
        Container<T> *current = node->right;

        while (current->left != nullptr) current = current->left;
        return current;
    }

    int getHeight(const Container<T>* const node) const {
        return node == nullptr ? 0 : node->height;
    }
    int getBalanceValue(const Container<T> *const node) const {
        return node == nullptr ? 0 : getHeight(node->left) - getHeight(node->right);
    }

    void smallLeftRotation(Container<T> *&node) {
        Container<T>* result = node->right;
        Container<T>* tmp = result->left;

        result->left = node;
        node->right = tmp;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        result->height = max(getHeight(result->left), getHeight(result->right)) + 1;

        node = result;
    }
    void smallRightRotation(Container<T> *&node) {
        Container<T>* result = node->left;
        Container<T>* tmp = result->right;

        result->right = node;
        node->left = tmp;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        result->height = max(getHeight(result->left), getHeight(result->right)) + 1;

        node = result;
    }

    void insert_(Container<T> *&node, const T key, Container<T> **res) {
        if (node == nullptr){
            node = new Container<T>;
            node->value = key;
            node->left = nullptr;
            node->right = nullptr;
            node->height = 1;
            *res = node;
        }

        if (key < node->value) insert_(node->left, key, res);
        else if (key > node->value)
            insert_(node->right, key, res);


        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalanceValue(node);

        if (balance > 1 && key < node->left->value){
            smallRightRotation(node);
            return;
        }

        if (balance < -1 && key >  node->right->value){
            smallLeftRotation(node);
            return;
        }

        if (balance > 1 && key > node->left->value){
            smallLeftRotation(node->left);
            return smallRightRotation(node);
        }

        if (balance < -1 && key < node->right->value){
            smallRightRotation(node->right);
            return smallLeftRotation(node);
        }
    }
    void delete_(Container<T> *&node, T key, Container<T> **res) {
        if (node == nullptr){
            return;
        }

        if (key < node->value) delete_(node->left, key, res);
        else if (key > node->value)
            delete_(node->right, key, res);
        else {
            if ((node->left == nullptr) || (node->right == nullptr)){
                Container<T> *temp = node->left ? node->left : node->right;

                if (temp == nullptr){
                    temp = node;
                    node = nullptr;
                }
                else *node = *temp;

                *res = temp;
            }
            else{
                Container<T>* temp = next(node);
                node->value = temp->value;
                delete_(node->right, temp->value, res);
            }
        }

        if (node == nullptr)
            return;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalanceValue(node);

        if (balance > 1 && getBalanceValue(node->left) >= 0){
            smallRightRotation(node);
            return;
        }

        if (balance > 1 && getBalanceValue(node->left) < 0){
            smallLeftRotation(node->left);
            smallRightRotation(node);
            return;
        }

        if (balance < -1 && getBalanceValue(node->right) <= 0){
            smallLeftRotation(node);
            return;
        }

        if (balance < -1 && getBalanceValue(node->right) > 0){
            smallRightRotation(node->right);
            smallLeftRotation(node);
            return;
        }
    }
    Container<T>* exist(Container<T> *&node, const int key) {
        if (node == nullptr)
            return nullptr;

        if (node->value == key)
            return node;

        if (node->value > key) return exist(node->left, key);
        else return exist(node->right, key);
    }

public:
    Tree()
    :root(nullptr){};
    Tree(const Tree &tree){
        root = nullptr;
        root->left = tree.root->left;
        root->right = tree.root->right;
    }
    Tree& operator=(const Tree& tree) {
        treeSize = tree.treeSize;
        root = new Container<T>;
        root->value = tree.root->value;
        root->left = tree.root->left;
        root->right = tree.root->right;
        root->height = tree.root->height;

        return *this;
    }

    iterator begin(){return iterator(root);}
    const_iterator cbegin(){return const_iterator(root);}
    iterator end(){
        MyIterator<T> n = iterator(root);
        int s = treeSize;

        while (s != 1)
        {
            n++;
            s--;
        }

        return n;
    }
    const_iterator cend() {
        MyIterator<T> it = const_iterator(root);
        int s = treeSize;

        while (s != 1)
        {
            it++;
            s--;
        }

        return it;
    }

    iterator insert(const T &val){
        treeSize++;
        Container<T> *res = root;

        insert_(root, val, &res);

        return iterator(res);
    }
    iterator remove(const T &val){
        treeSize--;
        Container<T> *res = root;

        delete_(root, val, &res);

        return iterator(res);
    }
    iterator find(const T &val){
        if (exist(root, val) != nullptr)
        {
            return iterator(exist(root, val)); //Ïðîâåðêà íà ñóùåñòâîâàíèå
        }
        else
        {
            cout << "Error!";
        }
    }
    const_iterator cfind(const T &val){
        if (exist(root, val) != nullptr)
        {
            return iterator(exist(root, val)); //Ïðîâåðêà íà ñóùåñòâîâàíèå
        }
        else
        {
            cout << "Error!";
        }
    }

    size_t size() const{return treeSize;};
    bool empty() const{return root == nullptr;};
};


#endif //CPPLABS_SPRING_MYTREE_H
