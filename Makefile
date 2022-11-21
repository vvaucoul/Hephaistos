# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 23:52:42 by vvaucoul          #+#    #+#              #
#    Updated: 2022/11/21 12:48:49 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../mk-files/utils/Colors.mk

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
WORKFLOW_NAME 	= hephaistos_workflow
ASM				= nasm

DEFAULT_FLAGS 	=# -Wall -Wextra -Werror -Wfatal-errors
CFLAGS 			= 	-fno-builtin -fno-exceptions -fno-stack-protector \
					-nostdlib -nodefaultlibs \
					-std=gnu99 -ffreestanding -O2

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

workflow: $(WORKFLOW_NAME)

$(WORKFLOW_NAME): $(NAME)
	@$(CC) $(LDFLAGS) $(DEFAULT_FLAGS) $(INCLUDES) -o $(WORKFLOW_NAME) $(NAME) workflows/$(WORKFLOW_NAME).c $(LIB_DIR).a

.PHONY: workflow

clean:
	@rm -rf $(OBJS) $(OBJS_ASM) $(DEPENDS) $(DEPENDS_ASM) $(WORKFLOW_NAME)

fclean: clean
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

.PHONY: all clean fclean re ascii