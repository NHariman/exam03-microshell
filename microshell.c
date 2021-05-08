#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	ft_puterr(char *str, int nb)
{
	write(2, str, ft_strlen(str));
	return (nb);
}

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return(s1[i] - s2[i]);
	
}

typedef struct s_shell
{
	char **envp;

}				t_shell;

t_shell g_shell;

void	exec_cd(char *str)
{
	int dir;

	dir = chdir(str);
	if (dir == -1)
	{
		ft_strerr("error: cd: cannot change directory to ", 1);
		ft_strerr(str, 1);
		ft_strerr("\n");
	}
}

int	main(int ac, char **av, char **envp)
{
	g_shell.envp = envp;
	char **semicol;
	if (ac == 1)
		return(0);
	if (strcmp("cd", av[1]))
		exec_cd(av[1]);

}