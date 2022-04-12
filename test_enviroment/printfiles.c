#include <stdio.h>
#include <dirent.h>
int main (void)
{
	DIR *folder;
	struct dirent *entry;

	folder = opendir("."); /* . to represent present directory*/

	if (folder == NULL)/* if directory is empty print error*/
	{
		printf("Error occured: unable to read directory");
			return (0);
	}
	while ((entry = readdir(folder)) != NULL)/* entry point looking into specified folder*/
		printf("%s\n", entry->d_name); /* d_name containing NULL terminated filename*/
return (0);
}
