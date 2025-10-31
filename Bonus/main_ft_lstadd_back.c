/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_lstadd_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 20:35:36 by dansimoe          #+#    #+#             */
/*   Updated: 2025/10/31 01:15:11 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include <bsd/string.h>
#include <signal.h>
#include <setjmp.h>

#define GREEN "\033[92m"
#define GREY  "\033[90m"
#define BLACK_ON_GREEN "\033[1;30;102m"
#define WHITE_ON_RED "\033[1;37;41m"
#define ITALIC_BLUE "\033[3;34m"
#define RED "\033[91m"
#define RESET "\033[0m"

static sigjmp_buf jump_buffer;

void segfault_handler(int sig)
{
    (void) sig;
    siglongjmp(jump_buffer, 1);
}

t_list	*lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list); 
}

int	main()
{
	t_list			*header;
	t_list			*second;
	t_list			*third;
	t_list			*temp;
	t_list			*new;
	//int				expi[4];
	//int				subi[4];
	int				t;
	int				j;
	int				success = 0;
	int				i = 0;
	int				fd;
	char			*function = "ft_lstadd_back";

	signal(SIGSEGV, segfault_handler);
	
	fd = open("./build/res_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Failed to open file.");
		return (-1);
	}
	
	///////////Test 1///////////
	char	exp[4][1024] = {"ola", "tudo", "bem", "contigo?"};
	char	sub[4][1024] = {"ola", "tudo", "bem", "contigo?"};
	header = lstnew(sub[0]);
	second = lstnew(sub[1]);
	third = lstnew(sub[2]);
	header->next = second;
	second->next = third;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		new = lstnew(sub[3]);
		ft_lstadd_back(&header, new);
		if (new)
		{
			t = 0;
			j = -1;
			temp = header;
			while (temp)
			{
				t += strcmp(temp->content, exp[++j]);
				temp = temp->next;
			}
			if (t == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for \"%s\". ", i, exp[0]);
				printf("Expected: ");
				j =-1;
				while (++j < 4)
					printf("\\\"%s\"", exp[j]);
				printf(" My own: ");
				j = -1;
				temp = header;
				while (temp)
				{
					printf("\\\"%s\"", (char *)temp->content);
					temp = temp->next;
					free(header);
					header = temp;
				}
				printf(RESET "\n");
				success++;
			}
			else
			{
				printf(RED "✗ [%d] Testing for \"%s\". ", i, exp[0]);
				printf("Expected: ");
				j = -1;
				while (++j < 4)
					printf("\\\"%s\"", exp[j]);
				printf(" My own: ");
				j = -1;
				temp = header;
				while (temp)
				{
					printf("\\\"%s\"", (char *)temp->content);
					temp = temp->next;
					free(header);
					header = temp;
				}
				printf(RESET "\n");
			}
		}
		else
			printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: \"(null)\"" RESET "\n", i, exp[0], exp[0]);
	}
	else
		printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, exp[0], exp[0]);
	i++;
  
	///////////Test 1///////////
	char	exp2[4][1024] = {"1", "", "42", "1024"};
	char	sub2[4][1024] = {"1", "", "42", "1024"};
	header = lstnew(sub2[0]);
	second = lstnew(sub2[1]);
	third = lstnew(sub2[2]);
	header->next = second;
	second->next = third;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		new = lstnew(sub2[3]);
		ft_lstadd_back(&header, new);
		if (new)
		{
			t = 0;
			j = -1;
			temp = header;
			while (temp)
			{
				t += strcmp(temp->content, exp2[++j]);
				temp = temp->next;
			}
			if (t == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for \"%s\". ", i, exp2[0]);
				printf("Expected: ");
				j =-1;
				while (++j < 4)
					printf("\\\"%s\"", exp2[j]);
				printf(" My own: ");
				j = -1;
				temp = header;
				while (temp)
				{
					printf("\\\"%s\"", (char *)temp->content);
					temp = temp->next;
					free(header);
					header = temp;
				}
				printf(RESET "\n");
				success++;
			}
			else
			{
				printf(RED "✗ [%d] Testing for \"%s\". ", i, exp2[0]);
				printf("Expected: ");
				j = -1;
				while (++j < 4)
					printf("\\\"%s\"", exp2[j]);
				printf(" My own: ");
				j = -1;
				temp = header;
				while (temp)
				{
					printf("\\\"%s\"", (char *)temp->content);
					temp = temp->next;
					free(header);
					header = temp;
				}
				printf(RESET "\n");
			}
		}
		else
			printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: \"(null)\"" RESET "\n", i, exp2[0], exp2[0]);
	}
	else
		printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, exp2[0], exp2[0]);
	i++;

	///////////Test 1///////////
	char	exp3[4][1024] = {"", "00", "42", "1024"};
	char	sub3[4][1024] = {"", "00", "42", "1024"};
	header = lstnew(sub3[0]);
	second = lstnew(sub3[1]);
	third = lstnew(sub3[2]);
	header->next = second;
	second->next = third;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		new = lstnew(sub3[3]);
		ft_lstadd_back(&header, new);
		if (new)
		{
			t = 0;
			j = -1;
			temp = header;
			while (temp)
			{
				t += strcmp(temp->content, exp3[++j]);
				temp = temp->next;
			}
			if (t == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for \"%s\". ", i, exp3[0]);
				printf("Expected: ");
				j =-1;
				while (++j < 4)
					printf("\\\"%s\"", exp3[j]);
				printf(" My own: ");
				j = -1;
				temp = header;
				while (temp)
				{
					printf("\\\"%s\"", (char *)temp->content);
					temp = temp->next;
					free(header);
					header = temp;
				}
				printf(RESET "\n");
				success++;
			}
			else
			{
				printf(RED "✗ [%d] Testing for \"%s\". ", i, exp3[0]);
				printf("Expected: ");
				j = -1;
				while (++j < 4)
					printf("\\\"%s\"", exp3[j]);
				printf(" My own: ");
				j = -1;
				temp = header;
				while (temp)
				{
					printf("\\\"%s\"", (char *)temp->content);
					temp = temp->next;
					free(header);
					header = temp;
				}
				printf(RESET "\n");
			}
		}
		else
			printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: \"(null)\"" RESET "\n", i, exp3[0], exp3[0]);
	}
	else
		printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, exp3[0], exp3[0]);
	i++;

	///////////Test 1///////////
	int	exp4[4] = {INT_MIN, INT_MAX, 42, 1024};
	int	sub4[4] = {INT_MIN, INT_MAX, 42, 1024};
	header = lstnew(&sub4[0]);
	second = lstnew(&sub4[1]);
	third = lstnew(&sub4[2]);
	header->next = second;
	second->next = third;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		new = lstnew(&sub4[3]);
		ft_lstadd_back(&header, new);
		if (new)
		{
			t = 0;
			j = -1;
			temp = header;
			while (temp)
			{
				if (*(int *)temp->content == exp4[++j])
					t += 0;
				else
					t += 1;
				temp = temp->next;
			}
			if (t == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for %d. ", i, exp4[0]);
				printf("Expected: ");
				j =-1;
				while (++j < 4)
					printf("\\%d", exp4[j]);
				printf(" My own: ");
				j = -1;
				temp = header;
				while (temp)
				{
					printf("\\%d", *(int *)temp->content);
					temp = temp->next;
					free(header);
					header = temp;
				}
				printf(RESET "\n");
				success++;
			}
			else
			{
				printf(RED "✗ [%d] Testing for %d. ", i, exp4[0]);
				printf("Expected: ");
				j = -1;
				while (++j < 4)
					printf("\\%d", exp4[j]);
				printf(" My own: ");
				j = -1;
				temp = header;
				while (temp)
				{
					printf("\\%d", *(int *)temp->content);
					temp = temp->next;
					free(header);
					header = temp;
				}
				printf(RESET "\n");
			}
		}
		else
			printf(RED "✗ [%d] Testing for %d. Expected: %d My own: \"(null)\"" RESET "\n", i, exp4[0], exp4[0]);
	}
	else
		printf(RED "✗ [%d] Testing for %d. Expected: %d My own: <<seg fault>>" RESET "\n", i, exp4[0], exp4[0]);
	i++;

	///////////Test 1///////////
	int	exp5[4] = {0, INT_MAX, 42, 1024};
	int	sub5[4] = {0, INT_MAX, 42, 1024};
	header = lstnew(&sub5[0]);
	second = lstnew(&sub5[1]);
	third = lstnew(&sub5[2]);
	header->next = second;
	second->next = third;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		new = lstnew(&sub5[3]);
		ft_lstadd_back(&header, new);
		if (new)
		{
			t = 0;
			j = -1;
			temp = header;
			while (temp)
			{
				if (*(int *)temp->content == exp5[++j])
					t += 0;
				else
					t += 1;
				temp = temp->next;
			}
			if (t == 0)
			{
				printf(GREEN "✓" GREY " [%d] Testing for %d. ", i, exp5[0]);
				printf("Expected: ");
				j =-1;
				while (++j < 4)
					printf("\\%d", exp5[j]);
				printf(" My own: ");
				j = -1;
				temp = header;
				while (temp)
				{
					printf("\\%d", *(int *)temp->content);
					temp = temp->next;
					free(header);
					header = temp;
				}
				printf(RESET "\n");
				success++;
			}
			else
			{
				printf(RED "✗ [%d] Testing for %d. ", i, exp5[0]);
				printf("Expected: ");
				j = -1;
				while (++j < 4)
					printf("\\%d", exp5[j]);
				printf(" My own: ");
				j = -1;
				temp = header;
				while (temp)
				{
					printf("\\%d", *(int *)temp->content);
					temp = temp->next;
					free(header);
					header = temp;
				}
				printf(RESET "\n");
			}
		}
		else
			printf(RED "✗ [%d] Testing for %d. Expected: %d My own: \"(null)\"" RESET "\n", i, exp5[0], exp5[0]);
	}
	else
		printf(RED "✗ [%d] Testing for %d. Expected: %d My own: <<seg fault>>" RESET "\n", i, exp5[0], exp5[0]);
	i++;
	
	///////////Test 1///////////
	char	exp6[4][1024] = {"00", "42", "1024", "NULL"};
	char	sub6[4][1024] = {"00", "42", "1024", "NULL"};
	header = lstnew(sub6[0]);
	second = lstnew(sub6[1]);
	third = lstnew(sub6[2]);
	header->next = second;
	second->next = third;
	if (sigsetjmp(jump_buffer, 1) == 0)
	{
		ft_lstadd_back(&header, NULL);
		temp = header;
		 while (temp->next)
			temp = temp->next;
		if (strcmp(temp->content, exp6[2]) == 0)
		{
			printf(GREEN "✓" GREY " [%d] Testing for \"%s\". ", i, exp6[0]);
			printf("Expected: ");
			j =-1;
			while (++j < 4)
				printf("\\\"%s\"", exp6[j]);
			printf(" My own: ");
			j = -1;
			temp = header;
			while (temp)
			{
				printf("\\\"%s\"", (char *)temp->content);
				temp = temp->next;
				free(header);
				header = temp;
			}
			printf(RESET "\n");
			success++;
		}
		 else
		{
			printf(RED "✗ [%d] Testing for \"%s\". ", i, exp6[0]);
			printf("Expected: ");
			j = -1;
			while (++j < 4)
				printf("\\\"%s\"", exp6[j]);
			printf(" My own: ");
			j = -1;
			temp = header;
			while (temp)
			{
				printf("\\\"%s\"", (char *)temp->content);
				temp = temp->next;
				free(header);
				header = temp;
			}
			printf(RESET "\n"); 
		} 
	}
	else
		printf(RED "✗ [%d] Testing for \"%s\". Expected: \"%s\" My own: <<seg fault>>" RESET "\n", i, exp6[0], exp6[0]);
	i++;

	///////////RESULT///////////
	if (success == i)
		printf(BLACK_ON_GREEN " PASS " RESET ITALIC_BLUE " %s" RESET "\n\n", function);
	else
		printf(WHITE_ON_RED " FAIL " RESET ITALIC_BLUE " %s" RESET "\n\n", function);

	///////////RESULTS_LOGS///////////
	write(fd, function, strlen(function));
	write(fd, " ", 1);
	if (success / i == 1)
		write(fd, "OK :D 1\n", 8);
	else
		write(fd, "KO :( 0\n", 8);
	close (fd);
	return (0);
}