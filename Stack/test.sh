cp main.cpp ./main_std.cpp
sed -i 's/ft::stack/std::stack/g' main_std.cpp
clang++ main_std.cpp -std=c++98 -o std_stack
echo "- - - - - - - - - - - - - - - stl"
time ./std_stack > std_output


clang++ main.cpp -std=c++98 -o ft_stack
echo "- - - - - - - - - - - - - - - my"
time ./ft_stack > ft_output

diff std_output ft_output

rm -rf main_std.cpp ft_output std_output ft_stack std_stack