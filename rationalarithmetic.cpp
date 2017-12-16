#include <iostream>
using namespace std;

int main(void);
long gcd(long a, long b){
    return b == 0? a: gcd(b, a%b);
}

int main(void){
    long x1, y1, x2, y2;
    long x, y;
    char op;
    int t, i;
    
    cin >> t;   
    for (i=0; i<t; i++){
        cin >> x1 >> y1 >> op >> x2 >> y2;
        if (op=='+'){
            x = x1*y2 + x2*y1;
            y = y1*y2;
        } else
        if (op=='-'){
            x = x1*y2 + (-x2)*y1;
            y = y1*y2;
        } else
        if (op=='*'){
            x = x1*x2;
            y = y1*y2;
        } else 
        if (op=='/'){
            x = x1*y2;
            y = y1*x2;
        }
        
            x1 = gcd(x, y);
            x = x/x1;
            y = y/x1;
        if (x>0&&y<0){
            x = -x;
            y = -y;
        }
        cout << x << " / " << y << endl;
    }
}