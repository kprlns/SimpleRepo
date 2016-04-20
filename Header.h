#include <stdlib.h>
#include <time.h>

char surname[20][10]=
{"Biersak","Williams","Jovi",
"Redkliff","Gates","Jobs",
"Mercury","Sykes","Greenwood",
"Skywalker", "Facker", "Stone",
"Stark", "Potter", "Weasley",
"Dumbledore", "Snape", "Parker",
"Manson", "Lindemann"}

char inits[23][3]={"P.A","R.A","M.O","R.E",
"B.M","T.H",
"L.P",
"M.E","T.A","L.L","I.C","C.A",
"J.O", "H.N","B.O","N.N" "J.O", "V.I"
"A.M","A.R","A.N","T.H","E.E"
}

typedef struct Human
{
  char surname[10];
  char init[3];
  char gender;
  int group;
  int marks[4];
}Human;



void base_print(char* file_path) // распечатка базы
{
    FILE* f;
    f=fopen(file_path, "rb");
    if(f)
    {
        int i=1;
        Human h;
        while( ( fread(&h,sizeof(Human),1,f) )>0 )
        {
            printf("%d) %s %s Gender: %c. Group #%d \t Marks:",i,h.surname,h.init,h.gender, h.group);
            for(int z=0; z<4; z++)
            {
                printf(" %d",h.marks[z]);
            }
            printf("\n");
        }
    }
    else {printf("Error while opening the file.\n")}
}






Human random_add(char* surname, char* init, char gender) //генерация структуры для 1 человека
{
  Human h;
  for(int i=0;i<10;i++)
  {
    h.surname[i]=surname[i];
  }
  for(int i=0;i<3;++)
  {
     h.init[i]=inits[i]
  }

  for(int i=0; i<4; i++)
  {
   h.marks[i]=2+rand()%4;
  }
  h.group=101+(rand()%8);
  return p;
}


void base_create(char* file) //создание базы
{
  FILE* f;
  srand((unsigned) time(0) );
  f=fopen(file,"wb");
  if(f)
  {
    int num=0;
    printf("How much elements in base do you need?\n");
    scanf("%d",&num);
    for (int i = 0;i<num;i++)
    {
      int rs=rand()%20, ri=rand()%23;
      char g;
      if((rs+ri)%2) g='M';
      else g='F';
      Human a=random_add(surname[rs], inits[ri], &g);
      fwrite(&a,sizeof(a),1,f);
    }
    fclose(f);
    printf("Creation proceeded successful\n", );
  }
  else
  {
    printf("Error while opening the file.\n");
  }
}

void manual_add(char* file) //ручное добавление в базу
{
  FILE* f;
  f=fopen(file,"a+b");
  if(f)
  {
    printf("How much elements do you need to add?\n");
    Human h;
    int num;
    scanf("%d",&num);
    for (int i=0; i<num;i++)
    {
      scanf("%s%s%c%d", &h.surname, &h.inits, &h.gender, &h.group);
      for (int j=0;j<4;j++)
      {
        scanf("%d", &h.marks[j]);
        if(p.marks[j]<2) p.marks[j]=2;
        if(p.marks[j]>5) p.marks[j]=5;
      }
      fwrite(&p,sizeof(Human),1,f);
    }
    fclose(f);
    printf("Addition proceeded successful\n");
  }
  else {printf("Error while opening the file.\n");}
}

void deletion_by_number(char* file_path, int n) //удаляет элемент по номеру
{
    int num=1;
    FILE* f=fopen(file_path,"rb");
    FILE* to_delete=fopen("del.dat","w+b");
    Human h;
    if(f&&to_delete)
    {
    while(fread(&h,sizeof(Human),1,f)>0)
    {
        if(num!=n)
        {
            fwrite(&h,sizeof(Human),1,to_delete)
            i++;
        }
        else i++;

    }
    rewind(to_delete);
    fclose(f);
    fopen(file_path,"wb");
    while(fread(&h,sizeof(Human),1,f)>0)
    {
        fwrite(&h,sizeof(Human),1,f);
    }
    fclose(f); fclose(to_delete);
    remove("del.dat");
    }
    else printf("Error while opening files\n" );

}
int comparator(char* a, char*b)
{
    for(int i=0;i<10;i++)
    {
        if(a[i]!=b[i]) return 0;
        if(a[i]==b[i] && a[i]=='\0') return 1;
    }
}

void deletion_by_surname(char* path, char* surname)
{
    Human h;
    FILE* f=fopen(path,"rb");
    FILE* delete=fopen("name.dat","w+b");
    if(f&&delete)
    {
        while(fread(&h,sizeof(Human),1,f)>0)
        {
            if(comparator(&q.name,name))
            {
                char c;
                printf("\n");
                printf("%s %s %c %d %d %d %d %d\n",h.surname,h.init,h.gender,h.group,h.marks[0],h.marks[1],h.marks[2],h.marks[3]);
                printf("Delete this student?[Y/n]\n");
                while(1)
                {
                    scanf("%c",&c);
                    if(c=='N' || c=='n' || c=='Y' || c=='y') break;
                    else print("Error,enter[Y/n]\n");
                }
                if(c=='N' || c=='n')
                {
                    fwrite(&h,sizeof(Human),1,delete);
                }
            }
            else
            {
                fwrite(&h,sizeof(Human),1,delete);
            }
        }
        fclose(f);
        rewind(delete);
        fopen(path, "wb");
        while(fread(&h,sizeof(Human),1,delete)>0)
        {
            fwrite(&h,sizeof(Human),1,f);
        }
        fclose(f);fclose(delete);
        remove("name.dat");
    }
    else {printf("Error while opening files\n");}
}

    int task(char* path, int n)
    {
        FILE* f=fopen(path,"rb");
        if(f)
        {
            int res=0; Human h;
            while(fread(&h,sizeof(Human),1,f)>0)
            {
                if(h.group==n && h.gender=='F')
                {
                    int flag=1;
                    for(int i=0;i<4;i++)
                    {
                        if(h.marks[i]<4) flag=0;
                    }
                    if(flag) res++;
                }
            }
        return (res);
        }
        else {printf("Error while opening file"); return -1;}
    }







void delete_base(path* char)
{
    FILE* f=fopen(path,"wb");
    if(f)
		fclose(f);
	else
		printf("I can not find or open the file.\n");
}
