#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
ll cas = 1;
#define Case cout<<"Case "<<cas<<": ";cas++;

ll Stoi(string str) {
    ll num = 0;
    ll mul = 1;
    while (!str.empty()) {
        char c = str.back();
        ll x = c - '0';
        str.pop_back();
        x *= mul;
        num += x;
        mul *= 10;
    }
    return num;
}

ll Pill(ll num) {
    string s1, s2;
    s1.clear();
    ll x = num;
    while (x) {
        ll y = x % 10;
        x /= 10;
        char c = y + '0';
        s1.push_back(c);
    }
    s2 = s1;
    reverse(s1.begin(), s1.end());
    s1.pop_back();
    string str = s1 + s2;
    num = Stoi(str);
    return num;
}

ll Pilh(ll num) {
    string s1, s2;
    s1.clear();
    ll x = num;
    while (x) {
        ll y = x % 10;
        x /= 10;
        char c = y + '0';
        s1.push_back(c);
    }
    s2 = s1;
    reverse(s1.begin(), s1.end());
    string str = s1 + s2;
    num = Stoi(str);
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T = 1;
    cin >> T;
    while (T--) {
        
        ll l,r;
        cin>>l>>r;
        ll ans = 0;
        if (l >= r) swap(l, r);
        if (l == 0) ans++;

        ll a = 1, b = r;
        if (b > 1e9) b = 1e9;
        ll lo = a, hi = b + 1;

        ll lol = -1, hil = -1;
        ll mid, x;

        while (lo <= hi) {
            mid = (lo + hi) / 2;
            x = Pill(mid);
            if (x >= l) {
                hi = mid - 1;
                lol = mid;
            } else {
                lo = mid + 1;
            }
        }

        lo = a, hi = b + 1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            x = Pill(mid);
            if (x <= r) {
                lo = mid + 1;
                hil = mid;
            } else {
                hi = mid - 1;
            }
        }

        if (lol != -1 && hil != -1) {
            ans += (hil - lol + 1);
        }

        lo = a, hi = b + 1;
        lol = -1, hil = -1;

        while (lo <= hi) {
            mid = (lo + hi) / 2;
            x = Pilh(mid);
            if (x >= l) {
                hi = mid - 1;
                lol = mid;
            } else {
                lo = mid + 1;
            }
        }

        lo = a, hi = b + 1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            x = Pilh(mid);
            if (x <= r) {
                lo = mid + 1;
                hil = mid;
            } else {
                hi = mid - 1;
            }
        }

        if (lol != -1 && hil != -1) {
            ans += (hil - lol + 1);
        }
        Case;
        cout << ans << endl;
    }
    return 0;
}
