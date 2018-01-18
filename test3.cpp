//Counting even decimal value substrings in a binary string
/*
* Example: 101
* Possible substrings:        1
                            0 1
                          1 0 1
                            0
                          1 0
                        1
* Number of substring with substr[0] == str[i] is : N - i
* Even number: substr[0] == '0'
************************************************************/
#include <iostream>
#include <string>
using namespace std;
int countEvenNumber (string str, int N)
{
   int count = 0;
   for (int i = 0; i < N; i++)
   {
      if(str[i] == '0')
      {
         count += N-i;
      }
   }
   return count;
}  

int main()
{
   string str;
   cout << "Input the string:" << endl; 
   cin >> str;

   int N = str.length();
   int count = countEvenNumber(str,N);
   cout << "Result:" << count << endl;
   return 0;
}
