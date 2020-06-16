#include"common.h"


int main(char argc,char **argv)
{
	int i,j;
	hash_table_t t;
	//if more than 1 file is there we need to compare each file name with 1st file name
	if(argc >2)
	{
		for(i=0;i<argc-1;i++)
		{
			for(j=i+1;j<argc;j++)
			{
				if(!(strcmp(argv[i],argv[j])))
				{
					printf("ERROR:same file is found multiple times\n");


				}
			}
		}


	}
	//check whether any file is given or not
	if(argc == 1)
	{
		printf("ERROR:No file is given");
	}
	FILE *fp1;
	//open 1st file
	fp1=fopen(argv[1],"r");
	//check whether the file is empty
	if(fp1==NULL)
	{
		printf("ERROR:file is empty");
		return FAILURE;

	}
	//check whether the file is .txt or not
	for(i=0;i<argc;i++)
	{
		if(strstr(argv[i],".txt"))
		{
			printf("file is .txt form\n");
		}
		else
		{
			printf("ERROR:file is not .txt form\n");
		}
	}
int option;
char choice;
char str[10];
char file[10];
do
{
printf("1.create database\n2.update database\n3.search database\n4.delete database\n5.print database\n6.search file\n7.save database\n");
printf("enter choice:");
scanf("%d",&option);
switch(option)
{
	case 1:
		create_database(&t,argv,argc);
		break;
	case 3:
		printf("enter the string to be search :");
		scanf("%s",&str);
		
		search_database(t,str);
		break;
	case 4:
		delete_database(&t);
		break;
	case 5:
		print_database(t);
		break;
	case 6:
		printf("enter the file to be search :");
		scanf("%s",&file);
		
		search_file_database(t,file);
		break;
	case 7:
		save_database(t);
		break;
		

	default:
		printf("invalid option\n");
}

getchar();
        printf("\nDo you want to continue:");
        scanf("%c",&choice);

    }while(choice == 'y' ||choice =='Y');

}



		

		






