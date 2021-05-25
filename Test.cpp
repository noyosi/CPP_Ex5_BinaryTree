#include "doctest.h"
#include "BinaryTree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;
using namespace ariel;


TEST_CASE("int tree"){
    BinaryTree<int> bt;
    CHECK_NOTHROW(bt.add_root(10)); 
    CHECK_NOTHROW(bt.add_root(4)); //change the root
    CHECK_NOTHROW(bt.add_left(4, 2));
    CHECK_NOTHROW(bt.add_left(2, 1));
    CHECK_NOTHROW(bt.add_right(2, 3));
    CHECK_NOTHROW(bt.add_right(4, 6));
    CHECK_NOTHROW(bt.add_left(6, 5));
    CHECK_NOTHROW(bt.add_right(6, 7));

    int pre[] = {4,2,1,3,6,5,7};
    int in[] = {1,2,3,4,5,6,7};
    int post[] = {1,3,2,5,7,6,4};

    int i=0;

    //inorder
    for(const int &element: bt){  
        CHECK_EQ((element), in[i++]); 
    }   
    
    for(auto it=bt.begin_inorder(); it!=bt.end_inorder(); ++it){
        i=0;
        CHECK_EQ((*it), in[i++]);
    }

    for(auto it=bt.begin_preorder(); it!=bt.end_preorder(); ++it){
        i=0;
        CHECK_EQ((*it), pre[i++]);
    }

    for(auto it=bt.begin_postorder(); it!=bt.end_postorder(); ++it){
        i=0;
        CHECK_EQ((*it), post[i++]);
    }
}

TEST_CASE("string tree"){
    BinaryTree<string> bt;
    CHECK_NOTHROW(bt.add_root("10"));
    CHECK_NOTHROW(bt.add_root("4")); //change the root
    CHECK_NOTHROW(bt.add_left("4", "2"));
    CHECK_NOTHROW(bt.add_left("2", "1"));
    CHECK_NOTHROW(bt.add_right("2", "3"));
    CHECK_NOTHROW(bt.add_right("4", "6"));
    CHECK_NOTHROW(bt.add_left("6", "5"));
    CHECK_NOTHROW(bt.add_right("6", "7"));
    //CHECK_THROWS(bt.add_left("8", "9")); //8 isn't exist
    //CHECK_THROWS(bt.add_right("8", "9")); //8 isn't exist

    string pre[] = {"4","2","1","3","6","5","7"};
    string in[] = {"1","2","3","4","5","6","7"};
    string post[] = {"1","3","2","5","7","6","4"};

    int i=0;

    //inorder
    for(const string &element: bt){  
        CHECK_EQ((element), in[i++]);
    }   
    
    for(auto it=bt.begin_inorder(); it!=bt.end_inorder(); ++it){
        i=0;
        CHECK_EQ((*it), in[i++]);
    }

    for(auto it=bt.begin_preorder(); it!=bt.end_preorder(); ++it){
        i=0;
        CHECK_EQ((*it), pre[i++]);
    }

    for(auto it=bt.begin_postorder(); it!=bt.end_postorder(); ++it){
        i=0;
        CHECK_EQ((*it), post[i++]);
    }
}

TEST_CASE("char tree"){
    BinaryTree<char> bt;
    CHECK_NOTHROW(bt.add_root('a'));
    CHECK_NOTHROW(bt.add_root('2'));
    CHECK_NOTHROW(bt.add_root('4')); //change the root
    CHECK_NOTHROW(bt.add_left('4', '2'));
    CHECK_NOTHROW(bt.add_left('2', '1'));
    CHECK_NOTHROW(bt.add_right('2', '3'));
    CHECK_NOTHROW(bt.add_right('4', '6'));
    CHECK_NOTHROW(bt.add_left('6', '5'));
    CHECK_NOTHROW(bt.add_right('6', '7'));
    //CHECK_THROWS(bt.add_left('8', '9')); //8 isn't exist
    //CHECK_THROWS(bt.add_right('8', '9')); //8 isn't exist

    char pre[] = {'4','2','1','3','6','5','7'};
    char in[] = {'1','2','3','4','5','6','7'};
    char post[] = {'1','3','2','5','7','6','4'};

    int i=0;

    //inorder
    for(const char &element: bt){  
        CHECK_EQ((element), in[i++]);
    }   
    
    for(auto it=bt.begin_inorder(); it!=bt.end_inorder(); ++it){
        i=0;
        CHECK_EQ((*it), in[i++]);
    }

    for(auto it=bt.begin_preorder(); it!=bt.end_preorder(); ++it){
        i=0;
        CHECK_EQ((*it), pre[i++]);
    }

    for(auto it=bt.begin_postorder(); it!=bt.end_postorder(); ++it){
        i=0;
        CHECK_EQ((*it), post[i++]);
    }
}

TEST_CASE("special tree"){
    BinaryTree<int> bt;
    CHECK_THROWS(bt.add_left(8, 9)); //no root

    CHECK_NOTHROW(bt.add_root(4)); 
    CHECK_NOTHROW(bt.add_left(4, 2));
    CHECK_NOTHROW(bt.add_right(4, 3));
    CHECK_THROWS(bt.add_left(8, 9)); //8 isn't exist
    CHECK_THROWS(bt.add_right(8, 9)); //8 isn't exist
    CHECK_NOTHROW(cout << bt << endl;);
}