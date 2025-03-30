// Copyright 2021 NNTU-CS
#include <algorithm>

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
                while (j + 1 < len && arr[j] == arr[j + 1]) {
                    j++;
                }
            }
        }
        while (i + 1 < len && arr[i] == arr[i + 1]) {
            i++;
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }
            
            int left_val = arr[left];
            int right_val = arr[right];
            int left_count = 1;
            int right_count = 1;
            
            while (left + 1 < len && arr[left] == arr[left + 1]) {
                left++;
                left_count++;
            }
            
            while (right - 1 >= 0 && arr[right] == arr[right - 1]) {
                right--;
                right_count++;
            }
            
            count += left_count * right_count;
            left++;
            right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int binarySearchCount(int *arr, int left, int right, int value) {
    int count = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            count = 1;
            int l = mid - 1;
            while (l >= left && arr[l] == value) {
                count++;
                l--;
            }
            int r = mid + 1;
            while (r <= right && arr[r] == value) {
                count++;
                r++;
            }
            return count;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int target = value - arr[i];
        if (target < arr[i]) {
            break;
        }
        
        int cnt = binarySearchCount(arr, i + 1, len - 1, target);
        count += cnt;
        
        while (i + 1 < len && arr[i] == arr[i + 1]) {
            i++;
        }
    }
    return count;
}
