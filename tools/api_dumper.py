#!/usr/bin/env python

import subprocess
import re
import os

def get_forward_decls(whence):
  return subprocess.Popen([
    'cpp',
    '-DNWNX_DUMP_STRUCTS',  # Flag for any special casing needs.
    '-D_NWNDEF_CUSTOM_H_',  # Ignore this since it includes c headers.
    '-D_CEXOARRAYLIST_H_',  # Special Cased
    '-D_CEXOLINKEDLIST_H_', # Special Cased
    '-D_CEXOLINKEDLISTINTERNAL_H_', # Special Cased
    whence+'/../api/nwndef.h'],
    stdout=subprocess.PIPE).communicate()[0].decode("utf-8")

def get_struct_defs(whence):
  return subprocess.Popen([
    'cpp',
    '-DNWNX_DUMP_STRUCTS',  # Flag for any special casing needs.
    '-D_NWNDEF_H_',         # Already done.
    '-D_NWNDEF_CUSTOM_H_',  # Ignore this since it includes c headers.
    '-D_CEXOARRAYLIST_H_',  # Special Cased
    '-D_CEXOLINKEDLIST_H_', # Special Cased
    '-D_CEXOLINKEDLISTINTERNAL_H_', # Special Cased
    whence+'/../api/all.h'],
    stdout=subprocess.PIPE).communicate()[0].decode("utf-8")

def astyle(whence):
  # Make it all look a little better and avoid too many whitespace changes
  # later.
  subprocess.Popen([
    'astyle',
    '--suffix=none', # Don't want .orig files.
    whence+'/../api/api_dump.h'],
    stdout=subprocess.PIPE)

DELETE_PATTERNS = [
  # No preprocessor
  re.compile('^#.*?$', flags=re.MULTILINE),
  # Namespaces
  re.compile('namespace.*?}', flags=re.MULTILINE|re.DOTALL),
  # No operators
  re.compile('^.*?operator.*?;', flags=re.MULTILINE),
  # No templates
  re.compile('template.*?[};]', flags=re.MULTILINE|re.DOTALL),
  # No externs
  re.compile('^extern.*?\(.*?\).*?;', flags=re.MULTILINE|re.DOTALL),
  # No funcions
  re.compile('^.*?[a-zA-Z0-9]\(.*?\).*?;', flags=re.MULTILINE),
  # No visibility specifiers
  re.compile('(public|private|protected).*?:')
]

CEXOARRAYLIST = """
struct CExoArrayList_{0}
{{
    {1} *Array;
    unsigned long Length;
    unsigned long ArraySize;
}};"""

CEXOLINKEDLIST = """
struct CExoLinkedList_{0} {{
    /* 0x0/0 */ CExoLinkedListInternal *List;
}};"""

CRESHELPER = """
struct CResHelper_{0} {{
    /* 0x0/0 */ unsigned long m_bAutoRequest;
    /* 0x4/4 */ {1} *m_pRes;
    /* 0x8/8 */ CResRef m_cResRef;
    /* 0x18/24 */ unsigned long res_vptr;
}};"""

# Format calls pass in sanitized template parameter name
# and the original template parameter.
TEMPLATE_FORMATERS = {
  'CExoArrayList': CEXOARRAYLIST,
  'CExoLinkedList': CEXOLINKEDLIST,
  'CResHelper': CRESHELPER,
}

HEADER = """
// Auto-Generated DO NOT edit or use as an include.
"""

