/** 
 * Declaring includes 
*/

#include <iostream>
#include <iomanip>
using namespace std;

/** 
 * Declaring constants 
*/

const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number

/***** Complete this program. *****/

/**
 * Writing the function declaration
*/

void do_spiral(const int n, const int start);
void make_spiral(int spiral_matrix[][MAX_SIZE], int n, int start);
void print_sprial(int spiral_matrix[][MAX_SIZE], int n);

/**
 * The main: Generate and print spirals of various sizes.
 */
int main()
{
   do_spiral(1, 1);
   do_spiral(5, 1);
   do_spiral(9, 11);
   do_spiral(12, 13);
   do_spiral(15, 17);
}

/**
 * Giving the function definitions
*/

// Function to create a spiral based on the size and starting number given

void do_spiral(const int n, const int start)
{
    int spiral_matrix[MAX_SIZE][MAX_SIZE];
    
    if(n % 2 == 0)         // Check if the size of spiral is odd or even
    {
        cout << "Spiral of size " << n << " starting at " << start << endl;
        
        // Printing the error message if the size given is odd
        
        cout << "***** Error: Size " << n << " must be odd." << endl << endl;
    }
    else if(n % 2 != 0)
    {
        make_spiral(spiral_matrix, n, start);      // Calling the function to make the spiral
        print_sprial(spiral_matrix, n);            // Calling the function to print the spiral
    }
}

// Function to create a 2-D matrix making a spiral 

void make_spiral(int spiral_matrix[][MAX_SIZE], int n, int start)
{
    cout << "Spiral of size " << n << " starting at " << start << endl << endl;
    
    int value, side = n, row=n-1, col=n-1;
 
    value=n*n + (start-1);              // Adding the start value to give the appropriate value according to it
   
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

// Function to print the 2-D matrix that was created to make the spiral 

void print_sprial(int spiral_matrix[][MAX_SIZE], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            // Printing out the values of the matrix
            
            cout<< setw(4) << spiral_matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}