#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000 // Have 1000 students

typedef struct students
{
    char name[30], id[12];
    float point, midPoint, finalPoint, practicePoint, avrPoint;
}st;

void menu();
void input(st a[MAX], int &n);
void printList(st a[MAX], int n);
char letterPoints(float x);
void printList_Again(st a[MAX], int n);
int countLetters(st A[], int n, float a, float b);
void printList_letterPoint(st a[MAX], int n);
void find(st a[MAX], int n,char c[]);
void sort(st a[MAX], int n);
void deleted(st a[MAX], int &n, int index);
void deleteStudent(st a[MAX], int &n);
void insert(st a[MAX], int &n, st b);

int main(){
    st student1[MAX], student2;
    int n, choose = 0;
    char c[12];
MENU:do
    {
        menu();
        printf("Pls enter selection: ");
        scanf("%d", &choose);
        switch(choose){
            case 0:
                exit(0);
            case 1:{
                system("cls");
                input(student1,n);
                system("cls");
                goto MENU;
            }break; 
            case 2:{
                system("cls");
                printList(student1,n);
                system("pause");
                system("cls");
                goto MENU;
            }break;
            case 3:{
                system("cls");
                printList_letterPoint(student1,n);
                system("pause");
                system("cls");
                goto MENU;
            }break;
            case 4:{
                system("cls");
                find(student1,n,c);
                system("pause");
                system("cls");
                goto MENU;
            }break;
            case 5:{
                system("cls");
                sort(student1,n);
                system("pause");
                system("cls");
            }break;
            case 6:{
                system("cls");
                deleteStudent(student1,n);
                system("pause");
                system("cls");
            }break;
            case 7:{
                system("cls");
                insert(student1,n,student2);
                system("pause");
                system("cls");
            }break;
            case 8:{
                system("cls");
                printList_Again(student1,n);
                system("pause");
                system("cls");
                goto MENU;
            }break;
    }   
    } while (choose != 9);

    system("pause");
    return 0;
}
void menu(){
    printf("+-----------------------------------------------MENU-------------------------------------------------+\n");
    printf("|0. Exit                                                                                             |\n");
    printf("|1. Import a list of students                                                                        |\n");
    printf("|2. Export a list of students                                                                        |\n");
    printf("|3. Student score statistics                                                                         |\n");
    printf("|4. Find student                                                                                     |\n");
    printf("|5. Sort list students                                                                               |\n");
    printf("|6. Delete student                                                                                   |\n");
    printf("|7. Insert student                                                                                   |\n");
    printf("|8. Export the list of students who failed the subject                                               |\n");
    printf("+----------------------------------------------------------------------------------------------------+\n");
}
void input(st a[MAX], int &n){
    do
    {
        printf("Enter the number of students (0 <= st <= 1000): ");
        scanf("%d", &n);
        if(n < 0 || n > MAX)
            printf("Pls enter again !\n");
        else if(n == 0){
            printf("No stutents !\n");
            break;
        }
    } while (n < 0 || n > MAX);
    

    for (int i = 0; i < n; i++){   
        printf("Student %d\n", i+1);
        fflush(stdin);
        printf("Enter name: "); gets(a[i].name);
        printf("Enter ID: "); gets(a[i].id);
        do{
            printf("Enter point: "); scanf("%f", &a[i].point);
            printf("Enter midterm grades: "); scanf("%f", &a[i].midPoint);
            printf("Enter final grades: "); scanf("%f", &a[i].finalPoint);
            printf("Enter practice grades: "); scanf("%f", &a[i].practicePoint);

            a[i].avrPoint = (((2*a[i].point + 3*a[i].midPoint + 5*a[i].finalPoint)/10)*2 + a[i].practicePoint)*1.0/3;

            if((a[i].point > 10 || a[i].point < 0) || (a[i].midPoint > 10 || a[i].midPoint < 0) || (a[i].finalPoint > 10 || a[i].finalPoint < 0) || (a[i].practicePoint > 10 || a[i].practicePoint < 0))
                printf("Wrong input !\nPls enter again !\n");
            }while ((a[i].point > 10 || a[i].point < 0) || (a[i].midPoint > 10 || a[i].midPoint < 0) || (a[i].finalPoint > 10 || a[i].finalPoint < 0) || (a[i].practicePoint > 10 || a[i].practicePoint < 0));
            
        system("cls");
    }
}
char letterPoints(float x){
    char letters;
    if(x <= 10.0 && x >= 8.0)
        return letters = 'A';
    else if(x <= 7.9 && x >= 7.0)
        return letters = 'B';
    else if(x <= 6.9 && x >= 5.5)
        return letters = 'C';
    else if(x <= 7.4 && x >= 4.0)
        return letters = 'D';
    else if(x <= 3.9 && x >= 0.0)
        return letters = 'F';
}
void printList(st a[MAX], int n){
    printf("+----------------------------------------------------------------------------------------------------------------------------+\n");
    printf("|                                                 STUDENT INFORMATION                                                        | \n");
    printf("+----------------------------------------------------------------------------------------------------------------------------+\n");
    printf("| NUM     NAME          ID           POINT     MID GRADES     FINAL GRADES     PRAC GRADES     GPA             LETTERS       |\n");

    for (int i = 0; i < n; i++){
        printf("| %-8d%-14s%-13s%-10.2f%-15.2f%-17.2f%-16.2f%-16.2f%c\t     |\n", i+1, a[i].name, a[i].id, a[i].point, a[i].midPoint, a[i].finalPoint, a[i].practicePoint, a[i].avrPoint, letterPoints(a[i].avrPoint));
    }
    printf("+----------------------------------------------------------------------------------------------------------------------------+\n");
}
void printList_Again(st a[MAX], int n){
    int temp = 0;
    
    for (int i = 0; i < n; i++)
    {
        if(a[i].avrPoint <= 3.9 && a[i].avrPoint >= 0.0){
            temp++;
        }
    }

    if(temp == 0){
        printf("\033[32m"); // printf front green
        printf("No re-learning students !\n");
        printf("\033[37m"); // printf fornt white
    }
        
    else{
        printf("+----------------------------------------------------------------------------------------------------------------------------+\n");
        printf("|                                                 STUDENT INFORMATION                                                        | \n");
        printf("+----------------------------------------------------------------------------------------------------------------------------+\n");

        printf("| NUM     NAME          ID           POINT     MID GRADES     FINAL GRADES     PRAC GRADES     AVER GRADES     LETTERS POINT |\n");
        for (int i = 0; i < n; i++)
    {
        if(a[i].avrPoint <= 3.9 && a[i].avrPoint >= 0.0){
            printf("| %-8d%-14s%-13s%-10.2f%-15.2f%-17.2f%-16.2f%-16.2f%c\t     |\n", i+1, a[i].name, a[i].id, a[i].point, a[i].midPoint, a[i].finalPoint, a[i].practicePoint, a[i].avrPoint, letterPoints(a[i].avrPoint));
        }
    }
    printf("+----------------------------------------------------------------------------------------------------------------------------+\n");

    }
}
int countLetters(st A[], int n, float a, float b){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(A[i].avrPoint <= b && A[i].avrPoint >= a)
            cnt++;
    }
    return cnt;
}
void printList_letterPoint(st a[MAX], int n){
    printf("Total number of students achieving A grades: \033[32m%d\033[37m\n",countLetters(a,n,8.0,10.0));
    printf("Total number of students achieving B grades: \033[0;36m%d\033[37m\n",countLetters(a,n,7.0,7.9));
    printf("Total number of students achieving C grades: \033[34m%d\033[37m\n",countLetters(a,n,5.5,6.9));
    printf("Total number of students achieving D grades: \033[33m%d\033[37m\n",countLetters(a,n,4.0,5.4));
    printf("Total number of students achieving F grades: \033[31m%d\033[37m\n",countLetters(a,n,0.0,3.9));
}
void find(st a[MAX], int n,char c[]){
    fflush(stdin);
    printf("\033[32mSearch for student information\033[37m");
    printf("\nEnter the ID: ");
    gets(c);
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if(strstr(a[i].id, c)){ // use strstr to find
                printf("Name: %s\n", a[i].name);
                printf("ID: %s\n", a[i].id);
                printf("Score: %.2f\n", a[i].point);
                printf("Midterm Score: %.2f\n", a[i].midPoint);
                printf("Final Score: %.2f\n", a[i].finalPoint);
                printf("Practice Score: %.2f\n", a[i].practicePoint);
                printf("GPA: %.2f\n", a[i].avrPoint);
                temp++;
        }
    }
    if(temp == 0)
        printf("\033[31mNot Found !!!\033[37m\n");
}
void sort(st a[MAX], int n){
    char choose[5];
    int temp;
    fflush(stdin);
    printf("Do you want to sort up or down ?\n");
    printf("Press U/D: ");
    scanf("%s", choose);
    if(strcmp(choose,"U") == 0 || strcmp(choose,"Up") == 0 || strcmp(choose,"up") == 0 || strcmp(choose, "u") == 0){
        for (int i = 0; i < n-1; i++){  //bubble sort
            for (int j = 1; j < n; j++){
                if(a[i].avrPoint > a[j].avrPoint){
                    temp = a[i].avrPoint;
                    a[i].avrPoint = a[j].avrPoint;
                    a[j].avrPoint = temp;
                }
            }
        }
        printList(a,n);
    }
    else if(strcmp(choose,"D") == 0 || strcmp(choose,"Down") == 0 || strcmp(choose,"down") == 0 || strcmp(choose, "d") == 0){
        for (int i = 0; i < n-1; i++){ //bubble sort
            for (int j = 1; j < n; j++){
                if(a[i].avrPoint < a[j].avrPoint){
                    temp = a[i].avrPoint;
                    a[i].avrPoint = a[j].avrPoint;
                    a[j].avrPoint = temp;
                }
            }
        }
        printList(a,n);
    }
    else{
        printf("Wrong syntax ! \n");
        printf("Pls enter again !\n");
    }
}
void deleted(st a[MAX], int &n, int index){
    for (int i = index; i < n - 1; i++)
    {
        a[i] = a[i+1];
    }
    n--;
}