vptr = """
struct CGameObject_vtbl {
    unsigned long           field_0;
    void                    (*Constructor)(CGameObject*);
    void                    (*Destructor)(CGameObject*, char);
    void                    (*SetId)(CGameObject*);
    void                    (*ResetUpdateTimes)(CGameObject*);
    CNWCObject*             (*AsNWCObject)(CGameObject*);
    CNWSObject*             (*AsNWSObject)(CGameObject*);
    CNWCDoor*               (*AsNWCDoor)(CGameObject*);
    CNWSDoor*               (*AsNWSDoor)(CGameObject*);
    CNWCModule*             (*AsNWCModule)(CGameObject*);
    CNWSModule*             (*AsNWSModule)(CGameObject*);
    CNWCArea*               (*AsNWCArea)(CGameObject*);
    CNWSArea*               (*AsNWSArea)(CGameObject*);
    CNWCCreature*           (*AsNWCCreature)(CGameObject*);
    CNWSCreature*           (*AsNWSCreature)(CGameObject*);
    CNWCItem*               (*AsNWCItem)(CGameObject*);
    CNWSItem*               (*AsNWSItem)(CGameObject*);
    CNWCTrigger*            (*AsNWCTrigger)(CGameObject*);
    CNWSTrigger*            (*AsNWSTrigger)(CGameObject*);
    CNWCProjectile*         (*AsNWCProjectile)(CGameObject*);
    CNWSPlayerTURD*         (*AsNWSPlayerTURD)(CGameObject*);
    CNWSPlaceable*          (*AsNWSPlaceable)(CGameObject*);
    CNWCPlaceable*          (*AsNWCPlaceable)(CGameObject*);
    CNWSAreaOfEffectObject* (*AsNWSAreaOfEffectObject)(CGameObject*);
    CNWCAreaOfEffectObject* (*AsNWCAreaOfEffectObject)(CGameObject*);
    CNWSWaypoint*           (*AsNWSWaypoint)(CGameObject*);
    CNWSEncounter*          (*AsNWSEncounter)(CGameObject*);
    CNWCStore*              (*AsNWCStore)(CGameObject*);
    CNWSStore*              (*AsNWSStore)(CGameObject*);
    CNWSSoundObject*        (*AsNWSSoundObject)(CGameObject*);
    CNWCSoundObject*        (*AsNWCSoundObject)(CGameObject*);
};

struct CNWSObject_vtbl {
    unsigned long           field_0;
    void                    (*Constructor)(CNWSObject*);
    void                    (*Destructor)(CNWSObject*, char);
    void                    (*SetId)(CNWSObject*);
    void                    (*ResetUpdateTimes)(CNWSObject*);
    CNWCObject*             (*AsNWCObject)(CNWSObject*);
    CNWSObject*             (*AsNWSObject)(CNWSObject*);
    CNWCDoor*               (*AsNWCDoor)(CNWSObject*);
    CNWSDoor*               (*AsNWSDoor)(CNWSObject*);
    CNWCModule*             (*AsNWCModule)(CNWSObject*);
    CNWSModule*             (*AsNWSModule)(CNWSObject*);
    CNWCArea*               (*AsNWCArea)(CNWSObject*);
    CNWSArea*               (*AsNWSArea)(CNWSObject*);
    CNWCCreature*           (*AsNWCCreature)(CNWSObject*);
    CNWSCreature*           (*AsNWSCreature)(CNWSObject*);
    CNWCItem*               (*AsNWCItem)(CNWSObject*);
    CNWSItem*               (*AsNWSItem)(CNWSObject*);
    CNWCTrigger*            (*AsNWCTrigger)(CNWSObject*);
    CNWSTrigger*            (*AsNWSTrigger)(CNWSObject*);
    CNWCProjectile*         (*AsNWCProjectile)(CNWSObject*);
    CNWSPlayerTURD*         (*AsNWSPlayerTURD)(CNWSObject*);
    CNWSPlaceable*          (*AsNWSPlaceable)(CNWSObject*);
    CNWCPlaceable*          (*AsNWCPlaceable)(CNWSObject*);
    CNWSAreaOfEffectObject* (*AsNWSAreaOfEffectObject)(CNWSObject*);
    CNWCAreaOfEffectObject* (*AsNWCAreaOfEffectObject)(CNWSObject*);
    CNWSWaypoint*           (*AsNWSWaypoint)(CNWSObject*);
    CNWSEncounter*          (*AsNWSEncounter)(CNWSObject*);
    CNWCStore*              (*AsNWCStore)(CNWSObject*);
    CNWSStore*              (*AsNWSStore)(CNWSObject*);
    CNWSSoundObject*        (*AsNWSSoundObject)(CNWSObject*);
    CNWCSoundObject*        (*AsNWCSoundObject)(CNWSObject*);
    void                    (*AIUpdate)(CNWSObject*);
    void                    (*ClearAction)(CNWSObject*, CNWSObjectActionNode*, int);
    void                    (*EventHandler)(CNWSObject*, unsigned long, unsigned long, void*, unsigned long, unsigned long);
    void                    (*SetAnimation)(CNWSObject*, int);
    CResRef                 (*GetDialogResref)(CNWSObject*);
    int                     (*GetDialogInterruptable)(CNWSObject*);
    char                    (*GetGender)(CNWSObject*);
    CExoLocString*          (*GetFirstName)(CNWSObject*);
    CExoLocString*          (*GetLastName)(CNWSObject*);
    int                     (*GetMaxHitPoints)(CNWSObject*, int);
    int                     (*GetCurrentHitPoints)(CNWSObject*, int);
    int                     (*DoDamage)(CNWSObject*, int);
    int                     (*DoDamageReduction)(CNWSObject*, CNWSCreature*, int, unsigned char, int, int);
    unsigned int            (*DoDamageResistance)(CNWSObject*, CNWSCreature*, int, unsigned short, int, int, int);
    unsigned int            (*GetMaximumDamageResistanceVsDamageFlag)(CNWSObject*, unsigned short, int*);
    void                    (*DoDamageImmunity)(CNWSObject*, CNWSCreature*, int, unsigned short, int, int);
    void                    (*GetDamageImmunity)(CNWSObject*, unsigned char);
    void                    (*GetDamageImmunityByFlags)(CNWSObject*, unsigned short);
    unsigned long           (*GetEffectSpellId)(CNWSObject*);
    void                    (*SetEffectSpellId)(CNWSObject*, unsigned long);
    void                    (*SetLockOrientationToObject)(CNWSObject*, unsigned long);
    unsigned long           (*GetLockOrientationToObject)(CNWSObject*);
    CResRef                 (*GetPortrait)(CNWSObject*);
    void                    (*SetPortrait)(CNWSObject*, CResRef);
    unsigned short          (*GetPortraitId)(CNWSObject*);
    void                    (*SetPortraitId)(CNWSObject*, unsigned short);
    void                    (*BroadcastFloatyData)(CNWSObject*, CNWCCMessageData*);
    void                    (*BroadcastFloatyDataSTRREF)(CNWSObject*, unsigned long);
    void                    (*UpdateEffectPtrs)(CNWSObject*);
    void                    (*UpdateAttributesOnEffect)(CNWSObject*, CGameEffect*, int);
};

struct CNWArea_vtbl {
    unsigned long           field_0;
    void                    (*Constructor)(CNWArea*);
    void                    (*Destructor)(CNWArea*, char);
    int                     (*NoCreaturesOnLine)(CNWArea*);
    int                     (*HandleTransparentDoors)(CNWArea*);
    int                     (*GetIsIDInExcludeList)(CNWArea*);
    void                    (*pure__virtual);
    void                    (*SetFog)(CNWArea*, int, Vector);
    void                    (*SetIsNight)(CNWArea*, int);
    void                    (*SetWind)(CNWArea*, unsigned char);
    CNWSArea*               (*AsNWSArea)(CNWArea*);
};

struct CNWSArea_vtbl {
    unsigned long           field_0;
    void                    (*Constructor)(CNWSArea*);
    void                    (*Destructor)(CNWSArea*, char);
    int                     (*NoCreaturesOnLine)(CNWSArea*);
    int                     (*HandleTransparentDoors)(CNWSArea*);
    int                     (*GetIsIDInExcludeList)(CNWSArea*);
    void                    (*pure__virtual);
    void                    (*SetFog)(CNWSArea*, int, Vector);
    void                    (*SetIsNight)(CNWSArea*, int);
    void                    (*SetWind)(CNWSArea*, unsigned char);
    CNWSArea*               (*AsNWSArea)(CNWSArea*);
    // These appear to be always 0x0.
    unsigned long           field_24;
    unsigned long           field_28;
};

struct CNWSClient_vtbl {
    unsigned long           field_0;
    void                    (*Constructor)(CNWSClient*);
    void                    (*Destructor)(CNWSClient*, char);
    CNWSDungeonMaster*      (*AsNWSDungeonMaster)(CNWSClient*);
    CNWSPlayer*             (*AsNWSPlayer)(CNWSClient*);
};

struct CRes_vtbl {
    unsigned long           field_0;
    void                    (*Constructor)(CRes*);
    void                    (*Destructor)(CRes*, char);
    int                     (*GetFixedResourceSize)(CRes*);
    int                     (*GetFixedResourceDataOffset)(CRes*);
    void                    (*OnResourceFreed)(CRes*);
    void                    (*OnResourceServiced)(CRes*);
};

struct CServerExoApp_vtbl {
    unsigned long           field_0;
    void                    (*Constructor)(CServerExoApp*);
    void                    *AdmitNetworkAddress;
    unsigned long           AdmitPlayerName;
    unsigned long           SetNetworkAddressBan;
    unsigned long           PlayerListChange;
    unsigned long           HandleMessage;
    unsigned long           GetFPS;
    unsigned long           ContinueMessageProcessing;
    unsigned long           GetNetLayer;
    unsigned long           ShutDownToMainMenu;
    void                    *GetMultiplayerEnabled;
    unsigned long           GetExtendedServerInfo;
    unsigned long           HandleGameSpyToServerMessage;
    unsigned long           GetConnectionLib;
    unsigned long           GSClientGroupRoomAdded;
    unsigned long           GSClientChatMessage;
    unsigned long           GSClientAddServer;
    unsigned long           GSClientRemoveServer;
    unsigned long           GSClientUpdateServer;
    unsigned long           GSClientClearServers;
    unsigned long           GSClientUpdateConnectionPhase;
    unsigned long           GetServerInfo;
    unsigned long           GetExtendedServerInfo_;
    unsigned long           GetModuleDescription;
    void                    *GetApplicationId;
    unsigned long           SetApplicationIdsMatch;
    void                    *GetIsIPOnBannedList;
    void                    *GetIsPlayerNameOnBannedList;
    void                    *GetIsCDKeyOnBannedList;
    unsigned long           PushMessageOverWall;
    void                    *GetIsMultiPlayer;
    unsigned long           GetCDKeys;
    unsigned long           SetWeGotDisconnected;
};

struct CNWVirtualMachineCommands_vtbl {
    unsigned long           field_0;
    void                    (*Constructor)(CNWVirtualMachineCommands*);
    void                    (*Destructor)(CNWVirtualMachineCommands*, char);
    unsigned long           InitializeCommands;
    unsigned long           ExecuteCommand;
    void                    *RunScriptCallback;
    unsigned long           ReportError;
    unsigned long           CreateGameDefinedStructure;
    unsigned long           DestroyGameDefinedStructure;
    unsigned long           GetEqualGameDefinedStructure;
    void                    *CopyGameDefinedStructure;
    void                    *SaveGameDefinedStructure;
    unsigned long           LoadGameDefinedStructure;
    unsigned long           GetGameDefinedStructureName;
    unsigned long           GetDebuggerLabelName;
    unsigned long           GetEngineStructureWatchView;
    unsigned long           GetObjectWatchView;
    unsigned long           DebugGUIStart;
    unsigned long           DebugGUIStop;
    unsigned long           DebugGUISendMessageTo;
    unsigned long           DebugGUIGetMessageFrom;
    unsigned long           DebugGUIUpdate;
};

struct CExoPackedFile_vtbl {
    unsigned long           field_0;
    void                    (*Constructor)(CExoPackedFile*);
    void                    (*Destructor)(CExoPackedFile*, char);
    void                    *AddRefCount;
    void                    *AddAsyncRefCount;
    unsigned long           CloseFile;
    unsigned long           CloseAsyncFile;
    void                    *DeleteRefCount;
    void                    *DeleteAsyncRefCount;
    unsigned long           GetFile;
    void                    *GetAsyncFile;
    void                    *GetResourceSize;
    unsigned long           Initialize;
    unsigned long           OpenFile;
    unsigned long           OpenFile2;
    unsigned long           OpenAsyncFile;
    void                    *ReadResource;
    void                    *ReadResourceAsync;
    unsigned long           LoadHeader;
    unsigned long           UnloadHeader;
    unsigned long           GetResource;
};

"""

