#include "Trie.h"
#include <iostream>

Trie::Trie(){
    root = NULL;
}

Trie::~Trie(){
}

shared_ptr<trie_node> Trie::GetRoot(){
  return root;
}

shared_ptr<trie_node> Trie::InitNode(){
    shared_ptr<trie_node> ret(new trie_node);
    for(int i = 0; i < 26; i++){
        ret->next[i] = NULL;
    }
    ret->endOfName = false;
    return ret;
}

void Trie::insert(shared_ptr<trie_node> root, string name){
    shared_ptr<trie_node> node = root;
    int length = name.length();
    for(int i = 0; i < length; i++){
        int charIndex = name[i] - 'a';
        if(!node->next[charIndex]){
            node->next[charIndex] = InitNode();
        }
        node = node->next[charIndex];
    }
    node->endOfName = true;
}

bool Trie::search(shared_ptr<trie_node> root,string name){
    shared_ptr<trie_node> node = root;
    int length = name.length();
    for(int i = 0; i < length; i++){
        int charIndex = name[i] - 'a';
        if(node->next[charIndex] == NULL){
            return false;
        }
        node = node->next[charIndex];
    }
    return (node->endOfName && node != NULL);
}

bool Trie::isEmpty(shared_ptr<trie_node> root){
    for (int i = 0; i < 26; i++){
        if (root->next[i]){
            return false;
        }
    }
    return true;
}

shared_ptr<trie_node> Trie::remove(shared_ptr<trie_node> root, string name){
   return Trie::removeRecursive(root, name, 0);
}

shared_ptr<trie_node> Trie::removeRecursive(shared_ptr<trie_node> root, string name, int depth){
    if (root == NULL){
        return NULL;
    }
    int length = name.length();
    if (depth == length){
        if (root->endOfName == true){
            root->endOfName = false;
        }
        if (isEmpty(root) == true){
            root = NULL;
        }
        return root;
    }
    int index = name[depth] - 'a';
    root->next[index] = Trie::removeRecursive(root->next[index], name, depth + 1);
    if (isEmpty(root) == true && root->endOfName == false) {
        root = NULL;
    }
    return root;
}

int Trie::prefix(string namea, string nameb){
    int lengthOfnamea = namea.length();
    int lengthOfnameb = nameb.length();

    for(int i = 0; i < lengthOfnamea; i++){
        if( i == lengthOfnameb || namea[i] != nameb[i]){
            return i;
        }
    }
    return lengthOfnamea;
}

bool Trie::isendOfName(shared_ptr<trie_node> root){
    return root->endOfName != false;
}

void Trie::print(shared_ptr<trie_node> root){
    int maxcharsInName = 20;
    char name[maxcharsInName];
    return Trie::printRecursive(root, name, 0);
}

void Trie::printRecursive(shared_ptr<trie_node> root, char name[], int index)
{
    if (isendOfName(root) == true){
        name[index] = '\0';
        cout << name << endl;
    }
    for (int i = 0; i < 26; i++){
        if (root->next[i] != NULL){
            name[index] = i + 'a';
            Trie::printRecursive(root->next[i], name, index + 1);
        }
    }
}




