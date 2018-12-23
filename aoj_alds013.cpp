#include<iostream>
using namespace std;
int main(){
        int n,q,r=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        cin>>q;
        int b[q];
        for(int i=0;i<q;i++) cin>>b[i];
        for(int i=0;i<q;i++) {
                int low=0,hi=n-1,mid;
                while(low<hi){
                        mid = (low+hi)/2;
                        if(a[mid]<b[i]) low = mid+1;
                        else hi =mid;
                }
                if(a[low]==b[i]) r++;
        }
        cout<<r<<endl;
        return 0;
}

