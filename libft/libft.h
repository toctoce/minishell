/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:28:05 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/06 16:08:17 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <ctype.h>
# include <stdarg.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1023
# endif
# define OPEN_MAXI 256
# define TRUE 1
# define FALSE 0
# define ERROR 0
# define SUCCESS 1
# define FAIL 2
# define FT_NULL 0

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
int		ft_isalpha(int c);
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(char c);
void	*ft_memset(void *b, int c, size_t len);
int		ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *havstack, const char *needle, size_t len);
char	*ft_strdup(const char *s1);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_atoi(const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*get_next_line(int fd);
char	*gnl_strjoin_and_free(char *storage, char *buf);
void	gnl_free(char **address);
int		gnl_char_index(const char *str, char c);
int		gnl_strlen(char *str);
char	*gnl_strdup(char *src, int len);
char	*gnl_strjoin(char *s1, char *s2);
int		ft_printf(const char *format, ...);
int		ft_handle_specifier(char specifier, va_list ap);
int		ft_tolower(int c);
int		ft_spec_diu(va_list ap, char specifier);
int		ft_spec_u(va_list ap);
int		ft_spec_di(va_list ap);
int		ft_spec_p(va_list ap);
int		ft_spec_x(va_list ap, char specifier);
char	*ft_read_file(int fd);
int		ft_index_str(char *str, char c);
char	*ft_strndup(char *src, int len);

#endif
