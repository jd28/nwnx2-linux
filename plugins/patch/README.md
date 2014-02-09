##NWNX Patch

This plugin is a port of ShadoOow's windows NWNX plugin that he is
creating as apart of his Community Patch Project.

###Status:

This plugin should be considered beta.  Everything has been tested to
some degree, but has yet to be used in production.

###Features:

All features can be disabled via nwnx2.ini.  See
plugins/patch/nwnx2.ini for details and exceptions.

* Removes 1-4 limit on CopyItemAndModify.
* Allows Ability Decreases on items to bypass Immunity to Ability
  Drain.
* Modifies Circle Kick to revert back to the original target.  Note:
  Reverting back to the orginal target might not occur until after the
  current flurry is over / combat round end.  This feature really
  requires more real world testing and is disabled in the example
  nwnx2.ini
* Allows Ability Decrease from Curse to bypass Immunity to Ability
  Drain for servers with DnD/Very High Difficulty level.
* Fixes Trident Weapon Focus bug. NOTE: if you use nwnx_weapons, you
  MUST disable this.

###Pre-compiled binary:

[nwnx_patch.7z](https://dl.dropboxusercontent.com/u/32687721/nwnx_patch.7z)

Note this was compiled with GCC 4.8.1 on Ubuntu 13.10 and so may not
work for older servers.  Currently only the cmake build system is
supported.  If you don't know how to build it ask on the nwnx.org forums.



