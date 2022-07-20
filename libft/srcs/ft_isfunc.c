int 	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
int	 	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
int		ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
int		ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
int 	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
