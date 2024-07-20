# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 23:52:42 by vvaucoul          #+#    #+#              #
#    Updated: 2024/07/20 11:24:24 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../mk-files/utils/Colors.mk
include ../mk-files/rules/Rules.mk
CCACHE_DIR			=	ccache

#*******************************************************************************
#*                          DEFAULT COMPILATION RULES                          *
#*******************************************************************************

ifeq ($(CCACHE_INSTALLED), false)
	CCACHE			=	../$(DEPENDENCIES_DIR)/$(CCACHE_DIR)/ccache
else
	CCACHE 			=	ccache
endif

ifeq ($(CLANG_INSTALLED), false)
	CC				=	$(CCACHE) gcc
else
	CC				=	$(CCACHE) clang
endif

SCRIPTS_DIR			=	scripts

KERNEL_DIRECTORY	=	kernel
VERSION				:=	$(shell sh $(SCRIPTS_DIR)/HephaistosVersion.sh)

#*******************************************************************************
#*                           HEPHAISTOS COMPILATION                            *
#*******************************************************************************

NAME 			= Hephaistos.a
ASM				= nasm

DEFAULT_FLAGS 	=	-Wall -Wextra -Werror -Wfatal-errors
CFLAGS 			= 	-fno-builtin -fno-exceptions -fno-stack-protector \
					-nostdlib -nodefaultlibs \
					-std=c99 -ffreestanding -O2 \
					--std=c2x # Use C23 standard

LDFLAGS			= 	-g3 -m32

ASM_FLAGS		=	-f elf32 

LIB_DIR 		=	Hephaistos

INCLUDES 		=	-I./$(LIB_DIR) \
					-I../$(KERNEL_DIRECTORY)/includes

SRCS_DIR 		=	$(LIB_DIR)

SRCS			=	$(shell find $(SRCS_DIR) -name "*.c")
OBJS			=	$(SRCS:.c=.o)
DEPENDS			=	$(SRCS:.c=.d)

SRCS_ASM		=	$(shell find $(SRCS_DIR) -name "*.s")
OBJS_ASM		=	$(SRCS_ASM:.s=.o)
DEPENDS_ASM		=	$(SRCS_ASM:.s=.d)

%.o: %.c
	@printf "$(_LWHITE) $(_DIM)- Compiling: $(_END)$(_DIM)--------$(_END)$(_LCYAN) %s $(_END)$(_LGREEN)[$(_LWHITE)✓$(_LGREEN)]$(_END)\n" $< 
	@$(CC) $(LDFLAGS) $(CFLAGS) $(INCLUDES) -MD -c $< -o $@

%.o: %.s
	@printf "$(_LWHITE) $(_DIM)- Compiling: $(_END)$(_DIM)--------$(_END)$(_LPURPLE) %s $(_END)$(_LGREEN)[$(_LWHITE)✓$(_LGREEN)]$(_END)\n" $< 
	@$(ASM) $(ASM_FLAGS) $(INCLUDES) $< -o $@

all: $(NAME)

$(NAME): ascii $(OBJS) $(OBJS_ASM) 
	@ar -rcs $(NAME) $(OBJS) $(OBJS_ASM)
	@printf "\n$(_LWHITE)-$(_END)$(_DIM)$(_END)$(_LWHITE) %s $(_END)$(_DIM)-------------$(_END)$(_LGREEN)[$(_LWHITE)✓$(_LGREEN)]$(_END)\n" "HEPHAISTOS"

clean:
	@rm -rf $(OBJS) $(OBJS_ASM) $(DEPENDS) $(DEPENDS_ASM)

clean-ccache:
	@printf "$(_LWHITE)- CLEAN CCACHE $(_END)$(_DIM)----------$(_END) $(_LGREEN)[$(_LWHITE)✓$(_LGREEN)]$(_END)\n"
	@$(CCACHE) -c -C > /dev/null 2>&1

fclean: clean clean-ccache
	@rm -rf $(NAME) 

re: fclean all

ascii:
	@printf "$(_LRED) _    _ ______ _____  _    _          _____  _____ _______ ____   _____ $(_END)\n"
	@printf "$(_LRED)| |  | |  ____|  __ \| |  | |   /\   |_   _|/ ____|__   __/ __ \ / ____|$(_END)\n"
	@printf "$(_LRED)| |__| | |__  | |__) | |__| |  /  \    | | | (___    | | | |  | | (___  $(_END)\n"
	@printf "$(_LRED)|  __  |  __| |  ___/|  __  | / /\ \   | |  \___ \   | | | |  | |\___ \ $(_END)\n"
	@printf "$(_LRED)| |  | | |____| |    | |  | |/ ____ \ _| |_ ____) |  | | | |__| |____) |$(_END)\n"
	@printf "$(_LRED)|_|  |_|______|_|    |_|  |_/_/    \_\_____|_____/   |_|  \____/|_____/ $(_END)\n"
	@printf "$(_LRED)                                                                        $(_END)\n"
	@printf "$(_WHITE)Version $(VERSION)					       For KronOS Kernel\n\n"

-include $(DEPENDS)
-include $(DEPENDS_ASM)

.PHONY: all clean fclean re ascii workflow clean-ccache