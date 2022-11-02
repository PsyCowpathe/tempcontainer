c++ -Wall -Wextra -Werror -std=c++98 vectormain.cpp && ./a.out > moi.txt
c++ -Wall -Wextra -Werror -std=c++98 -D VALID=1 vectormain.cpp && ./a.out > stl.txt

diff moi.txt stl.txt

rm -rf moi.txt stl.txt
