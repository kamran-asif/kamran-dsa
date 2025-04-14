class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int res = 0;
        int i = 0, j = i + 1, k = j + 1;

        while (i + 2 < n) {
            if (abs(arr[j] - arr[i]) <= a &&
                abs(arr[k] - arr[j]) <= b &&
                abs(arr[k] - arr[i]) <= c) {
                res++;
            }

            if (k < n) {
                k++;
                if (k == n) {
                    j++;
                    k = j + 1;
                    if (j + 1 == n) {
                        i++;
                        j = i + 1;
                        k = j + 1;
                    }
                }
            }
        }
        return res;
    }
};
