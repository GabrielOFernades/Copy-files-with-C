#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		fprintf(stderr, "Usage: copy SOURCE DESTINATION");
		return 1;
	}
	
	FILE *source = fopen(argv[1], "r");
	
	FILE *destination = fopen(argv[2], "w");
	if(!destination)
	{
		fclose(source);
		printf("Could not create %s.\n", argv[2]);
		return 1;
	}
	
	BYTE buffer;
		
	while(fread(&buffer, sizeof(BYTE), 1, source))
	{
		fwrite(&buffer, sizeof(BYTE), 1, destination);
	}
	
	fclose(source);
	fclose(destination);
	return 0;
}
