#ifndef _TRIGONOMETRICUNITHELPER_H_
#define _TRIGONOMETRICUNITHELPER_H_

//Singleton pattern design
//Purpose of this class is to share the information about AreRadiansChecked flag between GUI and Functions used by equationParser
class TrigonometricUnitHelper
{
public:
	static TrigonometricUnitHelper& getInstance()
	{
		static TrigonometricUnitHelper instance; 
		return instance;
	}
private:
	TrigonometricUnitHelper() {}

public:
	TrigonometricUnitHelper(TrigonometricUnitHelper const&) = delete;
	void operator=(TrigonometricUnitHelper const&) = delete;
	bool AreRadiansChecked;
};

#endif