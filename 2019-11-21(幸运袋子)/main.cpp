#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int fun(int n, int* arr) {
		sort(arr, arr + n);
		int onenums = 0;
		for (int i = 0; arr[i] == 1; ++onenums, ++i);
		if (onenums == 0)  return 0;//没有1的话是形不成幸运袋子
		vector<int> prod = { 1 }; //记录可行的乘积
		vector<int> sum = { 0 };  //记录可行的和
		for (int i = onenums, size, k, presize = 0; i < n; ++i) {
			//从最后一个1的下一个位置开始, 因为之前的1没必要重复比较
			//和已经记录为onenumbs, 而1不影响乘积
			size = sum.size();//prod.size(),一样大
			arr[i] == arr[i - 1] ? k = presize : k = 0;
			//如果与前一数一样就没必要重复添加到前面的袋子
			for (; k < size; ++k) {
				//加入第i个球到袋子后，是否是幸运, 是的话保存乘积及和
				if (sum[k] + arr[i] + onenums > prod[k] * arr[i]) {
					prod.push_back(prod[k] * arr[i]);
					sum.push_back(sum[k] + arr[i]);
				}
			}
			presize = size;
		}
		int count = 0;
		if (onenums > 2) {
			count = onenums - 1;
		}
		for (int k = 1; k < (int)sum.size(); ++k) {//通过加入不同数量的1以使各袋子幸运
			count += onenums + sum[k] - prod[k];
			//(onenums + sum[k]) - prod[k]等于n, 则说明加入1个, 2各个,....n个都满足幸运
		}
		return count;
	}
};
int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	Solution p;
	cout << p.fun(n, arr) << endl;
	delete[] arr;
	system("pause");
	return 0;
}
