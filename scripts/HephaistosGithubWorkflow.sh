# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    HephaistosGithubWorkflow.sh                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 22:25:19 by vvaucoul          #+#    #+#              #
#    Updated: 2024/02/11 22:41:15 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
sed -i 's/#define __TEST_HEPHAISTOS__ 0/#define __TEST_HEPHAISTOS__ 1/g' ../Hephaistos/workflows/workflows.h