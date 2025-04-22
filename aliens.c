/*
 ************************************************************************
 *** Project #3:  Saving Aliens                                       ***
 *** Program:     aliens                                              ***
 *** Author:      Evan Blosser  (evan.a.blosser-1@ou.edu)             ***
 *** Class:       CS 1313 Computer Programming, Spring 2021           ***
 *** Lab:         Sec 010 Fridays 2:15pm                              ***
 *** Description: This program calculates the weekly pay I recive for ***
 ***              saving aliens.                                      *** 
 ************************************************************************
 */

 #include <stdio.h>
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
    * hourly_pay:     This is the payment amount for every hour worked
    * pay_alien:      This is the payment for every alien saved
    * pay_neon_alien: This is the payment for every neon alien saved
    *
    */
 
    float hourly_pay         = 8.25;
    float pay_alien          = 5.25;
    float pay_neon_alien     = 9.75;

   /*
    ***********************
    * Variable Subsection *
    ***********************
    *
    * hours_worked:      This is the user's input for the hours they
    *                    worked in the week
    * overtime:          This is the payment of time and a half for hours 
    *                    worked over 40   
    * overtime_worked:   This is the user's input for any hours worked
    *                    over 40 hours in the week
    * hours_pay:         This is the value calculated for the payment
    *                    the user will receive for hours worked
    * alien_pay:         This is the value calculated for the payment
    *                    the user will receive for aliens saved
    * weekly_pay:        This is the value calculated for the user's
    *                    total weekly payment.
    * aliens_tot:        This is the total number of aliens saved
    *                    in the week
    * aliens:            This is the number of aliens saved in the 
    *                    week
    * neon_aliens:       This is the number of neon aliens saved in
    *                    the week
    */ 

    float hours_worked, overtime, overtime_worked;
    float hours_pay, alien_pay, weekly_pay;
    int   aliens_tot, aliens, neon_aliens;

   /*
    *************************
    *** Execution Section ***
    *************************
    *
    ************************
    * Greetings Subsection *
    ************************
    *
    * This section greets the user and lets them know this program
    * will calculate their weekly pay for saving aliens.
    */ 

    printf("Hello, we are going to calculate your weekly pay\n");
    printf(" for saving aliens!\n");
    
   /*
    ********************
    * Input Subsection *
    ********************
    *
    * This section prompts the user to input the number of hours worked,
    * and how many hours they worked overtime. It also prompts the user
    * to input the number of aliens and neon aliens saved during the
    * week. 
    */

    printf("How many hours did you work this week? If you worked\n");
    printf(" overtime please input a maximum of full time hours.\n");
    scanf("%f" , &hours_worked);
    printf("How many hours of overtime did you work this week?\n");
    scanf("%f" , &overtime_worked);
    printf("Now, how many aliens did you save this week?\n");
    scanf("%d" , &aliens_tot);
    printf("Great job! How many of those aliens were neon?\n");
    scanf("%d" , &neon_aliens);
   
   /*
    **************************
    * Calculation Subsection *
    **************************
    *
    * This section; first calculates the numbre of non-neon aliens saved
    * and the payment for ovetime, and then performs the calculations
    * for weekly payment using the values for hours worked and aliens
    * saved that were inputted by the user.
    */
    
    overtime = hourly_pay * 1.5;
    aliens = aliens_tot - neon_aliens; 
    hours_pay = (hours_worked * hourly_pay) + (overtime_worked * overtime);
    alien_pay = (aliens * pay_alien) + (neon_aliens * pay_neon_alien); 
    weekly_pay = hours_pay + alien_pay;

   /* 
    *********************
    * Output Subsection *
    *********************
    * 
    * This section displays the user's inputs for hours worked,  
    * overtime worked, and both regular and neon aliens saved so
    * the user can double check that their input values are 
    * accurate. It then displays the calculated weekly pay to the user
    * that they are going to receive for saving aliens.
    */

    printf("Great job! You worked %f hours this week.\n", hours_worked);
    printf("You also worked %f hours overtime.\n", overtime_worked);
    printf("While working you saved %d non-neon aliens.\n", aliens);
    printf("You also saved %d neon aliens.\n", neon_aliens);
    printf("For your hard work you will be payed a total of\n");
    printf(" $ %f this week.\n", weekly_pay);


 } /*main*/
