/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doligtha <doligtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:09:51 by doligtha          #+#    #+#             */
/*   Updated: 2024/03/16 01:59:28 by doligtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>  // 'size_t';
# include <stdbool.h> // 'bool';

# ifndef VA_FORBIDDEN
#  include "printf.h"
int	ft_printf(const char *format, ...);
# endif

//this shit is hella slow but lets go
# ifdef DEBUG
#  include <stdio.h>
#  include <unistd.h>
#  include <limits.h>
#  include <string.h>
#  if defined(RESET) || defined(RED) || defined(GREEN) || defined(YELLOW) \
	|| defined(BLUE) || defined(MAGENTA) || defined(CYAN) || defined(WHITE)
#  else
#   define RESET "\033[0m"
#   define BLACK "\033[0;30m"
#   define RED "\033[0;31m"
#   define GREEN "\033[0;32m"
#   define YELLOW "\033[0;33m"
#   define BLUE "\033[0;34m"
#   define MAGENTA "\033[0;35m"
#   define CYAN "\033[0;36m"
#   define WHITE "\033[0;37m"
#  endif
# endif // #ifdef DEBUG

# ifndef ERROR_LIBFT
#  define ERROR_LIBFT -1
# endif

//linked list:
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//PDF ORDER:
//part 1 - ctype.h, string.h, strings.h, stdlib.h:
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);

void	*ft_calloc(size_t nmemb, size_t size); //malloc()
char	*ft_strdup(const char *s); //malloc()

//part 2 - 42fr functions:
char	*ft_substr(char const *s, unsigned int start, size_t len); //malloc()
char	*ft_strjoin(char const *s1, char const *s2); //malloc()
char	*ft_strtrim(char const *s1, char const *set); //malloc()
char	**ft_split(char const *s, char c); //malloc(), free();
char	*ft_itoa(int n); //malloc(), ft_intlen();
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char)); //malloc()
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd); //write()
void	ft_putstr_fd(char *s, int fd); //write()
void	ft_putendl_fd(char *s, int fd); //write()
void	ft_putnbr_fd(int n, int fd); //write()

//bonus linked list:
t_list	*ft_lstnew(void *content); //malloc()
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *)); //free()
void	ft_lstclear(t_list **lst, void (*del)(void *)); //ft_lstdelone()
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
			// ft_lstclear(), ft_lstnew(), ft_lstadd_back();

//newly added:
char	*ft_strrstr(const char *big, const char *little);
void	ft_free(void **ptr);

//gnl:
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif // BUFFER_SIZE
char	*gnl_splitnl(char **prefix, int i, char *result);
char	*get_next_line(int fd);
char	*get_next_line_bon(int fd);



#endif
