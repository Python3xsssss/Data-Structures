#include "unsorted_table.h"
#include "Polynomials.h"
#include <gtest.h>

TEST(UnsortedTable, can_create_unsorted_table)
{
  ASSERT_NO_THROW(UnsortedTable<Polynomial> s(1));
}


TEST(UnsortedTable, can_find_elem)
{
	UnsortedTable<Polynomial> s(1);
	s.Insert("12", Polynomial("x^2"));
	ASSERT_NO_THROW(s.Find("12"));
}


TEST(UnsortedTable, throws_when_finding_elem_with_nonexisting_id)
{
	UnsortedTable<Polynomial> s(1);
	s.Insert("12", Polynomial("x^2"));
	ASSERT_ANY_THROW(s.Find("21"));
}


TEST(UnsortedTable, can_insert_elem)
{
	UnsortedTable<Polynomial> s(1);
	ASSERT_NO_THROW(s.Insert("12", Polynomial("x^2")));
}


TEST(UnsortedTable, throws_when_inserting_elem_with_the_same_id)
{
	UnsortedTable<Polynomial> s(1);
	s.Insert("12", Polynomial("x^2"));
	ASSERT_ANY_THROW(s.Insert("12", Polynomial("x^2")));
}


TEST(UnsortedTable, can_create_copied_unsorted_table)
{
	UnsortedTable<Polynomial> s(1);
	s.Insert("12", Polynomial("x^2"));
	ASSERT_NO_THROW(UnsortedTable<Polynomial> s_c(s));
}



TEST(UnsortedTable, can_delete_element)
{
	UnsortedTable<Polynomial> s(1);
	s.Insert("12", Polynomial("x^2"));
	ASSERT_NO_THROW(s.Delete("12"));
}


TEST(UnsortedTable, throws_when_deleting_elem_with_nonexisting_id)
{
	UnsortedTable<Polynomial> s(1);
	s.Insert("12", Polynomial("x^2"));
	ASSERT_ANY_THROW(s.Delete("21"));
}


