#include "pch.h"
#include <iostream>
#include "../SuckerPunch/Queue.cpp"


TEST(QueueTest, 64RangeTest) {

    Q* stq[65];
    for(int i = 0; i < 64; ++i)
    {
        EXPECT_NO_THROW(stq[i] = create_queue());
    }
    for(int i = 0; i < 64; ++i)
    {
        EXPECT_NO_THROW(destroy_queue(stq[i]));
    }

}


TEST(QueueTest, StringTest) {

    char s0[] = "lamhot";
    Q* q0 = create_queue();

    for (short int i = 0; i < sizeof(s0); i++)
    {
        enqueue_byte(q0, s0[i]);
    }

    char s1[6];
    for (short int i = 0; i < sizeof(s0); i++)
    {
        s1[i] = dequeue_byte(q0);
    }
    EXPECT_EQ(std::string(s0), std::string(s1));
    destroy_queue(q0);
}

TEST(QueueTest, DequeueEmptyTest)
{

    Q* q0 = create_queue();

    enqueue_byte(q0, 1);
    dequeue_byte(q0);
    EXPECT_ANY_THROW(dequeue_byte(q0));
    destroy_queue(q0);
}

TEST(QueueTest, IntTest) {
    char a = 65;
  
    Q* q0 = create_queue();
    Q* q2 = create_queue();

    for (int i = 0; i < 6; i++)
    {
        enqueue_byte(q0, i);
    }

    for (int i = 5; i >=0; i--)
    {
   // EXPECT_EQ(std::stoi(dequeue_byte(q0)), i);
    }

    destroy_queue(q0);
}
