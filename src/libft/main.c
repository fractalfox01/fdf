#include <stdarg.h>
#include "libft.h"
#include <stdio.h>

#define	SWITCH_MAXARGS 12

// void	ft_switch(char *str, ...)
// {
// 	va_list	ap;
// 	int		i;

// 	i = 0;
// 	va_start(ap, str);
// 	if (*str == '>')
// 	{

// 	}
// 	else if (*str == '<')
// 	{

// 	}
// 	else if (*str == '=')
// 	{

// 	}
// }
typedef struct	s_ftprintf
{
	va_list					ap;
	char					*fmt;
	int						ARG_COUNT;
	int						S_FLAG;
	int						C_FLAG;
	int						P_FLAG;
	int						D_FLAG;
	int						I_FLAG;
	int						O_FLAG;
	int						U_FLAG;
	int						X_FLAG;
	int						H_FLAG;
	int						L_FLAG;
} t_ftprintf;

void	parser(struct s_ftprintf *pf, char *fmt)
{

}

void	print_error(void)
{
	ft_putstr("Error...\n");
}

void ft_printf(char *str, ...)
{
	struct s_ftprintf	pf;
	int					i;
	int					c;
	i = 0;
	c = ft_wordcount(str, '%');
	va_start((pf.ap), str);
	while (!(pf.fmt = ft_strchr(str, '%')))
	{
		str += ft_strxlen(str, '%') + 1;
		
	}
// 	while (str[i] != '\0' && str[i] != '%')
// 		ft_putchar(*str++);
// 	str++;
// 	while (*str != 0)
//   {
// 		if (*str == 's')
//     	pf.S_FLAG = 1;
// 		else if (*str == 'd')
// 			pf.D_FLAG = 1;
// 		else if (*str == 'c')
// 			pf.C_FLAG = 1;
// 		str++;
// 		while (*str != '\0' && *str != '%')
// 			str++;
// 		if (*str)
// 			str++;
// 	}
}

int	main(void)
{
	//char	c = 'a';
	// unsigned char c1 = 'b';
	// signed	char	c2 = 'c';

	//char	s[3] = "a1";
	// unsigned char	s1[3] = "b2";
	// signed char	s2[3] = "c3";

	// int	d = 9;
	//unsigned int d1 = 81;
	void	*d2[4] = {(void *)42, (void*)"Hello World", (void *)(-1)};

	ft_printf("%string: %s\tchar: %c\tpointer: %p\n", "Hello", 42, d2);
	// printf("d2 as p: %p\n", d2);
	// printf("d2 as d: %d\n", (int)*d2);
	// printf("d2[1] as p: %p\n", d2[1]);
	// printf("d2[1] as s: %s\n", (char *)d2[1]);
	// printf("d2[1] as p: %p\n", d2[2]);
	// printf("d2[1] as d: %d\n", (signed int)d2[2]);
	// ft_putnbr((signed int)d2[2]);
	// ft_putstr("\n");
	return (0);
}
