#pragma once
#include "afxcmn.h"
#include "Xml.h"	// Added by ClassView
#include "Common.h"	// Added by ClassView
#include "Interface.h"	// Added by ClassView
#include "afxwin.h"
#include "QKDTimer.h"
#include "QKDDisplay.h"
// CDlgCommandSheet dialog

class CDlgCommandSheet : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgCommandSheet)

public:
	CDlgCommandSheet(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgCommandSheet();

// Dialog Data
	enum { IDD = IDD_DLGCOMMANDSHEET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListCtrlCommand;
	virtual BOOL OnInitDialog();
	CXML m_xml;
	int m_iRealCmdCnt;
	bool m_bCmdChanged;
	CMD m_CMDArray[MAXCOMMAND];
	int m_iCmdSendCnt;
	
	QKDDisplay m_display;
	QKDTimer m_Timer;
	__int64 m_lastIndirect;
	int m_iCmdStartIdx;
	__int64 GPSTimeNowday;
	CmdInfo *m_pCmdInfo[256];
	CmdInfo *m_pCmdInfo_Recv[256];
	unsigned char m_bus_flag;
	void FillNote(CMD *pCMD);
	int FindPosition(bool up_direction, int rawPosition);
	void ResortCMD(int destination, int rawPosition);
	void DisplayCmd(int index, CMD cmdBuf);
	void OnSend();
	void DeleteCmdItem(int iIdx);
	void FillCmdSendEdit(CMD *pCMD);
	void GetCMDArrayFromLog(CString fileName);
	int GetArgsByteLength(unsigned char ucID);
	void GetCMDArray(CString fileName);
	void GetCMDArrayFromXml(CString fileName);
	void GetCmdInfo(CmdInfo *m_pCmdInfo[256]);
	void AddCmdToList(CMD_WN *pCmd, int index, int bNew);
	__int64 DiffTimeAbsReletive(void);
	CString GetRelativeTime(unsigned int sec);
	CString GetDeviceName(unsigned char dev_id);
	CString GetAbsTime(unsigned int sec);
	xmlXPathObjectPtr LocateXPath(char xpath_expr[]);
	xmlXPathObjectPtr LocateCommand(unsigned char dev_id, unsigned char cmd_id);
	void InsertArgValue(unsigned char *pDst, unsigned char *pSrc, int bitStart, int length);
	double GetCoefficient(CXML *pXml, unsigned char cmd_id, int bitStart);
	void ExtractArgValue(unsigned char *pDst, unsigned char *pSrc, int bitStart, int length);
	HMSTime SecondToHMSTime(int second);
	int HMSTimeToSecond(HMSTime time);
	static DWORD WINAPI RecvGPSProc(LPVOID lpParameter);
	afx_msg void OnDblclkList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnKeydownList2(NMHDR *pNMHDR, LRESULT *pResult);
	void SendCycleCmd();
	CEdit m_pEditCmdSend;
	CEdit m_pEditCmdRecv;
	afx_msg void OnBnClickedButtonInCmd();
	afx_msg void OnBnClickedButtonOutCmd();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CListCtrl m_listMonitor;
	ULARGE_INTEGER m_base_relative;
	ULARGE_INTEGER m_base_abs;
	void SaveToPLD(CFile *pldFile);
	afx_msg void OnBnClickedOk();
	char *m_CMDBuf;
	int m_CMD_length;
	CComboBox m_ComboPort;
	void MonitorDisplay(CmdInfo *pCmdInfo, int listCurrentNum);
	void monitorini(CmdInfo *pCmdInfo[256], CListCtrl listMonitor);
	void GetCmdInfo_monitor(CmdInfo *m_pCmdInfo[256]);
	int m_MonitorCmdNum;
	int m_listCurrentNum;
	bool m_ComStatus;
	afx_msg void OnBnClickedButtonOpencom();
};