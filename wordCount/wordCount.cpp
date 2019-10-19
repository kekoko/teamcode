#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
using namespace std;
int m=1,n=10;//若未出现-m，-n参数，默认值为1和10 
string inputFile(int argc,char *argv[])//读取文件 
{
	for(int i=0;i<argc;i++)
	{
		//cout<<argv[i]<<" "<<strlen(argv[i])<<endl;
		if(strcmp(argv[i],"-m")==0)//寻找m的值 
		{
			m=argv[i+1][0]-'0';
			i++;
			//cout<<"c"<<endl;
			continue;
		}
		if(strcmp(argv[i],"-n")==0)//寻找n的值 
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
			}//读取文件内容存入s中 
			//cout<<s<<endl;
			fin.close();
			break;
		}
	}
	return s;
}
void outputFile(int argc,char *argv[],int charactersNum,int wordNum,int lineNum,string s[],int snum[],int num)//输出文件 
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
		}//输出答案到文件 
	}
}
int Get_Character(string str){
	return str.length();
}
int Get_Line(string str) {
		int length=str.length();
	    int lines=0;
	    int sign=0;
	    int i;
	    for(i=0;i<length;i++)
	    {
		    if(str[i]!='\n'&&str[i]!=' '&&str[i]!='\t')
		    {
			    sign=1;	
		    }
		    else if(str[i]=='\n')
		    {
			    if(sign==1)
			    {
				    lines++;
				    sign=0;
			    }
		    }
	    }
	    lines=lines+1;
	    return	lines;
}
bool Word_panduan(string word){
	int len = word.length();
	if (len<4)//?D??3¤?èê?·?′óóú4
	{
		return false;
	}
	for(int i=0;i<4;i++)//?D??ê?·?×???￡?2?ê?μ??°·μ??0
	{
		if (word[i] <='a' && word[i]<='z' ||  word[i] <='A' && word[i]>='Z')
		{	
			return false;
		}
	}
	return true;
}
int Get_Word(string str){
	string word;
	int count;
	int j = 0;
	int len = str.length();
	for(int i=0,j=0;i<len;i++,j++){
		word[j] = str[i];
		if((str[i]>=32&&str[i]<=47) || (str[i]>=58&&str[i]<=64) ||(str[i]>=91&&str[i]<=96) || (str[i]>=123)){
			if(Word_panduan(word)){
				count+=1;
			}
		}
	}
	return count;
}
int main(int argc,char *argv[])
{
	string str=inputFile(argc,argv);
	string s[10];
	int sNum[10];
	int character = Get_Character(str);
	int line = Get_Line(str);
	int word = Get_Word(str);
	outputFile(argc,argv,character,line,word,s,sNum,10);//参数对应输出要求的各个内容 
	return 0;
}
