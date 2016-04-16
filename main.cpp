#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
using namespace std;
using namespace cv;

int main(int argc,char ** argv)
{

	cout<<" ./main key EC.png w 45 message to wirte on row 4 col 5"<<endl;
	cout<<" ./main key EC.png r to read message "<<endl;
	string key="key";// you can change the key into your own key, here my key is dao
	if(argc == 1)
		return -1;
	if(strcmp(argv[1],key.c_str())!=0)
	{
		cout<<"Wrong Key"<<endl
		return 1;
	}
		

	Mat pwd=imread(argv[2]);
	if(strcmp(argv[3],"w")==0)
	{
		int row=static_cast<int>(argv[4][0]-48);
		int col=static_cast<int>(argv[4][1]-48);

		pwd.at<uchar>(0,0)=char(row);
		pwd.at<uchar>(0,1)=char(col);
		int len=strlen(argv[5]);
		
		pwd.at<uchar>(0,2)=char(len);
		cout<<static_cast<int>(pwd.at<uchar>(0,0))<<" "<<static_cast<int>(pwd.at<uchar>(0,1))<<" "<<static_cast<int>(pwd.at<uchar>(0,2))<<endl;
		if(row>pwd.rows||col+len>pwd.cols)
			return -2;
		for(int i=0;i<len;i++)
		{
			pwd.at<uchar>(row,col+i)=(argv[5][i]);
			cout<<(pwd.at<uchar>(row,col+i))<<" ";
		}
		cout<<endl;
		string name(argv[2]);
		name=name.substr(0,name.find_first_of('.'))+".png";
		imwrite(name.c_str(),pwd);
		
	}	
	else if(strcmp(argv[3],"r")==0)
	{
		int where_row=static_cast<int>(pwd.at<uchar>(0,0));
		int where_col=static_cast<int>(pwd.at<uchar>(0,1));
		int where_len=static_cast<int>(pwd.at<uchar>(0,2));
		cout<<"row :"<<where_row<<", "<<"col :"<<where_col<<","<<"len :"<<where_len<<endl;
		for(int i=0;i<where_len;i++)
		{
			cout<<pwd.at<uchar>(where_row,where_col+i)<<" ";
		}
		cout<<endl;
		
	}

	
	
}
