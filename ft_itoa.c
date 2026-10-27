#include "libft.h"

static size_t	num_len(long n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	nb;

	nb = n;
	len = num_len(nb);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	len--;
	str[len] = nb % 10 + '0';
	nb /= 10;
	while (nb > 0)
	{
		len--;
		str[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
