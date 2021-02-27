/*
 * run_test.c
 *
 *  Created on: Feb 27, 2021
 *      Author: Kenneth
 */


#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>


/* A test case that does nothing and succeeds. */
static void null_test_success(void **state) {
    (void) state; /* unused */
}

static void null_test_success2(void **state) {
    (void) state; /* unused */
}

static void null_test_success3(void **state) {
    (void) state; /* unused */
}

int run_test_main(void) {
	cmocka_set_message_output(CM_OUTPUT_XML);
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
		cmocka_unit_test(null_test_success2),
		cmocka_unit_test(null_test_success3),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
