#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <cmath>
#include "vector.h"
#include <vector>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;

int main() {

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;

    unsigned int sz = 100000000;
    int countV1 = 0;
    int countV2 = 0;

    start = std::chrono::high_resolution_clock::now();
    std::vector<int> v1;
    for (int i = 1; i <= sz; ++i){
        v1.push_back(i);
        if (v1.capacity() == v1.size()) countV1++;
    }
    
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time = end-start;
    cout << "Self made vector uztruko " << time.count() << "sec"  << endl;
    cout << "countv1 = " << countV1 << endl;
    
    
    start = std::chrono::high_resolution_clock::now();
    std::vector<int> v2;
    for (int i = 1; i <= sz; ++i) {
        v2.push_back(i);
        if (v2.capacity() == v2.size()) countV2++;
    }
    
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time1 = end-start;
    cout << "std::vector uztruko " << time1.count() << "sec"  << endl;
    cout << "countv2 = " << countV2 << endl;

    return 0;
}