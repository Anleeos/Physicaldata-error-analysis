// physicaldataanalysis.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <math.h>

int main()
{
	using namespace std;
	cout << "输入你的仪器误差（注意单位一致）" << endl;
	double wc;
	cin >> wc;
	cout << "输入你的实验数据（ctrl+Z以终止）" << endl;
	double tp[10] = { 1 , 0 , 1.32 , 1.20 , 1.14 , 1.11 , 1.09 , 1.08 , 1.07 , 1.06 };
	double data, aver = 0, sx = 0;
	int i = 0;
	vector<double> datavec;
	while (cin >> data) {
		i++;
		datavec.push_back(data);
	}
	for (int j = 0; j < i; j++) {
		aver += datavec[j];
	}
	cin.clear();
	aver = aver / i;
	cout << "平均值修正，当前平均值为" << aver << "，请手动约修：";
	cin >> aver;
	double sum = 0;
	for (int j = 0; j < i; j++) {
		sum += (aver - datavec[j]) * (aver - datavec[j]);
	}
	if (i == 1)
		sx = wc / sqrt(3.0);
	else {
		sx = tp[i - 1] * sqrt(sum / (i * (i - 1)));
		cout << "A类：" << sx << endl;
		sx = sqrt(sx * sx + wc * wc / 3);
	}
	double ex = sx / aver;
	cout << "数据为" << aver << "+-" << sx << endl;
	cout << "相对误差为" << ex << endl << "输入#进行下一次计算，q结束程序";
	char ch;
	cin >> ch;
	if (ch == '#')
		return main();
	else
		return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
