// Problem 1: Cyclic Substring Maximum Sum

#include <stdio.h>
#include <string.h>

int maxCyclicSubstringSum(char *s) {
    int n = strlen(s);

    // doubled string for cyclic behavior
    char doubled[2 * n + 1];
    strcpy(doubled, s);
    strcat(doubled, s);

    int freq[26] = {0};
    int left = 0, sum = 0, maxSum = 0;

    for (int right = 0; right < 2 * n; right++) {
        int val = doubled[right] - 'a';
        sum += (val + 1);
        freq[val]++;

        // maintain unique chars + window size ≤ n
        while (freq[val] > 1 || (right - left + 1) > n) {
            int leftVal = doubled[left] - 'a';
            sum -= (leftVal + 1);
            freq[leftVal]--;
            left++;
        }

        if (sum > maxSum) {
            maxSum = sum;
        }
    }

    return maxSum;
}

int main() {
    char s[100005];
    scanf("%s", s);

    int result = maxCyclicSubstringSum(s);
    printf("%d\n", result);

    return 0;
}