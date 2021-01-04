//
// Created by Harshavardhan Bn on 1/3/21.
//

#include "SingleLinkedList.hpp"
#include<iostream>

ListNode::ListNode() : data(), next(nullptr){}

ListNode::ListNode(int t) : data(t), next(nullptr){
}

ListNode::ListNode(const ListNode &ln) : data(ln.data), next(ln.next){
}

ListNode& ListNode::operator=(const ListNode &ln) {
    if(this == &ln) return *this;
    this->data = ln.data;
    this->next = ln.next;
    return *this;
}

ListNode::~ListNode() {
    this->data = 0;
    this->next= nullptr;
}

SingleLinkedList::SingleLinkedList() : head(nullptr), tail(nullptr), size_m(0){
}

SingleLinkedList::SingleLinkedList(int t) {
    head = new ListNode(t);
    tail = head;
    size_m = 1;
}

SingleLinkedList::SingleLinkedList(const SingleLinkedList &sll) : head(nullptr), tail(nullptr),size_m(0){
    ListNode* temp = sll.head;
    ListNode* newNode;
    while (temp != nullptr){
        newNode = new ListNode(*temp);
        if(head == nullptr){
            head = newNode;
            tail = head;
        } else{
            tail->next = newNode;
            tail = newNode;
        }
        size_m++;
    }
}

SingleLinkedList& SingleLinkedList::operator=(const SingleLinkedList &sll) {
    if(this == &sll ) return *this;
    ListNode* temp;
    //Delete Existing Data
    while (head != nullptr){
        temp = head;
        this->head = this->head->next;
        delete temp;
    }
    this->tail = nullptr;
    this->size_m = 0;

    //Deep copy new Data
    temp = sll.head;
    ListNode* newNode;
    while (temp != nullptr){
        newNode = new ListNode(*temp);
        if(head == nullptr){
            head = newNode;
            tail = head;
        } else{
            tail->next = newNode;
            tail = newNode;
        }
        size_m++;
    }

    return *this;
}

SingleLinkedList::~SingleLinkedList() {
    ListNode* temp;
    //Delete Existing Data
    while (head != nullptr){
        temp = head;
        this->head = temp->next;
        delete temp;
    }
}

size_t SingleLinkedList::size() {
    return this->size_m;
}

int SingleLinkedList::front() {
    return this->head->data;
}

int SingleLinkedList::last() {
    return this->tail->data;
}

bool SingleLinkedList::empty() {
    bool ret = false;
    if(head == nullptr || tail == nullptr)
        ret = true;
    return ret;
}

void SingleLinkedList::push_front(int t) {
    ListNode* temp = new ListNode(t);
    temp->next = this->head;
    this->head = temp;
    if(temp->next == nullptr)
        this->tail = this->head;
    this->size_m++;
}

void SingleLinkedList::push_back(int t) {
    ListNode* temp = new ListNode(t);
    if(head == nullptr){
        this->head = temp;
        this->tail = this->head;
    } else {
        this->tail->next = temp;
        tail = tail->next;
    }
    this->size_m++;
}

void SingleLinkedList::printData() {
    ListNode* temp = this->head;
    while (temp != nullptr){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;
}

int SingleLinkedList::pop_back() {
    ListNode* temp = this->head;
    if(temp == nullptr || this->tail == nullptr){
        //TODO : Replace with Exception
        return -1;
    }
    if(this->head == this->tail){
        int ret = this->head->data;
        delete(this->head);
        this->head = this->tail = nullptr;
        this->size_m--;
        return ret;
    }

    while(temp->next != nullptr && temp->next!=this->tail) {
        temp = temp->next;
    }

    this->tail = temp;
    int ret = temp->next->data;
    delete(temp->next);
    temp->next = nullptr;
    this->size_m--;

    return ret;
}

int SingleLinkedList::pop_front() {
    ListNode* temp = this->head;
    if(temp == nullptr){
        //TODO : Replace with Exception
        return -1;
    }
    this->head = temp->next;
    if(this->tail == temp)
        this->tail = nullptr;
    int ret = temp->data;
    delete(temp);
    temp = nullptr;
    this->size_m--;
    return ret;
}

void SingleLinkedList::insert(int pos, int t) {
    if(pos > size_m || pos < 0){
        ERROR_STM("Position is out of SLL size");
        return;
    }

    if(size_m == 0){
        ERROR_STM("SLL is empty");
        return;
    }

    ListNode* node = new ListNode(t);


    ListNode* posNode = this->head;
    ListNode* prevNode = posNode;
    for (int i = 0; i < pos; ++i) {
        prevNode = posNode;
        posNode = posNode->next;
    }
    node->next = posNode;
    if(pos==0){
//    If the insertion is at the head, i.e., pos=0
        this->head = node;
    }else if(pos == size_m){
//    If the insertion is at the end, i.e., pos=size
        this->tail = prevNode->next = node;
    }else{
        prevNode->next = node;
    }

    this->size_m++;
}

void SingleLinkedList::replace(int pos, int t) {
    if(pos > size_m || pos < 0){
        ERROR_STM("Position is out of SLL size");
        return;
    }
    if(size_m == 0){
        ERROR_STM("SLL is empty");
        return;
    }


    if(pos==0){
        this->head->data = t;
    }else if(pos == size_m){
        this->tail->data = t;
    }else{
        ListNode* posNode = this->head;
        for (int i = 0; i < pos; ++i) {
            posNode = posNode->next;
        }
        posNode->data = t;
    }
}

int SingleLinkedList::at(int pos) {
    if(pos > size_m || pos < 0){
        ERROR_STM("Position is out of SLL size");
        //TODO : Replace this with Exception
        return -1;
    }

    if(size_m == 0){
        ERROR_STM("SLL is empty");
        return -1;
    }

    if(pos==0){
        return this->head->data;
    }else if(pos == size_m){
        return this->tail->data;
    }else{
        ListNode* posNode = this->head;
        for (int i = 0; i < pos; ++i) {
            posNode = posNode->next;
        }
        return posNode->data;
    }
}
