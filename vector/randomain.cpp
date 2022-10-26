#include "vector.tpp"
#include <vector>
#include <iterator>

int     main(void)
{
    ft::vector<int>     test;
    std::vector<int>    correct;

    std::cout << "| | | | | | | RANDOM ACCESS ITERATOR TEST | | | | | | |" << std::endl;

    std::cout << std::endl << "| | | Ptr constructor | | |" << std::endl;
    {
        int     value = 8;
        int     *ptr;

        ptr = &value;
        ft::vector<int>::iterator       myIt(ptr);
        std::vector<int>::iterator      corIt(ptr);

        std::cout << "Moi : " <<  *myIt << std::endl;
        std::cout << "Cor : " <<  *corIt << std::endl;
    }

    std::cout << std::endl << "| | | Copy constructor | | |" << std::endl;
    {
        int     value = 8;
        int     *ptr;

        ptr = &value;
        std::vector<int>::iterator      corIt(ptr);
        ft::vector<int>::iterator       myIt(ptr);
        ft::vector<int>::iterator       copyIt(myIt);

        std::cout << "Moi : " <<  *copyIt << std::endl;
        std::cout << "Cor : " <<  *corIt << std::endl;
    }

    std::cout << std::endl << "| | | Normal constructor + operator <!=, *, var++, => | | |" << std::endl;
    
        ft::vector<int>::iterator     it;
        std::vector<int>::iterator    cit;
        ft::vector<int>::iterator     ite;
        std::vector<int>::iterator    cite;

        correct.push_back(1);
        correct.push_back(2);
        correct.push_back(3);
        correct.push_back(4);
        correct.push_back(5);
        
        test.push_back(1);
        test.push_back(2);
        test.push_back(3);
        test.push_back(4);
        test.push_back(5);
        it = test.begin();
        ite = test.end();
        cit = correct.begin();
        cite = correct.end();

        while (it != ite && cit != cite)
        {
            std::cout << "moi : " << *it << std::endl;
            std::cout << "cor : " << *cit << std::endl;
            it++;
            cit++;
            if (it != ite)
                std::cout << std::endl;
        }
    

    std::cout << std::endl << "| | | operator == | | |" << std::endl;
    {
        ft::vector<int>::iterator     myit1;
        ft::vector<int>::iterator     myit2;
        std::vector<int>::iterator    corit1;
        std::vector<int>::iterator    corit2;
        bool                          res1;
        bool                          res2;

        corit1 = correct.begin();
        corit2 = correct.begin();
        myit1 = test.begin();
        myit2 = test.begin();
        res1 = myit1 == myit2;
        res2 = corit1 == corit2;
        std::cout << "moi : " << res1 << std::endl;
        std::cout << "cor : " << res2 << std::endl << std::endl;
        myit1++;
        corit1++;
        res1 = myit1 == myit2;
        res2 = corit1 == corit2;
        std::cout << "moi : " << res1 << std::endl;
        std::cout << "cor : " << res2 << std::endl;
    }

    std::cout << std::endl << "| | | operator < | | |" << std::endl;
    {
        ft::vector<int>::iterator     myit1;
        ft::vector<int>::iterator     myit2;
        std::vector<int>::iterator    corit1;
        std::vector<int>::iterator    corit2;
        bool                          res1;
        bool                          res2;

        corit1 = correct.begin(); //value = 1
        corit2 = correct.begin(); //value = 1
        myit1 = test.begin(); //value = 1
        myit2 = test.begin(); //value = 1
        res1 = myit1 < myit2; // 1 < 1
        res2 = corit1 < corit2; // 1 < 1
        std::cout << "moi : " << res1 << std::endl;
        std::cout << "cor : " << res2 << std::endl << std::endl;
        myit2++; //value = 2
        corit2++; //value = 2
        res1 = myit1 < myit2; // 1 < 2
        res2 = corit1 < corit2; // 1 < 2
        std::cout << "moi : " << res1 << std::endl;
        std::cout << "cor : " << res2 << std::endl;
    }

    std::cout << std::endl << "| | | operator > | | |" << std::endl;
    {
        ft::vector<int>::iterator     myit1;
        ft::vector<int>::iterator     myit2;
        std::vector<int>::iterator    corit1;
        std::vector<int>::iterator    corit2;
        bool                          res1;
        bool                          res2;

        corit1 = correct.begin(); //value = 1
        corit2 = correct.begin(); //value = 1
        myit1 = test.begin(); //value = 1
        myit2 = test.begin(); //value = 1
        res1 = myit1 > myit2; // 1 > 1
        res2 = corit1 > corit2; // 1 > 1
        std::cout << "moi : " << res1 << std::endl;
        std::cout << "cor : " << res2 << std::endl << std::endl;
        myit1++; //value = 2
        corit1++; //value = 2
        res1 = myit1 > myit2; // 2 > 1
        res2 = corit1 > corit2; // 2 > 1
        std::cout << "moi : " << res1 << std::endl;
        std::cout << "cor : " << res2 << std::endl;
    }

    std::cout << std::endl << "| | | operator <= | | |" << std::endl;
    {
        ft::vector<int>::iterator     myit1;
        ft::vector<int>::iterator     myit2;
        std::vector<int>::iterator    corit1;
        std::vector<int>::iterator    corit2;
        bool                          res1;
        bool                          res2;

        corit1 = correct.begin(); //value = 1
        corit2 = correct.begin(); //value = 1
        myit1 = test.begin(); //value = 1
        myit2 = test.begin(); //value = 1
        res1 = myit1 <= myit2; // 1 <= 1
        res2 = corit1 <= corit2; // 1 <= 1
        std::cout << "moi : " << res1 << std::endl;
        std::cout << "cor : " << res2 << std::endl << std::endl;
        myit2++; //value = 2
        corit2++; //value = 2
        res1 = myit1 <= myit2; // 1 <= 2
        res2 = corit1 <= corit2; // 1 <= 2
        std::cout << "moi : " << res1 << std::endl;
        std::cout << "cor : " << res2 << std::endl << std::endl;
        myit2--; //value = 1
        corit2--; //value = 1
        myit1++; //value = 2
        corit1++; //value = 2
        res1 = myit1 <= myit2; // 2 <= 1
        res2 = corit1 <= corit2; // 2 <= 1
        std::cout << "moi : " << res1 << std::endl;
        std::cout << "cor : " << res2 << std::endl;
    }

    std::cout << std::endl << "| | | operator >= && var--| | |" << std::endl;
    {
        ft::vector<int>::iterator     myit1;
        ft::vector<int>::iterator     myit2;
        std::vector<int>::iterator    corit1;
        std::vector<int>::iterator    corit2;
        bool                          res1;
        bool                          res2;

        corit1 = correct.begin(); //value = 1
        corit2 = correct.begin(); //value = 1
        myit1 = test.begin(); //value = 1
        myit2 = test.begin(); //value = 1
        res1 = myit1 >= myit2; // 1 >= 1
        res2 = corit1 >= corit2; // 1 >= 1
        std::cout << "moi : " << res1 << std::endl;
        std::cout << "cor : " << res2 << std::endl << std::endl;
        myit2++; //value = 2
        corit2++; //value = 2
        res1 = myit1 >= myit2; // 1 >= 2
        res2 = corit1 >= corit2; // 1 >= 2
        std::cout << "moi : " << res1 << std::endl;
        std::cout << "cor : " << res2 << std::endl << std::endl;
        myit2--; //value = 1
        corit2--; //value = 1
        myit1++; //value = 2
        corit1++; //value = 2
        res1 = myit1 >= myit2; // 2 >= 1
        res2 = corit1 >= corit2; // 2 >= 1
        std::cout << "moi : " << res1 << std::endl;
        std::cout << "cor : " << res2 << std::endl;
    }

    std::cout << std::endl << "| | | operator -> | | |" << std::endl;
    {
        class   tmp
        {
            public :
                int     value;
        };

        tmp     test;
        ft::random_access_iterator<tmp>  myit1(&test);

        myit1->value = 5;
        std::cout << "value = " << myit1->value << std::endl;
    }

    std::cout << std::endl << "| | | operator ++var && --var | | |" << std::endl;
    {
        ft::vector<int>::iterator     myit;
        std::vector<int>::iterator    corit;
        int                           res1;
        int                           res2;


        myit = test.begin();
        corit = correct.begin();
        res1 = *(++myit) + 4;
        res2 = *(++corit) + 4;
        std::cout << "moi : " << res1 << std::endl;
        std::cout << "cor : " << res2 << std::endl << std::endl;
        res1 = *(--myit) + 4;
        res2 = *(--corit) + 4;
        std::cout << "moi : " << res1 << std::endl;
        std::cout << "cor : " << res2 << std::endl;
    }

    std::cout << std::endl << "| | | operator + && - | | |" << std::endl;
    {
        ft::vector<int>::iterator     myit1;
        std::vector<int>::iterator    corit1;
        ft::vector<int>::iterator     myit2(test.begin());
        std::vector<int>::iterator    corit2;
        int                           res1;
        int                           res2;


        myit1 = test.begin();
        corit1 = correct.begin();
        myit1 = myit1 + 1;
        corit1 = corit1 + 1;
        std::cout << "moi : " << *myit1 << std::endl;
        std::cout << "cor : " << *corit1 << std::endl;
        myit1 = myit1 - 1;
        corit1 = corit1 - 1;
        std::cout << "moi : " << *myit1 << std::endl;
        std::cout << "cor : " << *corit1 << std::endl;
        myit2 = test.begin();
        corit2 = correct.begin();
        res1 = myit1 - myit2;
        res2 = corit1 - corit2;
        std::cout << "moi : " << *myit1 << std::endl;
        std::cout << "cor : " << *corit1 << std::endl;
    }

    std::cout << std::endl << "| | | operator += && -= && var[] | | |" << std::endl;
    {
        ft::vector<int>::iterator           myit;
        std::vector<int>::iterator          corit;
        int                                 res1;
        int                                 res2;


        myit = test.begin();
        corit = correct.begin();
        myit += 4;
        corit += 4;
        std::cout << "moi : " << *myit << std::endl;
        std::cout << "cor : " << *corit << std::endl << std::endl;
        myit -= 3;
        corit -= 3;
        std::cout << "moi : " << *myit << std::endl;
        std::cout << "cor : " << *corit << std::endl << std::endl;
        std::cout << "moi : " << myit[2] << std::endl;
        std::cout << "cor : " << corit[2] << std::endl;
    }

    std::cout << std::endl << "| | | const comparation | | |" << std::endl;
    {
        ft::vector<int>::const_iterator             myconstit;
        ft::vector<int>::iterator                   myit;
        std::vector<int>::iterator                  corit;
        std::vector<int>::const_iterator            corconstit;
        int                                         res1;
        int                                         res2;

        myit = test.begin();
        myconstit = test.begin();
        corit = correct.begin();
        corconstit = correct.begin();
        res1 = myit < myconstit;
        res2 = corit < corconstit;
        std::cout << "moi : " << res1 << std::endl;
        std::cout << "cor : " << res2 << std::endl;
    }
    return (0);
}