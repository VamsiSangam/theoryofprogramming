/* ===== ===== =====

Theory of Programming

Jump Search Algorithm
http://theoryofprogramming.com/2016/11/10/jump-search-algorithm/
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - Praveen Mylavarapu (saipraveen.ml)

===== ===== ===== */

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int jumpSearch(int arr[], int n, int value)
{
    int i, right, left, jump = (int) sqrt(n);

    for (i = 0; i + jump < n && arr[i] < value; i += jump) {
        // Keep jumping until value is between any two
        // elements of the array or when i goes out of bound
    }

    if (value <= arr[i]) {
        // right is i if search value is less than
        // any jumped element in the array.
        right = i;
    } else {
        // If not, right is last element
        right = n;
    }

    left = max(right - jump, 0);    // ensuring left doesn't go negative

    // Linear search backwards
    while (right >= left) {
        if (arr[right--] == value) {
            return right + 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(arr) / sizeof(int);

    cout << jumpSearch(arr, n, 0) << endl; // -1
    cout << jumpSearch(arr, n, 3) << endl; // 1
    cout << jumpSearch(arr, n, 11) << endl; // 5
    cout << jumpSearch(arr, n, 16) << endl; // -1

    return 0;
}
