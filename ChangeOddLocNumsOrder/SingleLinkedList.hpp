//
// Created by Harshavardhan Bn on 1/3/21.
//

#ifndef CHANGEODDLOCNUMSORDER_SINGLELINKEDLIST_HPP
#define CHANGEODDLOCNUMSORDER_SINGLELINKEDLIST_HPP

#define DEBUG_STM(fmt) \
        std::cout<<__FILE__<<":"<<__FUNCTION__<<":"<<__LINE__<<": "<<fmt<<std::endl
#define ERROR_STM(fmt) \
        std::cerr<<__FILE__<<":"<<__FUNCTION__<<":"<<__LINE__<<": "<<fmt<<std::endl

#include <opencl-c-base.h>

class SingleLinkedList;

//template <typename T>
class ListNode{
private:
    int data;
    ListNode* next;

public:
    friend class SingleLinkedList;
    ListNode();
    ListNode(int);
    ListNode(const ListNode &);

    ListNode&operator=(const ListNode&);

    virtual ~ListNode();
};

//template <typename T>
class SingleLinkedList{
public:
    SingleLinkedList();
    SingleLinkedList(int);
    SingleLinkedList(const SingleLinkedList&);

    SingleLinkedList&operator=(const SingleLinkedList&);

    int front();
    int last();
    size_t size();

    bool empty();

    void insert(int, int);
    void replace(int,int);
    void push_front(int);
    void push_back(int);
    int pop_front();
    int pop_back();
    int at(int);

    void printData();

    virtual ~SingleLinkedList();
private:
    ListNode* head;
    ListNode* tail;
    size_t size_m;
};


#endif //CHANGEODDLOCNUMSORDER_SINGLELINKEDLIST_HPP
