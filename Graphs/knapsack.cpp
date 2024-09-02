#include <bits/stdc++.h>
using namespace std;

struct Item
{
	int profit, weight;

	Item(int profit, int weight)
	{
		this->profit = profit;
		this->weight = weight;
	}
};

static bool cmp(struct Item a, struct Item b)
{
	int r1 = (int)a.profit / (int)a.weight;
	int r2 = (int)b.profit / (int)b.weight;
	return r1 > r2;
}

// Main greedy function to solve problem
int fractionalKnapsack(int W, struct Item arr[], int N)
{

	sort(arr, arr + N, cmp);

	int finalvalue = 0;

	for (int i = 0; i < N; i++)
	{

		if (arr[i].weight <= W)
		{
			W -= arr[i].weight;
			finalvalue += arr[i].profit;
		}

		else
		{
			finalvalue += arr[i].profit * ((double)W / (double)arr[i].weight);
			break;
		}
	}
	return finalvalue;
}

// Driver code
int main()
{
	int W = 50;
	Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << fractionalKnapsack(W, arr, N);
	return 0;
}
