#include "AVLTree.h"
#include <gtest.h>
TEST(AVLTree, can_create_tree)
{
	ASSERT_NO_THROW(AVLTree<int>());
}

TEST(AVLTree, can_insert_element)
{
	AVLTree<int> tree;
	tree.Insert(1, 3);
	EXPECT_EQ(1, tree.Find(3));
}

TEST(AVLTree, can_delete_element)
{
	AVLTree<int> tree;
	tree.Insert(1, 3);
	tree.Delete(3);
	ASSERT_ANY_THROW(tree.Find(3));
}


TEST(AVLTree, empty_tree_empty)
{
	AVLTree<int> tree;
	EXPECT_EQ(true, tree.Empty());
}

TEST(AVLTree, not_empty_tree_is_not_empty)
{
	AVLTree<int> tree;
	tree.Insert(1, 3);
	EXPECT_EQ(false, tree.Empty());
}

TEST(AVLTree, can_get_height_of_tree)
{
	AVLTree<int> tree;
	tree.Insert(2, 5);
	EXPECT_EQ(1, tree.GetHeight());
}


