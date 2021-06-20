#include <iostream>
#include <vector>
#include <string>
#include "b_plus_tree_structure.hpp"
#include "classes.h"

using namespace std;

//Testing function
void Example() {


    vector<Group> mans;
    int n = 10;

    cout << "Start tree" << endl;
    system("pause");
    BPlusTree<Group> tree(3);
    for (int i = 0; i < n; i++) {
        Group man(to_string(i));
        tree.Insert(man);
    }
    tree.Print();
    system("pause");
    Group man(to_string(8));
    system("cls");
    cout << "After deletion group: " << man <<endl;
    system("pause");
    tree.Remove(man);
    tree.Print();
}
int main()
{
    Example();
    return 0;
}


