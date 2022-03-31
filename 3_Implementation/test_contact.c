#include "unity.h"
#define PROJECT_NAME "CONTACT_MANAGEMENT"

/* Prototypes for all the test functions */
/**
 * @brief testing function for contact management
 * 
 */
extern void test_contact();
/* Required by the unity test framework */
void setUp(void)
{}
/* Required by the unity test framework */
void tearDown(void){}
/* Start of the application test */
int main(void){
    /* Initiate a unity test framework */
    UnityBegin(NULL);
    /* Run test functi0n */
    RUN_TEST(test_contact);
    /* Close the unity test framework */
    return (UnityEnd());
}