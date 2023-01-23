#include "../vector.tpp"
#include "tester.hpp"
#define TESTED_TYPE std::string

void	printSizes(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct, bool print_content = true)
{
	const size_t size = vct.size();
	const size_t capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator it = vct.begin();
		TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}


void pop_test(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = std::string((vct.size() - i), i + 65);
	printSizes(vct);

	vct.push_back("Hello");
	vct.push_back("Hi there");
	printSizes(vct);

	vct.push_back("ONE");
	vct.push_back("TWO");
	vct.push_back("THREE");
	vct.push_back("FOUR");

	printSizes(vct);
	vct.pop_back();
	vct.pop_back();
	printSizes(vct);
	vct.pop_back();
	vct.pop_back();
	vct.pop_back();
	vct.pop_back();
}
void	checkErase(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct,
					TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator const &it)
{
	static int i = 0;
	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
	printSizes(vct);
}

void erase_and_push(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = std::string((vct.size() - i), i + 65);
	printSizes(vct);

	checkErase(vct, vct.erase(vct.begin() + 2));

	checkErase(vct, vct.erase(vct.begin()));
	checkErase(vct, vct.erase(vct.end() - 1));

	checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
	checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

	vct.push_back("Hello");
	vct.push_back("Hi there");
	printSizes(vct);
	checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

	vct.push_back("ONE");
	vct.push_back("TWO");
	vct.push_back("THREE");
	vct.push_back("FOUR");
	printSizes(vct);
	checkErase(vct, vct.erase(vct.begin(), vct.end()));

}

int test_one()
{
	pop_test();
	erase_and_push();
	return(0);
}
