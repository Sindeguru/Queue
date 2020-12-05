#include "queue.h"

#include "../gtest/gtest.h"

TEST(Queue, can_create_steck_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> bf(3));
}
