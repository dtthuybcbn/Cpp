/* A product array puzzle */
#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

int main()
{
   int N; 
   cout << "Input the size of array:" << endl;
   cin >> N;
   int *arr = (int *)malloc(sizeof(int)*N);

   for (int i = 0; i < N; i++)
   {
      cout << "Input the element[" << i << "]:"<< endl;
      cin >> arr[i];
   } 
   cout << "Input array:" << endl;
   for (int i =0; i < N; i++)
   {
      cout << arr[i]<< "  ";
   
   }
   cout << endl;
   int *prod = (int *)malloc(sizeof(int)*N);
   int temp =1;
   std::memset(prod, 1, N);

   for (int i = 0; i < N; i++)
   {
      prod[i] = temp;
      temp *= arr[i];
   }
   temp = 1;
   for (int i = N-1; i >= 0; i--)
   {
      prod[i]*= temp;
      temp *= arr[i];
   }
   cout <<"Output array:" << endl;
   for (int i =0;i < N; i++)
      cout << prod[i] << "    ";
   cout << endl;
   return 0;
}

