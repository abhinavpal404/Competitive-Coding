const int SZ = 2;
int base[SZ];
int dp[SZ];
int add(ll a, ll b)
{
	ll res = a + b;
	if(res >= M)
		return res - M;
	return res;
}

ll mult(ll a, ll b)
{
	long long res = a;
	res *= b;
	if(res >= M)
		return res % M;
	return res;
}

struct matrix
{
	ll arr[SZ][SZ];

	void reset()
	{
		memset(arr, 0, sizeof(arr));
	}

	void makeiden()
	{
		reset();
		for(int i=0;i<SZ;i++)
		{
			arr[i][i] = 1;
		}
	}

	matrix operator + (const matrix &o) const 
	{
		matrix res;
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				res.arr[i][j] = add(arr[i][j], o.arr[i][j]);
			}
		}
		return res;
	}

	matrix operator * (const matrix &o) const 
	{
		matrix res;
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				res.arr[i][j] = 0;
				for(int k=0;k<SZ;k++)
				{
					res.arr[i][j] = add(res.arr[i][j] , mult(arr[i][k] , o.arr[k][j]));
				}
			}
		}
		return res;
	}
};

matrix power(matrix a, ll b)
{
	matrix res;
	res.makeiden();
	while(b)
	{
		if(b & 1)
		{
			res = res * a;
		}
		a = a * a;
		b >>= 1;
	}
	return res;
}


//For multiplying the matrix at the end..dp[i] is final matrix while base matrix contains base cases 
    for(int i = 0 ; i < SZ ; i++)
    {
        dp[i] = 0;
        for(int j = 0 ; j < SZ ; j++)
        {
            //cout<<expo.a[i][j]<<" "; 
            dp[i] = add(dp[i] , mult(expo.a[i][j],base[j]));
        }
    }
//Matrix Exponentiation:
//Sample Problem 1: http://codeforces.com/contest/954/problem/F
//Sample Solution 1: http://codeforces.com/contest/954/submission/39865763

//Sample Problem 2: http://codeforces.com/contest/821/problem/E
//Sample Solution 2: http://codeforces.com/contest/821/submission/39865878

//Sample Problem 3 (Only Matrix Expo): https://codeforces.com/contest/551/problem/D
//Sample Solution 3: https://codeforces.com/contest/551/submission/48459284

//Sample Problem 4: https://www.codechef.com/ENFE2019/problems/CHWLD
//Sample Solution 4: https://www.codechef.com/viewsolution/23218422
