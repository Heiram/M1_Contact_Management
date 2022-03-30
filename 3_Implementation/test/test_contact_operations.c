#include "unity.h"
#include "contact_operations.h"
#define PROJECT_NAME "contact management"
void test_main();
void setUp(){}
void tearDown(){}
int main(){
    UNITY_BEGIN();
    RUN_TEST(test_main);
    return UNITY_END;
}