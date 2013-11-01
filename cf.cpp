#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;
int x;
int w, h;
long long t;
long long dp[13][1 << 9][1 << 9];
void dfs(int n, int r1, int col, int r2, int r3)
{

	if (col == w)
	{
	
		dp[n + 1][r2][r3] += t;
		return;
	}
	
	if ((r1 >> col & 1) == 0)
	{
		if (col < w - 1 && (r1 >> col + 1 & 1) == 0)
		{
			
			if ((r2 >> col & 1) == 0)
			{
				dfs(n, r1, col + 2, r2 | 1 << col, r3);
			}
			if ((r2 >> col + 1 & 1) == 0)
			{
				
				dfs(n, r1, col + 2, r2 | 1 << col + 1, r3);
			}

			if ((col < w - 2) && (r1 >> col + 2 & 1) == 0)
			{
				dfs(n, r1, col + 3, r2, r3);
			}
		}
		if ((r2 >> col & 1) == 0)
		{
			if (col > 0 && (r2 >> col - 1 & 1) == 0)
			{
				dfs(n, r1, col + 1, r2 | 1 << col | 1 << col - 1, r3);
			}

			if (col < w - 1 && (r2 >> col + 1 & 1) == 0)
			{
				dfs(n, r1, col + 1, r2 | 1 << col | 1 << col + 1, r3);
				
			}
			if ((r3 >> col & 1) == 0)
			{
				dfs(n, r1, col + 1, r2 | 1 << col, r3 | 1 << col);
			}

		}

	}
	else
	{
		dfs(n, r1, col + 1, r2, r3);
	}

}
int main()
{
	/* code */
	
	cin >> h >> w;
	dp[0][0][0] = 1;

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < (1 << w); ++j)
		{
			for (int k = 0; k < (1 << w); ++k)
			{
				if (dp[i][j][k] != 0)
				{
					t = dp[i][j][k];
				
					dfs(i, j, 0, k, 0);
				}
			}
		}
	}
	cout << dp[h][0][0] << endl;
	system("pause");
	
	return 0;
}