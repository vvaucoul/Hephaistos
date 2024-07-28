/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:59:37 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 10:57:25 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>

#include <assert.h>
#include <memory.h>
#include <string.h>

void test_memset() {
	char buffer[10];
	memset(buffer, 'a', 10);
	for (int i = 0; i < 10; i++) {
		assert(buffer[i] == 'a');
	}
}

void test_memccpy() {
	char src[10] = "abcdefghi";
	char dest[10];
	memccpy(dest, src, 'd', 10);
	assert(strncmp(dest, "abcd", 4) == 0);
}

void test_memcpy() {
	char src[10] = "abcdefghi";
	char dest[10];
	memcpy(dest, src, 10);
	assert(strncmp(dest, src, 10) == 0);
}

void test_memmove() {
	char src[10] = "abcdefghi";
	char dest[10];
	memmove(dest, src, 10);
	assert(strncmp(dest, src, 10) == 0);
}

void test_memchr() {
	char src[10] = "abcdefghi";
	char *result = memchr(src, 'd', 10);
	assert(*result == 'd');
}

void test_memcmp() {
	char s1[10] = "abcdefghi";
	char s2[10] = "abcdefghi";
	assert(memcmp(s1, s2, 10) == 0);
}

void test_memjoin() {
	char s1[10] = "abc";
	char s2[10] = "def";
	char *result = memjoin(s1, s2, 3, 3);
	assert(strncmp(result, "abcdef", 6) == 0);
}

void test_bzero() {
	char buffer[10] = "abcdefghi";
	bzero(buffer, 10);
	for (int i = 0; i < 10; i++) {
		assert(buffer[i] == 0);
	}
}

int workflow_hephaistos_memory(void) {
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