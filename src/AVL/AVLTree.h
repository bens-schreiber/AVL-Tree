#pragma once
#include "AVLNode.h"
template <typename T>
class AVLTree
{
    AVLNode<T> *m_root{nullptr};
    unsigned int m_length{0};

public:
    inline int height() const
    {
        return m_root ? m_root->height() : -1;
    }

    inline unsigned int length() const
    {
        return m_length;
    }

    void insert(T data);

    void contains(T data);

    bool validate() const;

    void enumerate() const;
};