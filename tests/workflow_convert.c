/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:13:30 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 12:57:37 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>

#include <assert.h>
#include <convert.h>
#include <limits.h>
#include <string.h>
#include <math.h>

// Tests pour la fonction atoi
void test_atoi() {
    assert(atoi("123") == 123);
    assert(atoi("-123") == -123);
    assert(atoi("0") == 0);
    assert(atoi("+456") == 456);
    assert(atoi("00123") == 123);                // Leading zeros
    assert(atoi("2147483647") == 2147483647);    // INT_MAX
    assert(atoi("-2147483648") == -2147483648);  // INT_MIN
    assert(atoi("2147483648") == -2147483648);   // Overflow
    assert(atoi("-2147483649") == 2147483647);   // Underflow
    assert(atoi("abc") == 0);                    // Non-numeric string
    assert(atoi("") == 0);                       // Empty string
    assert(atoi("   123") == 123);               // Leading spaces
    assert(atoi("123abc") == 123);               // Mixed alphanumeric
    assert(atoi("  -42") == -42);                // Leading spaces and negative sign
}

// Tests pour la fonction itoa
void test_itoa() {
    char buffer[__ITOA_BUFFER_LENGTH__];

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    itoa(123, buffer);
    assert(strcmp(buffer, "123") == 0);

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    itoa(-123, buffer);
    assert(strcmp(buffer, "-123") == 0);

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    itoa(0, buffer);
    assert(strcmp(buffer, "0") == 0);

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    itoa(2147483647, buffer); // INT_MAX
    assert(strcmp(buffer, "2147483647") == 0);

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    itoa(-2147483648, buffer); // INT_MIN
    assert(strcmp(buffer, "-2147483648") == 0);

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    itoa(42, buffer);
    assert(strcmp(buffer, "42") == 0);

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    itoa(-42, buffer);
    assert(strcmp(buffer, "-42") == 0);
}

// Tests pour la fonction uitoa
void test_uitoa() {
    char buffer[__ITOA_BUFFER_LENGTH__];

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    uitoa(123, buffer);
    assert(strcmp(buffer, "123") == 0);

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    uitoa(0, buffer);
    assert(strcmp(buffer, "0") == 0);

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    uitoa(UINT_MAX, buffer);                    // UINT_MAX
    assert(strcmp(buffer, "4294967295") == 0);  // UINT_MAX in decimal

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    uitoa(42, buffer);
    assert(strcmp(buffer, "42") == 0);
}

// Tests pour la fonction itoa_base
void test_itoa_base() {
    char buffer[__ITOA_BUFFER_LENGTH__];

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    itoa_base(123, 16, buffer);
    assert(strcmp(buffer, "7B") == 0);

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    itoa_base(0, 2, buffer);
    assert(strcmp(buffer, "0") == 0);

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    itoa_base(-123, 16, buffer);
    assert(strcmp(buffer, "-7B") == 0);

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    itoa_base(2147483647, 16, buffer); // INT_MAX
    assert(strcmp(buffer, "7FFFFFFF") == 0);

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    itoa_base(-2147483647, 16, buffer); // INT_MIN + 1
    assert(strcmp(buffer, "-7FFFFFFF") == 0);

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    itoa_base(255, 2, buffer); // Base 2
    assert(strcmp(buffer, "11111111") == 0);

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    itoa_base(-255, 2, buffer); // Base 2 with negative number
    assert(strcmp(buffer, "-11111111") == 0);
}

// Tests pour la fonction uitoa_base
void test_uitoa_base() {
    char buffer[__ITOA_BUFFER_LENGTH__];

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    uitoa_base(123, 16, buffer);
    assert(strcmp(buffer, "7B") == 0);

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    uitoa_base(0, 2, buffer);
    assert(strcmp(buffer, "0") == 0);

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    uitoa_base(UINT_MAX, 16, buffer);
    assert(strcmp(buffer, "FFFFFFFF") == 0); // UINT_MAX in hexadecimal

    memset(buffer, 0, __ITOA_BUFFER_LENGTH__);
    uitoa_base(255, 8, buffer); // Base 8
    assert(strcmp(buffer, "377") == 0);
}

// Tests pour la fonction atoi_base_s
void test_atoi_base_s() {
    assert(atoi_base_s("7B", 16) == 123);
    assert(atoi_base_s("0", 2) == 0);
    assert(atoi_base_s("7FFFFFFF", 16) == 2147483647);    // INT_MAX
    assert(atoi_base_s("-80000000", 16) == -2147483648);  // INT_MIN
    assert(atoi_base_s("101010", 2) == 42);               // Base 2
    assert(atoi_base_s("377", 8) == 255);                 // Base 8
    assert(atoi_base_s("ZZ", 36) == 1295);                // Base 36 (max base)
}

// Tests pour la fonction itoa_s
void test_itoa_s() {
    char *result;

    result = itoa_s(123);
    assert(strcmp(result, "123") == 0);
    kfree(result);

    result = itoa_s(-123);
    assert(strcmp(result, "-123") == 0);
    kfree(result);

    result = itoa_s(0);
    assert(strcmp(result, "0") == 0);
    kfree(result);

    result = itoa_s(2147483647); // INT_MAX
    assert(strcmp(result, "2147483647") == 0);
    kfree(result);

    result = itoa_s(-2147483647); // INT_MIN + 1
    assert(strcmp(result, "-2147483647") == 0);
    kfree(result);
}

