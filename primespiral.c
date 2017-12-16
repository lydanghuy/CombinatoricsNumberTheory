#include <stdio.h>
#include <math.h>


int prime(int a) {
    int i;
    if (a == 1) return -2;
    for (i = 2; i <= sqrt(a); i++) {
        if (a%i == 0) return -2;
    }
    return -1;
}

int main() {
        int a[100][100],b[100][100];
        int size = 100;
        int i, j, k, l, count=0;
        int x2, y2, move;
        int x=0;
        int y=0;

        while(scanf("%d %d", &x2, &y2)!=EOF){
        int d = 0; // current direction; 0=RIGHT, 1=DOWN, 2=LEFT, 3=UP
        int c = 1; // counter
        x = (int)size/2;
        y = (int)size/2;
        int s = 1; // chain size
        if (size%2 == 0) { y--; }
        for (k=1; k<=(size-1); k++) //set up array
        {
            for (j=0; j<(k<(size-1)?2:3); j++)
            {
                for (i=0; i<s; i++)
                {
                    a[x][y] = prime(c);
                    //a[x][y]= c;
                    b[x][y] = c;
                    c++;

                    switch (d)
                    {
                        case 0: y = y + 1; break;
                        case 3: x = x + 1; break;
                        case 2: y = y - 1; break;
                        case 1: x = x - 1; break;
                    }
                }
                d = (d+1)%4;
            }
            s = s + 1;
        }
        a[x][y] = prime(c);
        //a[x][y] = c;
        b[x][y] = c;

        count++;
        for (i = 0; i<size; i++) // start searching
            for (j = 0; j<size; j++) 
                if(x2==b[i][j]){
                    a[i][j]=0;
                    goto NEXT;
                }
NEXT:for(move=0;move<200;move++)    
        for(i=0;i<size;i++)
            for(j=0;j<size;j++)
                if(a[i][j]==move)
                    for(k=0;k<size;k++)
                        for(l=0;l<size;l++)
                            if((abs(k-i)+abs(l-j)==1)&&(a[k][l]==-2))
                                a[k][l]=move+1;

        for (i = 0; i<size; i++) 
            for (j = 0; j<size; j++)
                if(y2==b[i][j]){
                    if(a[i][j]==-2) printf("Case %d: impossible\n", count);
                    else printf("Case %d: %d\n", count, a[i][j]);
                }
    }
    return 0;
}