#include "Tree.h"
#include "iostream"

using namespace std;

int main(){
     Tree<int> tree;

     cout << "in: " << *tree.insert(9) << endl;
     cout << "in: " << *tree.insert(15) << endl;
     cout << "in: " << *tree.insert(8) << endl;
     cout << "in: " << *tree.insert(7) << endl;
     cout << "in: " << *tree.insert(11) << endl;
     cout << "in: " << *tree.insert(10) << endl;
     cout << "in: " << *tree.insert(12) << endl;

     cout << "begin: " << *tree.begin() << endl;
     cout << "end: " << *tree.end() << endl;

     cout << "contain 9: ";
     tree.find(9) != nullptr ? cout << "yes" : cout << "no";
     cout << endl;
     cout << "size: " << tree.size() << endl;

     cout << "iterstor after removing 9: " << *tree.remove(9) << endl;
     cout << "size: " << tree.size() << endl;
}

