/*#include"common.h"

void update_database(hash_table_t *t,char *file);
{
	Slink *temp_1,*temp_2;
	node_t *temp,*temp1;
	FILE *fptr;
	char ch;
	int count_1;
	fptr=fopen(file,"r");
	for(i=1;i<SIZE;i++)
	{
		if(t->table[i] != NULL)
		{
			temp=t->table[i];
			while(temp)
			{
				temp1=temp->file_table;
				while(temp_1)
				{
				if(strcmp(file,temp_1->file_name)==0)
				{
					count_1=0;




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
							if((strcasecmp(arr_1,temp->word))==0)	
							{
								count_1++;
							}
						}
					}
					rewind(file);
				}

				if(count_1 == 0)
				{
					//case 1: where no other nodes and filetable is there 

					if( (temp->link == NULL) && (temp->file_table->link==NULL))
					{
						if(temp == t->table[i])
						{
							t->table[i]=NULL;
						}
						else
						{
							pre_temp->link=NULL;
							free(temp);
						}
					}
					//case 2:where no other nodes but other filetable is there
					if( (temp->link == NULL) && (temp->file_table->link != NULL))
					{
                        Slink *temp3
						//declare temp which is pointing to the file table of that node
						temp3=temp->file_table;
								temp_2=temp;
								temp=temp->link;
								free(temp2);

						t->table[i]->file_count--;
					}

					//case 3:where other nodes are there but no other filetable is there


					if( (t->table[i]->link != NULL) && (t->table[i]->file_table->link == NULL))
					{


						//declare pointer to traverse through nodes

						temp=t->table[i];
						while(temp)
						{
							//declare pointer to traverse through file table

							temp_1=temp_1->file_table;
							while(temp_1)
							{
								if((strcmp(file,temp_1->file_name)) == 0)
								{
									temp_2=temp1;

									temp_2=temp_2->link;
									free(temp_2);
								}
							}
							temp1=temp;
							temp=temp->link;
							free(temp1);
						}

					}
					//case 4: if multiple nodes and filetable is present


					if( (t->table[i]->link != NULL) && (t->table[i]->file_table->link != NULL))
					{
						//declare pointer to traverse through each node
						temp=t->table[i];
						while(temp)
						{
							temp_1=temp->file_table;
							while(temp_1)
							{
								if((strcmp(file,temp_1->file_name)) == 0)
								{


									temp2=temp_1	
										temp_1=temp_1->link;
									free(temp2);
									temp->file_table=temp_1;

								}

							}
							temp=temp->link;
						}
					}
				}
			}
		}*/
