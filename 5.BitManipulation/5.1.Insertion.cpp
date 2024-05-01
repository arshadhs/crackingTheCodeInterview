// Insertion: You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method
// to insert M into N such that M starts at bit j and ends at bit i. You can assume that the bits j through
// i have enough space to fit all of M. That is, if M = 10011, you can assume that there are at least 5
// bits between j and i. You would not, for example, have j = 3 and i = 2, because M could not fully
// fit between bit 3 and bit 2.
// EXAMPLE
// Input:  N = 10000000000, M = 10011, i = 2, j = 6
// Output: N = 10001001100

#include<iostream>
#include<bitset>
#include <cstdint>

int32_t insert(int32_t n, int32_t m, const int i, const int j) {
    if ((j-i) <= 0) return n;

    // std::cout << std::endl << std::bitset<32>(((1 << (j+1)) - (1 << i)));
    int reset_n = n & ~((1 << (j+1)) - (1 << i));   // clear bits in n

    m <<= i;    // shift m to left
    int ret = reset_n | m;  // insert the bits
    return ret; 
}

int main () {
    int m = 0b10011;
    int n = 0b10000000000;
    int i = 2;
    int j = 6;

    auto k = insert(n, m, i, j);
    std::cout << std::endl << std::bitset<sizeof(decltype(k))*8>(k);
    return 0;
}