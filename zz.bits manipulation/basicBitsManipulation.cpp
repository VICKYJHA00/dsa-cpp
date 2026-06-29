#include<iostream>
using namespace std;


// swap two numbers using bit manipulation
void swap(int &a , int& b){
    a = a^b;
    b = a^b;
    a = a^b;
}

//  check if the bit is set
// left sh(ift method
void checkBitSet(int n , int pos){
    if((n & (1<<pos)) != 0){
        cout<<"Bit is set\n";
    }else{
        cout<<"Bit is not set\n";
    }
}

// right shift method
void checkBitSetRightShift(int n , int pos){
    if((n>>pos) & 1) cout<<"Bit is set\n";
    else cout<<"Bit is not set\n";
}



void setBit(int& n, int pos){
    n = n | (1<<pos);
}

void clearBit(int& n,int pos){
    n = n & ~(1<<pos);
}

void  toggleBit(int& n, int pos){
    n = n ^ (1<<pos);
}

int main(){
    int n = 5; // 0101 in binary
    int pos = 1;
    
    cout << "Original number: " << n << endl;
    checkBitSet(n, pos);
    
    toggleBit(n, pos);
    cout << "After toggling bit " << pos << ": " << n << endl;
    checkBitSet(n, pos);
    
    return 0;
}