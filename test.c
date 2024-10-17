
int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
	while (1)
	{
		set->input = readline();
		set->cmd = ft_split(set->input);
		execve(*cmd, cmd, env);
	}
	return (0);
}
