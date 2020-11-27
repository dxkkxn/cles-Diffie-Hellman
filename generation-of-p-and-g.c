#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <time.h>
//Prend en paramètre un entier n et génère aléatoirement un nombre premier p de
//n bits ainsi qu’un élément g dans (Z/pZ)\{0, 1, p − 1}.
//Remarque : Comme expliqué plus haut, g devrait être une racine primitive modulo p.
//Pour ce projet, on se contentera d’un élément g différent de 0, 1 et p − 1.

void generation_of_p_and_g(mpz_t p, mpz_t g, int n)
{
  unsigned long seed;
  mpz_t p_moins1;
  mpz_init(p_moins1);
  gmp_randstate_t r;
  seed = time(NULL);
  gmp_randinit_default(r);
  gmp_randseed_ui(r, seed);
  //Calcul de p
  while (mpz_sizeinbase(p,2) != n)
  {
    mpz_urandomb(p, r, n);
    gmp_printf("1 p = %Zd \n", p);
    mpz_setbit(p, n-1);
    gmp_printf("2 p = %Zd \n", p);
    mpz_nextprime(p, p);
    gmp_printf("3 p = %Zd \n", p);
  }
  //Calcul de g != 0, 1, p-1

  mpz_sub_ui(p_moins1, p, 2); //p - 1
  do{
    mpz_urandomm(g, r, p_moins1);
  }while(mpz_cmp_d(g, 0) == 0 || mpz_cmp_d(g, 1) == 0);
  mpz_clear(p_moins1);
}


// Simulation le protocole d’échange de clés Diffie-Hellman entre un nombre m
// d’entités. Par exemple : Entité_1 envoie X à Entité_2.
void echange_des_cles(int m, mpz_t p, mpz_t g)
{
  int tab[m];
  for(int i = 1; i <= m; i++)
  {
    tab[i] = i;

  }


}



int main(){
  mpz_t premier, gener;
  mpz_inits(premier, gener, NULL);
  generation_of_p_and_g(premier, gener, 8);
  // gmp_printf("premier = %Zd\ngener = %Zd \n", premier, gener);
  echange_des_cles(3, premier, gener);
}
