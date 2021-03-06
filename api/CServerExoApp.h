#ifndef _CSERVEREXOAPP_H_
#define _CSERVEREXOAPP_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CExoLinkedList.h"
#include "CExoArrayList.h"
#include "CExoLocString.h"
#include "CResRef.h"
#include "nwnstructs.h"
#include "CServerExoAppInternal.h"

class CServerExoApp
{
public:
    void AddCDKeyToBannedList(CExoString);
    void AddCharListRequest(unsigned long);
    void AddIPToBannedList(CExoString);
    void AddPlayerNameToBannedList(CExoString);
    void AddSubNetProfileSendSize(unsigned long, unsigned long);
    void AddToExclusionList(unsigned long, unsigned char);
    int AdmitNetworkAddress(unsigned long, CExoString);
    int AdmitPlayerName(CExoString);
    int ContinueMessageProcessing();
    int ExportAllPlayers();
    void GSClientAddServer(void *, char *, char *, int, int, int, int, char *, int, int, char *, int, int, int, char *, char *, int, int, int, int, int, bool);
    void GSClientChatMessage(int, CExoString, CExoString);
    void GSClientClearServers();
    void GSClientGroupRoomAdded(int, unsigned long);
    void GSClientRemoveServer(void *);
    void GSClientUpdateConnectionPhase(unsigned char, CExoString const &);
    void GSClientUpdateServer(void *, char *, char *, int, int, int, int, char *, int, int, char *, int, int, int, char *, char *, int, int, int, int, int, bool);
    CExoLinkedList<unsigned long> * GetActiveExclusionList();
    unsigned char GetActivePauseState();
    CWorldTimer * GetActiveTimer(unsigned long);
    unsigned long GetApplicationId();
    CNWSArea * GetAreaByGameObjectID(unsigned long);
    CNWSAreaOfEffectObject * GetAreaOfEffectByGameObjectID(unsigned long);
    int GetAutoSavePending();
    CExoString GetBannedListString();
    int GetCDKeys(CExoArrayList<CExoString> **);
    CNWSPlayer * GetClientObjectByObjectId(unsigned long);
    CNWSClient * GetClientObjectByPlayerId(unsigned long, unsigned char);
    CCodeBase * GetCodeBase();
    CConnectionLib * GetConnectionLib();
    CNWSCreature * GetCreatureByGameObjectID(unsigned long);
    int GetCreatureDeathLogging();
    int GetDebugMode();
    int GetDifficultyOption(int);
    CNWSDoor * GetDoorByGameObjectID(unsigned long);
    CNWSEncounter * GetEncounterByGameObjectID(unsigned long);
    int GetExoAppInternal();
    int GetExportCharacterPending();
    int GetExportPlayersCharacter();
    CExtendedServerInfo * GetExtendedServerInfo();
    void GetExtendedServerInfo(CExtendedServerInfo *);
    float GetFPS();
    int GetFactionOfObject(unsigned long, int *);
    unsigned long GetFirstPCObject();
    CGameObject * GetGameObject(unsigned long);
    int GetGameSpyEnabled();
    int GetImportingChar();
    int GetIsCDKeyOnBannedList(CExoString);
    int GetIsControlledByPlayer(unsigned long);
    int GetIsIPOnBannedList(CExoString);
    int GetIsMultiPlayer();
    int GetIsPlayerNameOnBannedList(CExoString);
    CNWSItem * GetItemByGameObjectID(unsigned long);
    int GetLoadingModule();
    CNWSModule * GetModuleByGameObjectID(unsigned long);
    CExoLocString GetModuleDescription();
    int GetModuleLanguage();
    CExoString GetModuleName();
    void * GetModule();
    int GetMoveToModulePending();
    int GetMoveToModuleString();
    int GetMultiplayerEnabled();
    void * GetNWSMessage();
    CNetLayer * GetNetLayer();
    unsigned long GetNextPCObject();
    CGameObjectArray * GetObjectArray();
    int GetPauseState(unsigned char);
    CWorldTimer * GetPauseTimer();
    CNWPlaceMeshManager * GetPlaceMeshManager();
    CNWSPlaceable * GetPlaceableByGameObjectID(unsigned long);
    int GetPlayerAddressData(unsigned long, unsigned long *, unsigned char **, unsigned char **, unsigned long *);
    unsigned long GetPlayerIDByGameObjectID(unsigned long);
    int GetPlayerLanguage(unsigned long);
    CExoString GetPlayerListString();
    void * GetPlayerList();
    CExoString GetPortalListString();
    int GetReloadModuleWhenEmpty();
    void * GetServerAIMaster();
    CServerInfo * GetServerInfo();
    short GetServerMode();
    CNWSSoundObject * GetSoundObjectByGameObjectID(unsigned long);
    CNWSStore * GetStoreByGameObjectID(unsigned long);
    void * GetSysAdminList();
    CWorldTimer * GetTimestopTimer();
    CNWSTrigger * GetTriggerByGameObjectID(unsigned long);
    CNWSWaypoint * GetWaypointByGameObjectID(unsigned long);
    CWorldTimer * GetWorldTimer();
    void HandleGameSpyToServerMessage(int, void *, int);
    int HandleMessage(unsigned long, unsigned char *, unsigned long, int);
    int Initialize();
    void InitiateModuleForPlayer(void *);
    int IsOnActiveExclusionList(unsigned long);
    int IsOnExclusionList(unsigned long);
    int LoadCharacterFinish(CNWSPlayer *, int, int);
    int LoadCharacterStart(unsigned char, CNWSPlayer *, CResRef, void *, unsigned long);
    int LoadGame(unsigned long, CExoString &, CExoString &, CNWSPlayer *);
    int LoadModule(CExoString, int, CNWSPlayer *);
    int LoadPrimaryPlayer(CNWSPlayer *);
    int MainLoop();
    void MovePlayerToArea(void *);
    int OnCDChange();
    int OnExit();
    int OnGainFocus();
    int OnLostFocus();
    int OnVideoChange();
    void PlayerListChange(unsigned long, int, int);
    void PushMessageOverWall(unsigned char *, unsigned long);
    void RemoveCDKeyFromBannedList(CExoString);
    void RemoveFromExclusionList(unsigned long, unsigned char);
    void RemoveIPFromBannedList(CExoString);
    int RemovePCFromWorld(CNWSPlayer *);
    void RemovePlayerNameFromBannedList(CExoString);
    unsigned long ResolvePlayerByFirstName(CExoString const &);
    int RestartNetLayer();
    int RunModule();
    int SaveGame(unsigned long, CExoString &, CExoString &, CNWSPlayer *, int, CExoString &);
    int SendCharacterQuery(CNWSPlayer *);
    void SetApplicationIdsMatch(int);
    void SetAutoSavePending(int);
    void SetDebugMode(int);
    void SetEndGamePending(int);
    void SetEndGameString(CExoString &);
    void SetExportCharacterPending(int);
    void SetExportPlayersCharacter(unsigned long);
    int SetForceUpdate();
    void SetGameSpyEnabled(int);
    int SetGameSpyReporting(int);
    void SetImportingChar(int);
    void SetLoadingModule(int);
    void SetMoveToModulePending(int);
    void SetMoveToModuleString(CExoString &);
    int SetNetworkAddressBan(unsigned long, CExoString, int);
    void SetPauseState(unsigned char, int);
    void SetReloadModuleWhenEmpty(int);
    void SetWeGotDisconnected();
    void ShutDownToMainMenu();
    int ShutdownNetLayer();
    void Shutdown(int, int);
    int StartNewModule(CExoString &);
    void StartServices();
    void StopServices();
    int StripColorTokens(CExoString &);
    void TogglePauseState(unsigned char);
    void Uninitialize();
    int UnloadModule();
    int ValidatePlayerLogin(void *);
    void VomitServerOptionsToLog();
    ~CServerExoApp();
    CServerExoApp();

    /* 0x0/0 */ CServerExoApp_vt *vt;
    /* 0x4/4 */ CServerExoAppInternal *Internal;
};
#endif
