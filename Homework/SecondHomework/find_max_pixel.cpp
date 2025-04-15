#include <opencv2/opencv.hpp>
#include <iostream>

int getMaxPixelBrightness(const cv::Mat& img) {
    cv::Mat gray;

    // 1. 그레이스케일 변환
    if (img.channels() == 3) {
        cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    }
    else {
        gray = img;
    }

    // 2. 최소/최대 밝기 구하기
    double minVal, maxVal;
    cv::minMaxLoc(gray, &minVal, &maxVal);

    return static_cast<int>(maxVal);
}

int main() {
    // 이미지 불러오기
    cv::Mat image = cv::imread("Lenna.png");

    if (image.empty()) {
        std::cerr << "이미지를 불러올 수 없습니다." << std::endl;
        return -1;
    }

    int maxBrightness = getMaxPixelBrightness(image);
    std::cout << "최대 화소 밝기값: " << maxBrightness << std::endl;

    return 0;
}