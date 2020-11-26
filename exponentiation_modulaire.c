#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

int exp_mod(mpz_t g, mpz_t exp, mpz_t mod)
{
  mpz_t result = 1;
  while (exp != 0)
  {
    if (exp & 1)
      result = (result * g) % mod;
    g *= g % mod;
    exp >>= 1 ;
  }
  return result;
}
int main(){
  double a = 10;
  double q =  pow(5,47);
  q = fmod(q,10);
  printf("%d %f\n", exp_mod(5,47,10), q);
}
