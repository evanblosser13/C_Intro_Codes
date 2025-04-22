/*
 ****************************************************************
 *** Project #4:  Pizza Shop                                  ***
 *** Program:     pizza_time                                  ***
 *** Author:      Evan Blosser   (evan.a.blosser-1@ou.edu)    ***
 *** Class:       CS 1313 Computer Programming, Spring 2021   ***
 *** Lab:         Sec 010 Fridays 2:15pm                      ***
 *** Description: This program is an ordering system for a    ***
 ***              pizza shop, which logs the customer's order ***
 ***              and calculate's the total and taxes.        ***
 ****************************************************************
 */

#include <stdio.h>
#include <stdlib.h>

int main ()
{ /* main */

  /*
   ***************************
   *** Declaration Section ***
   ***************************
   *
   ******************************
   * Named Constants Subsection *
   ******************************
   *
   * cheesy_b_price:       This is the price of the Cheesy Bread.
   * fried_pick_price:     This is the price of the Fried Pickles.
   * fried_mush_price:     This is the price of the Fried Mushrooms.
   * saus_pizza_price:     This is the Sausage Pizza price.
   * pep_pizza_price:      This is the pepperoni pizza price.
   * chee_pizza_price:     This is the cheese pizza price.
   * mlkshk_price:         This is the milkshake price.
   * tea_price:            This is the tea price.
   * soda_price:           This is the soda price.
   * cinn_sticks_price:    This is the cinnamon sticks price.
   * lava_price:           This is the lava cake price.
   * pie_price:            This is the key lime pie price.
   * tax_rate:             This is the sales tax rate.
   * tip_rate:             This is the tip percentage.
   * void_price:           This is the price for nothing, or place holder
   *                       for calculating the grand total when no item is 
   *                       ordered within a category.
   *
   * program_fail_code:    This exits the program if any wrong input
   *                       values are enterd, or simply the it is part
   *                       of idiotproofing.
   * program_success_code: This exits the program after successful
   *                       completion.
   * void_code:            This is what the user will enter if they
   *                       don't want any item from the given section
   *                       like no appetizers.
   * cheesy_b_code:        This is what the user inputs if they would 
   *                       like to order cheesy bread.
   * fried_pick_code:      This is what the user inputs if they wish 
   *                       to order fried pickles.
   * fried_mush_code:      This is what the user inputs if they wish
   *                       to order fried mushrooms.
   * saus_pizza_code:      This is the input for the user to order
   *                       a sausage pizza.
   * pep_pizza_code:       This is the input for the user to order
   *                       a pepperoni pizza.
   * chee_pizza_code:      This is the input for the user to order
   *                       a cheese pizza.
   * mlkshk_code:          This is the input for the user to order 
   *                       a milkshake.
   * tea_code:             This is the input for a user to order a tea.
   * soda _code:           This is the input for a user to order a soda.
   * cinn_sticks_code:     This is the input for a user to order
   *                       cinnamon sticks.
   * lava_code:            This is the input for a user to order 
   *                       a lava cake.
   * pie_code:             This is the input for a user to order 
   *                       a key lime pie. 
   *
   */

   const float cheesy_b_price = 4.00, fried_pick_price = 3.75;
   const float fried_mush_price = 3.0;
   const float saus_pizza_price = 14.00, pep_pizza_price = 11.75;
   const float chee_pizza_price = 9.50;
   const float mlkshk_price = 5.50, tea_price = 3.75;
   const float soda_price = 3.25;
   const float cinn_sticks_price = 7.25, lava_price = 8.00;
   const float pie_price = 3.25;
   const float tax_rate = 0.0875, tip_rate = 0.19; 
   const float void_price = 0.00;

   const int program_fail_code = -1, program_success_code = 0;
   const int void_code = 0;
   const int cheesy_b_code = 1, fried_pick_code = 2;
   const int fried_mush_code = 3;
   const int saus_pizza_code = 1, pep_pizza_code = 2;
   const int chee_pizza_code = 3;  
   const int mlkshk_code = 1, tea_code = 2, soda_code = 3;
   const int cinn_sticks_code = 1, lava_code = 2, pie_code = 3;

  /* 
   ***********************
   * Variable Subsection *
   ***********************
   *
   * app_price:     This is the price of the chosen appetizer.
   * pizza_price:   This is the price of the chosen pizza.
   * dessert_price: This is the price of the chosne dessert.
   * drink_price:   This is the price of the chosen drink.
   * sub_total:     This is the summation of all ordered items price,
   *                before tax or tip.
   * tax_total:     This is the calculated sales tax.
   * tip_total:     This is the amount the customer tips, not including 
   *                taxes in the calculation.
   * grand_total:   This is the calculated cost of each meal ordered
   *                that the customer will pay.
   * app_code:      This is the code designating which appetizer was ordered.
   * pizza_code:    This is the code designating whcich pizza was ordered.
   * dessert_code:  This is the code designating which dessert was ordered. 
   * drink_code:    This is the code designation which drink was ordered.
   *
   */

   float app_price, pizza_price, dessert_price, drink_price;
   float sub_total, tax_total, tip_total, grand_total;
   int app_code, pizza_code, dessert_code, drink_code;

  /*
   *************************
   *** Execution Section ***
   *************************
   *
   ***********************
   * Greeting Subsection *
   ***********************
   *
   * This section greets the customer and explains
   * how to order pizza using the program. It can also
   * be utilized by employees if necessary.
   * 
   * It also tells the user this is Joe's pizza shop,
   * from spiderman-2; Pizza Time!
   *
   */

   printf("Hello and welcome to Joe's pizza shop!\n");
   printf("To place your order please select the number given\n");
   printf(" for each desired menu item when promted.\n\n");

  /* 
   ********************
   * Input Subsection *
   ********************
   *
   * This section prompts the user to input their order starting
   * with appetizers, then pizza, then dessert, and finally the drink. 
   *
   */

   printf("What appetizer would you like to order today?\n");
   printf("Please enter:\n  %d for no apppetizer\n  %d for cheesy bread\n",
       void_code, cheesy_b_code);
   printf("  %d for fried pickles\n  %d for fried mushrooms\n",
       fried_pick_code, fried_mush_code);      
   scanf("%d", &app_code);
   /*
    * Input idiotproofing for appetizer, and exit message and code
    */
   if ((app_code != void_code)       &&
       (app_code != cheesy_b_code)   &&
       (app_code != fried_pick_code) &&
       (app_code != fried_mush_code)){
       printf("ERROR: unknown item code %d, please restart.\n",
           app_code);
       exit(program_fail_code);
   } /* if ((app_code != void_code) &&...) */

   printf("What type of pizza would you like to order today?\n");
   printf("Please enter:\n  %d for no pizza\n  %d for sausage pizza\n",
       void_code, saus_pizza_code);
   printf("  %d for pepperoni pizza\n  %d for cheese pizza\n",
       pep_pizza_code, chee_pizza_code);
   scanf("%d", &pizza_code);
   /*
    * Input idiotproofing for pizza, and exit message and code
    */
   if ((pizza_code != void_code)       && 
       (pizza_code != saus_pizza_code) &&
       (pizza_code != pep_pizza_code)  &&
       (pizza_code != chee_pizza_code)){
       printf("ERROR: unknown item code %d, please restart.\n",
           pizza_code);
       exit (program_fail_code);
   }/* if ((pizza_code != void_code) &&...) */

   printf("What dessert would you like to go with your order?\n");
   printf("Please enter:\n  %d for no dessert\n  %d for cinnamon sticks\n",
       void_code, cinn_sticks_code);
   printf("  %d for lava cake\n  %d for key lime pie\n",
       lava_code, pie_code);
   scanf("%d", &dessert_code);
   /*
    * Input idiotproofing for dessert, and exit message and code
    */
    if ((dessert_code != void_code)        &&
        (dessert_code != cinn_sticks_code) &&
        (dessert_code != lava_code)        &&
        (dessert_code != pie_code)){
        printf("ERROR: unknown item code %d, please restart.\n",
            dessert_code);
        exit (program_fail_code);
     }/* if ((dessert_code != void_code) &&...) */

    printf("What drink would you like to go with your order?\n");
    printf("Please enter:\n  %d for no drink\n  %d for milkshake\n",
        void_code, mlkshk_code);
    printf("  %d for tea\n  %d for soda\n",
        tea_code, soda_code);
    scanf("%d", &drink_code);
    /*
     * Input idiotproofing for drink, and exit message and code
     */
     if ((drink_code != void_code)   &&
         (drink_code != mlkshk_code) &&
         (drink_code != tea_code)    &&
         (drink_code != soda_code)){
         printf("ERROR: unknown item code %d, please restart.\n",
             drink_code);
         exit(program_fail_code);
     }/* if ((drink_code != void_code) &&...) */


  /*
   **************************
   * Calculation Subsection *
   **************************
   *
   * This section is the bulk of the if statements, which assigns  
   * the code inputted by the user for each menu item to it's price.
   * Then it calculates the sub total, taxes, tip, and grand total.
   * 
   */

  /*
   * This if block assigns the price to the user's chosen appetizer
   */
   if (app_code == void_code){
       app_price = void_price;
   } /* if (app_code == void_code) */
   else if (app_code == cheesy_b_code){
            app_price = cheesy_b_price;
   } /* if app_code == cheesy_b_code */
   else if (app_code == fried_pick_code){
            app_price = fried_pick_price;
   } /* if (app_code == fried_pick_code) */
   else if (app_code == fried_mush_code){
            app_price = fried_mush_price;
   } /* if (app_code == fried_mush_code) */

  /*
   * This if block assigns the price to the user's chosen pizza
   */
   if (pizza_code == void_code){
       pizza_price = void_price;
   } /* if (pizza_code = void_code) */
   else if (pizza_code == saus_pizza_code){
            pizza_price = saus_pizza_price;
   } /* if (pizza_code == saus_pizza_code */
   else if (pizza_code == pep_pizza_code){
            pizza_price = pep_pizza_price;
   } /* if (pizza_code == pep_pizza_code) */
   else if (pizza_code == chee_pizza_code){
            pizza_price = chee_pizza_price;
   } /* if (pizza_code == chee_pizza_code) */ 

  /*
   * This if block assigns the price to the user's chosen dessert
   */
   if (dessert_code == void_code){
       dessert_price = void_price;
   } /* if (dessert_code == void_code) */
   else if (dessert_code == cinn_sticks_code){
            dessert_price = cinn_sticks_price;
   } /* if (dessert_code == cinn_sticks_code) */
   else if (dessert_code == lava_code){
            dessert_price = lava_price;
   } /* if (dessert_code == lava_code) */
   else if (dessert_code == pie_code){
            dessert_price = pie_price;
   } /* if (dessert_code == pie_code) */

  /*
   * This if block assigns the price to the user's chosen drink
   */
   if (drink_code == void_code){
       drink_price = void_price;
   } /* if (drink_code == void_code) */
   else if (drink_code == mlkshk_code){
            drink_price = mlkshk_price;
   } /* if (drink_code == mlkshk_code) */
   else if (drink_code == tea_code){
            drink_price = tea_price;
   } /* if (drink_code == tea_code) */
   else if (drink_code == soda_code){
            drink_price = soda_price;
   } /* if (drink_code == soda_code) */

  /*
   * This is the calculations for the sub total, tax, tip, and grand total
   */

   sub_total = app_price + pizza_price + dessert_price + drink_price;
   tax_total = sub_total * tax_rate;
   tip_total = sub_total * tip_rate;
   grand_total = sub_total + tax_total + tip_total;

  /*
   *********************
   * Output Subsection *
   *********************
   *
   * This section prints a complete itemized receipt of the order to
   * the user which includes the caluclated order cost.
   * 
   */
   printf("----------------------------------------------------------\n");
   printf("Joe's Pizza Shop\n\n");
   printf("Your order was:\n");
   
  /*
   * This if block assigns an itemized price for the ordered appetizer.
   */
   if (app_code == void_code){
      printf("  No appetizer:      $%5.2f\n",
          void_price);
   } /* if (app_code == void_code) */
   else if (app_code == cheesy_b_code){
      printf("  Cheesy bread:      $%5.2f\n",
          cheesy_b_price);
   } /* if (app_code == cheesy_b_code) */
   else if (app_code == fried_pick_code){
      printf("  Fried pickles:     $%5.2f\n",
          fried_pick_price);
   } /* if (app_code == fried_pick_code) */
   else if (app_code == fried_mush_code){
      printf("  Fried Mushrooms:   $%5.2f\n",
          fried_mush_price);
   } /* if (app_code == fried_mush_code) */

  /*
   * This if block assigns an itemized price for the ordered pizza.
   */
   if (pizza_code == void_code){
      printf("  No Pizza:          $%5.2f\n",
          void_price); 
   } /* if (pizza_code == void_code) */
   else if (pizza_code == saus_pizza_code){
      printf("  Sausage pizza:     $%5.2f\n",
          saus_pizza_price);
   } /* if (pizza_code == saus_pizza_code) */
   else if (pizza_code == pep_pizza_code){
      printf("  Pepperoni pizza:   $%5.2f\n",
          pep_pizza_price);
   } /* if (pizza_code == pep_pizza_code) */
   else if (pizza_code == chee_pizza_code){
      printf("  Cheese pizza:      $%5.2f\n",
          chee_pizza_price);
   } /* if (pizza_code == chee_pizza_code) */
   
  /*
   * This if block assigns an itemized price for the ordered dessert.
   */
   if (dessert_code == void_code){
      printf("  No dessert:        $%5.2f\n",
          void_price);
   } /* if (dessert_code == void_code) */
   else if (dessert_code == cinn_sticks_code){
      printf("  Cinnamon sticks:   $%5.2f\n",
          cinn_sticks_price);
   } /* if (dessert_code == cinn_sticks_code) */
   else if (dessert_code == lava_code){
      printf("  Lava cake:         $%5.2f\n",
          lava_price);
   } /* if (dessert_code == lava_code) */
   else if (dessert_code == pie_code){
      printf("  Key lime pie:      $%5.2f\n",
          pie_price);
   } /* if (dessert_code == pie_code) */

  /*
   * This if block assigns an itemized price for the ordered drink.
   */
   if (drink_code == void_code){
      printf("  No drink:          $%5.2f\n",
          void_price);
   } /* if (drink_code == void_code) */
   else if (drink_code == mlkshk_code){
      printf("  Milkshake:         $%5.2f\n",
          mlkshk_price);
   } /* if (drink_code == mlkshk_code) */
   else if (drink_code == tea_code){
      printf("  Tea:               $%5.2f\n",
          tea_price);
   } /* if (drink_code == tea_code) */
   else if (drink_code == soda_code){
      printf("  Soda:              $%5.2f\n",
          soda_price);
   } /* if (drink_code == soda_code) */ 

   printf("  -------------------------------------------\n");
   printf("  Subtotal:             $%5.2f\n",
       sub_total);
   printf("  Tax:                  $%5.2f\n",
       tax_total);
   printf("  Tip:                  $%5.2f\n",
       tip_total);
   printf("  -------------------------------------------\n");
   printf("  Grand Total:          $%5.2f\n\n",
       grand_total);
   printf("Thank you for visiting Joe's Pizza Shop!\n");
   printf("---------------------------------------------------------\n");

   return program_success_code;

} /* main */
