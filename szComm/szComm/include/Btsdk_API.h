/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* Copyright (c) 1999-2007 IVT Corporation
*
* All rights reserved.
* 
---------------------------------------------------------------------------*/
 
/////////////////////////////////////////////////////////////////////////////
// Module Name:
//     SDK_API.h
// Abstract:
//     This module defines exported BlueSoleil SDK API prototypes. 
// Usage:
//     #include "SDK_API.h"
// 
// Author://     
//     
// Revision History:
//     2007-12-25		Created
// 
/////////////////////////////////////////////////////////////////////////////



#ifndef _BTSDK_API_H
#define _BTSDK_API_H
extern "C" {

/*************** Function Prototype ******************/

/* Initialization and Termination */
typedef void Func_ReceiveBluetoothStatusInfo(ULONG usMsgType, ULONG pulData, ULONG param, BTUINT8 *arg);
BTINT32 Btsdk_Init(void);
BTINT32 Btsdk_Done(void);
BTBOOL Btsdk_IsSDKInitialized(void);
BTBOOL Btsdk_IsServerConnected();
BTINT32	Btsdk_RegisterGetStatusInfoCB4ThirdParty(Func_ReceiveBluetoothStatusInfo* statusCBK);
BTINT32 Btsdk_RegisterCallback4ThirdParty(BtSdkCallbackStru* call_back);
BTINT32 Btsdk_RegisterCallbackEx(BtSdkCallbackStru* call_back, DWORD priority);
BTINT32 Btsdk_RegisterCallback(BtSdkCallbackStru* call_back);
BTINT32	Btsdk_SetStatusInfoFlag(USHORT usMsgType);


/* Memory Management */
void *Btsdk_MallocMemory(BTUINT32 size);
void Btsdk_FreeMemory(void *memblock);

/* Local Bluetooth Device Initialization */
BTINT32 Btsdk_StartBluetooth(void);
BTINT32 Btsdk_StopBluetooth(void);
BTBOOL Btsdk_IsBluetoothReady(void);
BTBOOL Btsdk_IsBluetoothHardwareExisted();

/* Local Device Mode */
BTINT32 Btsdk_SetDiscoveryMode(BTUINT16 mode);
BTINT32 Btsdk_GetDiscoveryMode(BTUINT16 *mode);

/* Local Device Information */
BTINT32 Btsdk_GetLocalDeviceAddress(BTUINT8 *bd_addr);
BTINT32 Btsdk_SetLocalName(BTUINT8* name, BTUINT16 len);
BTINT32 Btsdk_GetLocalName(BTUINT8* name, BTUINT16 *len);
BTINT32 Btsdk_SetLocalDeviceClass(BTUINT32 device_class);
BTINT32 Btsdk_GetLocalDeviceClass(BTUINT32 *device_class);
BTINT32 Btsdk_GetLocalLMPInfo(BtSdkLocalLMPInfoStru *lmp_info);
BTINT32 Btsdk_SetFixedPinCode(BTUINT8 *pin_code, BTUINT16 size);
BTINT32 Btsdk_GetFixedPinCode(BTUINT8 *pin_code, BTUINT16 *psize);

/* Local Device Application Extension */
BTINT32 Btsdk_VendorCommand(BTUINT32 ev_flag, PBtSdkVendorCmdStru in_cmd, PBtSdkEventParamStru out_ev);
BTUINT32 Btsdk_EnumAVDriver();
void Btsdk_DeEnumAVDriver();
BTINT32 Btsdk_ActivateEx(const BTINT8 *pszSN, BTINT32 iSnlen);

/* Remote Device Discovery */
FUNC_EXPORT BTINT32 Btsdk_StartDeviceDiscovery(BTUINT32 device_class, BTUINT16 max_num, BTUINT16 max_seconds);
typedef void  (Btsdk_Inquiry_Result_Ind_Func)(BTDEVHDL dev_hdl);
typedef void  (Btsdk_Inquiry_Complete_Ind_Func)(void);
FUNC_EXPORT BTINT32 Btsdk_StopDeviceDiscovery(void);
FUNC_EXPORT BTINT32 Btsdk_UpdateRemoteDeviceName(BTDEVHDL dev_hdl, BTUINT8 *name, BTUINT16 *plen);
FUNC_EXPORT BTINT32 Btsdk_CancelUpdateRemoteDeviceName(BTDEVHDL dev_hdl);
FUNC_EXPORT BTINT32 Btsdk_LinkKeyReply(BTDEVHDL dev_hdl, BTUINT8* link_key);

/* Device Pairing */
FUNC_EXPORT BTINT32 Btsdk_IsDevicePaired(BTDEVHDL dev_hdl, BTBOOL *pis_paired);
FUNC_EXPORT BTINT32 Btsdk_PairDevice(BTDEVHDL dev_hdl);
FUNC_EXPORT BTINT32 Btsdk_UnPairDevice(BTDEVHDL dev_hdl);
FUNC_EXPORT BTINT32 Btsdk_PinCodeReply(BTDEVHDL dev_hdl, BTUINT8* pin_code, BTUINT16 size);
FUNC_EXPORT BTUINT32 Btsdk_AuthorizationResponse(BTSVCHDL svc_hdl, BTDEVHDL dev_hdl, BTUINT16 author_result);

/* Callback Prototype */
typedef BTUINT8  (Btsdk_UserHandle_Pin_Req_Ind_Func)(BTDEVHDL dev_hdl);
typedef BTUINT8  (Btsdk_UserHandle_Authorization_Req_Ind_Func)(BTSVCHDL svc_hdl, BTDEVHDL dev_hdl);
typedef void  (Btsdk_Link_Key_Notif_Ind_Func)(BTDEVHDL dev_hdl, BTUINT8 *link_key);
typedef void  (Btsdk_Authentication_Fail_Ind_Func)(BTDEVHDL dev_hdl);

/* Link Management */
FUNC_EXPORT BTBOOL Btsdk_IsDeviceConnected(BTDEVHDL dev_hdl);
FUNC_EXPORT BTINT32 Btsdk_GetRemoteDeviceRole(BTDEVHDL dev_hdl, BTUINT16 *prole);
FUNC_EXPORT BTINT32 Btsdk_GetRemoteLMPInfo(BTDEVHDL dev_hdl, BtSdkRemoteLMPInfoStru *info);
FUNC_EXPORT BTINT32 Btsdk_GetRemoteRSSI(BTDEVHDL dev_hdl, BTINT8* prssi);
FUNC_EXPORT BTINT32 Btsdk_GetRemoteLinkQuality(BTDEVHDL dev_hdl, BTUINT16 *plink_quality);
FUNC_EXPORT BTINT32 Btsdk_GetSupervisionTimeout(BTDEVHDL dev_hdl, BTUINT16 *ptimeout);
FUNC_EXPORT BTINT32 Btsdk_SetSupervisionTimeout(BTDEVHDL dev_hdl, BTUINT16 timeout);
FUNC_EXPORT BTINT32 Btsdk_ChangeConnectionPacketType(BTDEVHDL dev_hdl, BTUINT16 packet_type);

/* Remote Device Database Management */
FUNC_EXPORT BTDEVHDL Btsdk_GetRemoteDeviceHandle(BTUINT8 *bd_addr);
FUNC_EXPORT BTDEVHDL Btsdk_AddRemoteDevice(BTUINT8 *bd_addr);
FUNC_EXPORT BTINT32 Btsdk_DeleteRemoteDeviceByHandle(BTDEVHDL dev_hdl);
FUNC_EXPORT BTINT32 Btsdk_DeleteUnpairedDevicesByClass(BTUINT32 device_class);
FUNC_EXPORT BTUINT32 Btsdk_GetStoredDevicesByClass(BTUINT32 dev_class, BTDEVHDL *pdev_hdl, BTUINT32 max_dev_num);
FUNC_EXPORT BTUINT32 Btsdk_GetInquiredDevices(BTDEVHDL *pdev_hdl, BTUINT32 max_dev_num);
FUNC_EXPORT BTUINT32 Btsdk_GetPairedDevices(BTDEVHDL *pdev_hdl, BTUINT32 max_dev_num);
FUNC_EXPORT BTSDKHANDLE Btsdk_StartEnumRemoteDevice(BTUINT32 flag, BTUINT32 dev_class);
FUNC_EXPORT BTDEVHDL Btsdk_EnumRemoteDevice(BTSDKHANDLE enum_handle, PBtSdkRemoteDevicePropertyStru rmt_dev_prop);
FUNC_EXPORT BTINT32 Btsdk_EndEnumRemoteDevice(BTSDKHANDLE enum_handle);
FUNC_EXPORT BTINT32 Btsdk_GetRemoteDeviceAddress(BTDEVHDL dev_hdl, BTUINT8 *bd_addr);
FUNC_EXPORT BTINT32 Btsdk_GetRemoteDeviceName(BTDEVHDL dev_hdl, BTUINT8 *name, BTUINT16 *plen);
FUNC_EXPORT BTINT32 Btsdk_GetRemoteDeviceClass(BTDEVHDL dev_hdl, BTUINT32 *pdevice_class);
FUNC_EXPORT BTINT32 Btsdk_GetRemoteDeviceProperty(BTDEVHDL dev_hdl, PBtSdkRemoteDevicePropertyStru rmt_dev_prop);
FUNC_EXPORT BTINT32 Btsdk_RemoteDeviceFlowStatistic(BTDEVHDL dev_hdl, BTUINT32* rx_bytes, BTUINT32* tx_bytes);

/* Service Discovery */
BTINT32 Btsdk_BrowseRemoteServicesEx(BTDEVHDL dev_hdl, PBtSdkSDPSearchPatternStru psch_ptn, BTUINT32 ptn_num, BTSVCHDL *svc_hdl, BTUINT32 *svc_count);
BTINT32 Btsdk_BrowseRemoteServices(BTDEVHDL dev_hdl, BTSVCHDL *svc_hdl, BTUINT32 *svc_count);
BTINT32 Btsdk_RefreshRemoteServiceAttributes(BTSVCHDL svc_hdl, BtSdkRemoteServiceAttrStru *attribute);
BTINT32 Btsdk_GetRemoteServicesEx(BTDEVHDL dev_hdl, PBtSdkSDPSearchPatternStru psch_ptn, BTUINT32 ptn_num, BTSVCHDL *svc_hdl, BTUINT32 *svc_count);
BTINT32 Btsdk_GetRemoteServices(BTDEVHDL dev_hdl, BTSVCHDL *svc_hdl, BTUINT32 *svc_count);
BTINT32 Btsdk_GetRemoteServiceAttributes(BTSVCHDL svc_hdl, BtSdkRemoteServiceAttrStru *attribute);
BTSDKHANDLE Btsdk_StartEnumRemoteService(BTDEVHDL dev_hdl);
BTSVCHDL Btsdk_EnumRemoteService(BTSDKHANDLE enum_handle, PBtSdkRemoteServiceAttrStru attribute);
BTINT32 Btsdk_EndEnumRemoteService(BTSDKHANDLE enum_handle);

/* Connection Management Application Extension */
BTINT32 Btsdk_SetRemoteServiceParam(BTSVCHDL svc_hdl, BTUINT32 app_param);
BTINT32 Btsdk_GetRemoteServiceParam(BTSVCHDL svc_hdl, BTUINT32 *papp_param);

/* Connection Establishment */
FUNC_EXPORT BTINT32 Btsdk_Connect(BTSVCHDL svc_hdl, BTUINT32 lParam, BTCONNHDL *conn_hdl);
FUNC_EXPORT BTINT32 Btsdk_ConnectEx(BTDEVHDL dev_hdl, BTUINT16 service_class, BTUINT32 lParam, BTCONNHDL *conn_hdl);
typedef void  (Btsdk_Connection_Event_Ind_Func)(BTCONNHDL conn_hdl, BTUINT16 event, BTUINT8 *arg);

/* Connection Database Management */
FUNC_EXPORT BTINT32 Btsdk_GetConnectionProperty(BTCONNHDL conn_hdl, PBtSdkConnectionPropertyStru conn_prop);
FUNC_EXPORT BTSDKHANDLE Btsdk_StartEnumConnection(void);
FUNC_EXPORT BTCONNHDL Btsdk_EnumConnection(BTSDKHANDLE enum_handle, PBtSdkConnectionPropertyStru conn_prop);
FUNC_EXPORT BTINT32 Btsdk_EndEnumConnection(BTSDKHANDLE enum_handle);

/* Connection Release */
FUNC_EXPORT BTINT32 Btsdk_Disconnect(BTCONNHDL handle);

/* BlueSoleil Extend APIs */
BTUINT32 Btsdk_VDIInstallDev(BTINT8 *HardwareID,  BTINT8 *COMName);
BTUINT32 Btsdk_VDIDelModem( BTINT8 *COMName);
BTUINT32 Btsdk_GetActivationInformation(BTINT8 *SerialNumber, BTINT8 *ActivateInformation, BTUINT32 ActiveInformationLen);
BTUINT32 Btsdk_EnterUnlockCode(BTINT8 *UnlockCode);

/* 
		Object Push Profile 
*/
typedef void (Btsdk_OPP_STATUS_INFO_CB)(BTUINT8 first, BTUINT8 last, BTUINT8* filename, BTUINT32 filesize, BTUINT32 cursize);
void Btsdk_OPPRegisterStatusCallback4ThirdParty(BTCONNHDL conn_hdl, Btsdk_OPP_STATUS_INFO_CB *func);

/* Register a function for transfering file status
	first:		[in]first callback flag 
	last:		[in]last callback flag 
	filename:	[in]file name, only valid when first flag is setted.
	filesize:	[in]total transfer file size, only valid when first flag is setted.
	cursize:	[in]current transfer size
*/

/* OPP Server */
typedef BTBOOL (BTSDK_OPP_UIDealReceiveFile)(PBtSdkFileTransferReqStru pFileInfo);
void Btsdk_OPPRegisterDealReceiveFileCB4ThirdParty(BTSDK_OPP_UIDealReceiveFile* func);

/* Register a function for uploading file request from remote device.
   pFileInfo	[in/out] Specify the information of the file uploaded or to be uploaded.
				When input pFileInfo->flag is set to BTSDK_ER_CONTINUE, following operation is allowed:
				(1)If the application wants to save the file using a different name, copy the 
				new file name to pFileInfo->file_name.
				(2)If the application wants to reject the file uploading request, change pFileInfo->flag
				to one of OBEX error code except for BTSDK_ER_CONTINUE and BTSDK_ER_SUCCESS.
				(3)If the application allow to save the file, just keep pFileInfo->flag unchanged.

	return value is ignored.
*/

/* OPP Client */
BTINT32 Btsdk_OPPCancelTransfer(BTCONNHDL conn_hdl);
BTINT32 Btsdk_OPPPushObj(BTCONNHDL conn_hdl,BTUINT8 *szPushFilePath);
BTINT32 Btsdk_OPPPullObj(BTCONNHDL conn_hdl,BTUINT8 *szPullFilePath);
BTINT32 Btsdk_OPPExchangeObj(BTCONNHDL conn_hdl,BTUINT8 *szPushFilePath,BTUINT8 *szPullFilePath,BTINT32 *npushError, BTINT32 *npullError);

/* 
		Serial Port Profile 
*/
BTINT32 Btsdk_InitCommObj(BTUINT8 com_idx, BTUINT16 svc_class);
BTINT32 Btsdk_DeinitCommObj(BTUINT8 com_idx);
FUNC_EXPORT BTINT16 Btsdk_GetClientPort(BTCONNHDL conn_hdl);
BTUINT8 Btsdk_GetAvailableExtSPPCOMPort(BTBOOL bIsForLocalSPPService);
BTUINT32 Btsdk_SearchAppExtSPPService(BTDEVHDL dev_hdl, PBtSdkAppExtSPPAttrStru psvc);
BTUINT32 Btsdk_ConnectAppExtSPPService(BTDEVHDL dev_hdl, PBtSdkAppExtSPPAttrStru psvc, BTCONNHDL *conn_hdl);

BTUINT32 Btsdk_CommNumToSerialNum(int comportNum);
void Btsdk_PlugOutVComm(UINT serialNum, ULONG flag);
BOOL Btsdk_PlugInVComm(UINT serialNum, ULONG *comportNumber, UINT usageType, ULONG flag, DWORD dwTimeout);
BTUINT32 Btsdk_GetASerialNum();

/*Local SPP service*/
/* Service Manager */
BTSVCHDL Btsdk_AddServer(BtSdkLocalServerAttrStru *attribute);
BTINT32 Btsdk_RemoveServer(BTSVCHDL handle);
BTINT32 Btsdk_UpdateServerAttributes(BTSVCHDL handle, BtSdkLocalServerAttrStru *attribute);
BTINT32 Btsdk_StartServer(BTSVCHDL handle);
BTINT32 Btsdk_StopServer(BTSVCHDL handle);
BTINT32 Btsdk_GetServerAttributes(BTSVCHDL handle, BtSdkLocalServerAttrStru *attribute);
BTINT32 Btsdk_GetLocalServers(BTSVCHDL * svc_hdl, BTUINT32 * svc_count);


BTSDKHANDLE Btsdk_StartEnumLocalServer(void);
BTSVCHDL Btsdk_EnumLocalServer(BTSDKHANDLE enum_handle, PBtSdkLocalServerAttrStru attribute);
BTINT32 Btsdk_EndEnumLocalServer(BTSDKHANDLE enum_handle);

/*INI file operation API*/
/*get/write from/to file*/
BTUINT32 Btsdk_GetPrivateProfileString(BTINT8 *lpAppName, BTINT8 *lpKeyName, BTINT8 *lpDefault, BTINT8 *lpReturnedString, BTUINT32 nSize, BTINT8 *lpFileName);
BOOL Btsdk_WritePrivateProfileString(BTINT8 *lpAppName, BTINT8 *lpKeyName, BTINT8 *lpString, BTINT8 *lpFileName);
BTINT32 Btsdk_GetPrivateProfileInt(BTINT8 *lpAppName, BTINT8 *lpKeyName, BTINT32 nDefault, BTINT8 *lpFileName);
BOOL Btsdk_WritePrivateProfileInt(BTINT8 *lpAppName, BTINT8 *lpKeyName, BTINT32 nNumber, BTINT8 *lpFileName);

/*secure level for local service*/
BTUINT32 Btsdk_SetServiceSecurityLevel(BTSVCHDL svc_hdl, BTUINT8 level);
BTUINT32 Btsdk_GetServiceSecurityLevel(BTSVCHDL svc_hdl, BTUINT8 *level);

BTINT32 Btsdk_GetServerStatus(BTSVCHDL svc_hdl, BTUINT16 *status);
BTUINT32 Btsdk_SetSecurityMode(BTUINT16 secu_mode);

/************************************************************************/
/* BT2.1 support  begin                                                                    */
/************************************************************************/
BTINT32 Btsdk_IOCapReqReply(BTDEVHDL dev_hdl, BTUINT8 io_cap, BTUINT8 oob_data_present, BTUINT8 authen_req);
BTINT32 Btsdk_IOCapReqReject(BTDEVHDL dev_hdl);
BTINT32 Btsdk_UsrCfmReqReply(BTDEVHDL dev_hdl, BTBOOL accepted);
BTINT32 Btsdk_PasskeyReqReply(BTDEVHDL dev_hdl, BTUINT32 num_value);
BTINT32 Btsdk_RemOOBDataReqReply(BTDEVHDL dev_hdl, BTUINT8 *c_val, BTUINT8 *r_val);

/************************************************************************/
/* BT2.1 support end                                                                     */
/************************************************************************/
BTINT32 Btsdk_ExecuteHCICommandEx(BTUINT16 cmd_idx, BTUINT32 cmd_len, BTUINT8 *cmd_param, BTUINT32 ev_len, BTUINT8 *ev_param);

BTINT32 Btsdk_GetRemoteDeviceType(BTDEVHDL dev_hdl);

}
#endif