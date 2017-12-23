#include <stdio.h>
#include <assert.h>

typedef unsigned long long ULL;

ULL cnt(unsigned m) {
  ULL sum = 1;
  unsigned mleft = m, mright = 0, pow10 = 1;
  int i;
  for (i=0;mleft;i++) {
    assert (mleft*pow10+mright == m);
    int digit = mleft%10;
    mleft /= 10;
    sum += digit ? mleft*pow10 : (mleft-1)*pow10+mright+1;
    mright = digit*pow10+mright;
    pow10 *=10;
  }
  return sum;
}

int count(unsigned m) {
  int sum = 0;
  do { if (!(m%10)) sum++;
    m /= 10;
  } while (m);
  return sum;
}

int main () {

  long long m,n;

  while (1) {
    scanf("%lld%lld", &m,&n);
    if (m<0) break;
    assert(m<=n);
    ULL mc, nc;
    mc = cnt(m);
    nc = cnt(n);
    printf("%llu\n",nc-mc+count(m));
  }
}
