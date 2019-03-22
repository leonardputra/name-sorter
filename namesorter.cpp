 #include <vector>
 #include <algorithm>
 #include <iostream>
 #include <fstream>
 
using namespace std;

vector<string> names;
vector<string> swappedNames;
vector<string> unswappedNames;
vector<string>::iterator it; //iterator
string inFile;
string str;
string strFirst;
string strGiven;
string strFullName;

void getFile(string fileInput){
	ifstream file;
	file.open(fileInput.c_str());
		//check if the file is in use
	if (!file.is_open())
   		cout << "Error opening file, file in use?";
		//read from the file line by line and store it to vector
	while (std::getline(file, str))
	{
		// if a line contains string of length > 0 (there's a data), then save it in 'names' vector
		if(str.size() > 0)
			names.push_back(str);
	}
}

void swapNames(vector<string> unswapped){
  for (it=unswapped.begin(); it!=unswapped.end(); ++it)
{
  str=*it;
    {
	int pos = str.find_last_of(" \t\n");
	strGiven = str.substr(0, pos);
	strFirst = str.substr(pos+1);
		//combine the first and given name to the first-given format	
	strFullName = strFirst+" "+strGiven;
    swappedNames.push_back(strFullName);
	}
}
}

void unswapNames(vector<string> swapped){
  for (it=swapped.begin(); it!=swapped.end(); ++it)
{
  str=*it;
    {
	int pos = str.find_first_of(" \t\n");
	strGiven = str.substr(pos+1);
	strFirst = str.substr(0,pos);
		//combine the first and given name to the given-first format	
	strFullName = strGiven+" "+strFirst;
    unswappedNames.push_back(strFullName);
	}
}
}

void generateResult(){
	ofstream outputFile ("sorted-names-list.txt ");
	if (outputFile.is_open()){
	//iterate the unswappedNames vector and print it to the screen
    for (it=unswappedNames.begin(); it!=unswappedNames.end(); ++it){
    cout <<  *it << "\n";
    //save to file
 	outputFile << *it << "\n";   
}
}
    outputFile.close();
}

int main(int argc, char** argv){
	//open file specified on the commandline
	if( argc == 2 ) {
      inFile = argv[1];
    }
    else {
      cout << "Usage: namesorter ./InputFile \n";
      return 1;
    }
getFile(inFile);
	//swap names so the first name get sorted first
swapNames(names);
	//sort the previously swapped names alphabetically started from first name, and then given name
sort(swappedNames.begin(), swappedNames.end());
	//unswap back names to the original name
unswapNames(swappedNames);
	//displays & save the sorted output
generateResult();
return 0;
}


