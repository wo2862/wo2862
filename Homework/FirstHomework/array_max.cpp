#include <stdio.h>

int findMax(int arr[], int size) {
    int max = arr[0];  // 첫 번째 요소를 최댓값으로 초기화

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];  // 더 큰 값이 있으면 최댓값을 갱신
        }
    }
    return max;
}

int main() {
    int arr1[] = { 3, 7, 2, 9, 10, 5 };
    int arr2[] = { -10, -5, -3 };
    int arr3[] = { 100, 200, 300, 50, 400 };
    int arr4[] = { 0,0,-2,0 };
    int arr5[] = { 10000 };

    // 각 배열의 크기 계산
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    int size5 = sizeof(arr5) / sizeof(arr5[0]);

    // 각 배열에서 최댓값을 구하고 출력
    int max1 = findMax(arr1, size1);
    int max2 = findMax(arr2, size2);
    int max3 = findMax(arr3, size3);
    int max4 = findMax(arr4, size4);
    int max5 = findMax(arr5, size5);

    printf("%d\n", max1);
    printf("%d\n", max2);
    printf("%d\n", max3);
    printf("%d\n", max4);
    printf("%d\n", max5);

    return 0;
}