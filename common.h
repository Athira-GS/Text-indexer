#ifndef COMMON_H
#define COMMON_H

//1.standard header
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define SIZE 26
#define SUCCESS 0
#define FAILURE 1


//structure

typedef struct file_table
{
	char *file_name;
	int word_count;
	struct file_table *link; 
}Slink;

typedef struct node
{
	char *word;
	int file_count;
	Slink *file_table;
	struct node *link;
}node_t;

typedef struct database
{
	node_t *table[SIZE];
}hash_table_t;

int create_database(hash_table_t *t,char **argv,int argc);

void print_database(hash_table_t t);
void delete_database(hash_table_t *t); 
void search_database(hash_table_t t,char *str);
void search_file_database(hash_table_t t,char *file);
void save_database(hash_table_t t);
#endif
