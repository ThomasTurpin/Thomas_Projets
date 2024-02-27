/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:31:01 by tturpin           #+#    #+#             */
/*   Updated: 2024/02/27 16:50:03 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					push_price;
	int					position;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

t_stack_node			*find_last_node(t_stack_node *head);
void					append_node(t_stack_node **stack, int nbr);
void					create_stack(t_stack_node **a, char **argv);
t_stack_node			*return_cheapest(t_stack_node *stack);
void					print_stack(t_stack_node *top);
void					free_stack(t_stack_node **stack);
void					error_free(t_stack_node **a);
char					**ft_free_mal(char **tab);

void					ft_putstr(char *str);
long					ft_atol(const char *str);
char					**ft_split(char const *s, char c);
size_t					ft_strlen(const char *str);
size_t					ft_strlcpy(char *dest, const char *src, size_t size);

void					set_target(t_stack_node *a, t_stack_node *b);
void					set_cost(t_stack_node *a, t_stack_node *b);
void					find_cheapest(t_stack_node *b);
void					set_position(t_stack_node *stack);

void					do_pa(t_stack_node **a, t_stack_node **b);
void					do_pb(t_stack_node **b, t_stack_node **a);
void					do_rra(t_stack_node **a);
void					do_rrb(t_stack_node **b);
void					do_rrr(t_stack_node **a, t_stack_node **b);
void					do_ra(t_stack_node **a);
void					do_rb(t_stack_node **b);
void					do_rr(t_stack_node **a, t_stack_node **b);
void					do_sa(t_stack_node **a);
void					do_sb(t_stack_node **b);
void					do_ss(t_stack_node **a, t_stack_node **b);

int						get_stack_size(t_stack_node *stack);
t_stack_node			*find_highest(t_stack_node *stack);
t_stack_node			*find_smallest(t_stack_node *stack);

t_stack_node			*return_cheapest(t_stack_node *stack);
void					init_all(t_stack_node *a, t_stack_node *b);
void					rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);
void					reverse_rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);
void					rotate_one(t_stack_node **stack,
							t_stack_node *head_node, char stack_name);
void					do_moves(t_stack_node **a, t_stack_node **b);
void					push_swap(t_stack_node **a, t_stack_node **b);

int						is_digit(char c);
int						is_sign(char c);
int						nb_cmp(const char *s1, const char *s2);
int						argv_number(char *argv);
int						repetition(t_stack_node *a, int nbr);
int						only_zero(char *argv);
int						check_input(char **argv);

void					tiny_sort(t_stack_node **a);
void					nb_five(t_stack_node **a, t_stack_node **b);
int						is_sorted(t_stack_node *stack, int *argc);

#endif
