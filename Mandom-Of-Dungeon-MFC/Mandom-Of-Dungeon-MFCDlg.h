
// Mandom-Of-Dungeon-MFCDlg.h : ��� ����
//

#pragma once


// CMandomOfDungeonMFCDlg ��ȭ ����
class CMandomOfDungeonMFCDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMandomOfDungeonMFCDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MANDOMOFDUNGEONMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
