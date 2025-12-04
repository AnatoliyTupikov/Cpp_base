#include <iostream>
#include <string>
#include <vector>
#include <fstream> //bibl with file handling functions

//fstream - for both reading and writing to files
//ifstream - for reading from files
//ofstream - for writing to files

int main()
{
	//ofstream - writing to files
	//Text mode - data is written as text. Each data type is converted to a string representation. And \n -> \r\n on Windows.
	{
		setlocale(LC_ALL, "ru"); //for using national language in console
		std::ofstream fout; //object for writing to files. Wthout "New" because the object is created on stack memory
		fout.open("File_Man_base.txt"); //open file named sample.txt. If file doesn't exist, it will be created. We can use relative or absolute path.  
		//Withoout parameters, open() writes in text mode and errases the previous content of the file.
		// To write in binary mode, we can use: fout.open("sample.txt", std::ios::binary); 
		// To append data to the end of the file, we can use: fout.open("sample.txt", std::ios::app);

		if (!fout.is_open()) std::cout << "File open error" << std::endl; //check if file is open
		else
		{
			fout << 123 << std::endl; //In buffer of the stream write string "123" and end line. Endline is necessary to flush the buffer to the file.
		}

		fout.close(); //flush the buffer to the file and close the file

	}

	//ifstream - reading from files
	//Text mode - data is read as text. Each data type is read as a string representation. And \r\n -> \n on Windows.
	{
		
		std::ifstream fin; //object for reading from files. Wthout "New" because the object is created on stack memory
		fin.open("File_Man_base.txt"); //open file named myFile.txt. The file must exist. We can use relative or absolute path. 

		if (!fin.is_open()) std::cout << "File open error" << std::endl; //check if file is open
		else
		{
			std::vector<int> buffer; //create a buffer to store read data
			char ch;
			std::string str;
			while (fin.get(ch)) //return false when it can't read more characters from the file ( when the end of the file is reached)
			{
				buffer.push_back(ch); //store the read character in the buffer
				fin >> str;
				std::cout << str << std::endl;
			}
			for (char c : buffer) std::cout << c; //output the read data to console
		}

		fin.close(); //it needs to close the file
		
	}
	{

	}
	

	return 0;
}