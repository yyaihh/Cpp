//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include <time.h>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
///*
//* @brief 对输入图像进行细化,骨骼化
//* @param src为输入图像,用cvThreshold函数处理过的8位灰度图像格式，元素中只有0与1,1代表有元素，0代表为空白
//* @param dst为对src细化后的输出图像,格式与src格式相同，元素中只有0与1,1代表有元素，0代表为空白
//*/
//void thinImage(Mat & src, Mat & dst)
//{
//	int width = src.cols;
//	int height = src.rows;
//	src.copyTo(dst);
//	vector<uchar *> mFlag; //用于标记需要删除的点    
//	while (true)
//	{
//		//步骤一   
//		for (int i = 0; i < height; ++i)
//		{
//			uchar * p = dst.ptr<uchar>(i);
//			for (int j = 0; j < width; ++j)
//			{
//				//获得九个点对象，注意边界问题
//				uchar p1 = p[j];
//				if (p1 != 1) continue;
//				uchar p2 = (i == 0) ? 0 : *(p - dst.step + j);
//				uchar p3 = (i == 0 || j == width - 1) ? 0 : *(p - dst.step + j + 1);
//				uchar p4 = (j == width - 1) ? 0 : *(p + j + 1);
//				uchar p5 = (i == height - 1 || j == width - 1) ? 0 : *(p + dst.step + j + 1);
//				uchar p6 = (i == height - 1) ? 0 : *(p + dst.step + j);
//				uchar p7 = (i == height - 1 || j == 0) ? 0 : *(p + dst.step + j - 1);
//				uchar p8 = (j == 0) ? 0 : *(p + j - 1);
//				uchar p9 = (i == 0 || j == 0) ? 0 : *(p - dst.step + j - 1);
//				if ((p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9) >= 2 && (p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9) <= 6)//条件1判断
//				{
//					//条件2计算
//					int ap = 0;
//					if (p2 == 0 && p3 == 1) ++ap;
//					if (p3 == 0 && p4 == 1) ++ap;
//					if (p4 == 0 && p5 == 1) ++ap;
//					if (p5 == 0 && p6 == 1) ++ap;
//					if (p6 == 0 && p7 == 1) ++ap;
//					if (p7 == 0 && p8 == 1) ++ap;
//					if (p8 == 0 && p9 == 1) ++ap;
//					if (p9 == 0 && p2 == 1) ++ap;
//					//条件2、3、4判断
//					if (ap == 1 && p2 * p4 * p6 == 0 && p4 * p6 * p8 == 0)
//					{
//						//标记    
//						mFlag.push_back(p + j);
//					}
//				}
//			}
//		}
//		//将标记的点删除    
//		for (vector<uchar *>::iterator i = mFlag.begin(); i != mFlag.end(); ++i)
//		{
//			**i = 0;
//		}
//		//直到没有点满足，算法结束    
//		if (mFlag.empty())
//		{
//			break;
//		}
//		else
//		{
//			mFlag.clear();//将mFlag清空    
//		}
//
//		//步骤二，根据情况该步骤可以和步骤一封装在一起成为一个函数
//		for (int i = 0; i < height; ++i)
//		{
//			uchar * p = dst.ptr<uchar>(i);
//			for (int j = 0; j < width; ++j)
//			{
//				//如果满足四个条件，进行标记    
//				//  p9 p2 p3    
//				//  p8 p1 p4    
//				//  p7 p6 p5    
//				uchar p1 = p[j];
//				if (p1 != 1) continue;
//				uchar p2 = (i == 0) ? 0 : *(p - dst.step + j);
//				uchar p3 = (i == 0 || j == width - 1) ? 0 : *(p - dst.step + j + 1);
//				uchar p4 = (j == width - 1) ? 0 : *(p + j + 1);
//				uchar p5 = (i == height - 1 || j == width - 1) ? 0 : *(p + dst.step + j + 1);
//				uchar p6 = (i == height - 1) ? 0 : *(p + dst.step + j);
//				uchar p7 = (i == height - 1 || j == 0) ? 0 : *(p + dst.step + j - 1);
//				uchar p8 = (j == 0) ? 0 : *(p + j - 1);
//				uchar p9 = (i == 0 || j == 0) ? 0 : *(p - dst.step + j - 1);
//				if ((p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9) >= 2 && (p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9) <= 6)
//				{
//					int ap = 0;
//					if (p2 == 0 && p3 == 1) ++ap;
//					if (p3 == 0 && p4 == 1) ++ap;
//					if (p4 == 0 && p5 == 1) ++ap;
//					if (p5 == 0 && p6 == 1) ++ap;
//					if (p6 == 0 && p7 == 1) ++ap;
//					if (p7 == 0 && p8 == 1) ++ap;
//					if (p8 == 0 && p9 == 1) ++ap;
//					if (p9 == 0 && p2 == 1) ++ap;
//					if (ap == 1 && p2 * p4 * p8 == 0 && p2 * p6 * p8 == 0)
//					{
//						//标记    
//						mFlag.push_back(p + j);
//					}
//				}
//			}
//		}
//		//将标记的点删除    
//		for (vector<uchar *>::iterator i = mFlag.begin(); i != mFlag.end(); ++i)
//		{
//			**i = 0;
//		}
//		//直到没有点满足，算法结束    
//		if (mFlag.empty())
//		{
//			break;
//		}
//		else
//		{
//			mFlag.clear();//将mFlag清空    
//		}
//	}
//}
//
//int main() {
//	Mat src = imread("4.jpg", IMREAD_GRAYSCALE);
//	GaussianBlur(src, src, Size(7, 7), 0, 0);//高斯滤波
//	threshold(src, src, 140, 1, cv::THRESH_BINARY_INV);//二值化，前景为1，背景为0
//	Mat dst;
//	thinImage(src, dst);//图像细化（骨骼化）
//	src = src * 255;
//	imshow("原始图像", src);
//	dst = dst * 255;
//	imshow("细化图像", dst);
//	waitKey(0);
//	return 0;
//}
#include<iostream>
#include <time.h>
#include <opencv2/opencv.hpp>
#include <vector>//容器头文件 

