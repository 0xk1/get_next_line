#include "get_next_line_bonus.h"

void	ft_lstclear(t_list **list)
{
	t_list	*curr;
	t_list	*temp;

	curr = *list;
	if (!curr)
		return ;
	while (curr)
	{
		temp = curr->next;
		if (!curr->next)
			set_backup(curr, list);
		free(curr->data);
		free(curr);
		curr = temp;
	}
}

int	get_line_size(t_list *lst)
{
	int	ans;
	int	i;

	ans = 0;
	while (lst)
	{
		i = 0;
		while (lst->data[i] && lst->data[i] != '\n')
		{
			ans++;
			i++;
		}
		if (lst->data[i] == '\n')
			ans++;
		lst = lst->next;
	}
	return (ans);
}

char	*get_line(t_list **lst)
{
	t_list	*curr;
	char	*line;
	int		i;
	int		j;

	if (!(*lst))
		return (NULL);
	curr = *lst;
	line = malloc(sizeof(char) * get_line_size(*lst) + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (curr)
	{
		i = 0;
		while (curr->data[i] && curr->data[i] != '\n')
			line[j++] = curr->data[i++];
		if (curr->data[i] == '\n')
			line[j++] = '\n';
		curr = curr->next;
	}
	line[j] = '\0';
	ft_lstclear(lst);
	return (line);
}

char	*helper(t_list **lst, int fd)
{
	char	*buffer;
	ssize_t	bytes_read;

	while (1)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			return (get_line(&lst[fd]));
		}
		buffer[bytes_read] = '\0';
		if (!ft_lstadd_back(&lst[fd], buffer))
			return (NULL);
		if (ft_strchr(buffer) != -1)
			return (get_line(&lst[fd]));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_list	*lst[1024];

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0 || (read(fd, NULL, 0) == -1)
		|| BUFFER_SIZE > 0xffffffff)
		return (NULL);
	if (lst[fd] && ft_strchr(lst[fd]->data) != -1)
		return (get_line(&lst[fd]));
	return (helper(lst, fd));
}
