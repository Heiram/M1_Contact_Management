#include "unity.h"
#define PROJECT_NAME "CONTACT_MANAGEMENT"
extern void test_contact();
void setUp(void)
{}
void tearDown(void){}
int main(void){
    UnityBegin(NULL);
    RUN_TEST(test_contact);
    return (UnityEnd());
}