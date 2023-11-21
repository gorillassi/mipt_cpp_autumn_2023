#include "allocator.hpp" 

Allocator* init_allocator(size_t maxSize){
    Allocator* alloc = new Allocator;

    if(alloc->buffer != nullptr){
        delete[] alloc->buffer;
    }

    alloc->buffer = new char[maxSize];
    alloc->size = maxSize;
    alloc->offset = 0;

    return alloc;
}

char* alloc(Allocator* alloc, size_t size){

    if(alloc->offset + size > alloc->size){
        return nullptr;
    }
    else{
        char* ret = alloc->buffer + (alloc->offset);
        alloc->offset += size;
        return ret;
    }
}

void reset(Allocator *alloc){
    alloc->offset = 0;
}

void clear(Allocator *alloc){
    delete[] alloc->buffer;
    delete alloc;
}