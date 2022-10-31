c++ -Wall -Wextra -Werror -std=c++98 -D randomain.cpp && ./a.out > stl.txt
c++ -Wall -Wextra -Werror -std=c++98 -D VALID=1 randomain.cpp && ./a.out > moi.txt

diff stl.txt moi.txt

rm -rf stl.txt
rm -rf moi.txt
