#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int score;
    struct student* next;
};

struct student* head = NULL;

void add(char* name, int score){
    struct student* newNode = (struct student*)malloc(sizeof(struct student));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
    }
    else {
        struct student* p = head;
        while(p->next!=NULL){
            p = p->next;
        }
        p->next = newNode;
    }

}

void delete(char *name){
    struct student* p = head;
    struct student* previous = NULL;

    while(p != NULL){
        if(strcmp(p->name,name)==0){
            if(previous==NULL){
                head = p->next;
            }
            else {
                previous->next = p->next;
            }
            free(p);
            return;
        }
        previous = p;
        p = p->next;
    }
    
}

void print(){
    struct student* p = head;
    while(p != NULL){
        printf("%s %d\n", p->name, p->score);
        p = p->next;
    }
}

void quit(){
    struct student* p = head;
    while(p!=NULL){
        struct student* temp = p;
        p = p->next;
        free(temp);
    }
    head = NULL;
    return;

}

int main() {
    char command[100];
    char name[50];
    int score;

    while(1){
        scanf("%s", command);

        if(strcmp(command, "add")==0){
            scanf("%s %d", &name, &score);
            add(name, score);
        }
        else if(strcmp(command, "delete")==0){
            scanf("%s", &name);
            delete(name);
        }
        else if(strcmp(command, "print")==0){
            print();
        }
        else if(strcmp(command, "quit")==0){
            quit();
            break;
        }
    }
    return 0;
}
