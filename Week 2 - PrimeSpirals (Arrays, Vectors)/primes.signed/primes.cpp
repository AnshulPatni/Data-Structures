/**
 * Declaring Includes
 */
 
#include <iostream>
using namespace std;

/**
 * Declaring Constants
 */

const int MAX_NUMBER = 1000;  // maximum possible prime number
const int ROW_SIZE   = 20;    // row size for printing

/**
 * Declaring Functions
 */

void compute_primes(bool prime_array[]);
void print_primes(bool prime_array[]);

/***** Complete this program. *****/

/**
 * The main: Compute and print the prime numbers up to MAX_NUMBER.
 */
int main()
{
   bool prime_array[MAX_NUMBER];
   int n, i, k, l;
   
   compute_primes(prime_array);  // Calling the function to compute prime numbers
   
   print_primes(prime_array);    // Calling the function to print the prime numbers
   
   cout << endl << endl;
   cout << "Done!";
}

/**
 * Defining Functions
 */

// Funtion to compute all the prime number till the MAX_NUMBER

void compute_primes(bool prime_array[MAX_NUMBER])
{
   int i, k;
   for(i = 2; i < MAX_NUMBER; i++)
   {
      prime_array[i] = true;   // Initializing all the values in the boolean array to true
   }
   
   k = 2;
   
   while (k*k < MAX_NUMBER)   // Looping till the value is less than the square root of MAX_NUMBER
   {
      if (prime_array[k] == 1)
      { 
        for(int j = k*k; j <= MAX_NUMBER; j = j+k)
        {
            prime_array[j] = false;    // Setting all the multiples od a prime number to false
        }
      }
      k = k + 1;
   }
}

// Funtion to print all the prime number till the MAX_NUMBER

void print_primes(bool prime_array[MAX_NUMBER])
{
    int counter = 1;
    for(int l = 2; l < MAX_NUMBER; l++)
    {
        if(prime_array[l] == true)     // Printing only the true values which indicate that the number is prime
        {
            // Printing in a proper format
            if (l < 10)
            {
               cout << "  " << l << " ";
            }
            else if (l > 10 && l < 100)
            {
               cout << " " << l << " ";
            }
            else if (l > 100)
            {
               cout << l << " ";
            }
            counter = counter + 1;
        }
        if(counter > ROW_SIZE)   // Changing the row after the max row size is achieved
        {
            cout << endl;
            counter = 1;
        }
   }
}
