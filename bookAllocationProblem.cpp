///used binary search and timecomplexity = nlogn

#include <iostream>

using namespace std;

#define ll long long

bool isValidConfig(ll books[], ll n,ll k, ll mid)
{
    ll total_pages = 0;
    int student = 1;
    for(ll i = 0; i < n; i++)
    {
        if(total_pages + books[i] > mid)
        {
            total_pages = books[i];
            student++;
            if(student > k)
            {
                return false;
            }
        }
        else
        {
            total_pages += books[i];
        }
    }

    return true;
}

ll binarySearchBooks(ll books[], ll n, ll k)
{
    ll total_pages = 0;
    ll low = 0, hi = 0;
    for(int i = 0; i < n; i++)
    {
        total_pages += books[i];
        low = max(low, books[i]);
    }

    hi = total_pages;
    ll finalans = low;
    while(low<=hi)
    {
        ll mid = (low + hi) / 2;

        if(isValidConfig(books,n,k,mid))
        {
            finalans = mid;
            hi = mid-1;
        }

        else
        {
            low = mid + 1;
        }
    }
    return finalans;
}

int main()
{
    ll n;
    ll k;
    cin>>n>>k;
    ll books[100005];
    for(ll i = 0; i < n; i++)
    {
        cin>>books[i];
    }
    cout<<binarySearchBooks(books, n, k);
    return 0;
}

