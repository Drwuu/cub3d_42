/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:21:17 by lwourms           #+#    #+#             */
/*   Updated: 2021/04/24 17:10:04 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef enum	e_type
{
	CHAR,
	STRING,
	INT,
	UINT,
	LONG,
	ULONG,
	LONGLONG,
	ULONGLONG,
	FLOAT,
	DOUBLE,
	DICT
}				t_type;

typedef	struct	s_dictionary
{
	int 			key;
	void			*value;
}				t_dictionary;

typedef	struct	s_list
{
	void			*content;
	t_type			type;
	struct s_list	*previous;
	struct s_list	*next;
}				t_list;

float			ft_radian(float angle);

int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_ischar(const char *s, const char *c);
int				ft_char_ischars(char c, const char *chars);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isalpha(int c);
int				ft_iswhitespace(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

char			*ft_char_to_str(char c);
size_t			ft_strlen(const char *s);
int				ft_chr_index(const char *str, const char c, int i);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t destsize);
size_t			ft_strlcat(char *dst, const char *src, size_t destsize);
char			*ft_strnstr(const char *haystack, const char *needle,
				size_t len);

int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_itoa_ui(unsigned int n);
char			*ft_itoa_base(const char *base, unsigned long long n);
void			*ft_calloc(size_t size, size_t count);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(const char *s, const char *sep);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			**ft_free_dbl_array(void **datas, int size);

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putstr_at_fd(const char *s, int start, int end, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(void *content, t_type type);
t_list			*ft_lstnew_addback(t_list **alst, void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstfirst(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
				void (*del)(void *));
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
int				ft_lstsize(t_list *lst);

t_vec3			ft_vec3_create(float x, float y, float z);
t_vec3			ft_vec3_sub(t_vec3 vec_1, t_vec3 vec_2);
t_vec3			ft_vec3_normalize(t_vec3 vector);

#endif
