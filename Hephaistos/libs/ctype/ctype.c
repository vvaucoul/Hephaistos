/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctype.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:24:25 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/22 12:56:57 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctype.h"

/**
 * @brief Check if a character is alphanumeric.
 *
 * @param c The character to check.
 * @return true if the character is alphanumeric, false otherwise.
 */
bool isalnum(uchar_t c) {
    return (isalpha(c) || isdigit(c));
}

/**
 * @brief Check if a character is alphabetic.
 *
 * @param c The character to check.
 * @return true if the character is alphabetic, false otherwise.
 */
bool isalpha(uchar_t c) {
    return (islower(c) || isupper(c));
}

/**
 * @brief Check if a character is a blank space or tab.
 *
 * @param c The character to check.
 * @return true if the character is a blank space or tab, false otherwise.
 */
bool isblank(uchar_t c) {
    return (c == ' ' || c == '\t');
}

/**
 * @brief Check if a character is a control character.
 *
 * @param c The character to check.
 * @return true if the character is a control character, false otherwise.
 */
bool iscntrl(uchar_t c) {
    return (c >= 0 && c <= 31) || c == 127;
}

/**
 * @brief Check if a character is a digit.
 *
 * @param c The character to check.
 * @return true if the character is a digit, false otherwise.
 */
bool isdigit(uchar_t c) {
    return (c >= '0' && c <= '9');
}

/**
 * @brief Check if a character is a printable character except space.
 *
 * @param c The character to check.
 * @return true if the character is a printable character except space, false otherwise.
 */
bool isgraph(uchar_t c) {
    return (c >= 33 && c <= 126);
}

/**
 * @brief Check if a character is a lowercase letter.
 *
 * @param c The character to check.
 * @return true if the character is a lowercase letter, false otherwise.
 */
bool islower(uchar_t c) {
    return (c >= 'a' && c <= 'z');
}

/**
 * @brief Check if a character is a printable character.
 *
 * @param c The character to check.
 * @return true if the character is a printable character, false otherwise.
 */
bool isprint(uchar_t c) {
    return (c >= 32 && c <= 126);
}

/**
 * @brief Check if a character is a punctuation character.
 *
 * @param c The character to check.
 * @return true if the character is a punctuation character, false otherwise.
 */
bool ispunct(uchar_t c) {
    return (isgraph(c) && !isalnum(c));
}

/**
 * @brief Check if a character is an uppercase letter.
 *
 * @param c The character to check.
 * @return true if the character is an uppercase letter, false otherwise.
 */
bool isupper(uchar_t c) {
    return (c >= 'A' && c <= 'Z');
}

/**
 * @brief Check if a character is a hexadecimal digit.
 *
 * @param c The character to check.
 * @return true if the character is a hexadecimal digit, false otherwise.
 */
bool isxdigit(uchar_t c) {
    return (isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

/**
 * @brief Check if a character is a valid ASCII character.
 *
 * @param c The character to check.
 * @return true if the character is a valid ASCII character, false otherwise.
 */
bool isascii(uchar_t c) {
    return (c >= 0 && c <= 127);
}

/**
 * @brief Convert a character to its ASCII equivalent.
 *
 * @param c The character to convert.
 * @return The ASCII equivalent of the character.
 */
uchar_t toascii(uchar_t c) {
    return (c & 0x7F);
}

/**
 * @brief Convert a character to lowercase.
 *
 * @param c The character to convert.
 * @return The lowercase equivalent of the character.
 */
uchar_t tolower(uchar_t c) {
    return (isupper(c) ? c + 32 : c);
}

/**
 * @brief Convert a character to uppercase.
 *
 * @param c The character to convert.
 * @return The uppercase equivalent of the character.
 */
uchar_t toupper(uchar_t c) {
    return (islower(c) ? c - 32 : c);
}