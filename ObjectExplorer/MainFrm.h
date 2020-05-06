// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ObjectManager.h"
#include "INterfaces.h"
#include "ToolBarHelper.h"
#include "ThemeManager.h"

class CMainFrame : 
	public CFrameWindowImpl<CMainFrame>, 
	public CAutoUpdateUI<CMainFrame>,
	public CToolBarHelper<CMainFrame>,
	public IMainFrame,
	public CMessageFilter, 
	public CIdleHandler {
public:
	DECLARE_FRAME_WND_CLASS(nullptr, IDR_MAINFRAME)

	CMainFrame();
	BOOL PreTranslateMessage(MSG* pMsg) override;
	BOOL OnIdle() override;
	void OnFinalMessage(HWND) override;

	CCommandBarCtrl m_CmdBar;

	// Inherited via IMainFrame
	BOOL TrackPopupMenu(HMENU hMenu, HWND hWnd, POINT*, UINT) override;
	HIMAGELIST GetImageList() override;
	int GetIconIndexByType(PCWSTR type) const override;
	void ShowAllHandles(PCWSTR type) override;
	void ShowAllObjects(PCWSTR type) override;
	CUpdateUIBase* GetUpdateUI() override;
	ThemeManager* GetThemeManager() override;

	BEGIN_MSG_MAP(CMainFrame)
		MESSAGE_HANDLER(WM_TIMER, OnTimer)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		COMMAND_ID_HANDLER(ID_APP_EXIT, OnFileExit)
		COMMAND_ID_HANDLER(ID_VIEW_TOOLBAR, OnViewToolBar)
		COMMAND_ID_HANDLER(ID_VIEW_STATUS_BAR, OnViewStatusBar)
		COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)
		COMMAND_ID_HANDLER(ID_WINDOW_CLOSE, OnWindowClose)
		COMMAND_ID_HANDLER(ID_OBJECTS_ALLOBJECTTYPES, OnShowAllTypes)
		COMMAND_ID_HANDLER(ID_OBJECTS_ALLOBJECTS, OnViewAllObjects)
		COMMAND_ID_HANDLER(ID_HANDLES_PIPES, OnShowAllPipes)
		COMMAND_ID_HANDLER(ID_OBJECTS_MAILSLOTS, OnShowAllMailslots)
		COMMAND_ID_HANDLER(ID_HANDLES_ALLHANDLES, OnShowAllHandles)
		COMMAND_ID_HANDLER(ID_HANDLES_SHOWHANDLEINPROCESS, OnShowHandlesInProcess)
		COMMAND_ID_HANDLER(ID_SYSTEM_SERVICES, OnViewSystemServices)
		COMMAND_ID_HANDLER(ID_SYSTEM_DEVICES, OnViewSystemDevices)
		COMMAND_ID_HANDLER(ID_WINDOW_CLOSE_ALL, OnWindowCloseAll)
		COMMAND_ID_HANDLER(ID_WINDOW_CLOSEALLBUTTHIS, OnCloseAllButThis)
		COMMAND_ID_HANDLER(ID_OPTIONS_ALWAYSONTOP, OnAlwaysOnTop)
		COMMAND_ID_HANDLER(ID_OBJECTS_OBJECTMANAGER, OnShowObjectManager)
		COMMAND_ID_HANDLER(ID_DESKTOPS_ALLWINDOWS, OnShowAllWindows)
		COMMAND_ID_HANDLER(ID_FILE_RUNASADMINISTRATOR, OnRunAsAdmin)
		COMMAND_ID_HANDLER(ID_TAB_NEWWINDOW, OnNewWindow)

		COMMAND_ID_HANDLER(ID_PROCESS_MEMORYMAP, OnProcessMemoryMap)
		COMMAND_ID_HANDLER(ID_PROCESS_MODULES, OnProcessModules)
		COMMAND_ID_HANDLER(ID_PROCESS_THREADS, OnProcessThreads)

		COMMAND_ID_HANDLER(ID_GUI_ALLWINDOWSINDEFAULTDESKTOP, OnShowAllWindowsDefaultDesktop)
		COMMAND_RANGE_HANDLER(ID_WINDOW_TABFIRST, ID_WINDOW_TABLAST, OnWindowActivate)
		COMMAND_RANGE_HANDLER(ID_SHOWOBJECTSOFTYPE_PROCESS, ID_SHOWOBJECTSOFTYPE_PROCESS + 17, OnShowObjectOfType)
		COMMAND_RANGE_HANDLER(ID_SHOWHANDLESOFTYPE_PROCESS, ID_SHOWHANDLESOFTYPE_PROCESS + 17, OnShowHandlesOfType)
		COMMAND_RANGE_HANDLER(32768, 65535, OnForward)
		NOTIFY_CODE_HANDLER(TBVN_PAGEACTIVATED, OnTabActivated)
		NOTIFY_CODE_HANDLER(TBVN_CONTEXTMENU, OnTabContextMenu)
		NOTIFY_HANDLER(ATL_IDW_TOOLBAR, NM_RCLICK, OnBandRightClick)
		CHAIN_MSG_MAP(CAutoUpdateUI<CMainFrame>)
		CHAIN_MSG_MAP(CFrameWindowImpl<CMainFrame>)
		CHAIN_MSG_MAP(CToolBarHelper<CMainFrame>)
		REFLECT_NOTIFICATIONS()
	END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

private:
	LRESULT OnProcessMemoryMap(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnProcessThreads(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnProcessModules(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnNewWindow(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

	LRESULT OnTabActivated(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/);
	LRESULT OnTabContextMenu(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/);
	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnTimer(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
	LRESULT OnFileExit(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewSystemServices(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewSystemDevices(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewAllObjects(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnShowAllHandles(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnForwardMsg(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewToolBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewStatusBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnWindowClose(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnWindowCloseAll(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnCloseAllButThis(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnWindowActivate(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnShowObjectOfType(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnShowHandlesOfType(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnShowAllTypes(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnShowHandlesInProcess(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnForward(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnAlwaysOnTop(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnShowObjectManager(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnShowAllWindows(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnShowAllWindowsDefaultDesktop(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnRunAsAdmin(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBandRightClick(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/);
	LRESULT OnShowAllPipes(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnShowAllMailslots(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnDetachTab(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

private:
	void CloseAllBut(int page);
	void InitCommandBar();
	void InitToolBar(CToolBarCtrl& tb);
	bool DetachTab(int index);
	LRESULT ShowNotImplemented();

private:
	CTabView m_view;
	CMultiPaneStatusBarCtrl m_StatusBar;
	ObjectManager m_ObjMgr;
	inline static CImageListManaged m_TabImages;
	inline static std::unordered_map<std::wstring, int> m_IconMap;
	int m_CurrentPage = -1;
	inline static int m_ObjectsIcon, m_TypesIcon, m_HandlesIcon, m_ObjectManagerIcon, m_WindowsIcon, m_ServicesIcon;
	inline static int m_DevicesIcon, m_MemoryIcon;
	inline static int s_Frames;
};
