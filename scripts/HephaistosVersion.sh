# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    HephaistosVersion.sh                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 15:37:48 by vvaucoul          #+#    #+#              #
#    Updated: 2022/11/20 15:41:40 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Hephaistos Version
grep -hnr "_HEPHAISTOS_VERSION" | tail -c 6 | sed 's/"//g' > output

cat output
rm output