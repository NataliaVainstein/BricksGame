#include "LevelLoader.h"

LevelLoader::LevelLoader(std::string& _levelName)
:m_stream(_levelName.c_str())
{
}

bool LevelLoader::getLine(std::string& _strLine)
{
		if(!m_stream.eof())
		{
			getline(m_stream, _strLine);
			return true;
		}
		
		m_stream.close();
		return false;
}
