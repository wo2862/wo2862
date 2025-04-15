#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double coef; // 계수 (실수형)
    int exp;     // 차수
} Term;

typedef struct {
    Term* terms;
    int size;
    int capacity;
} Vector;

void initVector(Vector* v) {
    v->capacity = 4;
    v->size = 0;
    v->terms = (Term*)malloc(sizeof(Term) * v->capacity);
}

void pushBack(Vector* v, double coef, int exp) {
    if (coef == 0.0) return;

    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->terms = (Term*)realloc(v->terms, sizeof(Term) * v->capacity);
    }
    v->terms[v->size].coef = coef;
    v->terms[v->size].exp = exp;
    v->size++;
}

void freeVector(Vector* v) {
    free(v->terms);
}

int compare(const void* a, const void* b) {
    Term* t1 = (Term*)a;
    Term* t2 = (Term*)b;
    return t2->exp - t1->exp;
}

void inputPolynomial(Vector* poly, char name) {
    int n;
    printf("항의 개수를 입력하세요 : ");
    scanf_s("%d", &n);

    for (int i = 0; i < n; i++) {
        double coef;
        int exp;
        printf("%d번째 항의 계수와 차수를 입력하세요 (예 : 계수 차수) : ", i + 1);
        scanf_s("%lf %d", &coef, &exp);
        pushBack(poly, coef, exp);
    }

    qsort(poly->terms, poly->size, sizeof(Term), compare);

    printf("Poly %c : ", name);
    for (int i = 0; i < poly->size; i++) {
        if (i > 0) printf(" + ");
        printf("%.1fx^%d", poly->terms[i].coef, poly->terms[i].exp);
    }
    printf("\n");
}

void addPolynomials(Vector* result, Vector* A, Vector* B) {
    int i = 0, j = 0;
    while (i < A->size && j < B->size) {
        if (A->terms[i].exp > B->terms[j].exp) {
            pushBack(result, A->terms[i].coef, A->terms[i].exp);
            i++;
        }
        else if (A->terms[i].exp < B->terms[j].exp) {
            pushBack(result, B->terms[j].coef, B->terms[j].exp);
            j++;
        }
        else {
            double sum = A->terms[i].coef + B->terms[j].coef;
            pushBack(result, sum, A->terms[i].exp);
            i++; j++;
        }
    }

    while (i < A->size) {
        pushBack(result, A->terms[i].coef, A->terms[i].exp);
        i++;
    }
    while (j < B->size) {
        pushBack(result, B->terms[j].coef, B->terms[j].exp);
        j++;
    }

    qsort(result->terms, result->size, sizeof(Term), compare);

    printf("Poly C : ");
    for (int i = 0; i < result->size; i++) {
        if (i > 0) printf(" + ");
        printf("%.1fx^%d", result->terms[i].coef, result->terms[i].exp);
    }
    printf("\n");
}

int main() {
    Vector A, B, C;
    initVector(&A);
    initVector(&B);
    initVector(&C);

    inputPolynomial(&A, 'A');
    inputPolynomial(&B, 'B');
    addPolynomials(&C, &A, &B);

    freeVector(&A);
    freeVector(&B);
    freeVector(&C);
    return 0;
}