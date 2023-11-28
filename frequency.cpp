//we find the frequency of the Array's elements which given by the user.

#include <iostream>
#include <cstdlib> 
#include <iomanip>
using namespace std;

int main()
{

    const int sizeofArray = 10;
    int array[sizeofArray];
    
    for (int i = 0; i < sizeofArray; i++) {
        cout << "please enter "<<i+1<<". element of array as an integer " << endl;
        cin >> array[i];
    }
   
    for (int i = 0; i < sizeofArray; i++) {
        int frequency = 0;
        for (int j = 0; j < sizeofArray; j++) {
            if (array[j] == array[i]) {
                frequency++;
            }
        }
        cout << array[i] << " used " << frequency << " times" << endl;
    }
    return 0;
}




