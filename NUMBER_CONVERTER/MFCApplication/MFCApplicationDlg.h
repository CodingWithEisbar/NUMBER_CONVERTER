
// MFCApplicationDlg.h : header file
//

#pragma once


// CMFCApplicationDlg dialog
class CMFCApplicationDlg : public CDialogEx
{
// Construction
public:
	CMFCApplicationDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	BOOL _check_Decimal;
	BOOL _check_Binary;
	int _bits;
private:
	int _giaTriNhapVao;
	CString _ketQuaHienThi;
public:
	afx_msg void OnBnClickedDecimal();
	afx_msg void OnBnClickedBinary();
	CStatic hienThiKetQua02;
	CStatic hienThiKetQua;
	CStatic kieuChuyenDoi;
	afx_msg void OnBnClickedUsChar();
	afx_msg void OnBnClickedSignedChar();
	afx_msg void OnBnClickedUsShort();
	afx_msg void OnBnClickedSignedShort();
	afx_msg void OnBnClickedUsInt();
	afx_msg void OnBnClickedSignedInt();
	afx_msg void OnBnClickedFloat();
	afx_msg void OnBnClickedDouble();

	afx_msg void OnBnClickedConvert();
	
};
