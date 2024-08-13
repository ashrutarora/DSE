#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main()
{
    // Open the current directory
    DIR *dir = opendir(".");

    if (dir == NULL)
    {
        perror("Unable to open directory");
        exit(1);
    }

    // Read directory entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    // Close the directory
    closedir(dir);

    return 0;
}
