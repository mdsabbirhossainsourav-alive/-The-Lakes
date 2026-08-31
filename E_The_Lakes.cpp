#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        int tl = n*m;
        vector<int> a(tl);
        for(int i=0; i<tl; i++) 
        {
            cin >> a[i];
        }
        long long ans = 0;
        vector<int> st;
        st.reserve(tl);
        for(int i=0; i<tl; i++) 
        {
            if(a[i] == 0)
            {
                continue;
            }
            long long sum = 0;
            st.clear();
            sum += a[i],a[i] = 0;
            st.push_back(i);
            while(!st.empty()) 
            {
                int v = st.back();
                st.pop_back();
                int col = v%m;
                if(v>=m && a[v-m]>0) 
                {
                    sum += a[v-m],a[v-m]=0;
                    st.push_back(v-m);
                }
                if(v<tl-m && a[v+m]>0) 
                {
                    sum += a[v+m],a[v+m]=0;
                    st.push_back(v+m);
                }
                if(col>0 && a[v-1]>0) 
                {
                    sum += a[v-1],a[v-1]=0;
                    st.push_back(v-1);
                }
                if(col<m-1 && a[v+1]>0)
                {
                    sum += a[v+1],a[v+1]=0;
                    st.push_back(v+1);
                }
            }
            ans = max(ans,sum);
        }
        cout << ans << endl;
    }
    return 0;
}