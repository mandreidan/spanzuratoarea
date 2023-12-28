#include <stdio.h>
#include <string.h>

char spanzuratoare[40][40];
void model_spanzuratoarea(char v[40][40])
{
    for(int i=1;i<=10;i++)
    {
        v[14][i]='_';
    }
    for(int i=2;i<=14;i++)
    {
        v[i][3]='|';
        v[i][8]='|';
    }
    for(int i=3;i<=29;i++)
    {
        v[1][i]='_';
    }
    for(int i=8;i<=26;i++)
    {
        v[2][i]='_';
    }
    v[3][26]='|';
    v[2][29]='|';
    v[3][29]='|';
}
void deseneaza(int n,char v[40][40])
{
    if(n==1)
    {
        v[3][25]=v[3][27]=v[3][28]=v[3][30]='_';
        v[4][24]=v[5][24]='|';
        v[4][31]=v[5][31]='|';
        for(int i=25;i<=30;i++) v[5][i]='_';
    }
    if(n==2)
    {
        v[6][26]=v[6][29]='|';
    }
    if(n==3)
    {
        for(int i=7;i<=9;i++)
        {
            v[i][24]='|';
            v[i][31]='|';
        }
        for(int i=25;i<=30;i++)
        {
            v[9][i]='_';
        }
    }
    if(n==4)
    {
        for(int i=20;i<=23;i++)
        {
            v[6][i]=v[7][i]='_';
        }
        v[7][19]='|';
    }
    if(n==5)
    {
        for(int i=32;i<=35;i++)
        {
            v[6][i]=v[7][i]='_';
        }
        v[7][36]='|';
    }
    if(n==6)
    {
        for(int i=10;i<=11;i++)
        {
            v[i][24]='|';
            v[i][26]='|';
        }
        v[11][25]='_';
    }
    if(n==7)
    {
        for(int i=10;i<=11;i++)
        {
            v[i][29]='|';
            v[i][31]='|';
        }
        v[11][30]='_';
    }
}
void afisare(char v[40][40])
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<40;j++)
        {
            printf("%c",v[i][j]);
        }
        printf("\n");
    }
}

int main() {

    char cuvant[100];
    printf("Bun venit la Spanzuratoarea\nScrieti ghicitoarea care trebuie gasita de prietenii tai: ");
    int nr_cuvinte=0;
    for (int i = 0; i < 100; i++) {
        scanf ("%c", &cuvant[i]);
        if(cuvant[i]==' ') nr_cuvinte++;
        if (cuvant[i] == 10)
        {
            nr_cuvinte++;
            cuvant[i] = '\0';
            break;
        }
    }

    if(nr_cuvinte>1) printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nGhicitoarea este din %d cuvinte\n\n", nr_cuvinte);
    else
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nGhicitoarea este dintr-un cuvant cu %llu litere \n", strlen(cuvant));
    }
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
