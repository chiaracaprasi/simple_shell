#include <stdio.h>
#include <dirent.h>
int main (void)
{
	DIR *folder;
	struct dirent *entry;

	folder = opendir(".");

	if (folder == NULL)
	{
		printf("Error has occured, unable to read directory");
	}
	while ((entry = readdir(folder)) != NULL)
		printf("%s\n", entry->d_name);

	closedir(folder);
	return(0);
}
