
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




	DDX_Text(pDX, IDC_DUNGEON_MONSTER_LEFT, dungeon_monster_left);
	DDX_Text(pDX, IDC_DUNGEON_ARMOR_LEFT, dungeon_armor_left);


	DDX_Text(pDX, IDC_BATTLE_MONSTER, battle_monster);
	DDX_Text(pDX, IDC_BATTLE_DAMAGE, battle_monster_damage);
}

BEGIN_MESSAGE_MAP(CMandomOfDungeonMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDC_GROUP_DUNGEON, &CMandomOfDungeonMFCDlg::OnBnClickedGroupDungeon)
ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CMandomOfDungeonMFCDlg::OnBnClickedButtonUpdate)
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
	UpdatePlayers();
	UpdateRound();
	UpdateTurn();
	UpdateDungeon();
	UpdateBattle();

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

	player_turn_0.SetCheck(!player_turn_0.GetCheck());
	player_turn_1.SetCheck(!player_turn_1.GetCheck());
	player_turn_2.SetCheck(!player_turn_2.GetCheck());
	player_turn_3.SetCheck(!player_turn_3.GetCheck());

	player_id_0 = "player 0 id";
	player_id_1 = "player 1 id";
	player_id_2 = "player 2 id";
	player_id_3 = "player 3 id";

	player_life_point_0++;
	player_life_point_1++;
	player_life_point_2++;
	player_life_point_3++;

	player_victory_point_0++;
	player_victory_point_1++;
	player_victory_point_2++;
	player_victory_point_3++;

	UpdateData(FALSE);

	InvalidateStatic(&group_players);
}




void CMandomOfDungeonMFCDlg::UpdateRound()
{
	UpdateData();
	
	round_deck_size++;
	round_dungeon_size++;

	round_weapon_armor.EnableWindow(!round_weapon_armor.IsWindowEnabled());
	round_weapon_hero_sword.EnableWindow(!round_weapon_hero_sword.IsWindowEnabled());
	round_weapon_holy_grail.EnableWindow(!round_weapon_holy_grail.IsWindowEnabled());

	round_weapon_shield.EnableWindow(!round_weapon_shield.IsWindowEnabled());
	round_weapon_spear.EnableWindow(!round_weapon_spear.IsWindowEnabled());
	round_weapon_torch.EnableWindow(!round_weapon_torch.IsWindowEnabled());

	UpdateData(FALSE);

	InvalidateStatic(&group_round);
}



void CMandomOfDungeonMFCDlg::UpdateTurn()
{
	UpdateData();

	turn_action_pass.EnableWindow(!turn_action_pass.IsWindowEnabled());
	turn_action_draw.EnableWindow(!turn_action_draw.IsWindowEnabled());

	turn_action_add_monster.EnableWindow(!turn_action_add_monster.IsWindowEnabled());
	turn_action_remove_moster.EnableWindow(!turn_action_remove_moster.IsWindowEnabled());

	UpdateData(FALSE);

	InvalidateStatic(&group_round);
}




void CMandomOfDungeonMFCDlg::UpdateDungeon()
{
	UpdateData();

	dungeon_monster_left++;
	dungeon_armor_left++;

	UpdateData(FALSE);

	InvalidateStatic(&group_dungeon);
}


void CMandomOfDungeonMFCDlg::UpdateBattle()
{
	UpdateData();

	battle_monster = "no name";
	battle_monster_damage++;

	UpdateData(FALSE);

	InvalidateStatic(&group_battle);
}