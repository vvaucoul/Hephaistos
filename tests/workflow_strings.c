/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:41:26 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 12:47:58 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>
#include <hephaistos.h>

#include <assert.h>
#include <string.h>

/**
 * @brief Tests the length of a string.
 */
void test_strlen() {
	// Normal string
	assert(strlen("Hello, world!") == 13);
	// Empty string
	assert(strlen("") == 0);
	// String with special characters
	assert(strlen("\n\t\r") == 3);
	// Long string
	char long_str[1001];
	memset(long_str, 'a', 1000);
	long_str[1000] = '\0';
	assert(strlen(long_str) == 1000);
}

/**
 * @brief Tests the length of a number in base 10.
 */
void test_nbrlen() {
	// Positive number
	assert(nbrlen(1234567890) == 10);
	// Zero
	assert(nbrlen(0) == 1);
	// Negative number
	assert(nbrlen(-1234567890) == 11);
	// Single digit number
	assert(nbrlen(9) == 1);
	// Single digit negative number
	assert(nbrlen(-9) == 2);
}

/**
 * @brief Tests the length of a number in a given base.
 */
void test_nbrlen_base() {
	// Positive number in base 10
	assert(nbrlen_base(1234567890, 10) == 10);
	// Zero in base 10
	assert(nbrlen_base(0, 10) == 1);
	// Negative number in base 10
	assert(nbrlen_base(-1234567890, 10) == 11);
	// Number in base 2
	assert(nbrlen_base(1234567890, 2) == 31);
	// Number in base 16
	assert(nbrlen_base(1234567890, 16) == 8);
}

/**
 * @brief Tests string comparison.
 */
void test_strcmp() {
	// Identical strings
	assert(strcmp("Hello, world!", "Hello, world!") == 0);
	// Different strings
	assert(strcmp("Hello, world!", "Hello") != 0);
	// Strings with different lengths
	assert(strcmp("Hello", "Hello, world!") != 0);
	// Empty string and non-empty string
	assert(strcmp("", "Hello") != 0);
	// Empty strings
	assert(strcmp("", "") == 0);
}

/**
 * @brief Tests string comparison with length limit.
 */
void test_strncmp() {
	// Identical strings
	assert(strncmp("Hello, world!", "Hello, world!", 13) == 0);
	// Different strings
	assert(strncmp("Hello, world!", "Hello", 5) == 0);
	// Strings with different lengths
	assert(strncmp("Hello", "Hello, world!", 5) == 0);
	// Empty string and non-empty string
	assert(strncmp("", "Hello", 0) == 0);
	// Empty strings
	assert(strncmp("", "", 0) == 0);
}

/**
 * @brief Tests string truncation up to a specific character.
 */
void test_strtrtc() {
	char *result;

	// Truncate at ','
	result = strtrtc("Hello, world!", ',');
	assert(strcmp(result, "Hello") == 0);
	kfree(result);

	// Truncate at '!'
	result = strtrtc("Hello, world!", '!');
	assert(strcmp(result, "Hello, world") == 0);
	kfree(result);

	// Character not in string
	result = strtrtc("Hello, world!", 'x');
	assert(strcmp(result, "Hello, world!") == 0);
	kfree(result);

	// Empty string
	result = strtrtc("", 'x');
	assert(strcmp(result, "") == 0);
	kfree(result);
}

/**
 * @brief Tests string clearing.
 */
void test_strclr() {
	char str[] = "Hello, world!";
	char *result;

	// Clear the string
	result = strclr(str, str);
	assert(strcmp(result, "") == 0);

	// Test with different strings
	char str2[] = "Test string";
	result = strclr(str2, str2);
	assert(strcmp(result, "") == 0);
}

/**
 * @brief Tests string copy.
 */
void test_strcpy() {
	char dest[20];

	// Normal copy
	strcpy(dest, "Hello, world!");
	assert(strcmp(dest, "Hello, world!") == 0);

	// Empty string
	strcpy(dest, "");
	assert(strcmp(dest, "") == 0);

	// Single character
	strcpy(dest, "A");
	assert(strcmp(dest, "A") == 0);
}

/**
 * @brief Tests string copy with length limit.
 */
