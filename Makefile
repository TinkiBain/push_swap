# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 17:38:22 by ggwin-go          #+#    #+#              #
#    Updated: 2019/10/28 22:41:44 by ggwin-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

CC=clang
FLAGS=-Wall -Wextra -Werror
FLAGS+=-g

INCLUDES:=\
	-I includes\
	-I libft/includes

SRCS_DIR=sources
OBJS_DIR=objects

LIBFT_DIR=libft

include $(LIBFT_DIR)/libft_dependences.mk

SOURCES=main.c

SRCS=$(addprefix $(SRCS_DIR)/, $(SOURCES))
OBJS=$(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))

OBJS_CLEAN=$(strip $(foreach f,$(OBJS),$(wildcard $(f))))
NAME_CLEAN=$(strip $(NAME))

LIBFT_A=$(LIBFT_DIR)/libft.a

RED=\033[0;31m
GREEN=\033[0;32m
BLUE=\033[1;34m
NC=\033[0m

OBJS_SUBDIRS=$(OBJS_DIR)

.PHONY: all clean fclean re vg

LIBFT_OBJS_DEPENDS=$(addprefix $(LIBFT_DIR)/, $(LIBFT_OBJS))


all: $(NAME)

$(NAME): $(LIBFT_A) $(LIBFT_OBJS_DEPENDS) $(OBJS_SUBDIRS) $(OBJS)
	@printf "$(BLUE)Compiling $(NAME_CLEAN)...$(NC)\n"
	@$(CC) $(OBJS) $(LIBFT_A) $(INCLUDES) $(FLAGS) -o $(NAME)
	@printf "$(GREEN)Bin $(NAME) is ready to use!$(NC)\n"

-include $(OBJS:.o=.d)

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

$(LIBFT_DIR)/$(LIBFT_OBJS_DIR)/%.o: $(LIBFT_DIR)/$(LIBFT_SRCS_DIR)/%.c
	@make -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(INCLUDES) $(FLAGS) -o $@ -c $< -MMD

$(OBJS_SUBDIRS):
	@mkdir -p $@

clean:
ifneq ($(OBJS_CLEAN),)
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@printf "$(RED)$(NAME_CLEAN) objects files removed.$(NC)\n"
else
	@printf "$(RED)$(NAME_CLEAN) objects already cleaned$(NC)\n"
endif

fclean: clean
ifneq ($(NAME_CLEAN),)
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@rm -rf $(NAME)
	@printf "$(RED)Bin $(NAME_CLEAN) removed.$(NC)\n"
else
	@printf "$(RED)Objects and bin $(NAME_CLEAN) already cleaned$(NC)\n"
endif

re: fclean all
