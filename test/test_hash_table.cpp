#include "hash_table.h"
#include "Polynomials.h"
#include <gtest.h>

TEST(HashTable, can_create_hash_table)
{
  ASSERT_NO_THROW(HashTable<Polynomial> s(1));
}


TEST(HashTable, can_find_elem)
{
	HashTable<Polynomial> s(1);
	s.Insert("12", Polynomial("x^2"));
	ASSERT_NO_THROW(s.Find("12"));
}


TEST(HashTable, throws_when_finding_elem_with_nonexisting_id)
{
	HashTable<Polynomial> s(1);
	s.Insert("12", Polynomial("x^2"));
	ASSERT_ANY_THROW(s.Find("21"));
}


TEST(HashTable, can_insert_elem)
{
	HashTable<Polynomial> s(1);
	ASSERT_NO_THROW(s.Insert("12", Polynomial("x^2")));
}


TEST(HashTable, throws_when_inserting_elem_with_the_same_id)
{
	HashTable<Polynomial> s(1);
	s.Insert("12", Polynomial("x^2"));
	ASSERT_ANY_THROW(s.Insert("12", Polynomial("x^2")));
}


TEST(HashTable, can_create_copied_hash_table)
{
	HashTable<Polynomial> s(1);
	s.Insert("12", Polynomial("x^2"));
	ASSERT_NO_THROW(HashTable<Polynomial> s_c(s));
}



TEST(HashTable, can_delete_element)
{
	HashTable<Polynomial> s(1);
	s.Insert("12", Polynomial("x^2"));
	ASSERT_NO_THROW(s.Delete("12"));
}


TEST(HashTable, throws_when_deleting_elem_with_nonexisting_id)
{
	HashTable<Polynomial> s(1);
	s.Insert("12", Polynomial("x^2"));
	ASSERT_ANY_THROW(s.Delete("21"));
}


