# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 23:52:42 by vvaucoul          #+#    #+#              #
#    Updated: 2024/10/21 10:50:58 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../mk-files/utils/Colors.mk
include ../mk-files/rules/Rules.mk

CCACHE_DIR = ccache

ifeq ($(CCACHE_INSTALLED), false)
	CCACHE = ../$(DEPENDENCIES_DIR)/$(CCACHE_DIR)/ccache
else
	CCACHE = ccache
endif

CC = i386-elf-gcc

SCRIPTS_DIR = scripts
KERNEL_DIRECTORY = kernel
VERSION := $(shell sh $(SCRIPTS_DIR)/HephaistosVersion.sh)

NAME = Hephaistos.a
ASM = nasm

DEFAULT_FLAGS = -Wall -Wextra -Werror -Wfatal-errors
CFLAGS = -fno-builtin -fno-exceptions -fno-stack-protector -nostdlib -nodefaultlibs -nostdinc \
		 -ffreestanding -O0 -std=c2x -m32
LDFLAGS = -g3 -m32
ASM_FLAGS = -f elf32

LIB_DIR = Hephaistos
INCLUDES_DIR = include
INCLUDES = -I./$(LIB_DIR)/$(INCLUDES_DIR) -I../$(KERNEL_DIRECTORY)/includes

WORKFLOW_DIR := workflows tests
SRCS_DIR := $(LIB_DIR)

COMPILE_WORKFLOWS := $(shell sh ./scripts/HephaistosCompileWorkflows.sh)
ifeq ($(COMPILE_WORKFLOWS), 1)
	SRCS_DIR += $(WORKFLOW_DIR)
endif

SRCS = $(shell find $(SRCS_DIR) -name "*.c")
OBJS = $(SRCS:.c=.o)
DEPENDS = $(SRCS:.c=.d)

SRCS_ASM = $(shell find $(SRCS_DIR) -name "*.s")
OBJS_ASM = $(SRCS_ASM:.s=.o)
DEPENDS_ASM = $(SRCS_ASM:.s=.d)

%.o: %.c
	@printf "$(_LWHITE) $(_DIM)- Compiling: $(_END)$(_DIM)--------$(_END)$(_LCYAN) %s $(_END)$(_LGREEN)[$(_LWHITE)✓$(_LGREEN)]$(_END)\n" $< 
	@$(CC) $(LDFLAGS) $(DEFAULT_FLAGS) $(CFLAGS) $(INCLUDES) -MD -c $< -o $@

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

fre: clean all

re: fclean all

ascii:
	@printf "$(_LRED)██╗░░██╗███████╗██████╗░██╗░░██╗░█████╗░██╗░██████╗████████╗░█████╗░░██████╗$(_END)\n"
	@printf "$(_LRED)██║░░██║██╔════╝██╔══██╗██║░░██║██╔══██╗██║██╔════╝╚══██╔══╝██╔══██╗██╔════╝$(_END)\n"
	@printf "$(_LRED)███████║█████╗░░██████╔╝███████║███████║██║╚█████╗░░░░██║░░░██║░░██║╚█████╗░$(_END)\n"
	@printf "$(_LRED)██╔══██║██╔══╝░░██╔═══╝░██╔══██║██╔══██║██║░╚═══██╗░░░██║░░░██║░░██║░╚═══██╗$(_END)\n"
	@printf "$(_LRED)██║░░██║███████╗██║░░░░░██║░░██║██║░░██║██║██████╔╝░░░██║░░░╚█████╔╝██████╔╝$(_END)\n"
	@printf "$(_LRED)╚═╝░░╚═╝╚══════╝╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝╚═════╝░░░░╚═╝░░░░╚════╝░╚═════╝░$(_END)\n"
	@printf "$(_WHITE)Version $(_LCYAN)$(_BOLD)$(VERSION)$(_WHITE)$(_END)$(_BOLD)					           $(_LRED)For KronOS Kernel$(_END)\n\n"

-include $(DEPENDS)
-include $(DEPENDS_ASM)

.PHONY: all clean fclean fre re ascii clean-ccache
