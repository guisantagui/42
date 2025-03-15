#include "../includes/push_swap.h"

static void    sort_two(t_list **lst, int len, int reverse)
{
    if (!is_sorted(*lst, reverse, len))
        swap(*lst);
}

static void    sort_three(t_list **lst, int len, int reverse)
{
    int ref;

	if (is_sorted(*lst, reverse, len))
        return ;
	if (reverse == 0)
    	ref = find_max(*lst, len);
	else
		ref = find_min(*lst, len);
    if (*(int *)(*lst)->content == ref)
    {
        swap(*lst);
		rotate(lst);
		swap(*lst);
		rrotate(lst);
    }
    else if (*(int *)(*lst)->next->content == ref)
	{
        rotate(lst);
		swap(*lst);
		rrotate(lst);
	}
	sort_two(lst, len, reverse);
}

static void	sort_four(t_list **a, t_list **b, int len, int reverse)
{
	int	ref;

	if (reverse == 0)
		ref = find_min(*a, len);
	else
		ref = find_max(*a, len);
	if (is_sorted(*a, reverse, len))
		return ;
	if (*(int *)(*a)->content != ref)
	{
		push(a, b);
		sort_three(a, len - 1, reverse);
		push(b, a);
		swap(*a);
	}
	if (!is_sorted(*a, reverse, len))
	{
		push(a, b);
		sort_three(a, len - 1, reverse);
		push(b, a);
	}
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
void    sort_short(t_list **a, t_list **b, int len, int reverse)
{
	if (len == 2)
        sort_two(a, len, reverse);
    else if (len == 3)
        sort_three(a, len, reverse);
    else if (len == 4)
        sort_four(a, b, len, reverse);
	/*
    else if (len == 5)
        sort_five(a, b, len, reverse);
	*/
}