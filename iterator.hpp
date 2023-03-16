#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include <iterator>

namespace ft
{

/*********** std::iterator_traits ***********/

template <class Iterator> class iterator_traits
{
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;
};

template <class T> class iterator_traits<T*>
{
	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef std::random_access_iterator_tag	iterator_category;
};

template <class T> class iterator_traits<const T*>
{
	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef std::random_access_iterator_tag	iterator_category;
};

/*********** std::reverse_iterator ***********/

template< class Iter > class reverse_iterator
{
	public:
		typedef Iter								iterator_type;
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	protected:
		Iter	current;
	public:
		reverse_iterator():current() {}
		reverse_iterator(iterator_type x):current(x) {}
		template <class U>
		reverse_iterator(const reverse_iterator<U> &other):current(other.current) {}

		template <class U>
		reverse_iterator& operator=(const reverse_iterator<U> &other) {
			current = other.current;
			return *this;
		}
		iterator_type base() const { return current; }
		reference operator*() const { Iter tmp = current; return *--tmp; }
		pointer operator->() const { return &(operator*()); }
		reference operator[](difference_type n) const { return *(*this + n); }

		reverse_iterator& operator++() { --current; return (*this); }
		reverse_iterator& operator--() { ++current; return (*this); }
		reverse_iterator operator++( int ) { reverse_iterator tmp(*this); --current; return (tmp); }
		reverse_iterator operator--( int ) { reverse_iterator tmp(*this); ++current; return (tmp); }
		reverse_iterator operator+( difference_type n ) const { return reverse_iterator(current - n); }
		reverse_iterator operator-( difference_type n ) const { return reverse_iterator(current + n); }
		reverse_iterator& operator+=( difference_type n ) { current -= n; return (*this); }
		reverse_iterator& operator-=( difference_type n ) { current += n; return (*this); }
};

template< class Iter > class iterator
{
	public:
		typedef Iter								iterator_type;
		typedef typename iterator_traits<Iter>::difference_type		difference_type;
		typedef typename iterator_traits<Iter>::value_type			value_type;
		typedef typename iterator_traits<Iter>::pointer				pointer;
		typedef typename iterator_traits<Iter>::reference			reference;
		typedef typename iterator_traits<Iter>::iterator_category	iterator_category;
	protected:
		Iter	current;
	public:
		iterator():current() {}
		iterator(iterator_type x):current(x) {}
		template <class U>
		iterator(const iterator<U> &other):current(other.current) {}

		template <class U>
		iterator& operator=(const iterator<U> &other) {
			current = other.current;
			return *this;
		}
		iterator_type base() const { return current; }
		reference operator*() const { return current; }
		pointer operator->() const { return &(operator*()); }
		reference operator[](difference_type n) const { return *(*this + n); }

		iterator& operator++() { ++current; return (*this); }
		iterator& operator--() { --current; return (*this); }
		iterator operator++( int ) { iterator tmp(*this); ++current; return (tmp); }
		iterator operator--( int ) { iterator tmp(*this); --current; return (tmp); }
		iterator operator+( difference_type n ) const { return iterator(current + n); }
		iterator operator-( difference_type n ) const { return iterator(current - n); }
		iterator& operator+=( difference_type n ) { current += n; return (*this); }
		iterator& operator-=( difference_type n ) { current -= n; return (*this); }
};

template< class Iterator1, class Iterator2 >
bool operator==( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs ) {
	return (lhs.base() == rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator!=(const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs ) {
	return (lhs.base() != rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator<(const std::reverse_iterator<Iterator1>& lhs,  const std::reverse_iterator<Iterator2>& rhs ) {
	return (lhs.base() > rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator<=(const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs ) {
	return (lhs.base() >= rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator>(const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs ) {
	return (lhs.base() < rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator>=(const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs ) {
	return (lhs.base() <= rhs.base());
}

template< class Iter >
reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it ) {
	return (reverse_iterator<Iter>(it.base() - n));
}

template< class Iterator1, class Iterator2 >
typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
	return (rhs.base() - lhs.base());
}

}

#endif