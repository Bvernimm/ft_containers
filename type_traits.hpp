#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP


namespace ft
{

template<bool Cond, class T = void > struct enable_if {};
template<class T> struct enable_if<true, T> { typedef T type; };


template <class T> struct is_integral						: public false_type{};

template <> struct is_integral< bool >						: public true_type {};
template <> struct is_integral< char >						: public true_type {};
template <> struct is_integral< wchar_t >					: public true_type {};
template <> struct is_integral< signed char >				: public true_type {};
template <> struct is_integral< short int >					: public true_type {};
template <> struct is_integral< int >						: public true_type {};
template <> struct is_integral< long int >					: public true_type {};
template <> struct is_integral< long long int >				: public true_type {};
template <> struct is_integral< unsigned char >				: public true_type {};
template <> struct is_integral< unsigned short int >		: public true_type {};
template <> struct is_integral< unsigned int >				: public true_type {};
template <> struct is_integral< unsigned long int >			: public true_type {};
template <> struct is_integral< unsigned long long int >	: public true_type {};

template <> struct is_integral< const bool >						: public true_type {};
template <> struct is_integral< const char >						: public true_type {};
template <> struct is_integral< const wchar_t >						: public true_type {};
template <> struct is_integral< const signed char >					: public true_type {};
template <> struct is_integral< const short int >					: public true_type {};
template <> struct is_integral< const int >							: public true_type {};
template <> struct is_integral< const long int >					: public true_type {};
template <> struct is_integral< const long long int >				: public true_type {};
template <> struct is_integral< const unsigned char >				: public true_type {};
template <> struct is_integral< const unsigned short int >			: public true_type {};
template <> struct is_integral< const unsigned int >				: public true_type {};
template <> struct is_integral< const unsigned long int >			: public true_type {};
template <> struct is_integral< const unsigned long long int >		: public true_type {};

}

#endif