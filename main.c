#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define dimensiune_matrice 40
#define lungime_maxima_cuvant 100
#define dim_spanzuratoare_1 10
#define dim_spanzuratoare_2 14
#define dim_spanzuratoare_3 3
#define dim_spanzuratoare_4 8
#define body_length1 25
#define body_length2 30
#define gat_height 6
#define mana_height 6
#define mana_s_length 20
#define mana_d_length 32
#define picior_height 10
#define body_height 9







void model_spanzuratoarea(char spanzuratoare[dimensiune_matrice][dimensiune_matrice])
{
    for(int i=1;i<=dim_spanzuratoare_1;i++)
    {
        spanzuratoare[dim_spanzuratoare_2][i]='_';
    }
    for(int i=2;i<=dim_spanzuratoare_2;i++)
    {
        spanzuratoare[i][dim_spanzuratoare_3]='|';
        spanzuratoare[i][dim_spanzuratoare_4]='|';
    }
    for(int i=3;i<=body_length2-1;i++)
    {
        spanzuratoare[1][i]='_';
    }
    for(int i=dim_spanzuratoare_4;i<=body_length1+1;i++)
    {
        spanzuratoare[2][i]='_';
    }
    spanzuratoare[3][body_length1+1]='|';
    spanzuratoare[2][body_length2-1]='|';
    spanzuratoare[3][body_length2-1]='|';
}
void deseneaza(int n,char spanzuratoare[dimensiune_matrice][dimensiune_matrice])
{
    if(n==1) //cap
    {
        for(int i=body_length1;i<=body_length2;i++) spanzuratoare[3][i]='_';
        spanzuratoare[4][body_length1-1]=spanzuratoare[5][body_length1-1]='|';
        spanzuratoare[4][body_length2+1]=spanzuratoare[5][body_length2+1]='|';
        for(int i=body_length1;i<=body_length2;i++) spanzuratoare[5][i]='_';
    }
    if(n==2) //gat
    {
        spanzuratoare[gat_height][body_length1+1]=spanzuratoare[gat_height][body_length2-1]='|';
    }
    if(n==3) //body
    {
        for(int i=gat_height+1;i<=body_height;i++)
        {
            spanzuratoare[i][body_length1-1]='|';
            spanzuratoare[i][body_length2+1]='|';
        }
        for(int i=body_length1;i<=body_length2;i++)
        {
            spanzuratoare[body_height][i]='_';
        }
    }
    if(n==4)//mana stanga
    {
        for(int i=mana_s_length;i<=mana_s_length+3;i++)
        {
            spanzuratoare[mana_height][i]=spanzuratoare[mana_height+1][i]='_';
        }
        spanzuratoare[mana_height+1][mana_s_length-1]='|';
    }
    if(n==5) //mana dreapta
    {
        for(int i=mana_d_length;i<=mana_d_length+3;i++)
        {
            spanzuratoare[mana_height][i]=spanzuratoare[mana_height+1][i]='_';
        }
        spanzuratoare[mana_height+1][mana_d_length+4]='|';
    }
    if(n==6) //picior stang
    {
        for(int i=picior_height;i<=picior_height+1;i++)
        {
            spanzuratoare[i][body_length1-1]='|';
            spanzuratoare[i][body_length1+1]='|';
        }
        spanzuratoare[picior_height+1][body_length1]='_';
    }
    if(n==7) //picior drept
    {
        for(int i=picior_height;i<=picior_height+1;i++)
        {
            spanzuratoare[i][body_length2-1]='|';
            spanzuratoare[i][body_length2+1]='|';
        }
        spanzuratoare[picior_height+1][body_length2]='_';
    }
}
void afisare(char spanzuratoare[dimensiune_matrice][dimensiune_matrice])
{
    for(int i=0;i<dimensiune_matrice/2;i++)
    {
        for(int j=0;j<dimensiune_matrice;j++)
        {
            printf("%c",spanzuratoare[i][j]);
        }
        printf("\n");
    }
}

int main() {

    char spanzuratoare[dimensiune_matrice][dimensiune_matrice]={0};
    char cuvant[lungime_maxima_cuvant];
    printf("Bun venit la Spanzuratoarea\n");

    FILE *pf= fopen("C:\\Users\\Lenovo\\Desktop\\text.txt","r");

    srand(time(NULL));
    int random_variable = rand()%10000;
    for(int i=0;i<random_variable;i++)
    {

        fgets(cuvant ,lungime_maxima_cuvant,pf);

    }

    fclose(pf);





    printf("Cuvantul este din %llu litere \n", strlen(cuvant)-1);

    char ghicitoare[lungime_maxima_cuvant];
    strcpy(ghicitoare,cuvant);
    for(int i=0;i<strlen(cuvant);i++)
    {
        if((cuvant[i]>='a' && cuvant[i]<='z') || (cuvant[i]>='A' && cuvant[i]<='Z'))
        {
            ghicitoare[i]='_';
        }
    }
    printf("%s\n",ghicitoare);
    model_spanzuratoarea(spanzuratoare);
    int nr=0;
    while(nr<7)
    {
        char litera[100];
        printf("Litera urmatoare este:");
        scanf("%s",litera);
        int ok=0;
        for(int i=0;i<strlen(ghicitoare);i++)
        {
            if((cuvant[i]==litera[0]) || (cuvant[i] == litera[0]+32) || (cuvant[i]+32 == litera[0]))
            {
                ghicitoare[i]=cuvant[i];
                ok++;
            }
        }

        if(ok==0)
        {
            nr++;
            deseneaza(nr,spanzuratoare);
        }
        afisare(spanzuratoare);
        printf("%s\n",ghicitoare);
        if(strcmp(cuvant,ghicitoare)==0)
        {
            printf("%s","Ai ghichit. Felicitari!");
            break;
        }
    }
    if(nr==7) printf("N-ai ghicit.\nCuvantul era %s", cuvant );


    return 0;
}
