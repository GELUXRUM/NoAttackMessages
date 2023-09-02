#include "hooks.h"

namespace HookLineAndSinker
{
	typedef void(CriSneakMessageSig)(void*, const char*, const char*, bool);
	REL::Relocation<CriSneakMessageSig> OriginalFunction;

	void HookedShowHUDMessage(void*, const char*, const char*, bool)
	{
		return;
	}

	void RegisterHooks(F4SE::Trampoline& trampoline) {
		REL::Relocation<CriSneakMessageSig> sneakAttack{ REL::ID(222139), 0xF3 };	// sneak attack
		REL::Relocation<CriSneakMessageSig> vatsCrit{ REL::ID(222139), 0x1FD };		// VATS crit
		OriginalFunction = trampoline.write_call<5>(sneakAttack.address(), &HookedShowHUDMessage);
		OriginalFunction = trampoline.write_call<5>(vatsCrit.address(), &HookedShowHUDMessage);
	}
}
