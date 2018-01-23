/**
 * Declaring Includes
 */
 
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

/**
 * Declaring Constants
 */

const int MAX_START = 50;   // maximum starting number

/***** Complete this program. *****/

/**
 * Declaring the Functions
 */
 
void do_prime_spiral(const int n, const int start);
void make_spiral(vector<vector<int> >& spiral_matrix, int n , int start);
void print_spiral(vector<vector<int> >& spiral_matrix, int n, int start);
bool check_prime(vector<int>& prime_number, int value);
void get_prime(vector<int>& prime_number, int n, int start);

/**
 * The main: Generate and print prime spirals of various sizes.
 */
int main()
{
   do_prime_spiral(5, 1);
   do_prime_spiral(25, 11);
   do_prime_spiral(35, 0);
   do_prime_spiral(50, 31);
   do_prime_spiral(101, 41);
}

/**
 *  Function to create a prime spiral
 */

void do_prime_spiral(const int n, const int start)
{
    vector<vector <int> > spiral_matrix;
    
    // Initializing the vector spiral matrix
    vector<int>temp;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
          temp.push_back(0);  
        }
        spiral_matrix.push_back(temp);      // Inserting the 1-D vector in the spiral matrix
    }

  // Check if the start value of the spiral is within 1 and 50 (inclusive)

    if (start > 0 && start <= 50)
    
    
    {
        if(n % 2 == 0)         // Check if the size of spiral is odd or even
        {
            cout << "Prime spiral of size " << n << " starting at " << start << endl;
              
            // Printing the error message if the size given is odd
              
            cout << "***** Error: Size " << n << " must be odd." << endl << endl;
        }
        else if(n % 2 != 0)
        {
            make_spiral(spiral_matrix, n, start);      // Calling the function to make the spiral
            print_spiral(spiral_matrix, n, start);            // Calling the function to print the spiral
        }
    }
   else
   {
      cout << "Prime spiral of size " << n << " starting at " << start << endl;
      cout << "***** Error: Starting value 0 < 1 or > 50" << endl << endl;   
   }

}

/**
 *  Function to create a spiral
 */

void make_spiral(vector<vector<int> >& spiral_matrix, int n , int start)
{
    spiral_matrix.resize(n);
    cout << "Prime spiral of size " << n << " starting at " << start << endl;
    
    int value, side = n, row=n-1, col=n-1;
 
    value = n*n + (start-1);        // Adding the start value to give the appropriate value according to it
   
   // Condition applied so that the values in the matrix are greater than or equal to the start value
   while(value>=start)                 
   {
     for(int j=0; j<side; j++)      // Loop to print out the values in left direction
     {
         spiral_matrix[row][col] = value;
         col = col - 1;
         value = value - 1;
         
     }
     row = row - 1;
     col = col + 1;
     if(value>=start)
     {
         for(int j=0; j<side-1; j++)      // Loop to print out the values in upward direction
         {
            spiral_matrix[row][col] = value;
            row = row - 1;
            value = value - 1;
             
         }
         row = row + 1;
         col = col + 1;
     }
     if(value>=start)
     {
         for(int j=0; j<side-1; j++)      // Loop to print out the values in right direction
         {
            spiral_matrix[row][col] = value;
            col = col + 1;
            value = value - 1;
         }
         row = row + 1;
         col = col - 1;
     }
     if(value>=start)
     {
         for(int j=0; j<side-2; j++)      // Loop to print out the values in downward direction
         {
            spiral_matrix[row][col] = value;
            row = row + 1;
            value = value - 1;
         }
         col = col - 1;
         row = row - 1;
         side=side-2;
     }
   }
}

/**
 *  Function to print the prime spiral
 */

void print_spiral(vector<vector<int> >& spiral_matrix, int n, int start)
{
   int x = n*n + (start-1);
   vector<int> prime_number(x);
   get_prime(prime_number, n, start);
   cout << endl;
   int value = 0;
   bool prime;
   spiral_matrix.resize(n);
   for(int i=0; i<n; i++)
   {
     for(int j=0; j<n; j++)
     {
         // Printing out the values of the matrix
         
         value = spiral_matrix[i][j];
         prime = check_prime(prime_number, value);
         if (prime == true)
         {
             cout<< "#";
         }
         else
         {
             cout<< ".";
         }
     }
     cout << endl;
   }
    cout << endl;
}


void get_prime(vector<int>& prime_number, int n, int start)
{
   int i, k, l, counter = 0;
   int value = n*n + (start-1);
   bool prime_array[value];
   for(i = 2; i < value; i++)
   {
      prime_array[i] = true;   // Initializing all the values in the boolean array to true
   }
   
   k = 2;
   
   while (k*k < value)   // Looping till the value is less than the square root of MAX_NUMBER
   {
      if (prime_array[k] == true)
      { 
        for(int j = k*k; j <= value; j = j+k)
        {
            prime_array[j] = false;    // Setting all the multiples od a prime number to false
        }
      }
      k = k + 1;
   }
   
   for (l = 2; l < value; l++)
   {
      if(prime_array[l] == true)
      {
         // Setting the value in the vector created for prime numbers if the number found is a prime number
        prime_number[counter] = l ;    
        counter = counter + 1;
      }
   }
}


/**
 *  Function to check if the number is prime or not
 */

bool check_prime(vector<int>& prime_number, int value)
{
   if (value == 1)
   {
      return false;
   }
   else
   {
      for(int i = 0; i <= value; i++)
      {
         if(value == prime_number[i])
         {
            return true;
         }
      }
      return false;
   }
}