#include "CanliQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void enqueue(CanliQueue* queue, Canli* canli) {
    CanliNode* new_node = (CanliNode*) malloc(sizeof(CanliNode));
    new_node->canli = canli;
    new_node->next = NULL;
    
    if (queue->tail != NULL) {
        queue->tail->next = new_node;
    }
    queue->tail = new_node;
    
    if (queue->head == NULL) {
        queue->head = new_node;
    }
}

Canli* dequeue(CanliQueue* queue) {
    if (queue->head == NULL) return NULL;
    
    CanliNode* temp = queue->head;
    Canli* canli = temp->canli;
    queue->head = queue->head->next;
    
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    
    free(temp);
    return canli;
}

void printQueue(CanliQueue* queue) {
    CanliNode* current = queue->head;
    while (current != NULL) {
        if(current->canli->id != -1 &&current->a!=-2){
            printf("%s ", current->canli->gorunum(current->canli));
        }else if(current->a==-2){
            //printf("%s ", current->canli->gorunum(current->canli));
            printf("X ");
        }else if(current->canli->id == -1){
            printf("\n");     
        }
        
        current = current->next;
    }
    printf("\n");
}

/**
void canlilarikarsilastirX(CanliQueue* queue) {// ölenein id sine -2 ata ve yazdırırken X yazdır
    CanliNode* current = queue->head;
    //char *headGorunum = current->canli->gorunum(current->canli);
    //char *nextGorunum;
    while (current != NULL) {
        printf("%s ", current->canli->gorunum(current->canli));  
        //current = current->next;
        //nextGorunum = current->canli->gorunum(current->canli);
        //*nextGorunum = current->next->canli->gorunum(current->canli);
        if(strcmp(current->canli->gorunum(current->canli), "B")==0){//strcmp(current->canli->gorunum(current->canli), "B")
            printf("fddfdX");
            if(strcmp(current->next->canli->gorunum(current->canli), "C")==0)//C kazandı ve yeni head olmalı strcmp(current->next->canli->gorunum(current->canli), "B")
            {
                //*headGorunum = *nextGorunum;
                //current->canli->id=0;
                printf("fddfdX");

            }
            else if(strcmp(current->next->canli->gorunum(current->canli), "P")==0 ||
                    strcmp(current->next->canli->gorunum(current->canli), "S")==0)//B kazandı head korunur 
            {
                //current->next->canli->id=-2;
                printf("fddfdX");
            }
            else if(strcmp(current->next->canli->gorunum(current->canli), "B")==0)
            {
                
            }
        }
        if( strcmp(current->canli->gorunum(current->canli), "C")==0){
            if(strcmp(current->next->canli->gorunum(current->canli), "S")==0)//S kazandı ve yeni head olmalı 
            {
                //*headGorunum = *nextGorunum;
                //current->canli->id=-2;
                printf("fddfdX");
            }
            else if(strcmp(current->next->canli->gorunum(current->canli), "B")==0 ||  strcmp(current->next->canli->gorunum(current->canli), "P")==0)//B kazandı head korunur 
            {
                //current->next->canli->id=-2;
                printf("fddfdX");
            }

        }
        if( strcmp(current->canli->gorunum(current->canli), "S")==0 ){
            if(strcmp(current->next->canli->gorunum(current->canli), "B")==0 )//B kazandı ve yeni head olmalı 
            {
                //*headGorunum = *nextGorunum;
                //current->canli->id=-2;
            }
            else if(strcmp(current->next->canli->gorunum(current->canli), "P")==0 || strcmp(current->next->canli->gorunum(current->canli), "C")==0)//B kazandı head korunur 
            {
                //current->next->canli->id=-2;
            }

        }
        current = current->next;

    }

    //printf("\n");
}*/


void canlilarikarsilastirX(CanliQueue* queue) {
    CanliNode* current = queue->head;

    while (current != NULL && current->next != NULL) {  // current->next için güvenlik kontrolü ekledim
        char* currentGorunum = current->canli->gorunum(current->canli);  // Mevcut canlının görünümü
        //printf("%s --", currentGorunum);

        // Eğer mevcut canlı ve sonraki canlı null değilse
        if (current->canli && current->next->canli) {
            char* nextGorunum = current->next->canli->gorunum(current->next->canli);  // Sonraki canlının görünümü
            
            if(strcmp(currentGorunum, "B") == 0 && strcmp(nextGorunum, "C") == 0) {
                printf("X ");
                
                // İlgili işlem ya da canlıyı işaretleme (Örn: current->canli->a = false)
            } else if(strcmp(currentGorunum, "C") == 0 && strcmp(nextGorunum, "S") == 0) {
                printf("X ");
                // İlgili işlem ya da canlıyı işaretleme
            } else if(strcmp(currentGorunum, "S") == 0 && strcmp(nextGorunum, "B") == 0) {
                printf("X ");
                // İlgili işlem ya da canlıyı işaretleme
            }
        }

        current = current->next;
    }

    printf("\n");
}


/*

B → P
C → B
S → P
B → S
S → C
C → P

*/

