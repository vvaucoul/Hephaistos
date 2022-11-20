/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hephaistos_workflow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:36:33 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/20 12:10:29 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hephaistos.h>

static int __w_string(void)
{
    const char str[] = "Hello World !";
    int32_t nbr = -42;
    uint32_t unbr = 42;

    printf("Length : %u \n", strlen(str));
    printf("Length : %u \n", nbrlen(nbr));
    printf("Length : %u \n", unbrlen(unbr));

}

int main(void)
{
    if ((__w_string()) == -1)
        return (-1);
    return (0);
}