forwards = {}
templates = {}

TEMPLATE_FIELDS = re.compile('^\s*(.*?)<(.*?)>', flags=re.MULTILINE)
def template_field_replace(match):
  klass, tparam = match.groups(0)
  sanitized_tparam = tparam.replace(' ', '_').strip()
  if sanitized_tparam[-1] == "*":
    r = 'ptr' if sanitized_tparam[-2] == "_" else '_ptr'
    sanitized_tparam = sanitized_tparam.replace('*', r)

  sanitized_type = "%s_%s" % (klass, sanitized_tparam)
  # Add our new type to the forward decl list
  forwards[sanitized_type] = True

  if klass in TEMPLATE_FORMATERS:
    if klass not in templates: templates[klass] = {}
    # Add our new structure definition
    templates[klass][tparam] = TEMPLATE_FORMATERS[klass].format(sanitized_tparam, tparam)

  # Return comment with original type name and the new type.
  return """// {0}<{1}>\n{2}""".format(klass, tparam, sanitized_type)

INHERITANCE = re.compile(':(.*?){', flags=re.DOTALL)
def inheritance_replace(match):
  supers = match.groups(0)[0].strip().replace('public ', '').split(',')
  out = ['%s baseclass_%d;' % (supe, i) for i, supe in enumerate(supers)]
  return '{\n%s\n' % '\n'.join(out)

if __name__ == '__main__':
  whence = os.path.dirname(os.path.realpath(__file__))
  forward_decls = get_forward_decls(whence)
  struct_defs = get_struct_defs(whence)

  for d in DELETE_PATTERNS:
    struct_defs = d.sub('', struct_defs)
    forward_decls = d.sub('', forward_decls)

  struct_defs = INHERITANCE.sub(inheritance_replace, struct_defs)
  struct_defs = TEMPLATE_FIELDS.sub(template_field_replace, struct_defs)

  # Not designed for efficiency.
  with open(whence+'/../api/api_dump.h', 'w') as f:
    f.write(HEADER)

    f.write('// Forward Declarations\n\n')
    for line in forward_decls.splitlines():
      if len(line.strip()):
        f.write(line)
        f.write('\n')

    f.write(vptr)

    for t in sorted(forwards.keys()):
      f.write('struct %s;\n' % t)

    for t in sorted(templates.keys()):
      for u in sorted(templates[t].keys()):
        f.write(templates[t][u])

    f.write('// Struct Definitions\n\n')
    for line in struct_defs.splitlines():
      if (not len(line.strip())
          or '__extension__' in line):
           continue
      f.write(line)
      f.write('\n')

  astyle(whence)
