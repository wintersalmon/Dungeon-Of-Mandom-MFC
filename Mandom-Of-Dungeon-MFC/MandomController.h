#pragma once
class MandomController
{
public:
	MandomController();
	~MandomController();
	PyObject* pyModule;
	void StartGame();
	bool IsRunning();
	bool Update();
	int GetPlayerLifePoint(int playerNumber);
//	PyObject pyDict;
	PyObject *pyDict;
};

