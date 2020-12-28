#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include"interpreter.h"

using namespace std;

int main(int argc, char const *argv[])
{
	
	string line;
	std::vector<std::string> tokens;

	std::getline(std::cin, line);
	std::stringstream ss(line);

	copy(std::istream_iterator<string>(ss), std::istream_iterator<string>(), std::back_inserter(tokens));

	string name = "world";

	if (tokens.begin()+1 != tokens.end())
		name = tokens[1];

	bool flag = is_done();
	
	while (!flag){

		if(tokens[0] == "bye"){
			execute("bye");
			execute(name);
			flag = !is_done();
		}

		else if(tokens[0] == "hello"){
			execute("hello");
			execute(name);
		}

		else{

			for(std::vector<std::string>::iterator v = tokens.begin(); v != tokens.end(); v++)
				execute(*v);
		}
		std::cout<<endl;
		std::getline(std::cin, line);
		std::stringstream ss(line);
		tokens.clear();
		copy(std::istream_iterator<string>(ss), std::istream_iterator<string>(), std::back_inserter(tokens));
	}

	std::cout<<endl;
	
	return 0;
}
