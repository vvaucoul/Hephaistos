/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hephaistos_workflow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:36:33 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 13:00:33 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hephaistos_workflows.h"
#include <charon.h>

/**
 * @brief This function is a test called in the kernel to check all the lib.
 *
 * @return int Returns the status of the workflow.
 */
int hephaistos_workflow(void) {
	int ret = 0;

	if ((workflow_hephaistos_strings()) != 0) {
		__INFOD("[HEPHAISTOS] [STRINGS] "_RED
				"[KO]"_END);
		ret = 1;
	} else {
		__INFOD("[HEPHAISTOS] [STRINGS] "_GREEN
				"[OK]"_END);
	}

	if ((workflow_hephaistos_convert()) != 0) {
		__INFOD("[HEPHAISTOS] [CONVERT] "_RED
				"[KO]"_END);
		ret = 1;
	} else {
		__INFOD("[HEPHAISTOS] [CONVERT] "_GREEN
				"[OK]"_END);
	}

	// Todo: Implement tests for STDIO
	//  if ((workflow_hephaistos_stdio()) != 0) {
	//      __INFOD("[HEPHAISTOS] [STDIO] "_RED
	//              "[KO]"_END);
	//      ret = 1;
	//  } else {
	//      __INFOD("[HEPHAISTOS] [STDIO] "_GREEN
	//              "[OK]"_END);
	//  }

	// ! ||--------------------------------------------------------------------------------||
	// ! ||                                 ALGORITHM_TESTS                                ||
	// ! ||--------------------------------------------------------------------------------||

	if ((workflow_hephaistos_a_stack()) != 0) {
		__INFOD("[HEPHAISTOS] [ALGORITHM - STACK] "_RED
				"[KO]"_END);
		ret = 1;
	} else {
		__INFOD("[HEPHAISTOS] [ALGORITHM - STACK] "_GREEN
				"[OK]"_END);
	}

	if ((workflow_hephaistos_a_queue()) != 0) {
		__INFOD("[HEPHAISTOS] [ALGORITHM - QUEUE] "_RED
				"[KO]"_END);
		ret = 1;
	} else {
		__INFOD("[HEPHAISTOS] [ALGORITHM - QUEUE] "_GREEN
				"[OK]"_END);
	}

	if ((workflow_hephaistos_a_list()) != 0) {
		__INFOD("[HEPHAISTOS] [ALGORITHM - LIST] "_RED
				"[KO]"_END);
		ret = 1;
	} else {
		__INFOD("[HEPHAISTOS] [ALGORITHM - LIST] "_GREEN
				"[OK]"_END);
	}

	if ((workflow_hephaistos_a_hashtable()) != 0) {
		__INFOD("[HEPHAISTOS] [ALGORITHM - HASHTABLE] "_RED
				"[KO]"_END);
		ret = 1;
	} else {
		__INFOD("[HEPHAISTOS] [ALGORITHM - HASHTABLE] "_GREEN
				"[OK]"_END);
	}

	if ((workflow_hephaistos_a_bst()) != 0) {
		__INFOD("[HEPHAISTOS] [ALGORITHM - BST] "_RED
				"[KO]"_END);
		ret = 1;
	} else {
		__INFOD("[HEPHAISTOS] [ALGORITHM - BST] "_GREEN
				"[OK]"_END);
	}

	if ((workflow_hephaistos_a_rbtree()) != 0) {
		__INFOD("[HEPHAISTOS] [ALGORITHM - RBTREE] "_RED
				"[KO]"_END);
		ret = 1;
	} else {
		__INFOD("[HEPHAISTOS] [ALGORITHM - RBTREE] "_GREEN
				"[OK]"_END);
	}

	if ((workflow_hephaistos_a_array()) != 0) {
		__INFOD("[HEPHAISTOS] [ALGORITHM - ARRAY] "_RED
				"[KO]"_END);
		ret = 1;
	} else {
		__INFOD("[HEPHAISTOS] [ALGORITHM - ARRAY] "_GREEN
				"[OK]"_END);
	}

	if ((workflow_hephaistos_a_avl()) != 0) {
		__INFOD("[HEPHAISTOS] [ALGORITHM - AVL] "_RED
				"[KO]"_END);
		ret = 1;
	} else {
		__INFOD("[HEPHAISTOS] [ALGORITHM - AVL] "_GREEN
				"[OK]"_END);
	}

	printk("All tests passed!\n");

	return (ret);
}