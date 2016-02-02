#ifndef _CEXOARRAYLIST_H_
#define _CEXOARRAYLIST_H_

#include <algorithm>

// Only use for nwserver interoperability.

template <class T>
class CExoArrayList
{
public:
    // Extensions
    typedef T* iterator;
    typedef const T* const_iterator;
    const_iterator cbegin() const { return Array; }
    const_iterator cend() const { return Array+Length; }
    iterator begin() { return Array; }
    iterator end() { return Array+Length; }
    const_iterator begin() const { return cbegin(); }
    const_iterator end() const { return cend(); }

    // Default
    int AddUnique(T);
    void Add(T);
    void Allocate(unsigned long);
    int Contains(T);
    int DelIndex(int);
    int DerefContains(T);
    int IndexOf(T);
    void Insert(T, int);
    void Pack();
    void Remove(T);
    int SetSize(int);
    CExoArrayList<T>& operator=(CExoArrayList<T> const &);
    T & operator[](int) const;
    T & operator[](int);
    CExoArrayList(int);
    CExoArrayList(CExoArrayList<T> const &);
    ~CExoArrayList();

    /* 0x0/0 */ T *Array;

    /* You might have come here for compile errors regarding nAllocatedSize.
     * The fields were labelled incorrectly, so they have been swapped.
     * In order to not break plugins in subtle ways we've renamed them.
     * You probably want "Length" now.
     */
    /* 0x4/4 */ unsigned long Length;
    /* 0x8/8 */ unsigned long ArraySize;
};

template <class T>
bool operator==(const CExoArrayList<T>& lhs, const CExoArrayList<T>& rhs) {
    if(lhs.Length != rhs.Length) { return false; }
    for(size_t i = 0; i < lhs.Length; ++i) {
        if(lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}

template <class T>
bool operator!=(const CExoArrayList<T>& lhs, const CExoArrayList<T>& rhs) {
    return !(lhs == rhs);
}

template <class T>
int CExoArrayList<T>::AddUnique(T ele)
{
    if(IndexOf(ele) == -1) {
        Add(ele);
        return 1;
    }
    return 0;
}

template <class T>
void CExoArrayList<T>::Pack() {
    // Pack normally would reallocate the array to
    // the size of its current length.
}

template <class T>
void CExoArrayList<T>::Add(T ele)
{
    if(Length == ArraySize) {
        // Not default.  Original growth factor is Length + 1
        Allocate(1.5*ArraySize);
    }
    Array[Length++] = ele;
}

template <class T>
void CExoArrayList<T>::Allocate(unsigned long size) {
    if(size > ArraySize) {
        T* temp = new T[size];
        ArraySize = size;
        std::copy(Array, Array + Length, temp);
        delete[] Array;
        Array = temp;
    }
}

template <class T>
int CExoArrayList<T>::Contains(T ele) {
    return IndexOf(ele) != -1;
}

template <class T>
int CExoArrayList<T>::DelIndex(int index) {
    if (!Length || index >= Length) { return -1; }
    std::rotate(begin()+index, begin()+index+1, end());
    --Length;
    return 0;
}

template <class T>
int CExoArrayList<T>::DerefContains(T ele) {
    for(size_t i = 0; i < Length; ++i) {
        if(*ele == *Array[i]) { return 1; }
    }
    return 0;
}

template <class T>
int CExoArrayList<T>::IndexOf(T ele) {
    T* it = std::find(Array, Array + Length, ele);
    if (it == Array + Length) {
        return -1;
    }
    else {
        return std::distance(Array, it);
    }
}

template <class T>
void CExoArrayList<T>::Insert(T ele, int index) {
    if(index >= 0 && index < Length) {
        Add(ele);
        std::rotate(begin()+index, end()-1, end());
    }
}

template <class T>
void CExoArrayList<T>::Remove(T ele) {
    T* it = std::remove(begin(), end(), ele);
    Length -= std::distance(it, end());
}

template <class T>
int CExoArrayList<T>::SetSize(int size) {
    if (size > ArraySize) {
        Allocate(size);
    }
    return ArraySize;
}

template <class T>
CExoArrayList<T>& CExoArrayList<T>::operator=(CExoArrayList<T> const &other) {
    if(this != &other) {
        if(Array) {
            delete[] Array;
            Array = new T[other.ArraySize];
            Length = other.Length;
            ArraySize = other.ArraySize;
            std::copy(other.begin(), other.end(), begin());
        }
    }
    return *this;
}

template <class T>
T& CExoArrayList<T>::operator[](int index) const {
    return Array[index];
}

template <class T>
T& CExoArrayList<T>::operator[](int index) {
    return Array[index];
}

template <class T>
CExoArrayList<T>::CExoArrayList(int size)
{
    Array = new T[size];
    Length = 0;
    ArraySize = size;
}

template <class T>
CExoArrayList<T>::CExoArrayList(const CExoArrayList<T> &other)
{
    Array = new T[other.ArraySize];
    Length = other.Length;
    ArraySize = other.ArraySize;
    std::copy(other.begin(), other.end(), begin());
}

template <class T>
CExoArrayList<T>::~CExoArrayList()
{
    delete[] Array;
    Length = ArraySize = 0;
    Array = nullptr;
}
#endif
