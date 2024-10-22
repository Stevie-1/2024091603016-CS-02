#include <stdio.h> 
#include <stdlib.h> 

typedef struct node 
{
    char data; 
    struct node *next; 
}
node; 


void push(node **top, char array[], int *size, int time, int *location) {
    for (int i = 0; i < time; i++) 
    {
        node *tmp = malloc(sizeof(node)); 
        if (tmp == NULL)
        {
            return;
        }    
        (*location)++;
        tmp->data = array[(*location-1)]; 
        tmp->next = (*top); 
        *top = tmp; 
        (*size)++; 
    } 
    return;
} 

void pop(node **top, int time, int *size) {
    for(int i = 0; i < time; i++) 
    {
        if ((*top)->next == NULL) 
        {
            break; 
        }
        printf("%c", (*top)->data); 
        *top = (*top)->next;
        (*size)--;  
    }    
    return;
}



int main(void) 
{
    node *top = malloc(sizeof(node)); 
    if (top == NULL) 
    {
        return 1;
    } 
    top->next = NULL; 
    int size = 0; 
    int location = 0; 
    char string[26] = "kiglnmrmeiahenrteof4ardar"; 
    int array[34] = {3,1,1,2,2,1,2,1,1,2,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,1,1,1,1,1,2};

    for (int i = 0; i < 33; i+=2) 
    {
        push(&top, string, &size, array[i], &location);
        pop(&top, array[i+1], &size);  
    } 
    return 0;
}

