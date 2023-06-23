#ifndef HW3_LINKEDLISTDOUBLE_H
#define HW3_LINKEDLISTDOUBLE_H
#include <iostream>
#include "NodeDouble.h"
template <class ItemType>
class LinkedListDouble{
public:
    NodeDouble<ItemType>* headPtr;
    int itemCount;
    NodeDouble<ItemType>* getNodeAt(int pos) const{
       NodeDouble<ItemType>* curPtr = headPtr;
       for(int i = 0; i < pos; i++){
           curPtr = curPtr->getNext();
       }
       return curPtr;
   }
    LinkedListDouble(){
        headPtr = NULL;
        itemCount = 0;
    }
    LinkedListDouble(const LinkedListDouble<ItemType>& aList){
        itemCount = aList.itemCount;
        NodeDouble<ItemType>* origPtr = aList.headPtr;
        if(origPtr == NULL)
            headPtr = NULL;
        else{
            headPtr = new NodeDouble<ItemType>();
            headPtr->setItem(origPtr->getItem());
            NodeDouble<ItemType>* newChainPtr = headPtr;
            origPtr = origPtr -> getNext();
            while(origPtr != NULL){
                ItemType nextItem = origPtr->getItem();
                NodeDouble<ItemType>* newNodePtr = new NodeDouble<ItemType>(nextItem);
                newChainPtr->setNext(newNodePtr);
                newChainPtr = newChainPtr->getNext();
                origPtr = origPtr->getNext();
            }
            newChainPtr->setNext(NULL);
        }
    }

    ~LinkedListDouble(){
       this->itemCount = 0;
       this->clear();
   }
    bool isEmpty() const{
        return itemCount == 0;
    }

    void insert(const ItemType& newNode){
        NodeDouble<ItemType>* newNodePtr = new NodeDouble<ItemType>(newNode);
        if(itemCount==0){
            headPtr = newNodePtr;
            itemCount++;
            return;
        }
        else {
            if(newNodePtr->item < this->getNodeAt(0)->item){
                newNodePtr->setPrev(nullptr);
                newNodePtr->setNext(this->headPtr);
                itemCount++;
                this->headPtr = newNodePtr;
                return;
            }
            for (int i = 0; i < itemCount; ++i) {
                if(newNodePtr->item <  this->getNodeAt(i)->item ){
                    itemCount++;
                    NodeDouble<ItemType>* temp = this->getNodeAt(i);
                    NodeDouble<ItemType>* temp2 = this->getNodeAt(i-1);
                    this->getNodeAt(i)->setPrev(newNodePtr);
                    this->getNodeAt(i-1)->setNext(newNodePtr);
                    newNodePtr->setNext(temp);
                    newNodePtr->setPrev(temp2);
                    return;
                }
            }
            this->getNodeAt(itemCount-1)->setNext(newNodePtr);
            this->getNodeAt(itemCount)->setPrev(newNodePtr);
            itemCount++;
            return ;
        }

    }

    int findPos(ItemType item){
        int pos = 0;
        for(int i = 0; i < itemCount; i++){
            if(getNodeAt(i)->getItem()==item){
            return pos;
            }
            else  
            pos++;

        }
        return -1;
       
    }

    void remove(int pos){
        NodeDouble<ItemType>* curPtr = NULL;
        if(pos == 0 && itemCount>0){
            curPtr = headPtr;
            headPtr = headPtr->getNext();
            if (headPtr != nullptr) {
            headPtr->setPrev(nullptr);
        }
        }
        else if(pos == 0 && itemCount == 0){
            curPtr = headPtr;
            headPtr = nullptr;
            itemCount = 0;
            return;
        }
        else if(pos < itemCount-1){
            NodeDouble<ItemType>* prevPtr = getNodeAt(pos-1);
            curPtr = prevPtr->getNext();
            prevPtr->setNext(curPtr->getNext());
            curPtr->getNext()->setPrev(prevPtr);
        }
        else{
            NodeDouble<ItemType>* prevPtr = getNodeAt(pos-1);
            curPtr = prevPtr->getNext();
            prevPtr->setNext(nullptr);
        }
        curPtr->setNext(NULL);
        curPtr->setPrev(NULL);
        delete curPtr;
        curPtr = NULL;
        itemCount--;
    }

    void clear(){
        while(!isEmpty()){
            remove(0);
        }
    }

    ItemType getEntry(int pos) const{
        NodeDouble<ItemType>* nodePtr = getNodeAt(pos);
        return nodePtr->getItem();
    }

};
#endif