/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_stdio.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:35:30 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 12:59:11 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>

#include <stdio.h>
#include <string.h>

static int __test_sscank(void) {
    char *str = kmalloc(sizeof(char) * 100);

    memset(str, 0, 100);

    sscank("Hello World", "%s", str);

    printk("SSCANK: %s\n", str);

    if (strcmp(str, "Hello") != 0) {
        printk("SSCANK: [KO]\n");
        return (1);
    }

    return (0);
}

static int __test_snprintk(void) {
    char *str = kmalloc(sizeof(char) * 100);

    // Test 1 : Chaîne de caractères
    memset(str, 0, 100);
    snprintk(str, 100, "Hello %s", "World");
    printk("SNPRINTK: %s\n", str);
    if (strcmp(str, "Hello World") != 0) {
        printk("SNPRINTK: [KO]\n");
        return (1);
    }

    // Test 2 : Entier
    memset(str, 0, 100);
    snprintk(str, 100, "The answer is %d", 42);
    printk("SNPRINTK: %s\n", str);
    if (strcmp(str, "The answer is 42") != 0) {
        printk("SNPRINTK: [KO]\n");
        return (1);
    }

    // Test 3 : Flottant avec 2 décimales
    memset(str, 0, 100);
    snprintk(str, 100, "The value of pi is %.2f", 3.14159);
    printk("SNPRINTK: %s\n", str);
    if (strcmp(str, "The value of pi is 3.14") != 0) {
        printk("SNPRINTK: [KO]\n");
        return (1);
    }

    // Test 4 : Long
    memset(str, 0, 100);
    snprintk(str, 100, "Long number: %ld", 123456789L);
    printk("SNPRINTK: %s\n", str);
    if (strcmp(str, "Long number: 123456789") != 0) {
        printk("SNPRINTK: [KO]\n");
        return (1);
    }

    // Test 5 : Chaîne simple sans format
    memset(str, 0, 100);
    snprintk(str, 100, "This is a test");
    printk("SNPRINTK: %s\n", str);
    if (strcmp(str, "This is a test") != 0) {
        printk("SNPRINTK: [KO]\n");
        return (1);
    }

    // Test 6 : Grand entier
    memset(str, 0, 100);
    snprintk(str, 100, "The result is %d", 1000);
    printk("SNPRINTK: %s\n", str);
    if (strcmp(str, "The result is 1000") != 0) {
        printk("SNPRINTK: [KO]\n");
        return (1);
    }

    // Test 7 : Flottant avec 4 décimales
    memset(str, 0, 100);
    snprintk(str, 100, "The value of e is %.4f", 2.71828);
    printk("SNPRINTK: %s\n", str);
    if (strcmp(str, "The value of e is 2.7183") != 0) {
        printk("SNPRINTK: [KO]\n");
        return (1);
    }

    // Test 8 : Entier négatif
    memset(str, 0, 100);
    snprintk(str, 100, "The result is %d", -42);
    printk("SNPRINTK: %s\n", str);
    if (strcmp(str, "The result is -42") != 0) {
        printk("SNPRINTK: [KO]\n");
        return (1);
    }

    // Test 9 : Flottant arrondi à l'entier
    memset(str, 0, 100);
    snprintk(str, 100, "The value of pi is %.0f", 3.14159);
    printk("SNPRINTK: %s\n", str);
    if (strcmp(str, "The value of pi is 3") != 0) {
        printk("SNPRINTK: [KO]\n");
        return (1);
    }

    // Test 10 : Zéro
    memset(str, 0, 100);
    snprintk(str, 100, "The result is %d", 0);
    printk("SNPRINTK: %s\n", str);
    if (strcmp(str, "The result is 0") != 0) {
        printk("SNPRINTK: [KO]\n");
        return (1);
    }

    // Test 11 : Flottant avec 6 décimales
    memset(str, 0, 100);
    snprintk(str, 100, "The value of pi is %.6f", 3.14159);
    printk("SNPRINTK: %s\n", str);
    if (strcmp(str, "The value of pi is 3.141590") != 0) {
        printk("SNPRINTK: [KO]\n");
        return (1);
    }

    // Test 12 : Grand nombre
    memset(str, 0, 100);
    snprintk(str, 100, "The result is %d", 999999);
    printk("SNPRINTK: %s\n", str);
    if (strcmp(str, "The result is 999999") != 0) {
        printk("SNPRINTK: [KO]\n");
        return (1);
    }

    kfree(str);
    return (0);
}

int workflow_hephaistos_stdio(void) {
    #warning "TODO: Implement stdio tests"
    // if ((__test_sscank()) != 0) {
    //     printk("STDIO: [KO]\n"); // Remove the use of RED and RESET macros
    //     return (1);
    // }
    // if ((__test_snprintk()) != 0) {
    //     printk("STDIO: [KO]\n"); // Remove the use of RED and RESET macros
    //                              //   return (1);
    // }

    return (0);
}