# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By:  jlucas-f <jlucas-f@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/10 19:59:04 by user42            #+#    #+#              #
#    Updated: 2021/09/01 11:47:36 by  jlucas-f        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CC_FLAGS	= -Wall -Wextra -Werror
ARCHIVE		= ar -rc
INDEX		= ranlib
RM			= rm -f
RMDIR		= rm -rf

NAME		= libftprintf.a

INCLUDES_PATH	= ./includes
SOURCES_PATH	= ./sources
OBJECTS_PATH	= ./objects

INCLUDES_FILES	= libft.h ft_printf.h
SOURCES_FILES	= ft_printf.c ft_printf_char.c ft_printf_unsigned_int.c \
			ft_printf_hexadec_uppercase_unsigned_int.c ft_printf_int.c \
			ft_printf_ptr.c ft_printf_str.c ft_printf_hexadec_unsigned_int.c \
			\
			ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c \
			ft_isalnum.c ft_tolower.c ft_toupper.c ft_strlen.c ft_strlcpy.c \
			ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c \
			ft_atoi.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
			ft_memmove.c ft_memchr.c ft_memcmp.c ft_strdup.c ft_calloc.c \
			ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_substr.c ft_strjoin.c ft_strtrim.c \
			ft_split.c ft_strmapi.c

INCLUDES	= $(addprefix $(INCLUDES_PATH)/,$(INCLUDES_FILES))
SOURCES		= $(addprefix $(SOURCES_PATH)/,$(SOURCES_FILES))
OBJECTS		= $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCES_FILES)))

all:		$(NAME)

$(NAME):	$(OBJECTS) $(INCLUDES)
			$(ARCHIVE) $(NAME) $(OBJECTS)
			$(INDEX) $(NAME)

$(OBJECTS_PATH)/%.o:	$(SOURCES_PATH)/%.c $(INCLUDES)
					mkdir -p $(OBJECTS_PATH)
					$(CC) $(CC_FLAGS) -I $(INCLUDES_PATH) -c $< -o $@

clean:
			$(RM) $(OBJECTS)
			$(RMDIR) $(OBJECTS_PATH)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonus:

.PHONY:		all clean fclean re bonus
