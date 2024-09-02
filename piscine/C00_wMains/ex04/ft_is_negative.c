#include <unistd.h>

void ft_is_negative(int n)
{
	char	result;

	if (n < 0)
	{
		result = 'N';
	}
	else
	{
		result = 'P';
	}
	write(1, &result, 1);
}

int main()
{
	int	numNeg;
	int	numPos;
	int	numNull;
	
	numNeg = -23;
	numPos = 1;
	numNull = 0;
	ft_is_negative(numNeg);
	ft_is_negative(numPos);
	ft_is_negative(numNull);
}
