#include "../includes/push_swap.h"
void	free_char2(char ***a_char2)
{
    size_t	i;
    char	**char2;

    i = 0;
    char2 = *a_char2;
    while (char2[i])
    {
        free(char2[i]);
        char2[i] = NULL;
        i++;
    }
    free(char2);
    char2 = NULL;
}

size_t	char2len(char **char2)
{
    size_t	i;

    i = 0;
    while (char2[i])
        i++;
    return (i);
}

char *char2dup(char **char2)
{
    size_t  i;
    size_t  size;
    char **char2dup;

    i = 0;
    size = char2len(char2);
    char2dup = (char **) ft_calloc(size, sizeof(char *));
    if (!char2dup)
        return (NULL); 
    while (i < size)
    {
        char2dup[i] = ft_strdup(char2[i]);
        if (!char2dup[i])
            return(free_char2(char2dup), NULL); 
        i++;
    }
    return (char2dup);
}

int ft_issign(char c)
{
    return (c == '+' || c == '-');
}