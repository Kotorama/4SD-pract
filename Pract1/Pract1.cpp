#include <iostream>  
#include <cmath> 
using namespace std 
int main() { 
 double hx = 0.5, a = 5.3, y = 1.1, z; 
 for (double x = -3; x <= 3; x += hx) { 
  if (pow(x, 2) + pow(y, 2) <= pow(a, 2)) 
   z = x / (15 * pow(x, 2)); 
  else if (pow(x, 2) + pow(y, 2) > pow(a, 2)) 
   z = pow(x, 2) + exp(x); 
  cout << "z=\t" << z << endl; 
 } 
 return 0; 
}