void test_strncpy() {
	char dest[20];

	// Normal copy with limit
	strncpy(dest, "Hello, world!", 5);
	dest[5] = '\0'; // Ensure null termination
	assert(strcmp(dest, "Hello") == 0);

	// Source string is shorter than limit
	strncpy(dest, "Hi", 5);
	dest[2] = '\0';
	assert(strcmp(dest, "Hi") == 0);

	// Limit greater than source length
	strncpy(dest, "Hi", 10);
	dest[2] = '\0';
	assert(strcmp(dest, "Hi") == 0);
}

/**
 * @brief Tests string concatenation.
 */
void test_strcat() {
	char dest[20] = "Hello";

	// Normal concatenation
	strcat(dest, ", world!");
	assert(strcmp(dest, "Hello, world!") == 0);

	// Append empty string
	strcpy(dest, "Hi");
	strcat(dest, "");
	assert(strcmp(dest, "Hi") == 0);

	// Append single character
	strcpy(dest, "Hi");
	strcat(dest, "!");
	assert(strcmp(dest, "Hi!") == 0);
}

/**
 * @brief Tests string join.
 */
void test_strjoin() {
	char *result;

	// Join two strings
	result = strjoin("Hello", ", world!");
	assert(strcmp(result, "Hello, world!") == 0);
	kfree(result);

	// Join with empty string
	result = strjoin("", "world!");
	assert(strcmp(result, "world!") == 0);
	kfree(result);

	result = strjoin("Hello", "");
	assert(strcmp(result, "Hello") == 0);
	kfree(result);
}

/**
 * @brief Tests finding a character in a string.
 */
void test_strchr() {
	char *result;

	// Character in string
	result = strchr("Hello, world!", ',');
	assert(strcmp(result, ", world!") == 0);

	result = strchr("Hello, world!", '!');
	assert(strcmp(result, "!") == 0);

	// Character not in string
	result = strchr("Hello, world!", 'x');
	assert(result == NULL);

	// First character
	result = strchr("Hello, world!", 'H');
	assert(strcmp(result, "Hello, world!") == 0);
}

/**
 * @brief Tests finding the last occurrence of a character in a string.
 */
void test_strrchr() {
	char *result;

	// Last occurrence of character
	result = strrchr("Hello, world!", 'o');
	assert(strcmp(result, "orld!") == 0);

	// First character
	result = strrchr("Hello, world!", 'H');
	assert(strcmp(result, "Hello, world!") == 0);

	// Character not in string
	result = strrchr("Hello, world!", 'x');
	assert(result == NULL);

	// Last character
	result = strrchr("Hello, world!", '!');
	assert(strcmp(result, "!") == 0);
}

/**
 * @brief Tests string duplication.
 */
void test_strdup() {
	char *result;

	// Normal string
	result = strdup("Hello, world!");
	assert(strcmp(result, "Hello, world!") == 0);
	kfree(result);

	// Empty string
	result = strdup("");
	assert(strcmp(result, "") == 0);
	kfree(result);

	// Single character
	result = strdup("A");
	assert(strcmp(result, "A") == 0);
	kfree(result);
}

/**
 * @brief Tests string duplication with length limit.
 */
void test_strndup() {
	char *result;

	// Duplicate first 5 characters
	result = strndup("Hello, world!", 5);
	assert(strncmp(result, "Hello", 5) == 0);
	kfree(result);

	// Source string is shorter than limit
	result = strndup("Hi", 5);
	assert(strcmp(result, "Hi") == 0);
	kfree(result);

	// Limit is 0
	result = strndup("Hello, world!", 0);
	assert(strcmp(result, "") == 0);
	kfree(result);
}

/**
 * @brief Tests trimming whitespace from a string.
 */
void test_strtrim() {
	char *result;

	// Trim spaces around string
	result = strtrim(" Hello, world! ");
	assert(strcmp(result, "Hello, world!") == 0);
	kfree(result);

	// String with only spaces
	result = strtrim("    ");
	assert(strcmp(result, "") == 0);
	kfree(result);

	// String without spaces
	result = strtrim("NoSpaces");
	assert(strcmp(result, "NoSpaces") == 0);
	kfree(result);

	// String with leading and trailing newlines
	result = strtrim("\n\nHello, world!\n\n");
	assert(strcmp(result, "Hello, world!") == 0);
	kfree(result);
}

