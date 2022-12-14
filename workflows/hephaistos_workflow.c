/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hephaistos_workflow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:36:33 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/21 18:22:11 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hephaistos.h>
#include <passenger.h>

static int __w_string(void)
{
    const char str[] = "Hello World !";
    int32_t nbr = -42;
    uint32_t unbr = 42;

    printk("Length : %u \n", strlen(str));
    printk("Length : %u \n", nbrlen(nbr));
    printk("Length : %u \n", unbrlen(unbr));
    return (0);
}

int main(void)
{
    if ((__w_string()) == -1)
        return (-1);
    return (0);
}