class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        if (arr.size() <= 1) return arr; // agar array mein 1 ya 0 element hai toh waise hi return karo

        int idx = -1;
        // right se left jaake pehla index dhoondo jaha arr[i-1] > arr[i] ho
        for (int i = arr.size() - 1; i >= 1; --i) {
            if (arr[i] < arr[i - 1]) {
                idx = i - 1;
                break;
            }
        }

        // agar aisa koi index nahi mila, toh array already increasing order mein hai
        if (idx == -1) return arr;

        // ab right se left jaake pehla element dhoondo jo arr[idx] se chhota ho aur duplicate na ho
        for (int i = arr.size() - 1; i > idx; --i) {
            if (arr[i] < arr[idx] && arr[i] != arr[i - 1]) {
                swap(arr[i], arr[idx]); // values ko swap kar do
                break;
            }
        }

        return arr; // modified array return karo
    }
};

