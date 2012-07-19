/*
 * main.c
 *
 *  Created on: 9/03/2012
 *      Author: Dan
 */

#include <stdio.h>
#include <stdlib.h>

#include <gmp.h>

//#define __DEBUG

// prime( primeTtest, BottemTest, TopTest )

int main(int argc, char **argv) {
  mpz_t test; // Value to test
  mpz_t upper; // Upper limit to divide the test value by
  mpz_t divisor; // The value to divide the test value by
  mpz_t result; // Result of the mod divide

  unsigned int res_val = 0; // Return value from functions
  unsigned char prime = 1; // bit flag for if the number is prime or not

  mpz_init(test); // Initiate gmp integers
  mpz_init(upper); // TODO: Improve all of these so there are fewer operations
  mpz_init(divisor);
  mpz_init(result);

  
  
  //mpz_sqrt(upper, test); // Find the largest value to divide by
  //mpz_set_ui(divisor, 2); // First number to divide by is 2
  
  
  mpz_set_str(test, argv[1], 10); // Find the value under test
  mpz_set_str(divisor, argv[2], 10); // First number to divide by is 2nd argument
  mpz_set_str(upper, argv[3], 10); // Last Number to divide by is 3rd argument
  
  if (argc != 4) {
    // Error condition
    return 3;
  } else {
#ifdef __DEBUG
    gmp_printf("Number under test: %Zd\n", test);
#endif
    while (1) {
      mpz_mod(result, test, divisor); // result = test % divisor
      res_val = mpz_cmp_ui(result, 0); // Compare result to 0.  res_val == 0 when result == 0
      if (res_val == 0) { // if result from the mod divide was 0
        prime = 0; // Number isn't a prime
        break;
      }
      res_val = mpz_cmp(divisor, upper); // Check to see if the loop has finished
      if (res_val == 0)
        break; // Stop searching
      mpz_add_ui(divisor, divisor, 1); // divisor += 1
    }

    if (prime) {
#ifdef __DEBUG
      printf("Is a prime.\n");
#endif
      return 1; // Number is a prime
    } else {
#ifdef __DEBUG
      printf("Is not a prime.\n");
#endif
      return 0; // Number is not a prime
    }
  }

  return 4; // Should never get here..!
}
