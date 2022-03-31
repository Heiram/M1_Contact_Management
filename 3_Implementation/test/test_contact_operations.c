#include "unity.h"
#include "contact_operations.h"
#define PROJECT_NAME "contact management"

/* Prototypes for all the test functions */

/**
 * @brief testing function for contact management
 * 
 */

/**
 * @brief main testing operations for contact management
 * 
 */
void test_main();
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}
/* Start of the application test */
int main(){
    /* Initiate the unity test framework */
    UNITY_BEGIN();
    /* Run test functions */
    RUN_TEST(test_main);
    /* Close the unity test framework */
    return UNITY_END;
}