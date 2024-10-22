#include <stdio.h>
#include <stdlib.h> 

typedef struct node {
    int data; 
    struct node *next; 
}
node; 

node *newlistnode(int data){
    node *tmp = malloc(sizeof(node)); 
    if (tmp == NULL)    {
        return NULL;
    }    
    tmp->data = data; 
    tmp->next = NULL; 
    return tmp; 
}

void H(node **H, int *length, int DATA1, int DATA2, int DATA3){
    node *n0 = newlistnode(DATA1); 
    node *n1 = newlistnode(DATA2); 
    node *n2 = newlistnode(DATA3); 
    if (n0 == NULL || n1 == NULL || n2 == NULL) 
    {
        free(n0);
        free(n1);
        free(n2);
        return;
    }
    n0->next = n1; 
    n1->next = n2; 
    n2->next = *H; 
    *H = n0;
    (*length) += 3;
} 

void T(node **H, int *length, int DATA1, int DATA2, int DATA3){
    node *n0 = newlistnode(DATA1); 
    node *n1 = newlistnode(DATA2); 
    node *n2 = newlistnode(DATA3); 
    if (n0 == NULL || n1 == NULL || n2 == NULL) 
    {
        free(n0);
        free(n1);
        free(n2);
        return; 
    } 
    n0->next = n1; 
    n1->next = n2; 
    n2->next = NULL; 
    node *tmp = *H; 
    for (int i = 0; i < (*length-1); i++) 
    {
        tmp = tmp->next; 
    } 
    tmp->next = n0; 
    (*length) += 3;
} 

void D(node **H, int *length, int LOCATION){
    node *tmp_1 = *H; 
    if (LOCATION == 1) 
    {
        *H = (*H)->next; 
    }
    else
    {
        for (int i = 0; i < LOCATION; i++) 
        {
            tmp_1 = tmp_1->next; 
        } 
        node *tmp_2 = *H; 
        for (int i = 0; i < (LOCATION-2); i++) 
        {
            tmp_2 = tmp_2->next; 
        } 
        tmp_2->next = tmp_1; 
    }
    (*length) += -1;
}

void C(node *H, int length){
    node *tmp = H; 
    for (int i = 0; i < (length-1); i++) 
    {
        tmp = tmp->next; 
    } 
    tmp->next = H; 
}

void P(int startlocation, int length, int number_of_loop, node *H){
    node *ptr = H; 
    for (int i = 0; i <(startlocation-1); i++) 
    {
        ptr = ptr->next;
    }
    int n = number_of_loop*length; 
    for (int i = 0; i < n; i++) 
    {
        printf("%d", ptr->data); 
        ptr = ptr->next;
    } 
}


int main(void) 
{ 
    node *head; 
    head = newlistnode(1); 
    int length = 1; 

    T(&head, &length, 1, 1, 1); 
    H(&head, &length, 3, 2, 1);  
    T(&head, &length, 1, 3, 1);
    D(&head, &length, 9); 
    H(&head, &length, 1, 2, 1); 
    T(&head, &length, 2, 2, 2); 
    H(&head, &length, 2, 1, 2); 
    D(&head, &length, 1); 
    H(&head, &length, 2, 2, 1); 
    T(&head, &length, 1, 2, 2); 
    D(&head, &length, 23); 
    T(&head, &length, 2, 1, 1); 
    T(&head, &length, 2, 2, 2); 
    H(&head, &length, 1, 2, 1); 
    H(&head, &length, 1, 1, 1); 
    C(head, length); 

  /*H(&head, &length, , , ); 
    T(&head, &length, , , ); 
    D(head, &length, );
    C(head, length);*/
    int startlocation, number_of_loop; 
    printf("Startlocation:"); 
    scanf("%d", &startlocation);
    printf("The number of loops:"); 
    scanf("%d", &number_of_loop);

    P(startlocation, length, number_of_loop, head); 
    return 0;
}