void deleteStudent(st a[MAX], int &n){
    fflush(stdin);
    char id[12];

    printf("Enter the ID to remove: ");
    gets(id);

    bool found = false; // variable found is used to check if there is an ID that meets the required condition
    for (int i = 0; i < n; i++)
    {
        if(strcmp(a[i].id, id) == 0){
            deleted(a,n,i);
            printList(a,n);
            found = true;
            break;
        }
    }
    if (!found) {
        printf("No ID to delete!\n");
    }
}

void insert(st a[MAX], int &n, st b){
    int size = sizeof(a)/sizeof(a[0]);
    if (n == size) {
        printf("Cannot be inserted! Array is full.\n");
    }

    printf("Enter name: ");
    fflush(stdin);
    gets(b.name);
    strcpy(a[n].name, b.name);

    printf("Enter ID: ");
    fflush(stdin);
    gets(b.id);
    strcpy(a[n].id, b.id);

    printf("Enter point: ");
    scanf("%f", &b.point);
    a[n].point = b.point;

    printf("Enter midterm grades: ");
    scanf("%f", &b.midPoint);
    a[n].midPoint = b.midPoint;

    printf("Enter final grades: ");
    scanf("%f", &b.finalPoint);
    a[n].finalPoint = b.finalPoint;

    printf("Enter practice grades: ");
    scanf("%f", &b.practicePoint);
    a[n].practicePoint = b.practicePoint;

    a[n].avrPoint = ((2 * a[n].point + 3 * a[n].midPoint + 5 * a[n].finalPoint) / 10 * 2 + a[n].practicePoint) / 3.0;

    if (a[n].point < 0 || a[n].midPoint < 0 || a[n].finalPoint < 0 || a[n].practicePoint < 0) {
        printf("Scores cannot be negative! Please enter again.\n");
        return;
    }

    n++;
    printf("\033[32mStudent %s has been inserted.\033[37m\n", a[n-1].name);
}
