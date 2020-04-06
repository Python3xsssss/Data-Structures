#include "sorted_table.h"
#include "Polynomials.h"
#include <gtest.h>

TEST(SortedTable, can_create_sorted_table)
{
  ASSERT_NO_THROW(SortedTable<Polynomial> s(1));
}


TEST(SortedTable, can_find_elem)
{
	SortedTable<Polynomial> s(1);
	s.Insert("12", Polynomial("x^2"));
	ASSERT_NO_THROW(s.Find("12"));
}


TEST(SortedTable, throws_when_finding_elem_with_nonexisting_id)
{
	SortedTable<Polynomial> s(1);
	s.Insert("12", Polynomial("x^2"));
	ASSERT_ANY_THROW(s.Find("21"));
}


TEST(SortedTable, can_insert_elem)
{
	SortedTable<Polynomial> s(1);
	ASSERT_NO_THROW(s.Insert("12", Polynomial("x^2")));
}


TEST(SortedTable, throws_when_inserting_elem_with_the_same_id)
{
	SortedTable<Polynomial> s(1);
	s.Insert("12", Polynomial("x^2"));
	ASSERT_ANY_THROW(s.Insert("12", Polynomial("x^2")));
}


TEST(SortedTable, can_create_copied_unsorted_table)
{
	SortedTable<Polynomial> s(1);
	s.Insert("12", Polynomial("x^2"));
	ASSERT_NO_THROW(SortedTable<Polynomial> s_c(s));
}



TEST(SortedTable, can_delete_element)
{
	SortedTable<Polynomial> s(1);
	s.Insert("12", Polynomial("x^2"));
	ASSERT_NO_THROW(s.Delete("12"));
}


TEST(SortedTable, throws_when_deleting_elem_with_nonexisting_id)
{
	SortedTable<Polynomial> s(1);
	s.Insert("12", Polynomial("x^2"));
	ASSERT_ANY_THROW(s.Delete("21"));
}


