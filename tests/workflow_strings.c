/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:41:26 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/14 18:54:11 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hephaistos.h>
#include <charon.h>

void test_strtrtc() {
    char *result = strtrtc("Hello, world!", ',');
    assert(strcmp(result, "Hello") == 0);
    kfree(result);
}

void test_strclr() {
    char str[] = "Hello, world!";
    char *result = strclr(str, str);
    assert(strcmp(result, "") == 0);
}

void test_strcpy() {
    char dest[20];
    strcpy(dest, "Hello, world!");
    assert(strcmp(dest, "Hello, world!") == 0);
}

void test_strncpy() {
    char dest[20];
    strncpy(dest, "Hello, world!", 5);
    assert(strncmp(dest, "Hello", 5) == 0);
}

void test_strcat() {
    char dest[20] = "Hello";
    strcat(dest, ", world!");
    assert(strcmp(dest, "Hello, world!") == 0);
}

void test_strjoin() {
    char *result = strjoin("Hello", ", world!");
    assert(strcmp(result, "Hello, world!") == 0);
    kfree(result);
}

void test_strchr() {
    char *result = strchr("Hello, world!", ',');
    assert(strcmp(result, ", world!") == 0);
}

void test_strrchr() {
    char *result = strrchr("Hello, world!", 'o');
    assert(strcmp(result, "orld!") == 0);
}

void test_strdup() {
    char *result = strdup("Hello, world!");
    assert(strcmp(result, "Hello, world!") == 0);
    kfree(result);
}

void test_strndup() {
    char *result = strndup("Hello, world!", 5);
    assert(strncmp(result, "Hello", 5) == 0);
    kfree(result);
}

void test_strtrim() {
    char *result = strtrim(" Hello, world! ");
    assert(strcmp(result, "Hello, world!") == 0);
    kfree(result);
}

void test_strsub() {
    char *result = strsub("Hello, world!", 7, 5);
    assert(strcmp(result, "world") == 0);
    kfree(result);
}

void test_strsplit() {
    char **result = strsplit("Hello, world!", ',');
    assert(strcmp(result[0], "Hello") == 0);
    assert(strcmp(result[1], " world!") == 0);

    // Remember to kfree each string and the array itself
    kfree(result[0]);
    kfree(result[1]);
    kfree(result);
}

void test_strtok() {
    char str[] = "Hello, world!";
    char *token = strtok(str, ",");
    assert(strcmp(token, "Hello") == 0);
    token = strtok(NULL, ",");
    assert(strcmp(token, " world!") == 0);
}

void test_strstr() {
    char *result = strstr("Hello, world!", "world");
    assert(strcmp(result, "world!") == 0);
}

void test_strpbrk() {
    char *result = strpbrk("Hello, world!", ",!");
    assert(strcmp(result, ", world!") == 0);
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

    return (0);
}