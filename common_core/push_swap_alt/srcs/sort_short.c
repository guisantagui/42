#include "../includes/push_swap.h"

static void    sort_two(t_stack **stack, int len, int reverse)
{
    if (!is_sorted((*stack)->list, reverse, len))
        swap(stack);
}

static void    sort_three(t_stack **stack, int len, int reverse)
{
    int ref;

	if (is_sorted((*stack)->list, reverse, len))
        return ;
	if (reverse == 0)
    	ref = find_max((*stack)->list, len);
	else
		ref = find_min((*stack)->list, len);
    if (*(int *)(*stack)->list->content == ref)
    {
        swap(stack);
		rotate(stack);
		swap(stack);
		rrotate(stack);
    }
    else if (*(int *)(*stack)->list->next->content == ref)
	{
        rotate(stack);
		swap(stack);
		rrotate(stack);
	}
	sort_two(stack, len, reverse);
}

static void	sort_four(t_stack **a, t_stack **b, int len, int reverse)
{
	int	ref;

	if (reverse == 0)
		ref = find_min((*a)->list, len);
	else
		ref = find_max((*a)->list, len);
	if (is_sorted((*a)->list, reverse, len))
		return ;
	if (*(int *)(*a)->list->content != ref)
	{
		push(a, b);
		sort_three(a, len - 1, reverse);
		push(b, a);
		swap(a);
	}
	if (!is_sorted((*a)->list, reverse, len))
	{
		push(a, b);
		sort_three(a, len - 1, reverse);
		push(b, a);
	}
}

void	sort_three_fast(t_stack **stack, int len, int reverse)
{
	int ref;

	if (is_sorted((*stack)->list, reverse, len))
        return ;
	if (reverse == 0)
    	ref = find_max((*stack)->list, len);
	else
		ref = find_min((*stack)->list, len);
	if (*(int *)(*stack)->list->content == ref)
    {
        rotate(stack);
        if (!is_sorted((*stack)->list, reverse, len))
            swap(stack);
    }
    else if (*(int *)(*stack)->list->next->content == ref)
    {
        rrotate(stack);
        if (!is_sorted((*stack)->list, reverse, len))
            swap(stack);
    }
    else
        swap(stack);
}

void	sort_four_fast(t_stack **a, t_stack **b, int len, int reverse)
{
	int ref;

	if (is_sorted((*a)->list, reverse, len))
        return ;
	if (reverse == 0)
    	ref = find_min((*a)->list, len);
	else
		ref = find_max((*a)->list, len);
	if (*(int *)(*a)->list->next->content == ref)
		rotate(a);
	if (*(int *)(*a)->list->next->next->content == ref)
		rrotate(a);
	if (*(int *)(*a)->list->next->next->next->content == ref)
		rrotate(a);
	if (*(int *)(*a)->list->content == ref)
	{
		push(a, b);
		sort_three_fast(a, len, reverse);
		push(b, a);
	}
}

void    sort_short(t_stack **a, t_stack **b, int len, int reverse)
{
	if (len == 2)
        sort_two(a, len, reverse);
    else if (len == 3 && (*a)->size > 3)
        sort_three(a, len, reverse);
	else if (len == 3 && (*a)->size == 3)
		sort_three_fast(a, len, reverse);
    else if (len == 4 && (*a)->size > 4)
        sort_four(a, b, len, reverse);
	else if (len == 4 && (*a)->size == 4)
		sort_four_fast(a, b, len, reverse);
	/*
    else if (len == 5)
        sort_five(a, b, len, reverse);
	*/
}












/*
static void	sort_four(t_list **a, t_list **b, int len, int reverse)
{
	int	ref;

	if (reverse == 0)
		ref = find_min(*a, len);
	else
		ref = find_max(*a, len);
	if (is_sorted(*a, reverse))
		return ;
	if (*(int *)(*a)->next->next->content == ref)
		rrotate(a);
	if (*(int *)(*a)->next->next->next->content == ref)
		rrotate(a);
	while (*(int *)(*a)->content != ref)
		rotate(a);
	if (*(int *)(*a)->content == ref)
	{
		push(a, b);
		//ft_printf("now runs sort_three\n");
		//print_list(*a);
		sort_three(a, len - 1, reverse);
		//ft_printf("now sort_three ends\n");
		push(b, a);
		//print_list(*a);
		return ;
	}
}

static void	sort_five(t_list **a, t_list **b, int len, int reverse)
{
	int	ref;

	if (reverse == 0)
		ref = find_min(*a, len);
	else
		ref = find_max(*a, len);
	if (is_sorted(*a, reverse))
		return ;
	if (*(int *)(*a)->next->next->next->content == ref)
		rrotate(a);
	if (*(int *)(*a)->next->next->next->next->content == ref)
		rrotate(a);
	while (*(int *)(*a)->content != ref)
		rotate(a);
	if (*(int *)(*a)->content == ref)
	{
		push(a, b);
		sort_four(a, b, len - 1, reverse);
		push(b, a);
		return ;
	}
}
*/