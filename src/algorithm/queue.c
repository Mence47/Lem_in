/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 20:08:11 by rtroll            #+#    #+#             */
/*   Updated: 2019/02/20 19:43:29 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_delete_queue(t_queue **q)
{
	while (ft_dequeue(*q) != NULL)
		;
	free(*q);
	*q = NULL;
}

t_list	*ft_new_node(t_node *node)
{
	t_list *tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	tmp->next = NULL;
	tmp->item = node;
	return (tmp);
}

t_queue	*ft_create_queue(void)
{
	t_queue *q;

	q = (t_queue*)malloc(sizeof(t_queue));
	q->head = NULL;
	q->tail = NULL;
	return (q);
}

void	ft_enqueue(t_queue *q, t_node *node)
{
	t_list *tmp;

	tmp = ft_new_node(node);
	if (q->tail == NULL)
	{
		q->head = tmp;
		q->tail = q->head;
		return ;
	}
	q->tail->next = tmp;
	q->tail = tmp;
}

t_node	*ft_dequeue(t_queue *q)
{
	t_node *tmp;
	t_list *tmp2;

	if (q == NULL || q->head == NULL)
		return (NULL);
	tmp = q->head->item;
	tmp2 = q->head;
	q->head = q->head->next;
	if (q->head == NULL)
		q->tail = NULL;
	free(tmp2);
	return (tmp);
}
