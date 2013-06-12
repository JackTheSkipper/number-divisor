#ifndef PRIMEDIVISOR_H
#define PRIMEDIVISOR_H

#include <iostream>
#include <vector>

class PrimeDivisor
{
 public:
  //constuctor
  PrimeDivisor();
  PrimeDivisor(long long int prime, int multiplicity);
  
  //access members
  void setPrime(long long int prime);
  void setMulti(int multipliciy);
  long long int getPrime() const;
  int getMulti() const;

  //function
  std::vector<PrimeDivisor> prime_div(unsigned long long int num);
  std::vector<long long int> all_div(std::vector<PrimeDivisor> prime_gen);
  std::vector<long long int> vec_inorder(std::vector<long long int> vec_to_order);

  private:
  long long int prime; 
  int multiplicity;
};

#endif
