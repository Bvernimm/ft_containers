#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iterator>

namespace ft
{
template < class T, class Alloc = std::allocator<T> > class vector
{
/********************** Member types **********************/
	public:
		typedef T										value_type;
		typedef Alloc									allocator_type;
		typedef allocator_type::reference				reference;
		typedef allocator_type::const_reference			const_reference;
		typedef allocator_type::pointer					pointer;
		typedef allocator_type::const_pointer			const_pointer;
		typedef std::iterator<value_type>				iterator;
		typedef std::iterator<const value_type>			const_iterator;
		typedef ft::reverse_iterator<value_type>		reverse_iterator;
		typedef ft::reverse_iterator<const value_type>	const_reverse_iterator;
		typedef std::ptrdiff_t							difference_type;
		typedef std::size_t								size_type;

	protected:
		allocator_type	_allocator;
		pointer			_array;
		size_type		_filled_size;
		size_type		_maxsize;

/********************** Member functions **********************/
	/*********** Constructor/destructor ***********/
	explicit vector (const allocator_type &alloc = allocator_type())
	{
		_allocator = alloc;
		_array = 0;
		_filled_size = 0;
		_maxsize = 0;
	}
	explicit vector (size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
	{
		_allocator = alloc;
		_array = 0;//use later fct maybe

		_filled_size = n;
		_maxsize = n;
	}
	template <class InputIterator>vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
	{

	}
	vector (const vector &x)
	{

	}
	~vector()
	{

	}
	vector &operator= (const vector& x)
	{

	}

	/*********** Iterators ***********/
	iterator begin() { return _array; }
	const_iterator begin() const { return _array; }
	iterator end() { return _array + _filled_size; }
	const_iterator end() const { return _array + _filled_size; }
	reverse_iterator rbegin() { return _array + _filled_size; }
	const_reverse_iterator rbegin() const { return _array + _filled_size; }
	reverse_iterator rend() { return _array; }
	const_reverse_iterator rend() const { return _array; }

	/*********** Capacity ***********/
	size_type size() const { return _filled_size; }
	size_type max_size() const { return _allocator.max_size(); }
	size_type capacity() const { return _maxsize; }
	bool empty() const { return (_filled_size == 0); }
	void resize (size_type n, value_type val = value_type())
	{
		if (n < _filled_size)
		{
			pointer	tmp = _allocator.allocate(n);
			for (int i = 0; i < n; i++)
				tmp[i] = _array[i];
			_allocator.deallocate(_array, _maxsize);
			_array = tmp;
			_maxsize = n;
			_filled_size = n;
		}
		else if (n > _maxsize)
		{
			pointer	tmp = _allocator.allocate(n);
			for (int i = 0; i < _filled_size; i++)
				tmp[i] = _array[i];
			for (int i = _filled_size; i < n; i++)
				tmp[i] = val;
			_allocator.deallocate(_array, _maxsize);
			_maxsize = n;
			_filled_size = n;
			_array = tmp;
		}
		else if (n > _filled_size)
		{
			for (int i = _filled_size; i < n; i++)
				_array[i] = val;
			_filled_size = n;
		}
	}
	void reserve (size_type n)
	{
		if (n > max_size())
			throws std::length_error();
		if (n > _maxsize)
		{
			pointer	tmp = _allocator.allocate(n);
			for (int i = 0; i < _filled_size; i++)
				tmp[i] = _array[i];
			_allocator.deallocate(_array, _maxsize);
			_maxsize = n;
			_array = tmp;
		}
	}

	/*********** Element access ***********/
	reference operator[] (size_type n) { return (_array[n]); }
	const_reference operator[] (size_type n) const { return (_array[n]); }
	reference at (size_type n)
	{
		if (n >= size())
			throws std::out_of_range();
		else
			return (_array[n]);
	}
	const_reference at (size_type n) const
	{
		if (n >= size())
			throws std::out_of_range();
		else
			return (_array[n]);
	}
	reference front() { return (*begin()); }
	const_reference front() const { return (*begin()); }
	reference back() { return (*rbegin()); }
	const_reference back() const { return (*rbegin()); }
	value_type* data() noexcept { return (_array); }
	const value_type* data() const noexcept { return (_array); }

	/*********** Modifiers ***********/
	template <class InputIterator> void assign (InputIterator first, InputIterator last)
	{
		clear();
		insert(begin(), first, last);
	}
	void assign (size_type n, const value_type& val)
	{
		clear();
		insert(begin(), n, val);
	}

	void push_back (const value_type& val)
	{
		if (_filled_size == _maxsize)
		{
			_maxsize = _maxsize *2;
			reserve(_maxsize);
		}
		_allocator.construct( _array + _filled_size, val );
		_filled_size++;
	}
	void pop_back()
	{
		if (_filled_size > 0)
		{
			allocator.destroy(_array[_filled_size - 1]);
			_filled_size--;
		}
	}

	iterator insert (iterator position, const value_type& val);
	void insert (iterator position, size_type n, const value_type& val);
	template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last);

	iterator erase (iterator position);
	iterator erase (iterator first, iterator last);

	void swap (vector& x);

	void clear()
	{
		iterator	start;
		iterator	end;

		start = begin();
		end = end();
		for ( ; start != end; start++)
			allocator.destroy(&( *start ));
		_filled_size = 0;
	}

	/*********** Allocator ***********/
	allocator_type get_allocator() const;

};
template <class T, class Alloc>  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <class T, class Alloc>  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <class T, class Alloc>  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <class T, class Alloc>  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <class T, class Alloc>  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <class T, class Alloc>  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <class T, class Alloc>  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);


}

#endif