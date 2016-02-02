#ifndef _NWN_ALL_H_
#define _NWN_ALL_H_
#include "static_asserts.h"

#include "CNWSCreature.h"
#include "CNWSPlaceable.h"
#include "CNWSObject.h"
#include "CNWSModule.h"
#include "CNWSTrigger.h"
#include "CNWSWaypoint.h"
#include "CNWSEncounter.h"
#include "CNWSPlayerTURD.h"
#include "CNWSSoundObject.h"
#include "CNWSAreaOfEffectObject.h"
#include "CNWSArea.h"
#include "CNWSDoor.h"
#include "CNWSItem.h"
#include "CNWSStore.h"
#include "CNWSCombatRound.h"
#include "CNWSMessage.h"
#include "CExoLinkedListInternal.h"
#include "CExoLinkedList.h"
#include "CExoBaseInternal.h"
#include "CNWSPlayer.h"
#include "CExoResFile.h"
#include "CExoEncapsulatedFile.h"
#include "CExoResourceImageFile.h"
#include "CCodeBaseInternal.h"
#include "CCodeBase.h"
#include "CServerExoApp.h"
#include "CServerExoAppInternal.h"
#include "CNetLayerPlayerInfo.h"
#include "CGameObjectArray.h"
#include "CNWSCombatAttackData.h"
#include "CResGFF.h"
#include "CExoKeyTable.h"
#include "CNWSTile.h"
#include "CExoResMan.h"
#include "CGameSpyServer.h"
#include "CServerAIMaster.h"
#include "CNWSCreatureStats.h"
#include "CNWLevelStats.h"
#include "CExoMemman.h"
#include "CObjectLookupTable.h"
#include "CObjectTableManager.h"
#include "CNWSBarter.h"
#include "CItemRepository.h"
#include "CNWSDialog.h"
#include "CNWSPlayerLastUpdateObject.h"
#include "CNWSCreatureStats_ClassInfo.h"
#include "CNWSFaction.h"
#include "CNetworkProfiler.h"
#include "CNWSExpressionList.h"
#include "CServerAIList.h"
#include "CNWTileData.h"
#include "CERFFile.h"
#include "CConnectionLib.h"
#include "CExoStringList.h"
#include "CNWArea.h"
#include "CExoLocString.h"
#include "CExoLocStringInternal.h"
#include "CScriptCompiler.h"
#include "CNetLayerWindow.h"
#include "CVirtualMachineStack.h"
#include "CExoArrayList.h"
#include "CWorldTimer.h"
#include "CExoAliasList.h"
#include "CExoRandInternal.h"
#include "CExoAliasListInternal.h"
#include "CExoNetInternal.h"
#include "CExoNet.h"
#include "CNWSItemPropertyHandler.h"
#include "CExoString.h"
#include "CGameObject.h"
#include "CNWSClient.h"
#include "CNWSDungeonMaster.h"
#include "CNWSSysAdmin.h"
#include "CExoDebugInternal.h"
#include "CExoDebug.h"
#include "CExoFileThread.h"
#include "CBWCBlowFish.h"
#include "CNetLayerInternal.h"
#include "CDUtil.h"
#include "CRes.h"
#include "CExoNetExtendableBuffer.h"
#include "CExoNetFrameBuffer.h"
#include "CGameSpyClient.h"
#include "CNWTileSurfaceMesh.h"
#include "CExoBase.h"
#include "CNetLayer.h"
#include "CVirtualMachineCache.h"
#include "CNWSExpression.h"
#include "CNWSPlayerLUOInventory.h"
#include "CTwoDimArrays.h"
#include "CTlkTable.h"
#include "CNWCCMessageData.h"
#include "CNWCreatureStatsUpdate.h"
#include "CNWMessage.h"
#include "CNWTileSetManager.h"
#include "CNWPlaceMeshManager.h"
#include "CMemRecord.h"
#include "CNWSPlayerStoreGUI.h"
#include "CNWRules.h"
#include "CNWSPlayerCharSheetGUI.h"
#include "CPathfindInformation.h"
#include "CGameEffect.h"
#include "CNWVirtualMachineCommands.h"
#include "CResSET.h"
#include "CScriptEvent.h"
#include "CScriptLocation.h"
#include "CScriptTalent.h"
#include "CResTGA.h"
#include "CResRef.h"
#include "CFactionManager.h"
#include "CAppManager.h"
#include "CVirtualMachineDebuggerInstance.h"
#include "CVirtualMachine.h"
#include "CBWCMD5.h"
#include "CNWSScriptVarTable.h"
#include "CVirtualMachineDebugLoader.h"
#include "CNWSJournal.h"
#include "CExoEncrypt.h"
#include "CExoCriticalSection.h"
#include "CExoCriticalSectionInternal.h"
#include "CExoFile.h"
#include "CScriptCompilerIdListEntry.h"
#include "CNWTileSurfaceMeshHashTableEntry.h"
#include "CServerInfo.h"
#include "CMstNetLayer.h"
#include "CRes2DA.h"
#include "CNWTile.h"
#include "CNWSInventory.h"
#include "CExoPackedFile.h"
#include "CNWClass.h"
#include "CNWItem.h"
#include "CNWBaseItemArray.h"
#include "C2DA.h"
#include "CBWCBlowFishState.h"
#include "CNWRace.h"
#include "CNWTileSet.h"
#include "CResDWK.h"
#include "CVirtualMachineFile.h"
#include "CNWFeat.h"
#include "CNWSkill.h"
#include "CNWDomain.h"
#include "CResLTR.h"
#include "CExoTimers.h"
#include "CExoTimersInternal.h"
#include "CNWBaseItem.h"
#include "CLoopingVisualEffect.h"
#include "CNWDoorSurfaceMesh.h"
#include "CResNCS.h"
#include "CResNDB.h"
#include "CResNSS.h"
#include "CExoFileInternal.h"
#include "CResPWK.h"
#include "CNWSAmbientSound.h"
#include "CNWNameGen.h"
#include "CNWSpell.h"
#include "CNWSpellArray.h"
#include "CExoRand.h"
#include "CERFString.h"
#include "CResWOK.h"
#include "CResGFFFieldIDHash.h"
#include "CNWSEffectListHandler.h"
#include "CLastUpdateObject.h"
#include "CServerAIBodyBagInfo.h"
#include "CCombatInformation.h"
#include "CNWSSpellScriptData.h"
#include "CNWSCombatRoundAction.h"
#include "CNWSForcedAction.h"
#include "CServerAIEventNode.h"
#include "CScriptSourceFile.h"
#include "CNWPlaceableSurfaceMesh.h"
#include "Vector.h"
#include "CTlkFile.h"
#include "CExoIniInternal.h"
#include "CExoIni.h"
#include "CERFKey.h"
#include "CERFRes.h"
#include "CNWSPlayerContainerGUI.h"
#include "CNWSPlayerInventoryGUI.h"
#include "Plane.h"
#include "MS_RSAVLong.h"
#include "CBWCBlowFishBlock.h"
#include "CNWSExpressionNode.h"
#include "CNWSObjectActionNode.h"
#include "CNetLayerSessionInfo.h"
#include "CGameEffectApplierRemover.h"
#include "CNWTileSurfaceMeshAABBNode.h"
#include "CItemPropertyApplierRemover.h"
#include "CVirtualMachineCmdImplementer.h"
#include "CResARE.h"
#include "CResIFO.h"
#include "CNWSRules.h"
#include "CStoreCustomer.h"
#include "CNWSStats_Spell.h"
#include "MS_RSAPrivateKey.h"
#include "MS_RSAVLong_value.h"
#include "CCombatInformationNode.h"
#include "CNWSStats_SpellLikeAbility.h"
#include "CPathfindInfoIntraTileSuccessors.h"
#include "CExtendedServerInfo.h"
#include "MS_RSAPublicKey.h"
#include "Matrix.h"
#include "custom/nwn_globals.h"
#include "FunctionPtrs.h"
#endif
