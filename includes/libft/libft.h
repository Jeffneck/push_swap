#ifndef LIBFT_H
#define LIBFT_H 
#include <string.h> //size_t
#include <unistd.h> //write
#include <stdlib.h> //malloc, free
#include <stdio.h> //printf (interdit dans libft)
#include <strings.h> //bzero (interdit dans libft)
#include <ctype.h> //isalpha.. (interdit dans libft)

//mem_utils = leur particularité est de gérer la mémoire octet par octet
void *ft_memset(void *s, int c, size_t n); // Remplit une zone de mémoire avec une valeur donnée
void ft_bzero(void *s, size_t n); // Met à zéro une zone de mémoire
void *ft_memcpy(void *dest, const void *src, size_t n); // Copie une zone de mémoire source vers une destination
void *ft_memccpy(void *dest, const void *src, int c, size_t n); // Copie une zone de mémoire source vers une destination jusqu'à ce qu'un caractère donné soit rencontré
void *ft_memmove(void *dest, const void *src, size_t n); // Copie une zone de mémoire source vers une destination, même si les zones se chevauchent
void *ft_memchr(const void *s, int c, size_t n); // Recherche la première occurrence d'un caractère donné dans une zone de mémoire
int ft_memcmp(const void *pointer1, const void *pointer2, size_t size); // Compare deux zones de mémoire

void *ft_memalloc(size_t size); // Alloue une zone de mémoire et initialise chaque octet à 0
void ft_memdel(void **ap); // Libère la mémoire d'une zone allouée dynamiquement et met son pointeur à NULL

// str_utils
void ft_putstr(char const *s);//Affiche la chaine s sur la sortie standard.
void ft_putstr_fd(char const *s, int fd);//Ecrit la str s sur le descripteur de fichier fd.
void ft_putendl(char const *s); //Affiche la chaine s sur la sortie standard suivi d'un \n
void ft_putendl_fd(char const *s, int fd);//Ecrit la chaine s sur le descripteur de fichier fd suivi d’un ’\n’.
size_t ft_strlen(const char *str); // Calcule la longueur d'une chaîne de caractères
char *ft_strdup(const char *str1); // alloue puis duplique une chaîne de caractères
char *ft_strcpy(char *dest, const char *src); // Copie une chaîne source dans une chaîne de destination
char *ft_strncpy(char *dest, const char *src, size_t length); // Copie une partie d'une chaîne source dans une chaîne de destination
char *ft_strcat(char *dest, const char *src); // Concatène une chaîne source à la fin d'une chaîne de destination
char *ft_strncat(char *dest, const char *src, size_t size); // Concatène une partie d'une chaîne source à la fin d'une chaîne de destination
size_t ft_strlcat(char *dest, const char *src, size_t size); // Concatène une partie d'une chaîne source à la fin d'une chaîne de destination avec une taille maximale
char *ft_strchr(const char *str, int c); // Recherche la première occurrence d'un caractère donné dans une chaîne
char *ft_strrchr(const char *str, int c); // Recherche la dernière occurrence d'un caractère donné dans une chaîne
char *ft_strstr(const char *fullstring, const char *substring); // Recherche la première occurrence d'une sous-chaîne dans une chaîne
char *ft_strnstr(const char *full, const char *sub, size_t len); // Recherche une sous-chaîne dans une chaîne avec une longueur maximale
int ft_strcmp(const char *s1, const char *s2); // Compare deux chaînes de caractères
int ft_atoi(const char *str); // Convertit une chaîne de caractères en un entier

char *ft_strnew(size_t size); // Alloue une nouvelle chaîne de caractères et initialise chaque caractère à '\0'
void ft_strdel(char **as); // Libère la mémoire d'une chaîne de caractères allouée dynamiquement et met son pointeur à NULL
void ft_strclr(char *s); // Assigne la valeur '\0' à tous les caractères d'une chaîne
void ft_striter(char *s, void (*f)(char *)); // Applique une fonction à chaque caractère d'une chaîne
void ft_striteri(char *s, void (*f)(unsigned int, char *)); // Applique une fonction à chaque caractère d'une chaîne en précisant l'index du caractère
char * ft_strmap(char const *s, char (*f)(char));// Applique f à chaque caractère de la chaîne s, crée une nouvelle chaîne résultante.
char * ft_strmapi(char const *s, char (*f)(unsigned int, char));// Applique f à chaque caractère de la chaîne s avec index, crée une nouvelle chaîne résultante.
int	ft_strequ(char const *s1, char const *s2); // Compare lexicographiquement s1 et s2. Si les deux chaines sont égales, la fonction retourne 1, ou 0 sinon.
int	ft_strnequ(char const *s1, char const *s2, size_t n);// Compare lexicographiquement s1 et s2. jusqu’à n caractères maximum ou bien qu’un ’\0’ ait été rencontré. Si les deux chaines sont égales, la fonction retourne 1, ou 0 sinon.
char * ft_strsub(char const *s, unsigned int start, size_t len);//alloue copie et retourne un tronçon de str qui commence à start et est de taille len. 
char * ft_strjoin(char const *s1, char const*s2);// Alloue, copie et renvoie le résultat de la concaténation de s1 et s2. Si l’allocation echoue, la fonction renvoie NULL.
char * ft_strtrim(char const *s); //alloue et renvoie une copie d'une chaîne de caractères en supprimant les espaces blancs au début et à la fin de la chaîne d'entrée.
char ** ft_strsplit(char const *s, char c); //alloue un tableau de str pour stocker toutes les subchains contenues dans s et séparées par c. retourne NULl en cas d'erreur d'allocation.
char * ft_itoa(int n); //Transforme un entier en une str allouée.

//char_utils
void ft_putchar(char c); //afficher un char à l'écran
void ft_putchar_fd(char c, int fd); //Ecrit le caractère c sur le descripteur de fichier fd.
int ft_isalpha(int c); 
int ft_isdigits(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c); 






#endif //LIBFT_H