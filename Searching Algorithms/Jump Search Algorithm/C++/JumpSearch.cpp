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

int jumpSearch(int arr[], int n, int value)
{
    int i, right, left, jump = (int) sqrt(n);

    // Keep jumping until value is between any two elements of the array or when i goes out of bound
    for (i = 0; i + jump < n && arr[i] < value; i += jump);

    if (value <= arr[i])    // right is i if search value is less than any jumped element in the array. If not, right is last element
        right = i;
    else
        right = n;

    left = right - jump;

    if (left < 0)   // ensuring left dosen't go negaitive
        left = 0;

    // Linear search backwards
    while (right >= left)
        if (arr[right--] == value)
            return right + 1;

    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15}, n = sizeof(arr)/sizeof(int);

    cout << jumpSearch(arr, n, 0) << endl; // -1
    cout << jumpSearch(arr, n, 3) << endl; // 1
    cout << jumpSearch(arr, n, 11) << endl; // 5
    cout << jumpSearch(arr, n, 16) << endl; // -1

    return 0;
}
