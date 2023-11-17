#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*data;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		ft_strchr(char *s);
char	*ft_strdup(char *s);
void	set_backup(t_list *curr, t_list **list);
int		ft_lstadd_back(t_list **lst, char *s);

#endif
