/*
 *****************************************************************
 *** Project #5:  Big statistics                               ***
 *** Program:     statistics                                   ***
 *** Author:      Evan Blosser    (evan.a.bloser-1@ou.edu)     ***
 *** Class:       CS 1313 Computer Programming, Spring 2021    ***
 *** Lab:         Sec 010 Fridays 2:15pm                       ***
 *** Description: This program calculates the arithmetic mean, ***
 ***              geometric mean, root mean square, and the    ***
 ***              harmonic mean of a pair of lists with the    ***
 ***              same size or length.                         ***
 ***                                                           ***
 *****************************************************************
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main()
{ /* main */

  /*
   ******************************
   *** Declaration Subsection ***
   ******************************
   *
   ******************************
   * Named Constants Subsection *
   ******************************
   *
   * zero_sum:               This is the zero value used for 
   *                         setting calculation variables to zero.
   * initial_product:        This sets the value of the geometric mean
   *                         to one at the beginning of the for loop
   *                         for calculations to be accurate.
   * recip_numerator:        This value is the numerator for calculating
   *                         the reciprocal sum.
   * pow_numerator:          This value is the numerator for calcualating
   *                         the power of the geometric mean.
   * min_number_of_elements: This is the minimum size of an array
   *                         and is used for idiot proofing.
   * first_element:           This is the zero value used for
   *                         setting the element counter.
   * program_success_code:   This code is used to exit the program
   *                         after a successful run.
   * program_failure_code:   This code is used in the idiotproofing
   *                         to exit the program if it fails.
   *
   */

   const float zero_sum             =  0.0;
   const float initial_product      =  1.0;
   const float recip_numerator      =  1.0;
   const float pow_numerator        =  1.0;
   const int min_number_of_elements =  1;        
   const int first_element          =  0;
   const int program_success_code   =  0;
   const int program_failure_code   = -1;
 
  /*
   ***********************
   * Variable Subsection *
   *********************** 
   *
   * list1_inp_val = (float*)NULL: This is the first array list.
   * list2_inp_val = (float*)NULL: This is the second array list.
   * list1_inp_val_sum:            This is the calculated summation of
   *                               the numbers in the first list.
   * list2_inp_val_sum:            This is the calculated summation of
   *                               the numbers in the second list.
   * list1_inp_recip_sum:          This is the calculated reciprocal
   *                               sum for the first list, and is used to
   *                               calculate the harmonic mean.
   * list2_inp_recip_sum:          This is the calculated reciprocal
   *                               sum for the second list, and is used
   *                               to calculate the harmonic mean.
   * list1_arith_mean:             This is the first list's calculated
   *                               arithmetic mean.
   * list2_arith_mean:             This is the second list's calculated
   *                               arithmetic mean.
   * list1_geo_mean:               This is the first list's calculated
   *                               geometric mean.
   * list2_geo_mean:               This is the second list's calculated
   *                               geometric mean.
   * list1_root_mean:              This is the first list's calculated
   *                               root mean square.
   * list2_root_mean:              This is the second list's calculated
   *                               root mean square.
   * list1_harm_mean:              This is the first list's calculated
   *                               harmonic mean.
   * list2_harm_mean:              This is the second list's calculated
   *                               harmonic mean.
   * number_of_elements:           This is the user's input for setting
   *                               the list size.
   * element:                      This is the element counter for the 
   *                               for loop calculations.
   *
   */

   float* list1_inp_val = (float*)NULL;
   float* list2_inp_val = (float*)NULL;
   float  list1_inp_val_sum, list2_inp_val_sum;
   float  list1_inp_recip_sum, list2_inp_recip_sum;
   float  list1_arith_mean, list2_arith_mean;
   float  list1_geo_mean, list2_geo_mean;
   float  list1_root_mean, list2_root_mean;
   float  list1_harm_mean, list2_harm_mean;
   int    number_of_elements, element;


  /*
   *************************
   *** Execution Section ***
   *************************
   *
   ********************
   * Input Subsection *
   ********************
   *
   * This scans the user's input for the size of the pair
   * of lists that the user desires to calculate the arithmetic,
   * geometric, harmonic mean, and root mean square of.
   * Next it scans the user's input for each value of the 
   * lists. Finally there is idiot proofing put in place for bad
   * inputs, and makes sure the arrays are properly allocated
   * dynamically. If allocation fails the program will send an error
   * message before safely exiting.
   *
   */
   
   scanf("%d", &number_of_elements);
   if (number_of_elements < min_number_of_elements) {
       printf("ERROR: Can't calculate the mean of %d values.\n",
           number_of_elements);
       exit(program_failure_code);
   } /* if (number_of_elements < minimum_number_of_elements) */


   list1_inp_val =
       (float*)malloc(sizeof(float) * number_of_elements);
   if (list1_inp_val == (float*)NULL)  {
       printf("ERROR: Can't allocate the 1st float array\n");
       printf(" of length %d.\n", number_of_elements);
       exit(program_failure_code);
   } /* if (list1_inp_val == (float*)NULL) */

   list2_inp_val =
       (float*)malloc(sizeof(float) * number_of_elements);
   if (list2_inp_val == (float*)NULL)  {
       printf("ERROR: Can't allocate the 2nd float array\n");
       printf(" of length %d.\n", number_of_elements);
       exit(program_failure_code);
   } /* if (list2_inp_val == (float*)NULL) */


   for (element = first_element;
        element < number_of_elements; element++) {
       scanf("%f %f",
           &list1_inp_val[element],
           &list2_inp_val[element]);
   } /* for element */


   
  /*
   **************************
   * Calculation Subsection *
   **************************
   *
   * This section calculates the arithmetic mean, geometric mean,
   * root mean square, and the harmoinc mean of the pair of lists 
   * inputted by the user.
   *
   */


   /*
    * Summation calculations for simplifying mean calculations
    */


   list1_inp_val_sum = zero_sum;
   for (element = first_element;
        element < number_of_elements; element++) {
       list1_inp_val_sum =
           list1_inp_val_sum + list1_inp_val[element]; 
   } /* for element summation of values */


   list2_inp_val_sum = zero_sum;
   for (element = first_element;
        element < number_of_elements; element++) {
       list2_inp_val_sum =
           list2_inp_val_sum + list2_inp_val[element];
   } /* for element summation of values */

   list1_inp_recip_sum = zero_sum;
   for (element = first_element;
        element < number_of_elements; element++) {
       list1_inp_recip_sum =
           list1_inp_recip_sum + (recip_numerator / list1_inp_val[element]);
   } /* for element reciprocal summation of values */

   list2_inp_recip_sum = zero_sum;
   for (element = first_element;
        element < number_of_elements; element++) {
       list2_inp_recip_sum =
           list2_inp_recip_sum + (recip_numerator / list2_inp_val[element]);
   } /* for element reciprocal summation of values */



   /*
    * arthimetic, geometric, root, and harmonic mean calculations
    */

    list1_arith_mean =
        list1_inp_val_sum / number_of_elements;
    
    list2_arith_mean =
        list2_inp_val_sum / number_of_elements;
    
    list1_geo_mean = initial_product;
    for (element = first_element;
         element < number_of_elements; element++) {
        list1_geo_mean =
            list1_geo_mean * pow(list1_inp_val[element],
                pow_numerator/number_of_elements);  
    } /* for (element = zero_element; element < number_of_elements ... */

    list2_geo_mean = initial_product;
    for (element = first_element;
         element < number_of_elements; element++) {
        list2_geo_mean =
            list2_geo_mean * pow(list2_inp_val[element],
                pow_numerator/number_of_elements);
    } /* for (element = zero_element; element < number_of_elements ... */
    

    list1_root_mean = sqrt(list1_inp_val_sum / number_of_elements);
   
    list2_root_mean = sqrt(list2_inp_val_sum / number_of_elements);      

    list1_harm_mean = number_of_elements / list1_inp_recip_sum;

    list2_harm_mean = number_of_elements / list2_inp_recip_sum;


  /*
   *********************
   * Output Subsection *
   *********************
   *
   * This subsection prints the selected list length, the values for
   * each list, and finally the four calculated means.
   */

   printf("The selected list length was %d integers long.\n", 
       number_of_elements);
   printf("The values for the pair of lists used are:\n");
   for (element = first_element;
        element < number_of_elements; element++) { 
       printf("%f %f\n",
           list1_inp_val[element],
           list2_inp_val[element]);
   } /* for element  */




   printf("The arithmetic mean of the 1st list is:\n");
   printf(" %f\n", list1_arith_mean);

   printf("The arithmetic mean of the 2nd list is:\n");
   printf(" %f\n", list2_arith_mean);

   printf("The geometric mean of the 1st list is:\n");
   printf(" %f\n", list1_geo_mean);
  
   printf("The geometric mean of the 2nd list is:\n");
   printf(" %f\n", list2_geo_mean);

   printf("The root mean square of the 1st list is:\n");
   printf(" %f\n", list1_root_mean);
  
   printf("The root mean square of the 2nd list is:\n");
   printf(" %f\n", list2_root_mean);

   printf("The harmonic mean of the 1st list is:\n");
   printf(" %f\n", list1_harm_mean);

   printf("The harmonic mean of the 2nd list is:\n");
   printf(" %f\n", list2_harm_mean);

   free(list2_inp_val);
   list2_inp_val = (float*)NULL;
   free(list1_inp_val);
   list1_inp_val = (float*)NULL;
   return program_success_code;

 } /* main */
