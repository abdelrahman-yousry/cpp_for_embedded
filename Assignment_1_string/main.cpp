
//*****************************************************************************
// Name        : assignement_1_Strings.cpp
// Author      : Abdelrahman Yousry
//*****************************************************************************
#include <iostream>
#include <string>
#include <sstream>



using namespace std;

string file_extension(string file);
int file_size(string file);
void test_cases(int *size_of_music,int *size_of_image,int *size_of_movies,int *size_of_other,int lines);
int main() {
    /* variable initialization */
	int num, test[num];
	string str;
    int size_of_music =0,size_of_movies =0,size_of_image =0,size_of_other =0;

    /* scan the number of the test cases from the user */ 
	cout<<"Enter the number of test cases "<<endl;
	cin>>num;
    /* scan the number of the lines in each test case*/
	cout<<"Enter the number of the lines in each test cases "<<endl;
	for(int i=0;i<num;i++)
	{
		cin>>test[i];
	}
	for(int i=0;i<num;i++)
	{
		size_of_music=0;
		size_of_image=0;
		size_of_movies=0;
		size_of_other=0;
		test_cases(&size_of_music,&size_of_image,&size_of_movies,&size_of_other,test[i]);
		cout<<"music "<<size_of_music<<" movie "<<size_of_movies<<" image "<<size_of_image<<" other "<<size_of_other<<endl;

	}

	return 0;
}


 /*Function to detect extension From String */

string file_extension(string file)
{
	size_t first =file.rfind(".");
	size_t last=file.rfind(" ");
	size_t pos=last-first;
	return file.substr(first+1,pos-1);
}

/*Function to detector Size From String*/

int file_size(string file)
{
	size_t first =file.rfind(" ");
	size_t last=file.rfind("b");
	size_t pos=last-first;
	int size=stoi(file.substr(first,pos));
	return size;
}


void test_cases(int *size_of_music,int *size_of_image,int *size_of_movies,int *size_of_other,int lines)
{
	int i;
	string extension,str;
	int size_old;
	for(int i=0;i<lines;i++)
	{
		cout<<"please enter the file name "<< i+1<<" "<<endl;
		   cin.ignore();
		   getline(cin,str);
		extension=file_extension(str);
		size_old=file_size(str);
	if (extension=="mp3"||extension=="aac"||extension=="flac")
	{
		*(size_of_music)+=size_old;
	}
	else	if (extension=="jpg"||extension=="bmp"||extension=="gif")
		{
			*(size_of_image)+=size_old;
		}
	else	if (extension=="mp4"||extension=="avi"||extension=="mkv")
			{
				*(size_of_movies)+=size_old;
			}
	else
	{

		*(size_of_other)+=size_old;
	}

	}
}