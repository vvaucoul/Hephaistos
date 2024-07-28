# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    HephaistosCompileWorkflows.sh                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/28 10:37:32 by vvaucoul          #+#    #+#              #
#    Updated: 2024/07/28 11:53:22 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Check if __TEST_HEPHAISTOS__ is set to 1 in "./workflows/workflows.h"
FILE="./workflows/hephaistos_workflows.h"

# Check if the file exists
if [ ! -f "$FILE" ]; then
    echo "0"
    exit 0
fi

# Check if __TEST_HEPHAISTOS__ is set to 1
if grep -q '^#define __TEST_HEPHAISTOS__ 1' "$FILE"; then
    echo "1"
    exit 1
else
    echo "0"
    exit 0
fi
