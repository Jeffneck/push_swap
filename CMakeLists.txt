# Spécifie la version minimale de CMake requise
cmake_minimum_required(VERSION 3.27)

set(CMAKE_C_STANDARD 11)

# Déclare le nom du projet
project(push_swap)

# Définit les fichiers source de votre projet
set(SRCS
        srcs/main.c
        srcs/create_stack.c
        srcs/process_args.c
        srcs/stack_operations.c
        srcs/stack_utils.c
)

# Définit les fichiers d'en-tête (s'ils existent) - Remplacez le chemin approprié
# set(INC includes)

# Génère les fichiers objets (.o) à partir des fichiers source
add_library(${PROJECT_NAME}_lib OBJECT ${SRCS})

# Spécifie le nom de l'exécutable à créer
add_executable(${PROJECT_NAME} $<TARGET_OBJECTS:${PROJECT_NAME}_lib>)

# Inclut les fichiers d'en-tête (s'ils existent)
# target_include_directories(${PROJECT_NAME} PRIVATE ${INC})

# Définit les options de compilation
target_compile_options(${PROJECT_NAME}_lib PRIVATE -Wall -Wextra -Werror -g3)

# Liaison de l'exécutable avec la bibliothèque
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)
