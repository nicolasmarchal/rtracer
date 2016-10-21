#ifndef MY_H_
# define MY_H_

int	my_putchar(char);
int	err_putstr(char *);
int	my_putstr(char *);
int	my_puterror(char *);
int	my_put_nbr(int);
int	my_strlen(char *);
int	my_getnbr(char *);
int	my_getnbr_base(char *, char *);
int	my_strlen(char *);
int	my_strcmp(char *, char *);
char	*get_next_line(const int);
int	my_put_tab(char **);
char	**my_str_to_wordtab(char *, char);
char	*my_strdup(char *);
char	*my_strcat(char *, char *);
char	*my_strcat2(char *, char, char *);
void	str_init(char *, int);
void	free_tab(char **);
int	my_printf(const char *, int, ...);
int	my_strcpy(char *, char *);
char	*my_realloc(char *, int);
int	epur_str(char *);

#endif /* !MY_H_ */
