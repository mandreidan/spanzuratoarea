#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define dimensiune_matrice 40
#define lungime_maxima_cuvant 100

void model_spanzuratoarea(char spanzuratoare[dimensiune_matrice][dimensiune_matrice])
{
    for(int i=1;i<=10;i++)
    {
        spanzuratoare[14][i]='_';
    }
    for(int i=2;i<=14;i++)
    {
        spanzuratoare[i][3]='|';
        spanzuratoare[i][8]='|';
    }
    for(int i=3;i<=29;i++)
    {
        spanzuratoare[1][i]='_';
    }
    for(int i=8;i<=26;i++)
    {
        spanzuratoare[2][i]='_';
    }
    spanzuratoare[3][26]='|';
    spanzuratoare[2][29]='|';
    spanzuratoare[3][29]='|';
}
void deseneaza(int n,char spanzuratoare[dimensiune_matrice][dimensiune_matrice])
{
    if(n==1)
    {
        spanzuratoare[3][25]=spanzuratoare[3][27]=spanzuratoare[3][28]=spanzuratoare[3][30]='_';
        spanzuratoare[4][24]=spanzuratoare[5][24]='|';
        spanzuratoare[4][31]=spanzuratoare[5][31]='|';
        for(int i=25;i<=30;i++) spanzuratoare[5][i]='_';
    }
    if(n==2)
    {
        spanzuratoare[6][26]=spanzuratoare[6][29]='|';
    }
    if(n==3)
    {
        for(int i=7;i<=9;i++)
        {
            spanzuratoare[i][24]='|';
            spanzuratoare[i][31]='|';
        }
        for(int i=25;i<=30;i++)
        {
            spanzuratoare[9][i]='_';
        }
    }
    if(n==4)
    {
        for(int i=20;i<=23;i++)
        {
            spanzuratoare[6][i]=spanzuratoare[7][i]='_';
        }
        spanzuratoare[7][19]='|';
    }
    if(n==5)
    {
        for(int i=32;i<=35;i++)
        {
            spanzuratoare[6][i]=spanzuratoare[7][i]='_';
        }
        spanzuratoare[7][36]='|';
    }
    if(n==6)
    {
        for(int i=10;i<=11;i++)
        {
            spanzuratoare[i][24]='|';
            spanzuratoare[i][26]='|';
        }
        spanzuratoare[11][25]='_';
    }
    if(n==7)
    {
        for(int i=10;i<=11;i++)
        {
            spanzuratoare[i][29]='|';
            spanzuratoare[i][31]='|';
        }
        spanzuratoare[11][30]='_';
    }
}
void afisare(char spanzuratoare[40][40])
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<40;j++)
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

    char ghicitoare[100];
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
