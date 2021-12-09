cp main.cpp ./main_std.cpp
sed -i '' 's/ft::set/std::set/g' main_std.cpp
clang++ main_std.cpp -std=c++11 -o std_set
echo "- - - - - - - - - - - - - - - stl"
time ./std_set > std_output


clang++ main.cpp -std=c++11 -o ft_set
echo "- - - - - - - - - - - - - - - my"
time ./ft_set > ft_output

diff std_output ft_output

#rm -rf main_std.cpp ft_output std_output std_set ft_set