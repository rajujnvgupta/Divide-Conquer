#include <iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

int partition(int *in, int low, int hi)
{
    int i = low - 1;
    int pivot = in[hi];

    for(int j = low; j <= hi; j++)
    {
        if(in[j] < pivot)
        {
            i++;
            swap(in[i], in[j]);
        }
    }
    swap(in[i+1], in[hi]);

    return i + 1;  ///returning pivot element
}

void Quick(int *in, int low, int hi)
{

    if(low >= hi)
        return;

    int p = partition(in , low, hi);
    Quick(in, low, p - 1);
    Quick(in, p + 1, hi);
}

void randomSuffle(int *in, int low, int hi)
{
    for(int i = hi; i > 0; i--)
    {
        int j = rand() % i + 1;
        swap(in[i], in[j]);
    }
}

int main()
{
    int in[6] = {1,2,3,4,5,6};
    int low = 0, hi = 5;

    srand(time(NULL));
    randomSuffle(in, low, hi);

    for(int i = 0; i < 6; i++)
    {
        cout<<in[i]<<" ";
    }

    cout<<endl;

    Quick(in, low, hi);

    for(int i = 0; i < 6; i++)
    {
        cout<<in[i]<<" ";
    }

    return 0;
}
