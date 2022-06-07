#include "jparser.h" //jparse(), trim(), get_token(), ...
#include <stdio.h> //printf()
#include <string.h> //strlen()
#include <stdlib.h> //malloc() e realloc()
#include <ctype.h> //isspace()

int jparse(char *stream, size_t len)
{
	char *string = malloc(sizeof(char) * len);
	strcpy(string, stream);
	//removendo leading e trailing space
	char *trimmed = trim(string,len);
	//se string retornada for menor, realloc string e libera espaço do trimmed pra não dar leak
	if (strlen(trimmed) != len)
	{
		string = (char*)realloc(string, strlen(trimmed));
		strcpy(string, trimmed);
		free(trimmed);
	}
	//fim da remoção do leading e trailing space;
	//posicionando start e end no começo e no fim da string para verificar sintaxe

	char *start = string;
	char *end = string + (strlen(string) - 1);

	if (*start != '{' || *end != '}')
	{
		printf("Syntax error. Should open and close with curly braces.");
		return -1;
	}

	//next. check for key:value tokens
	//get_token() --> implement function that returns array of key:value
}

char* trim(char* string, size_t len)
{
	/* 	TRIMMING FUNCTION	
		- Copy string to buffer same size;
		- Trim edges of new buffered string
		- Create new buffer with realloc for trimmed string
		- If trimming worked, return new buffer; else, return same pointer.
	*/
	
	char* new_buffer = malloc(len * sizeof(char));
	strcpy(new_buffer, string);

	char *start = new_buffer,
		 *end = new_buffer + (len-1);

	for (int i = 0; i < len; i++)
	{
		if(isspace(*start))
		{
			start++;
		}
		
		if(isspace(*end))
		{
			end--;
		}
	}
	*(end + 1) = '\0';
	
	if (strlen(new_buffer) != strlen(start))
	{
		new_buffer = realloc(new_buffer, strlen(start));
		strcpy(new_buffer, start);
	}
	return new_buffer;
	
}