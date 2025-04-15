#include <opencv2/opencv.hpp>
#include <iostream>

int getMaxPixelBrightness(const cv::Mat& img) {
    cv::Mat gray;

    // 1. �׷��̽����� ��ȯ
    if (img.channels() == 3) {
        cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    }
    else {
        gray = img;
    }

    // 2. �ּ�/�ִ� ��� ���ϱ�
    double minVal, maxVal;
    cv::minMaxLoc(gray, &minVal, &maxVal);

    return static_cast<int>(maxVal);
}

int main() {
    // �̹��� �ҷ�����
    cv::Mat image = cv::imread("Lenna.png");

    if (image.empty()) {
        std::cerr << "�̹����� �ҷ��� �� �����ϴ�." << std::endl;
        return -1;
    }

    int maxBrightness = getMaxPixelBrightness(image);
    std::cout << "�ִ� ȭ�� ��Ⱚ: " << maxBrightness << std::endl;

    return 0;
}