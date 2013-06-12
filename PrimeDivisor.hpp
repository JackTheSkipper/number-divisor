#ifndef PRIMEDIVISOR_HPP
#define PRIMEDIVISOR_HPP

#include <iostream>
#include <vector>

typedef unsigned long long int ullInt;

class PrimeDivisor
{
 public:
  //constuctor
  PrimeDivisor();
  PrimeDivisor(ullInt prime, int multiplicity);
  
  //access members
  void setPrime(ullInt prime);
  void setMulti(int multipliciy);
  ullInt getPrime() const;
  int getMulti() const;

  //function
  std::vector<PrimeDivisor> prime_div(ullInt num);
  std::vector<unsigned long long int> all_div(std::vector<PrimeDivisor> prime_gen);
  std::vector<unsigned long long int> vec_inorder(std::vector<unsigned long long int> vec_to_order);

  private:
  ullInt prime; 
  int multiplicity;
};

#endif
