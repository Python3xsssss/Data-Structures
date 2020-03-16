#include "cyclic_queue.h"
#include <gtest.h>

TEST(CQueue, can_create_queue)
{
  ASSERT_NO_THROW(CQueue<int> s(1));
}


TEST(CQueue, can_create_copied_queue)
{
	CQueue<int> s(1);
	s.Push(1);
	ASSERT_NO_THROW(CQueue<int> s_c(s));
}

TEST(CQueue, can_push_elem)
{
	CQueue<int> s(5);
	ASSERT_NO_THROW(s.Push(14));
}

TEST(CQueue, can_pop_element)
{
	CQueue<int> s(5);
	s.Push(3);
	s.Push(1);
	EXPECT_EQ(3, s.Pop());
}

TEST(CQueue, can_get_count)
{
	CQueue<int> s(5);
	s.Push(1);
	EXPECT_EQ(1, s.GetCount());
}

TEST(CQueue, can_get_size)
{
	CQueue<int> s(5);
	EXPECT_EQ(5, s.GetSize());
}

TEST(CQueue, can_get_top_elem)
{
	CQueue<int> s(5);
	s.Push(3);
	EXPECT_EQ(3, s.Top());
}


TEST(CQueue, empty_queue_is_empty)
{
	CQueue<int> s(10);
	EXPECT_EQ(true, s.Empty());
}

TEST(CQueue, not_empty_queue_is_not_empty)
{
	CQueue<int> s(1);
	s.Push(1);
	EXPECT_EQ(false, s.Empty());
}

TEST(CQueue, full_stack_is_full)
{
	CQueue<int> s(5);
	for (size_t i = 0; i < 5; i++)
		s.Push(1);
	EXPECT_EQ(true, s.Full());
}

TEST(CQueue, not_full_queue_is_not_full)
{
	CQueue<int> s(5);
	s.Push(1);
	EXPECT_EQ(false, s.Full());
}

TEST(CQueue, throws_when_gets_top_elem_from_empty_queue)
{
	CQueue<int> s(5);
	ASSERT_ANY_THROW(s.Top());
}

TEST(CQueue, throws_when_underflow)
{
	CQueue<int> s(10);
	ASSERT_ANY_THROW(s.Pop());
}

TEST(CQueue, throws_when_overflow)
{
	CQueue<int> s(MAX_CQUEUE_SIZE);
	for (size_t i = 0; i < MAX_CQUEUE_SIZE; i++)
		s.Push(1);
	ASSERT_ANY_THROW(s.Push(1));
}


