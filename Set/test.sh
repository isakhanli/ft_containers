cp main.cpp ./main_std.cpp
sed -i '' 's/ft::set/std::set/g' main_std.cpp
sed -i '' 's/ft::pair/std::pair/g' main_std.cpp
sed -i '' 's/ft::make_pair/std::make_pair/g' main_std.cpp
clang++ main_std.cpp -Wall -Wextra -Werror -std=c++98 -o std_set
echo "- - - - - - - - - - - - - - - stl"
time ./std_set > std_output


clang++ main.cpp -Wall -Wextra -Werror -std=c++98 -o ft_set
echo "- - - - - - - - - - - - - - - my"
time ./ft_set > ft_output

diff std_output ft_output

rm -rf main_std.cpp ft_output std_output std_set ft_set