#ifndef B_PLUS_TREE_BPLUS_TREE_HPP
#define B_PLUS_TREE_BPLUS_TREE_HPP

#include <memory>
#include <vector>
#include <conio.h>
//Class of B+ tree node
template<typename DataType>
class BPlusNode {
    typedef std::shared_ptr<BPlusNode> Node;
public:
    bool leaf;
    unsigned size;
    std::vector<DataType> data;
    std::vector<Node> children;
    Node next_leaf;
    Node prev_leaf;
    Node parent;

    //Constructor
    BPlusNode();
};

//Class of B+ tree
template<typename DataType>
class BPlusTree {
    typedef std::shared_ptr<BPlusNode<DataType>> Node;
private:
    unsigned _minimum_degree;
    unsigned _min_node_fill;
    unsigned _max_node_fill;
    Node _root;

    //Search value in subtree
    std::pair<Node, unsigned>
        SubtreeSearch(Node subtree_root, const DataType& key);

    //Division tree into parts
    void SplitNode(Node node);

    //Insertion value into subtree
    std::pair<Node, unsigned>
        SubtreeInsert(Node subtree_root, const DataType& key);

    //Removing from subtree
    void SubtreeRemove(Node node, unsigned index);

    //Function for interactive finding elements
    Node ChooseNode(Node current_node);

public:
    //Constructor
    explicit BPlusTree(unsigned minimum_degree = 2);

    //Output in console
    void Print();

    //Check that element is at tree
    bool At(const DataType& key);

    //Insertion new element into tree
    void Insert(const DataType& key); 

    //Removing element from tree
    void Remove(const DataType& key);

};


#include "b_plus_tree_structure.hxx"

#endif //B_PLUS_TREE_BPLUS_TREE_HPP
#pragma once
