#include "vector.hpp"
#include "algorithm.hpp"
#include "utility.hpp"
#include "iterator.hpp"

#include <vector>

int	main(void)
{
	ft::vector<int> first;                                // empty vector of ints
	ft::vector<int> second (4,100);                       // four ints with value 100
	ft::vector<int> third (second.begin(),second.end());  // iterating through second
	ft::vector<int> fourth (third);                       // a copy of third
	int myints[] = {16,2,77,29};
	ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "Vectors contain :\n";
	for (std::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	for (std::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

// int	main(void)
// {
// 	std::vector<int> first;                                // empty vector of ints
// 	std::vector<int> second (4,100);                       // four ints with value 100
// 	std::vector<int> third (second.begin(),second.end());  // iterating through second
// 	std::vector<int> fourth (third);                       // a copy of third
// 	int myints[] = {16,2,77,29};
// 	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

// 	std::cout << "Vectors contain :\n";
// 	for (std::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';
// 	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';
// 	for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';
// 	for (std::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';
// 	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';
// }