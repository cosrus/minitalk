# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crusu <crusu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 18:33:25 by crusu             #+#    #+#              #
#    Updated: 2023/04/01 21:33:51 by crusu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ctype/ft_isalnum.c				\
		ctype/ft_isalpha.c 				\
		ctype/ft_isascii.c				\
		ctype/ft_isdigit.c				\
		ctype/ft_isprint.c				\
		ctype/ft_tolower.c				\
		ctype/ft_toupper.c				\
		ft_printf/ft_printf.c			\
		ft_printf/hex_type.c			\
		ft_printf/int_type.c			\
		ft_printf/set_flag.c			\
		ft_printf/str_type.c			\
		get_next_line/get_next_line.c	\
		list/ft_lstadd_back.c			\
		list/ft_lstadd_front.c			\
		list/ft_lstclear.c				\
		list/ft_lstdelone.c				\
		list/ft_lstiter.c				\
		list/ft_lstlast.c				\
		list/ft_lstmap.c				\
		list/ft_lstnew.c				\
		list/ft_lstsize.c				\
		putfd/ft_putchar_fd.c			\
		putfd/ft_putendl_fd.c			\
		putfd/ft_putnbr_fd.c			\
		putfd/ft_putstr_fd.c			\
		stdlib/ft_atoi.c				\
		stdlib/ft_calloc.c				\
		stdlib/ft_itoa.c				\
		stdlib/ft_itoh.c				\
		stdlib/ft_ltoa.c				\
		stdlib/ft_size.c				\
		stdlib/ft_usize.c				\
		string/ft_bzero.c				\
		string/ft_memchr.c				\
		string/ft_memcmp.c				\
		string/ft_memcpy.c				\
		string/ft_memmove.c				\
		string/ft_memset.c				\
		string/ft_split.c				\
		string/ft_strchr.c				\
		string/ft_strdup.c				\
		string/ft_striteri.c			\
		string/ft_strjoin.c				\
		string/ft_strlcat.c				\
		string/ft_strlcpy.c				\
		string/ft_strlen.c				\
		string/ft_strmapi.c				\
		string/ft_strncmp.c				\
		string/ft_strnstr.c				\
		string/ft_strrchr.c				\
		string/ft_strtrim.c				\
		string/ft_substr.c	

NAME = mylibft.a

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : %.c header/libft.h
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/ctype/
	@mkdir -p $(OBJS_DIR)/ft_printf/
	@mkdir -p $(OBJS_DIR)/get_next_line/
	@mkdir -p $(OBJS_DIR)/list/
	@mkdir -p $(OBJS_DIR)/putfd/
	@mkdir -p $(OBJS_DIR)/stdlib/
	@mkdir -p $(OBJS_DIR)/string/

	@echo "Compiling: $<"
	@gcc $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@ar r $(NAME) $(OBJECTS_PREFIXED)
	@echo "myLibft Done !"

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
	
.PHONY: all clean fclean re bonus
