/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflows.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:55:33 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/02/11 23:36:57 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __H_WORKFLOWS_H
#define __H_WORKFLOWS_H

/**
 * @brief This define is a test called in the kernel to check all the lib.
 *
 * @note This define is used in the Makefile to compile the test.
 */
#ifndef __TEST_HEPHAISTOS__
#define __TEST_HEPHAISTOS__ 1
#endif

extern int workflow_hephaistos_strings(void);
extern int workflow_hephaistos_memory(void);
extern int workflow_hephaistos_time(void);
extern int workflow_hephaistos_convert(void);
extern int workflow_hephaistos_a_stack(void);
extern int workflow_hephaistos_a_queue(void);
extern int workflow_hephaistos_a_list(void);
extern int workflow_hephaistos_a_hashtable(void);
extern int workflow_hephaistos_a_btree(void);
extern int workflow_hephaistos_a_rbtree(void);
extern int workflow_hephaistos_a_array(void);

extern int hephaistos_workflow(void);

#endif /* !__H_WORKFLOWS_H */