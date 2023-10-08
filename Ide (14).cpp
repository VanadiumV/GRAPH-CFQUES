#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> v[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, e;
    cin >> n >> e;

    ll x, y;
    for (int i = 0; i < e; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    // After calculating degree, we need to find the number of times the degree is still one for all nodes.
    ll cnt = 0;
    while (true) {
        ll flag = 0;
        vector<ll> d;
        
        for (ll i = 1; i <= n; i++) {
            if (v[i].size() == 1) {
                flag = 1;
                d.push_back(i);
                v[i].clear(); // Use v[i].clear() instead of v[i].clear;
            }
        }
        
        if (flag == 0)
            break;
        
        for (ll i = 0; i < d.size(); i++) {
            ll node = d[i];
            for (ll j = 1; j <= n; j++) {
                for (ll k = 0; k < v[j].size(); k++) {
                    if (v[j][k] == node) {
                        v[j].erase(v[j].begin() + k);
                        break; // Add break here to exit the loop once the node is found.
                    }
                }
            }
        }
        ++cnt;
    }
    cout << cnt << "\n";
    return 0;
}
