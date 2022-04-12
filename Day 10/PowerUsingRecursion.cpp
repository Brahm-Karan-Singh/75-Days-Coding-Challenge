/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int getPower(int num, int power){
    // base case
    if(power == 0)
        return 1;
    // recursive relation
    if(power%2 == 0)
        return getPower(num,power/2)*getPower(num,power/2);
    else
        return num * getPower(num,power/2)*getPower(num,power/2);
}

int main()
{
    int num , p;
    cin>>num>>p;
    int ans = getPower(num , p);
    cout<<"Your answer is "<<ans;
    return 0;
}
