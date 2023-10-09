#include "AVLTree.h"
#include <iostream>

template <typename T>
void AVLTree<T>::insert(T data)
{
    // Insert into the tree
    // On a duplicate value, we will skip insertion
    m_root = insertAVL(m_root, data);
    if (m_root)
    {
        m_length++;
    }
}

#define nheight(node) (node ? node->height() : -1)

// Recursively insert into the tree folloiwng the rules of a BST (left small right big)
template <typename T>
AVLNode<T> *insertAVL(AVLNode<T> *node, T data)
{
    // If the node is null, we have found the insertion point
    if (!node)
    {
        return new AVLNode<T>(data);
    }

    if (node->data() == data)
    {
        return node;
    }

    // Recursively insert into the tree
    if (data < node->data())
    {
        node->setLeft(insertAVL(node->left(), data));
    }
    else
    {
        node->setRight(insertAVL(node->right(), data));
    }

    // Update the height of the node
    node->setHeight(1 + std::max(nheight(node->left()), nheight(node->right())));

    // Rotate if necessary
    return determineRotation(node, data);
}

#define balanceFactor(node) (nheight(node->left()) - nheight(node->right()))

template <typename T>
bool AVLTree<T>::validate() const
{
    return abs(balanceFactor(m_root)) < 2;
}

template <typename T>
AVLNode<T> *determineRotation(AVLNode<T> *node, T data)
{
    auto balanceFactor = balanceFactor(node);

    // Range [-1, 1]
    if (abs(balanceFactor) < 2)
    {
        return node;
    }

    // Left Left Case
    if (balanceFactor > 1 && data < node->left()->data())
        return rightRotate(node);

    // Right Right Case
    if (balanceFactor < -1 && data > node->right()->data())
        return leftRotate(node);

    // Left Right Case
    if (balanceFactor > 1 && data > node->left()->data())
    {
        node->setLeft(leftRotate(node->left()));
        return rightRotate(node);
    }

    // Right Left Case
    if (balanceFactor < -1 && data < node->right()->data())
    {
        node->setRight(rightRotate(node->right()));
        return leftRotate(node);
    }

    return node;
}

template <typename T>
AVLNode<T> *leftRotate(AVLNode<T> *node)
{
    auto right = node->right();
    auto rightLeft = right->left();

    // Perform rotation
    right->setLeft(node);
    node->setRight(rightLeft);

    // Update heights
    node->setHeight(1 + std::max(nheight(node->left()), nheight(node->right())));
    right->setHeight(1 + std::max(nheight(right->left()), nheight(right->right())));
    return right;
}

template <typename T>
AVLNode<T> *rightRotate(AVLNode<T> *node)
{
    auto left = node->left();
    auto leftRight = left->right();

    // Perform rotation
    left->setRight(node);
    node->setLeft(leftRight);

    // Update heights
    node->setHeight(1 + std::max(nheight(node->left()), nheight(node->right())));
    left->setHeight(1 + std::max(nheight(left->left()), nheight(left->right())));
    return left;
}

template <typename T>
void AVLTree<T>::enumerate() const
{
    // pre order traversal
    enumeratePreOrder(m_root);
}

template <typename T>
void enumeratePreOrder(AVLNode<T> *node)
{
    if (!node)
    {
        return;
    }

    std::cout << "VALUE: " << node->data() << " "
              << "HEIGHT: " << node->height() << std::endl;

    enumeratePreOrder(node->left());
    enumeratePreOrder(node->right());
}

template class AVLNode<int>;
template class AVLTree<int>;