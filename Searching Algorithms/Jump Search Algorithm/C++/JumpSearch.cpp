/* ===== ===== =====

Theory of Programming

Jump Search Algorithm
http://theoryofprogramming.com/2016/11/10/jump-search-algorithm/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Praveen Mylavarapu (saipraveen.ml)

===== ===== ===== */

#include <iostream>
#include <math.h>

using namespace std;

bool jumpSearch(int a[100], int n, int value)
{
    int i, right = n, jump = (int) sqrt(n);

    for (i = 0; i + jump < n && a[i] < value; i += jump);

    if (a[i] >= value)
        right = i;

    while (right >= i - jump)
        if (a[right--] == value)
            return 0;

    return 1;
}

int main()
{
    int a[100], i = 0, n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements of search space: ";

    while (i < n)
        cin >> a[i++];

    cout << "Enter the value to be searched: ";
    cin >> value;

    if (jumpSearch(a, n, value))
        cout << "Not ";
    cout << "Found!" << endl;

    return 0;
}
