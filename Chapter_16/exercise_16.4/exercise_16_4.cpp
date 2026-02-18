#include <vector>
#include <iostream>

template<typename iter_type, typename val_type>
iter_type find(iter_type beg, iter_type end, const val_type& val) {
    while(beg != end) {
        if(*beg==val) return beg;
        ++beg;
    }    
    return end;
}

int main() {
    // List works in similar manners.
    std::vector<int> x = {1, 2, 3, 4, 5};
    std::cout << *find(x.begin(), x.end(), 5);
}