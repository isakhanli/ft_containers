cp main.cpp ./main_std.cpp
sed -i 's/ft::vector/std::vector/g' main_std.cpp
clang++ main_std.cpp -std=c++98 -o std_vector
echo "- - - - - - - - - - - - - - - stl"
time ./std_vector > std_output


clang++ main.cpp -std=c++98 -o ft_vector
echo "- - - - - - - - - - - - - - - my"
time ./ft_vector > ft_output

diff std_output ft_output

rm -rf main_std.cpp ft_output std_output std_vector ft_vector