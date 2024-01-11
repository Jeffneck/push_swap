#!/bin/bash

# Demande à l'utilisateur combien de nombres aléatoires il souhaite générer
echo "Combien de nombres aléatoires souhaitez-vous générer ?"
read nombre_nombres

# Vérifie si l'entrée de l'utilisateur est un nombre entier positif
if ! [[ $nombre_nombres =~ ^[0-9]+$ ]]; then
    echo "Veuillez entrer un nombre entier positif."
    exit 1
fi

# Génère et affiche les nombres aléatoires
# echo "Voici la liste des $nombre_nombres nombres aléatoires :"
liste_nombres=()
for ((i=1; i<=$nombre_nombres; i++)); do
    nombre_aleatoire=$((RANDOM))
    echo "$i : $nombre_aleatoire"
    liste_nombres+=("$nombre_aleatoire")
done

# Exécute le binaire ./push_swap avec la liste de nombres comme arguments
./push_swap "${liste_nombres[@]}" > out.txt
./push_swap "${liste_nombres[@]}" | ./checker_linux "${liste_nombres[@]}" 