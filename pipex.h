/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:34:50 by esteiner          #+#    #+#             */
/*   Updated: 2023/08/30 12:35:45 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <sys/wait.h>
# include <stdbool.h>

typedef struct s_files
{
	int		pipes_number;
	int		file_fd[2];
	int		pipe_fd[1024][2];
}				t_files;

int		start_program(char *argv, char **envp);
char	*find_path(char **paths, char *command_name);
char	*get_paths(char **envp);
int		child_process_middle(t_files *files, char **argv, char **envp, int i);
bool	open_pipes(t_files *files);

#endif //PIPEX_H
