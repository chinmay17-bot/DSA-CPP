int n = arr.size();
	vector<int> between(n-1 , 0);

	for(int gasstation = 1; gasstation <= k; gasstation++){
		int maxIndex = -1;
		long double maxSection = -1;
		for(int i = 0; i < n-1; i++){
			long double diff =  (arr[i+1] - arr[i]);
			long double sectionlen = diff / (long double)(between[i]+1);

			if(sectionlen > maxSection){
				maxIndex = i;
				maxSection = sectionlen;
			}
		}

		between[maxIndex]++;
	}



	
	long double ans = -1;

	for(int i = 0 ; i < n-1; i++){
		long double diff = (arr[i+1] - arr[i]);
		long double sectionlen = diff / (long double)(between[i] + 1);
		ans = max(ans , sectionlen);

	}