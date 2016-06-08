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
	PyObject *pyUpdater;
	int GetDeckSize();
	int GetDungeonSize();
	int GetTopMonsterInDeck();
	int GetHeroRemaingArmor();
	int GetPlayerVictoryPoint(int playerNumber);
	PyObject* pyGetPlayerLifePoint;
	PyObject* pyGetPlayerVictoryPoint;
	PyObject* pyGetPlayerName;
	CString GetPlayerName(int playerNumber);
	PyObject *pyGetDrawMonsterName;
	CString GetDrawMonsterName();
	CString GetBattleMonsterName();
	PyObject *pyHasPlayerPassed;
	bool HasPlayerPassed(int PlayerNumber);
	bool ActionTurnPass();
	CString GetLatestLog();
	int GetEventCount();
//	CString GetEvent();
	CString GetEvent(int idx);
	PyObject *pyGetEvent;
};

