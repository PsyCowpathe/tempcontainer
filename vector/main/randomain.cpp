/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomain.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:14:40 by agirona           #+#    #+#             */
/*   Updated: 2022/11/02 18:16:55 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID
    # include <vector>
    # include <utility>
	# include <iostream>
    namespace gg = std;
#else
	# include "../vector.tpp"
    namespace gg = ft;
#endif

int     main(void)
{
    gg::vector<int>     test;

    std::cout << "| | | | | | | RANDOM ACCESS ITERATOR TEST | | | | | | |" << std::endl;

    std::cout << std::endl << "| | | Ptr constructor | | |" << std::endl;
    {
        int     value = 8;
        int     *ptr;

        ptr = &value;
        gg::vector<int>::iterator       myIt(ptr);

        std::cout << "res : " <<  *myIt << std::endl;
    }

    std::cout << std::endl << "| | | Copy constructor | | |" << std::endl;
    {
        int     value = 8;
        int     *ptr;

        ptr = &value;
        gg::vector<int>::iterator       myIt(ptr);
        gg::vector<int>::iterator       copyIt(myIt);

        std::cout << "res : " <<  *copyIt << std::endl;
    }

    std::cout << std::endl << "| | | Normal constructor + operator <!=, *, var++, => | | |" << std::endl;
    
        gg::vector<int>::iterator     it;
        gg::vector<int>::iterator     ite;

        test.push_back(1);
        test.push_back(2);
        test.push_back(3);
        test.push_back(4);
        test.push_back(5);
        it = test.begin();
        ite = test.end();

        while (it != ite)
        {
            std::cout << "res : " << *it << std::endl;
            it++;
            if (it != ite)
                std::cout << std::endl;
        }
    

    std::cout << std::endl << "| | | operator == | | |" << std::endl;
    {
        gg::vector<int>::iterator     myit1;
        gg::vector<int>::iterator     myit2;
        bool                          res1;

        myit1 = test.begin();
        myit2 = test.begin();
        res1 = myit1 == myit2;
        std::cout << "res : " << res1 << std::endl;
        myit1++;
        res1 = myit1 == myit2;
        std::cout << "res : " << res1 << std::endl;
    }

    std::cout << std::endl << "| | | operator < | | |" << std::endl;
    {
        gg::vector<int>::iterator     myit1;
        gg::vector<int>::iterator     myit2;
        bool                          res1;

        myit1 = test.begin(); //value = 1
        myit2 = test.begin(); //value = 1
        res1 = myit1 < myit2; // 1 < 1
        std::cout << "res : " << res1 << std::endl;
        myit2++; //value = 2
        res1 = myit1 < myit2; // 1 < 2
        std::cout << "res : " << res1 << std::endl;
    }

    std::cout << std::endl << "| | | operator > | | |" << std::endl;
    {
        gg::vector<int>::iterator     myit1;
        gg::vector<int>::iterator     myit2;
        bool                          res1;

        myit1 = test.begin(); //value = 1
        myit2 = test.begin(); //value = 1
        res1 = myit1 > myit2; // 1 > 1
        std::cout << "res : " << res1 << std::endl;
        myit1++; //value = 2
        res1 = myit1 > myit2; // 2 > 1
        std::cout << "res : " << res1 << std::endl;
    }

    std::cout << std::endl << "| | | operator <= | | |" << std::endl;
    {
        gg::vector<int>::iterator     myit1;
        gg::vector<int>::iterator     myit2;
        bool                          res1;

        myit1 = test.begin(); //value = 1
        myit2 = test.begin(); //value = 1
        res1 = myit1 <= myit2; // 1 <= 1
        std::cout << "res : " << res1 << std::endl;
        myit2++; //value = 2
        res1 = myit1 <= myit2; // 1 <= 2
        std::cout << "res : " << res1 << std::endl;
        myit2--; //value = 1
        myit1++; //value = 2
        res1 = myit1 <= myit2; // 2 <= 1
        std::cout << "res : " << res1 << std::endl;
    }

    std::cout << std::endl << "| | | operator >= && var--| | |" << std::endl;
    {
        gg::vector<int>::iterator     myit1;
        gg::vector<int>::iterator     myit2;
        bool                          res1;

        myit1 = test.begin(); //value = 1
        myit2 = test.begin(); //value = 1
        res1 = myit1 >= myit2; // 1 >= 1
        std::cout << "res : " << res1 << std::endl;
        myit2++; //value = 2
        res1 = myit1 >= myit2; // 1 >= 2
        std::cout << "res : " << res1 << std::endl;
        myit2--; //value = 1
        myit1++; //value = 2
        res1 = myit1 >= myit2; // 2 >= 1
        std::cout << "res : " << res1 << std::endl;
    }

    /*std::cout << std::endl << "| | | operator -> | | |" << std::endl;
    { //pour ce test utiliser le flag -std=c++0x
        class   tmp
        {
            public :
                int     value;
        };

        tmp     test;
        gg::random_access_iterator<tmp>  myit1(&test);

        myit1->value = 5;
        std::cout << "value = " << myit1->value << std::endl;
    }*/

    std::cout << std::endl << "| | | operator ++var && --var | | |" << std::endl;
    {
        gg::vector<int>::iterator     myit;
        int                           res1;

        myit = test.begin();
        res1 = *(++myit) + 4;
        std::cout << "res : " << res1 << std::endl;
        res1 = *(--myit) + 4;
        std::cout << "res : " << res1 << std::endl;
    }

    std::cout << std::endl << "| | | operator + && - | | |" << std::endl;
    {
        gg::vector<int>::iterator     myit1;
        gg::vector<int>::iterator     myit2(test.begin());
        int                           res1;

        myit1 = test.begin();
        myit1 = myit1 + 1;
        std::cout << "res : " << *myit1 << std::endl;
        myit1 = myit1 - 1;
        std::cout << "res : " << *myit1 << std::endl;
        myit2 = test.begin();
        res1 = myit1 - myit2;
        std::cout << "res : " << *myit1 << std::endl;
    }

    std::cout << std::endl << "| | | operator += && -= && var[] | | |" << std::endl;
    {
        gg::vector<int>::iterator           myit;

        myit = test.begin();
        myit += 4;
        std::cout << "res : " << *myit << std::endl;
        myit -= 3;
        std::cout << "res : " << *myit << std::endl;
        std::cout << "res : " << myit[2] << std::endl;
    }

    std::cout << std::endl << "| | | const comparation | | |" << std::endl;
    {
        gg::vector<int>::const_iterator             myconstit;
        gg::vector<int>::iterator                   myit;
        int                                         res1;

        myit = test.begin();
        myconstit = test.begin();
        res1 = myit < myconstit;
        std::cout << "res : " << res1 << std::endl;
    }
    return (0);
}
