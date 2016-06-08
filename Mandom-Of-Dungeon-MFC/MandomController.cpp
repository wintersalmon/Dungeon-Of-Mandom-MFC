#include "stdafx.h"
#include "MandomController.h"

MandomController::MandomController()
	: pyModule(NULL)
	, pyDict(NULL)
{
	Py_Initialize();

	PyObject * pNameMain = PyUnicode_DecodeFSDefault("main");

	pyModule = PyImport_Import(pNameMain);
	assert(pyModule != NULL);

	pyDict = PyModule_GetDict(pyModule);
	assert(pyDict != NULL);

	pyUpdater = 
}


MandomController::~MandomController()
{
	Py_Finalize();
}


void MandomController::StartGame()
{
	PyObject* result_start = PyObject_CallMethod(pyModule, "start", NULL);
	assert(result_start != NULL);
	Py_DECREF(result_start);
}


bool MandomController::IsRunning()
{
	PyObject* result_is_running = PyObject_CallMethod(pyModule, "is_running", NULL);
	assert(result_is_running != NULL);
	if (PyBool_Check(result_is_running) == false)
		return false;
	Py_DECREF(result_is_running);
	return true;
}


bool MandomController::Update()
{
	PyObject* result_update = PyObject_CallMethod(pyModule, "update", NULL);
	assert(result_update != NULL);
	Py_DECREF(result_update);
	return true;
}


int MandomController::GetPlayerLifePoint(int playerNumber)
{
	PyObject * number = PyLong_FromLong(playerNumber);
	//PyObject * player_life_point = PyObject_CallMethod(pyModule, "get_player_life_point", number);
	//assert(player_life_point != NULL);
	//Py_DECREF(player_life_point);

	return 0;
}
