#include <vector>
#include <math.h>
#include "PrimeDivisor.hpp"

// typedef unsigned long long int ullInt;

using namespace std;

PrimeDivisor::PrimeDivisor() : prime(0), multiplicity(0)
{}

PrimeDivisor::PrimeDivisor(ullInt prime, int multiplicity) : prime(prime) , multiplicity(multiplicity)
{}


void PrimeDivisor::setPrime(ullInt prime)
{
  this->prime = prime;
}

void PrimeDivisor::setMulti(int multiplicity)
{
  this->multiplicity = multiplicity;
}

ullInt PrimeDivisor::getPrime() const
{
  return this->prime;
}

int PrimeDivisor::getMulti() const
{
  return this->multiplicity;
}

vector<PrimeDivisor> PrimeDivisor::prime_div(ullInt num)
{
  vector<PrimeDivisor> primdiv;
  ullInt racine;
  PrimeDivisor first,temp;
  int j;
  
  first.setPrime(0);
  first.setMulti(0);
  primdiv.push_back(first);

  racine = floor(sqrt(num))+1;
  //cout<<"racine : "<< racine <<endl;

  for(ullInt i=2;i<=racine;i++)
    {
      while(num%i==0)
	{
	  if(i!=primdiv.back().getPrime())
	    { 
	      j=1;
	      if(primdiv.back().getPrime()==0)
		{
		  primdiv.back().setPrime(i);
		  primdiv.back().setMulti(j);
		}
	      else
		{
		  temp.setPrime(i);
		  temp.setMulti(j);
		  primdiv.push_back(temp);
		}
	    }
	  else
	    {
	      j++;
	      primdiv.back().setMulti(j);
	    }
	  num=num/i;
	}
    }
  
  if(num!=1) 
    {
      if(primdiv.back().getPrime()==0) 
	{
	  primdiv.back().setPrime(num);
	  primdiv.back().setMulti(1);
	}
      else
	{
	  temp.setPrime(num);
	  temp.setMulti(1);
	  primdiv.push_back(temp);
	}
    }
  return primdiv;
}


vector<ullInt> PrimeDivisor::all_div(vector<PrimeDivisor> prime_gen)
{
  vector<ullInt> divisors_temp, divisors_all, divisors_order;
  int mul,a,div_size;
  ullInt p,mult,c;

  mul=prime_gen[0].getMulti();
  for(int j=0;j<=mul;j++)
    {
      a= pow(prime_gen[0].getPrime(),j);
      //cout<<a<<endl;
      divisors_temp.push_back(a);
      divisors_all.push_back(a);
    }
  
  div_size=divisors_temp.size();

  for(ullInt i=1 ; i<prime_gen.size();i++)
    {
      
      mul=prime_gen[i].getMulti();
      p= prime_gen[i].getPrime();
      //cout<<mul<<","<<p<<endl;
      for (int j =1 ; j <=mul; j++) 
	{
	  mult = pow(p,j);
	  for(int k=0; k<div_size;k++)
	    { 
	      //cout<<"div_size: "<<div_size<<endl;
	      c=mult*divisors_temp[k];
	      divisors_all.push_back(c);
	      // cout<<"last add: "<<divisors_all.back()<<endl;
	    }
	}
      
      div_size=divisors_all.size();
      //cout<<"size: "<<div_size<<endl;
      divisors_temp=divisors_all;
    }
  
  return(divisors_all);

}


vector<unsigned int long long> PrimeDivisor::vec_inorder(vector<unsigned int long long> vec_to_order)
{

  vector<ullInt> vec_in_order;
  vector<ullInt>::iterator it;
  ullInt order;
  int tempsize;

  for(ullInt i=0; i<vec_to_order.size();i++)
    {
     order = vec_to_order[i];
      if(vec_in_order.empty())
	{
	  vec_in_order.push_back(order);
	}
      else
	{
	  if(vec_in_order[0]>order)
	    {
	      it=vec_in_order.begin();
	      vec_in_order.insert(it,order);
	    }
	  else if(vec_in_order.back()<order)
	    {
	      vec_in_order.push_back(order);
	    }
	  else
	    {
	      tempsize=vec_in_order.size();
	      for(int j=0; j<tempsize;j++)
		{
		  if(order>vec_in_order[j] && order<vec_in_order[j+1])
		    {
		      it=vec_in_order.begin()+j;
		      vec_in_order.insert(it+1,order);
		    }
		}
	    }
	}
    }

  return(vec_in_order);
}



