#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int compterLignes(FILE *fichier) {
    int car, NbLigne = 1;
    while ((car = fgetc(fichier)) != EOF) {
        if (car == '\n') {
            ++NbLigne;
        }
    }
    rewind(fichier);
    return NbLigne;
}

void chargerPatients(FILE *file, stpatients *patients) {
    char line[MAX_LINE];
    int index = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        char *token = strtok(line, "$");
        if (token) patients->patient_id[index] = atoi(token);
        token = strtok(NULL, "$");
        if (token) patients->record_id[index] = atoi(token);
        token = strtok(NULL, "$");
        if (token) patients->age[index] = atoi(token);
        token = strtok(NULL, "$");
        if (token) patients->gender[index] = token[0];
        token = strtok(NULL, "$");
        if (token) patients->weight[index] = atof(token);
        token = strtok(NULL, "$");
        if (token) patients->height[index] = atoi(token);
        token = strtok(NULL, "$");
        if (token) patients->systolic_bp[index] = atoi(token);
        token = strtok(NULL, "$");
        if (token) patients->diastolic_bp[index] = atoi(token);
        token = strtok(NULL, "$");
        if (token) patients->heart_rate[index] = atof(token);
        token = strtok(NULL, "$");
        if (token) patients->condition[index] = (strcmp(token, "True") == 0) ? 1 : 0;
        index++;
    }
    rewind(file);
}

void chargerLifestyle(FILE *file, stlifestyle *lifestyle) {
    char line[MAX_LINE];
    int index = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        // Supprimer la nouvelle ligne
        line[strcspn(line, "\n")] = '\0';

        // Découper la ligne en champs
        char *token = strtok(line, "$");
        if (token != NULL) lifestyle->id[index] = atoi(token);

        token = strtok(NULL, "$");
        if (token != NULL) lifestyle->physical_activity[index] = atoi(token);

        token = strtok(NULL, "$");
        if (token != NULL) lifestyle->alcohol_consumption[index] = atof(token);

        token = strtok(NULL, "$");
        if (token != NULL) lifestyle->caffeine_consumption[index] = atof(token);

        token = strtok(NULL, "$");
        if (token != NULL) lifestyle->sleep_quality[index] = atof(token);

        index++;
    }
    rewind(file);
}

void afficherPatients(const stpatients *patients, int n) {
    for (int i = 0; i < n; i++) {
        printf("Patient %d:\n", i + 1);
        printf("  Patient ID: %d\n", patients->patient_id[i]);
        printf("  Record ID: %d\n", patients->record_id[i]);
        printf("  Age: %d\n", patients->age[i]);
        printf("  Gender: %c\n", patients->gender[i]);
        printf("  Weight: %.2f\n", patients->weight[i]);
        printf("  Height: %d\n", patients->height[i]);
        printf("  Systolic BP: %d\n", patients->systolic_bp[i]);
        printf("  Diastolic BP: %d\n", patients->diastolic_bp[i]);
        printf("  Heart Rate: %.2f\n", patients->heart_rate[i]);
        printf("  Condition: %s\n", patients->condition[i] ? "True" : "False");
        printf("\n");
    }
}

void afficherLifestyle(const stlifestyle *lifestyle, int n) {
    for (int i = 0; i < n; i++) {
        printf("Patient %d:\n", i + 1);
        printf("  ID: %d\n", lifestyle->id[i]);
        printf("  Physical Activity: %f\n", lifestyle->physical_activity[i]);
        printf("  Alcohol Consumption: %.2f\n", lifestyle->alcohol_consumption[i]);
        printf("  Caffeine Consumption: %.2f\n", lifestyle->caffeine_consumption[i]);
        printf("  Sleep Quality: %.2f\n\n", lifestyle->sleep_quality[i]);
    }
}
