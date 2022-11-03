c++ -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3 vectormain.cpp && ./a.out > moi.txt
c++ -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3 -D VALID=1 vectormain.cpp && ./a.out > stl.txt

diff moi.txt stl.txt

rm -rf moi.txt stl.txt
