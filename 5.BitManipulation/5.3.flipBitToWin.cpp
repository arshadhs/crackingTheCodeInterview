// Flip Bit to Win: You have an integer and you can flip exactly one bit from a O to a 1. Write code to
// find the length of the longest sequence of 1 s you could create.
// EXAMPLE
// Input:  1775 (or: 11011101111)
// Output: 8
#include<iostream>
#include<bitset>

bool isSet(int num, int pos) {
    return (num & (1 << pos) != 0);
}

template<typename T>
T flipBit(T num) {
    int maxLength = 0;
    int countOnesAndZeros = 0;
    int countOnes = 0;

    while(num) {        
        if (num & 1) {
            countOnes++;
        }
        else {
            countOnesAndZeros = countOnes;
            countOnes = 0;
        }
        maxLength = std::max(countOnes + countOnesAndZeros + 1, maxLength);

        num >>= 1;
    }
        
    return maxLength;
}

int main () {
    for(auto i : {0b11011101111U, 0b110111001111U, 0b1100111001111U, 0U, ~0U}) {
        std::cout << std::endl << std::bitset<32>(i) << " Count: " << flipBit(i);
    }
}