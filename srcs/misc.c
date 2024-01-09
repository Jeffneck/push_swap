#include "../includes/push_swap.h"

void    free_stack(t_stconfig *st)
{
    // printf("free_stack\n");
    t_stelem    *curr;
    t_stelem    *tmp;

    curr = st->top;
    while(curr)
    {
        tmp = curr->next;
        free(curr);
        curr = tmp;
    }
    free(st);
}

//ajouter a libft
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
}

//ajouter a libft
void    ft_putchar2_endl(char **char2)
{
    // printf("ft_putchar2_endl \n");//
    size_t	i;

    i = 0;
    while (char2[i])
    {
        ft_putstr_fd(char2[i], 1);
        write(1, "\n", 1);
        i++;
    }
}

//ajouter a libft
size_t	char2len(char **char2)
{
    size_t	i;

    i = 0;
    while (char2[i])
        i++;
    return (i);
}

//ajouter a libft
char **char2dup(char **char2)
{
    // printf("char2dup \n");//
    size_t  i;
    size_t  size;
    char **char2dup;

    i = 0;
    size = char2len(char2) + 1;
    char2dup = (char **) ft_calloc(size, sizeof(char *)); //malloc testé
    if (!char2dup)
        return (NULL); 
    while (i < size - 1)
    {
        char2dup[i] = ft_strdup(char2[i]); //malloc testé
        if (!char2dup[i])
            return(free_char2(&char2dup), NULL); 
        i++;
    }
    // ft_putchar2_endl(char2dup);//verif
    return (char2dup);
}

//ajouter a libft
int ft_issign(char c)
{
    return (c == '+' || c == '-');
}