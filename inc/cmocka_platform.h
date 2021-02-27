/*
 * cmocka_platform.h
 *
 *  Created on: Feb 27, 2021
 *      Author: Kenneth
 */

#ifndef EXAMPLE_USER_CMOCKA_PLATFORM_H_
#define EXAMPLE_USER_CMOCKA_PLATFORM_H_

/**
 * @note We just define these so cmocka will compile. Bare metal does not include these signals
 * because it doesn't generate them. Either case these are the portable POSIX numbers. Should not
 * trigger any macro redefinitions.
 */

/**
 * Instead of using the HAVE_XXX_H define mechnaism, we will just declare them here
 */

#include <signal.h>
#include <inttypes.h>

#endif /* EXAMPLE_USER_CMOCKA_PLATFORM_H_ */
