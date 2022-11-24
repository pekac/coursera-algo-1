#ifndef RND_QUEUE_ITERATOR_H
#define RND_QUEUE_ITERATOR_H

#include "../../dsa/iterator.h"

template<class T>
class RndQuequeIterator: public Iterator<T> {
    private:
        int index;
        int n;
        T* randomArray;
        T* shuffleArray(T* array, int size);
    public:
        RndQuequeIterator(T* array, int size);

        ~RndQuequeIterator();

        bool hasNext();

        T next();
};

#endif