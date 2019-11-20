#include "src/Animal.h"
#include "src/Herb.h"
#include "tests/test_EVOLUTION.h"
int main()
{
    std::cout<<"Choices:\n1-Test class Animals\n2-Test class Herb\n0-Exit";
    int k;
    while(k > 0){
        std::cout<<"\nEnter choice(0,1 or 2):";
        std::cin>>k;
        if(k==1) test_Animal();
        if(k==2) test_Herb();
    }
    return 0;
}