/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:55:48 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 12:42:56 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include <charon.h>
#include <ctype.h>
#include <macros.h>

/**
 * @file string.c
 * @brief Implementation of string functions.
 *
 * This file contains the implementation of string functions used in the Hephaistos project.
 * The USE_ASM_STRING_FUNCTIONS macro controls whether assembly language or C language string functions are used.
 */
#if USE_ASM_STRING_FUNCTIONS == 0
/**
 * @brief Calculate the number of digits in a signed integer.
 *
 * This function calculates the number of digits in a signed integer.
 *
 * @param nbr The signed integer for which to calculate the number of digits.
 * @return The number of digits in the signed integer.
 */
uint32_t nbrlen(int32_t nbr) {
	uint32_t len = 0;
	if (nbr == 0) {
		return (1);
	}
	if (nbr < 0) {
		len++;
		nbr = -nbr;
	}
	while (nbr > 0) {
		nbr /= 10;
		len++;
	}
	return (len);
}

/**
 * @brief Calculate the length of an unsigned 32-bit integer when converted to a string.
 *
 * This function calculates the number of characters required to represent an unsigned 32-bit integer
 * when converted to a string. It does not include the null-terminating character.
 *
 * @param nbr The unsigned 32-bit integer to calculate the length for.
 * @return The length of the unsigned 32-bit integer when converted to a string.
 */
uint32_t unbrlen(uint32_t nbr) {
	uint32_t len = 0;
	if (nbr == 0) {
		return (1);
	}
	while (nbr > 0) {
		nbr /= 10;
		len++;
	}
	return (len);
}

/**
 * Calculates the length of a null-terminated string.
 *
 * @param str The input string.
 * @return The length of the string.
 */
uint32_t strlen(const char *str) {
	uint32_t len = 0;
	while (str[len]) {
		len++;
	}
	return (len);
}

/**
 * @brief Calculates the number of digits in an integer when represented in a given base.
 *
 * This function takes an integer and a base as input and returns the number of digits required to represent the integer in the given base.
 *
 * @param nbr The integer for which the number of digits needs to be calculated.
 * @param base The base in which the integer is represented.
 *
 * @return The number of digits required to represent the integer in the given base.
 */
uint32_t nbrlen_base(const int32_t nbr, const uint8_t base) {
	uint32_t len = 0;
	int32_t n = nbr;

	if (n == 0) {
		return (1);
	}
	if (n < 0) {
		len++;
		n = -n;
	}
	while (n > 0) {
		n /= base;
		len++;
	}
	return (len);
}

/**
 * Calculates the length of an unsigned integer when represented in a given base.
 *
 * @param nbr The unsigned integer for which to calculate the length.
 * @param base The base in which the integer is represented.
 * @return The length of the integer when represented in the given base.
 */
uint32_t unbrlen_base(const uint32_t nbr, const uint8_t base) {
	uint32_t len = 0;
	int32_t n = nbr;

	if (nbr == 0) {
		return (1);
	}
	while (n > 0) {
		n /= base;
		len++;
	}
	return (len);
}

/**
 * @brief Compares two strings.
 *
 * This function compares the string pointed to by `s1` to the string pointed to by `s2`.
 * The comparison is done lexicographically, character by character.
 *
 * @param s1 Pointer to the first string to be compared.
 * @param s2 Pointer to the second string to be compared.
 *
 * @return An integer less than, equal to, or greater than zero if `s1` is found, respectively, to be less than, to match, or be greater than `s2`.
 */
int32_t strcmp(const char *s1, const char *s2) {
	if (s1 == NULL || s2 == NULL) {
		return -1;
	}

	size_t i = 0;
	while (s1[i] && s2[i]) {
		if (s1[i] != s2[i]) {
			return (unsigned char)s1[i] - (unsigned char)s2[i];
		}
		i++;
	}

	return (unsigned char)s1[i] - (unsigned char)s2[i];
}

/**
 * @brief Compares at most n characters of two strings.
 *
 * This function compares the first n characters of the strings s1 and s2. It returns an integer less than, equal to, or greater than zero if s1 is found, respectively, to be less than, to match, or be greater than s2.
 *
 * @param s1 Pointer to the first string to be compared.
 * @param s2 Pointer to the second string to be compared.
 * @param n Number of characters to compare.
 * @return An integer less than, equal to, or greater than zero if s1 is found, respectively, to be less than, to match, or be greater than s2.
 */
