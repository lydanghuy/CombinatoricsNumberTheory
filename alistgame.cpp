#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int X;
    cin >> X;

    int multiply = 2;
    int points = 0;
    
    while(multiply <= sqrt(X))
    {
    
     
            if(X% multiply == 0)
             {
                X /= multiply;
                points++;
            } 
            else
                multiply++;
        
    }
    
     if (X>1) points++;
     
        cout << points;
    return 0;
}
