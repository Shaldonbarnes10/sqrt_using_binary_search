#include<iostream>
using namespace std;
int integerpart(int n){
    int l=0,ans;
    int h=n/2;
    while (l<=h){
        long long int mid = l+(h-l)/2;
        long long int sqr = mid * mid;
        if (sqr == n){
            return mid;
        }else if (sqr > n){
            h=mid-1;
        }else{
            ans = mid;
            l=mid+1;
        }
    }
    return ans;
}
double decimalpart(int n) {
    double ans = integerpart(n);
    double increment = 0.1;

    for (int i = 0; i < 3; i++) {  // Precision of 2 decimal places
        while ((ans + increment) * (ans + increment) <= n) {
            ans += increment;
        }
        increment /= 10;  // Reduce increment for finer precision
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number whost sqrt is to be determined : ";
    cin>>n;
    double answer = decimalpart(n);
    cout << answer;
}