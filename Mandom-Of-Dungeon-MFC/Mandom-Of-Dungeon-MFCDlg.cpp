
// Mandom-Of-Dungeon-MFCDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Mandom-Of-Dungeon-MFC.h"
#include "Mandom-Of-Dungeon-MFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMandomOfDungeonMFCDlg ��ȭ ����



CMandomOfDungeonMFCDlg::CMandomOfDungeonMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MANDOMOFDUNGEONMFC_DIALOG, pParent)
	, turn_draw_monster(_T(""))
	, dungeon_monster_left(0)
	, dungeon_armor_left(0)
	, battle_monster(_T(""))
	, battle_monster_damage(0)
	, mandom(NULL)
	, last_event_idx(0)
	, turn_card_opened(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	player_id_0 = _T("");
	player_id_1 = _T("");
	player_id_2 = _T("");
	player_id_3 = _T("");
	player_life_point_0 = 0;
	player_life_point_1 = 0;
	player_life_point_2 = 0;
	player_life_point_3 = 0;
	player_victory_point_0 = 0;
	player_victory_point_1 = 0;
	player_victory_point_2 = 0;
	player_victory_point_3 = 0;
	round_deck_size = 0;
	round_dungeon_size = 0;
}

void CMandomOfDungeonMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_PLAYER_ID_0, player_id_0);
	DDX_Text(pDX, IDC_PLAYER_ID_1, player_id_1);
	DDX_Text(pDX, IDC_PLAYER_ID_2, player_id_2);
	DDX_Text(pDX, IDC_PLAYER_ID_3, player_id_3);

	DDX_Text(pDX, IDC_PLAYER_LIFE_POINT_0, player_life_point_0);
	DDX_Text(pDX, IDC_PLAYER_LIFE_POINT_1, player_life_point_1);
	DDX_Text(pDX, IDC_PLAYER_LIFE_POINT_2, player_life_point_2);
	DDX_Text(pDX, IDC_PLAYER_LIFE_POINT_3, player_life_point_3);

	DDX_Text(pDX, IDC_PLAYER_VICTORY_POINT_0, player_victory_point_0);
	DDX_Text(pDX, IDC_PLAYER_VICTORY_POINT_1, player_victory_point_1);
	DDX_Text(pDX, IDC_PLAYER_VICTORY_POINT_2, player_victory_point_2);
	DDX_Text(pDX, IDC_PLAYER_VICTORY_POINT_3, player_victory_point_3);

	DDX_Control(pDX, IDC_PLAYER_TURN_0, player_turn_0);
	DDX_Control(pDX, IDC_PLAYER_TURN_1, player_turn_1);
	DDX_Control(pDX, IDC_PLAYER_TURN_2, player_turn_2);
	DDX_Control(pDX, IDC_PLAYER_TURN_3, player_turn_3);



	DDX_Control(pDX, IDC_GROUP_PLAYERS, group_players);
	DDX_Control(pDX, IDC_GROUP_ROUND, group_round);
	DDX_Control(pDX, IDC_GROUP_DUNGEON, group_dungeon);
	DDX_Control(pDX, IDC_GROUP_BATTLE, group_battle);

	DDX_Control(pDX, IDC_ROUND_WEAPON_TORCH, round_weapon_torch);
	DDX_Control(pDX, IDC_ROUND_WEAPON_HOLY_GRAIL, round_weapon_holy_grail);
	DDX_Control(pDX, IDC_ROUND_WEAPON_SPEAR, round_weapon_spear);
	DDX_Control(pDX, IDC_ROUND_WEAPON_ARMOR, round_weapon_armor);
	DDX_Control(pDX, IDC_ROUND_WEAPON_SHIELD, round_weapon_shield);
	DDX_Control(pDX, IDC_ROUND_WEAPON_HERO_SWORD, round_weapon_hero_sword);

	DDX_Text(pDX, IDC_ROUND_DECK_SIZE, round_deck_size);
	DDX_Text(pDX, IDC_ROUND_DUNGEON_SIZE, round_dungeon_size);



	DDX_Control(pDX, IDC_TURN_DRAW, turn_action_draw);
	DDX_Control(pDX, IDC_TURN_PASS, turn_action_pass);

	DDX_Control(pDX, IDC_TURN_REMOVE_MONSTER, turn_action_remove_moster);
	DDX_Control(pDX, IDC_TURN_ADD_MONSTER, turn_action_add_monster);



	DDX_Text(pDX, IDC_TRUN_DRAW_MONSTER, turn_draw_monster);

	DDX_Text(pDX, IDC_DUNGEON_MONSTER_LEFT, dungeon_monster_left);
	DDX_Text(pDX, IDC_DUNGEON_ARMOR_LEFT, dungeon_armor_left);


	DDX_Text(pDX, IDC_BATTLE_MONSTER, battle_monster);
	DDX_Text(pDX, IDC_BATTLE_DAMAGE, battle_monster_damage);

	//  DDX_Text(pDX, IDC_EDIT_EVENT_LIST, dungeon_event);
	DDX_Control(pDX, IDC_LIST_EVENT, list_box_event);
}

