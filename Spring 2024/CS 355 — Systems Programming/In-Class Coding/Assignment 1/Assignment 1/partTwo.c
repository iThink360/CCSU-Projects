//
//  partTwo.c
//  Assignment 1
//
//  Created by Rumman Shahzad on 1/30/24.
//

/* Write a C program to input basic salary of an employee and calculate gross salary according to given conditions.

 * Basic Salary <= 10000 : HRA = 20%, DA = 80%
 * Basic Salary is between 10001 to 20000 : HRA = 25%, DA = 90%
 * Basic Salary >= 20001 : HRA = 30%, DA = 95%
 * Gross salary is the final salary computed after the additions of DA and HRA. The formula for DA and HRA is:
 
 * da = basic_salary * (DA/100)
 * If DA = 80% then the statement becomes da = basic_salary * (80/100). Which can also be written as DA = basic_salary * 0.08. Likewise you can also derive a formula for HRA.
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    // Assume a nonnegative salary input.
    
    float myBasicSalary;
    float da, hra, grossSalary;
    
    printf("Gross Salary Calculator\n\n");
    
    printf("Input a basic salary: ");
    scanf("%f", &myBasicSalary);
    
    // Calculate DA and HRA based on percentages mentioned above
    if (myBasicSalary <= 10000) {
        da = myBasicSalary * 0.80;
        hra = myBasicSalary * 0.20;
    }
    else if (myBasicSalary >= 10001 && myBasicSalary <= 20000) {
        da = myBasicSalary * 0.90;
        hra = myBasicSalary * 0.25;
    }
    else { // Basic salary >= 20001
        da = myBasicSalary * 0.95;
        hra = myBasicSalary * 0.30;
    }
    
    // Final computation and output
    grossSalary = myBasicSalary + da + hra;
    printf("Your gross salary is %f.\n", grossSalary);
    
    return 0;
}
