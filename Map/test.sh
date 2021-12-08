cp main.cpp ./main_std.cpp
sed -i '' 's/ft::map/std::map/g' main_std.cpp
sed -i '' 's/ft::pair/std::pair/g' main_std.cpp
sed -i '' 's/ft::make_pair/std::make_pair/g' main_std.cpp
clang++ main_std.cpp -std=c++11 -o std_map
echo "- - - - - - - - - - - - - - - stl"
time ./std_map > std_output


clang++ main.cpp -std=c++11 -o ft_map
echo "- - - - - - - - - - - - - - - my"
time ./ft_map > ft_output

diff std_output ft_output

#rm -rf main_std.cpp ft_output std_output std_map ft_map