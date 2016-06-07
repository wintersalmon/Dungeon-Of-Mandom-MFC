
// Mandom-Of-Dungeon-MFCDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"


// CMandomOfDungeonMFCDlg 대화 상자
class CMandomOfDungeonMFCDlg : public CDialogEx
{
// 생성입니다.
public:
	CMandomOfDungeonMFCDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MANDOMOFDUNGEONMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedGroupDungeon();
	CString player_id_0;
	CString player_id_1;
	CString player_id_2;
	CString player_id_3;
	int player_life_point_0;
	int player_life_point_1;
	int player_life_point_2;
	int player_life_point_3;
	int player_victory_point_0;
	int player_victory_point_1;
	int player_victory_point_2;
	int player_victory_point_3;
	afx_msg void OnBnClickedButtonUpdate();
	void UpdatePlayers();
	void InvalidateStatic(CStatic * pStatic);
	CStatic group_players;
	CStatic group_round;
	CStatic group_dungeon;
	CStatic group_battle;
	void UpdateRound();
	void UpdateDungeon();
	void UpdateBattle();
//	bool player_turn_0;
//	bool player_turn_1;
//	bool player_turn_2;
//	bool player_turn_3;
	CButton player_turn_0;
	CButton player_turn_1;
	CButton player_turn_2;
	CButton player_turn_3;
	int round_deck_size;
	int round_dungeon_size;
	CButton round_weapon_torch;
	CButton round_weapon_holy_grail;
	CButton round_weapon_spear;
	CButton round_weapon_armor;
	CButton round_weapon_shield;
	CButton round_weapon_hero_sword;
	CString turn_draw_monster;
	CButton turn_action_draw;
	CButton turn_action_pass;
	CButton turn_action_remove_moster;
	CButton turn_action_add_monster;
	int dungeon_monster_left;
	int dungeon_armor_left;
	CString battle_monster;
	int battle_monster_damage;
	void UpdateTurn();
//	void UpdateEvent();
//	CString dungeon_event;
	CListBox list_box_event;
	void UpdateEventList();
};
