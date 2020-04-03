//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include <time.h>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
///*
//* @brief ������ͼ�����ϸ��,������
//* @param srcΪ����ͼ��,��cvThreshold�����������8λ�Ҷ�ͼ���ʽ��Ԫ����ֻ��0��1,1������Ԫ�أ�0����Ϊ�հ�
//* @param dstΪ��srcϸ��������ͼ��,��ʽ��src��ʽ��ͬ��Ԫ����ֻ��0��1,1������Ԫ�أ�0����Ϊ�հ�
//*/
//void thinImage(Mat & src, Mat & dst)
//{
//	int width = src.cols;
//	int height = src.rows;
//	src.copyTo(dst);
//	vector<uchar *> mFlag; //���ڱ����Ҫɾ���ĵ�    
//	while (true)
//	{
//		//����һ   
//		for (int i = 0; i < height; ++i)
//		{
//			uchar * p = dst.ptr<uchar>(i);
//			for (int j = 0; j < width; ++j)
//			{
//				//��þŸ������ע��߽�����
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
//				if ((p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9) >= 2 && (p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9) <= 6)//����1�ж�
//				{
//					//����2����
//					int ap = 0;
//					if (p2 == 0 && p3 == 1) ++ap;
//					if (p3 == 0 && p4 == 1) ++ap;
//					if (p4 == 0 && p5 == 1) ++ap;
//					if (p5 == 0 && p6 == 1) ++ap;
//					if (p6 == 0 && p7 == 1) ++ap;
//					if (p7 == 0 && p8 == 1) ++ap;
//					if (p8 == 0 && p9 == 1) ++ap;
//					if (p9 == 0 && p2 == 1) ++ap;
//					//����2��3��4�ж�
//					if (ap == 1 && p2 * p4 * p6 == 0 && p4 * p6 * p8 == 0)
//					{
//						//���    
//						mFlag.push_back(p + j);
//					}
//				}
//			}
//		}
//		//����ǵĵ�ɾ��    
//		for (vector<uchar *>::iterator i = mFlag.begin(); i != mFlag.end(); ++i)
//		{
//			**i = 0;
//		}
//		//ֱ��û�е����㣬�㷨����    
//		if (mFlag.empty())
//		{
//			break;
//		}
//		else
//		{
//			mFlag.clear();//��mFlag���    
//		}
//
//		//���������������ò�����ԺͲ���һ��װ��һ���Ϊһ������
//		for (int i = 0; i < height; ++i)
//		{
//			uchar * p = dst.ptr<uchar>(i);
//			for (int j = 0; j < width; ++j)
//			{
//				//��������ĸ����������б��    
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
//						//���    
//						mFlag.push_back(p + j);
//					}
//				}
//			}
//		}
//		//����ǵĵ�ɾ��    
//		for (vector<uchar *>::iterator i = mFlag.begin(); i != mFlag.end(); ++i)
//		{
//			**i = 0;
//		}
//		//ֱ��û�е����㣬�㷨����    
//		if (mFlag.empty())
//		{
//			break;
//		}
//		else
//		{
//			mFlag.clear();//��mFlag���    
//		}
//	}
//}
//
//int main() {
//	Mat src = imread("4.jpg", IMREAD_GRAYSCALE);
//	GaussianBlur(src, src, Size(7, 7), 0, 0);//��˹�˲�
//	threshold(src, src, 140, 1, cv::THRESH_BINARY_INV);//��ֵ����ǰ��Ϊ1������Ϊ0
//	Mat dst;
//	thinImage(src, dst);//ͼ��ϸ������������
//	src = src * 255;
//	imshow("ԭʼͼ��", src);
//	dst = dst * 255;
//	imshow("ϸ��ͼ��", dst);
//	waitKey(0);
//	return 0;
//}
#include<iostream>
#include <time.h>
#include <opencv2/opencv.hpp>
#include <vector>//����ͷ�ļ� 

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
//����1��image--�����ͼƬ��һ��Ϊ�Ҷ�ͼ��ӿ����ٶȣ�
//����2��objects--���������ľ��ο������飻
//����3��scaleFactor--��ʾ��ǰ��������̵�ɨ���У��������ڵı���ϵ����Ĭ��Ϊ1.1��ÿ������������������10%;
//����4��minNeighbors--��ʾ���ɼ��Ŀ������ھ��ε���С����(Ĭ��Ϊ3��)��
//�����ɼ��Ŀ���С���εĸ�����С�� min_neighbors - 1 ���ᱻ�ų���
//���min_neighbors Ϊ 0, ���������κβ����ͷ������еı����ѡ���ο�
//����5��flags--Ҫôʹ��Ĭ��ֵ��Ҫôʹ��CV_HAAR_DO_CANNY_PRUNING
//CV_HAAR_DO_CANNY_PRUNING--��������ʹ��Canny��Ե������ų���Ե�������ٵ�����,��Ϊ��Щ����ͨ��������������������
//����6��7��minSize��maxSize�������Ƶõ���Ŀ������ķ�Χ��

void getfaceimg()//����ͼ���ȡ
{
	CascadeClassifier ccf;//������������
	string cascadeName = "haarcascade_frontalface_alt2.xml";//�������ģ�ͣ�����OpenCV�ļ���������
	ccf.load(cascadeName);//��ȡopencv�������ģ��
	vector<Rect> faces;//��������ż�⵽������
	long time = clock();
	string path = "1.png";
	Mat img = imread(path, 0);
	imshow("ԭͼ", img);
	equalizeHist(img, img);//ֱ��ͼ���⻯
						   //imshow("ֱ��ͼ���⻯", img);
						   //�������
	ccf.detectMultiScale(img, faces, 1.1, 3, 1, Size(50, 50), Size(500, 500));//�������
	for (vector<Rect>::const_iterator iter = faces.begin(); iter != faces.end(); iter++)
	{
		rectangle(img, *iter, Scalar(0), 2, 8); //�þ���Ȧ������
	}
	//��ȡ��������ͼ��
	Mat faceimg;
	vector<Rect>::const_iterator iter = faces.begin();
	faceimg = img(*iter);
	imshow("����ͼ��", faceimg);
	imwrite("faceImg//" + path, faceimg);
	imshow("�����", img);
	waitKey(999999);
	cout << "����ʱ�䣺" << clock() - time << "ms" << endl;
}


int main()
{
	getfaceimg();//����ͼ���ȡ
	return 0;
}