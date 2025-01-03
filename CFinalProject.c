#include <stdio.h>
#include <string.h>

int registerUser();
int login();
void password(int);

typedef struct
{
    char username[10];
    char password[10];
} User;

User u[10];
int count = 0;
int main()
{
    int index;
    int option;

    int breakCondition = 0;

    while (!breakCondition)
    {
        printf("welcome to the project\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            registerUser();
            break;
        case 2:
            index = login();
            if (index >= 0)
            {
                printf("Login successful\n");
            }
            else
            {
                printf("Incorrect username or password\n");
            }
            break;
        case 3:
            printf("Exiting program!!\n");
            return breakCondition = 1;
            break;
        default:
            printf("Invalid option. Please try again\n");
            break;
        }
    }
}

int registerUser()
{

    char tempUsername[10];
    char tempPass[8];
    printf("Register a new user\n");
    printf("enter username\n");
    scanf("%s",&tempUsername);
    strcpy(u[count].username, tempUsername);
    printf("Enter password\n");
     scanf("%s",&tempPass);
    strcpy(u[count].password, tempPass);
    printf("Registration successful");
    count++;
    return 0;
}

int login()
{
    int i;
    char pswd[8];
    char name[10];
     char tempPass[8];    
    printf("Login User\n");
    printf("enter username\n");
    scanf("%s",name);
    printf("Enter password\n");
    scanf("%s",pswd);
    for (i = 0; i <= count; i++)
    {
        if (strcmp(name, u[i].username) == 0 && strcmp(pswd, u[i].password) == 0)
        {
            return i;
        }
    }
    return -1;
}
