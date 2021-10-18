// t7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <fstream>
#include <string>


using namespace std;

int main() {
	
	int layer = 0;
	int node = 0;
	int ye = 0;
	string line;
	ifstream myfile("test3.txt");
	
	if (myfile.is_open())
	{	
		getline(myfile, line);//第一行数
		int num = stoi(line);
		/*
		
		for (int i = 0; i != num; i++) {
			array[i] = -1;
		}
		*/
		vector<int>array(num);
		vector<int>odd(num);
		for (int i = 0; i != num; i++) {
			myfile >> array[i];		
		}
		myfile.close();
		//auto [a,b] = f();
		
		int index = 0;
		int point = 0;
		int big = 0;
		for (index = 0; (index != num) || (point != num); index++)
		{
			if (array[index] != -1) {
				node += 1;
				//odd[index] += 1;

				if (point +1 == num) { //处理 9,10，-1,8,3，-1，-1
					if (array[point ] != -1) {
						//ye += 1;
						//node += 1;
						
						odd[point] = odd[index] + 1;
						big = odd[index] + 1;
						point += 1;
						break;
					}
					
				}
				
				
				point += 1;
				odd[point] = odd[index]+ 1;

				if (point +1== num) { //处理 9,10，-1,8,3，-1，-1，-1,7
					if (array[point] != -1) {
						//ye += 1;
						//node += 1;
						
						odd[point ] = odd[index] + 1;
						big = odd[index] + 1;
						point += 1;
						break;
					}
				}

				point += 1;
				odd[point] = odd[index] + 1;

				if ((array[point - 1] == -1) && (array[point] == -1)) { //下面2个-1
					ye += 1;
				}
			}
		}
			
		int shuzu_xia = index+1;
		int shuzu_shang = point;

		for (int i = shuzu_xia; i != num; i++) {
			if (array[i] != -1) {
				node += 1;
				ye += 1;
			}
		}
		big += 1;//+0
		std::printf("node:%d\n", node);
		std::printf("ye:%d\n", ye);
		std::printf("big:%d\n", big);

		
	}
}

