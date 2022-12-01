#pragma once
#include<iostream>
#include <fstream>
#include<string>
#include<ctime>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#define MAX_SIZE 4096   //帧数
#define POINT_NUM 2300
#define TOTAL_NUM MAX_SIZE*POINT_NUM   //每个文件的点云数量

using namespace cv;

int main() {
	//定义colorbar
	uint8_t selfcolor[256][3];
	for (int i = 0; i < 256; ++i) {
		if (i == 0) {
			selfcolor[i][0] = 0;
			selfcolor[i][1] = 0;
			selfcolor[i][2] = 0;
		}
		else if (i < 4) {
			selfcolor[i][0] = 33;
			selfcolor[i][1] = 67;
			selfcolor[i][2] = 95;
		}
		else if (i < 8) {
			selfcolor[i][0] = 36;
			selfcolor[i][1] = 69;
			selfcolor[i][2] = 96;
		}
		else if (i < 12) {
			selfcolor[i][0] = 40;
			selfcolor[i][1] = 72;
			selfcolor[i][2] = 99;
		}
		else if (i < 16) {
			selfcolor[i][0] = 44;
			selfcolor[i][1] = 74;
			selfcolor[i][2] = 101;
		}
		else if (i < 20) {
			selfcolor[i][0] = 49;
			selfcolor[i][1] = 77;
			selfcolor[i][2] = 103;
		}
		else if (i < 24) {
			selfcolor[i][0] = 54;
			selfcolor[i][1] = 81;
			selfcolor[i][2] = 106;
		}
		else if (i < 28) {
			selfcolor[i][0] = 59;
			selfcolor[i][1] = 84;
			selfcolor[i][2] = 108;
		}
		else if (i < 32) {
			selfcolor[i][0] = 64;
			selfcolor[i][1] = 87;
			selfcolor[i][2] = 111;
		}
		else if (i < 36) {
			selfcolor[i][0] = 68;
			selfcolor[i][1] = 90;
			selfcolor[i][2] = 114;
		}
		else if (i < 40) {
			selfcolor[i][0] = 74;
			selfcolor[i][1] = 94;
			selfcolor[i][2] = 117;
		}
		else if (i < 44) {
			selfcolor[i][0] = 80;
			selfcolor[i][1] = 97;
			selfcolor[i][2] = 120;
		}
		else if (i < 48) {
			selfcolor[i][0] = 87;
			selfcolor[i][1] = 102;
			selfcolor[i][2] = 123;
		}
		else if (i < 52) {
			selfcolor[i][0] = 93;
			selfcolor[i][1] = 106;
			selfcolor[i][2] = 126;
		}
		else if (i < 56) {
			selfcolor[i][0] = 100;
			selfcolor[i][1] = 110;
			selfcolor[i][2] = 130;
		}
		else if (i < 60) {
			selfcolor[i][0] = 108;
			selfcolor[i][1] = 116;
			selfcolor[i][2] = 134;
		}
		else if (i < 64) {
			selfcolor[i][0] = 115;
			selfcolor[i][1] = 120;
			selfcolor[i][2] = 138;
		}
		else if (i < 68) {
			selfcolor[i][0] = 125;
			selfcolor[i][1] = 127;
			selfcolor[i][2] = 143;
		}
		else if (i < 72) {
			selfcolor[i][0] = 134;
			selfcolor[i][1] = 132;
			selfcolor[i][2] = 148;
		}
		else if (i < 76) {
			selfcolor[i][0] = 145;
			selfcolor[i][1] = 139;
			selfcolor[i][2] = 154;
		}
		else if (i < 80) {
			selfcolor[i][0] = 157;
			selfcolor[i][1] = 147;
			selfcolor[i][2] = 160;
		}
		else if (i < 84) {
			selfcolor[i][0] = 169;
			selfcolor[i][1] = 155;
			selfcolor[i][2] = 167;
		}
		else if (i < 88) {
			selfcolor[i][0] = 183;
			selfcolor[i][1] = 164;
			selfcolor[i][2] = 174;
		}
		else if (i < 92) {
			selfcolor[i][0] = 201;
			selfcolor[i][1] = 175;
			selfcolor[i][2] = 183;
		}
		else if (i < 96) {
			selfcolor[i][0] = 215;
			selfcolor[i][1] = 186;
			selfcolor[i][2] = 191;
		}
		else if (i < 100) {
			selfcolor[i][0] = 218;
			selfcolor[i][1] = 192;
			selfcolor[i][2] = 194;
		}
		else if (i < 104) {
			selfcolor[i][0] = 223;
			selfcolor[i][1] = 199;
			selfcolor[i][2] = 198;
		}
		else if (i < 108) {
			selfcolor[i][0] = 229;
			selfcolor[i][1] = 210;
			selfcolor[i][2] = 203;
		}
		else if (i < 113) {
			selfcolor[i][0] = 106;
			selfcolor[i][1] = 136;
			selfcolor[i][2] = 110;
		}
		else if (i < 116) {
			selfcolor[i][0] = 137;
			selfcolor[i][1] = 227;
			selfcolor[i][2] = 216;
		}
		else if (i < 120) {
			selfcolor[i][0] = 111;
			selfcolor[i][1] = 224;
			selfcolor[i][2] = 236;
		}
		else if (i < 124) {
			selfcolor[i][0] = 96;
			selfcolor[i][1] = 222;
			selfcolor[i][2] = 248;
		}
		else if (i < 128) {
			selfcolor[i][0] = 95;
			selfcolor[i][1] = 211;
			selfcolor[i][2] = 248;
		}
		else if (i < 132) {
			selfcolor[i][0] = 98;
			selfcolor[i][1] = 199;
			selfcolor[i][2] = 244;
		}
		else if (i < 136) {
			selfcolor[i][0] = 101;
			selfcolor[i][1] = 189;
			selfcolor[i][2] = 241;
		}
		else if (i < 140) {
			selfcolor[i][0] = 103;
			selfcolor[i][1] = 180;
			selfcolor[i][2] = 238;
		}
		else if (i < 144) {
			selfcolor[i][0] = 105;
			selfcolor[i][1] = 173;
			selfcolor[i][2] = 236;
		}
		else if (i < 148) {
			selfcolor[i][0] = 106;
			selfcolor[i][1] = 167;
			selfcolor[i][2] = 234;
		}
		else if (i < 152) {
			selfcolor[i][0] = 108;
			selfcolor[i][1] = 161;
			selfcolor[i][2] = 232;
		}
		else if (i < 156) {
			selfcolor[i][0] = 109;
			selfcolor[i][1] = 155;
			selfcolor[i][2] = 231;
		}
		else if (i < 160) {
			selfcolor[i][0] = 107;
			selfcolor[i][1] = 151;
			selfcolor[i][2] = 229;
		}
		else if (i < 164) {
			selfcolor[i][0] = 105;
			selfcolor[i][1] = 147;
			selfcolor[i][2] = 227;
		}
		else if (i < 168) {
			selfcolor[i][0] = 103;
			selfcolor[i][1] = 143;
			selfcolor[i][2] = 226;
		}
		else if (i < 172) {
			selfcolor[i][0] = 101;
			selfcolor[i][1] = 139;
			selfcolor[i][2] = 225;
		}
		else if (i < 176) {
			selfcolor[i][0] = 99;
			selfcolor[i][1] = 136;
			selfcolor[i][2] = 223;
		}
		else if (i < 180) {
			selfcolor[i][0] = 98;
			selfcolor[i][1] = 133;
			selfcolor[i][2] = 222;
		}
		else if (i < 184) {
			selfcolor[i][0] = 97;
			selfcolor[i][1] = 130;
			selfcolor[i][2] = 221;
		}
		else if (i < 188) {
			selfcolor[i][0] = 95;
			selfcolor[i][1] = 127;
			selfcolor[i][2] = 220;
		}
		else if (i < 192) {
			selfcolor[i][0] = 94;
			selfcolor[i][1] = 124;
			selfcolor[i][2] = 219;
		}
		else if (i < 196) {
			selfcolor[i][0] = 93;
			selfcolor[i][1] = 122;
			selfcolor[i][2] = 218;
		}
		else if (i < 200) {
			selfcolor[i][0] = 92;
			selfcolor[i][1] = 120;
			selfcolor[i][2] = 217;
		}
		else if (i < 204) {
			selfcolor[i][0] = 91;
			selfcolor[i][1] = 117;
			selfcolor[i][2] = 216;
		}
		else if (i < 208) {
			selfcolor[i][0] = 90;
			selfcolor[i][1] = 114;
			selfcolor[i][2] = 215;
		}
		else if (i < 212) {
			selfcolor[i][0] = 89;
			selfcolor[i][1] = 113;
			selfcolor[i][2] = 214;
		}
		else if (i < 216) {
			selfcolor[i][0] = 88;
			selfcolor[i][1] = 111;
			selfcolor[i][2] = 213;
		}
		else if (i < 220) {
			selfcolor[i][0] = 87;
			selfcolor[i][1] = 109;
			selfcolor[i][2] = 213;
		}
		else if (i < 224) {
			selfcolor[i][0] = 86;
			selfcolor[i][1] = 106;
			selfcolor[i][2] = 212;
		}
		else if (i < 228) {
			selfcolor[i][0] = 85;
			selfcolor[i][1] = 105;
			selfcolor[i][2] = 211;
		}
		else if (i < 232) {
			selfcolor[i][0] = 84;
			selfcolor[i][1] = 103;
			selfcolor[i][2] = 211;
		}
		else if (i < 236) {
			selfcolor[i][0] = 83;
			selfcolor[i][1] = 101;
			selfcolor[i][2] = 210;
		}
		else if (i < 240) {
			selfcolor[i][0] = 83;
			selfcolor[i][1] = 100;
			selfcolor[i][2] = 209;
		}
		else if (i < 244) {
			selfcolor[i][0] = 82;
			selfcolor[i][1] = 98;
			selfcolor[i][2] = 209;
		}
		else if (i < 248) {
			selfcolor[i][0] = 81;
			selfcolor[i][1] = 97;
			selfcolor[i][2] = 208;
		}
		else {
			selfcolor[i][0] = 81;
			selfcolor[i][1] = 95;
			selfcolor[i][2] = 208;
		}
	}
	Mat mcolor(1, 256, CV_8UC3, selfcolor);

	//定义二维数组
	float(*pointZ)[POINT_NUM];
	pointZ = new float[MAX_SIZE][POINT_NUM];

	FILE* fp;
	std::string fileCount = "2210865737_500";
	std::string fileName = "D:\\dataSet\\ma\\03\\" + fileCount + ".bin";//文件名
	//原始存储的二进制文件，读取z数据
	fp = fopen(fileName.c_str(), "rb+");
	fread(pointZ, sizeof(float), TOTAL_NUM, fp);
	fclose(fp);

	Mat img(MAX_SIZE, POINT_NUM, CV_32FC1, pointZ); //生成z矩阵
	Mat intMat, mask, mask1, rgbz, rgbc, mixIma;
	double omin, omax, zmin, zmax, zmean, maxMin;
	mask = cv::Mat(img != 0); //空值掩膜
	zmean = cv::mean(img, mask)[0]; //计算z均值
	//粗糙去噪
	omin = zmean - 30;
	omax = zmean + 40;
	mask1 = cv::Mat(img > omin & img < omax); //噪声掩膜
	double zmean1 = cv::mean(img, mask)[0];
	img = (img - zmean1) * 2 + 110; //z映射到0-255
	img.convertTo(intMat, CV_8UC1); //取整
	cv::cvtColor(intMat, intMat, COLOR_GRAY2BGR); //单通道转三通道
	LUT(intMat, mcolor, rgbz); //赋色
	std::string folder = "D:\\dataSet\\ma\\03\\picture\\";
	cv::imwrite(folder + fileCount + ".jpg", rgbz); //存储图像

	delete[]pointZ;
	return 0;
}