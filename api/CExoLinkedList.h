#ifndef _CEXOLINKEDLIST_H_
#define _CEXOLINKEDLIST_H_
#include "nwndef.h"
#include "nwnstructs.h"
#include "CExoLinkedListInternal.h"

template <class T>
class CExoLinkedList
{
public:
    CExoLinkedListNode* AddAfter(T *e, CExoLinkedListNode *) { return List->AddAfter(e); }
    CExoLinkedListNode* AddBefore(T *e, CExoLinkedListNode *) { return List->AddBefore(e); }
    CExoLinkedListNode* AddHead(T *e) { return List->AddHead(e); }
    CExoLinkedListNode* AddTail(T *e) { return List->AddTail(e); }
    unsigned long Count() { return List->Count; }
    T* GetAtPos( CExoLinkedListNode *n) { return (T*)List->GetAtPos(n); };
    CExoLinkedListNode* GetHeadPos() { return List->FirstElement; }
    T* GetHead() { return (T*)List->GetAtPos(GetHead()); }
    void GetNext( CExoLinkedListNode *& node) { node = node->Next; }
    void GetPrev( CExoLinkedListNode *& node) { node = node->Previous; }
    CExoLinkedListNode* GetTailPos() { return List->LastElement; }
    int IsEmpty() { return List->Count == 0; }
    T* RemoveHead() { return (T*)List->RemoveHead(); }
    T* RemoveTail() { return (T*)List->RemoveTail(); }
    T* Remove( CExoLinkedListNode *n) { return (T*)List->Remove(n); }
    ~CExoLinkedList();
    CExoLinkedList();

    /* 0x0/0 */ CExoLinkedListInternal *List;
};


#endif
