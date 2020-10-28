#include <bits/stdc++.h>

typedef unsigned long long ull;
ull evenSum =0;
ull oddSum = 0;


void getEvenSum(){
    for(int i =0;i<1900000000;i++){
        evenSum+=i;
    }
}


void getOddSum(){
    for(int i =0;i<1800000000;i++){
        oddSum+=i;
    }
}




int main(){
    std::thread t1(getEvenSum);
    std::thread t2(getOddSum);

    t1.join();
    t2.join();

    std::cout<<evenSum<<std::endl;
    std::cout<<oddSum<<std::endl;

    

    return 0;

}
