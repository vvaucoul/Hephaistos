/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:41:26 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/27 19:07:50 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>
#include <hephaistos.h>

#include <assert.h>
#include <string.h>

void test_strtrtc() {
	char *result;

	result = strtrtc("Hello, world!", ',');
	assert(strcmp(result, "Hello") == 0);
	kfree(result);

	result = strtrtc("Hello, world!", '!');
	assert(strcmp(result, "Hello, world") == 0);
	kfree(result);

	result = strtrtc("Hello, world!", 'x'); // Character not in string
	assert(strcmp(result, "Hello, world!") == 0);
	kfree(result);
}

void test_strclr() {
	char str[] = "Hello, world!";
	char *result;

	result = strclr(str, str);
	assert(strcmp(result, "") == 0);

	// Test with different strings
	char str2[] = "Test string";
	result = strclr(str2, str2);
	assert(strcmp(result, "") == 0);
}

void test_strcpy() {
	char dest[20];

	strcpy(dest, "Hello, world!");
	assert(strcmp(dest, "Hello, world!") == 0);

	strcpy(dest, "");
	assert(strcmp(dest, "") == 0);
}

void test_strncpy() {
	char dest[20];

	strncpy(dest, "Hello, world!", 5);
	dest[5] = '\0'; // Ensure null termination
	assert(strcmp(dest, "Hello") == 0);

	strncpy(dest, "Hi", 5);
	dest[2] = '\0';
	assert(strcmp(dest, "Hi") == 0);
}

void test_strcat() {
	char dest[20] = "Hello";

	strcat(dest, ", world!");
	assert(strcmp(dest, "Hello, world!") == 0);

	strcpy(dest, "Hi");
	strcat(dest, "");
	assert(strcmp(dest, "Hi") == 0);
}

void test_strjoin() {
	char *result;

	result = strjoin("Hello", ", world!");
	assert(strcmp(result, "Hello, world!") == 0);
	kfree(result);

	result = strjoin("", "world!");
	assert(strcmp(result, "world!") == 0);
	kfree(result);

	result = strjoin("Hello", "");
	assert(strcmp(result, "Hello") == 0);
	kfree(result);
}

void test_strchr() {
	char *result;

	result = strchr("Hello, world!", ',');
	assert(strcmp(result, ", world!") == 0);

	result = strchr("Hello, world!", '!');
	assert(strcmp(result, "!") == 0);

	result = strchr("Hello, world!", 'x'); // Character not in string
	assert(result == NULL);
}

void test_strrchr() {
	char *result;

	result = strrchr("Hello, world!", 'o');
	assert(strcmp(result, "orld!") == 0);

	result = strrchr("Hello, world!", 'H');
	assert(strcmp(result, "Hello, world!") == 0);

	result = strrchr("Hello, world!", 'x'); // Character not in string
	assert(result == NULL);
}

void test_strdup() {
	char *result;

	result = strdup("Hello, world!");
	assert(strcmp(result, "Hello, world!") == 0);
	kfree(result);

	result = strdup("");
	assert(strcmp(result, "") == 0);
	kfree(result);
}

void test_strndup() {
	char *result;

	result = strndup("Hello, world!", 5);
	assert(strncmp(result, "Hello", 5) == 0);
	kfree(result);

	result = strndup("Hi", 5); // Source string is shorter than n
	assert(strcmp(result, "Hi") == 0);
	kfree(result);
}

void test_strtrim() {
	char *result;

	result = strtrim(" Hello, world! ");
	assert(strcmp(result, "Hello, world!") == 0);
	kfree(result);

	result = strtrim("    ");
	assert(strcmp(result, "") == 0);
	kfree(result);

	result = strtrim("NoSpaces");
	assert(strcmp(result, "NoSpaces") == 0);
	kfree(result);
}

void test_strsub() {
	char *result;

	result = strsub("Hello, world!", 7, 5);
	assert(strcmp(result, "world") == 0);
	kfree(result);

	result = strsub("Test string", 0, 4);
	assert(strcmp(result, "Test") == 0);
	kfree(result);
}

void test_strsplit() {
	char **result;

	result = strsplit("Hello, world!", ',');
	assert(strcmp(result[0], "Hello") == 0);
	assert(strcmp(result[1], " world!") == 0);
	kfree(result[0]);
	kfree(result[1]);
	kfree(result);

	result = strsplit("No,split,here", ';');
	assert(strcmp(result[0], "No,split,here") == 0);
	kfree(result[0]);
	kfree(result);
}

void test_strtok() {
	char str[] = "Hello, world!";
	char *token;

	token = strtok(str, ",");
	assert(strcmp(token, "Hello") == 0);
	token = strtok(NULL, ",");
	assert(strcmp(token, " world!") == 0);
}

void test_strstr() {
	char *result;

	result = strstr("Hello, world!", "world");
	assert(strcmp(result, "world!") == 0);

	result = strstr("No match here", "absent");
	assert(result == NULL);
}

void test_strpbrk() {
	char *result;

	result = strpbrk("Hello, world!", ",!");
	assert(strcmp(result, ", world!") == 0);

	result = strpbrk("Hello, world!", "xyz");
	assert(result == NULL);
}

void test_strrev() {
	char str1[] = "Hello";
	char str2[] = "A";

	char *result = strrev(str1);
	assert(strcmp(result, "olleH") == 0);

	result = strrev(str2);
	assert(strcmp(result, "A") == 0);
}

void test_strrevp() {
	char str[] = "abcdef";

	char *result = strrevp(str, 1, 4);
	assert(strcmp(result, "aedcbf") == 0);
}

int workflow_hephaistos_strings(void) {
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

	printk("All tests passed successfully.\n");

	return (0);
}