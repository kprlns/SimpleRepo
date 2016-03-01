int max_sum_on_sub(vector<int>& b){
	int maxsum=0, cursum=0;
    for (int i = 0; i < b.size(); ++i) {
            cursum+=b[i];
            if(cursum>maxsum){
                maxsum=cursum;
            }else if(cursum<0){
                cursum=0;
            }
    }
	return maxsum;
}
