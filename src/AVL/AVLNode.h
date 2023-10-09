#pragma once
template <typename T>
class AVLNode {
    T m_data;
    int m_height{0};
    AVLNode<T> *m_left{nullptr};
    AVLNode<T> *m_right{nullptr};

public:
    AVLNode(T data) : m_data(data) {}
    AVLNode(T data, int height) : m_height(height), m_data(data) {}
    
    inline T data() const {
        return m_data;
    }

    inline int height() const {
        return m_height;
    }

    inline AVLNode<T> *left() const {
        return m_left;
    }

    inline AVLNode<T> *right() const {
        return m_right;
    }

    inline void setLeft(AVLNode<T> *left) {
        m_left = left;
    }

    inline void setRight(AVLNode<T> *right) {
        m_right = right;
    }

    inline void setHeight(int height) {
        m_height = height;
    }
};