/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:55:48 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/26 22:11:32 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stddef.h>
#include <charon.h>

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

    uint32_t i = strlen(s);
    while (i > 0) {
        if (s[i] == c) {
            return ((char *)&s[i]);
        }
        i--;
    }
    return (NULL);
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
        return (NULL);
    }

    char *new_str = kmalloc(sizeof(char) * strlen(s) + 1);
    if (new_str == NULL) {
        return (NULL);
    }

    bzero(new_str, strlen(s) + 1);

    strclr(new_str, (char *)s);
    return (new_str);
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
        return (NULL);
    }

    char *new_str = kmalloc(sizeof(char) * len + 1);
    if (new_str == NULL) {
        return (NULL);
    }

    bzero(new_str, len + 1);

    strncpy(new_str, &s[start], len);
    return (new_str);
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
    if (s == NULL || accept == NULL)
        return (0);

    uint32_t i = 0;
    uint32_t j = 0;
    while (s[i]) {
        j = 0;
        while (accept[j]) {
            if (s[i] == accept[j])
                break;
            j++;
        }
        if (accept[j] == '\0')
            return (i);
        i++;
    }
    return (i);
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
        return (NULL);
    }

    uint32_t i = 0;
    uint32_t j = 0;
    while (s[i]) {
        j = 0;
        while (accept[j]) {
            if (s[i] == accept[j]) {
                return ((char *)&s[i]);
            }
            j++;
        }
        i++;
    }
    return (NULL);
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

    str += strspn(str, delim);
    if (*str == '\0') {
        return (NULL);
    }

    token = str;
    str = strpbrk(token, delim);
    if (str == NULL) {
        last = NULL;
    } else {
        *str = '\0';
        last = str + 1;
    }
    return (token);
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