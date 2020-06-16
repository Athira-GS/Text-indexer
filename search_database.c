#include"common.h"

void search_database(hash_table_t t,char *str)
{
	node_t *temp;
	Slink *temp2;
	 if((str[0] >= 65 && str[0] <=90) || (str[0] >= 97 && str[0] <=122))
	 {

	if(str[0] >= 97 && str[0]<= 122)
        {
           str[0]=toupper(str[0]);
        }
                int index=str[0]-65;

				//declare temp to traverse through nodes
				temp=t.table[index];
				while(temp)
				{
					if((strcasecmp(str,temp->word)) == 0)
					{
						printf("word : [%s]\n",temp->word);
						printf("file count : %d",temp->file_count);
						//declare temp2 to traverse through file table
						temp2=temp->file_table;
						while(temp2)
						{
							printf("file name : [%s]",temp2->file_name);
							printf("file count : %d",temp2->word_count);



						temp2=temp2->link;
						}

					}

					temp=temp->link;

				}
	 }
				printf("\n");

}
