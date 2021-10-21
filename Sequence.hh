
#pragma once
#include "Sequence.h"
#include <iostream>
using namespace std;

template <class T>
Sequence<T>::Sequence()
{
    head = NULL;
    size = 0;
}// Sequence

template <class T>
Sequence<T>::~Sequence()
{
    reclaimAllNodes(head);
}    // ~Sequence


template <class T>
void Sequence<T>::clear(void)
{
    reclaimAllNodes(head);
    head = NULL;
    size = 0;
} // clear

template <class T>
void Sequence<T>::reclaimAllNodes(NodeRecord*& initialP)
// requires: Null(initialP)  or  Alive(initialP)
//  ensures: all nodes in linked list
//           beginning with initialP are reclaimed
{
    if (initialP != NULL) {
        reclaimAllNodes(initialP->next);
        delete (initialP);
    } // end if
} // reclaimAllNodes

// You are required to implement add, remove, entry, length, and outputSequence functions here.
template <class T>
void Sequence<T> ::add(T& x, int pos) {
    if (pos > size)
        cout << "\nInvalid position entered \n";
    else {
        if (pos == 0) {
            NodeRecord* temp = new NodeRecord;
            temp->next = head;
            head = temp;
            head->value = x;
            size++;
        }//If Statement
        else {
            NodeRecord* current = head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }//For Statement
            NodeRecord* var = new NodeRecord;
            var->next = current->next;
            current->next = var;
            size++;
            var->value = x;
        }// else
    }// else
}// add


template <class T>
void Sequence<T>::remove(T& x, int pos) {
    if (pos >= size) {
        cout << "Enter valid position, position " << pos << " is invalid";
    }// if
    else {
        if (pos == 0) {
            NodeRecord* temp = head;
            head = head->next;
        }// if
        else {
            NodeRecord* current = head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }// for 
            NodeRecord* temp = current->next;
            current->next = temp->next;
            x = temp->value;
            delete temp;
            size--;
        }// else
    }//else
}// remove

template <class T>
T& Sequence<T>::entry(int pos) {
    if (pos < 0 || pos >= size) {
        cout << "Please enter valid position " << pos << " is invalid in this sequence ";
        return head->value;
    }// if
    else {
        NodeRecord* current = head;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }// for
        return current->value;
    }// else
}// entry

template <class T>
int Sequence<T>::length(void) {
    return size;
}// length 

template <class T>
void Sequence <T> ::outputSequence(void) {
    if (size == 0) {
        cout << "Sequence is Empty\n";
    }//if 
    else {
        NodeRecord* current = head;
        cout << "[";
        while (current != NULL) {
            if(current->next == NULL){
                cout << current->value;
                current = current->next;
            }
            else{
            cout << current->value;
            cout << ", ";
            current = current->next;
            }// else
        }// while
    cout << "]";
    }// else
}// outputSequence
