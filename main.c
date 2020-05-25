/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdidier <jdidier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 20:13:47 by jdidier           #+#    #+#             */
/*   Updated: 2020/05/25 21:40:18 by jdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char *line;
	char *line1;
	char *line2;
	int fd;
	int fd1;
	int fd2;
	int ret;
	int ret1;
	int ret2;
	int flag;
	int flag1;
	int flag2;

	ret = 0;
	ret1 = 0;
	ret2 = 0;
	flag = 0;
	flag1 = 0;
	flag2 = 0;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			printf("open error %d\n", fd);
		ret = get_next_line(fd, &line);
		while(ret > 0)
		{
			printf("%d : %s\n", ret, line);
			free(line);
			line = 0;
			ret = get_next_line(fd, &line);
		}
		if (ret <= 0)
		{
			printf("%d : %s\n", ret, line);
			free(line);
			line = 0;
		}
		/*
		ret = get_next_line(fd, &line);
		printf("%d : %s\n", ret, line);
		free(line);
		*/
		if (close(fd) == -1)
			printf("close error %d\n", fd);
	}
	else if (argc == 3)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			printf("open error %d\n", fd);
		if ((fd1 = open(argv[2], O_RDONLY)) == -1)
			printf("open error %d\n", fd1);
		ret = get_next_line(fd, &line);
		ret1 = get_next_line(fd1, &line1);
		while(ret > 0 || ret1 > 0)
		{
			if (!flag)
			{
				printf("line0: %d : %s\n", ret, line);
				free(line);
				line = 0;
			}
			if (!flag1)
			{
				printf("line1: %d : %s\n", ret1, line1);
				free(line1);
				line1 = 0;
			}
			if (ret > 0)
				ret = get_next_line(fd, &line);
			if (!ret && !flag)
			{
				printf("line0: %d : %s\n", ret, line);
				free(line);
				line = 0;
				flag = 1;
			}
			if (ret1 > 0)
				ret1 = get_next_line(fd1, &line1);
			if (!ret1 && !flag1)
			{
				printf("line1: %d : %s\n", ret1, line1);
				free(line1);
				line1 = 0;
				flag1 = 1;
			}
		}
		if (close(fd) == -1)
			printf("close error %d\n", fd);
		if (close(fd1) == -1)
			printf("close error %d\n", fd1);
	}
	else if (argc == 4)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			printf("open error %d\n", fd);
		if ((fd1 = open(argv[2], O_RDONLY)) == -1)
			printf("open error %d\n", fd1);
		if ((fd2 = open(argv[3], O_RDONLY)) == -1)
			printf("open error %d\n", fd2);
		ret = get_next_line(fd, &line);
		ret1 = get_next_line(fd1, &line1);
		ret2 = get_next_line(fd2, &line2);
		while(ret > 0 || ret1 > 0 || ret2 > 0)
		{
			if (!flag)
			{
				printf("line0: %d : %s\n", ret, line);
				free(line);
				line = 0;
			}
			if (!flag1)
			{
				printf("line1: %d : %s\n", ret1, line1);
				free(line1);
				line1 = 0;
			}
			if (!flag2)
			{
				printf("line2: %d : %s\n", ret2, line2);
				free(line2);
				line2 = 0;
			}
			if (ret > 0)
				ret = get_next_line(fd, &line);
			if (!ret && !flag)
			{
				printf("line0: %d : %s\n", ret, line);
				free(line);
				line = 0;
				flag = 1;
			}
			if (ret1 > 0)
				ret1 = get_next_line(fd1, &line1);
			if (!ret1 && !flag1)
			{
				printf("line1: %d : %s\n", ret1, line1);
				free(line1);
				line1 = 0;
				flag1 = 1;
			}
			if (ret2 > 0)
				ret2 = get_next_line(fd2, &line2);
			if (!ret2 && !flag2)
			{
				printf("line2: %d : %s\n", ret2, line2);
				free(line2);
				line2 = 0;
				flag2 = 1;
			}
		}
		if (close(fd) == -1)
			printf("close error %d\n", fd);
		if (close(fd1) == -1)
			printf("close error %d\n", fd1);
		if (close(fd2) == -1)
			printf("close error %d\n", fd2);
	}
	return (0);
}