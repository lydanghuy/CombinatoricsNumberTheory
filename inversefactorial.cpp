#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>

#include<cmath>
#include<string>
#include<cstdlib>
//#include<cstdint>
using namespace std;

int main()
{
    string input = "";

    cin >> input;

    const unsigned long long numDigits = input.size();

    if(numDigits < 10)
    {
        unsigned long long i = 1;
        unsigned long long ans = 1;

        while(true)
        {
            ans *= i;

            if(ans == stoi(input))
            {
                cout << i;
                break;
            }

            i++;
        }
    }
    else
    {
        unsigned long long  i = 1;
        double ans = 1;

        while(true)
        {
            ans += log10(i);

            if(floor(ans) == numDigits)
            {
                cout << i;
                break;
            }

            i++;
        }
    }

    return 0;
}
