#include "stdafx.h"
#include "MandomController.h"

MandomController::MandomController()
	: pyModule(NULL)
	, pyDict(NULL)
	, pyUpdater(NULL)
	, pyGetPlayerLifePoint(NULL)
	, pyGetPlayerVictoryPoint(NULL)
	, pyGetPlayerName(NULL)
	, pyGetDrawMonsterName(NULL)
	, pyHasPlayerPassed(NULL)
{
	Py_Initialize();

	PyObject * pNameMain = PyUnicode_DecodeFSDefault("main");

	pyModule = PyImport_Import(pNameMain);
	assert(pyModule != NULL);

	pyDict = PyModule_GetDict(pyModule);
	assert(pyDict != NULL);

	pyGetPlayerLifePoint = PyDict_GetItemString(pyDict, "get_player_life_point");
	assert(pyGetPlayerLifePoint != NULL);

	pyGetPlayerVictoryPoint = PyDict_GetItemString(pyDict, "get_player_victor_point");
	assert(pyGetPlayerVictoryPoint != NULL);

	pyGetPlayerName = PyDict_GetItemString(pyDict, "get_player_name");
	assert(pyGetPlayerName != NULL);

	//pyGetDrawMonsterName = PyDict_GetItemString(pyDict, "get_draw_monster_name");
	//assert(pyGetDrawMonsterName != NULL);

	pyHasPlayerPassed = PyDict_GetItemString(pyDict, "has_player_passed");
	assert(pyHasPlayerPassed != NULL);
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
	PyObject * number = PyLong_FromLong((long) playerNumber);
	PyObject * args = PyTuple_Pack(1, number);
	PyObject * player_life_point = PyObject_CallObject(pyGetPlayerLifePoint, args);
	assert(player_life_point != NULL);
	int life = PyLong_AsLong(player_life_point);
	Py_DECREF(player_life_point);
	return life;
}
//pyGetPlayerVictoryPoint
int MandomController::GetPlayerVictoryPoint(int playerNumber)
{
	PyObject * number = PyLong_FromLong((long)playerNumber);
	PyObject * args = PyTuple_Pack(1, number);
	PyObject * player_victory_point = PyObject_CallObject(pyGetPlayerVictoryPoint, args);
	assert(player_victory_point != NULL);
	int life = PyLong_AsLong(player_victory_point);
	Py_DECREF(player_victory_point);
	return life;
}

CString MandomController::GetPlayerName(int playerNumber)
{
	PyObject * number = PyLong_FromLong((long)playerNumber);
	PyObject * args = PyTuple_Pack(1, number);
	PyObject * player_name = PyObject_CallObject(pyGetPlayerName, args);
	PyObject * utf_name = PyUnicode_AsUTF8String(player_name);
	char * name_c = PyBytes_AsString(utf_name);
	assert(player_name != NULL);
	CString name(name_c);
	Py_DECREF(player_name);
	return name;
}



int MandomController::GetDeckSize()
{
	//num_of_monster_in_deck
	PyObject * deck_size = PyObject_CallMethod(pyModule, "num_of_monster_in_deck", NULL);
	assert(deck_size != NULL);
	int size = PyLong_AsLong(deck_size);
	Py_DECREF(deck_size);
	return size;
}


int MandomController::GetDungeonSize()
{
	PyObject * dungeon_size = PyObject_CallMethod(pyModule, "num_of_monster_in_dungeon", NULL);
	assert(dungeon_size != NULL);
	int size = PyLong_AsLong(dungeon_size);
	Py_DECREF(dungeon_size);
	return size;
}

// top_monster_code_in_deck
int MandomController::GetTopMonsterInDeck()
{
	PyObject * monster_code = PyObject_CallMethod(pyModule, "top_monster_code_in_deck", NULL);
	assert(monster_code != NULL);
	int code = PyLong_AsLong(monster_code);
	Py_DECREF(monster_code);
	return code;
}

// hero_remaining_armor
int MandomController::GetHeroRemaingArmor()
{
	PyObject * hero_armor = PyObject_CallMethod(pyModule, "hero_remaining_armor", NULL);
	assert(hero_armor != NULL);
	int armor = PyLong_AsLong(hero_armor);
	Py_DECREF(hero_armor);
	return armor;
}




CString MandomController::GetDrawMonsterName()
{
	PyObject * monster_name = PyObject_CallMethod(pyModule, "get_draw_monster_name", NULL);
	PyObject * utf_name = PyUnicode_AsUTF8String(monster_name);
	char * name_c = PyBytes_AsString(utf_name);
	assert(monster_name != NULL);
	CString name(name_c);
	Py_DECREF(monster_name);
	return name;
}


CString MandomController::GetBattleMonsterName()
{
	PyObject * monster_name = PyObject_CallMethod(pyModule, "get_battle_monster_name", NULL);
	PyObject * utf_name = PyUnicode_AsUTF8String(monster_name);
	char * name_c = PyBytes_AsString(utf_name);
	assert(monster_name != NULL);
	CString name(name_c);
	Py_DECREF(monster_name);
	return name;
}


bool MandomController::HasPlayerPassed(int PlayerNumber)
{
	PyObject * number = PyLong_FromLong((long)PlayerNumber);
	PyObject * args = PyTuple_Pack(1, number);
	PyObject * player_passed = PyObject_CallObject(pyHasPlayerPassed, args);
	assert(player_passed != NULL);
	bool passed = PyBool_Check(player_passed);
	Py_DECREF(player_passed);
	return passed;
}


bool MandomController::ActionTurnPass()
{
	PyObject * turn_passed = PyObject_CallMethod(pyModule, "action_turn_pass", NULL);
	assert(turn_passed != NULL);
	bool result = PyObject_IsTrue(turn_passed);
	Py_DECREF(turn_passed);
	return result;
}
