#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;

namespace ariel {

    template<typename T>

    class BinaryTree{

        class Node{

            public:
            T val;
            Node *left, *right;

            Node(T value) : val(value), left(nullptr), right(nullptr){}

            ~Node(){
            delete left;
            delete right;
            }
        };


        private:
        Node *root;

        public:
        BinaryTree():root(nullptr){}

        ~BinaryTree(){
            delete root;
        }

        BinaryTree<T> &add_root(T data){
            return *this;
        }

        BinaryTree<T> &add_left(T parent, T left_son){
            return *this;
        }

        BinaryTree<T> &add_right(T parent, T right_son){
            return *this;
        }

        friend std::ostream &operator<<(std::ostream &out, const BinaryTree &bt){
            out<<"Binary Tree";
            return out;
        }


        class in_order{  

            private:
            Node *node;

            public:
            in_order(Node *ptr = nullptr) : node(ptr){}

            in_order &operator ++ (){
                return *this;
            }
           
            const in_order operator ++ (int){
                return *this;
            }

            T *operator ->() const{ 
                return &(node->val);
            }

            T &operator *() const{
                return node->val;
            }
    
            bool operator == (const in_order &other) const{
                return node == other.node;
            }			

            bool operator != (const in_order &other) const{
                return node != other.node;
            }
        };


        class pre_order{

            private:
            Node *node;

            public:
            pre_order(Node *ptr = nullptr):node(ptr){}

        
            T *operator ->() const{ 
                return &(node->val);
            }

            T &operator *() const{
                return node->val;
            }

            pre_order &operator ++ (){
                return *this;
            }

            const pre_order operator ++ (int){
                return *this;
            }

            bool operator == (const pre_order &other) const{
                return node == other.node;
            }			

            bool operator != (const pre_order &other) const{
                return node != other.node;
            }
        };

        
        class post_order{

            private:
            Node *node;

            public:
            post_order(Node *ptr = nullptr) : node(ptr) {}

            T *operator ->() const{ 
                return &(node->val);
            }

            T &operator *() const{
                return node->val;
            }

            post_order &operator ++ (){
                return *this;
            }

            const post_order operator ++ (int){
                return *this;
            }

            bool operator == (const post_order &other) const{
                return node == other.node;
            }			

            bool operator != (const post_order &other) const{
                return node != other.node;
            }
        };


        in_order begin_inorder(){
            return in_order(root);
        }

        in_order end_inorder(){
            return (nullptr);
        }

        in_order begin() {
            return in_order(root);
        }

        in_order end() {
            return (nullptr);
        }

        pre_order begin_preorder(){
            return pre_order(root);   
        }

        pre_order end_preorder(){
            return (nullptr);
        }

        post_order begin_postorder(){
            return post_order(root);
        }

        post_order end_postorder(){
            return (nullptr);
        }
    };
}