#include "../includes/push_swap.h"
void	free_char2(char ***a_map_el2)
{
    size_t	i;
    char	**char2;

    i = 0;
    char2 = *a_map_el2;
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

int     *create_int1args(char **args) {
    int *int1args;
    size_t nb_args;
    size_t i;

    i = 0;
    nb_args = char2len(args);
    int1args = (int *) ft_calloc(nb_args, sizeof(int));
    if (!int1args)
        return (NULL);
    while (i < nb_args)
    {
        int1args[i] = ft_atol(args[i]);
        i++;
    }
    return (int1args);
}
char    **create_char2args(int size, char **args) {
    char **char2args;
    size_t i;

    i = 0;
    char2args = NULL;
    // Si le programme est lancé avec un seul argument, on split ce dernier
    if (size == 1)
        char2args = ft_split(args[0], ' ');
    // Sinon on utilise les arguments passés en paramètre tels quels
    else {
        char2args = (char **) ft_calloc(char2len(args), sizeof(char *));
        while (i < size)
        {
            char2args[i] = ft_strdup(args[i]);
            i++;
        }
    }
    return (char2args);
}

int *ft_extract_nbrs_from_args(int argc, char **argv)
{
    char **char2args;
    int *int1args;
    // gerer argv[1] = "1 2 3 4 5" et argv[2] = 1 =>erreur entree utilisateur
    if (argc == 1)
        return (NULL);
    char2args = create_char2args(argc - 1, &argv[1]);
    if (char2args == NULL)
        return (NULL);
    int1args = create_int1args(char2args);
    free_char2(&char2args);
    return (int1args);
}
