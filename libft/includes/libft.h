/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:27:15 by abrichar          #+#    #+#             */
/*   Updated: 2018/04/10 18:17:21 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>
# define BUFF_SIZE 10

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
typedef struct		s_printf
{
	char			flag_sharp;
	char			flag_zero;
	char			flag_minus;
	char			flag_plus;
	char			flag_space;
	int				width;
	int				precision;
	char			*length;
	char			conversion;
}					t_printf;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int nbr);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(char *src);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *foin,
								const char *aiguille, size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *foin, const char *aiguille);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_swap(int *a, int *b);
int					ft_sort_params(int argc, char **argv);
int					*ft_range(int min, int max);
void				ft_foreach(int *tab, int length, void (*f)(int));
int					ft_count_if(char **tab, int (*f)(char*));
void				ft_display_file(char *name);
char				*ft_except(char *str, char c);
int					get_next_line(const int fd, char **line);
int					match(char *s1, char *s2);
int					nmatch(char *s1, char *s2);
void				ft_putnstr(char *str, int nbr);
short				ft_countnbr(long nbr);
short				ft_countunbr(unsigned long nbr);
void				ft_putzerox(char letter);
char				*ft_itoabaseu(unsigned long nbr, int base, char min);
void				ft_putnbrwp(long nbr, int precision);
void				ft_putstrwp(char *str, int precision);
void				ft_putunbrwp(unsigned long nbr, int precision);
void				ft_putunbr(unsigned long n);
/*
**begin printf
*/
int					ft_printf(const char *restrict format, ...);
int					treat(t_printf *elem, va_list ap);
int					ft_c(int c, t_printf *elem);
int					ft_s(char *str, t_printf *elem);
int					ft_smaj(wchar_t *str, t_printf *elem);
int					ft_d(int nbr, t_printf *elem);
int					ft_l(long nbr, t_printf *elem);
int					ft_x(unsigned long nbr, char letter, t_printf *elem);
int					ft_o(unsigned long nbr, t_printf *elem);
int					ft_p(void *address, t_printf *elem);
int					check_conv(char **str, char *cha, t_printf *elem);
int					ft_percent(t_printf *elem);
int					is_null(t_printf *elem);
int					ft_cwl(wint_t c, t_printf *elem);
int					ft_count_unicode(wchar_t c);
int					ft_count_multiple_unicode(wchar_t *str);
int					ft_oux(unsigned long nbr, char letter, t_printf *elem);
int					ft_invalid_input(char c, t_printf *elem);
int					end_o(char *str, int count, t_printf *elem);
char				*check_flags(char **str, t_printf *elem);
char				*check_width(char **str, t_printf *elem);
char				*check_precision(char **str, t_printf *elem);
char				*check_len(char **s, t_printf *elem);
void				ft_putnbrwp(long nbr, int precision);
void				ft_putunbrwp(unsigned long nbr, int precision);
void				ft_putstrwp(char *str, int precision);
void				two_bytes(wchar_t c);
void				three_bytes(wchar_t c);
void				four_bytes(wchar_t c);
void				ft_unicode(unsigned int c);
/*
**ajout_lemin
*/
void				ft_lstaddlast(t_list **alst, t_list *new);
/*
** ajout corewar
*/
char				*ft_epur_str(char *str);
#endif
