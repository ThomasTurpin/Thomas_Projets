

int	ft_lstsize(t_list *begin_list)
{
	int	len;

	len = 0;
	while (begin_list != NULL)
	{
		len++;
		begin_list = begin_list->next;
	}
	return (len);
}
