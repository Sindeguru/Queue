#include "queue.h"

#include "../gtest/gtest.h"

TEST(TQueue, can_create_steck_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> bf(3));
}

TEST(TQueue, empty_true)
{
  TQueue<int> A(2);
  ASSERT_EQ(A.empty(), true);
}

TEST(TQueue, empty_false)
{
  TQueue<int> A(2);
  A.push(2);
  ASSERT_EQ(A.empty(), false);
}

TEST(TQueue, pop_take_right_element)
{
  TQueue<int> A(2);
  A.push(31);
  A.push(2);
  ASSERT_EQ(A.pop(), 31);
  ASSERT_EQ(A.pop(), 2);
}

TEST(TQueue, push_without_problems)
{
  TQueue<int> A(2);
  ASSERT_NO_THROW(A.push(13124125));
}

TEST(TQueue, create_queue_with_uncorrect_size)
{
  ASSERT_ANY_THROW(TQueue<int> A(-1));
}

TEST(TQueue, push_in_out_of_size)
{
  TQueue<int> A(0);
  ASSERT_ANY_THROW(A.push(13124125));
}

TEST(TQUeue, pop_in_empty_queue)
{
  TQueue<int> A(2);
  ASSERT_ANY_THROW(A.pop());
}
