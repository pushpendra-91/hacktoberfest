#include <bits/stdc++.h>
using namespace std;

//matrix dimension
const int z = 1000; 
//declaring DP matrix
int t[z][z]; 

int Knapsack(int wt[], int val[], int W, int n) {
    // Base Condition
    // (1) if capacity of the bag will be 0, then there can be no profit(no items can come in bag) OR
    // (2) if there will be no items present, what will we keep in our bag? Therefore profit will be zero
	if (n == 0 || W == 0)
		return 0;

	// if already calculated
	if (t[n][W] != -1)
		return t[n][W];
	// else calculate
	else {
        // if the weight of that item is less than or equal to the max capacity of our bag, then we can 
        // (1). nth item included
        // (2). not included
		if (wt[n - 1] <= W)
			t[n][W] = max(val[n - 1] + Knapsack(wt, val, W - wt[n - 1], n - 1),
			              Knapsack(wt, val, W, n - 1));

        // if the weight of that particular item is greater than the max capacity of our bag, then we can't put that item in our bag 
        // so, n-1 items remaining now
		else if (wt[n - 1] > W)
			t[n][W] = Knapsack(wt, val, W, n - 1);

		return t[n][W];
	}
}

signed main() {
	int n; cin >> n; 
	int val[n], wt[n]; 
	for (int i = 0; i < n; i++)
    {
		cin >> wt[i];
    }
	for (int i = 0; i < n; i++)
    {
		cin >> val[i];
    }

	int W; cin >> W; 


	for (int i = 0; i <= n; i++)
    {
		for (int j = 0; j <= W; j++)
        {
			t[i][j] = -1;
        }
    }

	cout << Knapsack(wt, val, W, n) << endl;
	return 0;
}