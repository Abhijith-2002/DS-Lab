#include<stdio.h>
#include<stdlib.h>

typedef struct Term {
    int coef;
    int expo;
    struct Term* next;
} Term;

Term* createTerm(int coef, int expo) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coef = coef;
    newTerm->expo = expo;
    newTerm->next = NULL;
    return newTerm;
}

void insertTerm(Term** head, Term** tail, int coef, int expo) {
    if (*head == NULL) {
        *head = createTerm(coef, expo);
        *tail = *head;
    } else {
        (*tail)->next = createTerm(coef, expo);
        *tail = (*tail)->next;
    }
}

void readPoly(Term** head, Term** tail) {
    int choice, coef, expo;
    do {
        printf("\nEnter the coeff : \n");
        scanf("%d", &coef);
        printf("\nEnter the expo : \n");
        scanf("%d", &expo);
        insertTerm(head, tail, coef, expo);
        printf("\nContinue adding more terms?(1/0)\n");
        scanf("%d", &choice);
    } while (choice);
}

void displayPoly(Term** head) {
    if (*head == NULL) {
        printf("\nEmpty!\n");
    } else {
        printf("\n");
        Term* ptr = *head;
        while (ptr) {
            printf("%dx^%d", ptr->coef, ptr->expo);
            if (ptr->next) {
                printf(" + ");
            }
            ptr = ptr->next;
        }
    }
}

void multiplyPoly(Term** head1, Term** head2, Term** head3, Term** tail3) {
    Term* ptr1 = *head1;
    while (ptr1) {
        Term* ptr2 = *head2;
        while (ptr2) {
            insertTerm(head3, tail3, (ptr1->coef * ptr2->coef), (ptr1->expo + ptr2->expo));
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

void removeDuplicates(Term** head3) {
    Term* ptr1 = *head3;
    while (ptr1 != NULL && ptr1->next != NULL) {
        Term* ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr1->expo == ptr2->next->expo) {
                ptr1->coef += ptr2->next->coef;
                ptr2->next = ptr2->next->next;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

int main() {
    Term* head1 = NULL;
    Term* tail1 = NULL;
    printf("\nReading First Polynomial...\n");
    readPoly(&head1, &tail1);
    printf("\nDisplaying First Polynomial...\n");
    displayPoly(&head1);
    Term* head2 = NULL;
    Term* tail2 = NULL;
    printf("\nReading Second Polynomial...\n");
    readPoly(&head2, &tail2);
    printf("\nDisplaying Second Polynomial...\n");
    displayPoly(&head2);
    Term* head3 = NULL;
    Term* tail3 = NULL;
    printf("\nPolynomial Multiplication Result : \n");
    multiplyPoly(&head1, &head2, &head3, &tail3);
    removeDuplicates(&head3);
    displayPoly(&head3);

    return 0;
}