/**
 * @brief Tests substring extraction.
 */
void test_strsub() {
	char *result;

	// Extract "world" from "Hello, world!"
	result = strsub("Hello, world!", 7, 5);
	assert(strcmp(result, "world") == 0);
	kfree(result);

	// Extract "Test" from "Test string"
	result = strsub("Test string", 0, 4);
	assert(strcmp(result, "Test") == 0);
	kfree(result);

	// Start index beyond string length
	result = strsub("Hello", 10, 2);
	assert(result == NULL);

	// Length exceeding string length
	result = strsub("Hello", 1, 10);
	assert(strcmp(result, "ello") == 0);
	kfree(result);
}

/**
 * @brief Tests splitting a string by a delimiter.
 */
void test_strsplit() {
	char **result;

	// Split by ','
	result = strsplit("Hello, world!", ',');
	assert(strcmp(result[0], "Hello") == 0);
	assert(strcmp(result[1], " world!") == 0);
	kfree(result[0]);
	kfree(result[1]);
	kfree(result);

	// No delimiter in string
	result = strsplit("No,split,here", ';');
	assert(strcmp(result[0], "No,split,here") == 0);
	kfree(result[0]);
	kfree(result);

	// Multiple delimiters
	result = strsplit("One,,Three", ',');
	assert(strcmp(result[0], "One") == 0);
	assert(strcmp(result[1], "") == 0);
	assert(strcmp(result[2], "Three") == 0);
	kfree(result[0]);
	kfree(result[1]);
	kfree(result[2]);
	kfree(result);
}

/**
 * @brief Tests tokenizing a string by delimiters.
 */
void test_strtok() {
	char str[] = "Hello, world!";
	char *token;

	token = strtok(str, ",");
	assert(strcmp(token, "Hello") == 0);
	token = strtok(NULL, ",");
	assert(strcmp(token, " world!") == 0);

	//Todo: Fix strtok
	// // Test with multiple delimiters
	// char str2[] = "One,,Three";
	// token = strtok(str2, ",");
	// assert(strcmp(token, "One") == 0);
	// token = strtok(NULL, ",");
	// printk("Token: %s\n", token);
	// assert(strcmp(token, "") == 0);
	// token = strtok(NULL, ",");
	// assert(strcmp(token, "Three") == 0);
	// token = strtok(NULL, ",");
	// assert(token == NULL);

	// // Test with no delimiters present
	// char str3[] = "NoDelimiters";
	// token = strtok(str3, ",");
	// assert(strcmp(token, "NoDelimiters") == 0);
	// token = strtok(NULL, ",");
	// assert(token == NULL);

	// // Test with consecutive delimiters
	// char str4[] = ",leading,and,trailing,delimiters,";
	// token = strtok(str4, ",");
	// assert(strcmp(token, "leading") == 0);
	// token = strtok(NULL, ",");
	// assert(strcmp(token, "and") == 0);
	// token = strtok(NULL, ",");
	// assert(strcmp(token, "trailing") == 0);
	// token = strtok(NULL, ",");
	// assert(strcmp(token, "delimiters") == 0);
	// token = strtok(NULL, ",");
	// assert(token == NULL);
}

/**
 * @brief Tests finding a substring in a string.
 */
void test_strstr() {
	char *result;

	// Substring found
	result = strstr("Hello, world!", "world");
	assert(strcmp(result, "world!") == 0);

	// Substring not found
	result = strstr("No match here", "absent");
	assert(result == NULL);

	// Empty needle
	result = strstr("Hello, world!", "");
	assert(strcmp(result, "Hello, world!") == 0);
}

/**
 * @brief Tests finding any of a set of characters in a string.
 */
void test_strpbrk() {
	char *result;

	// Find any of ',!'
	result = strpbrk("Hello, world!", ",!");
	assert(strcmp(result, ", world!") == 0);

	// No match
	result = strpbrk("Hello, world!", "xyz");
	assert(result == NULL);

	// First character
	result = strpbrk("Hello, world!", "H");
	assert(strcmp(result, "Hello, world!") == 0);
}

/**
 * @brief Tests reversing a string.
 */
