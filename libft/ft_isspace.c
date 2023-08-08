#include "libft.h"

int ft_isspace(char c)
{
    if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
        return (TRUE);
    return (FALSE);
}
