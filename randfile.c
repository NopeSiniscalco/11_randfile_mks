#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

int *randomize10()
{
	int *buffer = malloc(sizeof(int) * 10);
	int file_loc = open("/dev/random", O_RDONLY);
	if (file_loc == -1)
	{
		printf("Error opening file\n");
	}
	for (int i = 0; i < 10; i++)
	{
		read(file_loc, buffer + i, sizeof(int));
	}
	close(file_loc);
	return buffer;
}

int main()
{
	int *p;
	p = randomize10();
	//printf("Address:%p\n",p);
	for (int i = 0; i < 10; i++)
	{
		printf("Random number %d; %d\n", i, p[i]);
	}

	printf("\nWriting and Reading:\n");
    int temp_loc = open("./temp.txt", O_RDWR);
    write(temp_loc, p, sizeof(p));
    int * p2=malloc(sizeof(int)*10);
    read(temp_loc, p2, sizeof(p2));
    for (int i = 0; i < 10; i++)
    {
        printf("Random number %d; %d\n", i, p[i]);
    }
    close(temp_loc);
	free(p);
	free(p2);
}