#include <iostream>
#define int long long int
using namespace std;
int cnt = 0;
int l, r;
int solve(int n){

    if(n == 1 || n==0){
        ///cnt work as indexing
        cnt++;
        if(cnt >= l && cnt <= r){
			///increment answer by n = 1 || 0
            return n;
        }
        ///if cnt is not within range of l and r
        else{
            return 0;
        }
    }
    return solve(n/2)+solve(n%2)+solve(n/2);
}

int32_t main(){

    int n;
    cin>>n>>l>>r;
    if(l > r){
        swap(l, r);
    }
    cout<<solve(n)<<endl;
    return 0;
}

