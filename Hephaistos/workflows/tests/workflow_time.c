/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:50:17 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/14 18:57:57 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <charon.h>
#include <hephaistos.h>

int test_counter() {
    counter_t counter;
    counter_start(&counter);

    // Vérifier que le compteur a été démarré
    assert(counter_get_start(&counter) != 0);

    kmsleep(50);

    counter_stop(&counter);

    // Vérifier que le compteur a été arrêté
    assert(counter_get_end(&counter) != 0);

    // Vérifier que le temps écoulé est correct
    printk("Time elapsed: %d\n", counter_get_time(&counter));
    assert(counter_get_time(&counter) > 0);

    return (0);
}

int workflow_hephaistos_time(void) {
    if ((test_counter()) != 0) {
        return (1);
    }
    printk("All tests passed!\n");
    return (0);
}