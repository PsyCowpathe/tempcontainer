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

    std::cout << std::endl << "| | | Init constructor && copy constructor | | |" << std::endl;
	{
    	gg::vector<int>::iterator   		tmp;
		tmp = test.begin();

    	gg::vector<int>::reverse_iterator	it(tmp);
        std::cout << "res : " << *it << std::endl;
	
		gg::vector<int>::reverse_iterator	copy(it);
        std::cout << "res : " << *it << std::endl;
	}

	std::cout << std::endl << "| | | Operator [+, ++var, +=, -=, -, *] | | |" << std::endl;
	{
		gg::vector<int>::reverse_iterator	it1;
		gg::vector<int>::reverse_iterator	it2;
		int									res;

		it1 = test.rbegin();
		it2 = test.rbegin();
		++it2;
		it2 = it2 + 1;
		res = *it1 + *it2;
		std::cout << "res : " << res << std::endl;
		it1 += 2;
		res = *it1 + *it2;
		std::cout << "res : " << res << std::endl;
		it1 -= 2;
		res = *it1 + *it2;
		std::cout << "res : " << res << std::endl;
		it2 = it2 - 1;
		res = *it1 + *it2;
		std::cout << "res : " << res << std::endl;
	}

	std::cout << std::endl << "| | | Operator [var--, --var] | | |" << std::endl;
	{
		gg::vector<int>::reverse_iterator	it1;
		gg::vector<int>::reverse_iterator	it2;
		int									res;

		it1 = test.rend();
		it2 = test.rend();
		it1--;
		res = *it1 + *it2;
		std::cout << "res : " << res << std::endl;
		res = *(--it1) + *it2;
		std::cout << "res : " << res << std::endl;
	}

 	/*std::cout << std::endl << "| | | operator [->] | | |" << std::endl;
    { //pour ce test utiliser le flag -std=c++0x
        class   tmp
        {
            public :
                int     value;
        };

		tmp 	test;
		gg::vector<tmp>						vec;
        gg::vector<tmp>::reverse_iterator	it;

		vec.push_back(test);
		it = vec.rend();
        it->value = 5;
        std::cout << "value = " << it->value << std::endl;
    }*/

 	std::cout << std::endl << "| | | operator [var[]] | | |" << std::endl;
    {
        gg::vector<int>::reverse_iterator	it;

		it = test.rbegin();
        std::cout << "value = " << it[3] << std::endl;
    }
	
	std::cout << std::endl << "| | | operator [<] | | |" << std::endl;
    {
        gg::vector<int>::reverse_iterator	it1;
        gg::vector<int>::reverse_iterator	it2;
		bool								res;

		it1 = test.rend(); //0
		it2 = test.rbegin(); //5
		res = it1 < it2;
		std::cout << "res : " << res << std::endl;
	
		res = it2 < it1;
		std::cout << "res : " << res << std::endl;
    }

	std::cout << std::endl << "| | | operator [>] | | |" << std::endl;
    {
        gg::vector<int>::reverse_iterator	it1;
        gg::vector<int>::reverse_iterator	it2;
		bool								res;

		it1 = test.rend(); //0
		it2 = test.rbegin(); //5
		res = it2 > it1;
		std::cout << "res : " << res << std::endl;
	
		res = it1 > it2;
		std::cout << "res : " << res << std::endl;
    }

	std::cout << std::endl << "| | | operator [<=] | | |" << std::endl;
    {
        gg::vector<int>::reverse_iterator	it1;
        gg::vector<int>::reverse_iterator	it2;
		bool								res;

		it1 = test.rend(); //0
		it2 = test.rend(); //0
		res = it1 <= it2;
		std::cout << "res : " << res << std::endl;
	
		it1--; // 1
		res = it2 <= it1;
		std::cout << "res : " << res << std::endl;

		res = it1 <= it2;
		std::cout << "res : " << res << std::endl;
    }

	std::cout << std::endl << "| | | operator [>=] | | |" << std::endl;
    {
        gg::vector<int>::reverse_iterator	it1;
        gg::vector<int>::reverse_iterator	it2;
		bool								res;

		it1 = test.rend(); //0
		it2 = test.rend(); //0
		res = it1 >= it2;
		std::cout << "res : " << res << std::endl;
	
		it1--; // 1
		res = it2 >= it1;
		std::cout << "res : " << res << std::endl;

		res = it1 >= it2;
		std::cout << "res : " << res << std::endl;
    }

	std::cout << std::endl << "| | | operator [==] | | |" << std::endl;
    {
        gg::vector<int>::reverse_iterator	it1;
        gg::vector<int>::reverse_iterator	it2;
		bool								res;

		it1 = test.rend(); //0
		it2 = test.rend(); //0
		res = it1 == it2;
		std::cout << "res : " << res << std::endl;
	
		it1--; // 1
		res = it2 == it1;
		std::cout << "res : " << res << std::endl;
    }

    return (0);
}