// Tests pour la fonction uitoa_s
void test_uitoa_s() {
    char *result;

    result = uitoa_s(123);
    assert(strcmp(result, "123") == 0);
    kfree(result);

    result = uitoa_s(0);
    assert(strcmp(result, "0") == 0);
    kfree(result);

    result = uitoa_s(UINT_MAX);                   // UINT_MAX
    assert(strcmp(result, "4294967295") == 0);    // UINT_MAX in decimal
    kfree(result);
}

// Tests pour la fonction itoa_base_s
void test_itoa_base_s() {
    char *result;

    result = itoa_base_s(123, 16);
    assert(strcmp(result, "7B") == 0);
    kfree(result);

    result = itoa_base_s(0, 2);
    assert(strcmp(result, "0") == 0);
    kfree(result);

    result = itoa_base_s(-123, 16);
    assert(strcmp(result, "-7B") == 0);
    kfree(result);

    result = itoa_base_s(2147483647, 16); // INT_MAX
    assert(strcmp(result, "7FFFFFFF") == 0);
    kfree(result);

    result = itoa_base_s(-2147483647, 16); // INT_MIN + 1
    assert(strcmp(result, "-7FFFFFFF") == 0);
    kfree(result);
}

// Tests pour la fonction uitoa_base_s
void test_uitoa_base_s() {
    char *result;

    result = uitoa_base_s(123, 16);
    assert(strcmp(result, "7B") == 0);
    kfree(result);

    result = uitoa_base_s(0, 2);
    assert(strcmp(result, "0") == 0);
    kfree(result);

    result = uitoa_base_s(UINT_MAX, 16);    // UINT_MAX
    assert(strcmp(result, "FFFFFFFF") == 0); // UINT_MAX in hexadecimal
    kfree(result);
}

// Tests pour la fonction ftoa
void test_ftoa() {
    char *result;

    result = ftoa(123.456, 2);
    assert(strcmp(result, "123.45") == 0);
    kfree(result);

    result = ftoa(-123.456, 3);
    assert(strcmp(result, "-123.456") == 0);
    kfree(result);

    result = ftoa(0.0, 1);
    assert(strcmp(result, "0.0") == 0);
    kfree(result);

	//TODO: Fix ftoa
    // result = ftoa(1.23456789, 8);
    // assert(strcmp(result, "1.23456789") == 0);
    // kfree(result);

    // result = ftoa(-1.23456789, 8);
    // assert(strcmp(result, "-1.23456789") == 0);
    // kfree(result);

    result = ftoa(42.0, 0); // No decimal part
    assert(strcmp(result, "42") == 0);
    kfree(result);
}

// Tests pour la fonction htoa
void test_htoa() {
    char *result;

    result = htoa(123);
    assert(strcmp(result, "7B") == 0);
    kfree(result);

    result = htoa(0);
    assert(strcmp(result, "0") == 0);
    kfree(result);

    result = htoa(255);
    assert(strcmp(result, "FF") == 0);
    kfree(result);
}

// Tests pour la fonction btoa
void test_btoa() {
    char *result;

    result = btoa(123);
    assert(strcmp(result, "1111011") == 0);
    kfree(result);

    result = btoa(0);
    assert(strcmp(result, "0") == 0);
    kfree(result);

    result = btoa(255);
    assert(strcmp(result, "11111111") == 0);
    kfree(result);
}

// Tests pour la fonction otoa
void test_otoa() {
    char *result;

    result = otoa(123);
    assert(strcmp(result, "173") == 0);
    kfree(result);

    result = otoa(0);
    assert(strcmp(result, "0") == 0);
    kfree(result);

    result = otoa(255);
    assert(strcmp(result, "377") == 0);
    kfree(result);
}

// Tests pour la fonction atof
void test_atof() {
    assert(fabs(atof("123.456") - 123.456) < 0.0001);
    assert(fabs(atof("-123.456") - (-123.456)) < 0.0001);
    assert(fabs(atof("0.123") - 0.123) < 0.0001);
    assert(fabs(atof(".5") - 0.5) < 0.0001);    // No leading digit
    assert(fabs(atof("-.5") - (-0.5)) < 0.0001); // No leading digit with sign
    assert(fabs(atof("1.23456789") - 1.23456789) < 0.0001);
    assert(fabs(atof("-1.23456789") - (-1.23456789)) < 0.0001);
    assert(fabs(atof("1e3") - 1000.0) < 0.0001); // Scientific notation
    assert(fabs(atof("-1e3") + 1000.0) < 0.0001); // Scientific notation with sign
}

int workflow_hephaistos_convert(void) {
    test_atoi();
    test_itoa();
    test_uitoa();
    test_itoa_base();
    test_uitoa_base();
    test_atoi_base_s();
    test_itoa_s();
    test_uitoa_s();
    test_itoa_base_s();
    test_uitoa_base_s();
    test_ftoa();
    test_htoa();
    test_btoa();
    test_otoa();
    test_atof();

    return (0);
}