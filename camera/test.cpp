/*
* Reference:
* https://blog.csdn.net/qq_36662437/article/details/97628996
* https://www.cnblogs.com/ybqjymy/p/12510042.html
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture capture(1);

	capture.set(CV_CAP_PROP_FRAME_WIDTH, 1920); // 宽度
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, 1080); // 高度

	/*
	// 设置摄像头参数
	capture.set(CV_CAP_PROP_FRAME_WIDTH, 640); // 宽度
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, 480); // 高度
	capture.set(CV_CAP_PROP_FPS, 30); // 帧数
	capture.set(CV_CAP_PROP_BRIGHTNESS, 1); // 亮度 1
	capture.set(CV_CAP_PROP_CONTRAST, 40); // 对比度 40
	capture.set(CV_CAP_PROP_SATURATION, 50); // 饱和度 50
	capture.set(CV_CAP_PROP_HUE, 50); // 色调 50
	capture.set(CV_CAP_PROP_EXPOSURE, 50); // 曝光 50
	*/
	// 打印摄像头参数
	printf("width = %.2f\n", capture.get(CV_CAP_PROP_FRAME_WIDTH));
	printf("height = %.2f\n", capture.get(CV_CAP_PROP_FRAME_HEIGHT));
	printf("fbs = %.2f\n", capture.get(CV_CAP_PROP_FPS));
	printf("brightness = %.2f\n", capture.get(CV_CAP_PROP_BRIGHTNESS));
	printf("contrast = %.2f\n", capture.get(CV_CAP_PROP_CONTRAST));
	printf("saturation = %.2f\n", capture.get(CV_CAP_PROP_SATURATION));
	printf("hue = %.2f\n", capture.get(CV_CAP_PROP_HUE));
	printf("exposure = %.2f\n", capture.get(CV_CAP_PROP_EXPOSURE));

	if (!capture.isOpened()) return -1;
	Mat frame;
	if (!capture.read(frame)) return -1;
	imshow("Video", frame);

	// string str("pic_1.jpg");
	// string str("pic_2.jpg");
	// string str("pic_3.jpg");
	// string str("pic_4.jpg");
	// string str("pic_5.jpg");
	string str("pic_6.jpg");
	cout << str << endl;
	imwrite(str, frame);

	return 0;
}