BEGIN_MESSAGE_MAP(CMandomOfDungeonMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDC_GROUP_DUNGEON, &CMandomOfDungeonMFCDlg::OnBnClickedGroupDungeon)
ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CMandomOfDungeonMFCDlg::OnBnClickedButtonUpdate)
ON_BN_CLICKED(IDC_TURN_PASS, &CMandomOfDungeonMFCDlg::OnBnClickedTurnPass)
ON_BN_CLICKED(IDC_TURN_DRAW, &CMandomOfDungeonMFCDlg::OnBnClickedTurnDraw)
ON_BN_CLICKED(IDC_TURN_ADD_MONSTER, &CMandomOfDungeonMFCDlg::OnBnClickedTurnAddMonster)
ON_BN_CLICKED(IDC_ROUND_WEAPON_TORCH, &CMandomOfDungeonMFCDlg::OnBnClickedRoundWeaponTorch)
ON_BN_CLICKED(IDC_ROUND_WEAPON_HOLY_GRAIL, &CMandomOfDungeonMFCDlg::OnBnClickedRoundWeaponHolyGrail)
ON_BN_CLICKED(IDC_ROUND_WEAPON_SPEAR, &CMandomOfDungeonMFCDlg::OnBnClickedRoundWeaponSpear)
ON_BN_CLICKED(IDC_ROUND_WEAPON_ARMOR, &CMandomOfDungeonMFCDlg::OnBnClickedRoundWeaponArmor)
ON_BN_CLICKED(IDC_ROUND_WEAPON_SHIELD, &CMandomOfDungeonMFCDlg::OnBnClickedRoundWeaponShield)
ON_BN_CLICKED(IDC_ROUND_WEAPON_HERO_SWORD, &CMandomOfDungeonMFCDlg::OnBnClickedRoundWeaponHeroSword)
END_MESSAGE_MAP()


// CMandomOfDungeonMFCDlg �޽��� ó����

BOOL CMandomOfDungeonMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	this->mandom = new MandomController();
	mandom->StartGame();
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CMandomOfDungeonMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMandomOfDungeonMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMandomOfDungeonMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMandomOfDungeonMFCDlg::OnBnClickedButtonUpdate()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (mandom->IsRunning())
	{
		UpdateAll();
	}


}
void CMandomOfDungeonMFCDlg::InvalidateStatic(CStatic * pStatic)
{
	CRect rect;
	pStatic->GetWindowRect(&rect);

	CPoint & pointTopLeft = rect.TopLeft();
	CPoint & pointBottomRight = rect.BottomRight();
	ScreenToClient(&pointTopLeft);
	ScreenToClient(&pointBottomRight);

	InvalidateRect(rect);
}

void CMandomOfDungeonMFCDlg::UpdatePlayers()
{
	UpdateData();

	player_turn_0.SetCheck(!mandom->HasPlayerPassed(0));
	player_turn_1.SetCheck(!mandom->HasPlayerPassed(1));
	player_turn_2.SetCheck(!mandom->HasPlayerPassed(2));
	player_turn_3.SetCheck(!mandom->HasPlayerPassed(3));
		/*
	player_turn_0.SetCheck(!player_turn_0.GetCheck());
	player_turn_1.SetCheck(!player_turn_1.GetCheck());
	player_turn_2.SetCheck(!player_turn_2.GetCheck());
	player_turn_3.SetCheck(!player_turn_3.GetCheck());
	*/

	player_id_0 = mandom->GetPlayerName(0);
	player_id_1 = mandom->GetPlayerName(1);
	player_id_2 = mandom->GetPlayerName(2);
	player_id_3 = mandom->GetPlayerName(3);

	player_life_point_0 = mandom->GetPlayerLifePoint(0);
	player_life_point_1 = mandom->GetPlayerLifePoint(1);
	player_life_point_2 = mandom->GetPlayerLifePoint(2);
	player_life_point_3 = mandom->GetPlayerLifePoint(3);
	
	player_victory_point_0 = mandom->GetPlayerVictoryPoint(0);
	player_victory_point_1 = mandom->GetPlayerVictoryPoint(1);
	player_victory_point_2 = mandom->GetPlayerVictoryPoint(2);
	player_victory_point_3 = mandom->GetPlayerVictoryPoint(3);

	UpdateData(FALSE);

	InvalidateStatic(&group_players);
}




