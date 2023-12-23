#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void create_rank_file(const char *filename){
    FILE *file1 = fopen(filename, "w");
    if (file1 == NULL) {
        printf("Error: can't find file");
        exit(1);
    }
    fclose(file1);
}
void print_rank(const char *filename){
    Sort_rank(filename);
    FILE *file=fopen(filename,"r");
    if (file == NULL){
        create_rank_file(filename);
        file=fopen(filename,"r");
    }
    player players[10];
    printf("                  Rank|Score|Name\n");
    int rank= 1;
    int num =0;
    while(fscanf(file, "%49[^,],%d\n", players[num].name, &players[num].score) == 2){
        if (rank > 9){
                if(players[num].score > 9){
                    printf("                  %d  | %d  |%s\n",rank,players[num].score,players[num].name);
                }else{
                    printf("                   %d |  %d  |%s\n",rank,players[num].score,players[num].name);
                }
        }else{
            if(players[num].score > 9){
                printf("                   %d  | %d  |%s\n",rank,players[num].score,players[num].name);
            }else{
                printf("                   %d  |  %d  |%s\n",rank,players[num].score,players[num].name);
            }
        }
        rank++;
        num++;
    }
    fclose(file);
}
void add_to_rank(const char *filename,char *name,int *p){
    FILE *file=fopen(filename,"r");
    if (file == NULL){
        create_rank_file(filename);
        file=fopen(filename,"r");
    }
    player players[10];
    int num = 0;
    int sco = p;
    int found = 0;
    rewind(file);
    while (fscanf(file, "%49[^,],%d\n", players[num].name, &players[num].score) == 2) {
            if(strcmp(players[num].name, name) == 0){
                    found = 1;
                    if(players[num].score < sco){
                        players[num].score = sco;
                    }
            }
        num++;
    }
    fclose(file);
    if(found){
        file=fopen(filename,"w");
      for (int i = 0; i < num; i++) {
        fprintf(file, "%s,%d\n", players[i].name, players[i].score);
      }
      fclose(file);
    }else if(num >= 10 && sco > players[9].score){
      strncpy(players[9].name,name,49);
      players[9].name[49] = '\0';
      players[9].score = sco;
      file=fopen(filename,"w");
      for (int i = 0; i < num; i++) {
          fprintf(file, "%s,%d\n", players[i].name, players[i].score);
      }
       fclose(file);
    }else if(num < 10){
        file=fopen(filename,"a");
        fprintf(file,"%s,%d\n",name,p);
        fclose(file);
     }
     Sort_rank(filename);
}
void Sort_rank(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        create_rank_file(filename);
        file=fopen(filename,"r");
    }
    int num = 0;
    player players[10];
    rewind(file);
    while (fscanf(file, "%49[^,],%d\n", players[num].name, &players[num].score) == 2) {
        num++;
    }
    fclose(file);
    player temp;
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (players[j].score < players[j + 1].score) {
                temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing sorted data");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num; i++) {
        fprintf(file, "%s,%d\n", players[i].name, players[i].score);
    }
    fclose(file);
}
