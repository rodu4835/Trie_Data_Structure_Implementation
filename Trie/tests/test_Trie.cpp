// If you change anything in this file, your changes will be ignored 
// in your homework submission.
// Chekout TEST_F functions bellow to learn what is being tested.
#include <gtest/gtest.h>
#include "../code/Trie.h"

#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class test_Trie : public ::testing::Test {
protected:
	// This function runs only once before any TEST_F function
	static void SetUpTestCase(){
	}

	// This function runs after all TEST_F functions have been executed
	static void TearDownTestCase(){
	}

	// this function runs before every TEST_F function
	void SetUp() override {}

	// this function runs after every TEST_F function
	void TearDown() override {
	}
};

TEST_F(test_Trie, TestConstructor){
    Trie myTrie;
	ASSERT_FALSE(myTrie.GetRoot());
}

TEST_F(test_Trie, TestInitNode){
    Trie myTrie;
    shared_ptr<trie_node> nodeptr = myTrie.InitNode();  
	ASSERT_TRUE(nodeptr);
	ASSERT_FALSE(nodeptr->endOfName);
	for (int i = 0; i < 26; i++){
        ASSERT_FALSE(nodeptr->next[i]);
    }
}

TEST_F(test_Trie, Testinsert_search){
    Trie myTrie;
    shared_ptr<trie_node> root = myTrie.InitNode();

    myTrie.insert(root, "ron");
    ASSERT_TRUE(myTrie.search(root, "ron"));

    myTrie.insert(root, "rondo");
    ASSERT_TRUE(myTrie.search(root, "rondo"));

    myTrie.insert(root, "rondili");
    ASSERT_TRUE(myTrie.search(root, "rondili"));

    ASSERT_FALSE(myTrie.search(root, "ro"));
    ASSERT_FALSE(myTrie.search(root, "radge"));
}

TEST_F(test_Trie, Testremove){
    Trie myTrie;
    shared_ptr<trie_node> root = myTrie.InitNode();

    myTrie.insert(root, "ron");
    myTrie.insert(root, "rondo");
    myTrie.insert(root, "rondili");

    myTrie.remove(root, "rondo");

    ASSERT_TRUE(myTrie.search(root, "ron"));
    ASSERT_TRUE(myTrie.search(root, "rondili"));
    ASSERT_FALSE(myTrie.search(root, "rondo"));
}

TEST_F(test_Trie, Testprefix){
    Trie myTrie;

    ASSERT_EQ(4,myTrie.prefix("rondo", "rondili"));
}

TEST_F(test_Trie, TestisEndOfName){
    Trie myTrie;
    shared_ptr<trie_node> root = myTrie.InitNode();
    ASSERT_EQ(root->endOfName, myTrie.isendOfName(root));
}

TEST_F(test_Trie, Testprint){
    Trie myTrie;
    shared_ptr<trie_node> root = myTrie.InitNode();

    myTrie.insert(root, "ron");
    myTrie.insert(root, "rondo");
    myTrie.insert(root, "rondili");
    myTrie.insert(root, "rondirna");
    myTrie.insert(root, "rondax");

    cout << "Contents in the Trie should be as follows: " << endl;
    cout << "ron" << endl;
    cout << "rondax" << endl;
    cout << "rondili" << endl;
    cout << "rondirna" << endl;
    cout << "rondo" << endl;
    cout << "------------" << endl;

    myTrie.print(root);
    cout << endl;
    int pass;
    
    cout << "1 for all items in the list, 0 for not: ";
    cin >> pass;

    ASSERT_EQ(1,pass);

}