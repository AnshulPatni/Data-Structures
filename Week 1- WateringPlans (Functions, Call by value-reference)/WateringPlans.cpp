/***** #includes here. *****/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

/***** Define constants here. *****/

const int UNITS_PER_CAN = 3;
const string INPUT_FILE_NAME = "counts.txt";

/***** Declare functions here. *****/

void initialization(int&, int&, int&, int&, int&, int&);
void print_lines_above();
void print_lines_below();
void plan_near(int, int&, int&, int&);
void plan_far(int, int&, int&, int&, int);
void compare_both_plans(int, int);

/**
 * The main. For each count of plants, simulate Plan Near and Plan Far,
 * and decide which plan was better.
 */
 
int main()
{
    /***** Complete this main. *****/
    
   int plant_count;        //count of plants
   int cum_steps_near = 0, water_amt_near, cum_stepunits_near = 0;     //Variables for Plan Near
   int cum_steps_far = 0, water_amt_far, cum_stepunits_far;         //Variables for Plan Far
   
   ifstream input;
   input.open(INPUT_FILE_NAME);
   if (input.fail())
   {
       cout << "Failed to open " << INPUT_FILE_NAME << endl;
       return -1;
   }

    // Loop once for each number of plants read from the input file.
    
    // During each loop, simulate Plan Near and Plan Far.
    
    
    do
    {
        // Initilization of all the near and far plan Variables
        
        initialization(cum_steps_near, water_amt_near, cum_stepunits_near, cum_steps_far, water_amt_far, cum_stepunits_far);
    
        input >> plant_count;
        
        if (plant_count <= 0)               // Stop when the number of plants is 0 or less.
        {
            return 0;
        }
    
        // Plan Near
        if (plant_count > 0)
        {
           print_lines_above();
           
           cout << " Plan Near with " << plant_count << " plants" << endl;
           
           print_lines_below();
           
           
           plan_near(plant_count, cum_steps_near, water_amt_near, cum_stepunits_near);      //Function to get the step-wise iterations of the Plan Near
           
           cout << endl                         // Print out the results of plan near for given number of plants
                << "Plan Near: Total steps = "          
                << cum_steps_near 
                << ", total step-units = " 
                << cum_stepunits_near 
                << endl;      
           
           /*** Complete the code for Plan Near. ***/
   
           // Plan Far
           
           print_lines_above();
           
           cout << " Plan Far with " << plant_count << " plants" << endl;
           
           print_lines_below();
           
           /*** Complete the code for Plan Far. ***/
           int rem = plant_count % 3;
           
           plan_far(plant_count, cum_steps_far, water_amt_far, cum_stepunits_far, rem);             //Function to get the step-wise iterations of the Plan Far
           
           cout << endl                         // Print out the results of plan far for given number of plants 
                << "Plan Far: Total steps = " 
                << cum_steps_far 
                << ", total step-units = " 
                << cum_stepunits_far 
                << endl;
   
           // Which plan is better? Better means fewer step-units.
           
           cout << endl;
           cout << "*** With " << plant_count << " plants, ";
           
           compare_both_plans(cum_stepunits_near, cum_stepunits_far);       // Function to compare the cumulative step-units taken for Plan near and Plan Far
           
           /*** Complete the code to determine the better plan. ***/
       }
       else if (plant_count <= 0)           //Stop if number of plants is less than or equal to zero
       {
          break;
       }
    } while (plant_count > 0);              // Continue till the number of plants is greater than zero


    return 0;
}

/***** Define functions here. *****/

void initialization(int& cum_steps_near1, int& water_amt_near1, int& cum_stepunits_near1, int& cum_steps_far1, int& water_amt_far1, int& cum_stepunits_far1)
{
    cum_steps_near1 = 0;
    water_amt_near1 = 0;
    cum_stepunits_near1 = 0;      
    cum_steps_far1 = 0;
    water_amt_far1 = 0;
    cum_stepunits_far1 = 0;
}

void print_lines_above()
{
    cout << endl;
    cout << "==========================" << endl;
}

void print_lines_below()
{
   cout << "==========================" << endl;
   cout << endl;
   cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
   cout << "---------  ----------  ----------  ---------------" << endl; 
}

