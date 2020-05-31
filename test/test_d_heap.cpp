#include "d_heap.h"
#include <gtest.h>
TEST(DHeap, can_create_d_heap)
{
	ASSERT_NO_THROW(DHeap<int>(3));
}

TEST(DHeap, can_create_copied_d_heap)
{
	DHeap<int> heap(2);
	ASSERT_NO_THROW(DHeap<int>(heap));
}

TEST(DHeap, can_insert_element)
{
	DHeap<int> heap(2);
	ASSERT_NO_THROW(heap.Insert(3, 5));
}


TEST(DHeap, can_delete_min_element)
{
	DHeap<int> heap(2);
	heap.Insert(3, 5);
	heap.Insert(4, 6);
	ASSERT_NO_THROW(heap.DeleteMin());
}