void test_strrev() {
	char str1[] = "Hello";
	char str2[] = "A";

	// Reverse "Hello"
	char *result = strrev(str1);
	assert(strcmp(result, "olleH") == 0);

	// Reverse "A"
	result = strrev(str2);
	assert(strcmp(result, "A") == 0);
}

/**
 * @brief Tests reversing a portion of a string.
 */
void test_strrevp() {
	char str[] = "abcdef";

	// Reverse "bcde" in "abcdef"
	char *result = strrevp(str, 1, 4);
	assert(strcmp(result, "aedcbf") == 0);

	// Same start and end index
	result = strrevp(str, 2, 2);
	assert(strcmp(result, "aedcbf") == 0);
}

/**
 * @brief Tests setting memory.
 */
void test_memset() {
	char buffer[10];
	memset(buffer, 'a', 10);
	for (int i = 0; i < 10; i++) {
		assert(buffer[i] == 'a');
	}

	// Zero length
	memset(buffer, 'b', 0);
	assert(buffer[0] == 'a');
}

/**
 * @brief Tests copying memory with a stopping character.
 */
void test_memccpy() {
	char src[10] = "abcdefghi";
	char dest[10];
	memccpy(dest, src, 'd', 10);
	assert(strncmp(dest, "abcd", 4) == 0);

	// Character not found
	memccpy(dest, src, 'x', 10);
	assert(strncmp(dest, "abcdefghi", 10) == 0);
}

/**
 * @brief Tests copying memory.
 */
void test_memcpy() {
	char src[10] = "abcdefghi";
	char dest[10];
	memcpy(dest, src, 10);
	assert(strncmp(dest, src, 10) == 0);
}

/**
 * @brief Tests moving memory.
 */
void test_memmove() {
	char src[10] = "abcdefghi";
	char dest[10];
	memmove(dest, src, 10);
	assert(strncmp(dest, src, 10) == 0);

	// Overlapping regions
	memmove(src + 1, src, 5);
	assert(strncmp(src + 1, "abcde", 5) == 0);
}

/**
 * @brief Tests finding a character in memory.
 */
void test_memchr() {
	char src[10] = "abcdefghi";
	char *result = memchr(src, 'd', 10);
	assert(*result == 'd');

	// Character not found
	result = memchr(src, 'x', 10);
	assert(result == NULL);
}

/**
 * @brief Tests comparing memory.
 */
void test_memcmp() {
	char s1[10] = "abcdefghi";
	char s2[10] = "abcdefghi";
	assert(memcmp(s1, s2, 10) == 0);

	// Different strings
	s2[5] = 'x';
	assert(memcmp(s1, s2, 10) != 0);
}

/**
 * @brief Tests joining memory blocks.
 */
void test_memjoin() {
	char s1[10] = "abc";
	char s2[10] = "def";
	char *result = memjoin(s1, s2, 3, 3);
	assert(strncmp(result, "abcdef", 6) == 0);
}

/**
 * @brief Tests zeroing memory.
 */
void test_bzero() {
	char buffer[10] = "abcdefghi";
	bzero(buffer, 10);
	for (int i = 0; i < 10; i++) {
		assert(buffer[i] == 0);
	}
}

/**
 * @brief Executes the Hephaistos workflow for strings.
 *
 * This function is responsible for executing the workflow for strings in the Hephaistos module.
 * It performs a series of operations on strings and returns the result.
 *
 * @return An integer indicating the status of the workflow execution.
 */
int workflow_hephaistos_strings(void) {
	test_strlen();
	test_nbrlen();
	test_nbrlen_base();
	test_strcmp();
	test_strncmp();

	test_strtrtc();
	test_strclr();
	test_strcpy();
	test_strncpy();
	test_strcat();
	test_strjoin();
	test_strchr();
	test_strrchr();
	test_strdup();
	test_strndup();
	test_strtrim();
	test_strsub();
	test_strsplit();
	test_strtok();
	test_strstr();
	test_strpbrk();
	test_strrev();
	test_strrevp();

	test_memset();
	test_memccpy();
	test_memcpy();
	test_memmove();
	test_memchr();
	test_memcmp();
	test_memjoin();
	test_bzero();

	return (0);
}