void plan_near(int plant_count, int& cum_steps_near1, int& water_amt_near1, int& cum_stepunits_near1)
{
    for(int i=1; i <= plant_count; i++)
   {
       if (i % UNITS_PER_CAN == 0)
       {
           cum_steps_near1 = cum_steps_near1 + 1;
           water_amt_near1 = UNITS_PER_CAN-2;
           cum_stepunits_near1 = cum_stepunits_near1 + 1;
       }
       else if (i % UNITS_PER_CAN == 1)
       {
           cum_steps_near1 = cum_steps_near1 + i;
           water_amt_near1 = UNITS_PER_CAN;
           cum_stepunits_near1 = water_amt_near1 * i + cum_stepunits_near1;
       }
       else if (i % UNITS_PER_CAN == 2)
       {
           cum_steps_near1 = cum_steps_near1 + 1;
           water_amt_near1 = UNITS_PER_CAN - 1;
           cum_stepunits_near1 = cum_stepunits_near1 + 2;
       }
       
       //Printing the iteration for Plan Near
       cout << "Plant " << i << "      " << "    " << cum_steps_near1 << "     ";
       cout << "     " << water_amt_near1 << "     " << "         " << cum_stepunits_near1 << "          " << endl;
       
       //Printing for the step taken reaching the Faucet
       if (i % 3 == 0 || i == plant_count)
       {
           cum_steps_near1 = cum_steps_near1 + i;
           if(i != plant_count)
           {
               water_amt_near1 = 0;
           }
           else if (i == plant_count)
           {
               water_amt_near1 = water_amt_near1 - 1;
               cum_stepunits_near1 = cum_stepunits_near1 + (i*water_amt_near1);
           }
           cout << "FAUCET       " << "    " << cum_steps_near1 << "      ";
           cout << "    " << water_amt_near1 << "     " << "         " << cum_stepunits_near1 << "          " << endl;
       }
       
   }
}

