/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:46:39 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/28 15:02:14 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*str;

	i = 0;
	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>
#include <stdlib.h>
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

// Ejemplo de función que será pasada a ft_strmapi
char to_upper(unsigned int index, char c) {
    (void)index; // Marca el parámetro como no utilizado
    if (c >= 'a' && c <= 'z') {
        return c - 32; // Convierte a mayúscula
    }
    return c; // Devuelve el mismo carácter si no es minúscula
}

char reverse_case(unsigned int index, char c) {
    (void)index; // Marca el parámetro como no utilizado
    if (c >= 'a' && c <= 'z') {
        return c - 32; // Convierte a mayúscula
    } else if (c >= 'A' && c <= 'Z') {
        return c + 32; // Convierte a minúscula
    }
    return c; // Devuelve el mismo carácter si no es letra
}

int main(void)
{
    char *result;

    // Caso 1: Convertir a mayúsculas
    result = ft_strmapi("hello", to_upper);
    printf("Uppercase: %s\n", result); // Esperado: "HELLO"
    free(result);

    // Caso 2: Invertir el caso de las letras
    result = ft_strmapi("Hello World", reverse_case);
    printf("Reverse case: %s\n", result); // Esperado: "hELLO wORLD"
    free(result);

    return 0;
}*/
