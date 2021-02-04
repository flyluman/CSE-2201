#include <stdio.h>
#include <limits.h>

int main()
{
	FILE *in = fopen("input.txt", "r");

	int x, comp = 0, min = INT_MAX, max = INT_MIN;

	while(fscanf(in, "%d", &x) != EOF)
	{
		comp += 2; // 2 if() checksum
		if (x < min) min = x;
		if (x > max) max = x;
	}

	printf("Min = %d, Max = %d\n\n", min, max);
	printf("Number of comparisons : %d\n", comp);

	fclose(in);
	return 0;
}
