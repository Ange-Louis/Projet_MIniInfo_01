#include <stdio.h>
#include <stdlib.h>

int main (){
    FILE* lifestyle = NULL;
    FILE* patients = NULL;
    lifestyle = fopen("DATA/lifestyle.pengu", "r+");
    patients = fopen("DATA/patients.pengu", "r+");
    if (patients != NULL)
        {
            // Boucle de lecture des caractères un à un
            do
            {
                caractereActuel = fgetc(fichier); // On lit le caractère
                printf("%c", caractereActuel); // On l'affiche
            } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
 
            fclose(fichier);
        }

}