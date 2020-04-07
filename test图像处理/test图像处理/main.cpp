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

//void getfaceimg()//人脸图像获取
//{
//	CascadeClassifier ccf;//创建脸部对象
//	//string cascadeName = "haarcascade_frontalface_alt2.xml";//人脸检测模型，请在OpenCV文件夹中搜索
//	string cascadeName = "result.xml";
//	ccf.load(cascadeName);//读取opencv人脸检测模型
//	vector<Rect> faces;//容器，存放检测到的人脸
//	long time = clock();
//	string path = "1.png";
//	Mat img = imread(path, 0);
//	imshow("原图", img);
//	equalizeHist(img, img);//直方图均衡化
//						   //imshow("直方图均衡化", img);
//						   //人脸检测
//	ccf.detectMultiScale(img, faces, 1.1, 3, 1, Size(50, 50), Size(500, 500));//人脸检测
//	for (vector<Rect>::const_iterator iter = faces.begin(); iter != faces.end(); iter++)
//	{
//		rectangle(img, *iter, Scalar(0), 2, 8); //用矩形圈出人脸
//	}
//	//截取保存脸部图像
//	Mat faceimg;
//	vector<Rect>::const_iterator iter = faces.begin();
//	faceimg = img(*iter);
//	imshow("脸部图像", faceimg);
//	imwrite("faceImg//" + path, faceimg);
//	imshow("检测结果", img);
//	waitKey(999999);
//	cout << "花费时间：" << clock() - time << "ms" << endl;
//}
//
//
//int main()
//{
//	getfaceimg();//人脸图像获取
//	return 0;
//}

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace cv::ml;
using namespace std;

string positive_dir = "./elec_pepole/positive/";
string negative_dir = "./elec_pepole/negative/";
string testPic = "./elec_pepole/test/1586268475(1).png";

vector< float > get_svm_detector(const Ptr< SVM >& svm)
{
	// get the support vectors
	Mat sv = svm->getSupportVectors();
	const int sv_total = sv.rows;
	// get the decision function
	Mat alpha, svidx;
	double rho = svm->getDecisionFunction(0, alpha, svidx);

	CV_Assert(alpha.total() == 1 && svidx.total() == 1 && sv_total == 1);
	CV_Assert((alpha.type() == CV_64F && alpha.at<double>(0) == 1.) ||
		(alpha.type() == CV_32F && alpha.at<float>(0) == 1.f));
	CV_Assert(sv.type() == CV_32F);

	vector< float > hog_detector(sv.cols + 1);
	memcpy(&hog_detector[0], sv.ptr(), sv.cols * sizeof(hog_detector[0]));
	hog_detector[sv.cols] = (float)-rho;
	return hog_detector;
}

void svm_train(Mat &trainData, Mat &labels) {
	printf("\n start SVM training... \n");
	Ptr< SVM > svm = SVM::create();
	/* Default values to train SVM */
	svm->setGamma(5.383);
	svm->setKernel(SVM::LINEAR);
	svm->setC(2.67);
	svm->setType(SVM::C_SVC);
	svm->train(trainData, ROW_SAMPLE, labels);
	clog << "...[done]" << endl;

	// save xml
	svm->save("./hog_elec.yml");
}

void get_hog_descripor(Mat &image, vector<float> &desc) {
	HOGDescriptor hog;
	int h = image.rows;
	int w = image.cols;
	float rate = 64.0 / w;
	Mat img, gray;
	resize(image, img, Size(64, int(rate*h)));
	cvtColor(img, gray, COLOR_BGR2GRAY);
	Mat result = Mat::zeros(Size(102, 128), CV_8UC1);
	result = Scalar(127);
	Rect roi;
	roi.x = 0;
	roi.width = 64;
	roi.y = (128 - gray.rows) / 2;
	roi.height = gray.rows;
	gray.copyTo(result(roi));
	hog.compute(result, desc, Size(8, 8), Size(0, 0));
}

void generate_dataset(Mat &trainData, Mat &labels) {
	vector<string> images;
	vector<vector<float>> vecDec;
	vector<float> fv;
	glob(positive_dir, images);
	int posNum = images.size();
	for (int i = 0; i < posNum; i++)
	{
		Mat image = imread(images[i].c_str());
		vector<float> fv;
		get_hog_descripor(image, fv);
		printf("image path : %s, feature data length: %d \n", images[i].c_str(), fv.size());
		vecDec.push_back(fv);
	}
	images.clear();
	glob(negative_dir, images);
	int negNum = images.size();
	for (int i = 0; i < negNum; i++)
	{
		fv.clear();
		Mat image = imread(images[i].c_str());
		get_hog_descripor(image, fv);
		printf("image path : %s, feature data length: %d \n", images[i].c_str(), fv.size());
		vecDec.push_back(fv);
	}
	int trainDataNum = posNum + negNum;
	int trainDataLen = fv.size();


	Mat trainDataTemp(trainDataNum, trainDataLen, CV_32FC1);
	Mat trainLabel(trainDataNum, 1, CV_32SC1);


	for (int i = 0; i < trainDataNum; i++)
	{
		for (int j = 0; j < trainDataLen; j++)
		{
			trainDataTemp.at<float>(i, j) = vecDec[i][j];
		}
		if (i < posNum)
		{
			trainLabel.at<int>(i) = 1;
		}
		else
		{
			trainLabel.at<int>(i) = -1;
		}
	}

	trainData = trainDataTemp.clone();
	labels = trainLabel.clone();

	return;
}
int main(int argc, char* argv[]) {
	Mat trainData, labels;
	generate_dataset(trainData, labels);
	svm_train(trainData, labels);

	Ptr<SVM> svm = SVM::load("./hog_elec.yml");
	Mat test = imread(testPic);
	resize(test, test, Size(0, 0), 0.20, 0.20);

	imshow("input", test);
	Rect winRect;
	winRect.width = 64;
	winRect.height = 128;
	int sum_x = 0;
	int sum_y = 0;
	int count = 0;
	for (int row = 64; row < test.rows - 64; row += 4) {
		for (int col = 32; col < test.cols - 32; col += 4) {
			winRect.x = col - 32;
			winRect.y = row - 64;
			vector<float> fv;
			Mat hogRect = test(winRect);
			get_hog_descripor(hogRect, fv);
			Mat one_row = Mat::zeros(Size(fv.size(), 1), CV_32FC1);
			for (int i = 0; i < fv.size(); i++) {
				one_row.at<float>(0, i) = fv[i];
			}
			float result = svm->predict(one_row);
			if (result > 0) {
				// rectangle(test, winRect, Scalar(0, 0, 255), 1, 8, 0);
				sum_x += winRect.x;
				sum_y += winRect.y;
				count++;
			}
		}
	}
	winRect.x = sum_x / count;
	winRect.y = sum_y / count;
	rectangle(test, winRect, Scalar(255, 0, 0), 1, 8, 0);
	imshow("result", test);
	waitKey(0);
	return 0;
}

