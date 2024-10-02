//hard 
//understand previous DP striver question clearly then come here
//DP matrix dp[n-1][target] will give whether is it possible to make sum == 0 to target
//now u know for each number is that sum available in array, so find your answer

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int total=0;
	for(auto x:arr)
		total+=x;
	
	vector<vector<bool>> dp(n,vector<bool>(total/2+1,false));
	for(int i=0;i<n;i++)
		dp[i][0]=1;
	if(arr[0]<=total/2+1)
		dp[0][arr[0]]=1;

	
	for(int i=1;i<n;i++)
	{
		for(int target=1;target<=total/2+1;target++)
		{
			bool nottake=dp[i-1][target];
			bool take=false;
			if(arr[i]<=target)
			{
				take=dp[i-1][target-arr[i]];
			}

			dp[i][target]=nottake||take;
		}
	}

	int mini=1e9;

	for(int i=0;i<=total/2;i++)
	{
		if(dp[n-1][i]==true)
			mini=min(mini,abs(total-i)-i);
	}
	return mini;
}
	