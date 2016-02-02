#ifndef _CEXOLINKEDLISTINTERNAL_H_
#define _CEXOLINKEDLISTINTERNAL_H_
#include "nwndef.h"
#include "nwnstructs.h"

class CExoLinkedListInternal
{
public:
    CExoLinkedListNode* AddAfter(void* e, CExoLinkedListNode *n) {
        if(n == LastElement) { return AddTail(e); }
        CExoLinkedListNode* node = new CExoLinkedListNode();
        node->Previous = n;
        node->Data = e;
        node->Next = n->Next;
        n->Next = node;
        ++Count;
        return node;
    }

    CExoLinkedListNode* AddBefore(void* e, CExoLinkedListNode*n) {
        if(n == FirstElement) { return AddHead(e); }
        CExoLinkedListNode* node = new CExoLinkedListNode();
        node->Previous = n->Previous;
        node->Data = e;
        node->Next = n;
        n->Previous = node;
        ++Count;
        return node;
    }

    CExoLinkedListNode* AddHead(void* e) {
        CExoLinkedListNode* node = new CExoLinkedListNode();
        node->Previous = nullptr;
        node->Data = e;
        node->Next = FirstElement;
        FirstElement = node;
        ++Count;
    }

    CExoLinkedListNode* AddTail(void* e) {
        CExoLinkedListNode* node = new CExoLinkedListNode();
        node->Previous = LastElement;
        node->Data = e;
        node->Next = nullptr;
        LastElement = node;
        ++Count;
    }

    void* GetAtPos( CExoLinkedListNode *node) { return node ? node->Data : nullptr; }
    void GetNext( CExoLinkedListNode *& node) { node = node->Next; }
    void GetPrev( CExoLinkedListNode *& node) { node = node->Previous; }
    void* RemoveHead() {
        CExoLinkedListNode *node = FirstElement;
        if(node) {
            FirstElement = node->Next;
            if(FirstElement) {
                FirstElement->Previous = nullptr;
            }
            else {
                LastElement = nullptr;
            }
            --Count;
            void* temp = node->Data;
            delete node;
            return temp;
        }
        return nullptr;
    }

    void* RemoveTail() {
        CExoLinkedListNode *node = LastElement;
        if(node) {
            LastElement = node->Previous;
            if(LastElement) {
                LastElement->Next = nullptr;
            }
            else {
                FirstElement = nullptr;
            }
            --Count;
            void* temp = node->Data;
            delete node;
            return temp;
        }
        return nullptr;
    }

    void* Remove( CExoLinkedListNode *n) {
        if(n == FirstElement) { return RemoveHead(); }
        if(n == LastElement) { return RemoveTail(); }
        CExoLinkedListNode *prev = n->Previous;
        CExoLinkedListNode *next = n->Next;
        prev->Next = next;
        next->Previous = prev;
        --Count;

        void* temp = n->Data;
        delete n;
        return temp;

    }

    ~CExoLinkedListInternal();

    /* 0x0/0 */ CExoLinkedListNode *FirstElement;
    /* 0x4/4 */ CExoLinkedListNode *LastElement;
    /* 0x8/8 */ unsigned long Count;
};

#endif
