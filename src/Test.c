#include <stdio.h>
#include <stdlib.h>
#include "Canli.h"
#include "Bitki.h"
#include "sinek.h"
#include "pire.h"
#include "bocek.h"
#include "CanliQueue.h"
#include <string.h>

void printNumbersPerLine() {
    FILE *file = fopen("veri.txt", "r");
    if (file == NULL) {
        perror("Dosya açılamadı");
        exit(EXIT_FAILURE);
    }

    char line[1024]; // Satır için yeterli büyüklükte bir dizi.
    int number;
    int matris =0;
    Canli* canli1 = NULL;

    CanliQueue queues[5]; // Her canlı türü için bir kuyruk 4->5
    for (int i = 0; i < 5; i++) {
        queues[i].head = NULL;
        queues[i].tail = NULL;
    }
    Canli* canli;
    // Dosyadan bir satır oku. double ekle +0.1 ekle 
    while (fgets(line, sizeof(line), file) != NULL) {
        char *ptr = line;
        
        // Satırdaki sona kadar git.
        while (*ptr != '\0') {
            // Sayıyı oku ve hemen yanında bas.
            if (sscanf(ptr, "%d", &number) == 1) {
                //Canli* canli = NULL;
                canli = NULL;
                printf("%d ", number);
                matris+=1;

                if(number>=1&&number<=9){
                    canli = (Canli*)BitkiOlustur(number);
                    
                    enqueue(&queues[0], canli);
                    enqueue(&queues[4], canli);
                }else if(number>9&&number<21){
                    canli = (Canli*)BocekOlustur(number);
                    enqueue(&queues[1], canli);
                    enqueue(&queues[4], canli);
                }else if(number>=21&&number<51){
                    canli = (Canli*)SinekOlustur(number);
                    enqueue(&queues[2], canli);
                    enqueue(&queues[4], canli);    
                }else if(number>=51&&number<100){
                    canli = (Canli*)PireOlustur(number);
                    enqueue(&queues[3], canli);
                    enqueue(&queues[4], canli);
                }





                // Sayıdan sonraki karaktere kadar ilerle.
                while (*ptr >= '0' && *ptr <= '9') {
                    ptr++;
                }
            }
            if (*ptr != '\0') {
                ptr++; // Sonraki karaktere geç.
            }
        }
        
        printf("%lf \n", matris); // Her satır sonunda yeni bir satıra geç.
        canli1 = (Canli*)BitkiOlustur(-1);
        //enqueue(&queues[4], canli); canli1
        enqueue(&queues[4], canli1);

    }
    /*

    B → P
    C → B
    S → P
    B → S
    S → C
    C → P
    if(strcmp(currentGorunum, "B") == 0 && strcmp(nextGorunum, "C") == 0) {//B kazandı
                        printf("X ");
                        current->canli->id=-2;
                        printQueue(&queues[4]);
                        // İlgili işlem ya da canlıyı işaretleme (Örn: current->canli->a = false)
                    }else if(strcmp(currentGorunum, "B") == 0 && strcmp(nextGorunum, "S") == 0) {//B kazandı
                        
                        // İlgili işlem ya da canlıyı işaretleme
                    } else if(strcmp(currentGorunum, "C") == 0 && strcmp(nextGorunum, "S") == 0) {
                        printf("X ");
                        // İlgili işlem ya da canlıyı işaretleme
                    } else if(strcmp(currentGorunum, "S") == 0 && strcmp(nextGorunum, "B") == 0) {
                        printf("X ");
                        // İlgili işlem ya da canlıyı işaretleme
                    }else if(strcmp(currentGorunum, "C") == 0 && strcmp(nextGorunum, "C") == 0) {
                        if(current->canli->id < current->next->canli->id){
                            printf("X s");
                        }
                        // İlgili işlem ya da canlıyı işaretleme
                    }else if(strcmp(currentGorunum, "S") == 0 && strcmp(nextGorunum, "S") == 0) {
                        if(current->canli->id < current->next->canli->id){
                            printf("X s");
                        }
                        // İlgili işlem ya da canlıyı işaretleme
                    }else if(strcmp(currentGorunum, "C") == 0 && strcmp(nextGorunum, "C") == 0) {
                        if(current->canli->id < current->next->canli->id){
                            printf("X s");
                        }
                        // İlgili işlem ya da canlıyı işaretleme
                    }
    */


    for (int i = 0; i < 5; i++) {//P her türlü kaybeder
        //printQueue(&queues[i]);
        if(i==4){
            //printQueue(&queues[4]);
            //canlilarikarsilastirX(&queues[4]);
            //printf("%s \n",queues[4].head->canli->gorunum(queues[4].head->canli));
            //queues[4].head->canli->id=-2;
            //queues[4].head->canli->setId(queues[4].head->canli,-2);
            //printQueue(&queues[4]);
                
            CanliNode* winner = queues[4].head;// kazanan kimse o yeni current kaybeden ise id-2 olacak
            
            CanliNode* currentNext = queues[4].head->next;
            while (currentNext != NULL) {  // current->next için güvenlik kontrolü ekledim ->next
                char* currentGorunum = winner->canli->gorunum(winner->canli);  // Mevcut canlının görünümü
            //printf("%s --", currentGorunum);

            // Eğer mevcut canlı ve sonraki canlı null değilse
            if (currentNext->canli->id!=-1) {     
                //char* nextGorunum = currentNext->next->canli->gorunum(currentNext->next->canli);  // Sonraki canlının görünümü
                char* nextGorunum = currentNext->canli->gorunum(currentNext->next->canli);

                if(strcmp(currentGorunum, nextGorunum) != 0)
                { 
                    if(strcmp(currentGorunum, "B")==0){//B → S , B → P
                        if(strcmp(nextGorunum, "C")==0){//Head değişir 
                            
                            winner->a=-2;
                            winner =currentNext;

                        }else{//S veya P dir head değişmez hangi node ise id si -2 olur
                            currentNext->a=-2;
                        }
                    }else if(strcmp(currentGorunum, "C")==0){
                        
                        if(strcmp(nextGorunum, "S")==0){//Head değişir 
                            winner->a=-2;printf("ddd");
                            winner =currentNext;
                        }else{//B veya P dir head değişmez hangi node ise id si -2 olur
                            currentNext->a=-2;
                        }
                    }else if(strcmp(currentGorunum, "S")==0){
                        if(strcmp(nextGorunum, "B")==0){//Head değişir 
                            winner->a=-2;
                            winner =currentNext;
                        }else{//C veya P dir head değişmez hangi node ise id si -2 olur
                            currentNext->a=-2;

                        }
                    }

                }else{// id e bak 
                        
                    if(winner->canli->id > currentNext->canli->id){// head değişmez
                        currentNext->a=-2; winner->a=-2;//printf("dsa1dd");
                    }        
                    else if(winner->canli->id < currentNext->canli->id){//head değişir
                        winner->a=-2;
                        winner =currentNext;printf("dsa1dd2 ");
                        
                    
                    }else{// head değişmez
                        currentNext->a=-2; printf("esit");
                    }
                }   
            }
            printQueue(&queues[4]);
            currentNext = currentNext->next;
        }
 
            
        }

        printQueue(&queues[4]);
        Canli* canli3;
        while ((canli3 = dequeue(&queues[i])) != NULL) {
            canli3->yoket(canli3);
        }
    }
    free(canli1);
    free(canli);
    
    //free(ptr);
    fclose(file);
}

int main(int argc, char *argv[]) {
    

    printNumbersPerLine();
    /**
    Bitki* bitki = BitkiOlustur(2);
    printf("%s\n", bitki->super.gorunum((Canli*)bitki));
    bitki->super.yoket((Canli*)bitki);*/
    
    return 0;
}
