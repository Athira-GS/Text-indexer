#include"common.h"

void print_database(hash_table_t t)
{
	node_t *temp;
	Slink *temp1;
	int i;
	for(i=0;i<SIZE;i++)
	{
		if(t.table[i] != NULL)
		{
			printf("\nindex : [%d]\n",i);
			temp=t.table[i];
			while(temp)
			{
				printf("\nword : [%s]\n",temp->word);
				printf("file count :%d\t",temp->file_count);
				//declare pointer for traversing through file table
				temp1=temp->file_table;
				while(temp1)
				{
					printf("file name : [%s]\t",temp1->file_name);
					printf("word count : %d\t",temp1->word_count);

					temp1=temp1->link;
				}

				temp=temp->link;
			}
			printf("\n");
		}
	}
}


