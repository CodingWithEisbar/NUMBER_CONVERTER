
// MFCApplicationDlg.cpp : implementation file
//

#include <string>
#include <sstream>
#include "pch.h"
#include "integer.h"
#include "binary.h"
#include "ieee754.h"
#include "framework.h"
#include "MFCApplication.h"
#include "MFCApplicationDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CMFCApplicationDlg dialog



CMFCApplicationDlg::CMFCApplicationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION_DIALOG, pParent)
	, _check_Decimal(FALSE)
	, _check_Binary(FALSE)
	, _giaTriNhapVao(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplicationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_NHAP_VAO, _giaTriNhapVao);
	DDX_Check(pDX, IDC_BUTTON_DECIMAL, _check_Decimal);
	DDX_Check(pDX, IDC_BUTTON_BINARY, _check_Binary);
	/*DDX_Control(pDX, IDC_BINARY, hienThiKetQua);*/
	DDX_Control(pDX, IDC_CONVRT_TYPE2, kieuChuyenDoi);
	DDX_Control(pDX, IDC_KETQUA, hienThiKetQua02);

	DDX_Control(pDX, IDC_INSERT_TYPE, kieuDuLieuNhapVao);
}

BEGIN_MESSAGE_MAP(CMFCApplicationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	/*ON_BN_CLICKED(IDC_DECIMAL, &CMFCApplicationDlg::OnBnClickedDecimal)
	ON_BN_CLICKED(IDC_BINARY, &CMFCApplicationDlg::OnBnClickedBinary)*/
	ON_BN_CLICKED(IDC_US_CHAR, &CMFCApplicationDlg::OnBnClickedUsChar)
	ON_BN_CLICKED(IDC_SIGNED_CHAR, &CMFCApplicationDlg::OnBnClickedSignedChar)
	ON_BN_CLICKED(IDC_US_SHORT, &CMFCApplicationDlg::OnBnClickedUsShort)
	ON_BN_CLICKED(IDC_SIGNED_SHORT, &CMFCApplicationDlg::OnBnClickedSignedShort)
	ON_BN_CLICKED(IDC_US_INT, &CMFCApplicationDlg::OnBnClickedUsInt)
	ON_BN_CLICKED(IDC_SIGNED_INT, &CMFCApplicationDlg::OnBnClickedSignedInt)
	ON_BN_CLICKED(IDC_FLOAT, &CMFCApplicationDlg::OnBnClickedFloat)
	ON_BN_CLICKED(IDC_DOUBLE, &CMFCApplicationDlg::OnBnClickedDouble)
	
	ON_BN_CLICKED(IDC_CONVERT, &CMFCApplicationDlg::OnBnClickedConvert)
	
	ON_BN_CLICKED(IDC_BUTTON_BINARY, &CMFCApplicationDlg::OnBnClickedButtonBinary)
	ON_BN_CLICKED(IDC_BUTTON_DECIMAL, &CMFCApplicationDlg::OnBnClickedButtonDecimal)
END_MESSAGE_MAP()


// CMFCApplicationDlg message handlers

BOOL CMFCApplicationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplicationDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplicationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplicationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




// Xử lý thao tác chọn trên Windows
//void CMFCApplicationDlg::OnBnClickedDecimal()
//{
//	_check_Decimal = true;
//	_check_Binary = false;
//}
//
//void CMFCApplicationDlg::OnBnClickedBinary()
//{
//	_check_Binary = true;
//	_check_Decimal = false;
//}

void CMFCApplicationDlg::OnBnClickedButtonBinary()
{
	std::string convert_type = "Binary";
	CString hien_thi(convert_type.c_str());
	kieuDuLieuNhapVao.SetWindowText(hien_thi);

	_check_Binary = true;
	_check_Decimal = false;
}


void CMFCApplicationDlg::OnBnClickedButtonDecimal()
{
	std::string convert_type = "Decimal";
	CString hien_thi(convert_type.c_str());
	kieuDuLieuNhapVao.SetWindowText(hien_thi);

	_check_Decimal = true;
	_check_Binary = false;
}



void CMFCApplicationDlg::OnBnClickedUsChar()
{
	//Xử lý hiển thị kiểu chuyển đổi ra màn hình Windows
	std::string convert_type = "Unsigned Char";
	CString hien_thi(convert_type.c_str());
	kieuChuyenDoi.SetWindowText(hien_thi);

	//Xử lý giá trị nhập vào
	CString str;
	GetDlgItemText(IDC_NHAP_VAO, str);
	_giaTriNhapVao = _wtoi(str);

	//Kiểm tra kiểu nhập vào và tiến hành chuyển đổi
	if (_check_Binary) {
		integer inte;
		binary bin;
		std::string value_catch = std::to_string(_giaTriNhapVao);
		if (value_catch.size() > 8) {
			MessageBox(_T("Giá trị nhập vào vượt quá 8-bits"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
		std::string buildBinary = bin.build_binary(value_catch, 8);
		unsigned int result = inte.binary_to_unsigned_int(buildBinary,8);
		_ketQuaHienThi.Format(L"%u", result);
		hienThiKetQua02.SetWindowText(_ketQuaHienThi);

	}
	else if (_check_Decimal) {
		integer inte;
		binary bin;
		std::string value_catch = inte.unsigned_int_to_binary(_giaTriNhapVao,8);
		std::string result = bin.format(value_catch);
		CString hien_thi(result.c_str());

		hienThiKetQua02.SetWindowText(hien_thi);
	}
	

}


void CMFCApplicationDlg::OnBnClickedSignedChar()
{
	//Xử lý hiển thị kiểu chuyển đổi ra màn hình Windows
	std::string convert_type = "Signed Char";
	CString hien_thi(convert_type.c_str());
	kieuChuyenDoi.SetWindowText(hien_thi);

	//Xử lý giá trị nhập vào
	CString str;
	GetDlgItemText(IDC_NHAP_VAO, str);
	_giaTriNhapVao = _wtoi(str);

	//Kiểm tra kiểu nhập vào và tiến hành chuyển đổi
	if (_check_Binary) {
		integer inte;
		binary bin;
		std::string value_catch = std::to_string(_giaTriNhapVao);
		if (value_catch.size() > 8) {
			MessageBox(_T("Giá trị nhập vào vượt quá 8-bits"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
		std::string buildBinary = bin.build_binary(value_catch, 8);
		int8_t result = inte.binary_to_char(buildBinary);
		_ketQuaHienThi.Format(L"%d", result);
		hienThiKetQua02.SetWindowText(_ketQuaHienThi);

	}
	else if (_check_Decimal) {
		integer inte;
		binary bin;
		std::string value_catch = inte.char_to_binary(_giaTriNhapVao);
		std::string result = bin.format(value_catch);
		CString hien_thi(result.c_str());

		hienThiKetQua02.SetWindowText(hien_thi);
	}

}

void CMFCApplicationDlg::OnBnClickedUsShort()
{
	//Xử lý hiển thị kiểu chuyển đổi ra màn hình Windows
	std::string convert_type = "Unsigned Short";
	CString hien_thi(convert_type.c_str());
	kieuChuyenDoi.SetWindowText(hien_thi);

	//Xử lý giá trị nhập vào
	CString str;
	GetDlgItemText(IDC_NHAP_VAO, str);
	_giaTriNhapVao = _wtoi(str);

	//Kiểm tra kiểu nhập vào và tiến hành chuyển đổi
	if (_check_Binary) {
		integer inte;
		binary bin;
		std::string value_catch = std::to_string(_giaTriNhapVao);
		if (value_catch.size() > 16) {
			MessageBox(_T("Giá trị nhập vào vượt quá 16-bits"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
		std::string buildBinary = bin.build_binary(value_catch, 16);
		unsigned int result = inte.binary_to_unsigned_int(buildBinary, 16);
		_ketQuaHienThi.Format(L"%hu", result);
		hienThiKetQua02.SetWindowText(_ketQuaHienThi);

	}
	else if (_check_Decimal) {
		integer inte;
		binary bin;
		std::string value_catch = inte.unsigned_int_to_binary(_giaTriNhapVao, 8);
		std::string result = bin.format(value_catch);
		CString hien_thi(result.c_str());

		hienThiKetQua02.SetWindowText(hien_thi);
	}

}


void CMFCApplicationDlg::OnBnClickedSignedShort()
{
	//Xử lý hiển thị kiểu chuyển đổi ra màn hình Windows
	std::string convert_type = "Signed Short";
	CString hien_thi(convert_type.c_str());
	kieuChuyenDoi.SetWindowText(hien_thi);

	//Xử lý giá trị nhập vào
	CString str;
	GetDlgItemText(IDC_NHAP_VAO, str);
	_giaTriNhapVao = _wtoi(str);

	//Kiểm tra kiểu nhập vào và tiến hành chuyển đổi
	if (_check_Binary) {
		integer inte;
		binary bin;
		std::string value_catch = std::to_string(_giaTriNhapVao);
		if (value_catch.size() > 16) {
			MessageBox(_T("Giá trị nhập vào vượt quá 16-bits"), _T("Error"), MB_ICONERROR | MB_OK);
			return;
		}
		std::string buildBinary = bin.build_binary(value_catch, 16);
		int16_t result = inte.binary_to_short(buildBinary);
		_ketQuaHienThi.Format(L"%hd", result);
		hienThiKetQua02.SetWindowText(_ketQuaHienThi);

	}
	else if (_check_Decimal) {
		integer inte;
		binary bin;
		std::string value_catch = inte.short_to_binary(_giaTriNhapVao);
		std::string result = bin.format(value_catch);
		CString hien_thi(result.c_str());

		hienThiKetQua02.SetWindowText(hien_thi);
	}


}


void CMFCApplicationDlg::OnBnClickedUsInt()
{
	//Xử lý hiển thị kiểu chuyển đổi ra màn hình Windows
	std::string convert_type = "Unsigned Int";
	CString hien_thi(convert_type.c_str());
	kieuChuyenDoi.SetWindowText(hien_thi);
	//Xử lý giá trị nhập vào
	CString str;
	GetDlgItemText(IDC_NHAP_VAO, str);
	_giaTriNhapVao = _wtoi(str);

	//Kiểm tra kiểu nhập vào và tiến hành chuyển đổi
	if (_check_Binary) {
		integer inte;
		binary bin;
		std::string value_catch = std::to_string(_giaTriNhapVao);
		std::string buildBinary = bin.build_binary(value_catch, 32);
		unsigned int result = inte.binary_to_unsigned_int(buildBinary, 32);
		_ketQuaHienThi.Format(L"%u", result);
		hienThiKetQua02.SetWindowText(_ketQuaHienThi);

	}
	else if (_check_Decimal) {
		integer inte;
		binary bin;
		std::string value_catch = inte.unsigned_int_to_binary(_giaTriNhapVao,32);
		std::string result = bin.format(value_catch);
		CString hien_thi(result.c_str());
		
		hienThiKetQua02.SetWindowText(hien_thi);
	}

}


void CMFCApplicationDlg::OnBnClickedSignedInt()
{
	//Xử lý hiển thị kiểu chuyển đổi ra màn hình Windows
	std::string convert_type = "Signed Int";
	CString hien_thi(convert_type.c_str());
	kieuChuyenDoi.SetWindowText(hien_thi);

	//Xử lý giá trị nhập vào
	CString str;
	GetDlgItemText(IDC_NHAP_VAO, str);
	_giaTriNhapVao = _wtoi(str);

	//Kiểm tra kiểu nhập vào và tiến hành chuyển đổi
	if (_check_Binary) {
		integer inte;
		binary bin;
		std::string value_catch = std::to_string(_giaTriNhapVao);
		std::string buildBinary = bin.build_binary(value_catch, 32);
		unsigned int result = inte.binary_to_integer(buildBinary);
		_ketQuaHienThi.Format(L"%d", result); //CString _ketQuaHienThi
		hienThiKetQua02.SetWindowText(_ketQuaHienThi);

	}
	else if (_check_Decimal) {
		integer inte;
		binary bin;
		std::string value_catch = inte.integer_to_binary(_giaTriNhapVao);
		std::string result = bin.format(value_catch);
		CString hien_thi(result.c_str());
		
		hienThiKetQua02.SetWindowText(hien_thi);
	}

}

//Giá trị kiểm tra: 01000100111111001010000010100100
void CMFCApplicationDlg::OnBnClickedFloat()
{
	//Xử lý hiển thị kiểu chuyển đổi ra màn hình Windows
	std::string convert_type = "Float";
	CString hien_thi(convert_type.c_str());
	kieuChuyenDoi.SetWindowText(hien_thi);

	//Xử lý giá trị nhập vào
	CString Cstr;
	GetDlgItemText(IDC_NHAP_VAO, Cstr);
	GetDlgItemText(IDC_NHAP_VAO, Cstr);
	CT2CA pszConvertedAnsiString(Cstr);
	std::string input(pszConvertedAnsiString);//bin
	float giaTriNhapVao = _ttof(Cstr); //decimal

	//Kiểm tra kiểu nhập vào và tiến hành chuyển đổi
	if (_check_Binary) {
		ieee754 double_float;
		binary bin;
		std::string buildBinary = bin.build_binary(input, 32); //set thêm số 0
		float result = double_float.binary_to_float(buildBinary);
		if (result == INFINITY) {
			std::wstring error = L"Không thể hiển thị kết quả!!";
			CString show_error(error.c_str());
			hienThiKetQua02.SetWindowText(show_error);
		}
		else {
			_ketQuaHienThi.Format(_T("%0.18lf"), result);
			hienThiKetQua02.SetWindowText(_ketQuaHienThi);
		}

	}
	else if (_check_Decimal) {
		ieee754 double_float;
		binary bin;
		std::string value_catch = double_float.float_to_binary(giaTriNhapVao);
		std::string result = bin.format(value_catch);
		CString hien_thi(result.c_str());

		hienThiKetQua02.SetWindowText(hien_thi);
	}

}


void CMFCApplicationDlg::OnBnClickedDouble()
{
	//Xử lý hiển thị kiểu chuyển đổi ra màn hình Windows
	std::string convert_type = "Double";
	CString hien_thi(convert_type.c_str());
	kieuChuyenDoi.SetWindowText(hien_thi);

	//Xử lý giá trị nhập vào
	CString Cstr;
	GetDlgItemText(IDC_NHAP_VAO, Cstr);
	CT2CA pszConvertedAnsiString(Cstr);
	std::string input(pszConvertedAnsiString);
	double giaTriNhapVao = _ttof(Cstr);

	//Kiểm tra kiểu nhập vào và tiến hành chuyển đổi
	if (_check_Binary) {
		ieee754 double_float;
		binary bin;
		std::string buildBinary = bin.build_binary(input, 64);
		double result = double_float.binary_to_double(buildBinary);
		if (result == INFINITY) {
			std::wstring error = L"Không thể hiển thị kết quả!!";
			CString show_error(error.c_str());
			hienThiKetQua02.SetWindowText(show_error);
		}
		else {
			_ketQuaHienThi.Format(_T("%0.18lf"), result);
			hienThiKetQua02.SetWindowText(_ketQuaHienThi);
		}

	}
	else if (_check_Decimal) {
		ieee754 double_float;
		binary bin;
		std::string value_catch = double_float.double_to_binary(giaTriNhapVao);
		std::string result = bin.format(value_catch);
		CString hien_thi(result.c_str());

		hienThiKetQua02.SetWindowText(hien_thi);
	}
}


void CMFCApplicationDlg::OnBnClickedConvert()
{
	//Reset biến
	_giaTriNhapVao = 0;
	_bits = 0;
	std::string reset_edit_box = "";
	CString reset_EB(reset_edit_box.c_str());
	GetDlgItem(IDC_NHAP_VAO)->SetWindowText(reset_EB);
	//Reset kiểu dữ liệu
	std::string convert_type = "";
	CString hien_thi_kieu_du_lieu(convert_type.c_str());
	kieuChuyenDoi.SetWindowText(hien_thi_kieu_du_lieu);

	//Reset màn hình kết quả
	std::string res_show = "";
	CString reset_ket_qua(res_show.c_str());
	hienThiKetQua02.SetWindowText(reset_ket_qua);
}




