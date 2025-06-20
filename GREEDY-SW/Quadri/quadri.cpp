int quadri(int N, long long M, int V[]) {
    int i = 0, j = 0;
	int min = N, sum = 0;

	while (j <= N)
	{
		if (sum > M)
		{
			sum -= V[i];
			i++;
			if (j - i < min)
			{
				min = j - i;
			}
		}
		else
		{
			sum += V[j];
			j++;
		}
	}
	return min;
}
