/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:04:04 by rtroll            #+#    #+#             */
/*   Updated: 2019/03/16 18:48:24 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../src/libft/libft.h"
# define START 1
# define END 2
# define REGULAR 0
# define INF 2000000
# define CHECK(x) if (x == NULL) return (NULL)
# define CHECK_VOID(x) if (x == NULL) return

typedef struct			s_stack
{
	struct s_list		*top;
}						t_stack;

typedef struct			s_queue
{
	struct s_list		*head;
	struct s_list		*tail;
}						t_queue;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_list
{
	struct s_list		*next;
	struct s_node		*item;
}						t_list;

typedef struct			s_node
{
	char				*name;
	int					tag;
	int					dist;
	struct s_node		*prev;
	int					ant;
	struct s_point		coord;
	struct s_list		*adj;
	struct s_list		*alt;
}						t_node;

typedef struct			s_paths
{
	unsigned int		count;
	unsigned int		turns;
	struct s_list		**paths;
}						t_paths;

typedef struct			s_graph
{
	unsigned int		count;
	struct s_node		**nodes;
}						t_graph;

t_node					*ft_make_room(char *str, int a, int b, int *flag);
void					ft_expand_graph(t_graph **graph, t_node *room);
t_graph					*ft_empty_graph();
t_bool					ft_is_name(char *name, t_graph *graph);
void					ft_make_link(t_graph **graph, char *a, char *b);
t_paths					*ft_get_paths(t_graph *graph, unsigned int ants,
									t_list **cross);
t_list					*ft_new_node(t_node *node);
void					ft_enqueue(t_queue *q, t_node *node);
t_node					*ft_dequeue(t_queue *q);
t_queue					*ft_create_queue(void);
void					ft_add_to_list(t_list **list, t_node *link);
t_list					*ft_bfs(t_paths **paths, t_node *start);
t_node					*ft_find_start(t_graph *graph);
void					ft_print_result(t_paths *paths, unsigned int ants);
unsigned int			ft_list_len(t_list *list);
t_node					*ft_find_room(t_graph *graph, char *name);
void					ft_delete_queue(t_queue **q);
void					ft_delete_list(t_list **list);
void					ft_delete_paths(t_paths **paths);
void					ft_delete_graph(t_graph **graph);
t_list					*ft_list_dup(t_list *list);
void					ft_print_error_a(char **str);
void					ft_command_a(char *line, int *flag);
t_bool					ft_add_room_a(t_graph **graph, int *flag, char *line);
t_bool					ft_in_list(t_list *list, t_node *node);
t_list					*ft_return_path(t_node *end);
int						ft_in_paths(t_paths *paths, t_node *node);
void					ft_in_alt(t_node *node, t_node *prev, t_queue *alt);
void					ft_in_q(t_node *node, t_node *prev, t_list **visit,
						t_queue *q);
t_node					*ft_find_end(t_graph *graph);
void					ft_join(char **file, char **line);
void					ft_sort_paths(t_paths *paths);
t_node					*ft_pop(t_stack *s);
void					ft_push(t_stack *s, t_node *node);
t_stack					*ft_create_stack(void);
void					ft_delete_stack(t_stack **s);
t_list					*ft_find_path(t_node *start, t_paths *paths);
void					ft_calc_dist(t_graph *graph, t_paths *paths);
void					ft_delete_elem(t_list **list, t_node *node);
t_paths					*ft_finder(t_graph *graph, unsigned int ant);
unsigned int			ft_turn_count(t_paths *path, unsigned int ants,
										t_list *new);
t_paths					*ft_empty_paths(void);
t_bool					ft_is_way(t_node *node, t_paths *paths, t_list *v);
void					ft_expand_paths(t_paths **paths, t_list *new_path);
void					ft_calc_dist_start(t_graph *graph, t_paths *paths,
							t_list **cross);
#endif
