// Anuj Bhosale 23rd August JAVA Full Stack online batch
// FBS ID- FRN-11J0823/072
//  C mini project==>> Player management system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct player
{
    int jno, runs, wickets, matches;
    char name[20];
} player;
void store(player *, int);
void display(player *);
int searchbyjno(player *, int);
void display1(player *, int);
int searchbyname(player *, char *);
void deletee(player *, int);
void update(player *, int);
void topruns(player *);
void topwickets(player *p);
int ctr = 0;
int main()
{
    player *p;
    int choice, size, jnum, ch;
    char pname[20];
    printf("Enter the number of players: \n");
    scanf("%d", &size);
    p = (player *)malloc(sizeof(player) * size);
    do
    {
        printf("Press 1 to store the record of player: \n");
        printf("Press 2 to display the record of player: \n");
        printf("Press 3 to search the record of player(jno/name): \n");
        printf("Press 4 to delete the record of player: \n");
        printf("Press 5 to update the record of player: \n");
        printf("Press 6 to display TOP-3  record of player: \n");
        printf("Press 0 to exit the program\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            store(p, size);
            break;
        }
        case 2:
        {
            display(p);
            break;
        }
        case 3:
        {
            printf("Press 1 to search by jersey number: \n");
            printf("Press 2 to search by name of player: \n");
            scanf("%d", &ch);
            if (ch == 1)
            {
                printf("Enter the jersey number to search the record: \n");
                scanf("%d", &jnum);
                searchbyjno(p, jnum);
                int index = searchbyjno(p, jnum);
                display1(p, index);
                break;
            }
            else if (ch == 2)
            {
                printf("Enter the name of player to search record: \n");
                scanf("%s", &pname);
                int index = searchbyname(p, pname);
                display1(p, index);
                break;
            }
            else
            {
                printf("Invalid selection !!!\n");
            }
            break;
        }
        case 4:
        {
            printf("Enter the jersey number to delete the record: \n");
            scanf("%d", &jnum);
            searchbyjno(p, jnum);
            int index = searchbyjno(p, jnum);
            deletee(p, index);
            break;
        }
        case 5:
        {
            printf("Enter the jersey number to update the record: \n");
            scanf("%d", &jnum);
            searchbyjno(p, jnum);
            int index = searchbyjno(p, jnum);
            update(p, index);
            break;
        }
        case 6:
        {
            topruns(p);
            topwickets(p);
            break;
        }
        }
    } while (choice != 0);
}
void store(player *p, int s)
{

    if (ctr < s)
    {
        printf("Enter the jersey no of player: \n");
        scanf("%d", &p[ctr].jno);
        printf("Enter the name of player: \n");
        scanf("%s", &p[ctr].name);
        printf("Enter the number of matches of player: \n");
        scanf("%d", &p[ctr].matches);
        printf("Enter the runs of player: \n");
        scanf("%d", &p[ctr].runs);
        printf("Enter the wickets of player: \n");
        scanf("%d", &p[ctr].wickets);
        ctr++;
    }
    else
    {
        printf("List is full !!\n");
    }
}
void display(player *p)
{
    int i;
    for (i = 0; i < ctr; i++)
    {
        printf("The jersey number of player is '%d' the name is '%s' the  number of matches played are '%d' runs are '%d' and wicket takens are '%d'\n", p[i].jno, p[i].name, p[i].matches, p[i].runs, p[i].wickets);
    }
}
int searchbyjno(player *p, int jnum)
{
    int i;
    for (i = 0; i < ctr; i++)
    {
        if (p[i].jno == jnum)
        {
            return i;
        }
    }
    return -1;
}
void display1(player *p, int index)
{

    if (index == -1)
    {
        printf("Player not found !!\n");
    }
    else
    {
        printf("The jersey number of player is '%d' the name is '%s' the  number of matches played are '%d' runs are '%d' and wicket takens are '%d'\n", p[index].jno, p[index].name, p[index].matches, p[index].runs, p[index].wickets);
    }
}
int searchbyname(player *p, char *pname)
{
    int i;
    for (i = 0; i < ctr; i++)
    {
        if (strcmp(p[i].name, pname) == 0)
        {
            return i;
        }
    }
    return -1;
}
void deletee(player *p, int index)
{
    int i;
    for (i = index; i < ctr; i++)
    {
        p[i] = p[i + 1];
    }
    ctr--;
    printf("After deleting the remaining players record: \n");
    for (i = 0; i < ctr; i++)
    {
        printf("The jersey number of player is '%d' the name is '%s' the  number of matches played are '%d' runs are '%d' and wicket takens are '%d'\n", p[i].jno, p[i].name, p[i].matches, p[i].runs, p[i].wickets);
    }
}
void update(player *p, int index)
{
    int choi;

    if (index != -1)
    {
        do
        {
            printf("What you want to update ?\n");
            printf("press 1 to update the number of matches\n");
            printf("press 2 to update the number of runs\n");
            printf("press 3 to update wickets taken\n");
            printf("press 0 to exit\n");
            scanf("%d", &choi);
            switch (choi)
            {
            case 1:
            {
                printf("Enter the updated number of matches of player: \n");
                scanf("%d", &p[index].matches);
                break;
            }
            case 2:
            {
                printf("Enter the updated runs of player: \n");
                scanf("%d", &p[index].runs);
                break;
            }
            case 3:
            {
                printf("Enter the updated wickets taken by player: \n");
                scanf("%d", &p[index].wickets);
                break;
            }
            }
        } while (choi != 0);
    }
    else
    {
        printf("Invalid !!!\n");
    }
}
void topruns(player *p)
{
    for (int i = 0; i < ctr; i++)
    {
        for (int j = i + 1; j < ctr; j++)
        {
            if (p[i].runs < p[j].runs)
            {
                player temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    printf("Top 3 players by runs are: \n");
    for (int i = 0; i < 3 && i < ctr; i++)
    {
        printf("The jersey number of player is '%d' the name is '%s' the  number of matches played are '%d' runs are '%d' and wicket takens are '%d'\n", p[i].jno, p[i].name, p[i].matches, p[i].runs, p[i].wickets);
    }
}
void topwickets(player *p)
{
    for (int i = 0; i < ctr; i++)
    {
        for (int j = i + 1; j < ctr; j++)
        {
            if (p[i].wickets < p[j].wickets)
            {
                player temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    printf("Top 3 players by wickets are: \n");
    for (int i = 0; i < 3 && i < ctr; i++)
    {
        printf("The jersey number of player is '%d' the name is '%s' the  number of matches played are '%d' runs are '%d' and wicket takens are '%d'\n", p[i].jno, p[i].name, p[i].matches, p[i].runs, p[i].wickets);
    }
}