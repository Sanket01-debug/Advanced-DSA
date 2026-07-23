#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> t(n);
    for(int i=0; i<n; i++){
        cin >> t[i];
    }

    int n1 = n/2;
    int n2 = n - n1;

    vector<long long> sumsA(1LL << n1); //Size is 2^n1
    for(int mask = 0; mask < (1 << n1); mask++){
        long long s = 0;
        for(int i=0; i<n1; i++){
            if(mask & (1<<i)){
                s += t[i];
            }
        }
        sumsA[mask] = s;
    }

    vector<long long> sumsB(1LL << n2); //Size is 2^n2
    for(int mask = 0; mask < (1 << n2); mask++){
        long long s = 0;
        for(int i=0; i<n2; i++){
            if(mask & (1<<i)){
                s += t[n1+i];
            }
        }
        sumsB[mask] = s;
    }
    sort(begin(sumsB), end(sumsB));

    long long count = 0;
    for(long long s: sumsA){
        long long need = x - s; // remaining sum
        auto lo = lower_bound(sumsB.begin(), sumsB.end(), need);
        auto hi = upper_bound(sumsB.begin(), sumsB.end(), need);
        count += (hi-lo);
    }

    cout << count << endl;
    return 0;

}