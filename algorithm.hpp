#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

namespace ft
{

template <class InputIterator1, class InputIterator2>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
	for ( ; first1 != last1; first1++, first2++)
		if (!(*first1 != *first2))
			return false;
	return true;
}

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
{
  while (first1!=last1)
  {
    if (first2==last2 || *first2<*first1)
		return false;
    else if (*first1<*first2)
		return true;
    ++first1;
	++first2;
  }
  return (first2!=last2);
}

template <typename T> void swap(T &a, T &b)
{
    T	tmp(a);

    a = b;
    b = tmp;
}

}

#endif