// sudokuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "sudoku.h"
#include "sudokuDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int i_1,j_1;
int i=1,j=1,i_i,j_j;
int i_txt=0;
double a[10][10];
double b[10][10];
double c[10][10];
int t,n,k=0;
int times=0;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSudokuDlg dialog

CSudokuDlg::CSudokuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSudokuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSudokuDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSudokuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSudokuDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSudokuDlg, CDialog)
	//{{AFX_MSG_MAP(CSudokuDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSudokuDlg message handlers

BOOL CSudokuDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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

void CSudokuDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSudokuDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}


	CClientDC dc(this);

	for(i_1=0;i_1<10;i_1++)
	{
		dc.MoveTo(20,20+40*i_1);
		dc.LineTo(380,20+40*i_1);
		if(i_1%3==0)
		{
			dc.MoveTo(20,20+40*i_1+1);
			dc.LineTo(380,20+40*i_1+1);
		}
	}
	for(j_1=0;j_1<10;j_1++)
	{
		dc.MoveTo(20+40*j_1,20);
		dc.LineTo(20+40*j_1,380);
		if(j_1%3==0)
		{
			dc.MoveTo(20+40*j_1+1,20);
			dc.LineTo(20+40*j_1+1,380);
		}
	}

	if(i<1)
		TextOut(dc,460,150,"нч╫Б",4);
	else
	{
	CString cs;
	for(i_1=1;i_1<10;i_1++)
	{
		for(j_1=1;j_1<10;j_1++)
		{
			if(a[i_1][j_1]!=0)
			{
				cs.Format("%.0f",a[i_1][j_1]);
				TextOut(dc,40*j_1-10,40*i_1-10,cs,cs.GetLength());
			}
		}
	}
	}

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSudokuDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSudokuDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrTitle = "OpenFile";
	fileDlg.m_ofn.lpstrFilter = "Txt(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";

	CClientDC paDC(this);
	CString strLine;

	i_txt=1;
	if(IDOK == fileDlg.DoModal())
	{
		CStdioFile file(fileDlg.GetFileName(),CFile::modeRead);
		while(file.ReadString(strLine))
		{
			//AfxMessageBox(strLine); 

			float st=atof(strLine); 
			a[(i_txt-1)/9+1][(i_txt-1)%9+1]=st;
			i_txt++;
			if(i_txt==820) break;
		}
	
		file.Close();
		Invalidate();
	}

	for(i_1=1;i_1<10;i_1++)
	{
		for(j_1=1;j_1<10;j_1++)
		{
			b[i_1][j_1]=a[i_1][j_1];
		}
	}
	for(i_1=1;i_1<10;i_1++)
	{
		for(j_1=1;j_1<10;j_1++)
		{
			c[i_1][j_1]=a[i_1][j_1];
		}
	}
	i=1;j=1;i_i=1;j_j=1;
}

void CSudokuDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here

	if( times!=0 && c[i][j]==0 ) b[i][j]--;
	times=0;
	
	i=i_i;
	j=j_j;
	for(i;i<10;i++)
	{
	//	if(j==9) j=1;
		for(j;j<10;j++)
		{
			if(c[i][j]==0)
			{
			for(t=b[i][j]+1;t<10;t++)
			{
				b[i][j]=t;
				k=0;
				for(n=0;n<9;n++)
				{
					if(k) break;
					if( b[(i-1)/3*3+1+n/3][(j-1)/3*3+1+n%3]==b[i][j] && (i-1)/3*3+1+n/3!=i && (j-1)/3*3+1+n%3!=j )
						k=1;
				}
				for(n=1;n<10;n++)
				{
					if(k) break;
					if( b[i][n]==b[i][j] && n!=j )
						k=1;
				}
				for(n=1;n<10;n++)
				{
					if(k) break;
					if( b[n][j]==b[i][j] && n!=i )
						k=1;
				}
				if(!k) break;
			}
			if( b[i][j]==9 && k!=0 )
			{
				b[i][j]=0;

				if(j==1) {i--;j=9;}
				else j--;

				while(c[i][j]!=0)
				{
					if(j==1) {i--;j=9;}
					else j--;
				}

				if(j==1) {i--;j=9;}
				else j--;
			}
			}
			times++;
			if(times==100000)
			{
				if( b[i][j]==9 && k!=0 )
				{
					if(j==9) {i++;j=1;}
					else j++;
				}
				break;
			}
		}
		if(times==100000) break;
		j=1;
	}
	i_i=i;
	j_j=j;

	for(i_1=1;i_1<10;i_1++)
	{
		for(j_1=1;j_1<10;j_1++)
		{
			a[i_1][j_1]=b[i_1][j_1];
		}
	}
	
	Invalidate();

}

void CSudokuDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	b[9][9]++;
	i_i=9;j_j=9;
	i=9;j=9;
}
