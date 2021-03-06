#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>

#include "PrimeDivisor.hpp"

//typedef unsigned long long int ullInt;

using namespace std;

int main()
{
  ullInt n;
  vector<PrimeDivisor> prime;
  vector<ullInt> alldiv, divsort;
  clock_t t;
  PrimeDivisor comp;

  cout<<"type a number greater than 0:"<<endl;
  cin>>n;
  if(n<=0)
    {
      cout<<"n must be greater than 0"<<endl;
    }
  else
    {
      cout<<n<<endl;
    }

  t = clock();
    {
      prime=comp.prime_div(n);
      ullInt prod =1;
      int multi;
      for(ullInt i=0; i<prime.size();i++)
	{
	  printf("*************************************\n");
	  printf("prime[%lld] = %lld\n",i,prime[i].getPrime());
	  printf("multiplicity[%lld] = %d\n",i,prime[i].getMulti());
	  multi = prime[i].getMulti();
	  prod=prod*(multi+1);
	  }
      
      alldiv=comp.all_div(prime);
      divsort=comp.vec_inorder(alldiv);
      
      ullInt count=0;
      for(ullInt i=0; i<divsort.size();i++)
       	{
       	  cout<<divsort[i]<<endl;
	  count=count+divsort[i];
       	}

      cout<<"prod: "<<prod<<endl;
      cout<<"number of divisors: "<<alldiv.size()<<endl;
      cout<<"sum of divisors = " <<count<<endl;
      cout<<"sum of proper divisors = "<<count-n<<endl;
      
      if(prod!=alldiv.size()) 
	{
	  cout<<"Incorrect number of divisors"<<endl;
	}  

      
    }
      
    t = clock()- t;
    printf ("It took me %ld clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    return 0;
}