int32_t strncmp(const char *s1, const char *s2, uint32_t n) {
	if (s1 == NULL || s2 == NULL || n == 0) {
		return 0;
	}

	size_t i = 0;
	while (i < n) {
		if (s1[i] == '\0' || s2[i] == '\0') {
			break;
		}
		if (s1[i] != s2[i]) {
			return (unsigned char)s1[i] - (unsigned char)s2[i];
		}
		i++;
	}

	if (i < n) {
		return (unsigned char)s1[i] - (unsigned char)s2[i];
	}

	return 0;
}
#endif

/**
 * @brief Copies the C string pointed by source into the array pointed by destination, including the null character.
 *
 * @param destination Pointer to the destination array where the content is to be copied.
 * @param source      C string to be copied.
 *
 * @return Pointer to the destination array.
 */
char *strcpy(char *dest, const char *src) {
	if (dest == NULL || src == NULL) {
		return (NULL);
	}

	uint32_t i = 0;
	while (src[i]) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * @brief Copies a specified number of characters from a source string to a destination string.
 *
 * The strncpy function copies a specified number of characters from the source string to the destination string.
 * If the length of the source string is less than the specified number of characters, the remaining characters in the destination string are filled with null characters.
 *
 * @param dest The pointer to the destination string where the characters will be copied.
 * @param src The pointer to the source string from where the characters will be copied.
 * @param n The maximum number of characters to be copied.
 *
 * @return A pointer to the destination string.
 */
char *strncpy(char *dest, const char *src, uint32_t n) {
	if (dest == NULL || src == NULL) {
		return (NULL);
	}

	uint32_t i = 0;
	while (src[i] && i < n) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * Truncates a string to the first occurrence of a specified character.
 *
 * @param str The string to be truncated.
 * @param c The character to truncate the string at.
 * @return The truncated string.
 */
char *strtrtc(const char *str, const char c) {
	if (str == NULL) {
		return (NULL);
	}

	char *new_str = kmalloc(sizeof(char) * strlen(str) + 1);
	if (new_str == NULL) {
		return (NULL);
	}

	bzero(new_str, strlen(str) + 1);

	uint32_t i = 0;
	while (str[i] && str[i] != c) {
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/**
 * @brief Clears the given string by setting all its characters to null.
 *
 * @param new_str The cleared string.
 * @param str The string to be cleared.
 * @return The cleared string.
 */
char *strclr(char *new_str, char *str) {
	if (str == NULL) {
		return (NULL);
	}
	bzero(new_str, strlen(new_str));

	uint32_t i = 0;
	/* Skip all firsts spaces */
	while (str[i] && str[i] == ' ') {
		i++;
	}

	uint32_t j = 0;

	/* Skip all spaces in the string */
	while (str[i]) {
		if (str[i] == ' ') {
			while (str[i] && str[i] == ' ')
				i++;
			if (str[i] == '\0')
				break;
			new_str[j] = ' ';
			j++;
		}
		new_str[j] = str[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

/**
 * @brief Concatenates two strings.
 *
 * The strcat function appends a copy of the source string to the destination string.
 * The destination string must have enough space to hold the combined result.
 *
 * @param dest The destination string.
 * @param src The source string.
 * @return A pointer to the resulting string.
 */
char *strcat(char *dest, const char *src) {
	if (dest == NULL || src == NULL) {
		return (NULL);
	}

	uint32_t i = 0;
	uint32_t j = 0;
	while (dest[i]) {
		i++;
	}
	while (src[j]) {
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * Joins two strings together.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @return A pointer to the joined string.
 */
char *strjoin(char *s1, char *s2) {
	if (s1 == NULL || s2 == NULL) {
		return (NULL);
	}

	char *new_str = kmalloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	if (new_str == NULL) {
		return (NULL);
	}

	bzero(new_str, strlen(s1) + strlen(s2) + 1);

	strcpy(new_str, s1);
	strcat(new_str, s2);
	return (new_str);
}

/**
 * The strchr function searches for the first occurrence of the character c
 * (an unsigned char) in the string pointed to by the argument str.
 *
 * @param str The string to be searched.
 * @param c The character to be located.
 * @return A pointer to the first occurrence of the character c in the string str,
 *         or NULL if the character is not found.
 */
char *strchr(const char *s, int c) {
	if (s == NULL) {
		return (NULL);
	}

	uint32_t i = 0;
	while (s[i]) {
		if (s[i] == c) {
			return ((char *)&s[i]);
		}
		i++;
	}
	return (NULL);
}

/**
 * @brief Searches for the last occurrence of a character in a string.
 *
 * @param s The string to search in.
 * @param c The character to search for.
 * @return A pointer to the last occurrence of the character in the string, or NULL if the character is not found.
 */
char *strrchr(const char *s, int c) {
	if (s == NULL) {
		return (NULL);
	}

	// Pointer to the last occurrence of c
	char *last_occurrence = NULL;

	// Traverse the string until the null character
	while (*s != '\0') {
		if (*s == c) {
			last_occurrence = (char *)s;
		}
		s++;
	}

	// Check if the null character is c
	if (*s == c) {
		return (char *)s;
	}

	return last_occurrence;
}

/**
 * @brief The strdup() function returns a pointer to a new string which is a duplicate of the string s.
 * The memory for the new string is obtained with malloc(3), and can be freed with free(3).
 *
 * @param s The string to be duplicated.
 * @return A pointer to the duplicated string, or NULL if insufficient memory was available.
 */
char *strdup(const char *s) {
	if (s == NULL) {
		return (NULL);
	}

	char *new_str = kmalloc(sizeof(char) * strlen(s) + 1);
	if (new_str == NULL) {
		return (NULL);
	}

	bzero(new_str, strlen(s) + 1);

	strcpy(new_str, s);
	return (new_str);
}

/**
 * @brief Duplicate a portion of a string.
 *
 * The strndup function duplicates the first n characters of the string s into a new string.
 * The new string is null-terminated.
 *
 * @param s The string to be duplicated.
 * @param n The maximum number of characters to be duplicated.
 * @return A pointer to the newly allocated string, or NULL if an error occurred.
 */
char *strndup(const char *s, uint32_t n) {
	if (s == NULL) {
		return (NULL);
	}

	char *new_str = kmalloc(sizeof(char) * n + 1);
	if (new_str == NULL) {
		return (NULL);
	}

	bzero(new_str, n + 1);

	strncpy(new_str, s, n);
	return (new_str);
}

/**
 * @brief Removes leading and trailing whitespace characters from a string.
 *
 * This function removes any leading and trailing whitespace characters (spaces, tabs, newlines, etc.) from the given string.
 *
 * @param str The string to be trimmed.
 * @return The trimmed string.
 */
char *strtrim(char const *s) {
	if (s == NULL) {
		return NULL;
	}

	// Find the start of the trimmed string
	while (isspace((unsigned char)*s)) {
		s++;
	}

	// Find the end of the trimmed string
	const char *end = s + strlen(s) - 1;
	while (end > s && isspace((unsigned char)*end)) {
		end--;
	}

	// Calculate the length of the trimmed string
	size_t len = end - s + 1;

	// Allocate memory for the new trimmed string
	char *new_str = kmalloc(len + 1);
	if (new_str == NULL) {
		return NULL;
	}

	// Copy the trimmed string to the new memory
	strncpy(new_str, s, len);
	new_str[len] = '\0';

	return new_str;
}

/**
 * @brief Extracts a substring from a given string.
 *
 * This function takes a string `s` and extracts a substring starting from the `start` index
 * with a length of `len`. The extracted substring is returned as a new dynamically allocated
 * string.
 *
 * @param s The input string from which the substring is extracted.
 * @param start The starting index of the substring.
 * @param len The length of the substring.
 * @return The extracted substring as a dynamically allocated string.
 */
char *strsub(char const *s, unsigned int start, uint32_t len) {
	if (s == NULL) {
		return NULL;
	}

	uint32_t str_len = strlen(s);
	if (start >= str_len) {
		return NULL;
	}

	// Adjust length if it goes beyond the end of the string
	if (start + len > str_len) {
		len = str_len - start;
	}

	char *new_str = kmalloc(sizeof(char) * (len + 1));
	if (new_str == NULL) {
		return NULL;
	}

	strncpy(new_str, s + start, len);
	new_str[len] = '\0';

	return new_str;
}

/**
 * @brief Splits a string into an array of substrings based on a delimiter.
 *
 * This function takes a string `s` and a delimiter `c` and splits the string into an array of substrings.
 * The substrings are separated by the delimiter `c`. The function returns a pointer to an array of strings.
 *
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return A pointer to an array of strings.
 */
char **strsplit(char const *s, char c) {
	if (s == NULL) {
		return (NULL);
	}

	char *new_str = strtrim(s);
	if (new_str == NULL) {
		return (NULL);
	}

	uint32_t i = 0;
	uint32_t j = 0;
	uint32_t k = 0;
	uint32_t nb_words = 0;

	while (new_str[i]) {
		if (new_str[i] == c) {
			nb_words++;
		}
		i++;
	}
	nb_words++;

	char **tab = kmalloc(sizeof(char *) * (nb_words + 1));
	if (tab == NULL) {
		return (NULL);
	}

	i = 0;
	while (new_str[i]) {
		if (new_str[i] == c) {
			tab[j] = strsub(new_str, k, i - k);
			j++;
			k = i + 1;
		}
		i++;
	}
	tab[j] = strsub(new_str, k, i - k);
	tab[j + 1] = NULL;
	kfree(new_str);
	return (tab);
}

static int strspn(const char *s, const char *accept) {
	if (s == NULL || accept == NULL) {
		return 0;
	}

	const char *p = s;
	while (*p) {
		const char *a = accept;
		while (*a && *p != *a) {
			a++;
		}
		if (*a == '\0') {
			break;
		}
		p++;
	}
	return p - s;
}

/**
 * @brief Searches a string for any of a set of characters.
 *
 * The strpbrk() function searches the string pointed to by 'str' for any of the characters in the string 'charset'.
 * It returns a pointer to the first occurrence of any character from 'charset' in 'str', or a null pointer if no match is found.
 *
 * @param str The string to be searched.
 * @param charset The set of characters to search for.
 * @return A pointer to the first occurrence of any character from 'charset' in 'str', or a null pointer if no match is found.
 */
char *strpbrk(const char *s, const char *accept) {
	if (s == NULL || accept == NULL) {
		return NULL;
	}

	while (*s) {
		const char *a = accept;
		while (*a) {
			if (*s == *a) {
				return (char *)s;
			}
			a++;
		}
		s++;
	}
	return NULL;
}

/**
 * @brief The strtok function breaks a string into a sequence of tokens.
 *
 * This function scans the string pointed to by `str` and breaks it into a sequence of tokens.
 * A token is a sequence of characters within the string that is delimited by one of the characters
 * specified in the `delim` argument. The first call to strtok should have `str` as its first argument.
 * Subsequent calls to strtok should have `NULL` as their first argument, in order to retrieve the next token.
 *
 * @param str   Pointer to the null-terminated string to be tokenized.
 * @param delim Pointer to a null-terminated string containing the delimiter characters.
 *
 * @return On the first call, the function returns a pointer to the first token found in the string.
 *         On subsequent calls, the function returns a pointer to the next token found in the string.
 *         If no more tokens are found, the function returns `NULL`.
 *
 * @note The original string passed to strtok is modified by inserting null characters ('\0')
 *       in place of the delimiter characters. The function keeps track of its position in the string
 *       between calls by saving a pointer to the next character after the last token found.
 *       This pointer is stored internally in the function and is not accessible to the calling program.
 */
char *strtok(char *str, const char *delim) {
	static char *last;
	char *token;

	if (str == NULL) {
		str = last;
	}

	if (str == NULL) {
		return NULL;
	}

	// Skip leading delimiters
	str += strspn(str, delim);
	if (*str == '\0') {
		last = NULL;
		return NULL;
	}

	// Find the end of the token
	token = str;
	str = strpbrk(token, delim);
	if (str == NULL) {
		last = NULL;
	} else {
		*str = '\0';
		last = str + 1;

		// Skip consecutive delimiters
		last += strspn(last, delim);
	}

	return token;
}

/**
 * The strstr() function finds the first occurrence of the substring needle
 * in the string haystack. The terminating null bytes ('\0') are not compared.
 *
 * @param haystack The string to be searched.
 * @param needle The substring to search for.
 * @return A pointer to the first occurrence of the substring needle in the
 *         string haystack, or NULL if the substring is not found.
 */
char *strstr(const char *haystack, const char *needle) {
	if (haystack == NULL || needle == NULL) {
		return (NULL);
	}

	uint32_t i = 0;
	uint32_t j = 0;
	while (haystack[i]) {
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

/**
 * @brief Reverses a string.
 *
 * This function reverses the given string.
 *
 * @param str The string to be reversed.
 * @return The reversed string.
 */
char *strrev(char *str) {
	if (str == NULL) {
		return (NULL);
	}

	uint32_t i = 0;
	uint32_t j = strlen(str) - 1;
	char tmp;

	while (i < j) {
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}

/**
 * @brief Reverses a portion of a string.
 *
 * This function reverses a portion of the given string.
 *
 * @param str The string to be reversed.
 * @param start The starting index of the portion to be reversed.
 * @param end The ending index of the portion to be reversed.
 * @return The reversed string.
 */
char *strrevp(char *str, uint32_t start, uint32_t end) {
	if (str == NULL) {
		return (NULL);
	}

	uint32_t i = start;
	uint32_t j = end;
	char tmp;

	while (i < j) {
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}

// ! ||--------------------------------------------------------------------------------||
// ! ||                                MEM... FUNCTIONS                                ||
// ! ||--------------------------------------------------------------------------------||

/**
 * @brief Fills the first length bytes of the memory area pointed to by ptr with the constant byte value.
 *
 * @param ptr Pointer to the memory area.
 * @param value Value to be set.
 * @param length Number of bytes to be set to the value.
 * @return Pointer to the memory area ptr.
 */
void *memset(void *ptr, int value, uint32_t length) {
	uint32_t i = 0;
	while (i < length) {
		((uint8_t *)ptr)[i] = (uint8_t)value;
		++i;
	}
	return ptr;
}

/**
 * @brief Copies bytes from src to dest, stopping when the character c is found.
 *
 * @param dest Pointer to the destination array where the content is to be copied.
 * @param src Pointer to the source of data to be copied.
 * @param c Character to stop copying at.
 * @param length Number of bytes to be copied.
 * @return Pointer to the next character in dest after c, or NULL if c was not found in the first length characters of src.
 */
void *memccpy(void *dest, const void *src, int c, uint32_t length) {
	uint32_t i = 0;
	while (i < length) {
		((uint8_t *)dest)[i] = ((uint8_t *)src)[i];
		if (((uint8_t *)src)[i] == (uint8_t)c)
			return ((uint8_t *)dest + i + 1);
		++i;
	}
	return NULL;
}

/**
 * @brief Copies length bytes from src to dest.
 *
 * @param dest Pointer to the destination array where the content is to be copied.
 * @param src Pointer to the source of data to be copied.
 * @param length Number of bytes to be copied.
 * @return Pointer to the destination array dest.
 */
void *memcpy(void *dest, const void *src, uint32_t length) {
	uint32_t i = 0;
	while (i < length) {
		((uint8_t *)dest)[i] = ((uint8_t *)src)[i];
		++i;
	}
	return dest;
}

/**
 * @brief Copies length bytes from src to dest, ensuring no overflow of dest.
 *
 * @param dest Pointer to the destination array where the content is to be copied.
 * @param dest_size Size of the destination array.
 * @param src Pointer to the source of data to be copied.
 * @param length Number of bytes to be copied.
 * @return Pointer to the destination array dest, or NULL if dest_size is smaller than length.
 */
void *memscpy(void *dest, uint32_t dest_size, const void *src, uint32_t length) {
	if (dest_size < length) {
		return NULL;
	}
	return memcpy(dest, src, length);
}

/**
 * @brief Moves length bytes from src to dest, handling overlapping memory areas.
 *
 * @param dest Pointer to the destination array where the content is to be moved.
 * @param src Pointer to the source of data to be moved.
 * @param length Number of bytes to be moved.
 * @return Pointer to the destination array dest.
 */
void *memmove(void *dest, const void *src, uint32_t length) {
	if (src < dest) {
		for (uint32_t i = length; i != 0; --i) {
			((uint8_t *)dest)[i - 1] = ((uint8_t *)src)[i - 1];
		}
	} else {
		for (uint32_t i = 0; i < length; ++i) {
			((uint8_t *)dest)[i] = ((uint8_t *)src)[i];
		}
	}
	return dest;
}

/**
 * @brief Scans the first n bytes of the memory area pointed to by s for the character c.
 *
 * @param s Pointer to the memory area.
 * @param c Character to be located.
 * @param n Number of bytes to be analyzed.
 * @return Pointer to the first occurrence of the character c in the memory area s, or NULL if the character is not found.
 */
void *memchr(const void *s, int c, uint32_t n) {
	for (uint32_t i = 0; i < n; ++i) {
		if (((uint8_t *)s)[i] == (uint8_t)c)
			return (uint8_t *)s + i;
	}
	return NULL;
}

/**
 * @brief Compares the first n bytes of the memory areas s1 and s2.
 *
 * @param s1 Pointer to the first memory area.
 * @param s2 Pointer to the second memory area.
 * @param n Number of bytes to be compared.
 * @return An integer less than, equal to, or greater than zero if the first n bytes of s1 is found to be less than, to match, or be greater than the first n bytes of s2.
 */
int memcmp(const void *s1, const void *s2, uint32_t n) {
	for (uint32_t i = 0; i < n; ++i) {
		if (((uint8_t *)s1)[i] != ((uint8_t *)s2)[i])
			return ((uint8_t *)s1)[i] - ((uint8_t *)s2)[i];
	}
	return 0;
}

/**
 * @brief Joins two memory areas s1 and s2 of size n1 and n2 respectively.
 *
 * @param s1 Pointer to the first memory area.
 * @param s2 Pointer to the second memory area.
 * @param n1 Size of the first memory area.
 * @param n2 Size of the second memory area.
 * @return Pointer to the joined memory area.
 */
void *memjoin(void *s1, const void *s2, uint32_t n1, uint32_t n2) {
	for (uint32_t i = 0; i < n2; ++i) {
		((uint8_t *)s1)[n1 + i] = ((uint8_t *)s2)[i];
	}
	return s1;
}

/**
 * @brief Fills the first len bytes of the memory area pointed to by ptr with zero.
 *
 * @param ptr Pointer to the memory area.
 * @param len Number of bytes to be set to zero.
 * @return Pointer to the memory area ptr.
 */
void *bzero(void *ptr, uint32_t len) {
	return memset(ptr, 0, len);
}

// ! ||--------------------------------------------------------------------------------||
// ! ||                      Annexe K (Bounds-checking interfaces)                     ||
// ! ||--------------------------------------------------------------------------------||

/**
 * @brief Sets a block of memory with a specified value, ensuring secure memory handling.
 *
 * The memset_s function sets the first `length` bytes of the memory block pointed to by `ptr`
 * to the specified `value`. It ensures secure memory handling by checking the size of the memory
 * block (`smax`) and the length of the operation (`length`).
 *
 * @param ptr     Pointer to the memory block to be set.
 * @param smax    The maximum size of the memory block.
 * @param value   The value to be set (converted to `unsigned char`).
 * @param length  The number of bytes to be set.
 *
 * @return If the operation is successful, `0` is returned. Otherwise, an error code is returned.
 *         Possible error codes include:
 *         - `EINVAL`: Invalid parameter(s) passed.
 *         - `ERANGE`: The operation would exceed the memory block size.
 *         - `ESNOSPC`: The operation would exceed the maximum allowed size.
 *         - `ESAFETY`: The operation would result in an unsafe memory access.
 *         - `ENOMEM`: Insufficient memory to perform the operation.
 */
errno_t memset_s(void *ptr, rsize_t smax, int value, rsize_t length) {
	if (ptr == NULL) {
		return EINVAL;
	}
	if (smax < length) {
		return ERANGE;
	}
	volatile uint8_t *p = ptr;
	while (length--) {
		*p++ = value;
	}
	return 0;
}

/**
 * @brief Copies a block of memory, handling overlapping regions safely.
 *
 * The `memmove_s` function copies `length` bytes from the memory location pointed to by `src` to the memory location pointed to by `dest`.
 * This function ensures that the copy is performed correctly even if the source and destination memory regions overlap.
 *
 * @param dest The pointer to the destination memory location.
 * @param destmax The maximum number of bytes that can be written to the destination memory location.
 * @param src The pointer to the source memory location.
 * @param length The number of bytes to be copied.
 *
 * @return If successful, zero is returned; otherwise, an error code is returned.
 */
errno_t memmove_s(void *dest, rsize_t destmax, const void *src, rsize_t length) {
	if (dest == NULL || src == NULL) {
		return EINVAL;
	}
	if (destmax < length) {
		return ERANGE;
	}
	volatile uint8_t *d = dest;
	const volatile uint8_t *s = src;
	if (d < s) {
		while (length--) {
			*d++ = *s++;
		}
	} else {
		d += length;
		s += length;
		while (length--) {
			*--d = *--s;
		}
	}
	return 0;
}

/**
 * @brief Copies a block of memory from a source location to a destination location, with bounds checking.
 *
 * This function copies the memory block specified by the `src` parameter to the memory block specified by the `dest` parameter.
 * The number of bytes to be copied is specified by the `length` parameter.
 * The `destmax` parameter specifies the maximum number of bytes that can be written to the destination buffer.
 *
 * @param dest Pointer to the destination buffer where the content is to be copied.
 * @param destmax Maximum number of bytes that can be written to the destination buffer.
 * @param src Pointer to the source of data to be copied.
 * @param length Number of bytes to copy from the source buffer to the destination buffer.
 *
 * @return If successful, zero is returned. Otherwise, an error code is returned.
 */
errno_t memcpy_s(void *dest, rsize_t destmax, const void *src, rsize_t length) {
	if (dest == NULL || src == NULL) {
		return EINVAL;
	}
	if (destmax < length) {
		return ERANGE;
	}
	volatile uint8_t *d = dest;
	const volatile uint8_t *s = src;
	while (length--) {
		*d++ = *s++;
	}
	return 0;
}

/**
 * @brief Copies bytes from source to destination until a specific character is encountered or the maximum number of bytes is reached.
 *
 * This function copies at most `length` bytes from the memory area pointed to by `src` to the memory area pointed to by `dest`,
 * stopping the copy operation if the character `c` is encountered. The copy operation will not exceed `destmax` bytes.
 *
 * @param dest Pointer to the destination memory area where the copied bytes will be stored.
 * @param destmax Maximum number of bytes that can be written to the destination memory area.
 * @param src Pointer to the source memory area from where the bytes will be copied.
 * @param c The character that, if encountered, will stop the copy operation.
 * @param length Maximum number of bytes to be copied from the source memory area.
 *
 * @return If successful, zero is returned. Otherwise, an error code is returned.
 */
errno_t memccpy_s(void *dest, rsize_t destmax, const void *src, int c, rsize_t length) {
	if (dest == NULL || src == NULL) {
		return EINVAL;
	}
	if (destmax < length) {
		return ERANGE;
	}
	volatile uint8_t *d = dest;
	const volatile uint8_t *s = src;
	while (length--) {
		*d++ = *s;
		if (*s == (uint8_t)c) {
			return 0;
		}
		s++;
	}
	return 0;
}

/**
 * Searches for the first occurrence of a specific character in the given memory block.
 *
 * @param s     Pointer to the memory block to be searched.
 * @param smax  Maximum number of bytes to be searched in the memory block.
 * @param c     Character to be searched for.
 * @param idx   Pointer to store the index of the found character.
 *
 * @return      Zero if the character is found, otherwise an error code indicating the failure.
 */
errno_t memchr_s(const void *s, rsize_t smax, int c, rsize_t *idx) {
	if (s == NULL || idx == NULL) {
		return EINVAL;
	}
	const volatile uint8_t *p = s;
	while (smax--) {
		if (*p == (uint8_t)c) {
			*idx = p - (const uint8_t *)s;
			return 0;
		}
		p++;
	}
	*idx = smax;
	return 0;
}

/**
 * Compares two memory buffers in a secure manner.
 *
 * This function compares the first `s1max` bytes of the memory block pointed to by `s1`
 * with the first `s2max` bytes of the memory block pointed to by `s2`. The result of the
 * comparison is stored in the `diff` parameter.
 *
 * @param s1     Pointer to the first memory block.
 * @param s1max  Maximum number of bytes to compare in the first memory block.
 * @param s2     Pointer to the second memory block.
 * @param s2max  Maximum number of bytes to compare in the second memory block.
 * @param diff   Pointer to an integer where the result of the comparison will be stored.
 *               The value will be 0 if the memory blocks are equal, a positive value if
 *               the first differing byte in `s1` is greater than the corresponding byte
 *               in `s2`, or a negative value if it is less.
 *
 * @return       If successful, returns 0. If an error occurs, returns an error code.
 */
errno_t memcmp_s(const void *s1, rsize_t s1max, const void *s2, rsize_t s2max, int *diff) {
	if (s1 == NULL || s2 == NULL || diff == NULL) {
		return EINVAL;
	}
	const volatile uint8_t *p1 = s1;
	const volatile uint8_t *p2 = s2;
	while (s1max-- && s2max--) {
		if (*p1 != *p2) {
			*diff = *p1 - *p2;
			return 0;
		}
		p1++;
		p2++;
	}
	*diff = s1max - s2max;
	return 0;
}

/**
 * Searches for the last occurrence of a specific character in a memory block.
 *
 * This function searches for the last occurrence of the character 'c' in the memory block 's' of size 'smax'.
 * If the character is found, the index of its location is stored in the variable pointed to by 'idx'.
 *
 * @param s     Pointer to the memory block to be searched.
 * @param smax  Maximum number of bytes to be searched in the memory block.
 * @param c     Character to be searched for.
 * @param idx   Pointer to a variable where the index of the last occurrence of 'c' will be stored.
 *
 * @return      If successful, returns zero. If an error occurs, returns an error code defined in errno.h.
 */
errno_t memrchr_s(const void *s, rsize_t smax, int c, rsize_t *idx) {
	if (s == NULL || idx == NULL) {
		return EINVAL;
	}
	const volatile uint8_t *p = s;
	while (smax--) {
		if (*p == (uint8_t)c) {
			*idx = p - (const uint8_t *)s;
		}
		p++;
	}
	*idx = smax;
	return 0;
}

/**
 * Searches for the first occurrence of the byte string 'little' within the byte string 'big'.
 *
 * @param big The pointer to the byte string to be searched.
 * @param bigmax The maximum number of bytes to be searched in 'big'.
 * @param little The pointer to the byte string to search for.
 * @param littlemax The maximum number of bytes to be searched in 'little'.
 * @param result A pointer to the location where the pointer to the first occurrence of 'little' in 'big' will be stored.
 *               If 'result' is NULL, the function will only determine if 'little' is present in 'big'.
 *
 * @return If 'result' is not NULL and 'little' is found in 'big', the function returns zero and sets 'result' to the location of 'little' in 'big'.
 *         If 'result' is NULL and 'little' is found in 'big', the function returns zero.
 *         If 'result' is not NULL and 'little' is not found in 'big', the function returns a non-zero error code and sets 'result' to NULL.
 *         If 'result' is NULL and 'little' is not found in 'big', the function returns a non-zero error code.
 */
errno_t memmem_s(const void *big, rsize_t bigmax, const void *little, __unused__ rsize_t littlemax, void **result) {
	if (big == NULL || little == NULL || result == NULL) {
		return EINVAL;
	}
	const volatile uint8_t *b = big;
	const volatile uint8_t *l = little;
	while (bigmax--) {
		if (*b == *l) {
			*result = (void *)b;
			return 0;
		}
		b++;
	}
	*result = NULL;
	return 0;
}

/**
 * Moves a block of memory upwards, safely checking for buffer overflows.
 *
 * This function copies the contents of the memory block pointed to by 'src' to the memory block pointed to by 'dest',
 * moving the memory upwards. The number of bytes to be copied is specified by 'length'.
 *
 * The function performs a runtime-constrained check to ensure that the operation does not result in a buffer overflow.
 * The size of the destination buffer is specified by 'destmax'.
 *
 * @param dest     Pointer to the destination memory block.
 * @param destmax  Maximum number of bytes that can be written to the destination buffer.
 * @param src      Pointer to the source memory block.
 * @param length   Number of bytes to be copied.
 *
 * @return If successful, zero is returned. Otherwise, an error code indicating the cause of failure is returned.
 */
errno_t memmoveup_s(void *dest, rsize_t destmax, const void *src, rsize_t length) {
	if (dest == NULL || src == NULL) {
		return EINVAL;
	}
	if (destmax < length) {
		return ERANGE;
	}
	volatile uint8_t *d = dest;
	const volatile uint8_t *s = src;
	d += length;
	s += length;
	while (length--) {
		*--d = *--s;
	}
	return 0;
}

/**
 * Moves a block of memory down, overlapping the destination and source regions.
 *
 * This function moves the memory block pointed to by `src` to the memory block
 * pointed to by `dest`, while handling overlapping regions correctly. The `length`
 * parameter specifies the number of bytes to move.
 *
 * @param dest The pointer to the destination memory block.
 * @param destmax The maximum number of bytes that can be written to the destination block.
 * @param src The pointer to the source memory block.
 * @param length The number of bytes to move.
 * @return If successful, returns zero. Otherwise, returns an error code indicating the cause of failure.
 */
errno_t memmovedown_s(void *dest, rsize_t destmax, const void *src, rsize_t length) {
	if (dest == NULL || src == NULL) {
		return EINVAL;
	}
	if (destmax < length) {
		return ERANGE;
	}
	volatile uint8_t *d = dest;
	const volatile uint8_t *s = src;
	while (length--) {
		*d++ = *s++;
	}
	return 0;
}

/**
 * @brief Copies a specified number of bytes from the source memory to the destination memory, with a maximum limit on the destination size.
 *
 * This function copies the specified number of bytes from the source memory to the destination memory. It ensures that the copy operation does not exceed the maximum size of the destination memory.
 *
 * @param dest Pointer to the destination memory where the data will be copied.
 * @param destmax Maximum size of the destination memory.
 * @param src Pointer to the source memory from where the data will be copied.
 * @param length Number of bytes to be copied.
 * @return If successful, returns zero; otherwise, returns an error code indicating the cause of failure.
 */
errno_t memcpy_smax(void *dest, rsize_t destmax, const void *src, rsize_t length) {
	if (dest == NULL || src == NULL) {
		return EINVAL;
	}
	if (destmax < length) {
		return ERANGE;
	}
	volatile uint8_t *d = dest;
	const volatile uint8_t *s = src;
	while (length--) {
		*d++ = *s++;
	}
	return 0;
}