#include"common.h"

int create_database(hash_table_t *t,char **argv,int argc)
{
	char ch;
	int i,j;
	int flag = 0;
	node_t  *temp,*pre_temp;
	Slink *temp1,*temp2;
	//initially make each index of the array as NULL
	for(i=0; i<SIZE;i++)
	{
		t->table[i]=NULL;
	}

	FILE *fptr;
	for(j=1;j<argc;j++)
	{
		printf("filename %s\n", argv[j]);
	//	fptr=argv[i];
		fptr=fopen(argv[j],"r");
		if(fptr == NULL)
		{
			printf("ERROR:file is empty\n");
			return FAILURE;
		}
		while((ch = fgetc(fptr)) != EOF)
		{
			if((ch >= 65 && ch <=90) || (ch >= 97 && ch <=122))
			{
				int count=0;
				while(1)
				{
					ch =  fgetc(fptr);
					if((ch == ' ') || (ch =='\n'))
					{
						break;
					}
					count++;
				}
				char arr_1[count];
				//go to the initial position of that word
				fseek(fptr, -(count + 2), SEEK_CUR);
				i=0;
				while(1)
				{
					ch =  fgetc(fptr);
					if((ch == ' ') || (ch =='\n'))
					{
						break;
					}
					arr_1[i++]=ch;
				}
				arr_1[i]='\0';
			//	printf("%s\n",arr_1);
			//	printf("1st ch=%c\n",arr_1[0]);
				//findout the index of each word in the array
				if(arr_1[0] >= 97 && arr_1[0]<= 122)
				{
					arr_1[0]=toupper(arr_1[0]);
					printf("%c\n",arr_1[0]);
				}
				int index=arr_1[0];
			//	printf("%d\n",index);
			//	if(index > SIZE)
			//	{
					index=index-65;
			//	}
			//	printf("index=%d\n",index);
				if(t->table[index]==NULL)
				{
		printf("if filename %s\n", argv[j]);
		//			printf("str %s\n", arr_1);
					//allocating memory for each node
					t->table[index]=malloc(sizeof(node_t));
					//creating memory for storing the word
					t->table[index]->word=malloc(count * sizeof(char));
					//store that word in that memory
					strcpy(t->table[index]->word,arr_1);
					//initially file count will be 1
					t->table[index]->file_count=1;
					//creating memory for file table
		//			printf("dsad\n");
					t->table[index]->file_table=malloc(sizeof(Slink));
		//			printf("dhhhhsad\n");
		//			printf("strlen %d\n", strlen(argv[j]));
					//allocating memory for file name
					t->table[index]->file_table->file_name=malloc(strlen(argv[j]) * sizeof(char));
		//			printf("dsabbbd\n");
					//storing file name
					strcpy(t->table[index]->file_table->file_name,argv[j]);
		//			printf("dsad\n");
					//making link part as null
					t->table[index]->link=NULL;
		//			printf("dsad\n");
					//making link part of file table as null
					t->table[index]->file_table->link=NULL;
					//initialise word count of file table as 1
					t->table[index]->file_table->word_count=1;
					
				}
				//if table is not null
				else
				{
		printf("else filename %s\n", argv[j]);
		//			printf("str2 %s\n", arr_1);
					//declare a pointer 
					temp=t->table[index];
					while(1)
					{
						//compare the string already present in the node & string which is coming
						if((strcasecmp(arr_1,temp->word)) ==0)
						{
		//				printf("fdsfsfdsf arr_1 %s and temp->word %s\n", arr_1, temp->word);
							//increment word count;
							//temp->file_table->word_count++;
							temp1=temp->file_table;
							while(1)
							{
								//check whether the same strings are present in different file or not
								if((strcmp(argv[j],temp1->file_name)) !=0)
								{
									printf("strcmp=%d\n",(strcmp(argv[j],temp1->file_name)));




									//store temp1 in a new variable
									temp2=temp1;
									//updating temp1
									temp1=temp1->link;
								}
								else
								{
									temp1->word_count++;
									flag = 1;
									break;
								}

								if(temp1==NULL)
								{
									temp->file_count++;
									//update link of previous file table


									//create memory for new file table
									Slink *new = malloc(sizeof(Slink));
									//create memory for file name
									new->file_name=malloc(strlen(argv[j]) *sizeof(char));
									strcpy(new->file_name, argv[j]);
									new->word_count=1;
									new->link = NULL;
									flag = 1;

									temp2->link = new;
									break;
								}
							}

						}
						if(flag == 1)
						{
							flag = 0;
							break;
						}
						pre_temp=temp;
						temp=temp->link;
						if(temp == NULL)
						{
		//					printf("SADA\n");
                          //create memory for another node
                            pre_temp->link=malloc(sizeof(node_t));
                            //create memory for string
                            pre_temp->link->word=malloc(count * sizeof(char));
                            //store string
                            strcpy(pre_temp->link->word,arr_1);
                            pre_temp->link->file_count=1;
                            //creating memory for file table
                            pre_temp->link->file_table=malloc(sizeof(Slink));
                            //creating memory for file name
                            pre_temp->link->file_table->file_name=malloc(strlen(argv[j]));
                            //storing file name
                            strcpy(pre_temp->link->file_table->file_name,argv[j]);
                            //initialise word count of file table as 1
                            pre_temp->link->file_table->word_count=1;
							break;


						}
					}


				}


			}
		}
	}
	fclose(fptr);
}









