#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
using namespace std;
int m=1,n=10;//��δ����-m��-n������Ĭ��ֵΪ1��10 
string inputFile(int argc,char *argv[])//��ȡ�ļ� 
{
	for(int i=0;i<argc;i++)
	{
		//cout<<argv[i]<<" "<<strlen(argv[i])<<endl;
		if(strcmp(argv[i],"-m")==0)//Ѱ��m��ֵ 
		{
			m=argv[i+1][0]-'0';
			i++;
			//cout<<"c"<<endl;
			continue;
		}
		if(strcmp(argv[i],"-n")==0)//Ѱ��n��ֵ 
		{
			n=argv[i+1][0]-'0';
			i++;
			//cout<<"d"<<endl;
			continue;
		}
	}
	ifstream fin;
	string s="",line;
	for(int i=0;i<argc;i++)
	{
		if(strcmp(argv[i],"-i")==0)
		{
			fin.open(argv[i+1]);
			while(getline(fin,line))
			{
				s+="\n";
				s+=line;
			}//��ȡ�ļ����ݴ���s�� 
			//cout<<s<<endl;
			fin.close();
			break;
		}
	}
	return s;
}
void outputFile(int argc,char *argv[],int charactersNum,int wordNum,int lineNum,string s[],int snum[],int num)//����ļ� 
{
	for(int i=0;i<argc;i++)
	{
		if(strcmp(argv[i],"-o")==0)
		{
			ofstream fout;
			fout.open(argv[i+1]);
			fout<<"characters: "<<charactersNum<<endl;
			fout<<"words: "<<wordNum<<endl;
			fout<<"lines: "<<lineNum<<endl;
			/*for(int i=0;i<num;i++)
			{
				fout<<s[i]<<": "<<snum[i]<<endl;
			}*/
			fout.close();
			break;
		}//����𰸵��ļ� 
	}
}
int Get_Word(string str){
	return str.length();
}
int Get_Line(string str) {
	
}
int main(int argc,char *argv[])
{
	string str=inputFile(argc,argv);
	string s[10];
	int sNum[10];
	int word = Get_Word(str);
	outputFile(argc,argv,word,5,2,s,sNum,10);//������Ӧ���Ҫ��ĸ������� 
	return 0;
}
