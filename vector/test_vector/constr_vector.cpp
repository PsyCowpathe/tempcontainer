#include "../vector.tpp"
#include "tester.hpp"

#define TESTED_TYPE int


void  printvecs(std::string name, TESTED_NAMESPACE::vector<TESTED_TYPE> &vec)
{
               std::cout << name << ":" << std::endl;
 					std::cout << "_start = " << *vec.begin() << std::endl;
					std::cout << "capacity : " << vec.capacity() << std::endl;
					std::cout << "size : " << vec.size() << std::endl;
					std::cout << "content :" << std::endl;
					
					TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator tmp = vec.begin();
					
					while (tmp != vec.end())
					{
						std::cout << *tmp++ << std::endl;
					}

}
void printSize(TESTED_NAMESPACE::vector<TESTED_TYPE> &vec);
/*{
	std::cout << vec.size() << std::endl;
	std::cout << vec.capacity() << std::endl;
  TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator tmp = vec.begin();
			
			while (tmp != vec.end())
			{
				std::cout << *tmp++ << std::endl;
			}
}*/



int test_three()
{
    TESTED_NAMESPACE::vector<TESTED_TYPE> _default(9, 10);
    TESTED_NAMESPACE::vector<TESTED_TYPE> _default2(7, 666);
    TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator ita = _default.begin();
    TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = _default2.begin();
    TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator ite = _default2.end();
    TESTED_NAMESPACE::vector<TESTED_TYPE> range(it, ite);
    TESTED_NAMESPACE::vector<TESTED_TYPE> copy(_default);
    printvecs("default :", _default);
    ita++;

    _default.insert(ita, it, ite);
    printvecs("copy", copy);
    printvecs("default :", _default);
    _default.push_back(12);
        printvecs("default  after push_back(12) :" , _default);
    _default.pop_back();
        printvecs("default  after pop_back() :" , _default);
    std::cout << "is _default is empty ? " << _default.empty() << std::endl;
    
   
    std::cout << "_default == _default2 : " << (_default == _default2) << std::endl; 
    std::cout << "_default != _default2 : " << (_default != _default2) << std::endl; 
    std::cout << "_default >= _default2 : " << (_default >= _default2) << std::endl; 
    std::cout << "_default <= _default2 : " << (_default <= _default2) << std::endl; 
    std::cout << "_default > _default2 : " << (_default > _default2) << std::endl ;
    std::cout << "_default < _default2 : " << (_default < _default2) << std::endl ;
    
    
    TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator iter = _default.begin();
    TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator iters = _default.begin();
    TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator iter2 = _default2.begin();
    TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator iters2 = _default2.begin();

    TESTED_NAMESPACE::vector<TESTED_TYPE> test(12, 12);
    iter ++; 
    iter ++; 
    iter ++; 
    iters2 += 18;
    _default.insert(iter, 100, 100);
    iter = _default.begin();
    return(0);
}
