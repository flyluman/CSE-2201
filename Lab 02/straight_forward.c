#include <stdio.h>

int main()
{
	FILE *in = fopen("input.txt", "r");

	if (!in)
    {
        printf("Error finding input.txt\n");
        return 0;
    }

	int x, comp = 0, min, max, flag = 1;

	fscanf(in, "%d", &x);
	min = max = x;

	while(fscanf(in, "%d", &x) != EOF)
	{
		comp += 2, flag = 0;
		if (x > max) max = x, comp -= 1;
		else if (x < min) min = x;
	}

	if(flag)
	{
		printf("No value found in input.txt\n");
		return 0;
	}

	printf("Min = %d, Max = %d\n\n", min, max);
	printf("Number of comparisons : %d\n", comp);

	fclose(in);
	return 0;
}
