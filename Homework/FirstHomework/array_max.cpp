#include <stdio.h>

int findMax(int arr[], int size) {
    int max = arr[0];  // ù ��° ��Ҹ� �ִ����� �ʱ�ȭ

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];  // �� ū ���� ������ �ִ��� ����
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

    // �� �迭�� ũ�� ���
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    int size5 = sizeof(arr5) / sizeof(arr5[0]);

    // �� �迭���� �ִ��� ���ϰ� ���
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