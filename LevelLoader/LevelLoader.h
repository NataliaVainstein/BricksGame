#ifndef __LEVEL_LOADER__
#define __LEVEL_LOADER__

#include <fstream>	

class LevelLoader 
{
public: 
	LevelLoader(std::string& _levelName);
	bool getLine(std::string& _strLine);
	
private:
	std::ifstream m_stream;
};



#endif //__LEVEL_LOADER__
