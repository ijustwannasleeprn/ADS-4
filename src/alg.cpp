// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int size, int targetSum) {
    int pairCount = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == targetSum) {
                pairCount++;
            }
        }
    }
    return pairCount;
}

int countPairs2(int *arr, int size, int targetSum) {
    int pairCount = 0;
    int highBound = size - 1;
    while (highBound > 0 && arr[highBound] > targetSum) {
        highBound--;
    }
    for (int lowBound = 0; lowBound < highBound; lowBound++) {
        int currentValue = arr[lowBound];
        int requiredValue = targetSum - currentValue;
        int left = lowBound + 1;
        int right = highBound;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == requiredValue) {
                pairCount++;
                int temp = mid - 1;
                while (temp >= left && arr[temp] == requiredValue) {
                    pairCount++;
                    temp--;
                }
                temp = mid + 1;
                while (temp <= right && arr[temp] == requiredValue) {
                    pairCount++;
                    temp++;
                }
                break;
            } else if (arr[mid] < requiredValue) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return pairCount;
}

int findMatches(int *arr, int start, int end, int target) {
    int firstOccurrence = -1;
    int left = start;
    int right = end;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target) {
            if (arr[mid] == target) firstOccurrence = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (firstOccurrence == -1) return 0;
    int lastOccurrence = firstOccurrence;
    left = firstOccurrence;
    right = end;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            if (arr[mid] == target) lastOccurrence = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return lastOccurrence - firstOccurrence + 1;
}

int countPairs3(int *arr, int size, int targetSum) {
    int pairCount = 0;
    for (int i = 0; i < size; i++) {
        int complement = targetSum - arr[i];
        if (complement < 0) continue;
        pairCount += findMatches(arr, i + 1, size - 1, complement);
    }
    return pairCount;
}
