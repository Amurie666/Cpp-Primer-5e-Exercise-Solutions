#include <iostream>
#include <vector>
int main()
{
  // The executable will throw an exception: terminate called after throwing an instance of 'std::out_of_range'
  // what():  vector::_M_range_check: __n (which is 0) >= this->size() (which is 0)
  std::vector<int> empty;
  std::cout << "at: " << empty.at(0) << std::endl;
  std::cout << "subscript: " << empty[0] << std::endl;
  std::cout << "front: " << empty.front() << std::endl;
  std::cout << "begin: " << *empty.begin() << std::endl;
}