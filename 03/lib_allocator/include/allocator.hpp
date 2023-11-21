#pragma once

#include <iostream> 

struct Allocator{
    size_t offset;
    size_t size;
    char* buffer;
};

Allocator* init_allocator(size_t maxSize);

char* alloc(Allocator* alloc, size_t size);

void reset(Allocator *alloc);

void clear(Allocator *alloc);