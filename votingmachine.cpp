#include <stdio.h>
#include <string.h>

int main() 
{
    char parties[4][30] = {"BJP", "CONGRESS", "SAMAJVADI", "OTHERS"};
    int votes[4] = {0};
    char voters[300][100];
    long long int _Phone_Numbers[50];
    int totalVoters = 0;

    while (1) 
    {
        char name[50], gender, id[10];
        int age;

        printf("Enter your name: ");
        scanf("%s", name);

        printf("Enter your gender (M/F): ");
        scanf(" %c", &gender);

        printf("Enter your age: ");
        scanf("%d", &age);

        if (age < 18) 
        {
            printf("You are under 18 years old. Cannot vote. \n");
            continue;
        }

        printf("Enter your Phone Number(10 digits) : ");
        scanf("%lld", &_Phone_Numbers[totalVoters]);

        if (_Phone_Numbers[totalVoters] < 1000000000 || _Phone_Numbers[totalVoters] > 9999999999) 
        {
            printf("\n Invalid roll number. Please enter a 10-digit roll number. ");
            continue;
        }

        int alreadyVoted = 0;
        for (int i = 0; i < totalVoters; i++) 
        {
            if (_Phone_Numbers[totalVoters] == _Phone_Numbers[i]) 
            {
                alreadyVoted = 1;
                continue;
            }
        }

        if (alreadyVoted) 
        {
            printf("You have already voted. Invalid vote. \n");
        } else 
        {
            printf("\n Choose a party:");
            for (int i = 0; i < 4; i++) 
            {
                printf("\n %d. %s", i + 1, parties[i]);
            }

            int vote;
            printf("Enter the party number you want to vote for: ");
            scanf("%d", &vote);

            if (vote >= 1 && vote <= 4) 
            {
                votes[vote - 1]++;
                strcpy(voters[totalVoters], name);
                totalVoters++;
                printf("\n Vote cast successfully!");
            } else 
            {
                printf("\n Invalid party number. Vote not counted.");
            }
        }

        printf("Enter 0 to exit or any other number to continue: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 0) 
        {
            break;
        }
    }

    printf("\n Election Results:");
    for (int i = 0; i < 4; i++) 
    {
        printf("\n %s: %d votes", parties[i], votes[i]);
    }

    printf("\n List of Voters:\n");
    for (int i = 0; i < totalVoters; i++) 
    {
        printf("\n %s - Phone Number: %lld ", voters[i], _Phone_Numbers[i]);
    }

//   return 0;
}
