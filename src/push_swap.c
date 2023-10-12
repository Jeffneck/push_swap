#include "../includes/push_swap.h"
#include "../includes/libft/libft.h"
/*
Ensemble des fonctions qui calculent les opérations optimales à effectuer sur les stacks 
pour trier les entiers le plus rapidement possible dans la stack A
*/
void    algo_3_stack(t_stconfig *stA, t_stconfig *stB)
{
    //trouver la position de max et min puis faire les op correspondantes
    size_t pos_min; 
    size_t pos_max;

    pos_min = find_pos_min_stack(stA);
    pos_max = find_pos_max_stack(stA);
    if (pos_min == 0)
    {
        if (pos_max == 2)
            return; 
        else
            printf("sa\nra\n");
    }
    else if (pos_max == 0)
    {
        if (pos_min == 1)
            printf("ra\n");
        else
            printf("sa\nrra\n");
    }
    else 
    {
        if (pos_min == 1)
            printf("sa\n");
        else
            printf("rra\n");
    }
    
}

void    algo_5_stack(t_stconfig *stA, t_stconfig *stB)
{
    printf("pb\npb");
    if ( 

    )
}
t_chuncks *determine_chuncks(t_stconfig *stA)
{
    t_chuncks *ch;
    
    ch = (t_chuncks *) malloc (sizeof(t_chuncks));
    if (ch == NULL)
        return(NULL);
    if (stA->size < 200)
        ch ->nb_chuncks = 5;
    else
        ch->nb_chuncks = 11;
    ch->min_stA = find_min_stack(stA); //ecrire la fonction 
    ch->max_stA = find_max_stack(stA); //ecrire la fonction 
    ch->range = (ch->max_stA - ch->min_stA) / ch->nb_chuncks;
    return (ch);
}

int    algo_big_stack(t_stconfig *stA, t_stconfig *stB)
{
    t_chuncks *chuncks;
    int movement;
    
    chuncks = determine_chuncks(stA);
    //fonction 1
    while (stA->top)
    {
        movement = best_movement_possible(chuncks, stA); // coder la fonction (3 = 3 x ra / -5 = 5 x rra, 0 = not move)
        
        while (movement > 0)
        {
            //ra
            movement--;
        }
        while (movement < 0)
        {
            //rra
            movement++;
        }
        //pb
    }
    //fonction 2
    //chercher stBmax et déterminer si rb ou rrb est le plus intéressant
    //push a
}

void    sort_stack(t_stconfig *stA, t_stconfig *stB)
{
    if (stA->size < 3)
        algo_3_stack(stA, stB);
    else if (stA->size < 5)
        algo_5_stack(stA, stB);
    else
        algo_big_stack(stA, stB);
    
}
int    main(int argc, char *argv[]) 
{
    t_stconfig *stA;
    t_stconfig *stB;
    int *tab;
    size_t size_tab;

    if (argc < 2)
        return;
    tab = ft_args_to_int_tab(argc - 1, &argv[1]);
    stA = ft_create_stack(tab, (size_t)(argc - 1));
    stB = ft_create_stack(NULL, 0);
    sort_stack(stA, stB);
    return (0);
}