/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:34:50 by esteiner          #+#    #+#             */
/*   Updated: 2023/09/17 12:34:50 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*get_paths(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	return (envp[i]);
}

char	*find_path(char **paths, char *command_name)
{
	char	*test_path;
	char	*test_path_test;
	int		i;

	i = 0;
	while (paths[i])
	{
		test_path_test = ft_strjoin(paths[i], "/");
		test_path = ft_strjoin(test_path_test, command_name);
		free (test_path_test);
		if (0 == access(test_path, X_OK))
			return (test_path);
		else
			free(test_path);
		i++;
	}
	return (NULL);
}

int	start_program(char *argv, char **envp)
{
	char	*paths;
	char	**split_paths;
	char	**split_command;
	char	*final_path;

	split_command = ft_split(argv, ' ');
	paths = get_paths(envp);
	split_paths = ft_split(paths, ':');
	final_path = find_path(split_paths, split_command[0]);
	ft_free_array(split_paths);
	if (!final_path)
		return (ft_putstr_fd("pipex: ", 2), \
				ft_putstr_fd(split_command[0], 2), \
				ft_putstr_fd(": command not found\n", 2), 127);
	execve(final_path, split_command, envp);
	perror("execve");
	ft_free_array(split_command);
	return (1);
}

int	child_process_middle(t_files *files, char **argv, char **envp, int i)
{
	int	counter;

	dup2 (files->pipe_fd[i][0], 0);
	dup2 (files->pipe_fd[i + 1][1], 1);
	close(files->file_fd[1]);
	close(files->file_fd[0]);
	counter = 0;
	while (files->pipes_number > counter)
	{
		close(files->pipe_fd[counter][0]);
		close(files->pipe_fd[counter][1]);
		counter++;
	}
	exit (start_program(argv[i + 3], envp));
}

bool	open_pipes(t_files *files)
{
	int	i;

	i = 0;
	while (files->pipes_number > i)
	{
		if (pipe(files->pipe_fd[i]) == -1)
			return (false);
		i++;
	}
	return (true);
}