using namespace std;
using namespace cv;


//void detectMultiScale(
//	const Mat& image,
//	CV_OUT vector<Rect>& objects,
//	double scaleFactor = 1.1,
//	int minNeighbors = 3,
//	int flags = 0,
//	Size minSize = Size(),
//	Size maxSize = Size()
//);
//参数1：image--待检测图片，一般为灰度图像加快检测速度；
//参数2：objects--被检测物体的矩形框向量组；
//参数3：scaleFactor--表示在前后两次相继的扫描中，搜索窗口的比例系数。默认为1.1即每次搜索窗口依次扩大10%;
//参数4：minNeighbors--表示构成检测目标的相邻矩形的最小个数(默认为3个)。
//如果组成检测目标的小矩形的个数和小于 min_neighbors - 1 都会被排除。
//如果min_neighbors 为 0, 则函数不做任何操作就返回所有的被检候选矩形框
//参数5：flags--要么使用默认值，要么使用CV_HAAR_DO_CANNY_PRUNING
//CV_HAAR_DO_CANNY_PRUNING--函数将会使用Canny边缘检测来排除边缘过多或过少的区域,因为这些区域通常不会是人脸所在区域；
//参数6、7：minSize和maxSize用来限制得到的目标区域的范围。

void getfaceimg()//人脸图像获取
{
	CascadeClassifier ccf;//创建脸部对象
	string cascadeName = "haarcascade_frontalface_alt2.xml";//人脸检测模型，请在OpenCV文件夹中搜索
	ccf.load(cascadeName);//读取opencv人脸检测模型
	vector<Rect> faces;//容器，存放检测到的人脸
	long time = clock();
	string path = "1.png";
	Mat img = imread(path, 0);
	imshow("原图", img);
	equalizeHist(img, img);//直方图均衡化
						   //imshow("直方图均衡化", img);
						   //人脸检测
	ccf.detectMultiScale(img, faces, 1.1, 3, 1, Size(50, 50), Size(500, 500));//人脸检测
	for (vector<Rect>::const_iterator iter = faces.begin(); iter != faces.end(); iter++)
	{
		rectangle(img, *iter, Scalar(0), 2, 8); //用矩形圈出人脸
	}
	//截取保存脸部图像
	Mat faceimg;
	vector<Rect>::const_iterator iter = faces.begin();
	faceimg = img(*iter);
	imshow("脸部图像", faceimg);
	imwrite("faceImg//" + path, faceimg);
	imshow("检测结果", img);
	waitKey(999999);
	cout << "花费时间：" << clock() - time << "ms" << endl;
}


int main()
{
	getfaceimg();//人脸图像获取
	return 0;
}