void plan_far(int plant_count, int& cum_steps_far1, int& water_amt_far1, int& cum_stepunits_far1, int rem)
{
    for(int i = plant_count; i > 0; i--)
   {
       if (i == plant_count)    //For step 1 in the Plan Far
       {
           cum_steps_far1 = i;
           water_amt_far1 = UNITS_PER_CAN;
           cum_stepunits_far1 = cum_steps_far1 * water_amt_far1;
           cout << "Plant " << i << "      " << "    " << cum_steps_far1 << "     ";
           cout << "     " << water_amt_far1 << "     " << "         " << cum_stepunits_far1 << "          " << endl;
       }
       else                    //For preceding steps after 1st step in the Plan Far
       {
           if (rem == 0)
           {
               if (i % 3 == 0)
               {
                   cum_steps_far1 = cum_steps_far1 + i;
                   water_amt_far1 = UNITS_PER_CAN;
                   cum_stepunits_far1 = cum_stepunits_far1 + (i*water_amt_far1);
               }
               else if (i % 3 == 2)
               {
                   cum_steps_far1 = cum_steps_far1 + 1;
                   water_amt_far1 = UNITS_PER_CAN - 1;
                   cum_stepunits_far1 = cum_stepunits_far1 + 2;
               }
               else if (i % 3 == 1)
               {
                   cum_steps_far1 = cum_steps_far1 + 1;
                   water_amt_far1 = UNITS_PER_CAN - 2;
                   cum_stepunits_far1 = cum_stepunits_far1 + 1;
               }
               
               cout << "Plant " << i << "      " << "    " << cum_steps_far1 << "     ";
               cout << "     " << water_amt_far1 << "     " << "         " << cum_stepunits_far1 << "          " << endl;
               
               //Printing for the step taken reaching the Faucet        
               
               if (i % 3 == 1 || i == 1)
               {
                   cum_steps_far1 = cum_steps_far1 + i;
                   water_amt_far1 = UNITS_PER_CAN - 3;
                   cout << "FAUCET       " << "    " << cum_steps_far1 << "      ";
                   cout << "    " << water_amt_far1 << "     " << "         " << cum_stepunits_far1 << "          " << endl;
               }
               
           }
           else if (rem == 2)
           {
               if (i % 3 == 0)
               {
                   cum_steps_far1 = cum_steps_far1 + 1;
                   water_amt_far1 = UNITS_PER_CAN - 2;
                   cum_stepunits_far1 = cum_stepunits_far1 + 1;
               }
               else if (i % 3 == 2)
               {
                   cum_steps_far1 = cum_steps_far1 + i;
                   water_amt_far1 = UNITS_PER_CAN;
                   cum_stepunits_far1 = cum_stepunits_far1 + (i*water_amt_far1);
               }
               else if (i % 3 == 1)
               {
                   cum_steps_far1 = cum_steps_far1 + 1;
                   water_amt_far1 = UNITS_PER_CAN - 1;
                   cum_stepunits_far1 = cum_stepunits_far1 + 2;
               }
               
               cout << "Plant " << i << "      " << "    " << cum_steps_far1 << "     ";
               cout << "     " << water_amt_far1 << "     " << "         " << cum_stepunits_far1 << "          " << endl;
                       
               if (i % 3 == 0 || i == 1)
               {
                   cum_steps_far1 = cum_steps_far1 + i;
                   if (i % 3 == 0)
                   {
                       water_amt_far1 = UNITS_PER_CAN - 3;
                   }
                   else if (i == 1)
                   {
                       water_amt_far1 = UNITS_PER_CAN - 2;
                       cum_stepunits_far1 = cum_stepunits_far1 + 1;
                   }
                   
                   //Printing for the step taken reaching the Faucet
                   
                   cout << "FAUCET       " << "    " << cum_steps_far1 << "      ";
                   cout << "    " << water_amt_far1 << "     " << "         " << cum_stepunits_far1 << "          " << endl;
               }
               
           }
           else if (rem == 1)
           {
               if (i % 3 == 0)
               {
                   cum_steps_far1 = cum_steps_far1 + 1;
                   water_amt_far1 = UNITS_PER_CAN - 1;
                   cum_stepunits_far1 = cum_stepunits_far1 + 2;
               }
               else if (i % 3 == 2)
               {
                   cum_steps_far1 = cum_steps_far1 + 1;
                   water_amt_far1 = UNITS_PER_CAN - 2;
                   cum_stepunits_far1 = cum_stepunits_far1 + 1;
               }
               else if (i % 3 == 1)
               {
                   cum_steps_far1 = cum_steps_far1 + i;
                   water_amt_far1 = UNITS_PER_CAN;
                   cum_stepunits_far1 = cum_stepunits_far1 + (i*water_amt_far1);
               }
               cout << "Plant " << i << "      " << "    " << cum_steps_far1 << "     ";
               cout << "     " << water_amt_far1 << "     " << "         " << cum_stepunits_far1 << "          " << endl;
                       
               if (i % 3 == 2 || i == 1)
               {
                   cum_steps_far1 = cum_steps_far1 + i;
                   if (i % 3 == 2)
                   {
                       water_amt_far1 = UNITS_PER_CAN - 3;
                   }
                   else if (i == 1)
                   {
                       water_amt_far1 = UNITS_PER_CAN - 1;
                       cum_stepunits_far1 = cum_stepunits_far1 + 2;
                   }
                   cout << "FAUCET       " << "    " << cum_steps_far1 << "      ";
                   cout << "    " << water_amt_far1 << "     " << "         " << cum_stepunits_far1 << "          " << endl;
               }
               
           }
           
       }
       
   }
}


void compare_both_plans(int cum_stepunits_near, int cum_stepunits_far)
{
    if(cum_stepunits_near > cum_stepunits_far)
   {
       cout << "Plan Far is better with " << cum_stepunits_near-cum_stepunits_far << " fewer step-units." << endl;
   }
   else if (cum_stepunits_far > cum_stepunits_near)
   {
       cout << "Plan Near is better with " << cum_stepunits_far-cum_stepunits_near << " fewer step-units." << endl;
   }
   else if (cum_stepunits_far = cum_stepunits_near)
   {
       cout << "Plan Near and Plan Far gives out same cumulative steps-units as " << cum_stepunits_near << endl;
   }
}