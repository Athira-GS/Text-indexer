#include"common.h"

void search_file_database(hash_table_t t,char *file)
{
	node_t *temp;
	Slink *temp1;
	int i;
	for(i=0;i<SIZE;i++)
	{
		if(t.table[i] != NULL)
		{
			//declare temp to traverse through nodes
			temp=t.table[i];
			while(temp)
			{
				//declare temp1 to traverse through file table
				temp1=temp->file_table;
				while(temp1)
				{

					if((strcmp(file,temp1->file_name)) ==0)
					{
						printf("\nword : [%s]\n",temp->word);
						printf("file name : [%s]\t",temp1->file_name);
						printf("word count : %d\n",temp1->word_count);
						break;


					}


                 temp1=temp1->link;
				}

				temp=temp->link;
			}


		}
	}

}
