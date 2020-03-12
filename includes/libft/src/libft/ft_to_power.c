unsigned long long	ft_to_power(unsigned long long a, int power)
{
	if (power == 0)
		return (1);
	a = a * ft_to_power(a, power - 1);
	return (a);
}