#include "allocator.hpp"
#include <gtest/gtest.h> 

#ifdef RUN_TESTS
    //Проверка инициализации
    TEST(tts, tts0)
    {
        Allocator* allocator = init_allocator(100);
        EXPECT_NE(allocator, nullptr);
    }
    //Проверка выделения памяти
    TEST(tts, tts1)
    {
        Allocator* allocator = init_allocator(100);
        char* ptr = alloc(allocator, 20);
        EXPECT_NE(ptr, nullptr);
    }
    //Проверка на веделение всей памяти
    TEST(tts, tts2)
    {
        Allocator* allocator = init_allocator(100);
        char* ptr1 = alloc(allocator, 50);
        char* ptr2 = alloc(allocator, 51);
        EXPECT_NE(ptr1, nullptr);
        EXPECT_EQ(ptr2, nullptr);
    }
    //Проверка сброса
    TEST(tts, tts3)
    {
        Allocator* allocator = init_allocator(100);
        char* ptr1 = alloc(allocator, 50);
        reset(allocator);
        char* ptr2 = alloc(allocator, 50);
        EXPECT_NE(ptr1, nullptr);
        EXPECT_NE(ptr2, nullptr);
    }
#endif

