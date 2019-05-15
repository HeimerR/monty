#include "monty.h"
/**
* clean_line - delete spaces
* @content: line to clean
* Return: line cleaned.
*/
char  *clean_line(char *content)
{
	char line[10];
	int i = 1, j = 0;

	if (content[0] == '\n')
	{
		return (content);
	}
	while (content[i] != '\n')
	{
		if(content[i] != ' ' && content[i - 1] 
		{
			line[j++] = content[i];
		}
	}
return (content);
}
