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

/*
Dans cette version on utilise le fait d'avoir déjà trouvé les final_pos de chaque elem (utile pour la gestion des chuncks)
le nb le plus bas sera tjr 0 et la pos max sera la size - 1 de la stack
range = size 
*/
t_chuncks *make_chuncks(t_stconfig stA)
{
    t_chuncks *ch;
    
    ch = (t_chuncks *) malloc (sizeof(t_chuncks));
    if (ch == NULL)
        return(NULL);
    if (stA.size < 200)
        ch ->nb_chuncks = 5;
    else
        ch->nb_chuncks = 11;
    ch->max_stA = stA.size; //ecrire la fonction 
    ch->range = (ch->max_stA - ch->min_stA) / ch->nb_chuncks;
    return (ch);
}
int is_in_chunck(t_chuncks *chuncks, int curr_chunck, int nb)
{
    int ch_min; 
    int ch_max;

    ch_min = chuncks->range * curr_chunck; //verifier le calcul
    ch_max = chuncks->range * (curr_chunck + 1) - 1; //verifier le calcul
    if (nb >= ch_min && nb <= ch_max)
        return (1);
    return (0);
}
int moves_from_top_stA(t_stelem *node, int chunck_min, int chunck_max)
{
    int moves;

    moves = 0;
    while (node)
    {
        if(node->final_pos >= chunck_min || node->final_pos >= chunck_max )
            return (moves);
        moves++;
        node = node->next;
    }
    return (-1);
}

int moves_from_bottom_stA(t_stelem *node, int chunck_min, int chunck_max)
{
    int moves;

    moves = 1;
    while (node)
    {
        if(node->final_pos >= chunck_min || node->final_pos >= chunck_max )
            return (moves);
        moves++;
        node = node->prev;
    }
    return (-1);
}

int best_moves_stA(t_stconfig stA, int chunck_min, int chunck_max)
{
    int moves_top; 
    int moves_bot; 

    moves_top = moves_from_top_stA(stA.top, chunck_min, chunck_max);
    moves_bot = moves_from_bottom_stA(stA.top, chunck_min, chunck_max);

    if(moves_top <= moves_bot)
        return (moves_top);
    return (moves_bot);
}
void    algo_big_stack(t_stconfig *stA, t_stconfig *stB)
{
    t_chuncks *chuncks;
    static int curr_chunck = 0;
    int moves_stA;
    int moves_stB;
    
    

    chuncks = determine_chuncks(stA);
    while (stA->top)
    {
        mutualize_moves(best_moves_stA(stA, chuncks), )
        (best_moves_stA(stA, chuncks) > 0 && best_moves_stB(stB) > 0)
        {

        }
    }
}