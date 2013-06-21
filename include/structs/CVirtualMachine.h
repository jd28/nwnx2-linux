/*
 *  (c) 2007
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  $Id$
 *  $HeadURL$
 *
 */

/* jmd: Ported from NWNX v2.8 api. */

#ifndef _NX_NWN_STRUCT_CVIRTUALMACHINE_
#define _NX_NWN_STRUCT_CVIRTUALMACHINE_

struct CVirtualMachine_s {
    uint32_t                   field_0;
    void                      *vm_return_value;
    uint32_t                   vm_instruction_executed;
    uint32_t                   vm_recursion_level;
    CVirtualMachineScript      vm_script[8];
    uint32_t                   vm_valid_obj[8];
    nwn_objid_t                vm_object_id[8];
    CVirtualMachineStack       vm_stack;
    uint32_t                   vm_instruction_ptr_level;
    uint32_t                   vm_runtime_instruction_ptr[128];
    uint32_t                   vm_stack_size_to_save;
    uint32_t                   vm_base_stack_size_to_save;
    CNWVirtualMachineCommands *vm_implementer;
    uint32_t                   vm_debug_gui_required;
    uint32_t                   vm_debugger_spawned;
    CVirtualMachineFile        vm_file;
    uint32_t                   vm_cache;
    uint32_t                   field_3C4;
    uint32_t                   vm_script_log;
    uint32_t                   field_3CC;
    uint32_t                   field_3D0;
    uint32_t                   vm_enable_logging;
    uint32_t                   vm_enable_profiling;
    uint32_t                   field_3DC;
    uint32_t                   field_3E0;
    uint32_t                   field_3E4;
};

#endif /* _NX_NWN_STRUCT_CVIRTUALMACHINE_ */

/* vim: set sw=4: */
