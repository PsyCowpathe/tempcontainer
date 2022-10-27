#ifndef VALID
    #include <vector>
    #include <utility>
    namespace gg = std;
#else
	#include "../vector.tpp"
    namespace gg = ft;
#endif

int     main(void)
{
    gg::vector<int>     test;

    std::cout << "| | | | | | | REVERSE ITERATOR TEST | | | | | | |" << std::endl;
    
    std::cout << std::endl << "| | | Normal constructor && operator [=, var++, !=] | | |" << std::endl;
    
    gg::vector<int>::reverse_iterator   it;

    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);

    it = test.rbegin();

    while (it != test.rend())
    {
        std::cout << "res : " << *it << std::endl;
        it++;
        if (it != test.rend())
            std::cout << std::endl;
    }

    std::cout << std::endl << "| | | Init constructor | | |" << std::endl;
	{
    	gg::vector<int>::iterator   		tmp;

		tmp = test.begin();
    	gg::vector<int>::reverse_iterator	it(tmp);

        std::cout << "res : " << *it << std::endl;
	}
    return (0);
}