void CMandomOfDungeonMFCDlg::UpdateRound()
{
	UpdateData();
	
	round_deck_size = mandom->GetDeckSize();
	round_dungeon_size = mandom->GetDungeonSize();

	round_weapon_torch.EnableWindow(mandom->HasWeapon(0));
	round_weapon_holy_grail.EnableWindow(mandom->HasWeapon(1));
	round_weapon_spear.EnableWindow(mandom->HasWeapon(2));
	round_weapon_armor.EnableWindow(mandom->HasWeapon(3));
	round_weapon_shield.EnableWindow(mandom->HasWeapon(4));
	round_weapon_hero_sword.EnableWindow(mandom->HasWeapon(5));

	UpdateData(FALSE);

	InvalidateStatic(&group_round);
}



void CMandomOfDungeonMFCDlg::UpdateTurn()
{
	UpdateData();
	if (turn_card_opened)
	{
		turn_draw_monster = mandom->GetDrawMonsterName();
	}
	else
	{
		turn_draw_monster = "";
	}
	/*
	turn_action_pass.EnableWindow(!turn_action_pass.IsWindowEnabled());
	turn_action_draw.EnableWindow(!turn_action_draw.IsWindowEnabled());

	turn_action_add_monster.EnableWindow(!turn_action_add_monster.IsWindowEnabled());
	turn_action_remove_moster.EnableWindow(!turn_action_remove_moster.IsWindowEnabled());
	*/
	UpdateData(FALSE);

	InvalidateStatic(&group_round);
}




void CMandomOfDungeonMFCDlg::UpdateDungeon()
{
	UpdateData();

	dungeon_monster_left = mandom->GetDungeonSize();
	dungeon_armor_left = mandom->GetHeroRemaingArmor();

	UpdateData(FALSE);

	InvalidateStatic(&group_dungeon);
}


void CMandomOfDungeonMFCDlg::UpdateBattle()
{
	UpdateData();

	battle_monster = mandom->GetBattleMonsterName();
	battle_monster_damage++;

	UpdateData(FALSE);

	InvalidateStatic(&group_battle);
}

//void CMandomOfDungeonMFCDlg::UpdateEvent()
//{
//	UpdateData();
//	dungeon_event += "event xxx aaa bbb\n";
//	UpdateData(FALSE);
//	Invalidate();
//}

void CMandomOfDungeonMFCDlg::UpdateEventList()
{
	if (last_event_idx < mandom->GetEventCount())
	{
		int i = 0;
		for ( i = last_event_idx; i < mandom->GetEventCount(); i++)
		{
			CString new_event_str = mandom->GetEvent(i);
			list_box_event.AddString(new_event_str);
		}
		last_event_idx = i;
		Invalidate();
	}

}


void CMandomOfDungeonMFCDlg::OnBnClickedTurnPass()
{
	if (mandom->ActionTurnPass())
	{
		UpdateAll();
	}
}


void CMandomOfDungeonMFCDlg::UpdateAll()
{
	mandom->Update();
	UpdatePlayers();
	UpdateRound();
	UpdateTurn();
	UpdateDungeon();
	UpdateBattle();
	UpdateEventList();
	Invalidate();
}


void CMandomOfDungeonMFCDlg::OnBnClickedTurnDraw()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	turn_card_opened = true;
	UpdateAll();
}


void CMandomOfDungeonMFCDlg::OnBnClickedTurnAddMonster()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (mandom->ActionTurnMonsterAddToDungeon())
	{
		turn_card_opened = false;
		UpdateAll();
	}
}


void CMandomOfDungeonMFCDlg::OnBnClickedRoundWeaponTorch()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (mandom->ActionTurnWeaponRemove(0))
	{
		turn_card_opened = false;
		UpdateAll();
	}
}


void CMandomOfDungeonMFCDlg::OnBnClickedRoundWeaponHolyGrail()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (mandom->ActionTurnWeaponRemove(1))
	{
		turn_card_opened = false;
		UpdateAll();
	}
}


void CMandomOfDungeonMFCDlg::OnBnClickedRoundWeaponSpear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (mandom->ActionTurnWeaponRemove(2))
	{
		turn_card_opened = false;
		UpdateAll();
	}
}


void CMandomOfDungeonMFCDlg::OnBnClickedRoundWeaponArmor()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (mandom->ActionTurnWeaponRemove(3))
	{
		turn_card_opened = false;
		UpdateAll();
	}
}


void CMandomOfDungeonMFCDlg::OnBnClickedRoundWeaponShield()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (mandom->ActionTurnWeaponRemove(4))
	{
		turn_card_opened = false;
		UpdateAll();
	}
}


void CMandomOfDungeonMFCDlg::OnBnClickedRoundWeaponHeroSword()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (mandom->ActionTurnWeaponRemove(5))
	{
		turn_card_opened = false;
		UpdateAll();
	}
}
