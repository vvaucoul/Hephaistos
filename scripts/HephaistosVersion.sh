# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    HephaistosVersion.sh                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 15:37:48 by vvaucoul          #+#    #+#              #
#    Updated: 2024/07/26 22:19:07 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Hephaistos Version
grep -hnr "_HEPHAISTOS_VERSION" Hephaistos/include/hephaistos.h | awk -F'"' '{print $2}' > output

# Print Version
cat output
rm output