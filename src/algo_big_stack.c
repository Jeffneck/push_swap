#include "../includes/push_swap.h"
#include "../includes/libft/libft.h"

/*
Concept : tri par insertion amélioré
Algorithme qui divise la stack A en chuncks
les chuncks sont des portions entre nb_max et nb_min, 
le nombre de chuncks varie en fonction de la taille de la pile à trier (au + optimal)
on traite les chuncks 1 par 1 dans l'ordre croissant
ensuite on trouve le nb de la chunck courante le plus facile a envoyer sur B (on le met au top stA puis push b)
les nb d'une même chunck ne seront pas triés dans b, on s'en occuppe au moment de renvoyer le tout sur A

amélioration possible : trier directement les éléments envoyés à stB car on peut utiliser les commandes doubles (ss, rr, rrr) si on s'aperçoit que les 2 stacks 


*/
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
    ch->min_stA = min_in_stack(*stA); //ecrire la fonction 
    ch->max_stA = max_in_stack(*stA); //ecrire la fonction 
    ch->range = (ch->max_stA - ch->min_stA) / ch->nb_chuncks;
    return (ch);
}
int is_in_chunck(t_chuncks *chuncks, int curr_chunck, int nb)
{
    int ch_min; 
    int ch_max;

    ch_min = chuncks->min_stA + chuncks->range * curr_chunck; //verifier le calcul
    ch_max = chuncks->min_stA + chuncks->range * (curr_chunck + 1) - 1; //verifier le calcul
    if (nb >= ch_min && nb <= ch_max)
        return (1);
    return (0);
}
int nearest_chunck_nb(t_chuncks *chuncks, int curr_chunck, t_stconfig *stA)
{
    /*On recherche le nb du chunck le plus proche en de la 1re et deuxième moitié de la stack
    On ne garde que le plus proche
    return -1 si la stA ne contient aucun élément du chunck.
    */
    t_stelem *curr_node;
    int nearest_top;
    int nearest_bot;
    size_t nb_moves;

    curr_node = stA->top;
    nearest_top = -1;
    nearest_bot = -1;
    nb_moves = 0;
    
    if (stA == NULL)
        return (-2);//que faire si stA est NULL;
    while (nb_moves++ <= (stA->size / 2))
    {
        if (is_in_chunck(chuncks, curr_chunck, curr_node->data))
        {
            nearest_top = nb_moves;
            break; 
        }
        curr_node = curr_node->next;
    }
    curr_node = stA->bottom;
    nb_moves = 0;
    while (nb_moves++ < (stA->size / 2))
    {
        if (is_in_chunck(chuncks, curr_chunck, curr_node->data))
        {
            nearest_bot = nb_moves + 1;// +1 pour le
            break; 
        }
        curr_node = curr_node->prev;
    }
    if (nearest_top <= nearest_bot || nearest_bot == -1)
        return (nearest_top);
    return (nearest_bot);
}

void    presort_and_push_chuncks(t_chuncks *chuncks, t_stconfig *stA, t_stconfig *stB)
{
    /*
        on divise en portions puis en envoie les portions dans la stack B dans l'ordre croissant. 
        les portions sont triées mais pas les nombres qu'elles contiennent.
    */
    int current_chunck;
    int movement; //détermine le nb de moves a effectuer pour mettrehold_first ou hold_second au top de stA

    current_chunck = 0;
    while (stA->top)
    {
        //boucle pour incrémenter la valeur du chunck quand aucun nb de stA n'est compris dans current_chunck
        while (nearest_chunck_nb(chuncks, current_chunck, stA) == -1)
            current_chunck++;
        movement = nearest_chunck_nb(chuncks, current_chunck, stA);
        while (movement > 0)
        {
            operation_manager(stA, stB, ft_strsplit("ra", ','));
            movement--;
        }
        while (movement < 0)
        {
            operation_manager(stA, stB, ft_strsplit("rra", ','));
            movement++;
        }
        operation_manager(stA, stB, ft_strsplit("pb", ','));        
    }
}
void    return_sorted_in_stA(t_stconfig *stA, t_stconfig *stB)
{
    //mettre en haut de la liste le premier nb > top stB sur la liste stA.
}
void    insertion_sort_stB_to_stA(t_stconfig *stA, t_stconfig *stB)
{
    /*fonction recursive de tri par insertion (decroissant) pour trier la stB dans stA 
    La stB est partiellement triée (chuncks), dc peu de moves en moyenne
    */
    size_t i_max;//indice de la valeur max dans stB
    if(stB == NULL)
        return ;
    i_max = pos_max_stack(*stB);
    if (i_max < (stB->size / 2))
    {
        while (i_max-- > 0)
            operation_manager(stA, stB, ft_strsplit("rb", ','));
    }
    else 
    {
        while (i_max < (stB->size - 1))
            operation_manager(stA, stB, ft_strsplit("rrb", ','));
    }
    operation_manager(stA, stB, ft_strsplit("pa", ','));
    return_sorted_in_stA(stA, stB);
    return ;
}
void    algo_big_stack(t_stconfig *stA, t_stconfig *stB)
{
    t_chuncks *chuncks;
    
    chuncks = determine_chuncks(stA);
    //fonction 1
    presort_and_push_chuncks(chuncks, stA, stB);
    //fonction 2
    insertion_sort_stB_to_stA(stA, stB);
}