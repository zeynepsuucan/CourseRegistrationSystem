#ifndef HW3_NODEDOUBLE_H
#define HW3_NODEDOUBLE_H
#include <string>
#include <cstddef>

template<class ItemType>
class NodeDouble{
public:
    ItemType item; // a data item
    NodeDouble<ItemType>* next; // pointer to the next node
    NodeDouble<ItemType>* prev;
    NodeDouble(){
        this->next = NULL;
        this->prev = NULL;
    }
    NodeDouble(const ItemType& anItem){
        this->item = anItem;
        this->next = NULL;
        this->prev = NULL;
    }
    NodeDouble(const ItemType& anItem, NodeDouble<ItemType>* nextPtr){
        this->item= anItem;
        this->next = nextPtr;
    }
    NodeDouble(const ItemType& anItem, NodeDouble<ItemType>* nextPtr, NodeDouble<ItemType>* prevPtr){
        this->item= anItem;
        this->next = nextPtr;
        this->prev = prevPtr;
    }
    
    void setItem(const ItemType& anItem){
        this->item = anItem;
    }
    void setNext(NodeDouble<ItemType>* nextPtr){
        this->next = nextPtr;
    }
    void setPrev(NodeDouble<ItemType>* prevPtr){
        this->prev = prevPtr;
    }

    ItemType getItem() const{
        return item;
    }
    NodeDouble<ItemType>* getNext() const{
        return next;
    }
    NodeDouble<ItemType>* getPrev() const{
        return prev;
    }
};
#endif