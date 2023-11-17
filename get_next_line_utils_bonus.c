#include "get_next_line_bonus.h"

int	ft_strchr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*ans;

	i = 0;
	while (s[i])
		i++;
	if (i == 0)
		return (NULL);
	ans = malloc(sizeof(char) * i + 1);
	if (!ans)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ans[i] = s[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

int	ft_lstadd_back(t_list **lst, char *s)
{
	t_list	*node;
	t_list	*curr;

	node = malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->next = NULL;
	node->data = s;
	if (!lst || !(*lst))
		*lst = node;
	else
	{
		curr = *lst;
		while (curr->next)
			curr = curr->next;
		curr->next = node;
	}
	return (1);
}

void	set_backup(t_list *curr, t_list **list)
{
	int		nl_idx;
	char	*back_up;
	char	*s;
	t_list	*new;

	nl_idx = ft_strchr(curr->data);
	back_up = NULL;
	if (nl_idx == -1)
		*list = NULL;
	else
	{
		s = curr->data + nl_idx + 1;
		back_up = ft_strdup(s);
		if (!back_up)
		{
			*list = NULL;
			return ;
		}
		new = malloc(sizeof(t_list));
		new->next = NULL;
		new->data = back_up;
		*list = new;
	}
}
