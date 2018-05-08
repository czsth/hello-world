//给定维度，给出立体图的边
//离散数学（本科教学版）：P284（图论相关）

#include <iostream>
#include <bitset>
using namespace std;

const int DIM = 10;
bool isLine(int a);      //while a has only one high digit, return true
void printLine(int a, int b);

int main(int argc, char const *argv[]) {

    for(int i = 0; i < (1 << DIM); i++){
        for(int j = i; j < (1 << DIM); j++){
            if(isLine(i ^ j)){
                printLine(i, j);
                putchar('\n');
            }
        }
    }
    return 0;
}

bool isLine(int a){
    bool rtn = true;
    if(a == 0){
        rtn = false;
    }
    else{
        while(!(a & 1)){
            a >>= 1;
        }
        if((a >> 1) != 0){
            rtn = false;
        }
    }
    return rtn;
}

void printLine(int a, int b){
    cout << "(" << bitset<DIM>(a)
    << "," << bitset<DIM>(b) << ")";
}
