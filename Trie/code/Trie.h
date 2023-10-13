#ifndef TRIE_H__
#define TRIE_H__

#include <string>
#include <memory>
#include <vector>

using namespace std;

struct trie_node {
    shared_ptr<trie_node> next[26];
    bool endOfName;
};


class Trie {
public:

    Trie();

    ~Trie();

    shared_ptr<trie_node> GetRoot();
    
    shared_ptr<trie_node> InitNode();

    void insert(shared_ptr<trie_node> root, string name);

    bool search(shared_ptr<trie_node> root, string name);

    bool isEmpty(shared_ptr<trie_node> root);

    shared_ptr<trie_node> remove(shared_ptr<trie_node> root, string name);

    shared_ptr<trie_node> removeRecursive(shared_ptr<trie_node> root, string name, int depth);

    int prefix(string namea, string nameb);

    bool isendOfName(shared_ptr<trie_node> root);

    void print(shared_ptr<trie_node> root);

    void printRecursive(shared_ptr<trie_node> root, char str[], int level);

private:

    shared_ptr<trie_node> root;
  
};

#endif  // TRIE_H__
