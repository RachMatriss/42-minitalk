/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 09:47:24 by ramedjra          #+#    #+#             */
/*   Updated: 2023/02/17 10:43:19 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*f_itoa function is to print long int num */
static void	f_itoa(long int num, char *base, int n, int *leng)
{
	if (num < 0)
	{
		num *= (-1);
		*leng += write(1, "-", 1);
	}
	if (num >= n)
		f_itoa(num / n, base, n, leng);
	*leng += 1;
	ft_putchar_fd(base[num % n], 1);
}

/*f_utoi function is to print long unsigned int num*/
static void	f_utoi(long unsigned int num, char *base, unsigned int n, int *leng)
{
	if (num >= n)
		f_utoi(num / n, base, n, leng);
	*leng += 1;
	ft_putchar_fd(base[num % n], 1);
}

/* ft_printstr function is to print str || pntr */
static void	ft_printstr(va_list args, int *leng, int pntr)
{
	char			*tmp;

	if (pntr == 0)
	{
		tmp = va_arg(args, char *);
		if (!tmp)
		{
			*leng += write(1, "(null)", 6);
			return ;
		}
		*leng += write(1, tmp, ft_strlen(tmp));
	}
	else if (pntr == 1)
	{
		*leng += write(1, "0x", 2);
		f_utoi(va_arg(args, unsigned long), "0123456789abcdef", 16, leng);
	}
}

/* = = = check format = = =
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
*/
static void	ft_format(va_list args, const char frmt, int *leng)
{
	if (frmt == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		*leng += 1;
	}
	else if (frmt == 's')
		ft_printstr(args, leng, 0);
	else if (frmt == 'p')
		ft_printstr(args, leng, 1);
	else if (frmt == 'd' || frmt == 'i')
		f_itoa(va_arg(args, int), "0123456789", 10, leng);
	else if (frmt == 'u')
		f_utoi(va_arg(args, unsigned int), "0123456789", 10, leng);
	else if (frmt == 'x')
		f_utoi(va_arg(args, unsigned int), "0123456789abcdef", 16, leng);
	else if (frmt == 'X')
		f_utoi(va_arg(args, unsigned int), "0123456789ABCDEF", 16, leng);
	else if (frmt == '%')
		*leng += write(1, "%", 1);
}

/*ft_printf function is == printf*/
/* == Note ==
	Function called with varying number of arguments of varying types
	void va_start(va_list ap, last)
		-> last: last parameter of which calling function knows the type
 		-> ap: va_list to initialize
 	void type va_arg(va_list ap, type)
 		-> ap: va_list initialized by va_start()
 		-> type: a type name specified
 		-> each call modifies ap so that next call returns next argument
 	void va_end(va_list ap)
 		-> signlas there are no further args
 		-> causes ap to be invalidated
 		-> va_start() must be matched by va_end() from within same funtion
*/
int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		leng;

	i = -1;
	leng = 0;
	va_start(args, s);
	while (s[++i])
	{
		if (s[i] == '%')
			ft_format(args, s[++i], &leng);
		else
			leng += write(1, &s[i], 1);
	}
	va_end(args);
	return (leng);
}
