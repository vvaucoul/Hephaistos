# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    HephaistosVersion.sh                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 15:37:48 by vvaucoul          #+#    #+#              #
#    Updated: 2024/07/20 11:19:02 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Hephaistos Version
grep -hnr "_HEPHAISTOS_VERSION" Hephaistos/hephaistos.h | awk -F'"' '{print $2}' > output

# Print Version
cat output
rm output