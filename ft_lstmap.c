#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	**tail;
	t_list	*node;
	void	*content;

	if (!f)
		return (NULL);
	head = NULL;
	tail = &head;
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			if (del)
				del(content);
			ft_lstclear(&head, del);
			return (NULL);
		}
		*tail = node;
		tail = &node->next;
		lst = lst->next;
	}
	return (head);
}
