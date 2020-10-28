#include <bits/stdc++.h>

void printVector(std::vector<int> v) 
{ 
    // lambda expression to print vector 
    for_each(v.begin(), v.end(), [](int i) 
    { 
        std::cout << i << " "; 
    }); 
    std::cout << std::endl; 
} 


int main(int argc, char const *argv[])
{
    /* code */
    std::function<void()>ifn = [](){
        std::cout<<"hello"<<std::endl;
    };
    ifn();

     std::vector<int> v {4, 1, 3, 5, 2, 3, 1, 7}; 
  
    printVector(v); 


    std::vector<int>:: iterator p = find_if(v.begin(), v.end(), [](int i) 
    { 
        return i > 4; 
    }); 
    std::cout << "First number greater than 4 is : " << *p << std::endl; 
  
  
    // function to sort vector, lambda expression is for sorting in 
    // non-decreasing order Compiler can make out return type as 
    // bool, but shown here just for explanation 
    sort(v.begin(), v.end(), [](const int& a, const int& b) -> bool
    { 
        return a > b; 
    }); 
  
    printVector(v); 
    return 0;
}
