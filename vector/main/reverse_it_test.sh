c++ -Wall -Wextra -Werror -std=c++98 -D main/reversemain.cpp && ./a.out > stl.txt
c++ -Wall -Wextra -Werror -std=c++98 -D VALID=0 main/reversemain.cpp && ./a.out > moi.txt

diff stl.txt moi.txt

rm -rf stl.txt
rm -rf moi.txt
