#include <iostream>
using namespace std;

int main() {
    // Check the given answer for N=52
    cout << "For expected answer 54, 24, 26:" << endl;
    cout << "Sum: " << (54 + 24 + 26) << " (should be " << (2*52) << ")" << endl;
    cout << "XOR: " << (54 ^ 24 ^ 26) << " (should be 52)" << endl;
    
    // Check our answer for N=52
    cout << "For our answer 16, 26, 62:" << endl;
    cout << "Sum: " << (16 + 26 + 62) << " (should be " << (2*52) << ")" << endl;
    cout << "XOR: " << (16 ^ 26 ^ 62) << " (should be 52)" << endl;
    
    return 0;
}