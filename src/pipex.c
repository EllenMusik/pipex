/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:34:50 by esteiner          #+#    #+#             */
/*   Updated: 2023/08/30 12:34:50 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	child_process_1(t_files *files, char **argv, char **envp)
{
	int	counter;

	if (dup2(files->file_fd[0], 0) == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(1);
	}
	dup2(files->pipe_fd[0][1], 1);
	close(files->file_fd[1]);
	close(files->file_fd[0]);
	counter = 0;
	while (files->pipes_number > counter)
	{
		close(files->pipe_fd[counter][0]);
		close(files->pipe_fd[counter][1]);
		counter++;
	}
	exit(start_program(argv[2], envp));
}

int	child_process_2(t_files *files, char **argv, char **envp, int i)
{
	int	counter;

	dup2 (files->file_fd[1], 1);
	dup2 (files->pipe_fd[i][0], 0);
	close(files->file_fd[0]);
	close(files->file_fd[1]);
	counter = 0;
	while (files->pipes_number > counter)
	{
		close(files->pipe_fd[counter][0]);
		close(files->pipe_fd[counter][1]);
		counter++;
	}
	exit (start_program(argv[i + 3], envp));
}

int	pipex2(char **argv, char **envp, t_files *files, int i)
{
	int	pid2;
	int	status;

	pid2 = fork();
	if (pid2 < 0)
		return (ft_putstr_fd("fork last failed\n", 2), 1);
	if (pid2 == 0)
		child_process_2(files, argv, envp, i);
	i = 0;
	while (files->pipes_number > i)
	{
		close(files->pipe_fd[i][0]);
		close(files->pipe_fd[i][1]);
		i++;
	}
	close(files->file_fd[0]);
	close(files->file_fd[1]);
	waitpid(pid2, &status, 0);
	return (status);
}

int	pipex1(char **argv, char **envp, t_files *files)
{
	int	pid1;
	int	status;
	int	i;

	i = 0;
	status = 0;
	pid1 = fork ();
	if (pid1 < 0)
		return (ft_putstr_fd("fork first failed\n", 2), 1);
	if (pid1 == 0)
		child_process_1(files, argv, envp);
	while (argv[i + 3 + 2])
	{
		pid1 = fork ();
		if (pid1 < 0)
			return (ft_putstr_fd("fork failed\n", 2), 1);
		if (pid1 == 0)
			child_process_middle(files, argv, envp, i);
		i++;
	}
	status = pipex2(argv, envp, files, i);
	return (status);
}

int	main(int ac, char **av, char **envp)
{
	int		status;
	t_files	files;

	if (ac < 5)
		return (ft_putstr_fd("at least 5 arguments needed\n", 2), 1);
	files.file_fd[0] = open(av[1], O_RDONLY);
	files.file_fd[1] = open(av[ac - 1], O_RDWR | O_TRUNC, 0666);
	if (files.file_fd[1] == -1)
	{
		files.file_fd[1] = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
		if (files.file_fd[1] == -1)
			return (ft_putstr_fd("outfile could not be opened!\n", 2), 1);
	}
	files.pipes_number = ac - 4;
	if (!open_pipes(&files))
		return (ft_putstr_fd("pipe failed :c\n", 2), 1);
	status = pipex1(av, envp, &files);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	return (status);
}
